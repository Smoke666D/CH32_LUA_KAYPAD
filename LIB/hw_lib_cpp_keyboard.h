#pragma once

#include "os_core.h"

/****************************************DEFINES******************************************************************/

#define KEY_ON_STATE       ( HAL_BIT_RESET  )
#define KEY_OFF_STATE      ( HAL_BIT_SET )


/****************************************TYPES******************************************************************/

typedef enum: uint8_t
{
  key_code_brake = 0,
  key_code_make,
  key_code_time_out,
} key_event;

typedef enum: uint8_t
{
  key_code_off = 0,
  key_code_on,
  key_code_repeat,  
} key_status;

typedef struct
{
  uint8_t   key_index;
  key_event  Status;
} _keybard_evet;

template <uint8_t _size> class cpp_keyboard
{
protected:   
    uint16_t timeout;
    uint8_t keydown_delay;
    uint8_t repeat_time;
    uint8_t keydown_hold_time;
    BitState_t (*getPortCallback)(uint8_t); 
    key_status status [_size];
    uint8_t timer[_size];         
    u32 delay_timeout = 0;
    class cpp_can_rx_buffer : public os::os_message_buffer<cpp_can_rx_buffer,  CANRX_QUEUE_SIZE * sizeof( _keybard_evet )> {}
    key_buffer = {};

public:
    cpp_keyboard(BitState_t(*_getPortCallback)(uint8_t),                             
                            uint8_t _repeat_time,
                            uint8_t _keydown_hold_time,
                            uint8_t _keydown_delay,
                            uint16_t _timeout = 0) :
    timeout(_timeout),
    keydown_delay(_keydown_delay),    
    getPortCallback(_getPortCallback),       
    keydown_hold_time(_keydown_hold_time),
    repeat_time(_repeat_time)        
    {}  
    void init(BitState_t (*_getPortCallback)(uint8_t),
                             
              uint8_t _repeat_time,
              uint8_t _keydown_hold_time,
              uint8_t _keydown_delay,
               uint16_t _timeout = 0)
    {
        getPortCallback =_getPortCallback;
        keydown_delay = _keydown_delay;
        keydown_hold_time = _keydown_hold_time;
        repeat_time = _repeat_time;    
        timeout = _timeout;
    }

    bool get( _keybard_evet * event)      
    {
        return (key_buffer.recieve(event,sizeof(_keybard_evet),0) !=0 ) ? true :false;
    }

    void post( uint8_t key, key_event state)
    {
        _keybard_evet  TEvent;
        TEvent.key_index = key;
        TEvent.Status  = state;
        timer[key]    = 0U;
        key_buffer.send(&TEvent,sizeof(_keybard_evet), portMAX_DELAY);
        if ( state == key_code_make ) delay_timeout = 0;
    }


   void run(uint32_t time)
   {
        for (auto i = 0U; i < _size; i++ )                                          /* §²?§³?§²§×§³?§³?§²?§²¡ã§²?§²? §³?§²?§²?§³?§³¡ë§²?§²? §³?§²?§³?§³?§²?§³?§²?§²§×§²? §²?§²?§³?§³?§²?§²? §²?§²?§²¡ã§²?§²§×§²¡ã§³?§³?§³?§³? */
        {
           if (getPortCallback(i) == KEY_OFF_STATE  )
           {
               if (status[i] != key_code_off)
               {
                   status[i] = key_code_off; /*§²?§²?§³?§³?§²?§³?§²?§²§×§²§× §²?§²?§²¡ã§²?§²§×§³€§²§× §²¡¯§²?§²?§²?*/
                   post(i, key_code_brake);
               }
           }
           else
           {
              timer[i] += time;
              if ( status[i] == key_code_off )
              {
                     if ( timer[i] >= keydown_delay )
                     {
                        status[i] = key_code_on;
                        post( i , key_code_make);
                     }
               }
               else
               {
                   if (false 
                       || (true 
                            && timer[i] >=  keydown_hold_time 
                            && status[i]== key_code_on
                            )
                        || (true
                            &&  timer[i] >= repeat_time    
                            && status[i]== key_code_repeat 
                        )     
                    )
                    {
                        status[i] = key_code_repeat;
                        post( i , key_code_make);
                    }
               }
            }
         }
        if (timeout)
        {
            if  (++delay_timeout  > timeout)
            {
                delay_timeout = 0;
                post(0 , key_code_time_out);
            }
        }
   }
};