/*
 * main.h
 *
 * Created: 2/24/2014 6:08:06 PM
 *  Author: Jake
 */ 


#ifndef MAIN_H_
#define MAIN_H_


#include "buttons.h"
#include "serial_console.h"
#include "state_machine.h"
#include "shift_registers.h"

enum myButton {NONE, ONOFF, STARTPAUSE, ADVANCE};
typedef enum myButton button;

enum myState {OFF, PAUSED, RUNNING};
typedef enum myState state;




#endif /* MAIN_H_ */