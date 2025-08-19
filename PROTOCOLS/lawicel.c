/*
 * lawicel.c
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#include "lawicel.h"
#include "hal_can.h"
#include "hal_timers.h"


static uint8_t CanChnOpen=0;
static uint8_t CanInitialized=0;
static uint32_t CanSpeed=6;
static uint8_t AutoPollAutoSend=1;
static uint8_t FilterMode=0;
static uint8_t CanRcvTimestampOn=0;
static LAWICEL_BUS_STATE CanBusMode = LAWICEL_BUS_OFF;
static MessageBufferHandle_t * CANTXMessageBuffer;
static xCanTxCallBack CanSendCallback;

void LAWICEL_Init( MessageBufferHandle_t * MessageBuffer, xCanTxCallBack func )
{
    CanSendCallback =  func;
    CANTXMessageBuffer = MessageBuffer;
}

/* const */
static const uint32_t bitrate_table[] =
  {
    CAN_10KBS,
    CAN_20KBS,
    CAN_50KBS,
    CAN_100KBS,
    CAN_125KBS,
    CAN_250KBS ,
    CAN_500KBS,
    CAN_800KBS,
    CAN_1MBS
  };


uint8_t hex2ascii(uint8_t chr)
{
    chr = chr & 0xF;
    if(chr > 9)
    {
        chr += 0x37;
    }
    else
    {
        chr += 0x30;
    }
    return chr;
}

uint8_t ascii2hex(uint8_t chr)
{
    if((chr <= 0x5A) && (chr >= 0x41)) // Großbuchstaben
    {
        chr -= 0x37;
        return chr &0xF;
    }
    if((chr <= 0x7A) && (chr >= 0x61)) // Kleinbuchstaben
    {
        chr -=0x57;
        return chr &0xF;
    }

    if((chr <= 0x39) && (chr >= 0x30)) // Zahlen
    {
        chr -= 0x30;
    }
    return chr & 0xF;
}


static void GetVersionInfo(uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
    *SerXmtBufPtr = 0;
    SerXmtBuf[*SerXmtBufPtr] = 'V';
    (*SerXmtBufPtr)++;
    SerXmtBuf[*SerXmtBufPtr] = '1';
    (*SerXmtBufPtr)++;
    SerXmtBuf[*SerXmtBufPtr] = '6';
    (*SerXmtBufPtr)++;
    SerXmtBuf[*SerXmtBufPtr] = '6';
    (*SerXmtBufPtr)++;
    SerXmtBuf[*SerXmtBufPtr] = '6';
    (*SerXmtBufPtr)++;
    SerXmtBuf[*SerXmtBufPtr] = '\r'; // Append <CR>
    (*SerXmtBufPtr)++;
}

static void GetSerialNumber(uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
    *SerXmtBufPtr = 0;

    SerXmtBuf[*SerXmtBufPtr] = 'N';
    (*SerXmtBufPtr)++;

    memcpy (&SerXmtBuf[*SerXmtBufPtr],"0001",4);
//  memcpy (&SerXmtBuf[SerXmtBufPtr],EepromData.DeviceSN,4);
    *SerXmtBufPtr = *SerXmtBufPtr + 4;

    SerXmtBuf[*SerXmtBufPtr] = '\r'; // Append <CR>
    (*SerXmtBufPtr)++;


}

