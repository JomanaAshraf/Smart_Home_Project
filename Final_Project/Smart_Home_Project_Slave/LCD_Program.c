/************************** Auther :      Ahmed Kamal *********************************************/
/************************** Date :        20/10/2020    *******************************************/
/************************** Version :     V1         **********************************************/
/************************** Description : Implemntation To LCD Functions **************************/

#define F_CPU 16000000UL
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"





static void LCD_VidLatch(u8 Copy_U8User)
{
	MDIO_VidSetPinValue(RW_PORT,RW_PIN,MDIO_LOW);

#if LCD_MODE==EIGHT_BIT

	MDIO_VidSetPinValue(D0_PORT,D0_PIN,(Copy_U8User&1));

	MDIO_VidSetPinValue(D1_PORT,D1_PIN,((Copy_U8User>>1)&1));

	MDIO_VidSetPinValue(D2_PORT,D2_PIN,((Copy_U8User>>2)&1));

	MDIO_VidSetPinValue(D3_PORT,D3_PIN,((Copy_U8User>>3)&1));

	MDIO_VidSetPinValue(D4_PORT,D4_PIN,((Copy_U8User>>4)&1));

	MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>5)&1));

	MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>6)&1));

	MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>7)&1));

	MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
	_delay_ms(1);

#elif LCD_MODE==FOUR_BIT
	if(1 == (GET_BIT(RS_PORT,RS_PIN)))
	{
		MDIO_VidSetPinValue(D4_PORT,D4_PIN,((Copy_U8User>>4)&1));

		MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>5)&1));

		MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>6)&1));

		MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>7)&1));


		MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
		_delay_ms(1);
		MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
		_delay_ms(1);


		MDIO_VidSetPinValue(D4_PORT,D4_PIN,(Copy_U8User&1));

		MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>1)&1));

		MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>2)&1));

		MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>3)&1));


		MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
		_delay_ms(1);
		MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
		_delay_ms(1);

	}
	else if(0 == (GET_BIT(RS_PORT,RS_PIN)))
	{
		if((Copy_U8User == FUN_SET_1_LINE) || (Copy_U8User== FUN_SET_2_LINE))
		{

			MDIO_VidSetPinValue(D4_PORT,D4_PIN,((Copy_U8User>>4)&1));

			MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>5)&1));

			MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>6)&1));

			MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>7)&1));

			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
			_delay_ms(1);
			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
			_delay_ms(1);


			MDIO_VidSetPinValue(D4_PORT,D4_PIN,((Copy_U8User>>4)&1));

			MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>5)&1));

			MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>6)&1));

			MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>7)&1));


			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
			_delay_ms(1);
			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
			_delay_ms(1);


			MDIO_VidSetPinValue(D4_PORT,D4_PIN,(Copy_U8User&1));

			MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>1)&1));

			MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>2)&1));

			MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>3)&1));


			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
			_delay_ms(1);
			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
			_delay_ms(1);
		}
		else
		{
			MDIO_VidSetPinValue(D4_PORT,D4_PIN,((Copy_U8User>>4)&1));

			MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>5)&1));

			MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>6)&1));

			MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>7)&1));


			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
			_delay_ms(1);
			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
			_delay_ms(1);


			MDIO_VidSetPinValue(D4_PORT,D4_PIN,(Copy_U8User&1));

			MDIO_VidSetPinValue(D5_PORT,D5_PIN,((Copy_U8User>>1)&1));

			MDIO_VidSetPinValue(D6_PORT,D6_PIN,((Copy_U8User>>2)&1));

			MDIO_VidSetPinValue(D7_PORT,D7_PIN,((Copy_U8User>>3)&1));


			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_HIGH);
			_delay_ms(1);
			MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);
			_delay_ms(1);
		}
	}


#endif
}

/*******************************************************/
/*******************************************************/


void LCD_VidSendData(u8 Copy_U8Data)
{
	MDIO_VidSetPinValue(RS_PORT,RS_PIN,MDIO_HIGH);
	LCD_VidLatch(Copy_U8Data);
	_delay_ms(10);
}

void LCD_VidSendCommand(u8 Copy_U8Command)
{
	MDIO_VidSetPinValue(RS_PORT,RS_PIN,MDIO_LOW);
	LCD_VidLatch(Copy_U8Command);
	_delay_ms(10);
}


