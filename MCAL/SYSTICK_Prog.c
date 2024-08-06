/*
 * SYSTICK_Prog.c
 *
 * Created: 7/31/2024 8:35:28 AM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "SYSTICK_Int.h"
#include "SYSTICK_Priv.h"
#include "CONFIG/SYSTICK_Cfg.h"



/*********************************************/

static void (*SysTick_SetCallBackpointer) (void)=NULLPTR;

/********************************************/

void Systick_Init(SysTick_Config_t*prt_sysick)
{
    STCTRL_REG&=(0xE);
//  CLR_BIT(STCTRL_REG,ENABLE_BIT);             // clear enable bit
    STRELOAD_REG=prt_sysick->period;            // Set the Reload Value in the STRELOAD Register.
    STCURRENT_REG=0;                            //  Clear the Counter by clearing the STCURRENT Register
    STCTRL_REG|=prt_sysick->clk_source;
    STCTRL_REG|=prt_sysick->inerrupt_enable;
    SET_BIT(STCTRL_REG,ENABLE_BIT);
}

void SysTick_Stop(void)
{
    CLR_BIT(STCTRL_REG,ENABLE_BIT);
}

void SysTick_SetCallBack(void (*FuncPointer)(void))
{
    SysTick_SetCallBackpointer=FuncPointer;
}

