################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c 

C_DEPS += \
./HAL_DRIVER/hal_can_ch32.d \
./HAL_DRIVER/hal_gpio_ch32.d \
./HAL_DRIVER/hal_irq.d \
./HAL_DRIVER/hal_timers_ch32.d 

OBJS += \
./HAL_DRIVER/hal_can_ch32.o \
./HAL_DRIVER/hal_gpio_ch32.o \
./HAL_DRIVER/hal_irq.o \
./HAL_DRIVER/hal_timers_ch32.o 



# Each subdirectory must supply rules for building sources it contributes
HAL_DRIVER/hal_can_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_gpio_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_irq.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_timers_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c
	@	riscv-wch-elf-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/LUA" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

