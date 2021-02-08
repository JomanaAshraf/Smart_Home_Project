#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

void LCD_VidSendData(u8 Copy_U8Data);
void LCD_VidSendCommand(u8 Copy_U8Command);
void LCD_VidInt(void);
void LCD_VidSendNumber(u32 Copy_U32Number);
void LCD_VidGoToXY(u8 Copy_U8Row , u8 Copy_U8Column);
void LCD_VidSendWord(u8 *Copy_U8Word);
void LCD_VidSendSpecialChar(u8 *Copy_U8arr,u8 Copy_U8NumberOfChar);

#endif
