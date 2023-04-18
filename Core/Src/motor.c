#include "main.h"
#include "tim.h"
#include <stdio.h>

void set_motor_speed(int motor_ID, int16_t speed){
  GPIO_PinState IN1, IN2;
  if(speed > 0){
    IN1 = GPIO_PIN_SET;
    IN2 = GPIO_PIN_RESET;
  }
  else{
    IN1 = GPIO_PIN_RESET;
    IN2 = GPIO_PIN_SET;
  }
  switch(motor_ID){
    case 1:
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, IN1);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, IN2);
      (&htim2)->Instance->CCR1 = ABS(speed);
      break;
    case 2:
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, IN1);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, IN2);
      (&htim2)->Instance->CCR2 = ABS(speed);
      break;
    case 3:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, IN1);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, IN2);
      (&htim2)->Instance->CCR3 = ABS(speed);
      break;
    case 4:
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, IN1);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, IN2);
      (&htim2)->Instance->CCR4 = ABS(speed);
      break;
  }
}

void set_motors(int16_t *motors){
    printf("M: %d %d %d %d\r\n", motors[0], motors[1], motors[2], motors[3]);
    for(int i=0;i<4;i++){
        set_motor_speed(i, motors[i]);
    }
}
