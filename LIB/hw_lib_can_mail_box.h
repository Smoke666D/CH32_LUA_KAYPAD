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


#define MAX_TIME_STAMP 0xFF

typedef struct
{             
    uint8_t dlc:4;    
    bool is_free;
    uint8_t time_stamp;
    uint8_t data[8];
} can_data_buffer;

typedef struct
{
    uint32_t ident;   
    uint8_t extd_id:1;
    uint8_t rtr:1;
    uint8_t enable:1;
	uint8_t new_data:1;
    uint8_t data_buffer_id;

} can_filter_descr;


template < uint8_t count> class can_lib_data_buffer_mng
{
protected:
    can_data_buffer data[count];    
    uint8_t cur_data_count;

    void restamp( uint8_t i)
    {       
       for (auto _i =0 ; _i < count; i++ )
       {
            if (true
                && _i!= i
                && data[_i].time_stamp > data[i].time_stamp)
            {
                data[_i].time_stamp--;
            }
       }
       data[i].time_stamp = cur_data_count;
    }

    void add_stamp(uint8_t i)
    {

        if (cur_data_count < count-1)
        {
            cur_data_count++;
            data[i].time_stamp = cur_data_count;
        }
        else 
        {
            restamp(i);
        }
    }

public:
    can_lib_data_buffer_mng():    
    cur_data_count(0)
    {
        for (auto i = 0; i < count; i++)
        {
            data[i].is_free = true;
            data[i].time_stamp = 0;
        }
    }


    uint8_t add( CAN_FRAME_TYPE  &item)
    {
        uint8_t i;
        for (i = 0; i < count; i++)
        {
            if (data[i].is_free)                                
            {
                break;   
            }
            else if (i == (count-1) )
            {                
                for (i = 1; i < count && data[0].time_stamp == 0; i++);                
            }
        }

        data[i].dlc = item.DLC;
        memcpy(data[i].data,item.data,item.DLC);
        data[i].is_free = false;
        add_stamp(i);               
        return i;
    }
    bool get(  uint8_t index, CAN_FRAME_TYPE &item)
    {

    }


    bool set(uint8_t _index, CAN_FRAME_TYPE & _packet )
    {
        if (_index < count)
        {
            data[_index].dlc = _packet.DLC;
            memcpy(data[_index].data, _packet.data, _packet.DLC);         
            restamp(_index);
        }

    }
               
};

