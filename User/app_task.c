/*
 * app_task.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "app_task.h"
#include "hal_usart.h"
#include "lawicel.h"

static TaskHandle_t  AppTaskHandle;
static QueueHandle_t    pRXQueue;
static QueueHandle_t    pTXQueue;
static QueueHandle_t    pCANRXQueue;

#define RX_BUFFER_SIZE  40
static u8 RX_DATA_BUFFER[RX_BUFFER_SIZE];
static u8 TX_DATA_BUFFER[RX_BUFFER_SIZE];
static u8 TX_SIZE;
static u8 RX_INDEX = 0;
static u8 RX_SIZE  = 0;
static u8 data_byte;



QueueHandle_t * xRXQueue( void )
{
  return  (&pRXQueue);
}

QueueHandle_t * xTXQueue( void )
{
  return  (&pTXQueue);
}

QueueHandle_t * xCANRXQueue( void )
{
  return  (&pCANRXQueue);
}


TaskHandle_t * xGetAppTaskHandle ()
{
    return  &AppTaskHandle ;
}

void TX_Callback(void)
{
    uint8_t tx_data;
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    if ( xQueueReceiveFromISR(pTXQueue, &tx_data, &xHigherPriorityTaskWoken ) == pdPASS )
    {
        HAL_SendByte_IT(HAL_USART3,tx_data);
    }
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

void RX_Callback( void)
{
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    u8 data = data_byte;
    HAL_RecieveByte_IT(HAL_USART3 ,&data_byte);
    xQueueSendFromISR( pRXQueue, &data, &xHigherPriorityTaskWoken );
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

void vAppInit()
{
    HALUSARTInit(HAL_USART3,115200,HAL_StopBits_1,HAL_Parity_No,UART_WORDLENGTH_8B);
    HALUSARTInitIT(HAL_USART3,&RX_Callback,&TX_Callback,1,1);
    HALUSARTEnable(HAL_USART3);
    HAL_RecieveByte_IT(HAL_USART3 ,&data_byte);
}

void vAppTask( void * argument )
{
    uint8_t data;
    uint8_t cmd_len;
    while(1)
    {
        if ( uxQueueMessagesWaiting(pRXQueue) != 0)
        {
            if ( xQueueReceive(pRXQueue, &data, 0U ) == pdPASS )
            {
                RX_DATA_BUFFER[RX_INDEX] = data;
                if (RX_SIZE <= (RX_BUFFER_SIZE )) RX_SIZE++;
                if (data =='\r')
                {
                    cmd_len = RX_INDEX -1;
                    DataParser( RX_DATA_BUFFER, cmd_len,TX_DATA_BUFFER,&TX_SIZE);
                    if (TX_SIZE!= 0)
                    {
                        for (uint8_t i =1; i< TX_SIZE;i++)
                        {
                            xQueueSend(pTXQueue,&TX_DATA_BUFFER[i],1);
                        }
                        HAL_SendByte_IT(HAL_USART3,TX_DATA_BUFFER[0]);
                        while ( uxQueueMessagesWaiting(pTXQueue) != 0);
                    }
                }

            }
        }
        if ( uxQueueMessagesWaiting(pCANRXQueue) != 0)
        {


        }
    }
}



