/*
 * app_task.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */
#include "app_task.h"
#include "hal_usart.h"
#include "lawicel.h"
#include "hal_dma.h"
#include "hal_can.h"
#include "hal_timers.h"
#include "UART.h"


#define UART_RX_BUFFERS_COUNT 2
#define   STORAGE_SIZE_BYTES 100
#define STREAM_BUFFER_SIZE_BYTES 100
#define UART_RX_LINE_BUFFER 80



static int uartLineIndex = 0;
static uint8_t uartLine[UART_RX_LINE_BUFFER];
static uint8_t tx_data_transfer = 0;
static TaskHandle_t         AppTaskHandle;
static TaskHandle_t         CanRecieveTaskHandle;
static QueueHandle_t        pRXQueue;
static QueueHandle_t        pTXQueue;
static MessageBufferHandle_t USART_TX_Message;
static uint8_t ucMessageBufferStorage[ STORAGE_SIZE_BYTES ];
static uint8_t ucRXStreamBufferStorage[ STREAM_BUFFER_SIZE_BYTES + 1 ];
static uint8_t dma_buff[100];
static StaticStreamBuffer_t xRXStreamBufferStruct;
static StreamBufferHandle_t xRXStreamBuffer;
static MessageBufferHandle_t xCANRXMessageBuffer;
static StaticMessageBuffer_t xMessageBufferStruct;
static int currentUartRxBufferToRead = 0;
static uint8_t uartRxBuffer[UART_RX_BUFFER];


static void SendDataToSerial( uint8_t * data_buffer, uint8_t data_size);


MessageBufferHandle_t * xTXMessage(void)
{
    return (&USART_TX_Message);
}

QueueHandle_t * xRXQueue( void )
{
  return  (&pRXQueue);
}

QueueHandle_t * xTXQueue( void )
{
  return  (&pTXQueue);
}

TaskHandle_t * xGetCanTaskHandle ()
{
    return  &CanRecieveTaskHandle ;
}


TaskHandle_t * xGetAppTaskHandle ()
{
    return  &AppTaskHandle ;
}



void DMA_Callback()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    HAL_DMA_Disable(DMA1_CH2);
    uint8_t size = xMessageBufferReceiveFromISR(USART_TX_Message,&dma_buff,100,&xHigherPriorityTaskWoken);
    if ( size >0 )
        HAL_DMA_Start(DMA1_CH2,size,(u32)dma_buff);
    else
        tx_data_transfer =0;
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );


}



void APPCANSEND(CAN_TX_FRAME_TYPE *buffer)
{
    if (HAL_CANSend(buffer)==CAN_TxStatus_NoMailBox)
    {
        xQueueSend(pTXQueue,buffer,portMAX_DELAY);
    }


}

void vCallBack()
{
    CAN_TX_FRAME_TYPE buffer;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if (xQueueReceiveFromISR(pTXQueue,&buffer,&xHigherPriorityTaskWoken)==pdPASS)
    {
        HAL_CANSend(&buffer);
    }
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}

void MsgFromCan( HAL_CAN_RX_FIFO_NUMBER_t fifo)
{
   LAWICEL_CAN_MSG_t msg_to_send;
   BaseType_t xHigherPriorityTaskWoken = pdFALSE;
   HAL_CAN_MSG_GET(  fifo,  &msg_to_send.msg );
   msg_to_send.time_stamp =getTimeCounter();
   xQueueSendFromISR(pRXQueue,&msg_to_send,&xHigherPriorityTaskWoken);
   portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}



RCC_ClocksTypeDef RCC_ClocksStatus;

void vAppInit()
{
   xCANRXMessageBuffer = xMessageBufferCreateStatic(sizeof(ucMessageBufferStorage),ucMessageBufferStorage,&xMessageBufferStruct);
   xRXStreamBuffer = xStreamBufferCreateStatic(STREAM_BUFFER_SIZE_BYTES,1,ucRXStreamBufferStorage,&xRXStreamBufferStruct );
   LAWICEL_Init(&xCANRXMessageBuffer, APPCANSEND);
   HAL_CANToInitMode();
   RCC_GetClocksFreq(&RCC_ClocksStatus);
   HAL_CANSetRXCallback(&MsgFromCan);
   HAL_CANSetERRCallback(&vCallBack);
   HAL_CANSetTXCallback(&vCallBack);
   HAL_TIMER_InitIt(TIMER1,100000,99,&MSTimrCallBack,1,0);
   HAL_TiemrEneblae(TIMER1);
}


static void SendDataToSerial( uint8_t * data_buffer, uint8_t data_size)
{
    if (data_size <= DEF_USBD_FS_PACK_SIZE)
    {
        xMessageBufferSend(USART_TX_Message,( void * ) data_buffer, data_size, 1);
    }
    else 
    {
        uint8_t temp_size = data_size;
        uint8_t cur_size;
        uint8_t offset = 0;
        while (temp_size)
        {
            if (temp_size >= DEF_USBD_FS_PACK_SIZE) cur_size = DEF_USBD_FS_PACK_SIZE;
            else 
            {
                cur_size = temp_size;
            }
            xMessageBufferSend(USART_TX_Message,( void * ) &data_buffer[offset], cur_size, 1);
            temp_size = temp_size - cur_size; 
            offset = offset + cur_size;

        }
    }
}



void vAppTask( void * argument )
{
    currentUartRxBufferToRead = 0;
    while(1)
    {
       UART2_DataRx_Deal( );
       currentUartRxBufferToRead = UART2_DataTx_Deal( uartRxBuffer) ;
       if (currentUartRxBufferToRead  != 0)
       {
            uint8_t read_p = 0;   
            while(read_p  < currentUartRxBufferToRead)
            {
                uint8_t c = uartRxBuffer[read_p];
                switch (c)
                {
                    case '\0':
                    case '\r':
                    case '\n':
                        if (uartLineIndex > 0)
                        {
                            DataParser( uartLine, uartLineIndex,&SendDataToSerial);
                            uartLineIndex = 0;
                        }
                        break;
                    default:
                        uartLine[uartLineIndex++] = c;
                        break;
            }
            read_p++;
        }    
      }  
    }
}
/*
 *  §©§Ñ§Õ§Ñ§é§Ñ §à§Ò§â§Ñ§Ò§à§ä§Ü§Ú §á§â§Ú§ç§à§Õ§Ú§ë§Ú§ç §á§Ñ§Ü§ä§à§Ó CAN
 */
void vCanTask( void * argument )
{
    LAWICEL_CAN_MSG_t msg;
    while(1)
    {
        //§¨§Õ§Ö§Þ §á§à§Ü§Ñ §Ó §à§é§Ö§â§Ö§Õ§Ú §ß§Ö §á§à§ñ§Ó§Ú§ä§ã§ñ §á§Ñ§Ü§Ö§ä
        xQueueReceive(pRXQueue,&msg,portMAX_DELAY);
        //§°§ä§á§â§Ñ§Ó§Ý§ñ§Ö§Þ §Ö§Ô§à §ß§Ñ §à§Ò§â§Ñ§Ò§à§ä§Ü§å, §Ó §Ü§Ñ§é§Ö§ä§ã§Ó§Ö §á§Ñ§â§Ñ§Þ§Ö§ä§â§Ñ callback §ß§Ñ §æ§å§ß§Ü§Ú§ð §á§Ö§â§Ö§Õ§Ñ§é§Ú
        //§Õ§Ñ§ß§ß§í§ç §á§à USART DMA
        ParseCanMessage(msg,&SendDataToSerial);
    }
}





