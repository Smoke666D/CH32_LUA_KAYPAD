################################################################################
# MRS Version: 1.9.2
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


# Each subdirectory must supply rules for building sources it contributes
Peripheral/HAL_LIB/%.o: ../Peripheral/HAL_LIB/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

