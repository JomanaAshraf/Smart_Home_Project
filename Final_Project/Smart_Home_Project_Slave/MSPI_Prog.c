#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_Interface.h"
#include "MSPI_Private.h"
#include "MDIO_Interface.h"


void MCAL_SPIMasterInit()
{
	MDIO_VidSetPinDir(PortB,Pin4,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortB,Pin5,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortB,Pin7,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortB,Pin6,MDIO_INPUT);

	SET_BIT(SPCR,4);

	SET_BIT(SPCR,0);

	SET_BIT(SPCR,6);

	MDIO_VidSetPinValue(PortB,Pin4,MDIO_HIGH);
}

void MCAL_SPISlaveInit(void)
{
	SET_BIT(SPCR,6);
	MDIO_VidSetPinDir(PortB,Pin6,MDIO_OUTPUT);
	MDIO_VidSetPinDir(PortB,Pin4,MDIO_INPUT);
	MDIO_VidSetPinDir(PortB,Pin5,MDIO_INPUT);
	MDIO_VidSetPinDir(PortB,Pin7,MDIO_INPUT);
}

u8 MCAL_SPIMasterSend(u8 Copy_U8Data)
{
	/*Clear SS to send data to slave*/
	MDIO_VidSetPinValue(PortB,Pin4,MDIO_LOW);
	/*Put data on SPDR*/
	SPDR=Copy_U8Data;
	/*Wait until the transmission is finished*/
     while((GET_BIT(SPSR,7))==0);
	 /*read SPDR*/
     return SPDR;
}

u8 MCAL_SPISlaveReceive(u8 Copy_U8Data)
{
	/*Put data on SPDR*/
		SPDR=Copy_U8Data;
		/*Wait until data is received in SPI register*/
		while((GET_BIT(SPSR,7)) == 0);
		/*read the received data*/
		return SPDR ;
}
