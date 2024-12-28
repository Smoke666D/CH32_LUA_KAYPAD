/*
 * init.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#include "init.h"
#include "app_task.h"
#include "hal_gpio.h"
#include "hal_timers.h"
#include "ch32v30x_usbfs_device.h"

static void vGpioInit();

void InitDevice()
{
    vGpioInit();
    vAppInit();
    UART2_ParaInit( 1 );
   // USBOTG_FS->UEP2_DMA = (uint32_t)(uint8_t *)&UART2_Tx_Buf[ 0 ];
  //  USBOTG_FS->UEP2_RX_CTRL &= ~USBFS_UEP_R_RES_MASK;
   // USBOTG_FS->UEP2_RX_CTRL |= USBFS_UEP_R_RES_ACK;
    USBFS_RCC_Init( );
    USBFS_Device_Init( ENABLE );


}



static void vGpioInit()
{
    HAL_InitGPO();
    HAL_InitGpioAF(CAN_Port,CAN_TX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_AF_PP);
    HAL_InitGpioAF(CAN_Port,CAN_RX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_IPU);
    HAL_InitGpioAF(RS_Port,RS_TX_Pin,0,GPIO_Mode_AF_PP);
    HAL_InitGpioIn(RS_Port,RS_RX_Pin);

}
