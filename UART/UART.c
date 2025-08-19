/********************************** (C) COPYRIGHT *******************************
* File Name          : UART.C
* Author             : WCH
* Version            : V1.01
* Date               : 2022/12/13
* Description        : uart serial port related initialization and processing
*******************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

#include "UART.h"
#include "app_task.h"
/*******************************************************************************/
/* Variable Definition */
/* Global */

/* The following are serial port transmit and receive related variables and buffers */
volatile UART_CTL Uart;

__attribute__ ((aligned(4))) uint8_t  UART2_Tx_Buf[ DEF_UARTx_TX_BUF_LEN ];  /* Serial port 2 transmit data buffer */
__attribute__ ((aligned(4))) uint8_t  UART2_Rx_Buf[ DEF_UARTx_RX_BUF_LEN ];  /* Serial port 2 receive data buffer */
volatile uint32_t UARTx_Rx_DMACurCount;                       /* Serial port 1 receive dma current counter */
volatile uint32_t UARTx_Rx_DMALastCount;                      /* Serial port 1 receive dma last value counter  */

/*********************************************************************
 * @fn      RCC_Configuration
 *
 * @brief   Configures the different system clocks.
 *
 * @return  none
 */
uint8_t RCC_Configuration( void )
{
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );
    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_DMA1, ENABLE );
    return 0;
}

/*********************************************************************
 * @fn      TIM2_Init
 *
 * @brief   100us Timer
 *          144 * 100 * 13.8888 -----> 100uS
 *
 * @return  none
 */




/*********************************************************************
 * @fn      UART2_ParaInit
 *
 * @brief   Uart2 parameters initialization
 *          mode = 0 : Used in usb modify initialization
 *          mode = 1 : Used in default initializations
 * @return  none
 */
void UART2_ParaInit( uint8_t mode )
{
    uint8_t i;

    Uart.Rx_LoadPtr = 0x00;
    Uart.Rx_DealPtr = 0x00;
   
    Uart.Rx_TimeOutMax = 30;

    Uart.Tx_LoadNum = 0x00;
    Uart.Tx_DealNum = 0x00;
    Uart.Tx_RemainNum = 0x00;
    for( i = 0; i < DEF_UARTx_TX_BUF_NUM_MAX; i++ )
    {
        Uart.Tx_PackLen[ i ] = 0x00;
    }
    Uart.Tx_Flag = 0x00;
    Uart.Tx_CurPackLen = 0x00;
    Uart.Tx_CurPackPtr = 0x00;

    Uart.USB_Up_IngFlag = 0x00;
    Uart.USB_Up_TimeOut = 0x00;
    Uart.USB_Up_Pack0_Flag = 0x00;
    Uart.USB_Down_StopFlag = 0x00;
    UARTx_Rx_DMACurCount = 0x00;
    UARTx_Rx_DMALastCount = 0x00;

    if( mode )
    {
        Uart.Com_Cfg[ 0 ] = (uint8_t)( DEF_UARTx_BAUDRATE );
        Uart.Com_Cfg[ 1 ] = (uint8_t)( DEF_UARTx_BAUDRATE >> 8 );
        Uart.Com_Cfg[ 2 ] = (uint8_t)( DEF_UARTx_BAUDRATE >> 16 );
        Uart.Com_Cfg[ 3 ] = (uint8_t)( DEF_UARTx_BAUDRATE >> 24 );
        Uart.Com_Cfg[ 4 ] = DEF_UARTx_STOPBIT;
        Uart.Com_Cfg[ 5 ] = DEF_UARTx_PARITY;
        Uart.Com_Cfg[ 6 ] = DEF_UARTx_DATABIT;
        Uart.Com_Cfg[ 7 ] = DEF_UARTx_RX_TIMEOUT;
    }
}




/*********************************************************************
 * @fn      UART2_USB_Init
 *
 * @brief   Uart2 initialization in usb interrupt
 *
 * @return  none
 */
void UART2_USB_Init( void )
{
    uint32_t baudrate;
    uint8_t  stopbits;
    uint8_t  parity;

    baudrate = ( uint32_t )( Uart.Com_Cfg[ 3 ] << 24 ) + ( uint32_t )( Uart.Com_Cfg[ 2 ] << 16 );
    baudrate += ( uint32_t )( Uart.Com_Cfg[ 1 ] << 8 ) + ( uint32_t )( Uart.Com_Cfg[ 0 ] );
    stopbits = Uart.Com_Cfg[ 4 ];
    parity = Uart.Com_Cfg[ 5 ];

    UART2_ParaInit( 0);

    /* restart usb receive  */
    USBFSD->UEP2_DMA = (uint32_t)(uint8_t *)&UART2_Tx_Buf[ 0 ];
    USBFSD->UEP2_RX_CTRL &= ~USBFS_UEP_R_RES_MASK;
    USBFSD->UEP2_RX_CTRL |= USBFS_UEP_R_RES_ACK;
}

