################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v30x_it.c \
../User/init.c \
../User/lua_task.c \
../User/main.c \
../User/system_ch32v30x.c \
../User/system_init.c 

C_DEPS += \
./User/ch32v30x_it.d \
./User/init.d \
./User/lua_task.d \
./User/main.d \
./User/system_ch32v30x.d \
./User/system_init.d 

OBJS += \
./User/ch32v30x_it.o \
./User/init.o \
./User/lua_task.o \
./User/main.o \
./User/system_ch32v30x.o \
./User/system_init.o 



# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
