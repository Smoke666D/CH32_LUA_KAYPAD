/*
 * lua_task.c
 *
 *  Created on: Feb 14, 2025
 *      Author: i.dymov
 */

#include "lua_task.h"
#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lapi.h"
#include "hw_lib_can.h"
#include "hal_timers.h"
#include "led_task.h"
#include "io_task.h"
#include "string.h"
#include "hal_wdt.h"


#define  FLASH_STORAGE_ADR         0x00025000UL
#define  FLASH_STORAGE_LENGTH      0x2800U
#define  FLASH_STORAGE_LENGTH_SIZE 4U

/*
Global variables
*/
static TaskHandle_t  LuaTaskHandle;

static char * pcLuaErrorString;

/* 
Static function
*/
static int iCanSetConfig(lua_State *L);
static int iCanSendData( lua_State *L );
static int iCanSendTable( lua_State *L );
static void vSendCanData(CAN_TX_FRAME_TYPE * frame );
static int iCanSendRequest( lua_State *L );
static int iCanSetResiveFilter(lua_State *L );
static int iCanGetResivedData(lua_State *L );
static int iCanResetResiveFilter(lua_State *L );


TaskHandle_t * xGetLuaTaskHandle ()
{
    return  &LuaTaskHandle ;
}




/*
Функия отправки запроса. В качестве парамеров передаються
CAN_ID запроса, CAN_ID ответа, данные пакта запроса
*/
static int iCanSendRequest( lua_State *L )
{
  CAN_TX_FRAME_TYPE frame;
	int arg_number = lua_gettop(L);
	if (arg_number >= SEND_REQUEST_ARGUMENT_COUNT)  //Проверяем, что при вызове нам передали нужное число аргументов
	{
    eMailboxFilterSet(lua_tointeger( L, SECOND_ARGUMENT ),ANSWER_FILTER );
		frame.DLC  = arg_number -2;
		for (int i=0;i<frame.DLC;i++)
		{
			frame.data[i] = (uint8_t) lua_tointeger(L,-(arg_number-2-i)); //Третьем агрументом должно передоватьс время плавного старта в милисекундах
		}
     frame.ident = (uint32_t)lua_tointeger(L, FIRST_ARGUMENT);
     vSendCanData(&frame);
	}
	return ( NO_RESULT );
}














/*
Функция проерки пришле ли нужный пакет
В качестве параметра передается CAN_ID для проверки. В случае если параметров не переадно,
проверяеться фильтр, установленный ранее функцией iCanSendRequest
*/
int iCanCheckData(lua_State *L )
{
	uint32_t uiRes = 0U;
	switch (lua_gettop(L)) 
  {
     case 0:
        uiRes = vCheckAnswer();
        break;
     case 1:
		    uiRes = vCanChekMessage( lua_tointeger(L, FIRST_ARGUMENT) );
        break;
      default:
        break;
	}
	lua_pushnumber(L, uiRes );
	return ( 1U );
}


int iCanGetMessage(lua_State *L )
{
	uint8_t n = 0;
	CAN_FRAME_TYPE  RXPacket;
	switch (lua_gettop(L) )
	{
    case 1:
			luaL_checktype(L, 1, LUA_TNUMBER);
			RXPacket.ident = (uint32_t) lua_tointeger(L,1);
			n= vCanGetMessage(&RXPacket);
      break;
    case 0:
      vCanGetAnsewerMessage(&RXPacket);
      break;
	}
	if (n!=0)
	{
		n = RXPacket.DLC;
		for (int i = 0; i <n;i++)
		{
			lua_pushnumber(L,RXPacket.data[i]);
		}
	}
	return ( n );
}


static RESULT_t eIsLuaSkriptValid(const uint8_t* pcData, uint32_t size, uint32_t * real_size)
{
	uint8_t ucRes = RESULT_FALSE;
  if (size < MAX_SCRIPT_SIZE)
  {
    if ( ( pcData[0] == LUA_SIGNATURE[0] ) && ( pcData[1] == LUA_SIGNATURE[1] ) && ( pcData[2] == LUA_SIGNATURE[2] ) && (pcData[3] == LUA_SIGNATURE[3]) )
		{
            printf("Find signature\r\n");
            *real_size =size;
					  ucRes = RESULT_TRUE;
		}
    else 
    {
	      for (uint32_t ulIndex = 0;ulIndex < size; ulIndex++)
	      {
		          if ( pcData[ulIndex] == 0x00 )
              {
                  *real_size =ulIndex;
					        ucRes = RESULT_TRUE;
					        break;
				      }
			  }
		}
  }
	return ( ucRes );
}



const uint8_t* uFLASHgetScript ( void )
{
  return ( const uint8_t* )( FLASH_STORAGE_ADR + FLASH_STORAGE_LENGTH_SIZE );
}
uint32_t uFLASHgetLength ( void )
{
  uint32_t size ;
  size = *( uint8_t* )( FLASH_STORAGE_ADR  );
  size |= (*( uint8_t* )( FLASH_STORAGE_ADR  +1 ))<<8;
  size |= (*( uint8_t* )( FLASH_STORAGE_ADR  +2 ))<<16;
  size |= (*( uint8_t* )( FLASH_STORAGE_ADR  +3 ))<<24;
  return  size;
}

