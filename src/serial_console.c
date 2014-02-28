/*
 * serial_console.c
 *
 * Created: 2/24/2014 5:30:13 PM
 *  Author: Jake
 */ 

#include "main.h"

void serial_console_init(void)
{
	static usart_serial_options_t usart_options = {
		.baudrate = 9600,
		.charlength = 8,
		.paritytype = US_MR_PAR_NO,
		.stopbits = false
	};
	
	stdio_serial_init(CONSOLE_UART, &usart_options);
}