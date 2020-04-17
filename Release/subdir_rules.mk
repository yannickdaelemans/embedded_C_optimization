################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/msp430-gcc-8.3.1.25_win64/bin/msp430-elf-gcc-8.3.1.exe" -c -mmcu=msp430fr6989 -mhwmult=f5series -I"C:/ti/ccs1000/ccs/ccs_base/msp430/include_gcc" -I"C:/Users/Yannick/workspace_v10/Embedded_C_timings" -I"C:/ti/ccs1000/ccs/tools/compiler/msp430-gcc-8.3.1.25_win64/msp430-elf/include" -Os -Wall -mlarge -mcode-region=none -mdata-region=lower -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


