################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_ambientMonitor.c \
../Drivers/API/src/API_debounce.c \
../Drivers/API/src/API_delay.c \
../Drivers/API/src/API_encoder.c \
../Drivers/API/src/API_i2c.c \
../Drivers/API/src/API_lcd.c \
../Drivers/API/src/API_scd4x.c \
../Drivers/API/src/API_uart.c \
../Drivers/API/src/port.c 

OBJS += \
./Drivers/API/src/API_ambientMonitor.o \
./Drivers/API/src/API_debounce.o \
./Drivers/API/src/API_delay.o \
./Drivers/API/src/API_encoder.o \
./Drivers/API/src/API_i2c.o \
./Drivers/API/src/API_lcd.o \
./Drivers/API/src/API_scd4x.o \
./Drivers/API/src/API_uart.o \
./Drivers/API/src/port.o 

C_DEPS += \
./Drivers/API/src/API_ambientMonitor.d \
./Drivers/API/src/API_debounce.d \
./Drivers/API/src/API_delay.d \
./Drivers/API/src/API_encoder.d \
./Drivers/API/src/API_i2c.d \
./Drivers/API/src/API_lcd.d \
./Drivers/API/src/API_scd4x.d \
./Drivers/API/src/API_uart.d \
./Drivers/API/src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o Drivers/API/src/%.su Drivers/API/src/%.cyclo: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/CMSIS/Include" -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/Core/Inc" -I"/home/growcast/Documents/Especializacion-FIUBA/PdM_workspace/tp-final/Drivers/API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_ambientMonitor.cyclo ./Drivers/API/src/API_ambientMonitor.d ./Drivers/API/src/API_ambientMonitor.o ./Drivers/API/src/API_ambientMonitor.su ./Drivers/API/src/API_debounce.cyclo ./Drivers/API/src/API_debounce.d ./Drivers/API/src/API_debounce.o ./Drivers/API/src/API_debounce.su ./Drivers/API/src/API_delay.cyclo ./Drivers/API/src/API_delay.d ./Drivers/API/src/API_delay.o ./Drivers/API/src/API_delay.su ./Drivers/API/src/API_encoder.cyclo ./Drivers/API/src/API_encoder.d ./Drivers/API/src/API_encoder.o ./Drivers/API/src/API_encoder.su ./Drivers/API/src/API_i2c.cyclo ./Drivers/API/src/API_i2c.d ./Drivers/API/src/API_i2c.o ./Drivers/API/src/API_i2c.su ./Drivers/API/src/API_lcd.cyclo ./Drivers/API/src/API_lcd.d ./Drivers/API/src/API_lcd.o ./Drivers/API/src/API_lcd.su ./Drivers/API/src/API_scd4x.cyclo ./Drivers/API/src/API_scd4x.d ./Drivers/API/src/API_scd4x.o ./Drivers/API/src/API_scd4x.su ./Drivers/API/src/API_uart.cyclo ./Drivers/API/src/API_uart.d ./Drivers/API/src/API_uart.o ./Drivers/API/src/API_uart.su ./Drivers/API/src/port.cyclo ./Drivers/API/src/port.d ./Drivers/API/src/port.o ./Drivers/API/src/port.su

.PHONY: clean-Drivers-2f-API-2f-src

