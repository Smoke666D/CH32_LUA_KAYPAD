#ifndef USER_IO_TASK_H_
#define USER_IO_TASK_H_

#include "main.h"

#define KEY_COUNT           8

#define kl1_key            0x00U
#define kl2_key            0x01U
#define kl3_key            0x02U
#define kl4_key            0x03U
#define kl5_key            0x04U
#define kl6_key            0x05U
#define kl7_key            0x06U
#define kl8_key            0x07U

#ifdef __cplusplus
 extern "C" {
#endif 

uint8_t getKeyData();

#ifdef __cplusplus
}
#endif


#endif