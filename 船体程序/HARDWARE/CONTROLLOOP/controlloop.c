#include "bsp.h"

void ControlLoop(void)
{

	if(URX >= 1)
	{		
		//��������Ϊ�ٶȺͽǶ�
		Speed = 1830- (URX - 2048) / 40;
		Angle = 1832 + (URY - 2048) / 20;
		

		TIM_SetCompare1(TIM3,Speed);										//���ü�ʱ��14���ֵ��led0pwmval�Ƚ�
		TIM_SetCompare2(TIM3,Angle);
	}
//	else
//	{
//		TIM_SetCompare1(TIM3,1850);										//���ü�ʱ��14���ֵ��led0pwmval�Ƚ�
//		TIM_SetCompare2(TIM3,1850);
//	
//	}
	
	
	//printf("Speed=%u\r\n",Speed);
	//printf("Angle=%u\r\n",Angle);
	//�����������ˣ��Ͱ�����һ��ע���ˣ�ʹ������һ��
	//Angle = 1850 - (URY - 2048) / 20;
	
	//��������
	//motor_control(Speed);
	//steering_engine_control(Angle);
		
	//TIM_SetCompare2(TIM3,1850);
	//TIM_SetCompare1(TIM3,1850);
	//motor_control(1850);
	//steering_engine_control(1950);
	
	
	
	
		//static u8 dir=1;
//	if(USART_RX_STA&0x8000)			//��������
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
