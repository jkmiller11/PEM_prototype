/*
 * state_machine.c
 *
 * Created: 2/24/2014 6:19:43 PM
 *  Author: Jake
 */ 

#include "main.h"

extern button last_button;
extern state current_state;
extern uint8_t current_valve;

void update_state(void) {
	switch (current_state)
	{
	case OFF:
		if (last_button == ONOFF)
		{
			current_state = PAUSED;
		}
		break;
	case PAUSED:
		if (last_button ==  ONOFF)
		{
			current_state = OFF;
		}
		else if (last_button == STARTPAUSE)
		{
			current_state = RUNNING;
		}
		else if (last_button == ADVANCE)
		{
			advance_valve();
		}
		break;
	case RUNNING:
		if (last_button == ONOFF)
		{
			current_state = OFF;
		}
		else if (last_button == STARTPAUSE)
		{
			current_state = PAUSED;
		}
		else if (last_button == ADVANCE)
		{
			advance_valve();
		}
		break;
	}
	last_button = NONE;
}

void advance_valve(void)
{
	if (current_valve < 7)
	{
		current_valve++;
	}
}

void print_current_state(void)
{
	switch (current_state)
	{
	case OFF:
		printf("OFF\n");
		break;
	case PAUSED:
		printf("PAUSED\n");
		break;
	case RUNNING:
		printf("RUNNING\n");
		break;
	}
}