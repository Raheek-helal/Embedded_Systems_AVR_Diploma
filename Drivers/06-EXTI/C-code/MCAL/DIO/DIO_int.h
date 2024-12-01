/*
 * DIO_init.h
 *
 *  Created on: Nov 23, 2023
 *      Author: Raheek_Helal
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

/*MACROS FOR PORTS*/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

/*MACROS FOR PINS*/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

/*MACROS FOR DIRECTIONS*/
#define DIO_OUTPUT 1
#define DIO_INPUT  0

/*MACROS FOR VALUS*/
#define DIO_HIGH   1
#define DIO_LOW    0

/*Pin Functions*/
void MDIO_vSetPinDir  ( u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8Dir );
void MDIO_vSetPinVal  ( u8 A_u8PortNo, u8 A_u8PinNo, u8 Au8Val );
u8   MDIO_u8GetPinVal ( u8 A_u8PortNo, u8 A_u8PinNo );
/*Port Functions*/
void MDIO_vSetPortDir ( u8 A_u8PortNo, u8 A_u8Dir );
void MDIO_vSetPortVal ( u8 A_u8PortNo, u8 Au8Val );
u8   MDIO_GetPortVal  ( u8 A_u8PortNo );

void MDIO_vTogPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

#endif /* MCAL_DIO_DIO_INT_H_ */
