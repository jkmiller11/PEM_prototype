/*
 * GPS.h
 *
 * Created: 3/25/2014 2:23:33 PM
 *  Author: Jake
 */ 

#include <asf.h>

#ifndef GPS_H_
#define GPS_H_

#define GPS_SERIAL				USART0
#define GPS_SERIAL_ID			ID_USART0	
#define GPS_SERIAL_BAUDRATE		9600
#define GPS_SERIAL_CHAR_LENGTH	US_MR_CHRL_8_BIT
#define GPS_SERIAL_PARITY		US_MR_PAR_NO
#define GPS_SERIAL_STOP_BIT		US_MR_NBSTOP_1_BIT

void gps_init(void);
void gps_encode(void);




#endif /* GPS_H_ */