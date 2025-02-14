################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/MRS_DATA/workspace/LUA/lapi.c \
C:/MRS_DATA/workspace/LUA/lauxlib.c \
C:/MRS_DATA/workspace/LUA/lbaselib.c \
C:/MRS_DATA/workspace/LUA/lcode.c \
C:/MRS_DATA/workspace/LUA/lcorolib.c \
C:/MRS_DATA/workspace/LUA/lctype.c \
C:/MRS_DATA/workspace/LUA/ldblib.c \
C:/MRS_DATA/workspace/LUA/ldebug.c \
C:/MRS_DATA/workspace/LUA/ldo.c \
C:/MRS_DATA/workspace/LUA/ldump.c \
C:/MRS_DATA/workspace/LUA/lfunc.c \
C:/MRS_DATA/workspace/LUA/lgc.c \
C:/MRS_DATA/workspace/LUA/linit.c \
C:/MRS_DATA/workspace/LUA/liolib.c \
C:/MRS_DATA/workspace/LUA/llex.c \
C:/MRS_DATA/workspace/LUA/lmathlib.c \
C:/MRS_DATA/workspace/LUA/lmem.c \
C:/MRS_DATA/workspace/LUA/loadlib.c \
C:/MRS_DATA/workspace/LUA/lobject.c \
C:/MRS_DATA/workspace/LUA/lopcodes.c \
C:/MRS_DATA/workspace/LUA/loslib.c \
C:/MRS_DATA/workspace/LUA/lparser.c \
C:/MRS_DATA/workspace/LUA/lstate.c \
C:/MRS_DATA/workspace/LUA/lstring.c \
C:/MRS_DATA/workspace/LUA/lstrlib.c \
C:/MRS_DATA/workspace/LUA/ltable.c \
C:/MRS_DATA/workspace/LUA/ltablib.c \
C:/MRS_DATA/workspace/LUA/ltm.c \
C:/MRS_DATA/workspace/LUA/luaeheap.c \
C:/MRS_DATA/workspace/LUA/lundump.c \
C:/MRS_DATA/workspace/LUA/lutf8lib.c \
C:/MRS_DATA/workspace/LUA/lvm.c \
C:/MRS_DATA/workspace/LUA/lzio.c 

OBJS += \
./LUA/lapi.o \
./LUA/lauxlib.o \
./LUA/lbaselib.o \
./LUA/lcode.o \
./LUA/lcorolib.o \
./LUA/lctype.o \
./LUA/ldblib.o \
./LUA/ldebug.o \
./LUA/ldo.o \
./LUA/ldump.o \
./LUA/lfunc.o \
./LUA/lgc.o \
./LUA/linit.o \
./LUA/liolib.o \
./LUA/llex.o \
./LUA/lmathlib.o \
./LUA/lmem.o \
./LUA/loadlib.o \
./LUA/lobject.o \
./LUA/lopcodes.o \
./LUA/loslib.o \
./LUA/lparser.o \
./LUA/lstate.o \
./LUA/lstring.o \
./LUA/lstrlib.o \
./LUA/ltable.o \
./LUA/ltablib.o \
./LUA/ltm.o \
./LUA/luaeheap.o \
./LUA/lundump.o \
./LUA/lutf8lib.o \
./LUA/lvm.o \
./LUA/lzio.o 

C_DEPS += \
./LUA/lapi.d \
./LUA/lauxlib.d \
./LUA/lbaselib.d \
./LUA/lcode.d \
./LUA/lcorolib.d \
./LUA/lctype.d \
./LUA/ldblib.d \
./LUA/ldebug.d \
./LUA/ldo.d \
./LUA/ldump.d \
./LUA/lfunc.d \
./LUA/lgc.d \
./LUA/linit.d \
./LUA/liolib.d \
./LUA/llex.d \
./LUA/lmathlib.d \
./LUA/lmem.d \
./LUA/loadlib.d \
./LUA/lobject.d \
./LUA/lopcodes.d \
./LUA/loslib.d \
./LUA/lparser.d \
./LUA/lstate.d \
./LUA/lstring.d \
./LUA/lstrlib.d \
./LUA/ltable.d \
./LUA/ltablib.d \
./LUA/ltm.d \
./LUA/luaeheap.d \
./LUA/lundump.d \
./LUA/lutf8lib.d \
./LUA/lvm.d \
./LUA/lzio.d 


# Each subdirectory must supply rules for building sources it contributes
LUA/lapi.o: C:/MRS_DATA/workspace/LUA/lapi.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lauxlib.o: C:/MRS_DATA/workspace/LUA/lauxlib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lbaselib.o: C:/MRS_DATA/workspace/LUA/lbaselib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lcode.o: C:/MRS_DATA/workspace/LUA/lcode.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lcorolib.o: C:/MRS_DATA/workspace/LUA/lcorolib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lctype.o: C:/MRS_DATA/workspace/LUA/lctype.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldblib.o: C:/MRS_DATA/workspace/LUA/ldblib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldebug.o: C:/MRS_DATA/workspace/LUA/ldebug.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldo.o: C:/MRS_DATA/workspace/LUA/ldo.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldump.o: C:/MRS_DATA/workspace/LUA/ldump.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lfunc.o: C:/MRS_DATA/workspace/LUA/lfunc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lgc.o: C:/MRS_DATA/workspace/LUA/lgc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/linit.o: C:/MRS_DATA/workspace/LUA/linit.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/liolib.o: C:/MRS_DATA/workspace/LUA/liolib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/llex.o: C:/MRS_DATA/workspace/LUA/llex.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lmathlib.o: C:/MRS_DATA/workspace/LUA/lmathlib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lmem.o: C:/MRS_DATA/workspace/LUA/lmem.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/loadlib.o: C:/MRS_DATA/workspace/LUA/loadlib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lobject.o: C:/MRS_DATA/workspace/LUA/lobject.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lopcodes.o: C:/MRS_DATA/workspace/LUA/lopcodes.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/loslib.o: C:/MRS_DATA/workspace/LUA/loslib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lparser.o: C:/MRS_DATA/workspace/LUA/lparser.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstate.o: C:/MRS_DATA/workspace/LUA/lstate.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstring.o: C:/MRS_DATA/workspace/LUA/lstring.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstrlib.o: C:/MRS_DATA/workspace/LUA/lstrlib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltable.o: C:/MRS_DATA/workspace/LUA/ltable.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltablib.o: C:/MRS_DATA/workspace/LUA/ltablib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltm.o: C:/MRS_DATA/workspace/LUA/ltm.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/luaeheap.o: C:/MRS_DATA/workspace/LUA/luaeheap.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lundump.o: C:/MRS_DATA/workspace/LUA/lundump.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lutf8lib.o: C:/MRS_DATA/workspace/LUA/lutf8lib.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lvm.o: C:/MRS_DATA/workspace/LUA/lvm.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lzio.o: C:/MRS_DATA/workspace/LUA/lzio.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V_LUA\Debug" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\PROTOCOLS" -I"C:\MRS_DATA\workspace\CH32V_LUA\Core" -I"C:\MRS_DATA\workspace\CH32V_LUA\User" -I"C:\MRS_DATA\workspace\CH32V_LUA\Peripheral\inc" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\include" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\CH32V_LUA\FreeRTOS\portable\MemMang" -I"C:\MRS_DATA\workspace\CH32V_LUA\USB_Device" -I"C:\MRS_DATA\workspace\CH32V_LUA\UART" -I"C:\MRS_DATA\workspace\LUA" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

