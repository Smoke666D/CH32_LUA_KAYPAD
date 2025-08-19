################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/EEPROM_25C.c \
../LIB/filters.c \
../LIB/hw_data_model.c \
../LIB/hw_lib_adc.c \
../LIB/hw_lib_can.c \
../LIB/hw_lib_din.c \
../LIB/hw_lib_eeprom_i2c.c \
../LIB/hw_lib_keyboard.c \
../LIB/hw_timeout.c 

OBJS += \
./LIB/EEPROM_25C.o \
./LIB/filters.o \
./LIB/hw_data_model.o \
./LIB/hw_lib_adc.o \
./LIB/hw_lib_can.o \
./LIB/hw_lib_din.o \
./LIB/hw_lib_eeprom_i2c.o \
./LIB/hw_lib_keyboard.o \
./LIB/hw_timeout.o 

C_DEPS += \
./LIB/EEPROM_25C.d \
./LIB/filters.d \
./LIB/hw_data_model.d \
./LIB/hw_lib_adc.d \
./LIB/hw_lib_can.d \
./LIB/hw_lib_din.d \
./LIB/hw_lib_eeprom_i2c.d \
./LIB/hw_lib_keyboard.d \
./LIB/hw_timeout.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/%.o: ../LIB/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

