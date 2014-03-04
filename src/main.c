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

void RTT_Handler(void)
{
	//rtt_disable_interrupt(RTT, RTT_MR_RTTINCIEN);
	rtt_get_status(RTT);
	//count++;
	//printf("%d\n", count);
	if (current_state == PAUSED)
	{
		gpio_toggle_pin(PIO_PB27_IDX);
	}
	//rtt_enable_interrupt(RTT, RTT_MR_RTTINCIEN);
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
	button_init(ID_PIOA, PIOA, PIO_PA17, PIOA_IRQn, (void*) onoff_handler);//arduino sda1
	button_init(ID_PIOA, PIOA, PIO_PA18, PIOA_IRQn, (void*) startpause_handler);//arduino scl1
	button_init(ID_PIOA, PIOA, PIO_PA20, PIOA_IRQn, (void*) advance_handler);//arduino pin 43
	
	rtt_disable_interrupt(RTT, RTT_MR_RTTINCIEN);
	rtt_init(RTT, 16384);
	rtt_enable_interrupt(RTT, RTT_MR_RTTINCIEN);
	NVIC_EnableIRQ(RTT_IRQn);
	
	while (1)
	{
		//update_state();
		print_current_state();
		//printf("%d\n", /*rtt_read_timer_value(RTT)*/count);
		delay_ms(100);
	}
}
