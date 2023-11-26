/*function send command*/
void HLCD_vSendCommand(u8 A_u8Cmd)
{
	/* control RS and RW Pins */
	MDIO_vSetPinValue('A',0,0);
	MDIO_vSetPinValue('A',1,0);
	
	/* write command on the data pins   */
	MDIO_vPORTValue('D',A_u8Cmd);
	
	/* pulse on the enable pin */
	
}

/*function send data*/
void HLCD_vSendData(u8 A_u8Data)
{
	
}