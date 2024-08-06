
#include "StdTypes.h"
#include "MemMap.h"
#include "MCAL/RCC_Int.h"
#include "MCAL/DIO_Int.h"
#include "MCAL/SYSTICK_Int.h"
#include "HAL/LEDS_Int.h"
#include "HAL/PUSH_BUTTON_Int.h"



#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 762

const char arr[10]={0XFA,0X60,0XD9,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};

void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}



u8 button_flag=0;
void flash_led_every_half_sec (void)
{
    while(!(READ_BIT(STCTRL_REG,COUNT)));
    LED_TOGGLE(RED_LED);
}

void read_button(void)
{
    if(DIO_ReadPin(BUTTON_PIN)==1)
    {
        Delay_MS(30);
        if(DIO_ReadPin(BUTTON_PIN)==1)
        {
            if(button_flag==1)
            button_flag=0;
            else if(button_flag==0)
            button_flag=1;
        }

    }
}

int main(void)
{
    RCC_Init(PIOSC,16);
    DIO_ENABLE(PF); /* port F */
    DIO_Init();
    Systick_Init(&systick_var);

    LED_ON(RED_LED);

    while (1)
    {
        read_button();
        if(1==button_flag)
        {
            flash_led_every_half_sec();
        }
        else
        {
            LED_OFF(RED_LED);
        }
    }
}


