/*
 * SYSTICK_Cfg.c
 *
 * Created: 7/31/2024 11:17:39 AM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "MCAL/SYSTICK_Int.h"
#include "SYSTICK_Cfg.h"

SysTick_Config_t systick_var =
{
	.period =7999999,
	.clk_source=SYSTEM_CLK,
	.inerrupt_enable=ENABLE,
};


