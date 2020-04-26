################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Drivers/gpiolib/gpiolib.c 

OBJS += \
./src/Drivers/gpiolib/gpiolib.o 

C_DEPS += \
./src/Drivers/gpiolib/gpiolib.d 


# Each subdirectory must supply rules for building sources it contributes
src/Drivers/gpiolib/%.o: ../src/Drivers/gpiolib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 Linux gcc compiler'
	arm-linux-gnueabihf-gcc -Wall -O0 -g3 -I"/home/diploma/Work/peta_proj/images/linux/sdk/sysroots/cortexa9hf-neon-xilinx-linux-gnueabi/usr/include" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


