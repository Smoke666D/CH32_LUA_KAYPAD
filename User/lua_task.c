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

static TaskHandle_t  LuaTaskHandle;
static LUA_STATE_t lua_state;
static char * pcLuaErrorString;

TaskHandle_t * xGetLuaTaskHandle ()
{
    return  &LuaTaskHandle ;
}


static int iCanSetResiveFilter(lua_State *L )
{
  uint8_t ucResNumber = NO_RESULT;
  if (lua_gettop(L) == 1U )  /*Проверяем, что при вызове нам передали нужное число аргументов*/
  {
	  lua_pushnumber(L, eMailboxFilterSet( ( uint32_t ) lua_tointeger(L,-1),INPUT_FILTER)== BUFFER_FULL ? 1U : 0U );
	  ucResNumber = ONE_RESULT;
  }
  return ( ucResNumber );
}

static int iCanResetResiveFilter(lua_State *L )
{
  if (lua_gettop(L) == 1U )  /*Проверяем, что при вызове нам передали нужное число аргументов*/
  {
    eMailboxFilterReset( ( uint32_t ) lua_tointeger(L,-1));;
  }
  return ( NO_RESULT );
}

static int iCanSetConfig(lua_State *L)
{
	if (lua_gettop(L) == TWO_ARGUMENTS)
	{
		uint8_t ucCanNumber =(uint8_t) lua_tointeger( L, FIRST_ARGUMENT); //First argument it's channel number
    vCANBoudInit( (uint16_t)lua_tointeger( L, SECOND_ARGUMENT) );

	}
	return ( NO_RESULT );
}

static int iCanSetNodeID(lua_State *L)
{
	if (lua_gettop(L) == TWO_ARGUMENTS)
	{
		ConfigNodeID( (uint8_t) lua_tointeger( L, FIRST_ARGUMENT)); 
   

	}
	return ( NO_RESULT );
}


static int iSetBackLigthBrigth(lua_State *L)
{
   if (lua_gettop(L) == ONE_ARGUMENT)
   {
      vSetBackLigth((uint8_t) lua_tointeger( L, FIRST_ARGUMENT));
   }
   return ( NO_RESULT );
}




