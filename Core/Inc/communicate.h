/*
 * communicate.h
 *
 *  Created on: Mar 6, 2023
 *      Author: sundw
 */

#ifndef INC_COMMUNICATE_H_
#define INC_COMMUNICATE_H_

#include "main.h"

void update_status(void);
void communicate_recv(void);

extern uint16_t voltage; // 0 to 65535
extern int16_t motors[4]; // -3000 to 3000
extern uint16_t servos[8]; // 1000 to 2000
extern uint32_t last_recv;

#endif /* INC_COMMUNICATE_H_ */
