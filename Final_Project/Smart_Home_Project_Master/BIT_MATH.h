#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

	#define SET_BIT(REG,BIT) REG=REG|(1<<BIT)
	#define CLR_BIT(REG,BIT) REG=REG&(~(1<<BIT))
	#define TGL_BIT(REG,BIT) REG=REG^(1<<BIT)
	#define GET_BIT(REG,BIT) (REG>>BIT)&1
 
 
#endif