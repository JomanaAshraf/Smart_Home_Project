#ifndef _MSPI_INTERFACE_H_
#define	_MSPI_INTERFACE_H_

void MCAL_SPIMasterInit(void);

void MCAL_SPISlaveInit(void);

u8 MCAL_SPIMasterSend(u8 Copy_U8Data);

u8 MCAL_SPISlaveReceive(u8 Copy_U8Data);


#endif
