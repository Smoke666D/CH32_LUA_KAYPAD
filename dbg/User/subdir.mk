################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v30x_it.c \
../User/init.c \
../User/io_task.c \
../User/led_task.c \
../User/lua_task.c \
../User/main.c \
../User/system_ch32v30x.c \
../User/system_init.c 

OBJS += \
./User/ch32v30x_it.o \
./User/init.o \
./User/io_task.o \
./User/led_task.o \
./User/lua_task.o \
./User/main.o \
./User/system_ch32v30x.o \
./User/system_init.o 

C_DEPS += \
./User/ch32v30x_it.d \
./User/init.d \
./User/io_task.d \
./User/led_task.d \
./User/lua_task.d \
./User/main.d \
./User/system_ch32v30x.d \
./User/system_init.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

