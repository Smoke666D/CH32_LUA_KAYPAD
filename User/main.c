/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 *task1 and task2 alternate printing
 */


#include "FreeRTOS.h"
#include "task.h"
#include "system_init.h"
#include "lawicel.h"
#include "app_task.h"
#include "init.h"



/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
	SystemCoreClockUpdate();
    InitDevice();
    USART_Printf_Init( 115200) ;
    printf( "SystemClk:%d\r\n", SystemCoreClock );
	printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf( "Simulate USB-CDC/HID Device running on USBFS Controller\r\n" );
  
    vSYSqueueInit();
    vSYStaskInit();
    vTaskStartScheduler();

	while(1)
	{

	}
}
