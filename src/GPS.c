/*
 * GPS.c
 *
 * Created: 3/25/2014 2:23:17 PM
 *  Author: Jake
 */ 

#include "main.h"

void gps_init(void)
{
	sysclk_init();

	static usart_serial_options_t usart_options = {
		.baudrate = GPS_SERIAL_BAUDRATE,
		.charlength = GPS_SERIAL_CHAR_LENGTH,
		.paritytype = GPS_SERIAL_PARITY,
		.stopbits = GPS_SERIAL_STOP_BIT
	};

	usart_serial_init(GPS_SERIAL, &usart_options);
}

void gps_encode(void)
{
	
}