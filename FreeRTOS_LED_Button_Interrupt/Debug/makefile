################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Third_Party/SEGGER/SEGGER/subdir.mk
-include Third_Party/SEGGER/OS/subdir.mk
-include Third_Party/SEGGER/Config/subdir.mk
-include Third_Party/FreeRTOS/org/Source/portable/MemMang/subdir.mk
-include Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Third_Party/FreeRTOS/org/Source/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOS_LED_Button_Interrupt.elf

# Tool invocations
FreeRTOS_LED_Button_Interrupt.elf: $(OBJS) $(USER_OBJS) C:\Users\Minhd\workspace\FreeRTOS_LED_Button_Interrupt/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=rdimon.specs -lc -lrdimon -T"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "FreeRTOS_LED_Button_Interrupt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "FreeRTOS_LED_Button_Interrupt.elf" "FreeRTOS_LED_Button_Interrupt.bin"
	arm-none-eabi-size "FreeRTOS_LED_Button_Interrupt.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
