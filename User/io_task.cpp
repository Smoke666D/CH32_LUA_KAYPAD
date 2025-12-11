#include "io_task.h"
#include "os_core.h"
#include "hal_gpio.h"
#include "hw_lib_cpp_keyboard.h"
#include "init.h"

static PortName_t      port[KEY_COUNT] = { 
										   KL1_Port, 
										   KL2_8_Port,
										   KL2_8_Port,
										   KL2_8_Port,
										   KL2_8_Port,
										   KL2_8_Port,
										   KL2_8_Port,
										   KL2_8_Port
										  };	

static const uint16_t   pin[KEY_COUNT] = { 
										   KL1Pin,
										   KL2Pin,
										   KL3Pin,
										   KL4Pin,
										   KL5Pin,
										   KL6Pin,
										   KL7Pin,
										   KL8Pin
										   };

static BitState_t fPortState (uint8_t i)
{
	return HAL_GetBit(port[i], pin[i]);    
}

static cpp_keyboard<KEY_COUNT> keyboard = {&fPortState, 30 , 40, 20};


class cpp_IO_task : os::os_task<cpp_IO_task, IO_STK_SIZE>
{
 public:
    void run(void )  __attribute__((__noreturn__)) ;    
    using os_task::os_task;
};

cpp_IO_task IO_task ={"IO_Task",IO_TASK_PRIO};


static uint8_t data;

uint8_t getKeyData()
{
    return data;
}

void  cpp_IO_task::run(void )
{  
   uint8_t _key_mask[] = {kl1_key,kl2_key,kl3_key,kl4_key,kl5_key,kl6_key,kl7_key,kl8_key};
   _keybard_evet event;
   while(1)
   {
   		sleep(1); 
		keyboard.run(1);
        if ( keyboard.get(&event) )
		{			
			uint8_t key_mask = _key_mask[event.key_index] ;			
			if (event.Status == key_code_make)
			{
				data |= key_mask;
			}
			else
			{
				data &= ~key_mask;
			}
        }
	}
}