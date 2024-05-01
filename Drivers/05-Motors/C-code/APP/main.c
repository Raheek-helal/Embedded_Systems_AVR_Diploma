/*
 * main.c
 *
 *  Created on: Feb 11, 2024
 *      Author: Raheek_Helal
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>


int main(void)
{
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);

	while(1)
	{
		MDIO_vSetPinVal(DIO_PORTA, DIO_PIN3, DIO_HIGH);
		_delay_ms(1000);
		MDIO_vSetPinVal(DIO_PORTA, DIO_PIN3, DIO_LOW);
		_delay_ms(1000);
	}
}
