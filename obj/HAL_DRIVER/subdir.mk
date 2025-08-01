################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_dma_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c \
c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_usart.c 

C_DEPS += \
./HAL_DRIVER/hal_can_ch32.d \
./HAL_DRIVER/hal_dma_ch32.d \
./HAL_DRIVER/hal_gpio_ch32.d \
./HAL_DRIVER/hal_irq.d \
./HAL_DRIVER/hal_timers_ch32.d \
./HAL_DRIVER/hal_usart.d 

OBJS += \
./HAL_DRIVER/hal_can_ch32.o \
./HAL_DRIVER/hal_dma_ch32.o \
./HAL_DRIVER/hal_gpio_ch32.o \
./HAL_DRIVER/hal_irq.o \
./HAL_DRIVER/hal_timers_ch32.o \
./HAL_DRIVER/hal_usart.o 


EXPANDS += \
./HAL_DRIVER/hal_can_ch32.c.234r.expand \
./HAL_DRIVER/hal_dma_ch32.c.234r.expand \
./HAL_DRIVER/hal_gpio_ch32.c.234r.expand \
./HAL_DRIVER/hal_irq.c.234r.expand \
./HAL_DRIVER/hal_timers_ch32.c.234r.expand \
./HAL_DRIVER/hal_usart.c.234r.expand 



# Each subdirectory must supply rules for building sources it contributes
HAL_DRIVER/hal_can_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_dma_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_dma_ch32.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_gpio_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_irq.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_timers_ch32.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
HAL_DRIVER/hal_usart.o: c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_usart.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER" -I"c:/Users/i.dymov/Documents/SYSTEM_LIB/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

