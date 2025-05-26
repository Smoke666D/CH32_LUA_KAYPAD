/*
 * system_init.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "system_init.h"
#include "hw_lib_can.h"
#include "hal_can.h"
#include "io_task.h"
#include "hw_lib_keyboard.h"

static StaticTask_t xIdleTaskTCB;
static StaticTask_t xTimerTaskTCB;
static StaticTask_t xLuaTaskTCB;
static StaticTask_t xIOTaskTCB;
static StaticTask_t xCANRXTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];
static StackType_t CANRXTaskBuffer[ CANRX_STK_SIZE ];
static StackType_t LuaTaskBuffer[ LUA_STK_SIZE ];
static StackType_t IOTaskBuffer[ IO_STK_SIZE ];
static uint8_t canRXBuffer[ CANRX_QUEUE_SIZE * sizeof( CAN_FRAME_TYPE )  ];
static uint8_t canTXBuffer[ CANTX_QUEUE_SIZE * sizeof( CAN_FRAME_TYPE ) ];
uint8_t ucQueueStorageArea[  16U  ];
static StaticQueue_t xStaticQueue;
static StaticQueue_t xcanTXqueue;
static StaticQueue_t xcanRXqueue;
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
 (* xGetCanRXTaskHandle ())= xTaskCreateStatic( vCanRXTask, "CanrxTask", CANRX_STK_SIZE , ( void * ) 1, CANRX_TASK_PRIO  ,
      (StackType_t * const )CANRXTaskBuffer, &xCANRXTaskTCB );
 (* xGetIOTaskHandle ())= xTaskCreateStatic( vIOTask, "IOTask", IO_STK_SIZE , ( void * ) 1, IO_TASK_PRIO  ,
    (StackType_t * const )IOTaskBuffer, &xIOTaskTCB );
 (* xGetLuaTaskHandle()) = xTaskCreateStatic( vLuaTask, "LuaTask", LUA_STK_SIZE , ( void * ) 1, LUA_TASK_PRIO  ,
      (StackType_t * const )LuaTaskBuffer, &xLuaTaskTCB );
  return;
}

INIT_FUNC_LOC void vSYSqueueInit ( void )
{
 *( xKeyboardQueue()) = xQueueCreateStatic( 16U, sizeof( KeyEvent ),ucQueueStorageArea, &xStaticQueue );
 *( pCANRXgetQueue() ) = xQueueCreateStatic( CANRX_QUEUE_SIZE, sizeof( CAN_FRAME_TYPE), ( uint8_t* )canRXBuffer, &xcanRXqueue );
 *( pCANTXgetQueue() ) = xQueueCreateStatic( CANTX_QUEUE_SIZE, sizeof( CAN_TX_FRAME_TYPE ), ( uint8_t* )canTXBuffer, &xcanTXqueue );
}
/*----------------------------------------------------------------------------*/
void vSYSeventInit ( void )
{
 // *(osLUAetPDMstatusHandle () ) = xEventGroupCreateStatic(&xLuaStateEventGroup );
}
