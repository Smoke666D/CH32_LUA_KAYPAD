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

static TaskHandle_t  AppTaskHandle;
static TaskHandle_t  CanRecieveTaskHandle;
static QueueHandle_t    pRXQueue;
static MessageBufferHandle_t USART_TX_Message;

#define   STORAGE_SIZE_BYTES 100
static uint8_t ucMessageBufferStorage[ STORAGE_SIZE_BYTES ];
#define STREAM_BUFFER_SIZE_BYTES 100
static uint8_t ucTXStreamBufferStorage[ STREAM_BUFFER_SIZE_BYTES + 1 ];
static uint8_t ucRXStreamBufferStorage[ STREAM_BUFFER_SIZE_BYTES + 1 ];
static StaticStreamBuffer_t xTXStreamBufferStruct;
static StaticStreamBuffer_t xRXStreamBufferStruct;
static StreamBufferHandle_t xRXStreamBuffer;

static uint32_t CanSpeed=6;

static MessageBufferHandle_t xCANRXMessageBuffer;
static StaticMessageBuffer_t xMessageBufferStruct;
#define RX_BUFFER_SIZE  100
static u8 TX_DATA_BUFFER[RX_BUFFER_SIZE];
static u8 TX1_DATA_BUFFER[RX_BUFFER_SIZE];
void CanHacker_ExecTimestamp(CanHacker_HandleTypeDef *canhacker);
static void CanHacker_Receive_Cmd(CanHacker_HandleTypeDef *canhacker, uint8_t *cmd_buf);
//static void CanHacker_UartMsgReadyCallback(CanHacker_HandleTypeDef *canhacker, uint8_t *line);
static void gotoNextBufferToRead();
static void CanHacker_ExecGetSerial();
static void CanHacker_ExecGetSWVersion();
static void CanHacker_ExecGetVersion();
static void CanHacker_ExecOpen(CanHacker_HandleTypeDef *canhacker);
static void CanHacker_ExecClose(CanHacker_HandleTypeDef *canhacker);
static void CanHacker_ErrorCallback( char *message) ;
static void transmitErrorMessage(char *message);
static  void CanHacker_ExecSetBitrate( uint8_t *str);
static void throwError(char *msg);
static uint8_t tx_data_transfer = 0;
static uint8_t CanChnOpen=0;
static uint8_t CanInitialized=0;
#define UART_RX_BUFFER 256
#define UART_RX_BUFFERS_COUNT 2

/* const */
static const uint32_t bitrate_table[] =
  {
    10UL,
    20UL,
    50UL,
    100UL,
    3,
    2,
    1,
    0,
    0L
  };

typedef struct
{
    uint8_t buffer[UART_RX_BUFFER];
    uint8_t readed;
    uint8_t filled;
    int offset;
} UART_DMA_RX_Buffer;

UART_DMA_RX_Buffer uartRxBuffer[UART_RX_BUFFERS_COUNT]= {
    { .readed = 0, .filled = 0, .offset = 0 },
    { .readed = 0, .filled = 0, .offset = 0 }
};

uint8_t ascii2byte(uint8_t val)
{
    if (val >= 'a') {
        return val - 'a' + 10; // convert chars a-f
    }
    if (val >= 'A') {
        return val - 'A' + 10; // convert chars A-F
    }
    return val - '0';     // convert chars 0-9
}

uint8_t nibble2ascii(uint8_t byte) {
    byte &= 0x0F;
    return byte < 10 ? byte + 48 : byte + 55;
}


int currentUartRxBuffer = 0;
int currentUartRxBufferToRead = 0;
static CanHacker_HandleTypeDef hcanhacker;

static u8 TX_SIZE;



MessageBufferHandle_t * xTXMessage(void)
{
    return (&USART_TX_Message);
}


QueueHandle_t * xRXQueue( void )
{
  return  (&pRXQueue);
}


TaskHandle_t * xGetCanTaskHandle ()
{
    return  &CanRecieveTaskHandle ;
}




TaskHandle_t * xGetAppTaskHandle ()
{
    return  &AppTaskHandle ;
}


uint8_t dma_buff[100];
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





void vCallBack()
{}