void vSendCanData(CAN_TX_FRAME_TYPE * frame )
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
Функия отправки запроса. В качестве парамеров передаються
CAN_ID запроса, CAN_ID ответа, данные пакта запроса
*/
int iCanSendRequest( lua_State *L )
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
Функция отправки пакета по CAN. Вариативное кол-во агрументов, в завимости от DLC фрейма
*/
int iCanSendData( lua_State *L )
{
    CAN_TX_FRAME_TYPE frame;
	  frame.DLC = lua_gettop(L)-1;  //Определяем кол-во агрументов, дожно быть как миниум 2 (CAN_ID и как миниум один байт данных)
	  if (frame.DLC >= TWO_ARGUMENTS)
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
int iCanSendTable( lua_State *L )
{
  CAN_TX_FRAME_TYPE frame;
	if (lua_gettop(L)== CAN_SEND_TABLE_ARGUMENT_COUNT)  //Проверяем, что при вызове нам передали нужное число аргументов
	{
		if ( lua_istable(L, CAN_TABLE_POS ) )  //Убеждаемся что нам передали таблицу данных
		{
			frame.DLC 	= (uint8_t) lua_tointeger(L, FRAME_SIZE_POS);  //Читаем рамер таблицы
			if  (frame.DLC  <= CAN_FRAME_SIZE )
			{
				for (uint8_t i = 0; i < frame.DLC ; i++)
				{
					lua_geti(L, CAN_TABLE_POS , i + 1);
					frame.data[i]= lua_tointeger(L,-1);  //Вытаскиваем данные из таблицы
					lua_pop(L,1);
				}
        frame.ident = lua_tointeger(L, FIRST_ARGUMENT );
				 vSendCanData(&frame);
			}
		}
	}
	return (  NO_RESULT );
}

int iCanGetResivedData(lua_State *L )
{
	uint8_t n;
	CAN_FRAME_TYPE  RXPacket;
	if (lua_gettop(L)==2)
	{
	  
	    luaL_checktype(L, -1, LUA_TTABLE);
	    RXPacket.ident = (uint32_t) lua_tointeger(L,-2);
	    if ( vCanGetMessage(&RXPacket) == 1)
	    {
	        n = luaL_len(L, -1);
	    	for (int i = 1; i<(n+1);i++)
	    	{
	    	  lua_pushnumber(L,RXPacket.data[i-1]);
	    		lua_seti(L, -2, i);
	      }
	    	lua_pushnumber(L,1U );
	    }
	    else
	    {
	      lua_pushnumber(L,0U );
	    }
	}
	return ( 1U );
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
		    uiRes = vCanChekMessage( lua_tointeger(L, CAN_ID_POS) );
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


static const INIT_FUNC_LOC char Script[] = "CANID = 0x15 Keys = 0 OldKeys= 0 step = 0  time = 0 main = function () \n\
   \n\
 ConfigCan(1,250) t=0  \n\
 LED_BACK_LIGTH={[1]=14,[2]=0,[3]=0,[4]=0,[5]=0,[6]=0,[7]=0,[8]=0} \n\
 LED_BRIGTH={[1]=0,[2]=14,[3]=0,[4]=0,[5]=0,[6]=0,[7]=0,[8]=0} \n\
 LED_STATE={[1]=0,[2]=0,[3]=0,[4]=0,[5]=0,[6]=0,[7]=0,[8]=0} \n\
  ConfigNodeID(CANID) setCanFilter(0x500+CANID) setCanFilter(0x400+CANID) setCanFilter(0x300+CANID) setCanFilter(0x200+CANID) \n\
 while true do  t= t+time/100 if (t>1000) then\n\
  t=0 step=step+800  if step>26400 then step = 8000 end\n\
 CanSend(0x0CF00400 | 0x80000000 ,0x55,0x55,0x55,step and 0xFF,step >>8,0x55,0x55,0x56) end\n\
 \n\
 GetCanToTable( 0x500+CANID,LED_BACK_LIGTH) \n\
 GetCanToTable( 0x400+CANID,LED_BRIGTH) \n\
 GetCanToTable( 0x200+CANID,LED_STATE)  \n\
 if Keys ~=OldKeys then CanSend(0x180+CANID,Keys,0,0,0,0,0,0,0) OldKeys = Keys end \n\
 \n\
 \n\
     time,Keys = coroutine.yield(LED_BRIGTH[1],LED_BACK_LIGTH[1],LED_STATE[1],LED_STATE[2],LED_STATE[3]) end end";

int res ;

 
static lua_State *L1 = NULL;


void vLuaTask( void * argument )
{
   uint8_t data_buffer[5]={0,0,0,0,0};
 
    uint16_t counter = 0;
    lua_state = LUA_INIT;
    uint32_t ulWorkCicleIn10us;
    while(1)
    {
      vTaskDelay( 1 );
        switch (lua_state)
        {
            case LUA_INIT:
               L1  = luaL_newstate();
               luaL_openlibs(L1);
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
               lua_register(L1,"ConfigNodeID",      iCanSetNodeID);
               printf("Memory %d\r\n",lua_gc(L1,LUA_GCCOUNT,0)*1024);
               res =luaL_dostring(L1, Script);//, sizeof(Script)+1 , Script )));//  || lua_pcall(L1, 0, LUA_MULTRET, 0)) 	);
               printf("Res %d\r\n",res);
               printf("Memory %d\r\n",lua_gc(L1,LUA_GCCOUNT,0)*1024);
               HAL_TiemrEneblae(TIMER1);
               lua_getglobal(L1, "main");
               lua_state = LUA_RUN;
               break;
            case LUA_RUN:
                ulWorkCicleIn10us= HAL_GetTimerCnt(TIMER1);
                lua_pushinteger(L1, ulWorkCicleIn10us);
                lua_pushinteger(L1, getKeyData());
                res = lua_resume(L1,0,2);
                for (uint8_t i=0;i<5;i++)
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
                            vSetBrigth(temp_data);
                            break;
                        case 4:
                            vSetBackLigth(temp_data);
                            break;
                      }
                    }
                }  
                counter++;
                if (counter == 1000)
                {
                  counter=0;
                  printf("data %i %i %i",data_buffer[0],data_buffer[1],data_buffer[2]);
                  printf("timer = %i\r\n",ulWorkCicleIn10us);
                }
                HAL_TimerReset(TIMER1);
                switch ( res)
                {
                    case LUA_OK:
                    case LUA_YIELD:
                         vTaskDelay( 1 );
                         break;
                    default:
	   	   	            pcLuaErrorString =  (char *) lua_tostring( L1, LAST_ARGUMENT );
                        printf("Error = %s\r\n",pcLuaErrorString);
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
