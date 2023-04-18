/*
 * communicate.cpp
 *
 *  Created on: Mar 6, 2023
 *      Author: sundw
 */

#include "main.h"
#include "usart.h"
#include "battery_monitor.h"
#include "string.h"
#include "stdio.h"

int16_t motors[4] = {0, 0, 0, 0}; // -3000 to 3000
uint16_t servos[8] = {1500, 1500, 1500, 1500}; // 1000 to 2000

uint32_t last_recv = 0;

#define CMD_LEN 2 * 4 + 2 * 8
uint8_t cmd_buff[CMD_LEN];

void start_cmd_receive(){
	HAL_UARTEx_ReceiveToIdle_IT(&huart5, cmd_buff, CMD_LEN);
}

void parse_cmd(uint8_t *cmd){
    memcpy(motors, cmd, 2 * 4);
    memcpy(servos, cmd + 2 * 4, 2 * 8);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
	if(Size == CMD_LEN){
		parse_cmd(cmd_buff);
	}
    last_recv = HAL_GetTick();
    start_cmd_receive();
}

void update_status(){
    printf("VBAT: %.2fV; CURRENT: %.2fA\r\n", get_bat_status_voltage(), get_bat_status_current());
}
