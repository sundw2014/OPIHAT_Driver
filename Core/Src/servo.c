#include "main.h"
#include "tim.h"
#include <stdio.h>

void set_servo_position(int servo_ID, uint16_t position){
  // positon: 1000 - 2000
  switch(servo_ID){
    case 0:
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, position);
      break;
    case 1:
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, position);
      break;
    case 2:
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, position);
      break;
    case 3:
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, position);
      break;
    case 4:
      __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, position);
      break;
    case 5:
      __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, position);
      break;
    case 6:
      __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, position);
      break;
    case 7:
      __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, position);
      break;
  }
}

void set_servos(uint16_t *servos){
//    printf("S: %d %d %d %d %d %d %d %d\r\n", servos[0], servos[1], servos[2], servos[3], servos[4], servos[5], servos[6], servos[7]);
    for(int i=0;i<8;i++){
        set_servo_position(i, servos[i]);
    }
}
