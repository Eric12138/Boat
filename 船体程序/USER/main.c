#include<stm32f4xx.h>
#include<led.h>
#include<delay.h>
#include<bsp.h>

int main()
{
	u8 dir=1;
	u16 led0pwmval=1850;
	u16 start = 0;
	int j = 0;
	
	int receive_message_number = 0;
	u8 communication_state_flag = 0;
	/*
	u16 pre_URX = 0;
	u16 pre_pre_URX = 1;
	u16 pre_pre_pre_URX = 2;
	u16 pre_pre_pre_pre_URX = 3;
	u16 pre_pre_pre_pre_pre_URX = 4;
	u16 pre_pre_pre_pre_pre_pre_URX = 5;
	u16 pre_pre_pre_pre_pre_pre_pre_URX = 6;
//	u16 pre_URX = 0;
//	u16 pre_URX = 0;
//	u16 pre_URX = 0;
	*/
	bsp_Init();
	printf("ready?");
//	for(j = 0; j < 100; j++)
//	{
//		TIM_SetCompare2(TIM3,1850);
//		delay_ms(50);
//	}
//	
	while(1)
	{
		//while(1)
		//{
			//TIM_SetCompare2(TIM3,1850);
		//}
		if(USART_RX_STA&0x8000)			//��������
		{	
			if((USART_RX_STA & 0x3fff) == 0x0004)
			{
				URX = USART_RX_BUF[0]<<8 | USART_RX_BUF[1];
				URY = USART_RX_BUF[2]<<8 | USART_RX_BUF[3];
				USART_RX_STA=0;
			}
		}
		//printf("URX=%u\r\n",URX);
		//printf("URY=%u\r\n",URY);
		
		//TIM_SetCompare1(TIM3,1850);	

		//��ʼ��ֹͨ���ܷɣ�ʹ�ÿ��Ź�
		/*
		switch (receive_message_number)
		{
			case 0:
				pre_pre_pre_URX = URX;
				break;
			
			case 1:
				pre_pre_URX = URX;
				break;
			
			case 2:
				pre_URX = URX;
				break;
			
			case 3:
				pre_pre_pre_URX = URX;
				break;
			
			case 4:
				pre_pre_pre_pre_URX = URX;
				break;
			
			case 5:
				pre_pre_pre_pre_pre_URX = URX;
				break;
			
			case 6:
				pre_pre_pre_pre_pre_pre_URX = URX;
				break;
			
			case 7:
				pre_pre_pre_pre_pre_pre_pre_URX = URX;
				break;
			
		}
		
		
		printf("pre_pre_pre_URX=%u\r\n",pre_pre_pre_URX);
		printf("pre_pre_URX=%u\r\n",pre_pre_URX);
		printf("pre_URX=%u\r\n",pre_URX);
		
		receive_message_number ++;
		
		if(receive_message_number >= 8)
		{
			receive_message_number = 0;
		}
		
		if((pre_URX == pre_pre_URX) && (pre_pre_URX = pre_pre_pre_URX) && (pre_pre_pre_URX == pre_pre_pre_pre_URX) && (pre_pre_pre_pre_URX == pre_pre_pre_pre_pre_URX) && (pre_pre_pre_pre_pre_URX == pre_pre_pre_pre_pre_pre_URX) && (pre_pre_pre_pre_pre_pre_URX == pre_pre_pre_pre_pre_pre_pre_URX))		//���һֱ���ܵ���ͬ���ݣ�flag����Ϊ1
		{
			
			printf("did i do it?\r\n");
			communication_state_flag = 0;
		}
		else
		{
			printf("all function goes well\r\n");
			communication_state_flag = 1;
		}
		*/
		j ++;
		
		//printf("communication_state_flag=%u\r\n",communication_state_flag);
		//���ݱ�־λ���ж��Ƿ�ι��
		if(j <= 30)
		{
			IWDG_ReloadCounter();
		}
		
		led0 = ~led0;
		led1 = ~led1;
		delay_ms(30);
	}
}
