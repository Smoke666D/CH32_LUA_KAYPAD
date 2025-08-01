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
 * @fn      UART2_CfgInit
 *
 * @brief   Uart2 configuration initialization
 *
 * @return  none
 */
void UART2_CfgInit( uint32_t baudrate, uint8_t stopbits, uint8_t parity )
{
    USART_InitTypeDef USART_InitStructure = {0};
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    uint16_t dat = dat;

    /* delete contains in ( ... )  */
    /* First set the serial port introduction to output high then close the TE and RE of CTLR1 register (note that USARTx->CTLR1 register setting 9 bits has a limit) */
    /* Note: This operation must be performed, the TX pin otherwise the level will be pulled low */
    GPIO_SetBits( GPIOA, GPIO_Pin_2 );
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init( GPIOA, &GPIO_InitStructure );

    /* clear te/re */
    USART2->CTLR1 &= ~( USART_CTLR1_TE | USART_CTLR1_RE );

    /* USART2 Hard configured: */
    /* Configure USART1 Rx (PA3) as input floating */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
    GPIO_Init( GPIOA, &GPIO_InitStructure );

    /* Configure USART2 Tx (PA2) as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init( GPIOA, &GPIO_InitStructure );

    /* Test IO */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init( GPIOA, &GPIO_InitStructure );

    /* USART2 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
        - USART Clock disabled
        - USART CPOL: Clock is active low
        - USART CPHA: Data is captured on the middle 
        - USART LastBit: The clock pulse of the last data bit is not output to 
                         the SCLK pin
    */
    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;

    /* Number of stop bits (0: 1 stop bit; 1: 1.5 stop bits; 2: 2 stop bits). */
    if( stopbits == 1 )
    {
        USART_InitStructure.USART_StopBits = USART_StopBits_1_5;
    }
    else if( stopbits == 2 )
    {
        USART_InitStructure.USART_StopBits = USART_StopBits_2;
    }
    else
    {
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
    }

    /* Check digit (0: None; 1: Odd; 2: Even; 3: Mark; 4: Space); */
    if( parity == 1 )
    {
        USART_InitStructure.USART_Parity = USART_Parity_Odd;
        USART_InitStructure.USART_WordLength = USART_WordLength_9b;
    }
    else if( parity == 2 )
    {
        USART_InitStructure.USART_Parity = USART_Parity_Even;
        USART_InitStructure.USART_WordLength = USART_WordLength_9b;
    }
    else
    {
        USART_InitStructure.USART_Parity = USART_Parity_No;
    }
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init( USART2, &USART_InitStructure );
    USART_ClearFlag( USART2, USART_FLAG_TC );

    /* Enable USART2 */
    USART_Cmd( USART2, ENABLE );
}

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
    Uart.Rx_RemainLen = 0x00;
    Uart.Rx_TimeOut = 0x00;
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
 * @fn      UART2_Init
 *
 * @brief   Uart2 total initialization
 *          mode     : See the useage of UART2_ParaInit( mode )
 *          baudrate : Serial port 2 default baud rate
 *          stopbits : Serial port 2 default stop bits
 *          parity   : Serial port 2 default parity
 *
 * @return  none
 */
