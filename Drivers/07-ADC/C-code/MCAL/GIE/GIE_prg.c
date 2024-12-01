/*
 * GIE_prg.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Raheek_Helal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <avr/io.h>

#include "GIE_int.h"





void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, 7);
}
void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, 7);
}







