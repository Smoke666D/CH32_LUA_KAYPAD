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
static int currentUartRxBuffer = 0;
static int currentUartRxBufferToRead = 0;
UART_DMA_RX_Buffer uartRxBuffer[UART_RX_BUFFERS_COUNT]= {
    { .readed = 0, .filled = 0, .offset = 0 },
    { .readed = 0, .filled = 0, .offset = 0 }
};


static void gotoNextBufferToRead();
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


void startUartDmaReceive( UART_DMA_RX_Buffer *uartRxBuffer)
{
    uartRxBuffer->readed = 0;
    HAL_DMA_Start(DMA1_CH3,UART_RX_BUFFER,(u32)uartRxBuffer->buffer);
}



void DMA_RX_Callback()
{
    HAL_DMA_Disable(DMA1_CH3);
    uartRxBuffer[currentUartRxBuffer].filled = 1;
    currentUartRxBuffer++;
    currentUartRxBuffer %= UART_RX_BUFFERS_COUNT;
    startUartDmaReceive(&uartRxBuffer[currentUartRxBuffer]);
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
   LAWICEL_Init(&xCANRXMessageBuffer);
   HAL_CANToInitMode();
   RCC_GetClocksFreq(&RCC_ClocksStatus);
   HAL_CANSetRXCallback(&MsgFromCan);
   HAL_CANSetERRCallback(&vCallBack);
   HAL_CANSetTXCallback(&vCallBack);
 //  HAL_CANIntIT(2,2,0);
                           /* CAN_FilterInitTypeDef CAN_FilterInitSturcture={0};
                            CAN_FilterInitSturcture.CAN_FilterNumber = 0;
                            CAN_FilterInitSturcture.CAN_FilterMode = CAN_FilterMode_IdMask;
                            CAN_FilterInitSturcture.CAN_FilterScale = CAN_FilterScale_32bit;
                            CAN_FilterInitSturcture.CAN_FilterIdHigh = 0;
                            CAN_FilterInitSturcture.CAN_FilterIdLow = 0;
                            CAN_FilterInitSturcture.CAN_FilterMaskIdHigh =0;
                            CAN_FilterInitSturcture.CAN_FilterMaskIdLow = 0;
                            CAN_FilterInitSturcture.CAN_FilterFIFOAssignment = CAN_Filter_FIFO1;
                            CAN_FilterInitSturcture.CAN_FilterActivation = ENABLE;
                            CAN_FilterInit( &CAN_FilterInitSturcture );
                          *///  HAL_CANToInitMode();
   
   HAL_TIMER_InitIt(TIMER1,100000,99,&MSTimrCallBack,1,0);
   HAL_TiemrEneblae(TIMER1);
}



static void SendDataToSerial( uint8_t * data_buffer, uint8_t data_size)
{
    if ( !tx_data_transfer )
    {
        tx_data_transfer = 1;
        memcpy(dma_buff,data_buffer,data_size);
        HAL_DMA_Disable(DMA1_CH2);
        ulTaskNotifyTake(0,0);
        HAL_DMA_Start(DMA1_CH2,data_size,(u32)dma_buff);
    }
    else
    {
        xMessageBufferSend(USART_TX_Message,( void * ) data_buffer, data_size, 1);
    }
}



int processUartDmaBuffer( UART_DMA_RX_Buffer *uartRxBuffer)
{
    int itemsProcessed = 0;
    int dmaOffset;
    if (uartRxBuffer->readed) { return itemsProcessed; }
    if (uartRxBuffer->filled)
    {
        dmaOffset = UART_RX_BUFFER;
    }
    else
    {
        dmaOffset = UART_RX_BUFFER -  HAL_DMA_GetCounter(DMA1_CH3);
    }
    //§±§â§à§Ó§Ö§â§ñ§Ö§Þ §ã§à§ã§ä§à§ñ§ß§Ö §Ò§å§æ§æ§Ö§â§Ñ §á§â§Ú§Ö§Þ§Ñ
    int bytesReady = dmaOffset - uartRxBuffer->offset;
    if (bytesReady > 0)
    {
        while(uartRxBuffer->offset < dmaOffset)
        {
            uint8_t c = uartRxBuffer->buffer[uartRxBuffer->offset];
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
            uartRxBuffer->offset++;
        }
        itemsProcessed++;
      }

      if (uartRxBuffer->offset >= UART_RX_BUFFER)
      {
          uartRxBuffer->readed = 1;
          uartRxBuffer->offset = 0;
          uartRxBuffer->filled = 0;
          gotoNextBufferToRead();
       }
      return itemsProcessed;
}

void vAppTask( void * argument )
{
    currentUartRxBuffer = 0;
    currentUartRxBufferToRead = 0;
    startUartDmaReceive( &uartRxBuffer[currentUartRxBuffer]);
    while(1)
    {

        UART2_DataRx_Deal( );
        UART2_DataTx_Deal( );
        vTaskDelay(1);
       // int itemsProcessed = processUartDmaBuffer( &uartRxBuffer[currentUartRxBufferToRead]);
       // if (!itemsProcessed)
        //{
                    
       // }
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
        vTaskDelay(1);

    }
}

static void gotoNextBufferToRead() {
    if (currentUartRxBufferToRead != currentUartRxBuffer) {
        currentUartRxBufferToRead++;
        currentUartRxBufferToRead %= UART_RX_BUFFERS_COUNT;
    }
}