void vLuaTask( void * argument )
{
    int res ;
    static lua_State *L1 = NULL;
    uint8_t data_buffer[6]={0,0,0,0,0,0};
    static LUA_STATE_t lua_state = LUA_INIT;
    uint32_t ulWorkCicleIn10us;
#ifdef DEBUG_PRINT
    uint16_t counter = 0;
    uint32_t max_clock = 0;
#endif


    while(1)
    {
        vTaskDelay( 1 );
        HAL_WDTReset();
        switch (lua_state)
        {
            case LUA_INIT:
               lua_state = LUA_ERROR;
               L1  = luaL_newstate();  //Созадем состояние LUA, занимет 2К оперативной памяти
               luaL_openlibs(L1);      //Подлючаем библиотеки
               //Регестрируем пользовательские функции
               lua_register(L1,"CanSend",           iCanSendData);
               lua_register(L1,"CanTable",          iCanSendTable);
               lua_register(L1,"CheckCanId",        iCanCheckData );
               lua_register(L1,"GetRequest",        iCanGetMessage);
               lua_register(L1,"sendCandRequest",   iCanSendRequest);
	             lua_register(L1,"GetCanMessage",     iCanGetMessage) ;
               lua_register(L1,"setCanFilter",      iCanSetResiveFilter );
               lua_register(L1,"ResetCanFilter",    iCanResetResiveFilter );
	             lua_register(L1,"GetCanToTable",     iCanGetResivedData);
	             lua_register(L1,"ConfigCan",         iCanSetConfig);
               uint32_t real_size;
              if ( eIsLuaSkriptValid(uFLASHgetScript(), uFLASHgetLength()+1,&real_size) == RESULT_TRUE )
	   	         {     
	   	    	      if (luaL_loadbuffer(L1, uFLASHgetScript(), real_size , uFLASHgetScript())==0 )  
                  {
                   
                    if  (lua_pcall(L1, 0, LUA_MULTRET, 0) == 0 )
                    {
                        lua_getglobal(L1, "main");
#ifdef DEBUG_PRINT
                            printf("Memory %d\r\n",lua_gc(L1,LUA_GCCOUNT,0)*1024);
#endif
                            HAL_TiemrEneblae(TIMER1);
                            lua_getglobal(L1, "main");  //Закидываем в стек глобальнйо имя рабочей функции lua скрипта
                            lua_state = LUA_RUN;
                    }
                  }
                  else 
                  {
                      pcLuaErrorString =  (char *) lua_tostring( L1, LAST_ARGUMENT );
#ifdef DEBUG_PRINT
                      printf("Error = %s\r\n",pcLuaErrorString);
#endif
                  }  
	   	          }
	   	          else
	   	          {
                  printf("File break\r\n");
                }
               break;
            case LUA_RUN:
                ulWorkCicleIn10us= HAL_GetTimerCnt(TIMER1);
                lua_pushinteger(L1, ulWorkCicleIn10us);
                lua_pushinteger(L1, getKeyData());
                res = lua_resume(L1,0,2);       //Возобновляем выполнение скрита
                for (uint8_t i=0;i<6;i++)
                {
                    uint8_t temp_data = (uint8_t) lua_tointeger( L1,-(i+1));
                    if (data_buffer[i]!=temp_data)
                    {
                      data_buffer[i]=temp_data;
                      switch (i)
                      {
                        default:
                            vSetLedOn((i+1),temp_data);
                            break;
                        case 3:
                            vSetLedBrigth(temp_data);
                            break;
                        case 4:
                            vSetBackLigth(temp_data);
                            break;
                        case 5:
                            vSetBackLigthColor(temp_data);
                            break;
                      }
                    }
                }  
#ifdef DEBUG_PRINT
                if (++counter == 1000)
                {
                  counter=0;
                  if( max_clock<ulWorkCicleIn10us) max_clock =ulWorkCicleIn10us;
                  printf("timer = %i max_timer=%i\n",ulWorkCicleIn10us,max_clock);
                  printf("Memory %d\r\n",lua_gc(L1,LUA_GCCOUNT,0)*1024);
                }
#endif
                HAL_TimerReset(TIMER1);
                switch ( res)
                {
                    case LUA_OK:
                    case LUA_YIELD:
                         break;
                    default:
	   	   	              pcLuaErrorString =  (char *) lua_tostring( L1, LAST_ARGUMENT );
#ifdef DEBUG_PRINT
                        printf("Error = %s\r\n",pcLuaErrorString);
#endif
                        lua_state = LUA_ERROR;
                        break;  
                }
                lua_pop(L1,1);
                break;
              case LUA_ERROR:
                break;
        }
    }
}


