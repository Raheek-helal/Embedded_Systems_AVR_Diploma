/*
 * LCD_prg.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Raheek_Helal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"

void HLCD_vSendCommand(u8 A_u8Command)
{
	MDIO_vSetPinVal (LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW); //RS -> LOW
	MDIO_vSetPinVal (LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW); //RW -> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Command);

	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH); //EN Pulse Sequence
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);  //EN Pulse Sequence
	_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char)
{
	MDIO_vSetPinVal (LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH); //RS -> HIGH
	MDIO_vSetPinVal (LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);  //RW -> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);

	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);  //EN Pulse Sequence
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);   //EN Pulse Sequence
	_delay_ms(1);
}

void HLCD_vInit(void)
{
	/*set your pin directions*/
	MDIO_vSetPortDir(LCD_DATA_PORT, 0XFF);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);
	/*start init sequence*/
	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);
	_delay_ms(1);

}

void HLCD_vPrintString(char A_s8String[])
{
	for(u8 L_u8i = 0; A_s8String[L_u8i] != '\0'; L_u8i++)
	{
		HLCD_vSendChar(A_s8String[L_u8i]);
	}
}

void HLCD_vPringNumber(s32 A_s32Number)
{
	u8 L_u8Digits[10] = {0};
	u8 L_u8Counter = 0;
	/* TODO: Implement negative number handling  */
	/* TODO: Implement Zero in units corner case */

	while(A_s32Number > 0)
	{
		L_u8Digits[L_u8Counter] = A_s32Number%10;
		L_u8Counter++;
		A_s32Number /= 10;
	}
	/* print array in reverse */
	for(s8 L_s8PrintIndex=0; L_s8PrintIndex >= 0; L_s8PrintIndex--)
	{
		HLCD_vSendChar('0' + L_u8Digits[L_s8PrintIndex]);
	}
}

void HLCD_vSetCursorPosition(u8 A_u8LinePos, u8 A_u8LineNo)
{
	switch(A_u8LineNo)
	{
	case LCD_LINE0:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 0);
		break;
	case LCD_LINE1:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 64);
		break;
	}
}

void HLCD_vSaveCustomChar(u8 A_u8CgramIndex, u8 A_u8CustomCharData[])
{
	/* set CGRAM address */
	HLCD_vSendCommand(0b01000000 + (A_u8CgramIndex * 8));
	/* set custom char data */
	for(u8 L_u8Idx = 0; L_u8Idx < 8; L_u8Idx++)
	{
		HLCD_vSendChar(A_u8CustomCharData[L_u8Idx]);
	}
	/* set DDRAM address */
	HLCD_vSendCommand(0x80);
}

void HLCD_vDisplyCustomChar(u8 A_u8CgramIndex)
{
	if(A_u8CgramIndex < 8)
	HLCD_vSendChar(A_u8CgramIndex);
}



