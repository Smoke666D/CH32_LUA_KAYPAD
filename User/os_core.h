#ifndef __os_core 
#define __os_core


#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "message_buffer.h"

namespace os
{


template <class _T>  void (*mem_func(   void(_T::*_member)(void )))(void *)
{
    const union
    {
        void(_T::*member)(void);
        void(*func)(void *);
    } &ptr = {.member = _member};
    return ptr.func;
} 

template <typename T, int _stack_size> class os_task 
{
    private:    
     TaskHandle_t xHandle = NULL;         
     StackType_t xStack[ _stack_size ];  
     StaticTask_t xTaskBuffer; 
    public:
    void suspend()
    {
        vTaskSuspend(xHandle);
    }
    /*void resume()
    {
        if (os::context_get() == context::task)
        {
            vTaskResume(xHandle);
        }
        else 
        {
            BaseType_t xYieldRequired;
            xYieldRequired = xTaskResumeFromISR( xHandle );
            portYIELD_FROM_ISR( xYieldRequired );
        }
    }*/
    static void sleep(const uint32_t tick)
    {
        vTaskDelay(tick);  
    }
    void sleep_until( const uint32_t tick)
    {

    }
    void task_run( void )
    {

    }
   


    os_task( const char* _name, const UBaseType_t uxPriority)
    {                       
        xHandle = xTaskCreateStatic(mem_func(&T::run), _name, 
                                    _stack_size, (void *)1, uxPriority, 
                                    (StackType_t * const )xStack,&xTaskBuffer);                                        
    }
        
};

class buffer 
{
protected:
   MessageBufferHandle_t xMessageBuffer;
   StaticMessageBuffer_t xMessageBufferStruct;
public:   
   buffer(uint8_t * _pMessageBufferStorage, const uint32_t _buffer_size);
   uint32_t isr_send(const void *_pvTxData, const uint32_t _xDataLengthBytes);
   uint32_t recieve( void *_pvRxData, const uint32_t _xDataLengthBytes, const TickType_t _xTicksToWait);


};

template <typename T, int _buffer_size> class os_message_buffer : public buffer
{
protected:
    uint8_t ucMessageBufferStorage[_buffer_size];
public:
    using buffer::recieve;    
    os_message_buffer(): buffer(ucMessageBufferStorage, sizeof(ucMessageBufferStorage))
    {
    }
};

}

#endif