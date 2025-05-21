#include "led_task.h"
#include "hal_dma.h"
#include "hal_spi.h"
#include "init.h"
#include "string.h"
#include "hal_gpio.h"
#include "hal_timers.h"


static uint8_t  LED_ON[SPI_PACKET_SIZE] 		=         { 0x00 , 0x00 , 0x00 };
static uint8_t  LED_BLINK[SPI_PACKET_SIZE]    	=         { 0x00 , 0x00 , 0x00 };
static uint16_t backligch_brigth		        = 0x1F;
static uint16_t led_brigth 				        = 0x3F;
static uint8_t  color_div 				        = 1U;
static uint8_t  brigth_color[SPI_PACKET_SIZE];
static uint16_t led_brigth_counter 		        = 0;
static uint16_t led_blink_counter 		        = 0;
static uint8_t  BlinkON					        = 1;
static uint8_t  data[SPI_PACKET_SIZE];

void LC()
{
   HAL_DMA_Disable(DMA1_CH5);
   HAL_SPI_RXOveleyClear(HAL_SPI2 );
   while (HAL_SPI_GetBusy(HAL_SPI2) == HAL_SET);
   HAL_SetBit(CS_Port, CSPin);
}

/*
 *
 */
static uint16_t calcBrigt(uint8_t pbr)
{
  return ( ( pbr > MAX_BRIGTH )?  MAX_BRIGTH_COUNTER :  (uint16_t) ( sin((double)pbr*(3.14/2.0)/MAX_BRIGTH )*(MAX_BRIGTH_COUNTER) ) );
}
/*
 *
 */

/*
 *
 */
INIT_FUNC_LOC void vLedDriverStart(void)
{

   DMA_INIT_t init;
    init.stream = DMA1_CH5;
    init.direction = MTOP;
    init.mode  = DMA_Mode_Normal;
    init.paddr = (u32)&SPI2->DATAR;
    init.memadr = (u32)data;
    init.dma_size = DMA_HWORD;
    init.bufsize = SPI_PACKET_SIZE;
    init.prioroty = dma_VeryHigh;
    HAL_DMAInitIT(init, DMA1_CH5_PRIOR  , DMA1_CH5_SUBPRIOR , &LC  );
    HAL_TiemrEneblae(TIMER3);
    HAL_TiemrEneblae(TIMER2);
    return;
}
/*
 * §¶§å§ß§Ü§è§Ú§ñ §Ó§Ü§Ý§ð§é§Ö§ß§Ú§ñ §ã§Ó§Ö§ä§à§Õ§Ú§à§Õ§à§í.
 * §¬§à§â§â§Ö§Ü§ä§ß§à§ã§ä§î §Ñ§â§Ô§å§Þ§Ö§ß§ä§à§Ó §á§â§à§Ó§Ö§â§ñ§ä§ã§ñ §á§â§Ú §Ó§í§Ù§à§Ó§Ö
 */
void vSetLedOn(uint8_t Color,uint8_t State)
{
	LED_ON[Color-1] = State;
	return;
}

uint8_t uGetLedState( uint8_t Color )
{
    return (LED_ON[Color-1]);
}



/*
 *
 */
void vSetLedBrigth(uint8_t brigth)
{
	led_brigth = calcBrigt(brigth);
	return;
}

void vSetBackLigthColor(uint8_t color)
{
	brigth_color[0]=MAX_DATA;
	brigth_color[1]=MAX_DATA;
	brigth_color[2]=MAX_DATA;
	color_div =2;
	switch (color)
	{
		case  RED:
			brigth_color[1]=0x00;
			brigth_color[2]=0x00;
			color_div =1;
			break;
		case GREEN:
			brigth_color[0]=0x00;
			brigth_color[2]=0x00;
			color_div =1;
			break;
		case BLUE:
			brigth_color[0]=0x00;
			brigth_color[1]=0x00;
			color_div =1;
			break;
		case YELLOW:
			brigth_color[2]=0x00;
			break;
		case YELLOW_GREEN:
			brigth_color[2]=0x00;
			break;
		case  AMBER:
			brigth_color[2]=0x00;
			break;
		case VIOLET:
			brigth_color[1]=0x00;
			break;
		case CYAN:
			brigth_color[0]=0x00;
			break;
		case WHITE:
		default:
			break;
	}
	return;
}
/*
 *
 */
