#include "bsp.h"

void bsp_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);
	LED_Init();
	TIM14_Init();
	TIM3_PWM_Init(2000-1,840-1);
	uart_init(115200);
	uart2_init(115200);
	Adc_Init();
	IWDG_Init(3,500);
	//BEEP_Init();
	//KEY_Init();
	Tx_Message[4] = 0x0d;
	Tx_Message[5] = 0x0a;
	USART_RX_STA = 0;
	TIM_SetCompare2(TIM3,Angle);
	
	//steering_engine_control(1850);
	
	//如果电机没有初始化，取消注释这段代码
	
	//TIM_SetCompare2(TIM3,1800);
	//delay_ms(2500);
	
	//TIM_SetCompare2(TIM3,2000);
	//delay_ms(1500);
	
}
