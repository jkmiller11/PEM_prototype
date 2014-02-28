/*
 * buttons.h
 *
 * Created: 2/24/2014 3:02:16 PM
 *  Author: Jake
 */ 

#include <asf.h>

#ifndef BUTTONS_H_
#define BUTTONS_H_

//cutoff frequency for button debouncing
#define DEBOUNCE_FREQ 20

void button_init(uint32_t ul_id, Pio *p_pio, const uint32_t ul_mask, IRQn_Type IRQn, void (*p_handler) (uint32_t, uint32_t));

void onoff_handler(void);
void startpause_handler(void);
void advance_handler(void);


#endif /* BUTTONS_H_ */