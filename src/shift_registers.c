/*
 * shift_registers.c
 *
 * Created: 2/25/2014 4:25:47 PM
 *  Author: Jake
 */ 
#include "main.h"

bool registers[NUM_SHIFT_REG_PINS];
extern uint8_t current_valve;

void shift_register_init(void)
{
	//RCLK
	gpio_configure_pin(RCLK_PIN_ID,PIO_TYPE_PIO_OUTPUT_0);
	//SERCLK
	gpio_configure_pin(SERCLK_PIN_ID,PIO_TYPE_PIO_OUTPUT_0);
	//SER
	gpio_configure_pin(SER_PIN_ID,PIO_TYPE_PIO_OUTPUT_0);
	
	//initialize registers
	shift_register_clear();
}

void shift_register_clear(void)
{
	for (int i = 0; i < sizeof(registers)/sizeof(bool); i++)
	{
		registers[i] = false;
	}
}

void shift_register_output(void)
{
	gpio_set_pin_low(RCLK_PIN_ID);
	for (int i = 0; i < NUM_SHIFT_REG_PINS; i++)
	{
		gpio_set_pin_low(SERCLK_PIN_ID);
		int val = registers[i];
		if (val == true)
		{
			gpio_set_pin_high(SER_PIN_ID);
		}
		else
		{
			gpio_set_pin_low(SER_PIN_ID);
		}
		gpio_set_pin_high(SERCLK_PIN_ID);
	}
	gpio_set_pin_high(RCLK_PIN_ID);
	delay_us(100);
}

void toggle_LED(void)
{
	uint8_t current_LED = 8 + current_valve;
	if (registers[current_LED] == true)
	{
		registers[current_LED] = false;
	}
	else
	{
		registers[current_LED] = true;
	}
	shift_register_output();
}