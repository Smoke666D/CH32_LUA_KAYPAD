/*
 * app_task.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "app_task.h"

#include "hal_usart.h"
#include "lawicel.h"
#include "hal_can.h"
#include "hal_timers.h"

static TaskHandle_t  AppTaskHandle;
static QueueHandle_t    pRXQueue;


#define   STORAGE_SIZE_BYTES 100
static uint8_t ucMessageBufferStorage[ STORAGE_SIZE_BYTES ];
#define STREAM_BUFFER_SIZE_BYTES 100
static uint8_t ucTXStreamBufferStorage[ STREAM_BUFFER_SIZE_BYTES + 1 ];
static uint8_t ucRXStreamBufferStorage[ STREAM_BUFFER_SIZE_BYTES + 1 ];
static StaticStreamBuffer_t xTXStreamBufferStruct;
static StaticStreamBuffer_t xRXStreamBufferStruct;
static StreamBufferHandle_t xRXStreamBuffer;
static StreamBufferHandle_t xTXStreamBuffer;


static MessageBufferHandle_t xCANRXMessageBuffer;
static StaticMessageBuffer_t xMessageBufferStruct;
#define RX_BUFFER_SIZE  100
static u8 RX_DATA_BUFFER[RX_BUFFER_SIZE];
static u8 TX_DATA_BUFFER[RX_BUFFER_SIZE];
static u8 TX_SIZE;
static u8 RX_INDEX = 0;
static u8 data_byte;



QueueHandle_t * xRXQueue( void )
{
  return  (&pRXQueue);
}






TaskHandle_t * xGetAppTaskHandle ()
{
    return  &AppTaskHandle ;
}

void TX_Callback(void)
{
    uint8_t tx_data;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if (xStreamBufferReceiveFromISR(xTXStreamBuffer,&tx_data,1,&xHigherPriorityTaskWoken ) > 0 )
    {
        HAL_SendByte_IT(HAL_USART3,tx_data);
    }
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

void RX_Callback( void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    HAL_RecieveByte_IT(HAL_USART3 ,&data_byte);
    uint8_t data = data_byte;
    xStreamBufferSendFromISR(xRXStreamBuffer, &data, 1, &xHigherPriorityTaskWoken);
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

void vCallBack()
{}



void vAppInit()
{
   xCANRXMessageBuffer = xMessageBufferCreateStatic(sizeof(ucMessageBufferStorage),ucMessageBufferStorage,&xMessageBufferStruct);
   xTXStreamBuffer = xStreamBufferCreateStatic(STREAM_BUFFER_SIZE_BYTES,1,ucTXStreamBufferStorage,&xTXStreamBufferStruct );
   xRXStreamBuffer = xStreamBufferCreateStatic(STREAM_BUFFER_SIZE_BYTES,1,ucRXStreamBufferStorage,&xRXStreamBufferStruct );
   LAWICEL_Init(&xCANRXMessageBuffer);
   HAL_CANToInitMode();
   HAL_CANSetRXCallback(&ProcessMsgFromCan);
   HAL_CANSetERRCallback(&vCallBack);
   HAL_CANSetTXCallback(&vCallBack);


   HALUSARTInit(HAL_USART3,115200,HAL_StopBits_1,HAL_Parity_No,UART_WORDLENGTH_8B);
   HALUSARTInitIT(HAL_USART3,&RX_Callback,&TX_Callback,1,1);
   HALUSARTEnable(HAL_USART3);
   HAL_RecieveByte_IT(HAL_USART3 ,&data_byte);
   HAL_TIMER_InitIt(TIMER1,100000,99,&MSTimrCallBack,1,0);
   HAL_TiemrEneblae(TIMER1);
}

void SendDataToSerial( uint8_t * data_buffer, uint8_t data_size)
{
    uint8_t cur_data_szie =  data_size;
    if (xStreamBufferIsEmpty(xTXStreamBuffer) == pdTRUE )
    {
        cur_data_szie--;
        xStreamBufferSend( xTXStreamBuffer,( void * ) &data_buffer[ 1 ], cur_data_szie, 0 );
        HAL_SendByte_IT(HAL_USART3,data_buffer[0]);
    }
    else
    {
        xStreamBufferSend( xTXStreamBuffer,( void * ) &data_buffer[0], cur_data_szie, 0 );
    }
}

void vAppTask( void * argument )
{
    uint8_t RXDATA[100];
    uint8_t cmd_len;
    while(1)
    {
        if (xStreamBufferIsEmpty(xRXStreamBuffer) == pdFALSE)
        {
            uint8_t data_size =  xStreamBufferReceive(xRXStreamBuffer,RXDATA,100,0);
            for (uint8_t i =0 ; i < data_size;i++)
            {
                RX_DATA_BUFFER[RX_INDEX] = RXDATA[i];
                if (RX_INDEX <= (RX_BUFFER_SIZE )) RX_INDEX++;
                if (RXDATA[i] =='\r')
                {
                    cmd_len = RX_INDEX -1;
                    DataParser( RX_DATA_BUFFER, cmd_len,TX_DATA_BUFFER,&TX_SIZE);
                    if (TX_SIZE!= 0)
                    {
                        SendDataToSerial(TX_DATA_BUFFER,TX_SIZE);
                    }
                    RX_INDEX = 0;
                }
            }
        }
        if (xMessageBufferIsEmpty(xCANRXMessageBuffer) == pdFALSE)
        {
            TX_SIZE = xMessageBufferReceive( xCANRXMessageBuffer, TX_DATA_BUFFER, sizeof(ucMessageBufferStorage),0);
            SendDataToSerial(TX_DATA_BUFFER,TX_SIZE);
        }
    }
}