static uint16_t CNTR = 0;

/*********************************************************************
 * @fn      UART2_DataTx_Deal
 *
 * @brief   Uart2 data transmission processing
 *
 * @return  none
 */
uint8_t UART2_DataTx_Deal(uint8_t *uartRxBuffer )
{

    /* uart1 transmission processing */
    if( Uart.Tx_Flag )
    {
        Uart.Tx_Flag = 0x00;
        Uart.Tx_CurPackPtr += CNTR;
        Uart.Tx_PackLen[ Uart.Tx_DealNum ] = 0x0000;
        if( ++Uart.Tx_DealNum >= DEF_UARTx_TX_BUF_NUM_MAX )
        {
             Uart.Tx_DealNum = 0x00;
        }
        NVIC_DisableIRQ( USBFS_IRQn );
        NVIC_DisableIRQ( USBFS_IRQn ); 
        Uart.Tx_RemainNum--;
        /* If the current serial port has suspended the downlink, restart the driver downlink */
        if( ( Uart.USB_Down_StopFlag == 0x01 ) && ( Uart.Tx_RemainNum < 2 ) )
        {
            USBFSD->UEP2_RX_CTRL &= ~USBFS_UEP_R_RES_MASK;
            USBFSD->UEP2_RX_CTRL |= USBFS_UEP_R_RES_ACK;
            Uart.USB_Down_StopFlag = 0x00;
        }
        NVIC_EnableIRQ( USBFS_IRQn );
    }
    else
    {
        /* Load data from the serial port send buffer to send  */
        if( Uart.Tx_RemainNum )
        {
            Uart.Tx_CurPackLen = Uart.Tx_PackLen[ Uart.Tx_DealNum ];
            Uart.Tx_CurPackPtr = ( Uart.Tx_DealNum * DEF_USB_FS_PACK_LEN );
            memcpy(uartRxBuffer,&UART2_Tx_Buf[ Uart.Tx_CurPackPtr],Uart.Tx_CurPackLen) ;
            CNTR= Uart.Tx_CurPackLen;
            Uart.Tx_Flag = 0x01;
            return CNTR;
        }
    }
    return 0;
}

static MessageBufferHandle_t * USART_TX_Message;

void SetBuff()
{
  USART_TX_Message = *(xTXMessage());
  xMessageBufferReset(USART_TX_Message);
}

/*********************************************************************
 * @fn      UART2_DataRx_Deal
 *
 * @brief   Uart2 data receiving processing
 *
 * @return  none
 */
void UART2_DataRx_Deal( void )
{
    uint16_t packlen;
    if( Uart.USB_Up_IngFlag == 0 )
    {
           if( Uart.USB_Up_Pack0_Flag )
           {
                if( Uart.USB_Up_TimeOut >= ( DEF_UARTx_RX_TIMEOUT * 20 ) )
                {
                    NVIC_DisableIRQ( USBFS_IRQn );
                    NVIC_DisableIRQ( USBFS_IRQn );
                    Uart.USB_Up_IngFlag = 0x01;
                    Uart.USB_Up_TimeOut = 0x00;
                    USBFSD->UEP3_TX_LEN = 0;
                    USBFSD->UEP3_TX_CTRL &= ~USBFS_UEP_T_RES_MASK;
                    USBFSD->UEP3_TX_CTRL |= USBFS_UEP_T_RES_ACK;
                    Uart.USB_Up_IngFlag = 0;
                    Uart.USB_Up_Pack0_Flag = 0x00;
                    NVIC_EnableIRQ( USBFS_IRQn );
                }
        }
         if (xMessageBufferIsEmpty(USART_TX_Message)==pdFALSE)
         {               
            packlen =  xMessageBufferReceive(USART_TX_Message,UART2_Rx_Buf,DEF_USBD_FS_PACK_SIZE,0);
            /* Calculate the length of this upload */
            NVIC_DisableIRQ( USBFS_IRQn );
            NVIC_DisableIRQ( USBFS_IRQn );
            Uart.USB_Up_IngFlag = 0x01;
            Uart.USB_Up_TimeOut = 0x00;
            USBFS_Endp_DataUp( DEF_UEP3, (uint8_t *)UART2_Rx_Buf, packlen, DEF_UEP_CPY_LOAD );
            /* Calculate the variables of interest */
            /* Start 0-length packet timeout timer */
            if( packlen == DEF_USBD_FS_PACK_SIZE )
            {
                Uart.USB_Up_Pack0_Flag = 0x01;
            }
            NVIC_EnableIRQ( USBFS_IRQn );
        }
    }
    else
    {
        /* Set the upload success flag directly if the upload is not successful after the timeout */
        if( Uart.USB_Up_TimeOut >= DEF_UARTx_USB_UP_TIMEOUT )
        {
            Uart.USB_Up_IngFlag = 0x00;
            USBFS_Endp_Busy[ DEF_UEP3 ] = 0;
        }
    }
}
