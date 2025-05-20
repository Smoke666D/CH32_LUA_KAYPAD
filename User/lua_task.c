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
	  lua_pushnumber(L, eMailboxFilterSet( ( uint32_t ) lua_tointeger(L,-1))== BUFFER_FULL ? 1U : 0U );
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

int iCanSendPDM( lua_State *L )
{
  
    CAN_TX_FRAME_TYPE frame;
	  uint8_t  size = lua_gettop(L);
    frame.DLC = size;
	  if (size >= TWO_ARGUMENTS)
	  {
		  size--;
		  for (int i=0;i< size ;i++)
		  {
			  frame.data[i]= (uint8_t) lua_tointeger(L,-( size-i)); /*Третьем агрументом должно передоватьс время плавного старта в милисекундах*/
		  }
      frame.ident = (uint32_t)lua_tointeger(L, FIRST_ARGUMENT);
      if ((frame.ident &  CAN_EXT_FLAG) == CAN_EXT_FLAG)
      {
          frame.ident&=~CAN_EXT_FLAG;
          frame.id_type = HAL_CAN_EXTD_ID;
      }
      else
      {
        frame.id_type = HAL_CAN_STD_ID;
      }
      APPCANSEND(&frame);	
	  }
	  return ( NO_RESULT );
}

int iCanCheckData(lua_State *L )
{
	uint32_t uiRes = 0U;
	if (lua_gettop(L) == 1)
	{
		  uiRes = vCanChekMessage( lua_tointeger(L, CAN_ID_POS) );
	}
	lua_pushnumber(L, uiRes );
	return ( 1U );
}


int iCanGetMessage(lua_State *L )
{
	uint8_t n = 0;
	CAN_FRAME_TYPE  RXPacket;
	if (lua_gettop(L) == 1)
	{
	
			luaL_checktype(L, 1, LUA_TNUMBER);
			RXPacket.ident = (uint32_t) lua_tointeger(L,1);
			n= vCanGetMessage(&RXPacket);
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


static const char * Script = "In1 = 0 step = 0 Out1 = false time = 0 main = function () \n\
 function stop()  time,In1 = coroutine.yield(Out1,i)  end  \n\
 ConfigCan(1,250) t=0 \n\
 while true do  t= t+time/100 if (t>1000) then\n\
  t=0 step=step+800  if step>26400 then step = 8000 end\n\
 CanSend(0x0CF00400 | 0x80000000 ,0x55,0x55,0x55,step and 0xFF,step >>8,0x55,0x55,0x56) end\n\
  Out1 = not Out1   stop() end end";

int res ;

 
static lua_State *L1 = NULL;
 void InitLuaTask()
{
      
              
 
}



void vLuaTask( void * argument )
{
   int ss =200;
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
              lua_register(L1,"CanSend", iCanSendPDM);
               lua_register(L1,"CheckCanId", iCanCheckData );
	             lua_register(L1,"GetCanMessage",iCanGetMessage) ;
               lua_register(L1,"setCanFilter", iCanSetResiveFilter );
               lua_register(L1,"ResetCanFilter", iCanResetResiveFilter );
	             lua_register(L1,"GetCanToTable",iCanGetResivedData);
	             lua_register(L1,"ConfigCan",iCanSetConfig);
               res =luaL_dostring(L1, Script);//, sizeof(Script)+1 , Script )));//  || lua_pcall(L1, 0, LUA_MULTRET, 0)) 	);
               printf("Res %d\r\n",res);
               HAL_TiemrEneblae(TIMER1);
               lua_state = LUA_RUN;
               break;
            case LUA_RUN:
                lua_getglobal(L1, "main");
                
                ss=10000;
               
                // int temp;
                ulWorkCicleIn10us= HAL_GetTimerCnt(TIMER1);
                lua_pushinteger(L1, ulWorkCicleIn10us);
                lua_pushinteger(L1, ss);
                res = lua_resume(L1,0,2);
                printf("timer = %i",ulWorkCicleIn10us);
                HAL_TimerReset(TIMER1);
              //  printf("%d\r\n", lua_gettop(L1));
              //  printf("%d\r\n", lua_tointeger(L1, 1)); 
               
             //   printf("%d\r\n", lua_tointeger(L1, 2));
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
