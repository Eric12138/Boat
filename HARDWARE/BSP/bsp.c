#include "bsp.h"

void bsp_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	USART1_Init(115200);	//串口初始化波特率为115200
	LED_Init();
	CAN1_Init();
	Dbus_Init();
	TIM14_Init();
	TIM13_Init();
	Adc_Init();

}
