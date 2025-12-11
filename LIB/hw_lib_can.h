#ifndef HW_LIB_CAN_H_
#define HW_LIB_CAN_H_

#ifdef __cplusplus
 extern "C" {
#endif 

#include "hal_can.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "list.h"
#include "task.h"
#include "semphr.h"
#include "message_buffer.h"
#include "portmacro.h"

#define CAN_EXT_FLAG   0x80000000
#define CAN_RTR_FLAG   0x40000000

#define CAN_FILTER_COUNT              16
#define HALF_CAN_FILTER_COUNT		  (CAN_FILTER_COUNT/2)
#define NORMAL_CAN_ID_FILTER_COUNT   ((HALF_CAN_FILTER_COUNT)*4)
#define EXTEND_CAN_ID_FILTER_COUNT   ((HALF_CAN_FILTER_COUNT)*2)
#define MAILBOXSIZE  (NORMAL_CAN_ID_FILTER_COUNT  + EXTEND_CAN_ID_FILTER_COUNT )





typedef struct {
  uint8_t enable:1;
  uint8_t index;
} CanFilterHeandler;

#define  ANSWER_FILTER 0x01
#define  INPUT_FILTER  0x00


typedef enum
{
  ERROR_NO  = 0,
  BUFFER_FULL = 1
} ERROR_TYPE_t;


bool lib_can_get_new_data( const uint8_t mail_box_index, CAN_FRAME_TYPE * RXPacket);
bool lib_can_check_new_data(uint8_t MailboxId);
bool lib_can_set_new(uint32_t id, uint8_t extd, uint8_t rtr, uint8_t * findMBIndex );


void ConfigNodeID( uint8_t node_id);
void eMailboxFilterReset(uint8_t MailboxId) ;
void vCANBoudInit( uint16_t boudrate );


void lib_can_send_data(CAN_TX_FRAME_TYPE *buffer);

SemaphoreHandle_t * pGetCanMutex();

#ifdef __cplusplus
}
#endif
#endif