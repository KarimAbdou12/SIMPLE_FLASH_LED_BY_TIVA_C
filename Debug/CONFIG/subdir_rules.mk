################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.obj: ../CONFIG/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/ARM Diploma/TIVA_C/TIVA_C" --include_path="E:/ARM Diploma/TIVA_C" --include_path="D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=PART_TM4C1231H6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="CONFIG/$(basename $(<F)).d_raw" --obj_directory="CONFIG" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


