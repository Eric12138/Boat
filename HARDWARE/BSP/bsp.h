#ifndef	__BSP_H__
#define	__BSP_H__

#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "math.h"
#include "stdio.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "chassispid.h"
#include "timer.h"

#define LED0 						PCout(1) 
#define LED1 						PCout(0)	
#define BEEP 						PCout(2) 


typedef struct
{
	struct
	{
		int16_t  p1;
		int16_t  p2;
		int16_t  p3;
		int16_t  p4;
	}position;				//底盘电机返回的位置值	
	struct
	{
		int16_t  v1;
		int16_t  v2;
		int16_t  v3;
		int16_t  v4;
	}velocity;				//底盘电机返回的速度值	
	struct
	{
		int16_t  c1;
		int16_t  c2;
		int16_t  c3;
		int16_t  c4;
	}current;				//底盘电机输入电流值
	struct
	{
		int16_t  w1;
		int16_t  w2;
		int16_t  w3;
		int16_t  w4;
	} SetSpeed;				//底盘电机速度给定值
	struct
	{
		int16_t  VX;
		int16_t  VY;
		int16_t  W0;
		
	} component;			//底盘电机解算三分量
	struct
	{
		int16_t  I1;
		int16_t  I2;
		int16_t  I3;
		int16_t  I4;
	} CurrentFeedBack;		//底盘电机电流环反馈分量
} ChassisMotorMsg;

typedef struct
{
    struct
    {
        uint16_t ch0;
        uint16_t ch1;
        uint16_t ch2;
        uint16_t ch3;
        uint8_t s1;
        uint8_t s2;
    } rc;					//遥控器四个通道、两个拨码开关
    struct
    {
        int16_t x;
        int16_t y;
        int16_t z;
        uint8_t press_l;
        uint8_t press_r;
    } mouse;				//鼠标拖动三分量、左右键点击
    struct
    {
        uint16_t v;			
    } key;					//键盘按键
} RC_Ctl_t;

typedef struct
{
	float Kp;				//比例
	float Ki;				//积分
	float Kd;				//微分
	float error_now;		//本次误差
	float error_last;		//上次误差
	float error_last_last;	//上上次误差
	int16_t pid_out;		//PID输出
}Inc_PID;					//增量式PID

extern Inc_PID ChassisPID_1;
extern Inc_PID ChassisPID_2;
extern Inc_PID ChassisPID_3;
extern Inc_PID ChassisPID_4;
extern volatile unsigned char Dbus_rx_buffer[25];	//DBUS接收缓冲区
extern  RC_Ctl_t RC_Ctl;
extern ChassisMotorMsg ChassisMotor;
extern double CurrentSensor_I;						//电流传感器检测值

void bsp_Init(void);

#endif
