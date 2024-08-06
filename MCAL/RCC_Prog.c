#include "StdTypes.h"
#include "MemMap.h"
#include "RCC_Priv.h"
#include "RCC_Int.h"
#include "CONFIG/RCC_Cfg.h"




/****************** For RCC2 **********************/

void RCC_Init (CLK_SOURCE_t source,u8 Frequancy)
{
    SET_BIT(SYSCTL_RCC2_REG,31); // USERCC2

    switch (source)
    {
        case MOSC :
        CLR_BIT(RCC,0);//  enable bit main oscillator  OSCSRC 4,5
        RCC2=(RCC2&(0X0<<4)) | (0X0<<4);
        #if (8 == Frequancy)
        {
            RCC=(RCC&(0X00<<6)) | (0X0E<<6); // bit (6) >> XTAL
        }
        #elif (16 == Frequancy)
        {
            WRITE_BYTE(RCC,6,0X15);
        }
        #endif
        {
            WRITE_BYTE(RCC,6,0X19); // 24 MHZ
        }
        break;

        case PIOSC :
        SET_BIT(RCC,0); // disable main oscillator
        RCC2=(RCC2&(0X0<<4)) | (0X1<<4);
        break;

        case PIOSC_div_4 :
        SET_BIT(RCC,0); // disable main oscillator
        RCC2=(RCC2&(0X0<<4)) | (0X2<<4);
        break;

        case LFIOSC :
        SET_BIT(RCC,0); // disable main oscillator
        RCC2=(RCC2&(0X0<<4)) | (0X3<<4);
        break;

        case _32_KHZ :
        SET_BIT(RCC,0); // disable main oscillator
        RCC2=(RCC2&(0X0<<4)) | (0X7<<4);
        break;

    }
}


/** source , source_Frequancy , div **/
void PLL_Init (CLK_SOURCE_t source,u8 source_Frequancy,PLL_MULTIP_T PLL_MULTIP,SYSDIV_t DIV)
{
    SET_BIT(RCC2,11); //BYPASS2
    CLR_BIT(RCC,22); //USESYSDIV

    RCC_Init(source,source_Frequancy); // Select the crystal value (XTAL) and oscillator source (OSCSRC)
    CLR_BIT(RCC2,13); //PWRDN2 ||  clear the PWRDN bit in RCC/RCC2
    //  Setting the XTAL field automatically pulls valid PLL configuration data for the appropriate crystal, ??????????

    //  3. Select the desired system divider (SYSDIV) in RCC/RCC2 and set the USESYS bit in RCC
    SET_BIT(RCC,22); // USESYSDIV

    // in RCC Table 5-4
    // in RCC2 we have to choice >> 400MHZ - 200 MHZ
    // and divisor it from sysdiv2

    if(PLL_MULTIP==PLL_MULTIP_200MHZ) // when div400=0
    {
        CLR_BIT(RCC2,30); // div400
        CLR_BIT(RCC2,11); // Bypass2

    // set USESYSDIV in RCC & USERCC2 TO use sysdiv2 ( done before )
        switch (DIV)
        {
            case SYSDIV_1 :
            WRITE_BYTE(RCC2,23,0x00);
            break;

            case SYSDIV_2 :
            WRITE_BYTE(RCC2,23,0x01);
            break;

            case SYSDIV_3 :
            WRITE_BYTE(RCC2,23,0x02);
            break;

            case SYSDIV_4 :
            WRITE_BYTE(RCC2,23,0x03);
            break;

            case SYSDIV_5 :
            WRITE_BYTE(RCC2,23,0x04);
            break;

            case SYSDIV_10 :
            WRITE_BYTE(RCC2,23,0x09);
            break;

            case SYSDIV_64 :
            WRITE_BYTE(RCC2,23,0x3F);
            break;
            default :
            break;

        }
    }
    else if(PLL_MULTIP==PLL_MULTIP_400MHZ) // when div400=1
    {
        SET_BIT(RCC2,30); // div400
        CLR_BIT(RCC2,11); // Bypass2
        switch (DIV)
        {

            case SYSDIV_2 :
            WRITE_BYTE(RCC2,23,0x00);
            break;

            case SYSDIV_3 :
            CLR_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x01);
            break;

            case SYSDIV_4 :
            SET_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x01);
            break;

            case SYSDIV_5 :
            CLR_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x02);
            break;

            case SYSDIV_6 :
            SET_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x02);
            break;

            case SYSDIV_7 :
            CLR_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x03);
            break;

            case SYSDIV_8 :
            SET_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x03);
            break;

            case SYSDIV_9 :
            CLR_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x04);
            break;

            case SYSDIV_10 :
            SET_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x04);
            break;

            case SYSDIV_127 :
            CLR_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x3F);
            break;

            case SYSDIV_128 :
            SET_BIT(RCC2,22);//SYSDIV2LSB
            WRITE_BYTE(RCC2,23,0x3F);
            break;

            default :
            break;

        }
    }


    // 4. Wait for the PLL to lock by polling the PLLLRIS bit in the Raw Interrupt Status (RIS) register
    while (!READ_BIT(RIS,6)); //PLLLRIS
    CLR_BIT(RCC2,11); //BYPASS2


}
