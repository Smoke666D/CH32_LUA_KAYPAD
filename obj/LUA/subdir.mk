################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LUA/lapi.c \
../LUA/lauxlib.c \
../LUA/lbaselib.c \
../LUA/lbitlib.c \
../LUA/lcode.c \
../LUA/lcorolib.c \
../LUA/lctype.c \
../LUA/ldblib.c \
../LUA/ldebug.c \
../LUA/ldo.c \
../LUA/ldump.c \
../LUA/lfunc.c \
../LUA/lgc.c \
../LUA/linit.c \
../LUA/liolib.c \
../LUA/llex.c \
../LUA/lmathlib.c \
../LUA/lmem.c \
../LUA/loadlib.c \
../LUA/lobject.c \
../LUA/lopcodes.c \
../LUA/loslib.c \
../LUA/lparser.c \
../LUA/lstate.c \
../LUA/lstring.c \
../LUA/lstrlib.c \
../LUA/ltable.c \
../LUA/ltablib.c \
../LUA/ltm.c \
../LUA/lua.c \
../LUA/luaeheap.c \
../LUA/lundump.c \
../LUA/lutf8lib.c \
../LUA/lvm.c \
../LUA/lzio.c 

C_DEPS += \
./LUA/lapi.d \
./LUA/lauxlib.d \
./LUA/lbaselib.d \
./LUA/lbitlib.d \
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
./LUA/lua.d \
./LUA/luaeheap.d \
./LUA/lundump.d \
./LUA/lutf8lib.d \
./LUA/lvm.d \
./LUA/lzio.d 

OBJS += \
./LUA/lapi.o \
./LUA/lauxlib.o \
./LUA/lbaselib.o \
./LUA/lbitlib.o \
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
./LUA/lua.o \
./LUA/luaeheap.o \
./LUA/lundump.o \
./LUA/lutf8lib.o \
./LUA/lvm.o \
./LUA/lzio.o 



# Each subdirectory must supply rules for building sources it contributes
LUA/%.o: ../LUA/%.c
	@	riscv-none-embed-gcc -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/MRS_DATA/workspace/CH32V_LUA/Debug" -I"c:/MRS_DATA/workspace/CH32V_LUA/Core" -I"c:/MRS_DATA/workspace/CH32V_LUA/User" -I"c:/MRS_DATA/workspace/CH32V_LUA/Peripheral/inc" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/include" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/Common" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/MRS_DATA/workspace/CH32V_LUA/FreeRTOS/portable/MemMang" -I"c:/MRS_DATA/workspace/CH32V_LUA/LUA" -I"c:/MRS_DATA/workspace/CH32V_LUA/LIB" -I"c:/MRS_DATA/workspace/CH32V_LUA/DRIVER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
