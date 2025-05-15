

#ifndef HW_LIB_CAN_H_
#define HW_LIB_CAN_H_

#include "main.h"
#include "hal_can.h"


#define CAN_FILTER_COUNT              16
#define HALF_CAN_FILTER_COUNT		  (CAN_FILTER_COUNT/2)
#define NORMAL_CAN_ID_FILTER_COUNT   ((HALF_CAN_FILTER_COUNT)*4)
#define EXTEND_CAN_ID_FILTER_COUNT   ((HALF_CAN_FILTER_COUNT)*2)
#define MAILBOXSIZE  (NORMAL_CAN_ID_FILTER_COUNT  + EXTEND_CAN_ID_FILTER_COUNT )


typedef struct {
    uint16_t ident;
    uint16_t filter_id;
    uint8_t DLC;
    uint8_t data[8];
    uint8_t new_data;
} CANRX;



typedef enum {
	CAN_OFF		 	= 0,
	CAN_NORMAL	 	= 1,
	CAN_CUT_OFF 	= 2,
	CAN_SHORT_CUT 	= 3,

} CAN_ERROR_TYPE;

typedef enum
{
  ERROR_NO  = 0,
  BUFFER_FULL = 1
} ERROR_TYPE_t;

typedef enum {
  CAN_OK,
  CAN_NO_TX_MAILBOX,
} CAN_ERROR_t;

void vCanRXTask(void *argument);
void vCanTXTask(void *argument);
TaskHandle_t * xGetRXTaskHandle ();
TaskHandle_t * xGetTXTaskHandle ();
QueueHandle_t* pCANTXgetQueue ( void );
QueueHandle_t* pCANRXgetQueue ( void );
CANRX * getMailBox();
uint8_t vCheckAnswer( void );
uint8_t vCanChekMessage(uint32_t id);
uint8_t vCanGetRequest(CAN_FRAME_TYPE * RXPacket);
uint8_t vCanGetMessage(CAN_FRAME_TYPE * RXPacket);
ERROR_TYPE_t eMailboxFilterSet(uint32_t id);
void vSetWaitFilter(uint32_t id);
void vCanInsertTXData(uint32_t CanID, uint8_t * data, uint8_t data_len );
#endif