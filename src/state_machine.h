/*
 * state_machine.h
 *
 * Created: 2/24/2014 6:18:54 PM
 *  Author: Jake
 */ 

#include <asf.h>


#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_


void update_state(void);
void advance_valve(void);
void print_current_state(void);


#endif /* STATE_MACHINE_H_ */