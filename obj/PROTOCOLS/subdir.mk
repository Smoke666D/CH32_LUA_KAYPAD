################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS/xmodem.c 

C_DEPS += \
./PROTOCOLS/xmodem.d 

OBJS += \
./PROTOCOLS/xmodem.o 



# Each subdirectory must supply rules for building sources it contributes
PROTOCOLS/xmodem.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS/xmodem.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V_LUA/USB_Device" -I"c:/MRS_DATA/workspace/CH32V_LUA/UART" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

