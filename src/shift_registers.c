/*
 * shift_registers.c
 *
 * Created: 2/25/2014 4:25:47 PM
 *  Author: Jake
 */ 
#include "main.h"

void shift_register_init(void)
{
	//RCLK
	gpio_configure_pin(PIO_PB2_IDX,PIO_TYPE_PIO_OUTPUT_0);
	//SERCLK
	gpio_configure_pin(PIO_PB0_IDX,PIO_TYPE_PIO_OUTPUT_0);
	//SER
	gpio_configure_pin(PIO_PB1_IDX,PIO_TYPE_PIO_OUTPUT_0);
}