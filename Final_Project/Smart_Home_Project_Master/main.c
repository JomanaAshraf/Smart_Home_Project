/*
 * main.c
 *
 *  Created on: Feb 7, 2021
 *      Author: acer
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART_Interface.h"
#include "MSPI_Interface.h"
#include "MDIO_Interface.h"

int main(void)
{
	MUSART_VidInit(9600);
	MCAL_SPIMasterInit();
	u8 val;

	while(1)
	{
		val = MUSART_VidReceiveDataPolling();
		if (val!=0)
		{
			MCAL_SPIMasterSend(val);
		}
	}
	return 0 ;
}
