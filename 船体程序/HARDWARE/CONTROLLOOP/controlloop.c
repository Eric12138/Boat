#include "bsp.h"

void ControlLoop(void)
{

	if(URX >= 1)
	{		
		//解算数据为速度和角度
		Speed = 1830- (URX - 2048) / 40;
		Angle = 1832 + (URY - 2048) / 20;
		

		TIM_SetCompare1(TIM3,Speed);										//设置计时器14里的值和led0pwmval比较
		TIM_SetCompare2(TIM3,Angle);
	}
//	else
//	{
//		TIM_SetCompare1(TIM3,1850);										//设置计时器14里的值和led0pwmval比较
//		TIM_SetCompare2(TIM3,1850);
//	
//	}
	
	
	//printf("Speed=%u\r\n",Speed);
	//printf("Angle=%u\r\n",Angle);
	//如果舵机方向反了，就把上面一行注释了，使用下面一行
	//Angle = 1850 - (URY - 2048) / 20;
	
	//发送数据
	//motor_control(Speed);
	//steering_engine_control(Angle);
		
	//TIM_SetCompare2(TIM3,1850);
	//TIM_SetCompare1(TIM3,1850);
	//motor_control(1850);
	//steering_engine_control(1950);
	
	
	
	
		//static u8 dir=1;
//	if(USART_RX_STA&0x8000)			//接受数据
//		{	
//			if((USART_RX_STA & 0x3fff) == 0x0004)
//			{
//				URX = USART_RX_BUF[0]<<8 | USART_RX_BUF[1];
//				URY = USART_RX_BUF[2]<<8 | USART_RX_BUF[3];
//				USART_RX_STA=0;
//			}
//		}
		
	//printf("URX=%u\r\n",URX);
	//printf("URY=%u\r\n",URY);
}
