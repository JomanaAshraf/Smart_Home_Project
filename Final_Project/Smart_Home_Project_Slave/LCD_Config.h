#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define FOUR_BIT 						0
#define EIGHT_BIT 						1

#define LCD_MODE 						FOUR_BIT

#define RS_PORT							PortA
#define RS_PIN							Pin1
	
	
#define RW_PORT							PortA
#define RW_PIN							Pin0
	
	
#define EN_PORT							PortA
#define EN_PIN							Pin2



#if LCD_MODE==EIGHT_BIT

	#define D0_PORT						PortC
	#define D0_PIN						Pin0

	#define D1_PORT						PortC
	#define D1_PIN						Pin1

	#define D2_PORT						PortC
	#define D2_PIN						Pin2

	#define D3_PORT						PortC
	#define D3_PIN						Pin3

	#define D4_PORT						PortC
	#define D4_PIN						Pin4

	#define D5_PORT						PortC
	#define D5_PIN						Pin5

	#define D6_PORT						PortC
	#define D6_PIN						Pin6

	#define D7_PORT						PortC
	#define D7_PIN						Pin7

#elif LCD_MODE==FOUR_BIT

	#define D4_PORT						PortA
	#define D4_PIN						Pin3
	
	#define D5_PORT						PortA
	#define D5_PIN						Pin4
	
	#define D6_PORT						PortA
	#define D6_PIN						Pin5
	
	#define D7_PORT						PortA
	#define D7_PIN						Pin6

#endif
#endif

	