/*
Функция отправки пакета по CAN. Вариативное кол-во агрументов, в завимости от DLC фрейма
*/
static int iCanSendData( lua_State *L )
{
    CAN_TX_FRAME_TYPE frame;
	  frame.DLC = lua_gettop(L)-1;  //Определяем кол-во агрументов, дожно быть как миниум 2 (CAN_ID и как миниум один байт данных)
	  if (frame.DLC + 1 >= TWO_ARGUMENTS)
	  {
		  for (int i=0; i< (frame.DLC) ;i++)
		  {
			  frame.data[i]= (uint8_t) lua_tointeger(L,-( frame.DLC-i)); 
		  }
      frame.ident = (uint32_t)lua_tointeger(L, FIRST_ARGUMENT);
      vSendCanData(&frame);
    }
	  return ( NO_RESULT );
}
/*
Функция отправки пакте по CAN, данные передаються таблицей
*/
static int iCanSendTable( lua_State *L )
{
  CAN_TX_FRAME_TYPE frame;
	if (lua_gettop(L)==  TWO_ARGUMENTS)  //Проверяем, что при вызове нам передали нужное число аргументов
	{
     if (lua_istable(L, LAST_ARGUMENT))   //Проверяем что в качестве аргумента передали таблицу
     { 	
      frame.ident = (uint32_t) lua_tointeger(L,FIRST_ARGUMENT);   //Читаем размер таблицы
			frame.DLC 	 = luaL_len(L, LAST_ARGUMENT);  //Читаем рамер таблицы
			if  (frame.DLC  <= CAN_FRAME_SIZE )
			{
				for (uint8_t i = 0; i < frame.DLC ; i++)
				{
					lua_geti(L, LAST_ARGUMENT , i +1 );   //Получаем элемент таблицы
					frame.data[i]=   lua_tointeger(L,LAST_ARGUMENT);  //Вытаскиваем данные из таблицы
					lua_pop(L,1);                         //Убираем значение из стэка
				}
				 vSendCanData(&frame);
			}
     }
	}
	return (  NO_RESULT );
}
/*
Инициализация контрллера CAN
*/
static int iCanSetConfig(lua_State *L)
{
	if (lua_gettop(L) == TWO_ARGUMENTS)
	{
    vCANBoudInit( (uint16_t)lua_tointeger( L, FIRST_ARGUMENT) );
    ConfigNodeID( (uint8_t) lua_tointeger( L, SECOND_ARGUMENT )); 
	}
	return ( NO_RESULT );
}
/*
Функция отправки даннх по CAN
*/
static void vSendCanData(CAN_TX_FRAME_TYPE * frame )
{
      if ((frame->ident &  CAN_EXT_FLAG) == CAN_EXT_FLAG)
      {
          frame->ident&=~CAN_EXT_FLAG;
          frame->id_type = HAL_CAN_EXTD_ID;
      }
      else
      {
        frame->id_type = HAL_CAN_STD_ID;
      }
      APPCANSEND(frame);	
}
/*
Функция установки CAN фильторв
*/
static int iCanSetResiveFilter(lua_State *L )
{
  uint8_t ucResNumber = NO_RESULT;
  if (lua_gettop(L) == ONE_ARGUMENT )  /*Проверяем, что при вызове нам передали нужное число аргументов*/
  {
	  lua_pushnumber(L, eMailboxFilterSet( ( uint32_t ) lua_tointeger(L,LAST_ARGUMENT ),INPUT_FILTER)== BUFFER_FULL ? 1U : 0U );
	  ucResNumber = ONE_RESULT;
  }
  return ( ucResNumber );
}
/*
Функция получаения пакет CAN 
*/
static int iCanGetResivedData(lua_State *L )
{
	uint8_t n;
  uint8_t res = 0;
	CAN_FRAME_TYPE  RXPacket;
	if (lua_gettop(L)==TWO_ARGUMENTS)
	{
	    if (lua_istable(L, LAST_ARGUMENT))   //Проверяем что в качестве аргумента передали таблицу
     { 
	    RXPacket.ident = (uint32_t) lua_tointeger(L,-2);
	    if ( vCanGetMessage(&RXPacket) == 1)
	    {
	        n = luaL_len(L, -1);
	    	for (int i = 1; i<(n+1);i++)
	    	{
	    	  lua_pushnumber(L,RXPacket.data[i-1]);
	    		lua_seti(L, -2, i);
	      }
	    	res = 1U;
	    }
     }
	}
  
  lua_pushnumber(L,res );
	return ( 1U );
}
/*
Функция сброса фильтра CAN
*/
static int iCanResetResiveFilter(lua_State *L )
{
  if (lua_gettop(L) == ONE_ARGUMENT )  /*Проверяем, что при вызове нам передали нужное число аргументов*/
  {
    eMailboxFilterReset( ( uint32_t ) lua_tointeger(L,FIRST_ARGUMENT));;
  }
  return ( NO_RESULT );
}