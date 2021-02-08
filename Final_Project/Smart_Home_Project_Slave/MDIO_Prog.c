/*
 * MDIO_Prog.c
 *
 *  Created on: Dec 18, 2020
 *      Author: acer
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Interface.h"
#include "MDIO_Private.h"


/********************************************************************************************/
/******************************************/
/********************************************************************************************/

void MDIO_VidSetPinDir(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,MDIO_State Copy_enuState)
{
	if(MDIO_OUTPUT==Copy_enuState)
	{
		switch (Copy_enuPort){
		case PortA: SET_BIT(DDRA,Copy_enuPin); break;
		case PortB: SET_BIT(DDRB,Copy_enuPin); break;
		case PortC: SET_BIT(DDRC,Copy_enuPin); break;
		case PortD: SET_BIT(DDRD,Copy_enuPin); break;
		}
	}
	else if(MDIO_INPUT==Copy_enuState)
	{
		switch (Copy_enuPort){
		case PortA: CLR_BIT(DDRA,Copy_enuPin); break;
		case PortB: CLR_BIT(DDRB,Copy_enuPin); break;
		case PortC: CLR_BIT(DDRC,Copy_enuPin); break;
		case PortD: CLR_BIT(DDRD,Copy_enuPin); break;
		}
	}
}

void MDIO_VidSetPinValue(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,MDIO_PWR_State Copy_enuPWRState)
{
	if(MDIO_HIGH==Copy_enuPWRState)
	{
		switch (Copy_enuPort){
		case PortA: SET_BIT(PORTA,Copy_enuPin); break;
		case PortB: SET_BIT(PORTB,Copy_enuPin); break;
		case PortC: SET_BIT(PORTC,Copy_enuPin); break;
		case PortD: SET_BIT(PORTD,Copy_enuPin); break;
		}
	}
	else if(MDIO_LOW==Copy_enuPWRState)
	{
		switch (Copy_enuPort){
		case PortA: CLR_BIT(PORTA,Copy_enuPin); break;
		case PortB: CLR_BIT(PORTB,Copy_enuPin); break;
		case PortC: CLR_BIT(PORTC,Copy_enuPin); break;
		case PortD: CLR_BIT(PORTD,Copy_enuPin); break;
		}

	}
}

void MDIO_VidGetPinValue(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,u8 *Copy_ptr_Value)
{
	u8 value=0;
	switch (Copy_enuPort){
	case PortA: value= GET_BIT(PINA,Copy_enuPin); break;
	case PortB: value= GET_BIT(PINB,Copy_enuPin); break;
	case PortC: value= GET_BIT(PINC,Copy_enuPin); break;
	case PortD: value= GET_BIT(PIND,Copy_enuPin); break;
	}
	*Copy_ptr_Value=value;

}

void MDIO_VidSetPortDir(MDIO_Port Copy_enuPort,MDIO_State Copy_enuState)
{
	if(MDIO_OUTPUT==Copy_enuState)
	{
		switch (Copy_enuPort){
		case PortA: DDRA=0xFF; break;
		case PortB: DDRB=0xFF; break;
		case PortC: DDRC=0xFF; break;
		case PortD: DDRD=0xFF; break;
		}
	}
	else if(MDIO_INPUT==Copy_enuState)
	{
		switch (Copy_enuPort){
		case PortA: DDRA=0x00; break;
		case PortB: DDRB=0x00; break;
		case PortC: DDRC=0x00; break;
		case PortD: DDRD=0x00; break;
		}
	}
}

void MDIO_VidSetPortValue(MDIO_Port Copy_enuPort,MDIO_PWR_State Copy_enuPWRState)
{
	if(MDIO_HIGH==Copy_enuPWRState)
	{
		switch (Copy_enuPort){
		case PortA: PORTA=0xFF; break;
		case PortB: PORTB=0xFF; break;
		case PortC: PORTC=0xFF; break;
		case PortD: PORTD=0xFF; break;
		}
	}
	else if(MDIO_LOW==Copy_enuPWRState)
	{
		switch (Copy_enuPort){
		case PortA: PORTA=0x00; break;
		case PortB: PORTB=0x00; break;
		case PortC: PORTC=0x00; break;
		case PortD: PORTD=0x00; break;
		}
	}

}

void MDIO_VidToggPin(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin)
{
	switch (Copy_enuPort)
	{
	case PortA: TGL_BIT(PORTA,Copy_enuPin); break;
	case PortB: TGL_BIT(PORTB,Copy_enuPin); break;
	case PortC: TGL_BIT(PORTC,Copy_enuPin); break;
	case PortD: TGL_BIT(PORTD,Copy_enuPin); break;
	}
}





