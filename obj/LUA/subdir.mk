################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lapi.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lauxlib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lbaselib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lcode.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lcorolib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lctype.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldblib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldebug.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldo.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldump.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lfunc.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lgc.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/linit.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/liolib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/llex.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lmathlib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lmem.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/loadlib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lobject.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lopcodes.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/loslib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lparser.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstate.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstring.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstrlib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltable.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltablib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltm.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/luaeheap.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lundump.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lutf8lib.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lvm.c \
C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lzio.c 

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
LUA/lapi.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lapi.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lauxlib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lauxlib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lbaselib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lbaselib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lcode.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lcode.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lcorolib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lcorolib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lctype.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lctype.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldblib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldblib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldebug.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldebug.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldo.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldo.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ldump.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ldump.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lfunc.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lfunc.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lgc.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lgc.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/linit.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/linit.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/liolib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/liolib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/llex.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/llex.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lmathlib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lmathlib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lmem.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lmem.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/loadlib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/loadlib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lobject.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lobject.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lopcodes.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lopcodes.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/loslib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/loslib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lparser.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lparser.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstate.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstate.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstring.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstring.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lstrlib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lstrlib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltable.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltable.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltablib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltablib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/ltm.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/ltm.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/luaeheap.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/luaeheap.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lundump.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lundump.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lutf8lib.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lutf8lib.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lvm.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lvm.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
LUA/lzio.o: C:/Users/i.dymov/Documents/SYSTEM_LIB/LUA/lzio.c
	@	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_DRIVER" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\HAL_LIB" -I"C:\MRS_DATA\workspace\LUA_TEST\Debug" -I"C:\MRS_DATA\workspace\LUA_TEST\Core" -I"C:\MRS_DATA\workspace\LUA_TEST\User" -I"C:\MRS_DATA\workspace\LUA_TEST\Peripheral\inc" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\include" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\Common" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\MRS_DATA\workspace\LUA_TEST\FreeRTOS\portable\MemMang" -I"C:\Users\i.dymov\Documents\SYSTEM_LIB\LUA" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

