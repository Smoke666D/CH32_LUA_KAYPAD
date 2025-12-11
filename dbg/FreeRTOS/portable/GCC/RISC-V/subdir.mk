################################################################################
# MRS Version: 2.3.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/port.c 

C_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/port.d 

S_UPPER_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/portASM.S 

S_UPPER_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/portASM.d 

OBJS += \
./FreeRTOS/portable/GCC/RISC-V/port.o \
./FreeRTOS/portable/GCC/RISC-V/portASM.o 

DIR_OBJS += \
./FreeRTOS/portable/GCC/RISC-V/*.o \

DIR_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/*.d \

DIR_EXPANDS += \
./FreeRTOS/portable/GCC/RISC-V/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Debug" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Core" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/User" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Peripheral/inc" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/include" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/Common" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.S
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -x assembler-with-cpp -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Startup" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/include" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/Common" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

