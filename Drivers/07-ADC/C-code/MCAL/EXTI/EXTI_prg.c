/*
 * EXTI_prg.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Raheek_Helal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <avr/io.h>

#include "EXTI_int.h"
#include "EXTI_cfg.h"



void MEXTI_vInit(void)
{
	/* 1- Sense control */
	//Falling Edge for INT0
	SET_BIT(MCUCR, 3);
	CLR_BIT(MCUCR, 2);

	/* 2- Enable interrupt */
	SET_BIT(GICR, 6);       //Enable INT0

}







