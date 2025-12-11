#include "os_core.h"


namespace os
{

buffer::buffer(uint8_t * _pMessageBufferStorage, const uint32_t _buffer_size)
{    
        xMessageBuffer = xMessageBufferCreateStatic(_buffer_size, _pMessageBufferStorage, &xMessageBufferStruct);
}

uint32_t buffer::isr_send(const void *_pvTxData, const uint32_t _xDataLengthBytes)
   {
        uint32_t sended_bytes;
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        sended_bytes = xMessageBufferSendFromISR( xMessageBuffer,
                                            _pvTxData,
                                            _xDataLengthBytes,
                                            &xHigherPriorityTaskWoken );
                                            
        portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
        return (sended_bytes);
   }
uint32_t buffer::recieve( void *_pvRxData, const uint32_t _xDataLengthBytes, const TickType_t _xTicksToWait )
{
    return xMessageBufferReceive( xMessageBuffer,
                                  _pvRxData,
                                  _xDataLengthBytes,
                                  _xTicksToWait );

}

uint32_t buffer::isr_recieve( void *_pvRxData, const uint32_t _xDataLengthBytes)
{
     uint32_t sended_bytes;
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        sended_bytes = xMessageBufferReceiveFromISR( xMessageBuffer,
                                            _pvRxData,
                                            _xDataLengthBytes,
                                            &xHigherPriorityTaskWoken );
                                            
        portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
        return (sended_bytes);

}

uint32_t buffer::send( const void *_pvTxData, const uint32_t _xDataLengthBytes, const TickType_t _xTicksToWait)
{
   return xMessageBufferSend( xMessageBuffer,
                                  _pvTxData,
                                  _xDataLengthBytes,
                                  _xTicksToWait );
}




   
mutex::mutex()
{
 _mutex= xSemaphoreCreateMutexStatic( &xMutexBuffer );
}

void mutex::give()
{
   xSemaphoreGive( _mutex );
}

bool mutex::take( uint32_t _time )
{
   return xSemaphoreTake( _mutex, _time);	

}

}