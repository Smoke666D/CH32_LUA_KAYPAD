################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app_task.c \
../User/ch32v30x_it.c \
../User/init.c \
../User/main.c \
../User/system_ch32v30x.c \
../User/system_init.c 

C_DEPS += \
./User/app_task.d \
./User/ch32v30x_it.d \
./User/init.d \
./User/main.d \
./User/system_ch32v30x.d \
./User/system_init.d 

OBJS += \
./User/app_task.o \
./User/ch32v30x_it.o \
./User/init.o \
./User/main.o \
./User/system_ch32v30x.o \
./User/system_init.o 


EXPANDS += \
./User/app_task.c.234r.expand \
./User/ch32v30x_it.c.234r.expand \
./User/init.c.234r.expand \
./User/main.c.234r.expand \
./User/system_ch32v30x.c.234r.expand \
./User/system_init.c.234r.expand 



# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

