################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/gcc

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.o" \
"./UART_communication/UART_communication.o" \
"./code_thesis_examples/extra_function.o" \
"./code_thesis_examples/thesis_example_code.o" \
"./init/init.o" \
"./timing/timing.o" \
-T"../msp430fr6989.ld" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-lgcc \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include UART_communication/subdir_vars.mk
-include code_thesis_examples/subdir_vars.mk
-include init/subdir_vars.mk
-include timing/subdir_vars.mk
-include subdir_rules.mk
-include UART_communication/subdir_rules.mk
-include code_thesis_examples/subdir_rules.mk
-include init/subdir_rules.mk
-include timing/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Embedded_C_timings.out \

EXE_OUTPUTS__QUOTED += \
"Embedded_C_timings.out" \

BIN_OUTPUTS += \
Embedded_C_timings.hex \

BIN_OUTPUTS__QUOTED += \
"Embedded_C_timings.hex" \


# All Target
all: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Embedded_C_timings.out"

# Tool invocations
Embedded_C_timings.out: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ti/gcc/bin/msp430-elf-gcc-6.4.0.exe" -mhwmult=f5series -O3 -Wall -mcode-region=none -mdata-region=lower -mlarge -Wl,-Map,"Embedded_C_timings.map" -Wl,--gc-sections -L"C:/ti/ccs1000/ccs/ccs_base/msp430/include_gcc" -mmcu=msp430fr6989 -o"Embedded_C_timings.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Embedded_C_timings.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/ti/gcc/bin/msp430-elf-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "Embedded_C_timings.hex"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.o" "UART_communication\UART_communication.o" "code_thesis_examples\extra_function.o" "code_thesis_examples\thesis_example_code.o" "init\init.o" "timing\timing.o" 
	-$(RM) "main.d" "UART_communication\UART_communication.d" "code_thesis_examples\extra_function.d" "code_thesis_examples\thesis_example_code.d" "init\init.d" "timing\timing.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

