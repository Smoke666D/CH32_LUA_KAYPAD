#include "hw_lib_can.h"
#include "hal_can.h"

CANRX MailBoxBuffer[MAILBOXSIZE];

static void vFilterSet(uint16_t mailboxindex);
static void vFilterSetExtd(uint16_t mailboxindex);
static QueueHandle_t pCanTXHandle;
static QueueHandle_t pCanRXHandle;
static TaskHandle_t  pCanTXTaskHandle;
static TaskHandle_t  pCanRXTaskHandle;


TaskHandle_t * xGetRXTaskHandle ()
{
    return  &pCanRXTaskHandle ;
}
TaskHandle_t * xGetTXTaskHandle ()
{
    return  &pCanTXTaskHandle ;
}
static CAN_ERROR_TYPE eCanError;

QueueHandle_t* pCANTXgetQueue ( void )
{
  return ( &pCanTXHandle );
}

/*
 *
 */
QueueHandle_t* pCANRXgetQueue ( void )
{
  return ( &pCanRXHandle );
}
CANRX * getMailBox()
{
	return MailBoxBuffer;
}


/*
 *
 */
uint8_t vCheckAnswer( void )
{
	 return ( MailBoxBuffer[0].new_data );
}

uint8_t vCanChekMessage(uint32_t id)
{
	uint8_t ucRes = 0;
	uint8_t max_data = MAILBOXSIZE;
	for (int k=0;k < max_data;k++)
	{
		if ((MailBoxBuffer[k].new_data == 1) && (MailBoxBuffer[k].ident = id  & (~CAN_EXT_FLAG)))
		{
				ucRes = 1U;
				break;
		}
	}
	return ( ucRes );
}

uint8_t vCanGetMessage(CAN_FRAME_TYPE * RXPacket)
{
	uint8_t res = 0U;
	uint16_t first_index, last_index;
	uint32_t can_id = RXPacket->ident;
	if ((can_id & CAN_EXT_FLAG) == CAN_EXT_FLAG )
    {
		can_id = can_id & (~CAN_EXT_FLAG);
		first_index = NORMAL_CAN_ID_FILTER_COUNT ;
		last_index = MAILBOXSIZE;
    }
    else
    {
    	first_index = 0;
        last_index = NORMAL_CAN_ID_FILTER_COUNT ;
    }
	for (uint16_t k =  first_index ; k < last_index; k++)
	{
		if ((MailBoxBuffer[k].new_data == 1) && (MailBoxBuffer[k].ident == can_id ))
		{
			RXPacket->DLC = MailBoxBuffer[k].DLC;
			for (int i =0; i < RXPacket->DLC;i++)
			{
				RXPacket->data[i] = MailBoxBuffer[k].data[i];
			}
			MailBoxBuffer[k].new_data = 0;
			res = 1U;
			break;
		}
	}
	return ( res );
}


void vConfigFiler()
{


	for (int i = 0;i<HALF_CAN_FILTER_COUNT;i++)
	{
	   HAL_CANSetFiters(i,0,0,0,0,FILTER_FIFO_0);
		
	}

	for (int i = HALF_CAN_FILTER_COUNT ;i<CAN_FILTER_COUNT;i++)
	{
		
		HAL_CANSetFitersEX(i,0,0,FILTER_FIFO_1);
	}


}



