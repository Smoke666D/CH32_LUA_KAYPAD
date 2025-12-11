################################################################################
# MRS Version: 2.3.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER/hal_adc_ch32.c \
../DRIVER/hal_can_ch32.c \
../DRIVER/hal_dac.c \
../DRIVER/hal_dma_ch32.c \
../DRIVER/hal_flash_ch32.c \
../DRIVER/hal_gpio_ch32.c \
../DRIVER/hal_i2c_ch32.c \
../DRIVER/hal_irq.c \
../DRIVER/hal_rtc_ch32.c \
../DRIVER/hal_spi_ch32.c \
../DRIVER/hal_timers_ch32.c \
../DRIVER/hal_usart.c \
../DRIVER/hal_wdt_ch32.c 

C_DEPS += \
./DRIVER/hal_adc_ch32.d \
./DRIVER/hal_can_ch32.d \
./DRIVER/hal_dac.d \
./DRIVER/hal_dma_ch32.d \
./DRIVER/hal_flash_ch32.d \
./DRIVER/hal_gpio_ch32.d \
./DRIVER/hal_i2c_ch32.d \
./DRIVER/hal_irq.d \
./DRIVER/hal_rtc_ch32.d \
./DRIVER/hal_spi_ch32.d \
./DRIVER/hal_timers_ch32.d \
./DRIVER/hal_usart.d \
./DRIVER/hal_wdt_ch32.d 

OBJS += \
./DRIVER/hal_adc_ch32.o \
./DRIVER/hal_can_ch32.o \
./DRIVER/hal_dac.o \
./DRIVER/hal_dma_ch32.o \
./DRIVER/hal_flash_ch32.o \
./DRIVER/hal_gpio_ch32.o \
./DRIVER/hal_i2c_ch32.o \
./DRIVER/hal_irq.o \
./DRIVER/hal_rtc_ch32.o \
./DRIVER/hal_spi_ch32.o \
./DRIVER/hal_timers_ch32.o \
./DRIVER/hal_usart.o \
./DRIVER/hal_wdt_ch32.o 

DIR_OBJS += \
./DRIVER/*.o \

DIR_DEPS += \
./DRIVER/*.d \

DIR_EXPANDS += \
./DRIVER/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
DRIVER/%.o: ../DRIVER/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Debug" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Core" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/User" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/Peripheral/inc" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/include" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/Common" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/dymov-i.d/Documents/CH32_LUA_KAYPAD/FreeRTOS/portable/MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

