/*
 * LEDS_Int.h
 *
 * Created: 7/30/2024 2:25:34 AM
 *  Author: Karim Abdou
 */ 


#ifndef LEDS_INT_H_
#define LEDS_INT_H_

typedef enum
{
	RED_LED,
	GREEN_LED,
	BLUE_LED
}LED_COLOR_t;

void LED_ON (LED_COLOR_t led);
void LED_OFF (LED_COLOR_t led);
void LED_TOGGLE (LED_COLOR_t led);

#endif /* LEDS_INT_H_ */