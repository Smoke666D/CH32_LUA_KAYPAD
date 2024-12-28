/*
 * main.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include "system_init.h"

#define CAN_SFID_MASK                      ((uint32_t)0x000007FFU)      /*!< mask of standard identifier */

#define INIT_FUNC_LOC //__attribute__((section(".stext")))

#define WCH32V3   2
#define WCH32V2   1

#define CORE WCH32V3

#define  TIM1_UP_ENABLE
#define USART3_IT_ENABLE

#endif /* USER_MAIN_H_ */
