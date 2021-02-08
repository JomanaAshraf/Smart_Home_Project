/*
 * UART_Private.h
 *
 *  Created on: Nov 11, 2020
 *      Author: acer
 */

#ifndef _MUSART_PRIVATE_H_
#define _MUSART_PRIVATE_H_

void __vector_13(void) __attribute__((signal));

#define UDR			(*(volatile u8 *)0x2C)

#define UCSRA		(*(volatile u8 *)0x2B)

#define UCSRB		(*(volatile u8 *)0x2A)

#define UCSRC		(*(volatile u8 *)0x40)

#define UBRRL		(*(volatile u8 *)0x29)

#define UBRRH		(*(volatile u8 *)0x40)


#endif
