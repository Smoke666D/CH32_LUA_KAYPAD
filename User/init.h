/*
 * init.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_INIT_H_
#define USER_INIT_H_

#include "main.h"
#include "hal_typedef.h"

#define USART_PRIOR     1
#define USART_SUB_PRIOR 2

#define CAN_RX_Pin                  GPIO_8
#define CAN_TX_Pin                  GPIO_9
#define CAN_Port                    PORT_B
#define RS_TX_Pin                   GPIO_10
#define RS_RX_Pin                   GPIO_Pin_11
#define RS_Port                     PORT_B


void InitDevice();

#endif /* USER_INIT_H_ */
