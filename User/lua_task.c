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

static TaskHandle_t  LuaTaskHandle;
static LUA_STATE_t lua_state;
static char * pcLuaErrorString;

TaskHandle_t * xGetLuaTaskHandle ()
{
    return  &LuaTaskHandle ;
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


static const char * Script = "Out1 = false  main = function () function stop()  In1 = coroutine.yield(Out1,i)  end  i = 0 \n\
while true do  i = i+ 1 if (i == 1000) then i = 0   Out1 = not Out1 end  stop() end end";

 int res ;
void vLuaTask( void * argument )
{
   
    lua_State *L = NULL;
    lua_State *L1 = NULL;
    lua_state = LUA_INIT;
    while(1)
    {
      vTaskDelay( 1 );
        switch (lua_state)
        {
            case LUA_INIT:
            
                L  = luaL_newstate();
                L1 = lua_newthread(L);
                luaL_openlibs(L1);
               // lua_register(L1,"setCanFilter", iCanSetResiveFilter);
               // lua_register(L1,"CanSend", iCanSendPDM);
               // lua_register(L1,"CheckCanId", iCanCheckData);
	   	       // lua_register(L1,"GetCanMessage",iCanGetMessage);
	   	       // lua_register(L1,"GetCanToTable",iCanGetResivedData);
	   	       // lua_register(L1,"sendCandRequest",iCanSendRequest);
	   	       // lua_register(L1,"CheckAnswer", iCanCheckData);
	   	       // lua_register(L1,"GetRequest",iCanGetMessage);
	   	       // lua_register(L1,"GetRequestToTable",iCanGetResivedData);
	   	        lua_register(L1,"ConfigCan",iCanSetConfig);
                
                res =luaL_dostring(L1, Script);//, sizeof(Script)+1 , Script )));//  || lua_pcall(L1, 0, LUA_MULTRET, 0)) 	);
                
                printf("Res %d\r\n",res);
                lua_state = LUA_RUN;
                break;
            case LUA_RUN:
                lua_getglobal(L1, "main");
                lua_pushinteger(L1, 20);
                // int temp;

                res = lua_resume(L1,L,1);

    
             
              //  printf("%d\r\n", lua_gettop(L1));
              //  printf("%d\r\n", lua_tointeger(L1, 1)); 
               
             //   printf("%d\r\n", lua_tointeger(L1, 2));
                switch ( res)
                {
                    case  LUA_OK:
                    case LUA_YIELD:
 
                         vTaskDelay( 1 );
                         break;
                    default:
	   	   	            pcLuaErrorString =  (char *) lua_tostring( L1, LAST_ARGUMENT );
                        printf("Error = %s\r\n",pcLuaErrorString);
                        lua_state = LUA_ERROR;
                        break;
                        
                }
               // lua_state = LUA_ERROR;
                lua_pop(L1,1);
                break;
              case LUA_ERROR:
                break;
        }

    }


}
