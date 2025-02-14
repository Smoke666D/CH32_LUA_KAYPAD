/*
 * lua_task.h
 *
 *  Created on: Feb 14, 2025
 *      Author: i.dymov
 */

#ifndef USER_LUA_TASK_H_
#define USER_LUA_TASK_H_

#include "main.h"
#include "system_init.h"


typedef enum {
    LUA_INIT,
    LUA_RUN,
    LUA_ERROR,
    LUA_STOP,
    LUA_RESTART,
    LUA_STATE_SIZE,
    LUA_WAIT_READY
} LUA_STATE_t;


TaskHandle_t * xGetLuaTaskHandle ();
void vLuaTask( void * argument );

#endif /* USER_LUA_TASK_H_ */
