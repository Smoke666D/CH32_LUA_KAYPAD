#ifndef USER_IO_TASK_H_
#define USER_IO_TASK_H_

#include "main.h"

TaskHandle_t * xGetIOTaskHandle ();
void vIOTask(void *argument);
#endif