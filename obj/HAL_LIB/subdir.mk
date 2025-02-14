################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/EEPROM_25C.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/filters.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_data_model.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_adc.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_din.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_keyboard.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_timeout.c 

OBJS += \
./HAL_LIB/EEPROM_25C.o \
./HAL_LIB/filters.o \
./HAL_LIB/hw_data_model.o \
./HAL_LIB/hw_lib_adc.o \
./HAL_LIB/hw_lib_din.o \
./HAL_LIB/hw_lib_keyboard.o \
./HAL_LIB/hw_timeout.o 

C_DEPS += \
./HAL_LIB/EEPROM_25C.d \
./HAL_LIB/filters.d \
./HAL_LIB/hw_data_model.d \
./HAL_LIB/hw_lib_adc.d \
./HAL_LIB/hw_lib_din.d \
./HAL_LIB/hw_lib_keyboard.d \
./HAL_LIB/hw_timeout.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_LIB/EEPROM_25C.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/EEPROM_25C.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/filters.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/filters.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/hw_data_model.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_data_model.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/hw_lib_adc.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/hw_lib_din.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_din.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/hw_lib_keyboard.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_lib_keyboard.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL_LIB/hw_timeout.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/HAL_LIB/hw_timeout.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

