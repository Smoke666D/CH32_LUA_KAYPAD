################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/HAL_LIB/EEPROM_25C.c \
../Peripheral/HAL_LIB/filters.c \
../Peripheral/HAL_LIB/hw_data_model.c \
../Peripheral/HAL_LIB/hw_lib_adc.c \
../Peripheral/HAL_LIB/hw_lib_can.c \
../Peripheral/HAL_LIB/hw_lib_din.c \
../Peripheral/HAL_LIB/hw_lib_eeprom_i2c.c \
../Peripheral/HAL_LIB/hw_lib_keyboard.c \
../Peripheral/HAL_LIB/hw_timeout.c 

C_DEPS += \
./Peripheral/HAL_LIB/EEPROM_25C.d \
./Peripheral/HAL_LIB/filters.d \
./Peripheral/HAL_LIB/hw_data_model.d \
./Peripheral/HAL_LIB/hw_lib_adc.d \
./Peripheral/HAL_LIB/hw_lib_can.d \
./Peripheral/HAL_LIB/hw_lib_din.d \
./Peripheral/HAL_LIB/hw_lib_eeprom_i2c.d \
./Peripheral/HAL_LIB/hw_lib_keyboard.d \
./Peripheral/HAL_LIB/hw_timeout.d 

OBJS += \
./Peripheral/HAL_LIB/EEPROM_25C.o \
./Peripheral/HAL_LIB/filters.o \
./Peripheral/HAL_LIB/hw_data_model.o \
./Peripheral/HAL_LIB/hw_lib_adc.o \
./Peripheral/HAL_LIB/hw_lib_can.o \
./Peripheral/HAL_LIB/hw_lib_din.o \
./Peripheral/HAL_LIB/hw_lib_eeprom_i2c.o \
./Peripheral/HAL_LIB/hw_lib_keyboard.o \
./Peripheral/HAL_LIB/hw_timeout.o 



# Each subdirectory must supply rules for building sources it contributes
Peripheral/HAL_LIB/%.o: ../Peripheral/HAL_LIB/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
