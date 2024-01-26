/*
 * main.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Raheek_Helal
 */
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"

int main(void)
{


	while(1)
	{
		HLCD_vInit();
		/*HLCD_vSendChar('R');
		HLCD_vSendChar('a');
		HLCD_vSendChar('h');
		HLCD_vSendChar('e');
		HLCD_vSendChar('e');
		HLCD_vSendChar('k');
		HLCD_vSendCommand(LCD_CLEAR);*/
		/* HLCD_vPrintString("Raheek"); */
		u8 HEART[]= {0x00, 0x0A, 0x1F, 0x0E, 0x04, 0x00, 0X00};
		HLCD_vSaveCustomChar(1,HEART);
		HLCD_vSetCursorPosition(3,1);
		HLCD_vDisplyCustomChar(1);

	}
}

