################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c1231h6pm_startup_ccs.obj" \
"./CONFIG/DIO_Cfg.obj" \
"./CONFIG/LEDS_Cfg.obj" \
"./CONFIG/PUSH_BUTTON_Cfg.obj" \
"./CONFIG/RCC_Cfg.obj" \
"./CONFIG/SYSTICK_Cfg.obj" \
"./HAL/LEDS_Prog.obj" \
"./HAL/PUSH_BUTTON_Prog.obj" \
"./MCAL/DIO_Prog.obj" \
"./MCAL/RCC_Prog.obj" \
"./MCAL/SYSTICK_Prog.obj" \
"../tm4c1231h6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include CONFIG/subdir_vars.mk
-include HAL/subdir_vars.mk
-include MCAL/subdir_vars.mk
-include subdir_rules.mk
-include CONFIG/subdir_rules.mk
-include HAL/subdir_rules.mk
-include MCAL/subdir_rules.mk
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
TIVA_C.out 

EXE_OUTPUTS__QUOTED += \
"TIVA_C.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "TIVA_C.out"

# Tool invocations
TIVA_C.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --define=ccs="ccs" --define=PART_TM4C1231H6PM --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"TIVA_C.map" --heap_size=0 --stack_size=512 -i"D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"D:/Download/download prog/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="TIVA_C_linkInfo.xml" --rom_model -o "TIVA_C.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c1231h6pm_startup_ccs.obj" "CONFIG\DIO_Cfg.obj" "CONFIG\LEDS_Cfg.obj" "CONFIG\PUSH_BUTTON_Cfg.obj" "CONFIG\RCC_Cfg.obj" "CONFIG\SYSTICK_Cfg.obj" "HAL\LEDS_Prog.obj" "HAL\PUSH_BUTTON_Prog.obj" "MCAL\DIO_Prog.obj" "MCAL\RCC_Prog.obj" "MCAL\SYSTICK_Prog.obj" 
	-$(RM) "main.d" "tm4c1231h6pm_startup_ccs.d" "CONFIG\DIO_Cfg.d" "CONFIG\LEDS_Cfg.d" "CONFIG\PUSH_BUTTON_Cfg.d" "CONFIG\RCC_Cfg.d" "CONFIG\SYSTICK_Cfg.d" "HAL\LEDS_Prog.d" "HAL\PUSH_BUTTON_Prog.d" "MCAL\DIO_Prog.d" "MCAL\RCC_Prog.d" "MCAL\SYSTICK_Prog.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

