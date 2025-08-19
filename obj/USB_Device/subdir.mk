################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_Device/ch32v30x_usbfs_device.c \
../USB_Device/usb_desc.c 

C_DEPS += \
./USB_Device/ch32v30x_usbfs_device.d \
./USB_Device/usb_desc.d 

OBJS += \
./USB_Device/ch32v30x_usbfs_device.o \
./USB_Device/usb_desc.o 


EXPANDS += \
./USB_Device/ch32v30x_usbfs_device.c.234r.expand \
./USB_Device/usb_desc.c.234r.expand 



# Each subdirectory must supply rules for building sources it contributes
USB_Device/%.o: ../USB_Device/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Debug" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/HAL_DRIVER" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/PROTOCOLS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Core" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/User" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/USB_Device" -I"c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/UART" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

