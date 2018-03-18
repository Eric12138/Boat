#include<stm32f4xx.h>
#include<led.h>
#include<delay.h>
#include<pwm.h>

int main()
{
	u16 led0pwmval=0;
	u8 dir=1;
	delay_init(168);
	LED_Init();
	TIM14_PWM_Init(500-1,84-1);
	while(1)
	{
		
	}
}
