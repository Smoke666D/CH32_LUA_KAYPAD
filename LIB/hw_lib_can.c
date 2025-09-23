#include "hw_lib_can.h"
#include "hal_flash.h"

CANRX MailBoxBuffer[MAILBOXSIZE];
static void vInitMailBoxBuffer( void );
static uint16_t CANbitRate;



static TaskHandle_t  CanRXTaskHandle;
static MessageBufferHandle_t pCanRXMessageBuffer;
static MessageBufferHandle_t pCanTXMessageBuffer;
static uint8_t Answer_filter_id = 0xFF;


MessageBufferHandle_t * xGetCanTXMessageBufffer()
{
	return &pCanTXMessageBuffer;
}

MessageBufferHandle_t * xGetCanRXMessageBufffer()
{
	return &pCanRXMessageBuffer;
}

TaskHandle_t * xGetCanRXTaskHandle ()
{
    return  &CanRXTaskHandle ;
}




 void CAN_SendMessage()
 {
    CAN_TX_FRAME_TYPE buffer;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if (xMessageBufferReceiveFromISR(pCanTXMessageBuffer,&buffer,sizeof( CAN_TX_FRAME_TYPE),&xHigherPriorityTaskWoken) !=0 )
    {
        HAL_CANSend(&buffer);
    }
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
 }

 void vRestartNode( void )
{

    return;
}


/*
 *
 */
void vSetWaitFilter(uint32_t id)
{

	 MailBoxBuffer[0].ident = id;
	// vFilterSet(0);

	 return;
}

/*
 *
 */
uint8_t vCheckAnswer( void )
{
	if (Answer_filter_id!=0xFF)
	{
	 return ( (MailBoxBuffer[Answer_filter_id].new_data == 1) ? 1: 0 );
	}
	return 0;
}

uint8_t vCanChekMessage(uint32_t id)
{
	uint8_t ucRes = 0;
	for (int k=0;k < MAILBOXSIZE;k++)
	{
		if ((MailBoxBuffer[k].new_data == 1) && (MailBoxBuffer[k].ident ==( id  & (~CAN_EXT_FLAG))))
		{
				ucRes = 1U;
				break;
		}
	}
	return ( ucRes );
}

 void  prv_read_can_received_msg( HAL_CAN_RX_FIFO_NUMBER_t fifo) 
{
   CAN_FRAME_TYPE rxMsg;
   HAL_CAN_MSG_GET(fifo, &rxMsg);
   static portBASE_TYPE xHigherPriorityTaskWoken;
   xHigherPriorityTaskWoken = pdFALSE;
   xMessageBufferSendFromISR(pCanRXMessageBuffer,&rxMsg,sizeof(CAN_FRAME_TYPE), &xHigherPriorityTaskWoken );
   portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
   return;
}
uint8_t vCanGetAnsewerMessage(CAN_FRAME_TYPE * RXPacket)
{
	uint8_t res = 0;
	if (Answer_filter_id!=0xFF)
	{
		if (MailBoxBuffer[Answer_filter_id].new_data == 1)
		{
			RXPacket->DLC = MailBoxBuffer[Answer_filter_id].DLC;
			for (int i =0; i < RXPacket->DLC;i++)
			{
				RXPacket->data[i] = MailBoxBuffer[Answer_filter_id].data[i];
			}
			res =1;
			eMailboxFilterReset(MailBoxBuffer[Answer_filter_id].ident);
	
		}
	}
	return (res);
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
			xTaskNotify(CanRXTaskHandle,can_id,eSetValueWithOverwrite);
			RXPacket->DLC = MailBoxBuffer[k].DLC;
			for (int i =0; i < RXPacket->DLC;i++)
			{
				RXPacket->data[i] = MailBoxBuffer[k].data[i];
			}
			MailBoxBuffer[k].new_data = 0;
			xTaskNotify(CanRXTaskHandle,0xFFFFFFFF,eSetValueWithOverwrite);
			res = 1U;
			break;
		}
	}
	return ( res );
}


uint8_t vGetNodeId( void )
{
  return ( OB->Data1 & 0xFF );
}

void vSetNodeID( uint8_t data)
{
    ProgramOptionByteData(1,data) ;
}

void ConfigNodeID( uint8_t node_id)
{
	if (vGetNodeId()!=node_id)
	{
		vSetNodeID(node_id);
	}
}