static void TransmitStandardFrame( uint8_t * SerRcvBuf, uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
    CAN_TX_FRAME_TYPE CanTxMsg;
    memset(CanTxMsg.data,0,8);
    // prepare 11 bit ID
    CanTxMsg.ident =                   (ascii2hex(SerRcvBuf[1])<<8 )& 0xF00;
    CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[2])<<4 )& 0x0F0));
    CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[3])    )& 0x00F));

    // set DLC
    CanTxMsg.DLC = (ascii2hex(SerRcvBuf[4]))& 0x00F;

        // copy message data
    for (uint8_t i=0;i<(CanTxMsg.DLC);i++)
    {
            CanTxMsg.data[i] = (ascii2hex(SerRcvBuf[5+2*i])<<4 )& 0x0F0;
            CanTxMsg.data[i] = (CanTxMsg.data[i] | ((ascii2hex(SerRcvBuf[i*2+6]))& 0x00F));
    }
    // send the message
    CanSendCallback( &CanTxMsg);

    SerXmtBuf[0] = 'Z';
    SerXmtBuf[1] = LAWICEL_SUCCES;
    (*SerXmtBufPtr)=2;


}
static void TransmitExtendedFrame( uint8_t * SerRcvBuf, uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
  //  LAWICEL_ERROR_CODE Result;
    CAN_TX_FRAME_TYPE CanTxMsg;

   // Result = LAWICEL_SUCCES;

    // if CAN channel is open and -not- listen only


        // Erase former CAN data bytes
        memset(CanTxMsg.data,0,8);

        // prepare 29 bit ID
        CanTxMsg.ident =                 (ascii2hex(SerRcvBuf[1])<<28 )& 0xF0000000;
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[2])<<24 )& 0x0F000000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[3])<<20 )& 0x00F00000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[4])<<16 )& 0x000F0000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[5])<<12 )& 0x0000F000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[6])<< 8 )& 0x00000F00));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[7])<< 4 )& 0x000000F0));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[8])     )& 0x0000000F));

        // Set message type 29 bit
        CanTxMsg.id_type = HAL_CAN_EXTD_ID;

        // set DLC
        CanTxMsg.DLC = (ascii2hex(SerRcvBuf[9]))& 0xF;

        // copy message data
        for (uint8_t i=0;i<(CanTxMsg.DLC);i++) {
            CanTxMsg.data[i] = (ascii2hex(SerRcvBuf[10+2*i])<<4 )& 0x0F0;
            CanTxMsg.data[i] = (CanTxMsg.data[i] | ((ascii2hex(SerRcvBuf[11+2*i]))& 0x00F));
        }
        // send the message
        CanSendCallback( &CanTxMsg);
    //-------------------------------------------------

        SerXmtBuf[0] = 'Z';
        SerXmtBuf[1] = LAWICEL_SUCCES;
       (*SerXmtBufPtr)=2;
}

static void TransmitStandardRtr(uint8_t * SerRcvBuf, uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
     LAWICEL_ERROR_CODE Result;
     CAN_TX_FRAME_TYPE CanTxMsg;
     Result = LAWICEL_SUCCES;

    // if CAN channel is open and -not- listen only
    if ((CanChnOpen == 1) && (CanBusMode == LAWICEL_BUS_ON)) {

        // Erase all former CAN data bytes
        memset(CanTxMsg.data,0,8);

        // prepare 11 bit ID
        CanTxMsg.ident =                 (ascii2hex(SerRcvBuf[1])<<8 )& 0xF00;
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[2])<<4 )& 0x0F0));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[3])    )& 0x00F));


        CanTxMsg.ident = CanTxMsg.ident | FLAG_RTR;
        // Set message type 11 bit
        CanTxMsg.id_type = HAL_CAN_STD_ID;

        // set DLC
        CanTxMsg.DLC = (ascii2hex(SerRcvBuf[4]))& 0x00F;

        // send the message
        CanSendCallback( &CanTxMsg);
    }
    else {
        Result = LAWICEL_ERROR;
    }

    //-------------------------------------------------

    *SerXmtBufPtr = 0;

    if (AutoPollAutoSend == 1) {
        if (Result == LAWICEL_SUCCES) {
            SerXmtBuf[*SerXmtBufPtr] = 'z';
            (*SerXmtBufPtr)++;
        }
    }
    SerXmtBuf[*SerXmtBufPtr] = Result;
    (*SerXmtBufPtr)++;


}


static void TransmitExtendedRtr(uint8_t * SerRcvBuf, uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
    LAWICEL_ERROR_CODE Result;
    CAN_TX_FRAME_TYPE CanTxMsg;
    Result = LAWICEL_SUCCES;

    // if CAN channel is open and -not- listen only

        // Erase former CAN data bytes
        memset(CanTxMsg.data,0,8);
        // prepare 29 bit ID
        CanTxMsg.ident =                 (ascii2hex(SerRcvBuf[1])<<28 )& 0xF0000000;
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[2])<<24 )& 0x0F000000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[3])<<20 )& 0x00F00000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[4])<<16 )& 0x000F0000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[5])<<12 )& 0x0000F000));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[6])<< 8 )& 0x00000F00));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[7])<< 4 )& 0x000000F0));
        CanTxMsg.ident = (CanTxMsg.ident | ((ascii2hex(SerRcvBuf[8])     )& 0x0000000F));

        // Set message type 29 bit RTR
        CanTxMsg.ident = CanTxMsg.ident | FLAG_RTR;

        CanTxMsg.id_type = HAL_CAN_EXTD_ID;

        // set DLC
        CanTxMsg.DLC = (ascii2hex(SerRcvBuf[9]))& 0xF;

        // send the message
        CanSendCallback( &CanTxMsg);


    //-------------------------------------------------

    *SerXmtBufPtr = 0;

    if (AutoPollAutoSend == 1) {
        if (Result == LAWICEL_SUCCES) {
            SerXmtBuf[*SerXmtBufPtr] = 'z';
            (*SerXmtBufPtr)++;
        }
    }
    SerXmtBuf[*SerXmtBufPtr] = Result;
    (*SerXmtBufPtr)++;

    // Send ASCII string to RS232 UART (Host-PC)

}





