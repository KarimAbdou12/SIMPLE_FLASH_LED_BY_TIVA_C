/*
 * SYSTICK_Int.h
 *
 * Created: 7/31/2024 11:16:51 AM
 *  Author: Karim Abdou
 */ 


#ifndef SYSTICK_INT_H_
#define SYSTICK_INT_H_

#define ENABLE_BIT 0
#define INTEN_BIT 1
#define CLK_SRC_BIT 2
#define COUNT 16

typedef enum 
{
	PIOSC_DIV4,
	SYSTEM_CLK
}CLK_SOURCE_T;

typedef enum
{
	DISABLE,
	ENABLE
}INTEN_t;


typedef struct 
{
	u8 period;
	CLK_SOURCE_T clk_source;
	INTEN_t inerrupt_enable;
	
}SysTick_Config_t;

#define SYSTEM_CLK  (0x04)
#define ENABLE		(0x10000)

extern SysTick_Config_t systick_var;
void Systick_Init(SysTick_Config_t*prt_sysick);
void SysTick_SetCallBack(void (*FuncPointer)(void));


#endif /* SYSTICK_INT_H_ */
