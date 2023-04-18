#include "main.h"
#include "tim.h"
#include <stdio.h>

void set_servo_position(int servo_ID, uint16_t position){
  // positon: 1000 - 2000
  switch(servo_ID){
    case 0:
      (&htim4)->Instance->CCR1 = position;
      break;
    case 1:
      (&htim4)->Instance->CCR2 = position;
      break;
    case 2:
      (&htim4)->Instance->CCR3 = position;
      break;
    case 3:
      (&htim4)->Instance->CCR4 = position;
      break;
    case 4:
      (&htim1)->Instance->CCR4 = position;
      break;
    case 5:
      (&htim1)->Instance->CCR3 = position;
      break;
    case 6:
      (&htim1)->Instance->CCR2 = position;
      break;
    case 7:
      (&htim1)->Instance->CCR1 = position;
      break;
  }
}

void set_servos(uint16_t *servos){
    printf("S: %d %d %d %d %d %d %d %d\r\n", servos[0], servos[1], servos[2], servos[3], servos[4], servos[5], servos[6], servos[7]);
    for(int i=0;i<8;i++){
        set_servo_position(i, servos[i]);
    }
}
