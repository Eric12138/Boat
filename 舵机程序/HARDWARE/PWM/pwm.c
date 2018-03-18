#include<pwm.h>
#include<sys.h>
#include<led.h>

void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        
	GPIO_Init(GPIOC,&GPIO_InitStructure);             			 	    	 //��ʼ��PC6
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        
	GPIO_Init(GPIOC,&GPIO_InitStructure);             			 	    	 //��ʼ��PC7
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM3);		    	 //�˿ڸ���ӳ��C6Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3);		    	 //�˿ڸ���ӳ��C7Ϊ��ʱ��3
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_Period=arr;   
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);									//��ʼ����ʱ��3
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;

	TIM_OC1Init(TIM3,&TIM_OCInitStructure);												//����OC1ͨ���ͼ�ʱ��3����pwm�Ƚ�ģʽ
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);												//����OC2ͨ���ͼ�ʱ��3����pwm�Ƚ�ģʽ
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);								//OC1ͨ����Ԥװ�ؼĴ�������--���˲������п��ޣ�
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//OC2ͨ����Ԥװ�ؼĴ�������--���˲������п��ޣ�
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);															//��ʱ��3��Ԥװ��ʹ��λ(ARPE)����--���˲������п��ޣ�
	
	TIM_Cmd(TIM3, ENABLE);  																				//ʹ��TIM3
}

void steering_engine_control()
{
	TIM_SetCompare1(TIM3,1850);
}

void motor_control()
{
	TIM_SetCompare2(TIM3,1850);
}
