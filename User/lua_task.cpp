/*
 * lua_task.c
 *
 *  Created on: Feb 14, 2025
 *      Author: i.dymov
 */
#include "lua_interface_cpp.h"
#include "os_core.h"
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
static RESULT_t eIsLuaSkriptValid(const uint8_t* pcData, uint32_t size, uint32_t * real_size)
{
	RESULT_t ucRes = RESULT_FALSE;
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


const char* pcFLASHgetScript ( void )
{
  return ( const char* )( FLASH_STORAGE_ADR + FLASH_STORAGE_LENGTH_SIZE );
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


class cpp_lua_task : os::os_task<cpp_lua_task, LUA_STK_SIZE>
{
protected:
 
  TickType_t xLastWakeTime;
  
 public:
    void run(void )  __attribute__((__noreturn__)) ;        
    using os_task::os_task;
};

cpp_lua_task lua_task ={"lua_Task",LUA_TASK_PRIO};

void cpp_lua_task::run( void  )
{
    char * pcLuaErrorString;
    int res ;
    lua_State *L1;
    LUA_STATE_t lua_state = LUA_INIT;
    uint32_t ulWorkCicleIn10us;
    uint32_t mid_time= 0;
    xLastWakeTime = xTaskGetTickCount();
#ifdef DEBUG_PRINT
    uint16_t counter = 0;
    uint32_t max_clock = 0;
#endif
    while(1)
    {
        vTaskDelayUntil( &xLastWakeTime,2);
        HAL_WDTReset();
        switch (lua_state)
        {
            case LUA_INIT:
               lua_state = LUA_ERROR;
               L1  = luaL_newstate();  //Созадем состояние LUA, занимет 2К оперативной памяти
               luaL_openlibs(L1);      //Подлючаем библиотеки
               //Регестрируем пользовательские функции
               luaL_openuser(L1);
              
              uint32_t real_size;
              if ( eIsLuaSkriptValid(uFLASHgetScript(), uFLASHgetLength()+1,&real_size) == RESULT_TRUE )
	   	         {     
	   	    	      if (luaL_loadbuffer(L1, pcFLASHgetScript() , real_size , pcFLASHgetScript())==0 )  
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
                HAL_TimerReset(TIMER1);
                lua_pushinteger(L1, ulWorkCicleIn10us);
                res = lua_resume(L1,0,1);       //Возобновляем выполнение скрита
#ifdef DEBUG_PRINT
                mid_time+=ulWorkCicleIn10us;
                if (++counter == 1000)
                {
                  counter=0;
                  if( max_clock<ulWorkCicleIn10us) max_clock =ulWorkCicleIn10us;
                  printf("timer = %i max_timer=%i\n",ulWorkCicleIn10us,mid_time/1000);
                  mid_time = 0;
                  printf("Memory %d\r\n",lua_gc(L1,LUA_GCCOUNT,0)*1024);
                }
#endif          
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



