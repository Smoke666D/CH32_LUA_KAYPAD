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


void InitDevice()
{
    HAL_InitGPO();
    HAL_InitGpioAF(CAN_Port,CAN_TX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_AF_PP);
    HAL_InitGpioAF(CAN_Port,CAN_RX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_IPU);
    HAL_InitGpioAF(RS_Port,RS_TX_Pin,0,GPIO_Mode_AF_PP);
    HAL_InitGpioIn(RS_Port,RS_RX_Pin);
    vAppInit();
}



