################################################################################
# MRS Version: 2.3.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/EEPROM_25C.c \
../LIB/filters.c \
../LIB/hw_data_model.c \
../LIB/hw_lib_adc.c \
../LIB/hw_lib_din.c \
../LIB/hw_lib_eeprom_i2c.c \
../LIB/hw_timeout.c 

C_DEPS += \
./LIB/EEPROM_25C.d \
./LIB/filters.d \
./LIB/hw_data_model.d \
./LIB/hw_lib_adc.d \
./LIB/hw_lib_din.d \
./LIB/hw_lib_eeprom_i2c.d \
./LIB/hw_timeout.d 

CPP_SRCS += \
../LIB/hw_lib_can.cpp \
../LIB/hw_lib_keyboard.cpp 

CPP_DEPS += \
./LIB/hw_lib_can.d \
./LIB/hw_lib_keyboard.d 

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

DIR_OBJS += \
./LIB/*.o \

DIR_DEPS += \
./LIB/*.d \

DIR_EXPANDS += \
./LIB/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
LIB/%.o: ../LIB/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Debug" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Core" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/User" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Peripheral/inc" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/include" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/Common" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

LIB/%.o: ../LIB/%.cpp
	@	riscv-none-embed-g++ -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

