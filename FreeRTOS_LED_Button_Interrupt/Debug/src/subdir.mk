################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DUSE_SEMIHOSTING -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/StdPeriph_Driver/inc" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Third_Party/SEGGER/Config" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Third_Party/SEGGER/OS" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Third_Party/SEGGER/SEGGER" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Third_Party/FreeRTOS/org/Source/include" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/Config" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/inc" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/CMSIS/device" -I"C:/Users/Minhd/workspace/FreeRTOS_LED_Button_Interrupt/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


