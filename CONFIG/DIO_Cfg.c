/*
 * DIO_Cfg.c
 *
 * Created: 7/29/2024 9:49:58 AM
 *  Author: Magic
 */ 

#include "StdTypes.h"
#include "MCAL/DIO_Int.h"
#include "DIO_Cfg.h"


	/* OUTPUT,INFREE,INPULL*/ 
const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS]={
	INFREE,      /* Port A Pin 0 */
	OUTPUT,      /* Port A Pin 1 */
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	INFREE,      /* Port A Pin 7 */
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	IN_PULLUP,		 /* Port B Pin 2 /*/
	OUTPUT,		 /* Port B Pin 3   */
	OUTPUT,		 /* Port B Pin 4 */
	OUTPUT,		 /* Port B Pin 5 */
	OUTPUT,		 /* Port B Pin 6 */
	OUTPUT,		 /* Port B Pin 7 */
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	OUTPUT,		 /* Port D Pin 0 */
	OUTPUT,		 /* Port D Pin 1 */
    OUTPUT,      /* Port D Pin 2 */
	OUTPUT,      /* Port D Pin 3 / */
	OUTPUT,		 /* Port D Pin 4  */
	OUTPUT,		 /* Port D Pin 5 */
	INFREE,		 /* Port D Pin 6 */
	OUTPUT,		 /* Port D Pin 7 */
	OUTPUT,		 /* Port E Pin 0 */
	OUTPUT,		 /* Port E Pin 1 */
	OUTPUT,		 /* Port E Pin 2 */
	OUTPUT,		 /* Port E Pin 3 */
	OUTPUT,		 /* Port E Pin 4 */
	OUTPUT,		 /* Port E Pin 5 */
	OUTPUT,		 /* Port E Pin 6 */
	OUTPUT,		 /* Port E Pin 7 */
	OUTPUT,		 /* Port F Pin 0 */
	OUTPUT,		 /* Port F Pin 1 */
	OUTPUT,		 /* Port F Pin 2 */
	OUTPUT,		 /* Port F Pin 3 */
	OUTPUT,		 /* Port F Pin 4 */
	OUTPUT,		 /* Port F Pin 5 */
	OUTPUT,		 /* Port F Pin 6 */
	OUTPUT,		 /* Port F Pin 7 */
};
