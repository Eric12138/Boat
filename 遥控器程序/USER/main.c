#include<stm32f4xx.h>
#include<led.h>
#include<delay.h>
#include<usart.h>
#include<adc.h>

const u8 TEXT_Buffer[]={"Explorer STM32F4 SPI TEST"};
#define SIZE sizeof(TEXT_Buffer)
	

int main()
{
	u8 key,mode;
	u16 t=0;			 
	u8 adc_buf[6];	
	u8 len;	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	//float adcx;																								//定义临时储存变量
	u16 adcx1, adcx2;
	float temp;
	u16 str=100;
	
	adc_buf[4] =0x0d;
	adc_buf[5] =0x0a;
	
	delay_init(168);
	uart_init(115200);
	uart2_init(115200);
	Adc_Init();
	//NRF24L01_Init();    		//初始化NRF24L01 
	
	printf("%d\n",str);
	while(1)
	{
		adcx1=Get_Adc1_Average(ADC_Channel_5,20);								//将adc1的5通道的20次取样平均值赋给adcx
		adcx2=Get_Adc2_Average(ADC_Channel_4,20);	
		
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp; 
		//printf("adc1=%u\r\n",adcx1);
		//printf("adc2=%u\r\n",adcx2);
		//printf("adc=%f\n",adcx);
		
		adc_buf[0] = adcx1>>8;
		adc_buf[1] = adcx1 & 0xff;
		adc_buf[2] = adcx2>>8;
		adc_buf[3] = adcx2 & 0xff;
		
//		printf("adc0=%u\r\n",adc_buf[0]);
//		printf("adc1=%u\r\n",adc_buf[1]);
//		printf("adc2=%u\r\n",adc_buf[2]);
//		printf("adc3=%u\r\n",adc_buf[3]);
			//len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			
		for(t=0;t<6;t++)
		{
			USART_SendData(USART2, adc_buf[t]);         //向串口1发送数据
			//printf("before while");
			while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//等待发送结束
			//printf("after while");
		}
		//USART_RX_STA=0;
		//USART_RX_STA|=0x8000;	//接收完成了 
//			
//		printf("\r\n您发送的消息为:\r\n");
//		for(t=0;t<len;t++)
//		{
//			USART_SendData(USART1, USART_RX_BUF[t]);         //向串口1发送数据
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
//		}
//		printf("\r\n\r\n");//插入换行		
		
		led0 = ~led0;
		led1 = ~led1;
		
		delay_ms(200);

	}
}
