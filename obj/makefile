################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include LUA/subdir.mk
-include LIB/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS/subdir.mk
-include Debug/subdir.mk
-include DRIVER/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
CH32V3_LUA.bin \
CH32V3_LUA.hex \

SECONDARY_LIST += \
CH32V3_LUA.lst \

SECONDARY_SIZE += \
CH32V3_LUA.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: CH32V3_LUA.elf secondary-outputs

# Tool invocations
CH32V3_LUA.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-g++ -march=rv32imafcxw -mabi=ilp32f -msmall-data-limit=8 -msave-restore -fmax-errors=20 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -T "c:/MRS_DATA/workspace/CH32V_LUA/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -Xlinker --print-memory-usage -Xlinker -print-memory-usage -Wl,-Map,"CH32V3_LUA.map" --specs=nano.specs --specs=nosys.specs -o "CH32V3_LUA.elf" $(OBJS)  $(LIBS)
CH32V3_LUA.bin: CH32V3_LUA.elf
	@	riscv-none-embed-objcopy -O binary "CH32V3_LUA.elf" "CH32V3_LUA.bin"
CH32V3_LUA.hex: CH32V3_LUA.elf
	@	riscv-none-embed-objcopy -O ihex "CH32V3_LUA.elf" "CH32V3_LUA.hex"
CH32V3_LUA.lst: CH32V3_LUA.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "CH32V3_LUA.elf" > "CH32V3_LUA.lst"
CH32V3_LUA.siz: CH32V3_LUA.elf
	riscv-none-embed-size --format=berkeley "CH32V3_LUA.elf"

# Other Targets
clean:
	-$(RM) $(OBJS) $(EXPANDS) $(CALLGRAPH_DOT) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS)$(C_UPPER_DEPS)$(CC_DEPS)$(C++_DEPS)$(CXX_DEPS)$(CPP_DEPS) CH32V3_LUA.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets