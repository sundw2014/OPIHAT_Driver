/*
 * communicate.cpp
 *
 *  Created on: Mar 6, 2023
 *      Author: sundw
 */

#include "main.h"

u16 voltage = 0; // 0 to 65535
s16 motors[4] = {0, 0, 0, 0}; // -3000 to 3000
u16 servos[8] = {1500, 1500, 1500, 1500}; // 1000 to 2000

u32 last_recv = 0;

#define CMD_LEN 2 * 4 + 2 * 8
u8 cmd_buff[CMD_LEN];
u16 rx_cnt = 0;

void parse_cmd(u8 *cmd){
    memcpy(motors, cmd, 2 * 4);
    memcpy(servos, cmd + 2 * 4, 2 * 8);
}

void communicate_recv(void)
{
    uint8_t temp;
    if(__HAL_UART_GET_FLAG(&huart5, UART_FLAG_RXNE) != RESET)
    {
        cmd_buff[rx_cnt++] = USART_ReceiveData(UART5);
        if(rx_cnt >= CMD_LEN) rx_cnt = 0;
    }

    if(USART_GetITStatus(UART5, USART_IT_IDLE) != RESET)
    {
		temp = &huart5->Instance->SR;
		temp = &huart5->Instance->DR;
        rx_cnt = 0;
        last_recv = time();
        parse_cmd(cmd_buff);
    }
}

void update_state(){
    USART_printf(UART5, "VBAT: %d", voltage);
}
