/*
 * buttons.c
 *
 * Created: 2/24/2014 3:01:55 PM
 *  Author: Jake
 */ 

#include "main.h"

extern button last_button;

void button_init(uint32_t ul_id, Pio *p_pio, const uint32_t ul_mask, IRQn_Type IRQn, void (*p_handler) (uint32_t, uint32_t))
{
	pmc_enable_periph_clk(ul_id);
	pio_set_input(p_pio, ul_mask, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(p_pio, ul_mask, DEBOUNCE_FREQ);
	pio_handler_set(p_pio, ul_id, ul_mask, PIO_IT_FALL_EDGE, p_handler);
	pio_enable_interrupt(p_pio, ul_mask);
	NVIC_EnableIRQ(IRQn);
}

void onoff_handler(void)
{
	last_button = ONOFF;
	//printf("ONOFF\n");
}

void startpause_handler(void)
{
	last_button = STARTPAUSE;
	//printf("STARTPAUSE\n");
}

void advance_handler(void)
{
	last_button = ADVANCE;
	//printf("ADVANCE\n");
}