void LCD_VidInt(void)
{
	MDIO_VidSetPinDir(EN_PORT,EN_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinDir(RS_PORT,RS_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinDir(RW_PORT,RW_PIN,MDIO_OUTPUT);


	MDIO_VidSetPinDir(D4_PORT,D4_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinDir(D5_PORT,D5_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinDir(D6_PORT,D6_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinDir(D7_PORT,D7_PIN,MDIO_OUTPUT);

	MDIO_VidSetPinValue(EN_PORT,EN_PIN,MDIO_LOW);


#if LCD_MODE==EIGHT_BIT
	MDIO_VidSetPortDir(D0_PORT,D0_PIN,MDIO_OUTPUT);

	MDIO_VidSetPortDir(D1_PORT,D1_PIN,MDIO_OUTPUT);

	MDIO_VidSetPortDir(D2_PORT,D2_PIN,MDIO_OUTPUT);

	MDIO_VidSetPortDir(D3_PORT,D3_PIN,MDIO_OUTPUT);


	_delay_ms(50);
	LCD_VidSendCommand(0x38);
	_delay_ms(1);
	LCD_VidSendCommand(0x0C);
	_delay_ms(1);
	LCD_VidSendCommand(LCD_CLR);
	_delay_ms(2);
	LCD_VidSendCommand(0b00000110); //Entery Mode
	LCD_VidSendCommand(0b10000000); //Set DDRAM Address

	_delay_ms(50);

#elif LCD_MODE==FOUR_BIT

	_delay_ms(50);
	LCD_VidSendCommand(FUN_SET_2_LINE);
	_delay_us(50);
	LCD_VidSendCommand(0x0C);
	_delay_us(50);
	LCD_VidSendCommand(LCD_CLR);
	_delay_ms(2);
	LCD_VidSendCommand(0b00000110); //Entery Mode
	LCD_VidSendCommand(0b10000000);//Set DDRAM Address

	_delay_ms(50);

#else
#error ENTRY MODE MUST BE 8-bit or 4-bit

#endif
}
/********************************************************/

void LCD_VidSendWord(u8 *Copy_U8Word)
{
	for(u8 i=0 ; Copy_U8Word[i]!='\0';i++)
	{
		if(Copy_U8Word[i]==32) LCD_VidSendData(0x10);
		else LCD_VidSendData(Copy_U8Word[i]);
	}
}


void LCD_VidSendNumber(u32 Copy_U32Number)
{
	if(Copy_U32Number<10)
	{
		LCD_VidSendData(Copy_U32Number+48);
	}
	else
	{
		s8 count=0;
		u32 x=Copy_U32Number;
		for(;x>0;count++,x/=10);
		u32 res=0;
		while(Copy_U32Number>0)
		{
			u8 temp = Copy_U32Number%10;
			Copy_U32Number/=10;
			res=temp+(res*10);
		}
		for(;count>0;count--)
		{
			u8 temp = res%10;
			LCD_VidSendData(temp+48);
			res/=10;
		}
	}
}


void LCD_VidGoToXY(u8 Copy_U8Row , u8 Copy_U8Column)
{
	if(0==Copy_U8Row)
	{
		LCD_VidSendCommand(128+Copy_U8Column);//0b10000001
	}
	else if(1==Copy_U8Row)
	{
		LCD_VidSendCommand(128+64+Copy_U8Column);
	}
}


void LCD_VidSendSpecialChar(u8 *Copy_U8arr,u8 Copy_U8NumberOfChar)
{


	LCD_VidSendCommand(0x40);

	for(u8 i=0;i<(Copy_U8NumberOfChar*8);i++)
	{
		LCD_VidSendData(Copy_U8arr[i]);
	}

	_delay_ms(50);

}


/*
 {{0x0F,0x08,0x1F,0x04,0x04,0x04,0x04,0x04},
 {0x00,0x00,0x00,0x1E,0x11,0x01,0x1E,0x00},
 {0x00,0x00,0x00,0x0E,0x0A,0x0A,0x1F,0x00},
{0x00,0x00,0x00,0x04,0x02,0x02,0x0F,0x00}};
 */








