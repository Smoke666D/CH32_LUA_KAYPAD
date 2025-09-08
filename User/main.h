/*
 * main.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include "system_init.h"

#define __SECTION(x)

#define V1  1
#define V2  2
#define V3  4

#define DEBUG_PRINT

#define DMA1_CH5_PRIOR    0
#define DMA1_CH5_SUBPRIOR 2
//#define DMA1_CH1_ENABLE 0
//#define DMA1_CH2_ENABLE 0
//#define DMA1_CH3_ENABLE 0
//#define DMA1_CH4_ENABLE 0
#define DMA1_CH5_ENABLE 1
//#define DMA1_CH6_ENABLE 0
//#define DMA1_CH7_ENABLE 0


#define WDT_ENABLE

#define TIM3_UP_ENABLE
#define CAN_SFID_MASK                      ((uint32_t)0x000007FFU)      /*!< mask of standard identifier */

#define INIT_FUNC_LOC //__attribute__((section(".stext"))) __attribute__((optimize(3)))
#define LUA_FUNC_LOC  INIT_FUNC_LOC

#define WCH32V3   2
#define WCH32V2   1


#define TIMER3_PRIOR      1
#define TIMER3_SUBPRIOR   3
#define CAN1_PRIOR        1
#define CAN1_SUBPRIOR     0

#define CORE WCH32V3


#define USART1_IT_ENABLE

#endif /* USER_MAIN_H_ */
