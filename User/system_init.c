/*
 * system_init.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "system_init.h"


static StaticTask_t xIdleTaskTCB;
static StaticTask_t xTimerTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

/*
 * 
 */

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
   *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
   *ppxIdleTaskStackBuffer = uxIdleTaskStack;
   *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}


void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize )
{
   *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
   *ppxTimerTaskStackBuffer = uxTimerTaskStack;
   *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}


/*----------------------------------------------------------------------------*/