void UART2_Init( uint8_t mode, uint32_t baudrate, uint8_t stopbits, uint8_t parity )
{
    USART_DMACmd( USART2, USART_DMAReq_Rx, DISABLE );
    DMA_Cmd( DMA1_Channel6, DISABLE );
    DMA_Cmd( DMA1_Channel7, DISABLE );

    UART2_CfgInit( baudrate, stopbits, parity );
    UART2_DMAInit( 0, &UART2_Tx_Buf[ 0 ], 0 );
    UART2_DMAInit( 1, &UART2_Rx_Buf[ 0 ], DEF_UARTx_RX_BUF_LEN );

    USART_DMACmd( USART2, USART_DMAReq_Rx, ENABLE );

    UART2_ParaInit( mode );
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

/*********************************************************************
 * @fn      UART2_DataTx_Deal
 *
 * @brief   Uart2 data transmission processing
 *
 * @return  none
 */
uint8_t UART2_DataTx_Deal(uint8_t *uartRxBuffer )
{
    uint16_t  count;

    /* uart1 transmission processing */
    if( Uart.Tx_Flag )
    {
    
        Uart.Tx_Flag = 0x00;

        NVIC_DisableIRQ( USBFS_IRQn );
        NVIC_DisableIRQ( USBFS_IRQn );

        /* Calculate the variables of last data */
        count = Uart.Tx_CurPackLen;
        Uart.Tx_CurPackLen -= count;
        Uart.Tx_CurPackPtr += count;
        if( Uart.Tx_CurPackLen == 0x00 )
        {
                Uart.Tx_PackLen[ Uart.Tx_DealNum ] = 0x0000;
                Uart.Tx_DealNum++;
                if( Uart.Tx_DealNum >= DEF_UARTx_TX_BUF_NUM_MAX )
                {
                    Uart.Tx_DealNum = 0x00;
                }
                Uart.Tx_RemainNum--;
        }

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
            /* Determine whether to load from the last unsent buffer or from a new buffer */
            if( Uart.Tx_CurPackLen == 0x00 )
            {
                Uart.Tx_CurPackLen = Uart.Tx_PackLen[ Uart.Tx_DealNum ];
                Uart.Tx_CurPackPtr = ( Uart.Tx_DealNum * DEF_USB_FS_PACK_LEN );
            }
            memset(uartRxBuffer,0,UART_RX_BUFFER);
            memcpy(uartRxBuffer,&UART2_Tx_Buf[ Uart.Tx_CurPackPtr],Uart.Tx_CurPackLen) ;
            /* Configure DMA and send */
           // USART_ClearFlag( USART2, USART_FLAG_TC );
            //DMA_Cmd( DEF_UART2_TX_DMA_CH, DISABLE );
            //DEF_UART2_TX_DMA_CH->MADDR = (uint32_t)&UART2_Tx_Buf[ Uart.Tx_CurPackPtr ];
            //DEF_UART2_TX_DMA_CH->CNTR = Uart.Tx_CurPackLen;
            //DMA_Cmd( DEF_UART2_TX_DMA_CH, ENABLE );
            //USART2->CTLR3 |= USART_DMAReq_Tx;
            Uart.Tx_Flag = 0x01;
            return 1;
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
   
    uint32_t remain_len;
    uint16_t packlen;
    
     NVIC_DisableIRQ( USBFS_IRQn );
    NVIC_DisableIRQ( USBFS_IRQn );
    if (xMessageBufferIsEmpty(USART_TX_Message)==pdFALSE)
    {
       
        uint16_t count =  xMessageBufferReceive(USART_TX_Message,UART2_Rx_Buf,100,0);
        if(  count > DEF_UARTx_RX_BUF_LEN )
        {
            /* Overflow handling */
            /* Save frame error status */
            printf("U0_O:%08lx\n",(uint32_t)Uart.Rx_RemainLen);
        }
        else
        {
            Uart.Rx_RemainLen = count;
        }
        Uart.Rx_TimeOut = 0x00;
    }
    NVIC_EnableIRQ( USBFS_IRQn );
        if( Uart.USB_Up_IngFlag == 0 )
        {
            /* Calculate the length of this upload */
            remain_len = Uart.Rx_RemainLen;
            packlen = 0x00;
            if( remain_len >= DEF_USBD_FS_PACK_SIZE )
            {
                packlen = DEF_USBD_FS_PACK_SIZE;
            }
            else
            {
                if( Uart.Rx_TimeOut >= Uart.Rx_TimeOutMax )
                {
                    packlen = remain_len;
                }
            }
            if( packlen > ( DEF_UARTx_RX_BUF_LEN ) )
            {
                packlen =  DEF_UARTx_RX_BUF_LEN ;
            }

            /* Upload serial data via usb */
            if( packlen )
            {
                NVIC_DisableIRQ( USBFS_IRQn );
                NVIC_DisableIRQ( USBFS_IRQn );
                Uart.USB_Up_IngFlag = 0x01;
                Uart.USB_Up_TimeOut = 0x00;
                USBFS_Endp_DataUp( DEF_UEP3, (uint8_t *)UART2_Rx_Buf, packlen, DEF_UEP_CPY_LOAD );
                /* Calculate the variables of interest */
                Uart.Rx_RemainLen =0;
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
    
    /*****************************************************************/
    /* Serial port 1 data processing via USB upload and reception */
    

    /*****************************************************************/
    /* Determine if a 0-length packet needs to be uploaded (required for CDC mode) */
    if( Uart.USB_Up_Pack0_Flag )
    {
        if( Uart.USB_Up_IngFlag == 0 )
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
    }
}
