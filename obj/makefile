################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include USB_Device/subdir.mk
-include UART/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include PROTOCOLS/subdir.mk
-include HAL_DRIVER/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS/subdir.mk
-include Debug/subdir.mk
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
CH32V3_CAN_HACKER.hex \

SECONDARY_LIST += \
CH32V3_CAN_HACKER.lst \

SECONDARY_SIZE += \
CH32V3_CAN_HACKER.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: CH32V3_CAN_HACKER.elf secondary-outputs

# Tool invocations
CH32V3_CAN_HACKER.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -T "c:/MRS_DATA/workspace/CH32V3_CAN_HACKER/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -Xlinker --print-memory-usage -Wl,-Map,"CH32V3_CAN_HACKER.map" --specs=nano.specs --specs=nosys.specs -o "CH32V3_CAN_HACKER.elf" $(OBJS)  $(LIBS)
CH32V3_CAN_HACKER.hex: CH32V3_CAN_HACKER.elf
	@	riscv-none-embed-objcopy -O ihex "CH32V3_CAN_HACKER.elf" "CH32V3_CAN_HACKER.hex"
CH32V3_CAN_HACKER.lst: CH32V3_CAN_HACKER.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "CH32V3_CAN_HACKER.elf" > "CH32V3_CAN_HACKER.lst"
CH32V3_CAN_HACKER.siz: CH32V3_CAN_HACKER.elf
	riscv-none-embed-size --format=berkeley "CH32V3_CAN_HACKER.elf"

# Other Targets
clean:
	-$(RM) $(OBJS) $(EXPANDS) $(CALLGRAPH_DOT) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) CH32V3_CAN_HACKER.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets