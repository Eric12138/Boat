#ifndef _PWM_H
#define _PWM_H
#include<sys.h>

void TIM3_PWM_Init(u16 arr,u16 psc);
void motor_control(u16 Speed);
void steering_engine_control(u16 Angle);

#endif
