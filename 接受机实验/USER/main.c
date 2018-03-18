#include<stm32f4xx.h>
#include<led.h>
#include<delay.h>
#include<usart.h>
#include<adc.h>
#include<usart2.h>
#include<24l01.h>
#include<spi.h>

const u8 TEXT_Buffer[]={"Explorer STM32F4 SPI TEST"};
#define SIZE sizeof(TEXT_Buffer)
	

int main()
{
	u8 key,mode;
	u16 t=0;			 
	u8 adc_buf[4];	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	//float adcx;																								//定义临时储存变量
	u16 adcx1, adcx2;
	float temp;
	u16 str=100;
	
	delay_init(168);
	uart_init(115200);
	
	uart2_init(115200);
	//Adc_Init();
	//NRF24L01_Init();    		//初始化NRF24L01 
	
	printf("%d\n",str);
	//NRF24L01_RX_Mode();
	USART_RX_STA = 0;
	while(1)
	{
		//NRF24L01_RxPacket(adc_buf);
			
		delay_ms(100);
		
		printf("\r\nass we can\r\n");
		
		if(USART_RX_STA&0x8000)
		{	
			printf("hello?");	//这个地方进不去
			if((USART_RX_STA & 0x3fff) == 0x0004)
			//len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n");
			{
				adcx1 = USART_RX_BUF[0]<<8 | USART_RX_BUF[1];
				adcx2 = USART_RX_BUF[2]<<8 | USART_RX_BUF[3];
				USART_RX_STA=0;
			}
		}
		
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp; 
		
		printf("adc1=%u\r\n",adcx1);
		printf("adc2=%u\r\n",adcx2);
		//printf("adc=%f\n",adcx);
			
		//NRF24L01_TX_Mode();
		//printf("ready");
		
		
		
		delay_ms(100);

	}
}
