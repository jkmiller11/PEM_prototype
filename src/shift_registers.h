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

void shift_register_init(void);



#endif /* SHIFT_REGISTERS_H_ */