void vSetBitrate( uint8_t data)
{
    uint8_t temp = OB->Data0 & 0x80;
    ProgramOptionByteData(0,temp | (data & 0x7F )) ;
}
/*
 * §£§à§Ù§Ó§â§Ñ§ë§Ñ§Ö§Þ §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ã§Ü§à§â§à§ã§ä§Ú CAN §Ú§Ù EEPROM
 */
uint16_t vGetBitrate()
{
   return (OB->Data0 & 0x7F);
}

void vCANBoudInit( uint16_t boudrate )
{
    switch (boudrate )
    {
        case 1000:
            CANbitRate = CAN_1MBS;
            break;
        case 500:
            CANbitRate = CAN_500KBS;
            break;
        case 250:
            CANbitRate = CAN_250KBS;
            break;
        default:
            CANbitRate = CAN_125KBS;
            break;    
		case 800:
			CANbitRate = CAN_800KBS;
			break;
		case 100:
			CANbitRate = CAN_100KBS;
			break;
		case 50:
			CANbitRate = CAN_50KBS;
			break;
		case 20:
			CANbitRate = CAN_20KBS;
			break;
		case 10:
			CANbitRate = CAN_10KBS;
			break;
    }
	if (CANbitRate!=vGetBitrate() ) vSetBitrate(CANbitRate);
    HAL_CANSetTXCallback(&CAN_SendMessage);
    HAL_CANSetERRCallback(&vRestartNode);
    HAL_CANSetRXCallback(&prv_read_can_received_msg);
	xTaskNotify(CanRXTaskHandle,0xFFFFFFFF,eSetValueWithOverwrite);
    HAL_CANIntIT(CANbitRate,CAN1_PRIOR,CAN1_SUBPRIOR);
	vInitMailBoxBuffer();
    return;
}


/*
 *
 */
void vCanInsertRXData(CAN_FRAME_TYPE * RXPacket)
{
	uint32_t ulNotifiedValue;
	uint16_t id = RXPacket->filter_id;
    xTaskNotifyWait( 0x00,0x00,&ulNotifiedValue,0);
	if (ulNotifiedValue == id) 
	{
		xTaskNotifyWait( 0x00,0x00,&ulNotifiedValue,10);
	}
	if (MailBoxBuffer[id].ident == RXPacket->ident)
	{
		MailBoxBuffer[id].DLC = RXPacket->DLC;
		for (int k =0;k <RXPacket->DLC;k++)
		{
			MailBoxBuffer[id].data[k] =  RXPacket->data[k];
		}
		MailBoxBuffer[id].new_data = 1;
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
					break;
			}
		}
	}

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
		xMessageBufferReceive(pCanRXMessageBuffer,&RXPacket,sizeof(CAN_FRAME_TYPE),portMAX_DELAY);
		vCanInsertRXData(&RXPacket); 
	}
}


static void vFilterSet(uint16_t mailboxindex)
{
	 uint16_t index = mailboxindex / 4;
     HAL_CANSetFiters(	index,
	 					MailBoxBuffer[index*4U  	].ident,
	 					MailBoxBuffer[index*4U  +1 	].ident,
						MailBoxBuffer[index*4U  +2	].ident,
	 					MailBoxBuffer[index*4U  +3	].ident   , 
						FILTER_FIFO_0); 
	 return;
}

void vFilterSetExtd(uint16_t mailboxindex)
{
		 uint16_t index = HALF_CAN_FILTER_COUNT +  ( mailboxindex - NORMAL_CAN_ID_FILTER_COUNT )/ 2;  //§ª§ß§Õ§Ö§Ü§ã §Ò§Ñ§ß§Ü§Ñ §æ§Ú§Ý§î§ä§â§à§Ó, §Ó §Ü§à§ä§à§â§à§Þ §ß§Ñ§Õ§à §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §æ§Ú§Ý§î§ä§â
		 uint16_t offset = (mailboxindex % 2) ? mailboxindex - 1 : mailboxindex;   //§ª§ß§Õ§Ö§Ü§ã §á§Ö§â§Ó§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §Þ§Ñ§ã§ã§Ú§Ó§Ö  MailBoxBuffer, §Ü§à§ä§à§â§í§Û §ß§Ñ§Õ§à §Ù§Ñ§á§Ú§ç§Ñ§ä§î §Ó §æ§Ú§Ý§î§ä§â
		 HAL_CANSetFitersEX(	index,
		 						MailBoxBuffer[offset     ].ident,
								MailBoxBuffer[offset  +1 ].ident,
								FILTER_FIFO_1);
	     return;

}




