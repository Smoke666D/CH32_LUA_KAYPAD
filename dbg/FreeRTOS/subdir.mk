################################################################################
# MRS Version: 2.3.0
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

DIR_OBJS += \
./FreeRTOS/*.o \

DIR_DEPS += \
./FreeRTOS/*.d \

DIR_EXPANDS += \
./FreeRTOS/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/%.o: ../FreeRTOS/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Debug" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Core" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/User" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Peripheral/inc" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/include" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/Common" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

