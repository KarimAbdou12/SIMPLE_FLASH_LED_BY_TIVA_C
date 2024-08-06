/******************************************************************************
 *
 * [FILE NAME]: DIO_Prog
 *
 * [AUTHOR]:    Karim Abdou
 *
 * [DATE CREATED]: 
 *
 * [DESCRIPTION]: < GPIO Driver >
 *
 *******************************************************************************/

#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "DIO_Priv.h"
#include "CONFIG/DIO_Cfg.h"


// LOCK & COMMIT ( ASK ) ?????

void DIO_ENABLE (DIO_PORT_t port_PIN)
{
    if(port_PIN>=PA&&port_PIN<=PF)
    {
        SET_BIT(SYSCTL_RCGC2_REG, port_PIN);
        while(!READ_BIT(SYSCTL_RCGC2_REG,port_PIN)); // must be delay 3 system clocks
    }

}



void DIO_Init(void) // for cong. pins before start proj.
{
    DIO_Pin_t i;
    for (i=PINA0;i<TOTAL_PINS;i++)
    {
        DIO_InitPin(i,DIO_PinsStatusArray[i]); //  it take nom. of pin & his status
    }

}

// Pins  PD7, PF0 and PC0?PC3 need lock and commit. DON’T USE PINS C0?C3 as 
//they are USED IN JTAG [DEBUGGING] AND ANY MISUSE MAY BURN THE TIVA.
//(LESA)
static void DIO_InitPin(DIO_Pin_t pin, DIO_PinStatus_t status)
{
    DIO_PORT_t port;
    u8 pin_num;

    if(pin>=0&&pin<32)
    {
        port=pin/8;
        pin_num=pin%8;
    }
    else if(pin>=32&&pin<38)
    {
        port=PE;
        pin_num=pin-32;
    }
    else if(pin>=38&&pin<43)
    {
        port=PF;
        pin_num=pin-38;
    }

    switch(status)
    {
        case OUTPUT:
        switch(port)
        {
            case PA:
            SET_BIT(GPIO_PORTA_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTA_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTA_DATA_REG,0,0X00);
            break;

            case PB:
            SET_BIT(GPIO_PORTB_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTB_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTB_DATA_REG,0,0X00);
            break;

            case PC:
            SET_BIT(GPIO_PORTC_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTC_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTC_DATA_REG,0,0X00);
            break;

            case PD:
            SET_BIT(GPIO_PORTD_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTD_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTD_DATA_REG,0,0X00);
            break;

            case PE:
            SET_BIT(GPIO_PORTE_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_AFSEL_REG,0x00);
            CLR_BIT(GPIO_PORTE_PUR_REG,0x00);
            CLR_BIT(GPIO_PORTE_PDR_REG,0x00);
            SET_BIT(GPIO_PORTE_DEN_REG,0x01);
            WRITE_BYTE(GPIO_PORTE_DATA_REG,0,0X00);
            break;

            case PF:
            SET_BIT(GPIO_PORTF_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTF_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTF_DATA_REG,0,0X00);
            break;

        }
        break;

        case INFREE:
        switch(port)
        {
            case PA:
            CLR_BIT(GPIO_PORTA_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTA_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTA_DATA_REG,0,0X00);
            break;

            case PB:
            CLR_BIT(GPIO_PORTB_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTB_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTB_DATA_REG,0,0X00);
            break;

            case PC:
            CLR_BIT(GPIO_PORTC_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTC_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTC_DATA_REG,0,0X00);
            break;

            case PD:
            CLR_BIT(GPIO_PORTD_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTD_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTD_DATA_REG,0,0X00);
            break;

            case PE:
            CLR_BIT(GPIO_PORTE_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTE_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTE_DATA_REG,0,0X00);
            break;

            case PF:
            CLR_BIT(GPIO_PORTF_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTF_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTF_DATA_REG,0,0X00);
            break;

            default:
            break;
        }
        break;

        case IN_PULLUP:
        switch(port)
        {
            case PA:
            CLR_BIT(GPIO_PORTA_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTA_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTA_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTA_DATA_REG,0,0X00);
            break;

            case PB:
            CLR_BIT(GPIO_PORTB_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTB_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTB_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTB_DATA_REG,0,0X00);
            break;

            case PC:
            CLR_BIT(GPIO_PORTC_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTC_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTC_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTC_DATA_REG,0,0X00);
            break;

            case PD:
            CLR_BIT(GPIO_PORTD_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTD_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTD_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTD_DATA_REG,0,0X00);
            break;

            case PE:
            CLR_BIT(GPIO_PORTE_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTE_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTE_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTE_DATA_REG,0,0X00);
            break;

            case PF:
            CLR_BIT(GPIO_PORTF_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_AFSEL_REG,pin_num);
            SET_BIT(GPIO_PORTF_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTF_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTF_DATA_REG,0,0X00);
            break;

            default:
            break;
        }
        break;

        case IN_PULLDOWN:
        switch(port)
        {
            case PA:
            CLR_BIT(GPIO_PORTA_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTA_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTA_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTA_DATA_REG,0,0X00);
            break;

            case PB:
            CLR_BIT(GPIO_PORTB_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTB_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTB_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTB_DATA_REG,0,0X00);
            break;

            case PC:
            CLR_BIT(GPIO_PORTC_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTC_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTC_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTC_DATA_REG,0,0X00);
            break;

            case PD:
            CLR_BIT(GPIO_PORTD_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTD_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTD_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTD_DATA_REG,0,0X00);
            break;

            case PE:
            CLR_BIT(GPIO_PORTE_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTE_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTE_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTE_DATA_REG,0,0X00);
            break;

            case PF:
            CLR_BIT(GPIO_PORTF_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PUR_REG,pin_num);
            SET_BIT(GPIO_PORTF_PDR_REG,pin_num);
            SET_BIT(GPIO_PORTF_DEN_REG,pin_num);
            WRITE_BYTE(GPIO_PORTF_DATA_REG,0,0X00);
            break;

            default:
            break;
        }
        break;

        case IN_ADC:
        switch(port)
        {
            case PA:
            CLR_BIT(GPIO_PORTA_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTA_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTA_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTA_DATA_REG,0,0X00);
            break;

            case PB:
            CLR_BIT(GPIO_PORTB_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTB_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTB_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTB_DATA_REG,0,0X00);
            break;

            case PC:
            CLR_BIT(GPIO_PORTC_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTC_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTC_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTC_DATA_REG,0,0X00);
            break;

            case PD:
            CLR_BIT(GPIO_PORTD_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTD_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTD_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTD_DATA_REG,0,0X00);
            break;

            case PE:
            CLR_BIT(GPIO_PORTE_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTE_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTE_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTE_DATA_REG,0,0X00);
            break;

            case PF:
            CLR_BIT(GPIO_PORTF_DIR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_AFSEL_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PUR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_PDR_REG,pin_num);
            CLR_BIT(GPIO_PORTF_DEN_REG,pin_num);
            SET_BIT(GPIO_PORTF_AMSEL_REG,pin_num);
            WRITE_BYTE(GPIO_PORTF_DATA_REG,0,0X00);
            break;

            default:
            break;
        }
        break;
    }


}



