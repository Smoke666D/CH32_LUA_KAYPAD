#include "io_task.h"
#include "hal_dma.h"
#include "string.h"

static TaskHandle_t  IOTaskHandle;
static int16_t  ADC1_DMABuffer[AC_CONVERION_NUMBER*ADC_CHANNEL];

TaskHandle_t * xGetIOTaskHandle ()
{
    return  &IOTaskHandle ;
}

void ADC1_Event( void )
{
 //   HAL_TiemrDisable(TIMER2);
    HAL_DMA_Disable(DMA1_CH1);

   // ADC_EXT_TRIG_DISABLE (ADC_1);

    //HW_TIMER_SelectOutTrigger(TIMER3,TIM_TRGOSource_OC4Ref);


   // FindMax();
    HAL_DMA_SetCounter(DMA1_CH1, AC_CONVERION_NUMBER*3);
    HAL_DMA_Enable(DMA1_CH1);
   // HAL_TiemrEneblae(TIMER2);
    //HW_TIMER_SelectOutTrigger(TIMER3,TIM_TRGOSource_Update);
   // ADC_EXT_TRIG_ENABLE (ADC_1);
    static portBASE_TYPE xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    //xTaskNotifyFromISR(pAdcTaskHandle,  ADC1_DATA_READY, eSetBits, &xHigherPriorityTaskWoken  );
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}


void vIOTask(void *argument)
{
	DMA_INIT_t init;
    init.stream = DMA1_CH1;
    init.direction = PTOM;
    init.mode  = DMA_Circular;
    init.paddr = (u32)&ADC1->RDATAR;
    init.memadr = (u32)ADC1_DMABuffer;
    init.dma_size = DMA_HWORD;
    init.bufsize = AC_CONVERION_NUMBER*3;
    init.prioroty = dma_VeryHigh;
    HAL_DMAInitIT(init,  ADC1_PRIOR , ADC1_SUB_PRIOR, &ADC1_Event  );
    HAL_DMA_Enable(DMA1_CH1);
    memset(ADC1_DMABuffer,0,AC_CONVERION_NUMBER*3);
	while(1)
	{  
		vTaskDelay(1); 
	}
}