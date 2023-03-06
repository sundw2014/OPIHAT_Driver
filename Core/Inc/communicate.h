/*
 * communicate.h
 *
 *  Created on: Mar 6, 2023
 *      Author: sundw
 */

#ifndef INC_COMMUNICATE_H_
#define INC_COMMUNICATE_H_

#include "main.h"

void update_state(void);
void communicate_recv(void);

extern u16 voltage; // 0 to 65535
extern s16 motors[4]; // -3000 to 3000
extern u16 servos[8]; // 1000 to 2000
extern u32 last_recv;

#endif /* INC_COMMUNICATE_H_ */
