/*
 * app_task.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_APP_TASK_H_
#define USER_APP_TASK_H_

#include "main.h"
#include "system_init.h"
#include "hal_can.h"



#define CANHACKER_HW_VER        0x10      // hardware version
#define CANHACKER_SW_VER        0x10      // software version
#define CANHACKER_SW_VER_MAJOR  0x01    // software major version
#define CANHACKER_SW_VER_MINOR  0x07    // software minor version
#define CANHACKER_SERIAL        "0001"    // device serial number
#define CANHACKER_CR 13
#define CANHACKER_ERROR 7
#define CANHACKER_SET_BITRATE     'S' // set CAN bit rate
#define CANHACKER_SET_BTR         's' // set CAN bit rate via
#define CANHACKER_OPEN_CAN_CHAN   'O' // open CAN channel
#define CANHACKER_CLOSE_CAN_CHAN  'C' // close CAN channel
#define CANHACKER_SEND_11BIT_ID   't' // send CAN message with 11bit ID
#define CANHACKER_SEND_29BIT_ID   'T' // send CAN message with 29bit ID
#define CANHACKER_SEND_R11BIT_ID  'r' // send CAN remote message with 11bit ID
#define CANHACKER_SEND_R29BIT_ID  'R' // send CAN remote message with 29bit ID
#define CANHACKER_READ_STATUS     'F' // read status flag byte
#define CANHACKER_SET_ACR         'M' // set Acceptance Code Register
#define CANHACKER_SET_AMR         'm' // set Acceptance Mask Register
#define CANHACKER_GET_VERSION     'V' // get hardware and software version
#define CANHACKER_GET_SW_VERSION  'v' // get software version only
#define CANHACKER_GET_SERIAL      'N' // get device serial number
#define CANHACKER_TIME_STAMP      'Z' // toggle time stamp setting
#define CANHACKER_READ_ECR        'E' // read Error Capture Register
#define CANHACKER_READ_ALCR       'A' // read Arbritation Lost Capture Register
#define CANHACKER_READ_REG        'G'   // read register conten from SJA1000
#define CANHACKER_WRITE_REG       'W'   // write register content to SJA1000
#define CANHACKER_LISTEN_ONLY     'L' // switch to listen only mode



#define UART_RX_BUFFER 256

typedef struct
{
    uint8_t buffer[UART_RX_BUFFER];
    uint8_t readed;
    uint8_t filled;
    int offset;
} UART_DMA_RX_Buffer;

void APPCANSEND(CAN_TX_FRAME_TYPE *buffer);
QueueHandle_t * xTXQueue( void );
MessageBufferHandle_t * xTXMessage(void);
TaskHandle_t * xGetCanTaskHandle ();
TaskHandle_t * xGetAppTaskHandle ();
void vAppTask( void * argument );
void vCanTask( void * argument );
void vAppInit();
QueueHandle_t * xRXQueue( void );

#endif /* USER_APP_TASK_H_ */
