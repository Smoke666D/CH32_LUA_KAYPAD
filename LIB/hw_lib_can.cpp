#include "hw_lib_can.h"
#include "hal_flash.h"
#include "string.h"
#include "system_init.h"
#include "hw_lib_can_mail_box.h"

static void  prv_read_can_received_msg( HAL_CAN_RX_FIFO_NUMBER_t fifo);
static void CAN_SendMessage();
static CAN_BOUNDRATE CANbitRate;
static  can_lib_mail_box <MAILBOXSIZE>   MailBoxBuffer;

/*
 *
 */
class cpp_can_rx_buffer : public os::os_message_buffer<cpp_can_rx_buffer,  CANRX_QUEUE_SIZE * sizeof( CAN_FRAME_TYPE )> {}
can_rx_buffer = {};

class cpp_can_tx_buffer : public os::os_message_buffer<cpp_can_rx_buffer,  CANRX_QUEUE_SIZE * sizeof( CAN_FRAME_TYPE )> {}
can_tx_buffer = {};

class cpp_can_rx_task : public os::os_task<cpp_can_rx_task, CANRX_STK_SIZE>
{
 public:
    void run(void )  __attribute__((__noreturn__)) ;        
    using os_task::os_task;
	
};

cpp_can_rx_task can_rx_task ={"can_rx_Task",CANRX_TASK_PRIO};
/*
*/
void cpp_can_rx_task::run( void )
{
	CAN_FRAME_TYPE RXPacket;
	while(1)
	{  
		can_rx_buffer.recieve(static_cast<void *>(&RXPacket),sizeof(CAN_FRAME_TYPE),portMAX_DELAY);
		MailBoxBuffer.insert(&RXPacket);
		
	}
}

/*
*/
static void  prv_read_can_received_msg( HAL_CAN_RX_FIFO_NUMBER_t fifo) 
{
   CAN_FRAME_TYPE rxMsg;
   HAL_CAN_MSG_GET(fifo, &rxMsg);
   can_rx_buffer.isr_send(&rxMsg,sizeof(CAN_FRAME_TYPE));
   return;
}

/*
*/
static void CAN_SendMessage()
{
    CAN_TX_FRAME_TYPE buffer;
	if (can_tx_buffer.isr_recieve(&buffer, sizeof( CAN_TX_FRAME_TYPE)) !=0 )
    {
        HAL_CANSend(&buffer);
    }
}

/*
*/
static void SetFilter( uint8_t _index)
{
	if (_index > NORMAL_CAN_ID_FILTER_COUNT )	
	{
		uint16_t index = HALF_CAN_FILTER_COUNT +  ( _index - NORMAL_CAN_ID_FILTER_COUNT )/ 2;  //§ª§ß§Õ§Ö§Ü§ã §Ò§Ñ§ß§Ü§Ñ §æ§Ú§Ý§î§ä§â§à§Ó, §Ó §Ü§à§ä§à§â§à§Þ §ß§Ñ§Õ§à §å§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §æ§Ú§Ý§î§ä§â
		uint16_t offset = (_index % 2) ? _index - 1 : _index;   //§ª§ß§Õ§Ö§Ü§ã §á§Ö§â§Ó§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §Þ§Ñ§ã§ã§Ú§Ó§Ö  MailBoxBuffer, §Ü§à§ä§à§â§í§Û §ß§Ñ§Õ§à §Ù§Ñ§á§Ú§ç§Ñ§ä§î §Ó §æ§Ú§Ý§î§ä§â
		HAL_CANSetFitersEX(	index,
		 					MailBoxBuffer.get_id(offset),
							MailBoxBuffer.get_id(offset  +1),
							FILTER_FIFO_1 );

	}
	else 
	{
		uint16_t index = _index / 4;
     	HAL_CANSetFiters( index,
	 					  MailBoxBuffer.get_id(index*4U),
	 					  MailBoxBuffer.get_id(index*4U  +1),
						  MailBoxBuffer.get_id(index*4U  +2),
	 					  MailBoxBuffer.get_id(index*4U  +3), 
						  FILTER_FIFO_0); 
	}
}


