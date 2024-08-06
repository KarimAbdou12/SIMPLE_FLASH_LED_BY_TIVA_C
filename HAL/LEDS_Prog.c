/*
 * LEDS_Prog.c
 *
 * Created: 7/30/2024 2:25:18 AM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "MCAL/DIO_Int.h"
#include "LEDS_Int.h"
#include "LEDS_Priv.h"
#include "CONFIG/LEDS_Cfg.h"


void LED_ON (LED_COLOR_t led)
{
	DIO_WritePin(led,HIGH);
}

void LED_OFF (LED_COLOR_t led)
{
	DIO_WritePin(led,LOW);
}

void LED_TOGGLE (LED_COLOR_t led)
{
	DIO_TogglePin(led);
}