void DIO_WritePin(DIO_Pin_t pin,DIO_PinVoltage_t volt)
{
    DIO_PORT_t port;
    u8 pin_num;

    if(pin>=0&&pin<32)
    {
        port=pin/8;
        pin_num=pin%8;
    }
    else if(pin>=32&&pin<38)
    {
        port=PE;
        pin_num=pin-32;
    }
    else if(pin>=38&&pin<43)
    {
        port=PF;
        pin_num=pin-38;
    }
    if (volt==HIGH)
    {
        switch(port)
        {
            case PA:
            SET_BIT(GPIO_PORTA_DATA_REG,pin_num);
            break;

            case PB:
            SET_BIT(GPIO_PORTB_DATA_REG,pin_num);
            break;
            case PC:

            SET_BIT(GPIO_PORTC_DATA_REG,pin_num);
            break;
            case PD:

            SET_BIT(GPIO_PORTD_DATA_REG,pin_num);
            break;

            case PE:

            SET_BIT(GPIO_PORTE_DATA_REG,pin_num);
            break;

            case PF:

            SET_BIT(GPIO_PORTF_DATA_REG,pin_num);
            break;
        }
    }
    else
    {
        switch(port)
        {
            case PA:
            CLR_BIT(GPIO_PORTA_DATA_REG,pin_num);
            break;

            case PB:
            CLR_BIT(GPIO_PORTB_DATA_REG,pin_num);
            break;
            case PC:

            CLR_BIT(GPIO_PORTC_DATA_REG,pin_num);
            break;
            case PD:

            CLR_BIT(GPIO_PORTD_DATA_REG,pin_num);
            break;

            case PE:

            CLR_BIT(GPIO_PORTE_DATA_REG,pin_num);
            break;

            case PF:

            CLR_BIT(GPIO_PORTF_DATA_REG,pin_num);
            break;
        }
    }

}

