/*
 * MDIO_Interface.h
 *
 *  Created on: Dec 18, 2020
 *      Author: acer
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_


typedef enum{
	PortA,
	PortB,
	PortC,
	PortD
}MDIO_Port;


typedef enum{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}MDIO_Pin;

typedef enum{
	MDIO_INPUT,
	MDIO_OUTPUT
}MDIO_State;

typedef enum{
	MDIO_LOW,
	MDIO_HIGH
}MDIO_PWR_State;

void MDIO_VidSetPinDir(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,MDIO_State Copy_enuState);


void MDIO_VidSetPinValue(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,MDIO_PWR_State Copy_enuPWRState);


void MDIO_VidGetPinValue(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin,u8 *Copy_ptr_Value);


void MDIO_VidToggPin(MDIO_Port Copy_enuPort,MDIO_Pin Copy_enuPin);


void MDIO_VidSetPortDir(MDIO_Port Copy_enuPort,MDIO_State Copy_enuState);


void MDIO_VidSetPortValue(MDIO_Port Copy_enuPort,MDIO_PWR_State Copy_enuPWRState);


#endif


