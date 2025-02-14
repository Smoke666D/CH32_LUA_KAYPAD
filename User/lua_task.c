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

static TaskHandle_t  LuaTaskHandle;
static LUA_STATE_t lua_state;
static char * pcLuaErrorString;

TaskHandle_t * xGetLuaTaskHandle ()
{
    return  &LuaTaskHandle ;
}


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
                lua_state = LUA_RUN;
                break;
            case LUA_RUN:
                break;
        }

    }


}
