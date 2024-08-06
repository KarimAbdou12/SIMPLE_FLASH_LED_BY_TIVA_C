/*
 * RCC_Int.h
 *
 *  Created on: Aug 2, 2024
 *      Author: Magic
 */

#ifndef MCAL_RCC_INT_H_
#define MCAL_RCC_INT_H_



typedef enum
{
    MOSC,
    PIOSC,
    PIOSC_div_4,
    LFIOSC,
    _32_KHZ
}CLK_SOURCE_t;


typedef enum
{
    PLL_MULTIP_200MHZ,
    PLL_MULTIP_400MHZ

}PLL_MULTIP_T;


//  Table5-5
/*** 1-2-3-4-5-10-64  in 200 MHZ ***/

//400 MHZ Valid when BYPASS2=0 from Table5-6.
/*** 2-3-4-5-6-7-8-9-10-127-128  in 400 MHZ ***/

typedef enum
{
    SYSDIV_1,
    SYSDIV_2,
    SYSDIV_3,
    SYSDIV_4,
    SYSDIV_5,
    SYSDIV_6,
    SYSDIV_7,
    SYSDIV_8,
    SYSDIV_9,
    SYSDIV_10,
    SYSDIV_64,
    SYSDIV_127,
    SYSDIV_128

}SYSDIV_t;


void RCC_Init (CLK_SOURCE_t source,u8 Frequancy);
void PLL_Init (CLK_SOURCE_t source,u8 source_Frequancy,PLL_MULTIP_T PLL_MULTIP,SYSDIV_t DIV);



#endif /* MCAL_RCC_INT_H_ */
