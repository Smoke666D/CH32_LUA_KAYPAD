################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_usart.c 

OBJS += \
./HAL_DRIVER/hal_can_ch32.o \
./HAL_DRIVER/hal_gpio_ch32.o \
./HAL_DRIVER/hal_irq.o \
./HAL_DRIVER/hal_timers_ch32.o \
./HAL_DRIVER/hal_usart.o 

C_DEPS += \
./HAL_DRIVER/hal_can_ch32.d \
./HAL_DRIVER/hal_gpio_ch32.d \
./HAL_DRIVER/hal_irq.d \
./HAL_DRIVER/hal_timers_ch32.d \
./HAL_DRIVER/hal_usart.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_DRIVER/hal_can_ch32.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_can_ch32.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_DRIVER/hal_gpio_ch32.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_gpio_ch32.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_DRIVER/hal_irq.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_irq.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_DRIVER/hal_timers_ch32.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_timers_ch32.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_DRIVER/hal_usart.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_DRIVER/hal_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

