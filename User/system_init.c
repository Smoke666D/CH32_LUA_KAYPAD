/*
 * system_init.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "system_init.h"
#include "app_task.h"
#include "lawicel.h"

static StaticTask_t xIdleTaskTCB;
static StaticTask_t xTimerTaskTCB;
static StaticTask_t xAPPTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];
static StackType_t AppTaskBuffer[ APP_STK_SIZE ];
uint8_t ucQueueStorageArea[  16U  ];
static StaticQueue_t xStaticQueue;
/*
 * 妤快把快技快扶扶抑快
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


INIT_FUNC_LOC  void vSYStaskInit ( void )
{

    (* xGetAppTaskHandle()) = xTaskCreateStatic( vAppTask, "AppTask", APP_STK_SIZE , ( void * ) 1, APP_TASK_PRIO  ,
            (StackType_t * const )AppTaskBuffer, &xAPPTaskTCB );
  /* (* xProcessTaskHandle ())
             = xTaskCreateStatic( vRedrawTask, "ProcessTask", PROCESS_STK_SIZE , ( void * ) 1, PROCESS_TASK_PRIO  ,
                                     (StackType_t * const )ProcessTaskBuffer, &ProcessTaskControlBlock );
  (* xCanOpenPeriodicTaskHandle ())
  = xTaskCreateStatic( vCanOpenPeriodicProcess, "CanOpenPeriodic", PERIODIC_CAN_STK_SIZE , ( void * ) 1, PERIODIC_CAN_TASK_PRIO ,
                     (StackType_t * const )CanOpnePeriodicTaskBuffer, &CanOpnePeriodicTaskControlBlock );
  (* xCanOpenProcessTaskHandle())
  = xTaskCreateStatic( vCanOpenProcess, "CanOpenProcessTask", CAN_OPEN_STK_SIZE , ( void * ) 1, CAN_OPEN_TASK_PRIO ,
  (StackType_t * const )CanOpneProccesTaskBuffer, &CanOpneProccesTaskControlBlock );
 (* getInputsTaskHandle()) =   xTaskCreateStatic( vInputsTask, "InputsTask", INPUTS_TASK_STACK_SIZE , ( void * ) 1, INPUT_TASK_PRIO, (StackType_t * const )InputsTaskBuffer, &InputsTaskControlBlock );
  DefautTask_Handler = xTaskCreateStatic( StartDefaultTask, "DefTask", DEFAULT_TASK_STACK_SIZE , ( void * ) 1, DEFAULT_TASK_PRIOR, (StackType_t * const )defaultTaskBuffer, &defaultTaskControlBlock );
  vTaskSuspend(* xProcessTaskHandle ());
  vTaskSuspend( *xCanOpenPeriodicTaskHandle ());
  vTaskSuspend( *xCanOpenProcessTaskHandle());
  vTaskSuspend(* getInputsTaskHandle());*/
  return;
}

INIT_FUNC_LOC void vSYSqueueInit ( void )
{

   * (xRXQueue()) = xQueueCreateStatic( 16U, 1,ucQueueStorageArea, &xStaticQueue );
}
/*----------------------------------------------------------------------------*/
void vSYSeventInit ( void )
{
 // *(osLUAetPDMstatusHandle () ) = xEventGroupCreateStatic(&xLuaStateEventGroup );
}