void MsgFromCan( HAL_CAN_RX_FIFO_NUMBER_t fifo)
{
   CAN_FRAME_TYPE msg_to_send;
   BaseType_t xHigherPriorityTaskWoken = pdFALSE;
   HAL_CAN_MSG_GET(  fifo,  &msg_to_send );
   xQueueSendFromISR(pCanRXHandle,&msg_to_send,&xHigherPriorityTaskWoken);
   portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

void vCallBack()
{
    CAN_TX_FRAME_TYPE buffer;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if (xQueueReceiveFromISR(pCanTXHandle,&buffer,&xHigherPriorityTaskWoken)==pdPASS)
    {
        HAL_CANSend(&buffer);
    }
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}

void vCANBoudInit( uint16_t boudrate )
{
	
   HAL_CANSetTXCallback(&vCallBack);

   HAL_CANSetRXCallback(&MsgFromCan);
    HAL_CANIntIT( boudrate,1,1);
	
		for (int i=0;i<MAILBOXSIZE;i++)
	{
		 MailBoxBuffer[i].ident = 0U;
		 MailBoxBuffer[i].new_data = 0U;
	}
    return;
}

void vSetWaitFilter(uint32_t id)
{
	 MailBoxBuffer[0].ident = id;
	 vFilterSet(0);

	 return;
}
/*
 *
 */
uint8_t vCanGetRequest(CAN_FRAME_TYPE * RXPacket)
{
	uint8_t res = 0U;
	res = vCheckAnswer();
	if ( res != 0U )
	{
		RXPacket->ident = MailBoxBuffer[0].ident;
		RXPacket->DLC = MailBoxBuffer[0].DLC;
		for (int i =0; i < RXPacket->DLC;i++)
		{
			RXPacket->data[i] = MailBoxBuffer[ 0U ].data[i];
		}
		MailBoxBuffer[0].new_data 	= 0U;
		MailBoxBuffer[0].ident 		= 0U;
	}
	return ( res );
}
/*
/*
 *
 */
void vCanInsertRXData(CAN_FRAME_TYPE * RXPacket)
{
	uint16_t id = RXPacket->filter_id;
	if (MailBoxBuffer[id].ident == RXPacket->ident)
	{
			MailBoxBuffer[id].DLC = RXPacket->DLC;
			for (int k =0;k <RXPacket->DLC;k++)
			{
				 MailBoxBuffer[id].data[k] =  RXPacket->data[k];
			}
			MailBoxBuffer[id].new_data = 1;
			return;
	}
	else
	{
		for (int i=0;i<MAILBOXSIZE;i++)
		{
			if (MailBoxBuffer[i].ident == RXPacket->ident)
				{
						MailBoxBuffer[i].DLC = RXPacket->DLC;
						for (int k =0;k <RXPacket->DLC;k++)
						{
							 MailBoxBuffer[i].data[k] =  RXPacket->data[k];
						}
						MailBoxBuffer[i].new_data = 1;
						return;
				}
		}
	}

	return;
}

ERROR_TYPE_t eMailboxFilterSet(uint32_t id)
{
	ERROR_TYPE_t eRes = BUFFER_FULL;

	if ( (id & CAN_EXT_FLAG ) == CAN_EXT_FLAG )   //§¦§ã§Ý§Ú ID §â§Ñ§ã§ê§Ú§â§Ö§ß§ß§í§Û
	{
		for (int i = NORMAL_CAN_ID_FILTER_COUNT ; i < MAILBOXSIZE; i++)  //§´§à §Ú§ë§Ö§Þ §ã§Ó§à§Ò§à§Õ§ß§í§Û §Ò§å§æ§æ§Ö§â §Ó §ã§ä§Ñ§â§ê§Ö§Û §á§à§Ý§à§Ó§Ú§ß§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ
		{
			if ( MailBoxBuffer[i].ident == 0U )
			{
				MailBoxBuffer[i].ident = id & (~CAN_EXT_FLAG);
				vFilterSetExtd(i);
				eRes = ERROR_NO;
				break;
			}
		}
	}
	else
	{
		for (int i=1; i < NORMAL_CAN_ID_FILTER_COUNT ; i++)
		{
			if ( MailBoxBuffer[i].ident == 0U )
			{
				MailBoxBuffer[i].ident = id;
				vFilterSet(i);
				eRes = ERROR_NO;
				break;
			}
		}
	}
	return ( eRes );
}

/*
 *
 */
void vCanInsertTXData(uint32_t CanID, uint8_t * data, uint8_t data_len )
{
	CAN_TX_FRAME_TYPE data_to_send;
	data_to_send.ident = CanID;
	data_to_send.DLC   = data_len;
	for (uint8_t i=0; i<data_len;i++)
	{
		data_to_send.data[i] = data[i];
	}
	xQueueSend(pCanTXHandle, &data_to_send, 1U);
	return;
}


static void vFilterSet(uint16_t mailboxindex)
{
	 uint16_t index = mailboxindex / 4;
     uint32_t FilterIdHigh 	= (MailBoxBuffer[index*4U +2U ].ident) ;
     uint32_t FilterIdLow  	= (MailBoxBuffer[index*4U  ].ident) ;
     uint32_t FilterMaskIdHigh = (MailBoxBuffer[index*4U +3U ].ident) ;
     uint32_t FilterMaskIdLow  = (MailBoxBuffer[index*4U +1U ].ident);
     HAL_CANSetFiters(index,FilterIdLow,FilterMaskIdLow ,FilterIdHigh ,FilterMaskIdHigh,FILTER_FIFO_0);
     return;
}

static void vFilterSetExtd(uint16_t mailboxindex)
{

		 uint16_t index = HALF_CAN_FILTER_COUNT +  ( mailboxindex - NORMAL_CAN_ID_FILTER_COUNT )/ 2;  //§ª§ß§Õ§Ö§Ü§ã §Ò§Ñ§ß§Ü§Ñ §æ§Ú§Ý§î§ä§â§à§Ó, §Ó §Ü§à§ä§à§â§à§Þ §ß§Ñ§Õ§à §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §æ§Ú§Ý§î§ä§â
		 uint16_t offset = (mailboxindex % 2) ? mailboxindex - 1 : mailboxindex;   //§ª§ß§Õ§Ö§Ü§ã §á§Ö§â§Ó§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §Þ§Ñ§ã§ã§Ú§Ó§Ö  MailBoxBuffer, §Ü§à§ä§à§â§í§Û §ß§Ñ§Õ§à §Ù§Ñ§á§Ú§ç§Ñ§ä§î §Ó §æ§Ú§Ý§î§ä§â.
	     HAL_CANSetFitersEX(index, MailBoxBuffer[offset     ].ident,MailBoxBuffer[offset +1U ].ident,FILTER_FIFO_1 );
	     return;

}

/*
 *
 */
void vCanRXTask(void *argument)
{
	CAN_FRAME_TYPE RXPacket;
	while(1)
	{
		xQueueReceive( pCanRXHandle, &RXPacket,  portMAX_DELAY );
		vCanInsertRXData(&RXPacket);
		eCanError = CAN_NORMAL;
	}
}

/*
 * §±§â§à§è§Ö§ã§ã §Õ§Ý§ñ §à§Ò§â§Ñ§Ò§à§ä§Ü§Ú can §ã§à§à§Ò§ë§Ö§ß§Ú§Û
 */
void vCanTXTask(void *argument)
{
	CAN_TX_FRAME_TYPE TXPacket;
	while(1)
	{

		xQueuePeek( pCanTXHandle, &TXPacket, portMAX_DELAY);
		if (HAL_CAN_TX_MAIL_BOX() != CAN_TxStatus_NoMailBox )
		{
			xQueueReceive( pCanTXHandle, &TXPacket, 1);
			HAL_CAN_MSG_SEND(&TXPacket);
			eCanError = CAN_NORMAL;
		}
	}
}