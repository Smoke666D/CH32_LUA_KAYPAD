/*
 * lawicel.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef LAWICEL_H_
#define LAWICEL_H_

#include "main.h"
#include <stdio.h>
#include <string.h>
#include "hal_can.h"

typedef enum
{
    LAWICEL_ERROR  =  0x7,
    LAWICEL_SUCCES =  0xD,

} LAWICEL_ERROR_CODE;

typedef void (*xCanTxCallBack)( CAN_TX_FRAME_TYPE *buffer ) ;


#define CANHACKER_SET_BITRATE     'S' // set CAN bit rate
#define CANHACKER_SET_BTR         's' // Настраивает BTR0/BTR1 CAN-контроллера SJA1000, где xx и yy шестнадцатеричные (HEX) 
#define CANHACKER_OPEN            'O'
#define CANHACKER_LISTEN_OPEN     'L'
#define CANHACKER_CLOSE           'C'
#define CANHACKER_TIME_STAMP      'Z'         

 typedef struct {
     uint8_t* data;
     uint16_t size;
     volatile uint16_t readIndex;
     volatile uint16_t writeIndex;
     volatile bool overrun;
 } rBuffer_t;
 void     ring_buffer_init(rBuffer_t* rb, uint8_t* pdata, size_t size);
 void     ring_buffer_reset(rBuffer_t* rb);
 void     ring_buffer_flush(rBuffer_t* rb);

 size_t   ring_buffer_available(rBuffer_t* rb);
 size_t   ring_buffer_available_for_write(rBuffer_t* rb);

 size_t   ring_buffer_find(rBuffer_t* rb, uint8_t byte);
 void     ring_buffer_seek(rBuffer_t* rb, uint8_t byte);

 uint8_t  ring_buffer_at(rBuffer_t* rb, size_t i);
 uint8_t  ring_buffer_peek(rBuffer_t* rb);

 uint8_t  ring_buffer_read(rBuffer_t* rb);
 size_t   ring_buffer_read_bytes(rBuffer_t* rb, uint8_t* pdata, size_t size);

 void     ring_buffer_write(rBuffer_t* rb, uint8_t byte);
 size_t   ring_buffer_write_bytes(rBuffer_t* rb, uint8_t* pdata, size_t size);

 /* low level */
 void     ring_buffer_move_read_index(rBuffer_t *rb, uint16_t offset);
 void     ring_buffer_move_write_index(rBuffer_t *rb, uint16_t offset);

 uint8_t* ring_buffer_get_read_ptr(rBuffer_t *rb);
 uint8_t* ring_buffer_get_write_ptr(rBuffer_t *rb);

 size_t   ring_buffer_get_read_linear_size(rBuffer_t *rb);
 size_t   ring_buffer_get_write_linear_size(rBuffer_t *rb);

/* version */

#define CONVERTER_VERSION_HW        "v002_EMU"
#define CONVERTER_VERSION_SW        "v011"

/* constants */

#define LAWICEL_RX_BUFFER_SIZE      128
#define LAWICEL_TX_BUFFER_SIZE      512
#define LAWICEL_CAN_TX_BUFFER_SIZE  512



typedef enum LAWICEL_TimestampState
{
  LAWICEL_TIMESTAMP_DISABLED = 0,
  LAWICEL_TIMESTAMP_ENABLED = 1,
} LAWICEL_TimestampState_t;

typedef enum
{
  LAWICEL_BUS_OFF = 0,
  LAWICEL_BUS_ON = 1,
  LAWICEL_BUS_LOM = 2,
} LAWICEL_BUS_STATE;

typedef struct LAWICEL_Instance
{
  //UART_HandleTypeDef *huart;
  //CAN_HandleTypeDef *hcan;

  QueueHandle_t LawicelRx;
  QueueHandle_t LawicelTx;
  QueueHandle_t CanTx;

  LAWICEL_TimestampState_t TimestampState;
  uint32_t savedTicks;
  uint16_t timer;

 // struct {
  //  bool lssFastScan;
 // } Flag;

} LAWICEL_Instance_t;

typedef struct
{
    CAN_FRAME_TYPE msg;
    uint32_t time_stamp;
} LAWICEL_CAN_MSG_t;


/* LAWICEL protocol */
#define LAWICEL_GET_VERSION         'v'
#define LAWICEL_GET_HARDWARE        'V'

#define LAWICEL_TRANSMIT_EXT        'T'
#define LAWICEL_TRANSMIT_STD        't'

#define LAWICEL_USE_TIMESTAMP       'Z'
#define LAWICEL_SET_BITRATE         'S'
#define LAWICEL_CLOSE_CAN           'C'
#define LAWICEL_OPEN_CAN            'O'

#define LAWICEL_CANOPEN_LSS         'L'
#define LAWICEL_LSS_FASTSCAN        'f'
#define LAWICEL_FASTSCAN_ERROR      'e'
#define LAWICEL_FASTSCAN_COMPLETE   'c'



uint8_t hex2ascii(uint8_t chr);
void ParseCanMessage(LAWICEL_CAN_MSG_t msg, void (* rxcallback)(  uint8_t *, uint8_t    ) );
uint32_t getTimeCounter();
void MSTimrCallBack();
#define LAWICEL_TIMER_MAX_MS        60000
void LAWICEL_Init( MessageBufferHandle_t * MessageBuffer, xCanTxCallBack func );
void DataParser( uint8_t * SerRcvBuf, uint8_t CmdLength, void (* rxcallback)(  uint8_t *, uint8_t    )   );
//void DataParser( uint8_t * data_buffer, uint8_t CmdLength, uint8_t * TX_BUFFER, uint8_t  TX_DATA );
void ProcessMsgFromCan( HAL_CAN_RX_FIFO_NUMBER_t fifo) ;
uint8_t ascii2hex(uint8_t chr);

#endif /* LAWICEL_H_ */
