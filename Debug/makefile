################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Drivers/u8g2/subdir.mk
-include src/Drivers/gpiolib/subdir.mk
-include src/subdir.mk
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
ELFSIZE += \
2019_11_25_Menu_sys_final.elf.size \


# All Target
all: 2019_11_25_Menu_sys_final.elf secondary-outputs

# Tool invocations
2019_11_25_Menu_sys_final.elf: $(OBJS)  $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v7 Linux gcc linker'
	arm-linux-gnueabihf-gcc -L"/home/diploma/Work/peta_proj/images/linux/sdk/sysroots/cortexa9hf-neon-xilinx-linux-gnueabi" -o "2019_11_25_Menu_sys_final.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

2019_11_25_Menu_sys_final.elf.size: 2019_11_25_Menu_sys_final.elf
	@echo 'Invoking: ARM v7 Linux Print Size'
	arm-linux-gnueabihf-size 2019_11_25_Menu_sys_final.elf  |tee "2019_11_25_Menu_sys_final.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(S_UPPER_DEPS)$(C_DEPS)$(ELFSIZE) 2019_11_25_Menu_sys_final.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
