/*
 * system_init.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "system_init.h"
#include "app_task.h"
#include "lawicel.h"


#define STORAGE_SIZE_BYTES 1000
static uint8_t ucTXMessageBufferStorage[ STORAGE_SIZE_BYTES ];
static StaticMessageBuffer_t xTXMessageBufferStruct;
static StaticTask_t xIdleTaskTCB;
static StaticTask_t xTimerTaskTCB;
static StaticTask_t xAPPTaskTCB;
static StaticTask_t xCanTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];
static StackType_t AppTaskBuffer[ APP_STK_SIZE ];
static StackType_t CanTaskBuffer[ CAN_STK_SIZE ];
uint8_t ucQueueStorageArea[  16U *sizeof(LAWICEL_CAN_MSG_t) ];
uint8_t ucTXQueueStorageArea[  16U *sizeof(CAN_TX_FRAME_TYPE) ];
static StaticQueue_t xStaticQueue;
static StaticQueue_t xStaticTXQueue;
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
    (* xGetCanTaskHandle ())
             = xTaskCreateStatic( vCanTask, "ProcessTask", CAN_STK_SIZE , ( void * ) 1, CAN_TASK_PRIO  ,
                                     (StackType_t * const ) CanTaskBuffer, &xCanTaskTCB );
  return;
}

INIT_FUNC_LOC void vSYSqueueInit ( void )
{

   * (xTXMessage()) = xMessageBufferCreateStatic( sizeof( ucTXMessageBufferStorage ),
           ucTXMessageBufferStorage,
           &xTXMessageBufferStruct );

   * (xRXQueue()) = xQueueCreateStatic( 16U, sizeof(LAWICEL_CAN_MSG_t),ucQueueStorageArea, &xStaticQueue );
   * (xTXQueue()) = xQueueCreateStatic( 16U, sizeof(CAN_TX_FRAME_TYPE),ucTXQueueStorageArea, &xStaticTXQueue );
}
/*----------------------------------------------------------------------------*/
void vSYSeventInit ( void )
{
 // *(osLUAetPDMstatusHandle () ) = xEventGroupCreateStatic(&xLuaStateEventGroup );
}
