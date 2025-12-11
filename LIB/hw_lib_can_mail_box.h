#pragma once

#include "os_core.h"

typedef struct 
{   
	uint32_t ident;   
    uint8_t extd_id:1;
    uint8_t rtr:1;
	uint8_t filter_id;
    uint8_t enable:1;
	uint8_t new_data:1;
    uint8_t DLC:4;	
    uint8_t data[8];
    
} CANRX;

template <uint8_t _size> class can_lib_mail_box
{
  protected:
	os::mutex semaphore ={};
  	CANRX data[_size];
  	bool find( uint8_t &index,  CAN_FRAME_TYPE & _packet )
	{
		uint8_t _id = _packet.filter_id;
		// §±§â§à§Ó§Ö§â§ñ§Ö§Þ §é§ä§à §ã§à§Ó§á§Ñ§á§Ñ§Õ§Ñ§Ö§ä §Ý§Ú §Ú§ß§Õ§Ö§Ü§ã §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§Ñ §ã §æ§Ú§Ý§î§ä§â§à§Þ
		uint8_t _first_index, _last_index;
		if  (true
			  && _id < _size
			  && data[_id].ident == _packet.ident 
			  && data[_id].rtr	 == _packet.rtr	
		)
		{
			_first_index = _id;				
		}
		else 
		{
			_first_index = (_packet.extd) ? NORMAL_CAN_ID_FILTER_COUNT : 0;
		}
		_last_index  = (_packet.extd) ? MAILBOXSIZE : NORMAL_CAN_ID_FILTER_COUNT;
		
		// §±§â§à§Ó§Ö§â§ñ§Ö§Þ §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§í
		for (uint8_t k =  _first_index; k < _last_index; k++)
		{
			if  (true
				 && data[k].ident 	== _packet.ident 
				 && data[k].rtr 	== _packet.rtr
				 && data[k].enable	== 1
				)
			{
				index = k;
				return true;
			}
		}    	
		return false;
	}
  public:
	
	
	void  insert(CAN_FRAME_TYPE * RXPacket)
	{
		uint8_t mail_box_id;
       	if  ( find( mail_box_id, *RXPacket) )	
		{	
			semaphore.take();
			data[mail_box_id].DLC = RXPacket->DLC;
			memcpy(data[mail_box_id].data, RXPacket->data, RXPacket->DLC);								
			data[mail_box_id].new_data = 1;				
			semaphore.give();			
		}		
	}

	bool get_new(const  uint8_t _index, CAN_FRAME_TYPE & packet)
	{
		if (true 
			&& _index < _size
			&& data[_index].enable == 1
			&& data[_index].new_data == 1			
		)						
		{
			packet.ident	 = data[_index].ident;			
			semaphore.take();			
			packet.DLC = data[_index].DLC;
			data[_index].new_data = 0;						
			memcpy(packet.data, data[_index].data, packet.DLC);
			semaphore.give();			
			return true;
		}
		return false;
	}

	bool find_free(const uint32_t _id,const  uint8_t _extd, const uint8_t _rtr, uint8_t &_index )
	{		
		uint8_t first_index,last_index;
	
		first_index = (_extd)? NORMAL_CAN_ID_FILTER_COUNT : 0;
		last_index  = (_extd) ? MAILBOXSIZE : NORMAL_CAN_ID_FILTER_COUNT;

		for (auto i= first_index ; i <  last_index ; i++)  //§´§à §Ú§ë§Ö§Þ §ã§Ó§à§Ò§à§Õ§ß§í§Û §Ò§å§æ§æ§Ö§â §Ó §ã§ä§Ñ§â§ê§Ö§Û §á§à§Ý§à§Ó§Ú§ß§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ
		{
			if ( data[i].enable == 0 )
			{
				data[i].ident = _id;
				data[i].rtr = _rtr;
				data[i].enable = 1;
				data[i].new_data = 0;
				_index = i;
				return true;

			}
		}
		return false;
	}

	bool resert(const uint8_t _index)
	{
		if (true
	 		&& _index < _size 
			&& data[_index].enable == 1
		)
		{
			data[_index].enable = 0;
			data[_index].ident = 0;		
			return true;
		}
		return false;
	}
	 
	uint32_t get_id(const uint8_t _index)
	{		
		return (_index < _size ) ? data[_index].ident : 0;		
	}

	bool is_new(const uint8_t _index)
	{
		return (_index < _size
		       &&  data[_index].enable == 1
			   &&  data[_index].new_data == 1
			   );
	}
	
};