static void SetFilterMode(uint8_t * SerRcvBuf,uint8_t * SerXmtBuf, uint8_t * SerXmtBufPtr)
//-------------------------------------------------
{
    LAWICEL_ERROR_CODE Result;
    Result = LAWICEL_SUCCES;

    if (CanChnOpen == 0){ // precondition
        FilterMode = ascii2hex(SerRcvBuf[1]);
    }
    else {
        Result = LAWICEL_ERROR;
    }
    //-------------------------------------------------

    *SerXmtBufPtr = 0;

    SerXmtBuf[*SerXmtBufPtr] = Result;
    (*SerXmtBufPtr)++;

}

void ParseCanMessage(LAWICEL_CAN_MSG_t msg, void (* rxcallback)(  uint8_t *, uint8_t    ) )
{
    uint8_t SerXmtBufPtr;
    uint8_t SerXmtBuf[60];
    if (msg.msg.id_type  == HAL_CAN_STD_ID)
    { // is -not- 29 bit

        SerXmtBuf[0] = (msg.msg.RTR == HAL_CAN_DATA) ?'t' : 'r';
         // convert 11 bit Id
         SerXmtBuf[1] = hex2ascii((msg.msg.ident & 0x700)>>8);
         SerXmtBuf[2] = hex2ascii((msg.msg.ident & 0x0F0)>>4);
         SerXmtBuf[3] = hex2ascii (msg.msg.ident & 0x00F);
                 // convert DLC
         SerXmtBuf[4] = hex2ascii(msg.msg.DLC);

         if (msg.msg.RTR == HAL_CAN_DATA)
         { // is -not- RTR
                     // convert data bytes to ASCII
             for (uint8_t i=0;i<msg.msg.DLC;++i)
             {
                 SerXmtBuf[5+i*2] = hex2ascii((msg.msg.data[i] & 0xF0)>>4);
                 SerXmtBuf[6+i*2] = hex2ascii (msg.msg.data[i] & 0x0F);
             }
             SerXmtBufPtr = 5 + (msg.msg.DLC*2);
         }
         else
         { // is RTR: no data
             SerXmtBufPtr = 5;
         }
        //if (CanRcvTimestampOn == 1) {
         SerXmtBuf[SerXmtBufPtr]   = hex2ascii((msg.time_stamp & 0xF000)>>12);
         SerXmtBuf[SerXmtBufPtr+1] = hex2ascii((msg.time_stamp & 0x0F00)>>8);
         SerXmtBuf[SerXmtBufPtr+2] = hex2ascii((msg.time_stamp & 0x00F0)>>4);
         SerXmtBuf[SerXmtBufPtr+3] = hex2ascii (msg.time_stamp & 0x000F);
         SerXmtBufPtr = SerXmtBufPtr +4;
                // }
         SerXmtBuf[SerXmtBufPtr] = '\r'; // Append <CR>
         SerXmtBufPtr ++;
                // xMessageBufferSendFromISR(*CANTXMessageBuffer,SerXmtBuf,SerXmtBufPtr,&xHigherPriorityTaskWoken );
      } // IF Id=not Extended
             //-------------------------------------------------

       else
       { // Id = EXTENDED 29 bit
                 if (msg.msg.RTR == HAL_CAN_DATA)
                 {
                     SerXmtBuf[0] = 'T';
                 }
                 else { // is 29 bit RTR
                     SerXmtBuf[0] = 'R';
                 }
                 SerXmtBufPtr++;
                 // 29 bit Id
                 SerXmtBuf[1] = hex2ascii((msg.msg.ident & 0x10000000)>>28);
                 SerXmtBuf[2] = hex2ascii((msg.msg.ident & 0x0F000000)>>24);
                 SerXmtBuf[3] = hex2ascii((msg.msg.ident & 0x00F00000)>>20);
                 SerXmtBuf[4] = hex2ascii((msg.msg.ident & 0x000F0000)>>16);
                 SerXmtBuf[5] = hex2ascii((msg.msg.ident & 0x0000F000)>>12);
                 SerXmtBuf[6] = hex2ascii((msg.msg.ident & 0x00000F00)>>8);
                 SerXmtBuf[7] = hex2ascii((msg.msg.ident & 0x000000F0)>>4);
                 SerXmtBuf[8] = hex2ascii (msg.msg.ident & 0x0000000F);
                 // DLC
                 SerXmtBuf[9] = hex2ascii(msg.msg.DLC);
                 // data bytes
                 if (msg.msg.RTR == HAL_CAN_DATA) { // is -not- RTR
                     // convert data bytes to ASCII
                     for (uint8_t i=0;i<msg.msg.DLC;++i) {
                         SerXmtBuf[10+i*2] = hex2ascii((msg.msg.data[i] & 0xF0)>>4);
                         SerXmtBuf[11+i*2] = hex2ascii (msg.msg.data[i] & 0x0F);
                     }
                     SerXmtBufPtr = 10 + (msg.msg.DLC *2);
                 }
                 else { // is RTR: no data
                     SerXmtBufPtr = 10;
                  }
                 // append timestamp, if enabled
                 //if (CanRcvTimestampOn == 1) {
                     SerXmtBuf[SerXmtBufPtr]   = hex2ascii((msg.time_stamp & 0xF000)>>12);
                     SerXmtBuf[SerXmtBufPtr+1] = hex2ascii((msg.time_stamp & 0x0F00)>>8);
                     SerXmtBuf[SerXmtBufPtr+2] = hex2ascii((msg.time_stamp & 0x00F0)>>4);
                     SerXmtBuf[SerXmtBufPtr+3] = hex2ascii (msg.time_stamp & 0x000F);
                     SerXmtBufPtr = SerXmtBufPtr +4;
                 //}

                 SerXmtBuf[SerXmtBufPtr] = '\r'; // Append <CR>
                 SerXmtBufPtr ++;
             }
    rxcallback(SerXmtBuf,SerXmtBufPtr );

}