ERROR_TYPE_t eMailboxFilterSet(uint32_t id, CLIB_FILTER_TYPE is_answer_fiter) 
{
	ERROR_TYPE_t eRes = BUFFER_FULL;

	if ( (id & CAN_EXT_FLAG ) == CAN_EXT_FLAG )   //§¦§ã§Ý§Ú ID §â§Ñ§ã§ê§Ú§â§Ö§ß§ß§í§Û
	{
		for (int i = NORMAL_CAN_ID_FILTER_COUNT ; i < MAILBOXSIZE; i++)  //§´§à §Ú§ë§Ö§Þ §ã§Ó§à§Ò§à§Õ§ß§í§Û §Ò§å§æ§æ§Ö§â §Ó §ã§ä§Ñ§â§ê§Ö§Û §á§à§Ý§à§Ó§Ú§ß§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ
		{
			if ( MailBoxBuffer[i].ident == 0U )
			{
				MailBoxBuffer[i].ident = id & (~CAN_EXT_FLAG);
				Answer_filter_id  =  (is_answer_fiter == ANSWER_FILTER) ? i:0xFF;
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
				if (is_answer_fiter == ANSWER_FILTER) Answer_filter_id  = i;
				vFilterSet(i);
				eRes = ERROR_NO;
				break;
			}
		}
	}
	return ( eRes );
}



/*
§°§ä§á§â§Ñ§Ó§Ü§Ñ §á§Ñ§Ü§Ö§ä§Ñ §Ó §ã§Ö§ä§î CAN. 
§¦§ã§Ý§Ú §ä§Ö§Ü§å§ë§Ú§Ö §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§í §ã§à§ß§ä§â§à§Ý§Ý§Ö§â§Ñ CAN §Ù§Ñ§ß§ñ§ä§í, §ä§à §á§Ñ§Ü§Ö§ä §â§Ñ§Ù§Þ§Ö§ë§Ñ§Ö§ä§ã§ñ §Ó §à§é§Ö§â§Ö§Õ§Ú §à§á§Ö§â§Ñ§è§Ú§à§ß§ß§à§Û §ã§Ú§ã§ä§Ö§Þ§í
*/
void APPCANSEND(CAN_TX_FRAME_TYPE *buffer)
{
    if ( HAL_CANSend(buffer) == CAN_TxStatus_NoMailBox )
    {
		xMessageBufferSend(pCanTXMessageBuffer,&buffer,sizeof(CAN_TX_FRAME_TYPE), portMAX_DELAY);
        //xQueueSend(pCanTXHandle,buffer,portMAX_DELAY);
    }
}



static void vInitMailBoxBuffer( void )
{
	for (int i=0;i<MAILBOXSIZE;i++)
	{
		  MailBoxBuffer[i].ident = 0U;
		 MailBoxBuffer[i].new_data = 0U;
         HAL_CANResetFiltesr(i);
	}
	return;
}
void eMailboxFilterReset(uint32_t id) 
{
if ( (id & CAN_EXT_FLAG ) == CAN_EXT_FLAG )   //§¦§ã§Ý§Ú ID §â§Ñ§ã§ê§Ú§â§Ö§ß§ß§í§Û
	{
		for (int i = NORMAL_CAN_ID_FILTER_COUNT ; i < MAILBOXSIZE; i++)  //§´§à §Ú§ë§Ö§Þ §ã§Ó§à§Ò§à§Õ§ß§í§Û §Ò§å§æ§æ§Ö§â §Ó §ã§ä§Ñ§â§ê§Ö§Û §á§à§Ý§à§Ó§Ú§ß§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ
		{
			if ( MailBoxBuffer[i].ident == (id & CAN_EXT_FLAG)  )
			{
				MailBoxBuffer[i].ident = 0;
				MailBoxBuffer[i].new_data = 0;
				vFilterSetExtd(i);
				break;
			}
		}
	}
	else
	{
		for (int i=1; i < NORMAL_CAN_ID_FILTER_COUNT ; i++)
		{
			if ( MailBoxBuffer[i].ident == id )
			{
				MailBoxBuffer[i].ident = 0;
				MailBoxBuffer[i].new_data = 0;
				vFilterSet(i);
				break;
			}
		}
	}
	return;

}