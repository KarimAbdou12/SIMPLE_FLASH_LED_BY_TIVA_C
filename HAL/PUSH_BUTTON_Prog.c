/*
 * PUSH_BUTTON_Prog.c
 *
 * Created: 8/6/2024 3:01:53 PM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "MCAL/DIO_Int.h"
#include "PUSH_BUTTON_Int.h"
#include "PUSH_BUTTON_Priv.h"
#include "CONFIG/PUSH_BUTTON_Cfg.h"


DIO_PinVoltage_t READ_BUTTON (u8 pin)
{
	DIO_PinVoltage_t volt;
	volt=DIO_ReadPin(pin);		/* HIGH  -  LOW  */
	
	
	return volt;
}
