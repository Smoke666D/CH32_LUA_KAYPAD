################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/croutine.c \
../FreeRTOS/event_groups.c \
../FreeRTOS/list.c \
../FreeRTOS/queue.c \
../FreeRTOS/stream_buffer.c \
../FreeRTOS/tasks.c \
../FreeRTOS/timers.c 

C_DEPS += \
./FreeRTOS/croutine.d \
./FreeRTOS/event_groups.d \
./FreeRTOS/list.d \
./FreeRTOS/queue.d \
./FreeRTOS/stream_buffer.d \
./FreeRTOS/tasks.d \
./FreeRTOS/timers.d 

OBJS += \
./FreeRTOS/croutine.o \
./FreeRTOS/event_groups.o \
./FreeRTOS/list.o \
./FreeRTOS/queue.o \
./FreeRTOS/stream_buffer.o \
./FreeRTOS/tasks.o \
./FreeRTOS/timers.o 



# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/%.o: ../FreeRTOS/%.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