void vSetBackLigth(uint8_t brigth)
{
	backligch_brigth =calcBrigt( brigth);
}
void vSetBrigth(uint8_t brigth)
{
	if (brigth <= MAX_BRIGTH)
	{
	    /*
	         * §Á§â§Ü§à§ã§ä§î §å§ã§ä§Ñ§ß§Ó§Ý  §Ú§Ó§Ñ§Ö§ä§ã§ñ §Õ§Ý§ñ §Ü§Ñ§Ø§Õ§à§Ô§à §è§Ó§Ö§ä§Ñ §à§ä§Õ§Ö§Ý§î§ß§à. §£§à§Ù§Þ§à§Ø§ß§à §Ù§Ñ§Õ§Ñ§Ó§Ñ§ä§î §Ú§ß§Õ§Ú§Ó§Ú§Õ§å§Ñ§Ý§ß§à§Ö §ã§à§à§ä§ß§à§ê§Ö§ß§Ú§Ö §ñ§â§Ü§à§ã§ä§Ö§Û §è§Ó§Ö§ä§à§Ó §Õ§Ý§ñ §á§à§Ý§å§é§Ö§ß§Ú§ñ
	           * §Õ§à§á§à§Ý§ß§Ú§ä§Ö§Ý§î§ß§í§ç §á§Ö§â§Ö§ç§à§Õ§ß§í§ç §è§Ó§Ö§ä§à§Ó, §ß§Ñ§á§â§Ú§Þ§Ö§â  AMBER §Ú YELLOW_GREEN
	    */
	    uint16_t pulse;
	    pulse =  (uint16_t)( ( (float)(brigth)/MAX_BRIGTH )* PWM_TIM_PERIOD )+1;
	    HAL_TIMER_SetPWMPulse(TIMER2, TIM_CHANNEL_1 | TIM_CHANNEL_2 | TIM_CHANNEL_3 ,pulse);
	    HAL_TIMER_EnablePWMCH(TIMER2);
	}
}
/*
 *  §¶§å§ß§Ü§è§Ú§ñ §Ó§í§Ó§à§Õ§Ñ §Õ§Ñ§ß§ß§í§ç §Ó SPI, §Ó§í§Ù§í§Ó§Ñ§Ö§ä§ã§ñ §á§à §á§â§Ö§â§í§Ó§Ñ§ß§Ú§ð §ä§Ñ§Û§Þ§â§Ñ ¡í4
 */
void vLedProcess( void )
{
	/*C§Ò§â§Ñ§Ó§í§ã§Ó§Ñ§Ö§Þ §æ§Ý§Ñ§Ô §ä§Ñ§Þ§Ö§â§Ñ 4*/
	uint8_t temp_led;
    if (++led_brigth_counter>(MAX_BRIGTH_COUNTER))
    {
    	led_brigth_counter = 0;
    }
    memset(data,0, SPI_PACKET_SIZE );
    temp_led = ~(LED_ON[0]  | LED_ON[1] | LED_ON[2] );
	if (led_brigth_counter < backligch_brigth)
	{
		 data[2]=brigth_color[0] & temp_led;
	 	 data[1]=brigth_color[1] & temp_led;
	 	 data[0]=brigth_color[2] & temp_led;
 	}
	if (led_brigth_counter < led_brigth)
	{
		data[2]|=LED_ON[0];
	 	data[1]|=LED_ON[1];
	 	data[0]|=LED_ON[2];
    }
	HAL_ResetBit(CS_Port, CSPin);
	HAL_DMA_SetCouterAndEnable(DMA1_CH5, SPI_PACKET_SIZE );
    return;
}

void TimersCallback()
{
    vLedProcess();
}