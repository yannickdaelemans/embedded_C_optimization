################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
init/%.o: ../init/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/gcc/bin/msp430-elf-gcc-6.4.0.exe" -c -mmcu=msp430fr6989 -mhwmult=f5series -I"C:/ti/ccs1000/ccs/ccs_base/msp430/include_gcc" -I"C:/Users/Yannick/workspace_v10/Embedded_C_timings" -I"C:/ti/gcc/msp430-elf/include" -O3 -Wall -mlarge -mcode-region=none -mdata-region=lower -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


