/*
 * main.c
 *
 *  Created on: Feb 7, 2021
 *      Author: acer
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_Interface.h"
#include "MDIO_Interface.h"
#include "LCD_Interface.h"

int main(void)
{
	MDIO_VidSetPinDir(PortC,Pin0,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortC,Pin1,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortC,Pin2,MDIO_OUTPUT);
	MCAL_SPISlaveInit();
	u8 x;
	while(1)
	{
		x= MCAL_SPISlaveReceive(0);
		if(x=='A')
		{
			MDIO_VidSetPinValue(PortC,Pin0,MDIO_HIGH);
		}
		else if (x=='B')
		{
			MDIO_VidSetPinValue(PortC,Pin1,MDIO_HIGH);
		}
		else if (x=='C')
		{
			MDIO_VidSetPinValue(PortC,Pin2,MDIO_HIGH);
		}
		else if (x=='S')
		{
			MDIO_VidSetPinValue(PortC,Pin0,MDIO_LOW);
			MDIO_VidSetPinValue(PortC,Pin1,MDIO_LOW);
			MDIO_VidSetPinValue(PortC,Pin2,MDIO_LOW);
		}
	}
	return 0 ;
}
