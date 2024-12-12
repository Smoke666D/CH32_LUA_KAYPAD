/*
 * system_init.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_SYSTEM_INIT_H_
#define USER_SYSTEM_INIT_H_


#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "semphr.h"
#include "message_buffer.h"
#include "portmacro.h"
#include "stdbool.h"


#define APP_TASK_PRIO               6  //§¥§°§­§¨§¦§¯ §¢§½§´§¾ §³§¡§®§½ §£§½§³§°§¬§ª§«
#define APP_STK_SIZE                256

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize );

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize );

void vSYStaskInit ( void );
void vSYSqueueInit ( void );
void vSYSeventInit ( void );

#endif /* USER_SYSTEM_INIT_H_ */
