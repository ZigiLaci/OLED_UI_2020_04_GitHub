################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/data_struct.c \
../src/gpio_buttons.c \
../src/main.c \
../src/navigation.c \
../src/print_logo_serial.c \
../src/print_window.c 

OBJS += \
./src/data_struct.o \
./src/gpio_buttons.o \
./src/main.o \
./src/navigation.o \
./src/print_logo_serial.o \
./src/print_window.o 

C_DEPS += \
./src/data_struct.d \
./src/gpio_buttons.d \
./src/main.d \
./src/navigation.d \
./src/print_logo_serial.d \
./src/print_window.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 Linux gcc compiler'
	arm-linux-gnueabihf-gcc -Wall -O0 -g3 -I"/home/diploma/Work/peta_proj/images/linux/sdk/sysroots/cortexa9hf-neon-xilinx-linux-gnueabi/usr/include" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