/***********************************************************PUBLIC FUNCTION*************************************************************************************************/

/*
*  §¶§å§ß§Ü§è§Ú§ñ §Ó§à§Ù§Ó§â§Ñ§ë§Ñ§Ö§ä §ã§é§Ú§ä§í§Ó§Ñ§Ö§ä §Õ§Ñ§ß§ß§í§Ö §Ú§Ù §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§Ñ §ã §ß§å§Ø§ß§í§Þ §ß§à§Þ§Ö§â§à§Þ
*/
bool lib_can_get_new_data( const uint8_t mail_box_index, CAN_FRAME_TYPE * RXPacket )
{	
	return MailBoxBuffer.get_new(mail_box_index, *RXPacket);
}

/*
*  §¶§å§ß§Ü§è§Ú§ñ §á§â§à§Ó§Ö§â§ñ§Ö§ä §Ö§ã§ä§î §Ý§Ú §ß§à§Ó§í§Ö §Õ§Ñ§ß§ß§í§Ö §Ó §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§Ö
*/
bool lib_can_check_new_data(const uint8_t MailboxId) 
{
	return MailBoxBuffer.is_new(MailboxId);
}

/*
*/
bool lib_can_set_new(const uint32_t id,const uint8_t extd, const uint8_t rtr, uint8_t * findMBIndex ) 
{	
	if (MailBoxBuffer.find_free(id, extd, rtr, *findMBIndex))
	{		
		SetFilter(*findMBIndex);		
		printf("id  =%x index=%x\r\n",id,*findMBIndex);
		return true;
	}
	return false;
}

/*
*
*/
void eMailboxFilterReset(const uint8_t MailboxId) 
{
    if ( MailBoxBuffer.resert(MailboxId) == true)
	{
		SetFilter(MailboxId );		
	}
	
}

/*
§°§ä§á§â§Ñ§Ó§Ü§Ñ §á§Ñ§Ü§Ö§ä§Ñ §Ó §ã§Ö§ä§î CAN. 
§¦§ã§Ý§Ú §ä§Ö§Ü§å§ë§Ú§Ö §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§í §ã§à§ß§ä§â§à§Ý§Ý§Ö§â§Ñ CAN §Ù§Ñ§ß§ñ§ä§í, §ä§à §á§Ñ§Ü§Ö§ä §â§Ñ§Ù§Þ§Ö§ë§Ñ§Ö§ä§ã§ñ §Ó §à§é§Ö§â§Ö§Õ§Ú §à§á§Ö§â§Ñ§è§Ú§à§ß§ß§à§Û §ã§Ú§ã§ä§Ö§Þ§í
*/
void lib_can_send_data(CAN_TX_FRAME_TYPE *buffer)
{
    if ( HAL_CANSend(buffer) == CAN_TxStatus_NoMailBox )
    {
		can_tx_buffer.send(&buffer,sizeof(CAN_TX_FRAME_TYPE), portMAX_DELAY);
    }
}

void vRestartNode( void )
{
    return;
}



/*
*/
uint8_t vGetNodeId( void )
{
  return ( OB->Data1 & 0xFF );
}
/*

*/
void vSetNodeID( uint8_t data)
{
    ProgramOptionByteData(1,data) ;
}
/*
*
*/
void ConfigNodeID( uint8_t node_id)
{
	if (vGetNodeId()!=node_id)
	{
		vSetNodeID(node_id);
	}
}
/*
*
*/
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
	//xTaskNotify(CanRXTaskHandle,0xFFFFFFFF,eSetValueWithOverwrite);
    HAL_CANIntIT(CANbitRate,CAN1_PRIOR,CAN1_SUBPRIOR);
	for (int i=0;i<MAILBOXSIZE;i++)
	{
		MailBoxBuffer.resert(i);
		if ((i%4) == 0 ) HAL_CANInitIDInactive(i/4, FILTER_FIFO_0);
       // HAL_CANResetFiltesr(i);
	}	
    return;
}