void vAppInit()
{
   xCANRXMessageBuffer = xMessageBufferCreateStatic(sizeof(ucMessageBufferStorage),ucMessageBufferStorage,&xMessageBufferStruct);

   xRXStreamBuffer = xStreamBufferCreateStatic(STREAM_BUFFER_SIZE_BYTES,1,ucRXStreamBufferStorage,&xRXStreamBufferStruct );
   LAWICEL_Init(&xCANRXMessageBuffer);
   HAL_CANToInitMode();
   HAL_CANSetRXCallback(&ProcessMsgFromCan);
   HAL_CANSetERRCallback(&vCallBack);
   HAL_CANSetTXCallback(&vCallBack);
   DMA_INIT_t init;

       init.stream = DMA1_CH2;
       init.direction = MTOP;
       init.mode  = DMA_Normal;
       init.paddr = (u32)(&USART3->DATAR);
       init.memadr = (u32)dma_buff;
       init.dma_size = DMA_BYTE;
       init.bufsize = 2;
       init.prioroty = dma_Medium;
       HAL_DMAInitIT(init,  0 , 1, &DMA_Callback );


       init.direction = PTOM;
       init.stream = DMA1_CH3;
       init.memadr = (u32)uartRxBuffer[0].buffer;
       init.bufsize = UART_RX_BUFFER;
       HAL_DMAInitIT(init,  0 , 1, &DMA_RX_Callback );
   HALUSARTInit(HAL_USART3,115200,HAL_StopBits_1,HAL_Parity_No,UART_WORDLENGTH_8B);
   HALUSARTEnable(HAL_USART3);
   USART_DMACmd(USART3,  USART_DMAReq_Tx | USART_DMAReq_Rx, ENABLE);
   HAL_TIMER_InitIt(TIMER1,100000,99,&MSTimrCallBack,1,0);
   HAL_TiemrEneblae(TIMER1);

}



void  SendData( uint8_t * data_buffer, uint8_t data_size)
{
    xMessageBufferSend(USART_TX_Message,( void * ) data_buffer, data_size, 1 );
}

void SendDataToSerial( uint8_t * data_buffer, uint8_t data_size)
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
      //  xStreamBufferSend( xTXStreamBuffer,( void * ) data_buffer, data_size, 1 );
    }
}
#define UART_RX_LINE_BUFFER 80
int uartLineIndex = 0;
uint8_t uartLine[UART_RX_LINE_BUFFER];




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
    //妤把抉志快把攸快技 扼抉扼找抉攸扶快 忌批扳扳快把忘 扭把我快技忘
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
                        //uartLine[uartLineIndex++] = '\0';
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



static void CanHacker_Receive_Cmd(CanHacker_HandleTypeDef *canhacker, uint8_t *cmd_buf)
{
    char firstChar = *cmd_buf;

    switch (firstChar) {
        // get serial number
        case CANHACKER_GET_SERIAL: {
            CanHacker_ExecGetSerial();
            return;
        }

        // get hard- and software version
        case CANHACKER_GET_VERSION: {
            CanHacker_ExecGetVersion();
            return;
        }

        // get only software version
        case CANHACKER_GET_SW_VERSION: {
            CanHacker_ExecGetSWVersion();
            return;
        }

        case CANHACKER_SEND_11BIT_ID:
            CanHacker_ExecTransmit11bit(canhacker, cmd_buf);
            return;

        case CANHACKER_SEND_R11BIT_ID:
            CanHacker_ExecTransmitR11bit(canhacker, cmd_buf);
            return;

        case CANHACKER_TIME_STAMP:
            CanHacker_ExecTimestamp(canhacker);
            return;

        case CANHACKER_OPEN_CAN_CHAN:
            CanHacker_ExecOpen(canhacker);
            return;

        case CANHACKER_CLOSE_CAN_CHAN:
            CanHacker_ExecClose(canhacker);
            return;

        case CANHACKER_SET_BITRATE:
            CanHacker_ExecSetBitrate( cmd_buf);
            return;

            // end with error on unknown commands
        default:
            CanHacker_ErrorCallback( "Unexpected command");
            return;
    }

    return; //CanHacker_ErrorCallback(canhacker, "Should never reach this section");
}



void vAppTask( void * argument )
{
    currentUartRxBuffer = 0;
    currentUartRxBufferToRead = 0;
    startUartDmaReceive( &uartRxBuffer[currentUartRxBuffer]);
    while(1)
    {
        int itemsProcessed = processUartDmaBuffer( &uartRxBuffer[currentUartRxBufferToRead]);
        if (!itemsProcessed)
        {
            vTaskDelay(1);
        }
    }
}

void vCanTask( void * argument )
{
    xTaskNotifyGive(CanRecieveTaskHandle);
    while(1)
    {
        vTaskDelay(1);
        if (xMessageBufferIsEmpty(xCANRXMessageBuffer) == pdFALSE)
        {
            TX_SIZE = xMessageBufferReceive( xCANRXMessageBuffer, TX1_DATA_BUFFER, sizeof(ucMessageBufferStorage),0);
            SendDataToSerial(TX1_DATA_BUFFER,TX_SIZE);
        }
    }
}


static void gotoNextBufferToRead() {
    if (currentUartRxBufferToRead != currentUartRxBuffer) {
        currentUartRxBufferToRead++;
        currentUartRxBufferToRead %= UART_RX_BUFFERS_COUNT;
    }
}








