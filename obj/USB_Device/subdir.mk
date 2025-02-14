################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_Device/ch32v30x_usbfs_device.c \
../USB_Device/usb_desc.c 

OBJS += \
./USB_Device/ch32v30x_usbfs_device.o \
./USB_Device/usb_desc.o 

C_DEPS += \
./USB_Device/ch32v30x_usbfs_device.d \
./USB_Device/usb_desc.d 


# Each subdirectory must supply rules for building sources it contributes
USB_Device/%.o: ../USB_Device/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

