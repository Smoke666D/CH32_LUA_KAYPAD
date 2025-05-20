/*
 * main.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include "system_init.h"

#define VM_HEAP_SIZE 10000


#define ADC_1_ENABLE  1
#define AC_CONVERION_NUMBER 100
#define ADC1_CH_COUNT 2
#define ADC_CHANNEL  (6)
#define ADC1_PRIOR      1
#define ADC1_SUB_PRIOR  2


#define CAN_SFID_MASK                      ((uint32_t)0x000007FFU)      /*!< mask of standard identifier */

#define INIT_FUNC_LOC //__attribute__((section(".stext"))) __attribute__((optimize(3)))
#define LUA_FUNC_LOC  INIT_FUNC_LOC

#define WCH32V3   2
#define WCH32V2   1

#define CAN1_PRIOR        1
#define CAN1_SUBPRIOR     0

#define CORE WCH32V3

#define  TIM1_UP_ENABLE
#define USART1_IT_ENABLE

#endif /* USER_MAIN_H_ */
