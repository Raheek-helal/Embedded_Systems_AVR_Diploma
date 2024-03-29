/*
 * bit_math.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Raheek_Helal
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CLR_BIT(value,bit)value=value&~((0b00000001)<<bit)
#define SET_BIT(value,bit)value=value|((0b00000001)<<bit)
#define TOG_BIT(value,bit)value=value^((0b00000001)<<bit)
#define GET_BIT(value,bit)(value>>bit)&0b00000001


#endif /* BIT_MATH_H_ */
