/*
 * shift_registers.h
 *
 * Created: 2/25/2014 4:25:32 PM
 *  Author: Jake
 */ 

#include <asf.h>

#ifndef SHIFT_REGISTERS_H_
#define SHIFT_REGISTERS_H_

#define NUM_SHIFT_REG 3
#define NUM_SHIFT_REG_PINS NUM_SHIFT_REG * 8

#define RCLK_PIN_ID		PIO_PB26_IDX //for arduino due
#define SERCLK_PIN_ID	PIO_PA14_IDX	//for arduino due
#define SER_PIN_ID		PIO_PA15_IDX	//for arduino due

void shift_register_init(void);
void shift_register_clear(void);
void shift_register_output(void);
void toggle_LED(void);



#endif /* SHIFT_REGISTERS_H_ */