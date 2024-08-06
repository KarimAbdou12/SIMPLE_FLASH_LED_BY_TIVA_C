/*
 * DIO_Priv.h
 *
 * Created: 7/29/2024 9:49:24 AM
 *  Author: Magic
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/***** RCGC2_REGISTER **********/
#define  PA		0
#define  PB		1
#define  PC		2
#define  PD		3
#define  PE		4
#define  PF		5


extern const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS];

static void DIO_InitPin(DIO_Pin_t pin, DIO_PinStatus_t status);  // array from confg.


#endif /* DIO_PRIV_H_ */