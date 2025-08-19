################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART/UART.c 

C_DEPS += \
./UART/UART.d 

OBJS += \
./UART/UART.o 


EXPANDS += \
./UART/UART.c.234r.expand 



# Each subdirectory must supply rules for building sources it contributes
UART/%.o: ../UART/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/HAL_DRIVER" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

