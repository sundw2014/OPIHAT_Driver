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

float voltage = 0, current = 0;
int16_t motors[4] = {0, 0, 0, 0}; // -3000 to 3000
uint16_t servos[8] = {1500, 1500, 1500, 1500}; // 1000 to 2000

uint32_t last_recv = 0;

#define CMD_LEN 2 * 4 + 2 * 8
uint8_t cmd_buff[CMD_LEN];
uint16_t rx_cnt = 0;

void parse_cmd(uint8_t *cmd){
    memcpy(motors, cmd, 2 * 4);
    memcpy(servos, cmd + 2 * 4, 2 * 8);
}

void communicate_recv(void)
{
    if(__HAL_UART_GET_FLAG(&huart5, UART_FLAG_RXNE) != RESET)
    {
        cmd_buff[rx_cnt++] = (uint16_t)((&huart5)->Instance->DR & (uint16_t)0x01FF);
        if(rx_cnt >= CMD_LEN) rx_cnt = 0;
    }

    if(__HAL_UART_GET_FLAG(&huart5, UART_FLAG_IDLE) != RESET)
    {
        uint8_t temp;
        temp = (&huart5)->Instance->SR;
		temp = (&huart5)->Instance->DR;
        rx_cnt = 0;
        last_recv = HAL_GetTick();
        parse_cmd(cmd_buff);
    }
}

void update_status(){
	printf("ck1\r\n");
    float voltage = get_bat_status_voltage();
	printf("ck2\r\n");
    float current = get_bat_status_current();
    printf("VBAT: %.2fV; CURRENT: %.2fA", voltage, current);
}
