/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "main.h"

	
//last button that was pressed
button last_button;

//the current state
state current_state;

//the current valve
uint8_t current_valve = 0;

int count = 0;

void RTT_Handler(void)
{
	count++;
	rtt_get_status(RTT);
}

int main (void)
{
	board_init();
	sysclk_init();
	serial_console_init();
	shift_register_init();

	
	//LED
	gpio_configure_pin(PIO_PB27_IDX,PIO_TYPE_PIO_OUTPUT_0);
	
	//set up the buttons
	button_init(ID_PIOA, PIOA, PIO_PA17, PIOA_IRQn, (void*) onoff_handler);
	button_init(ID_PIOA, PIOA, PIO_PA18, PIOA_IRQn, (void*) startpause_handler);
	button_init(ID_PIOA, PIOA, PIO_PA20, PIOA_IRQn, (void*) advance_handler);
	
	rtt_init(RTT, 16384);
	rtt_write_alarm_time(RTT, 5);
	rtt_enable_interrupt(RTT, RTT_MR_ALMIEN);
	
	while (1)
	{
		//update_state();
		//print_current_state();
		printf("%d\n", /*rtt_read_timer_value(RTT)*/count);
		delay_ms(500);
	}
}
