################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART/UART.c 

OBJS += \
./UART/UART.o 

C_DEPS += \
./UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
UART/%.o: ../UART/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\Core" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\User" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\USB_Device" -I"C:\MRS_DATA\workspace\CH32V3_CAN_HACKER\UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

