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
#include "UART.h"


void TIM2_Init( void )
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );
    TIM_DeInit( TIM2 );
    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = 100 - 1;
    TIM_TimeBaseStructure.TIM_Prescaler = SystemCoreClock / 1000000 - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM2, &TIM_TimeBaseStructure );
    /* Clear TIM2 update pending flag */
    TIM_ClearFlag( TIM2, TIM_FLAG_Update );
    /* TIM IT enable */
    TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE );
    /* Enable Interrupt */
    NVIC_EnableIRQ( TIM2_IRQn );
    /* TIM2 enable counter */
    TIM_Cmd( TIM2, ENABLE );
}

void InitDevice()
{
    HAL_InitGPO();
    HAL_InitGpioAF(CAN_Port,CAN_TX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_AF_PP);
    HAL_InitGpioAF(CAN_Port,CAN_RX_Pin,GPIO_Remap1_CAN1,GPIO_Mode_IPU);
    vAppInit();
    TIM2_Init();
    UART2_ParaInit( 1 );
    USBFS_RCC_Init( );
    USBFS_Device_Init( ENABLE );

}



