#include<stm32f4xx.h>
#include<led.h>
#include<delay.h>
#include<pwm.h>

int main()
{
	u16 led0pwmval=1800;
	u8 dir=1;
	delay_init(168);
	LED_Init();
	TIM3_PWM_Init(2000-1,840-1);
	
	//TIM_SetCompare1(TIM3,1800);
	//delay_ms(2000);
	
	//TIM_SetCompare1(TIM3,2000);
	//delay_ms(1000);
	
	
	
	
	
	
	while(1)
	{
		
		if(dir)
		{
			led0pwmval++;
		}
		else
		{
			led0pwmval--;
		}
		
		if(led0pwmval>1900)
		{
			dir=0;
		}
		if(led0pwmval==1800)
		{
			dir=1;
		}																											//����led0pwmvalѭ�������仯
		
		TIM_SetCompare1(TIM3,led0pwmval);										//���ü�ʱ��14���ֵ��led0pwmval�Ƚ�
		TIM_SetCompare2(TIM3,led0pwmval*5-1800*4);
		delay_ms(100);
	}
	
}