template <uint8_t _can_count, uint8_t _max_filter_count> class can_lib_mail_box 
{
  protected:
    static constexpr uint8_t std_filter_max_count = _max_filter_count/_can_count * 4;
    static constexpr uint8_t ext_filter_max_count = _max_filter_count/_can_count * 2;
    static constexpr uint8_t _size = (_max_filter_count/_can_count)*6;
    static constexpr uint8_t max_buffer_data_size = 8;
	os::mutex semaphore;

    can_lib_data_buffer_mng<max_buffer_data_size>  data_buffer;
    can_filter_descr can_discriptor[_size];
    uint8_t std_id_ptr;
    uint8_t extd_id_ptr;

  	bool desc_find( uint8_t &index,  CAN_FRAME_TYPE & _packet )
    {


    }


  	bool find( uint8_t &index,  CAN_FRAME_TYPE & _packet )
	{
		uint8_t _id = _packet.filter_id;
		// §±§â§à§Ó§Ö§â§ñ§Ö§Þ §é§ä§à §ã§à§Ó§á§Ñ§á§Ñ§Õ§Ñ§Ö§ä §Ý§Ú §Ú§ß§Õ§Ö§Ü§ã §Þ§Ñ§Û§Ý§Ò§à§Ü§ã§Ñ §ã §æ§Ú§Ý§î§ä§â§à§Þ
		uint8_t _first_index, _last_index;
		if  (true
			  && _id < _size
			  && can_discriptor[_id].ident == _packet.ident 
			  && can_discriptor[_id].rtr	 == _packet.rtr	
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
				 && can_discriptor[k].ident 	== _packet.ident 
				 && can_discriptor[k].rtr 	== _packet.rtr
				 && can_discriptor[k].enable	== 1
				)
			{
				index = k;
				return true;
			}
		}    	
		return false;
	}
  public:
    can_lib_mail_box():
    data_buffer(),
    semaphore(),
    std_id_ptr(0),
    extd_id_ptr(0)
    {
        for( auto i = 0; i<_size; i++)
        {
            can_discriptor[i].new_data = 0;
            can_discriptor[i].enable = 0;
        }
    }

	bool insert( CAN_FRAME_TYPE & _packet)
    {
        uint8_t desc_ptr = 0;
        // §±§à§Ý§å§é§Ñ§Ö§Þ §Ú§ß§Õ§Ö§Ü§ã §Õ§Ú§ã§Ü§â§Ú§á§ä§à§â§Ñ
        if (desc_find( desc_ptr, _packet))
        {
            semaphore.take();
            // §£ §Ò§å§æ§Ö§â§Ö §å§Ø§Ö §Ö§ã§ä§î §Õ§Ñ§ß§ß§í§Ö §Õ§Ý§ñ §ï§ä§à§Ô§à §Õ§Ú§Ü§ã§â§Ú§á§ä§à§â§Ñ, §ß§Ñ§Õ§à §á§Ö§â§Ö§Ù§Ñ§á§ã§Ñ§ä§î
            if (can_discriptor[desc_ptr].new_data == 1)
            {
                data_buffer.set(can_discriptor[desc_ptr].data_buffer_id, _packet);
            }
            else 
            {
                // §¥§à§Ò§Ñ§Ó§Ý§ñ§Ö§Þ §Õ§Ñ§ß§ß§í§Ö §Õ§Ý§ñ §Õ§Ú§ã§Ü§â§Ú§á§ä§à§â§Ñ §Ó §Ò§å§æ§æ§Ö§â
                can_discriptor[desc_ptr].data_buffer_id = data_buffer.add(_packet);
                can_discriptor[desc_ptr].new_data = 1;
            }
            semaphore.give();

            return true;
        }
        else 
        {
            // §¥§Ú§ã§Ü§â§Ú§á§ä§à§â §ß§Ö §ß§Ñ§Û§Õ§Ö§â
            return false;
        }
    }
	
	bool get_new(const  uint8_t _index, CAN_FRAME_TYPE & packet)
	{
		if (true 
			&& _index < _size
			&& can_discriptor[_index].enable == 1
			&& can_discriptor[_index].new_data == 1			
		)						
		{  
            semaphore.take();			

            // §±§à§Ý§å§é§Ñ§Ö§Þ §Õ§Ñ§ß§ß§í§Ö §á§Ñ§Ü§Ö§ä§Ñ §Ú§Ù §Ò§å§æ§æ§Ö§â§Ñ
            data_buffer.get(can_discriptor[_index].data_buffer_id, packet);            
			
            // §¬§à§á§Ú§â§å§Ö§Þ §Õ§Ñ§ß§ß§í§Ö §Ú§Ù §Õ§Ú§ã§Ü§â§Ú§á§ä§à§â§Ñ
            packet.ident = can_discriptor[_index].ident;
            packet.rtr = can_discriptor[_index].rtr;
            packet.extd = can_discriptor[_index].extd_id;

            // §³§Ò§â§Ñ§ã§í§Ó§Ñ§Ö§Þ §ä§Ö§Ô, §å§Ó§Ö§Õ§à§Þ§Ý§ñ§ñ §ã§Ú§ã§Ö§ä§Þ§å §é§ä§à §Þ§í §Ù§Ñ§Ò§â§Ñ§Ý§Ú §Õ§Ñ§ß§ß§í§Ö
            can_discriptor[_index].new_data = 0;            

			semaphore.give();			
			return true;
		}
		return false;
	}

    bool is_new(const uint8_t _index)
	{
		return (_index < _size
		       &&  can_discriptor[_index].enable == 1
			   &&  can_discriptor[_index].new_data == 1
			   );
	}

	bool find_free(const uint32_t _id,const  uint8_t _extd, const uint8_t _rtr, uint8_t &_index )
	{		
		uint8_t i;
        bool disc_is_find = false;
        if (_extd)
        {
            for ( i = _size; i > 0; i--)
            {
                if (true
                    && can_discriptor[i].enable == 0 
                    && i > std_id_ptr
                )
			    {
                    can_discriptor[i].extd_id = 1;
                    extd_id_ptr++;
                    disc_is_find = true;
                    break;	
    			}
            }
        }
        else 
        {
            for ( i= 0 ; i <  _size ; i++)  //§´§à §Ú§ë§Ö§Þ §ã§Ó§à§Ò§à§Õ§ß§í§Û §Ò§å§æ§æ§Ö§â §Ó §ã§ä§Ñ§â§ê§Ö§Û §á§à§Ý§à§Ó§Ú§ß§Ö §Þ§Ñ§ã§ã§Ú§Ó§Ñ
		    {
			    if (true
                    && can_discriptor[i].enable == 0 
                    && (i < (_size - extd_id_ptr))
                )
			    {
                    can_discriptor[i].extd_id = 0;
                    std_id_ptr++;
                    disc_is_find = true;
                    break;				    				    
			    }		    
            }
        }
        if ( disc_is_find )
        {
            can_discriptor[i].ident = _id;
			can_discriptor[i].rtr = _rtr;
		    can_discriptor[i].enable = 1;
			can_discriptor[i].new_data = 0;
            _index = i;
            return true;
        }   
		return false;
	}

	bool resert(const uint8_t _index)
	{
		if (true
	 		&& _index < _size 
			&& can_discriptor[_index].enable == 1
		)
		{
			can_discriptor[_index].enable = 0;		
			return true;
		}
		return false;
	}
	 
	uint32_t get_id(const uint8_t _index)
	{		
		return (_index < _size ) ? can_discriptor[_index].ident : 0;		
	}

	
	
};