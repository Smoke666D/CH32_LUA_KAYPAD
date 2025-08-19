################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER/hal_adc.c \
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

OBJS += \
./DRIVER/hal_adc.o \
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

C_DEPS += \
./DRIVER/hal_adc.d \
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


# Each subdirectory must supply rules for building sources it contributes
DRIVER/%.o: ../DRIVER/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

