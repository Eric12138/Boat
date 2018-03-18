#ifndef _PWM_H
#define _PWM_H
#include<sys.h>

void TIM3_PWM_Init(u16 arr,u16 psc);
void steering_engine_control(void);
void motor_control(void);

#endif
