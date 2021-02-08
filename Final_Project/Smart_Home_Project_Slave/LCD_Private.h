#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#define DISPLAY_LEFT				0x18
#define DISPLAY_RIGHT				0x1C
#define LCD_CLR						0x01


#if LCD_MODE==EIGHT_BIT
	#define FUN_SET_1_LINE			0x30
	#define FUN_SET_2_LINE			0x38


#elif LCD_MODE==FOUR_BIT
	#define FUN_SET_1_LINE			0x20
	#define FUN_SET_2_LINE			0x28

#endif

#endif
