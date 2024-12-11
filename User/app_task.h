/*
 * app_task.h
 *
 *  Created on: Dec 11, 2024
 *      Author: i.dymov
 */

#ifndef USER_APP_TASK_H_
#define USER_APP_TASK_H_

#include "main.h"
#include "system_init.h"

TaskHandle_t * xGetAppTaskHandle ();
void vAppTask( void * argument );
void vAppInit();
QueueHandle_t * xRXQueue( void );

#endif /* USER_APP_TASK_H_ */
