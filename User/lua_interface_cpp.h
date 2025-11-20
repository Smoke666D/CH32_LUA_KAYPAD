
#ifndef LUA_INTERFACE_CPP_H_
#define LUA_INTERFACE_CPP_H_

#include "main.h"
#include "system_init.h"


#ifdef __cplusplus
 extern "C" {
#endif 

#include "lua.h"
#include "lua_task.h"
#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lapi.h"
LUAMOD_API int luaopen_dev (lua_State *L);
LUALIB_API void luaL_openuser (lua_State *L);

#ifdef __cplusplus
}
#endif

#endif 