void InitCan()
{
    HAL_CANIntIT(bitrate_table[CanSpeed],2,0);
    CAN_FilterInitTypeDef CAN_FilterInitSturcture={0};
    CAN_FilterInitSturcture.CAN_FilterNumber = 0;
    CAN_FilterInitSturcture.CAN_FilterMode  = CAN_FilterMode_IdMask;
    CAN_FilterInitSturcture.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitSturcture.CAN_FilterIdHigh = 0;
    CAN_FilterInitSturcture.CAN_FilterIdLow = 0;
    CAN_FilterInitSturcture.CAN_FilterMaskIdHigh =0;
    CAN_FilterInitSturcture.CAN_FilterMaskIdLow = 0;
    CAN_FilterInitSturcture.CAN_FilterFIFOAssignment = CAN_Filter_FIFO1;
    CAN_FilterInitSturcture.CAN_FilterActivation = ENABLE;
    CAN_FilterInit( &CAN_FilterInitSturcture );
    HAL_CANToOperatingMode();

}


void DataParser( uint8_t * SerRcvBuf, uint8_t CmdLength, void (* rxcallback)(  uint8_t *, uint8_t    )   )
{
   static u8 TX_DATA = 1;
   static uint8_t TX_BUFFER[100];
   TX_BUFFER[0]  = LAWICEL_ERROR;

   switch (SerRcvBuf[0])
   {
        case (CANHACKER_SET_BITRATE):
            if (( CmdLength == 2 ) && (CanChnOpen==0))
            {
                  CanSpeed = ascii2hex(SerRcvBuf[1]);
                  if (CanSpeed<= 8)
                  {
                        CanInitialized = 1;
                        TX_BUFFER[0] =LAWICEL_SUCCES;
                  }
            }
            break;
        case (CANHACKER_SET_BTR):
                break;
        case (CANHACKER_OPEN): // Open CAN channel in normal mode
            if ((CmdLength == 1)&& (CanChnOpen == 0) && (CanInitialized == 1)) {
                InitCan();
                CanChnOpen = 1;
                CanBusMode = LAWICEL_BUS_ON;
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }
            break;
        case (CANHACKER_LISTEN_OPEN ): // Open CAN channel in listen-only mode
            if ((CmdLength == 1)&& (CanChnOpen == 0) && (CanInitialized == 1)) {
                InitCan();
                CanChnOpen = 1;
                CanBusMode =LAWICEL_BUS_LOM;
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }
            break;
            //-------------------------------------------------
        case (CANHACKER_CLOSE): // Close CAN channel
            if ((CmdLength == 1)) {
                HAL_CANToInitMode();
                CanChnOpen = 0;
                CanBusMode = LAWICEL_BUS_OFF;
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }

            break;
            //-------------------------------------------------
        case ('t'): // Send 11bit CAN message
            if ( ( CmdLength > 5 )  && (CanChnOpen == 1) &&  (CanBusMode == LAWICEL_BUS_ON)  )
            {
                TransmitStandardFrame(SerRcvBuf, TX_BUFFER, &TX_DATA);

            }
            break;
            //-------------------------------------------------
        case ('T'): // Send 29bit CAN message
            if ((CmdLength > 10) &&  (CanChnOpen == 1)  &&  (CanBusMode == LAWICEL_BUS_ON))
            {
                TransmitExtendedFrame(SerRcvBuf, TX_BUFFER, &TX_DATA);
            }
            break;
            //-------------------------------------------------
        case ('r'):// Send 11bit RTR
            if ((CmdLength == 5)
            &&  (CanChnOpen == 1)
            &&  (CanBusMode == LAWICEL_BUS_ON)) {
                TransmitStandardRtr(SerRcvBuf, TX_BUFFER, &TX_DATA);


            }

            break;
            //-------------------------------------------------
        case ('R'): // Send 29bit RTR
            if ((CmdLength == 10)
            &&  (CanChnOpen == 1)
            &&  (CanBusMode == LAWICEL_BUS_ON)) {
                TransmitExtendedRtr(SerRcvBuf, TX_BUFFER, &TX_DATA);

            }

            break;
            //-------------------------------------------------
        case ('X'): // activate AutoPollAutoSend feature
            if ((CmdLength == 2)
            &&  (ascii2hex(SerRcvBuf[1]) <= 1)) {
                AutoPollAutoSend = ascii2hex(SerRcvBuf[1]);
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }
            break;
            //-------------------------------------------------
        case ('D'): // single or dual filter
            if ((CmdLength == 2) )
             {
                TX_BUFFER[0] =LAWICEL_SUCCES;

            }

            break;
            //-------------------------------------------------
        case ('W'): // Dual or Single Filter
            if ((CmdLength == 2)
            &&  (ascii2hex(SerRcvBuf[1]) <= 1)) {
                FilterMode = ascii2hex(SerRcvBuf[1]);
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }
            break;

        case ('V'): // request version HW+SW
            if (CmdLength == 1) {
                GetVersionInfo(TX_BUFFER, &TX_DATA);
            }
            break;
            //-------------------------------------------------
                case ('v'): // request version HW+SW
            if (CmdLength == 1)
            {
                GetVersionInfo(TX_BUFFER, &TX_DATA);
            }
            break;
            //-------------------------------------------------
        case ('N'): // request serial number
            if (CmdLength == 1)
            {
                GetSerialNumber(TX_BUFFER, &TX_DATA);
            }
            break;
            //-------------------------------------------------
        case (CANHACKER_TIME_STAMP): // activate timestamp feature
            if ((CmdLength == 2)  && (ascii2hex(SerRcvBuf[1]) <= 1) && (CanChnOpen == 0) ) 
            {
                CanRcvTimestampOn = ascii2hex(SerRcvBuf[1]);
                TX_BUFFER[0] =LAWICEL_SUCCES;
            }
            break;
        default:
            break;

    }
    rxcallback(TX_BUFFER,TX_DATA);
}
static uint32_t timer_counter = 0;

uint32_t getTimeCounter()
{
    return timer_counter;
}

void MSTimrCallBack()
{
   if  (++timer_counter > 60000) timer_counter = 0;
}