DIO_PinVoltage_t DIO_ReadPin(DIO_Pin_t pin)
{
    DIO_PORT_t port;
    u8 pin_num;

    if(pin>=0&&pin<32)
    {
        port=pin/8;
        pin_num=pin%8;
    }
    else if(pin>=32&&pin<38)
    {
        port=PE;
        pin_num=pin-32;
    }
    else if(pin>=38&&pin<43)
    {
        port=PF;
        pin_num=pin-38;
    }
    DIO_PinVoltage_t volt=LOW;
    switch(port)
    {
        case PA:

        volt=READ_BIT(GPIO_PORTA_DATA_REG,pin_num);
        break;
        case PB:

        volt=READ_BIT(GPIO_PORTB_DATA_REG,pin_num);
        break;
        case PC:

        volt=READ_BIT(GPIO_PORTC_DATA_REG,pin_num);
        break;
        case PD:

        volt=READ_BIT(GPIO_PORTD_DATA_REG,pin_num);
        break;

        case PE:

        volt=READ_BIT(GPIO_PORTE_DATA_REG,pin_num);
        break;

        case PF:

        volt=READ_BIT(GPIO_PORTF_DATA_REG,pin_num);
        break;
    }
    return volt;
}

void DIO_WritePort(DIO_PORT_t port,u8 data)
{
    switch(port)
    {
        case PA:

        WRITE_BYTE(GPIO_PORTA_DATA_REG,0,data);
        break;
        case PB:

        WRITE_BYTE(GPIO_PORTB_DATA_REG,0,data);
        break;
        case PC:

        WRITE_BYTE(GPIO_PORTC_DATA_REG,0,data);
        break;
        case PD:

        WRITE_BYTE(GPIO_PORTD_DATA_REG,0,data);
        break;
        case PE:

        WRITE_BYTE(GPIO_PORTE_DATA_REG,0,data);
        break;
        case PF:

        WRITE_BYTE(GPIO_PORTF_DATA_REG,0,data);
        break;
    }

}


u8 DIO_ReadPort(DIO_PORT_t port)
{
    u8 data=0;
    switch(port)
    {
        case PA:

        data=GPIO_PORTA_DATA_REG&0X000000FF;
        break;
        case PB:

        data=GPIO_PORTB_DATA_REG&0X000000FF;
        break;
        case PC:

        data=GPIO_PORTC_DATA_REG&0X000000FF;
        break;
        case PD:

        data=GPIO_PORTD_DATA_REG&0X000000FF;
        break;
        case PE:

        data=GPIO_PORTE_DATA_REG&0X000000FF;
        break;
        case PF:

        data=GPIO_PORTF_DATA_REG&0X000000FF;
        break;
    }
    return data;

}


void DIO_TogglePin (DIO_Pin_t pin)
{
    DIO_PORT_t port;
    u8 pin_num;

    if(pin>=0&&pin<32)
    {
        port=pin/8;
        pin_num=pin%8;
    }
    else if(pin>=32&&pin<38)
    {
        port=PE;
        pin_num=pin-32;
    }
    else if(pin>=38&&pin<43)
    {
        port=PF;
        pin_num=pin-38;
    }

    switch(port)
    {
        case PA:

        TOG_BIT(GPIO_PORTA_DATA_REG,pin_num);
        break;
        case PB:

        TOG_BIT(GPIO_PORTB_DATA_REG,pin_num);
        break;
        case PC:

        TOG_BIT(GPIO_PORTC_DATA_REG,pin_num);
        break;
        case PD:

        TOG_BIT(GPIO_PORTD_DATA_REG,pin_num);
        break;
        case PE:

        TOG_BIT(GPIO_PORTE_DATA_REG,pin_num);
        break;
        case PF:

        TOG_BIT(GPIO_PORTF_DATA_REG,pin_num);
        break;
    }

}
