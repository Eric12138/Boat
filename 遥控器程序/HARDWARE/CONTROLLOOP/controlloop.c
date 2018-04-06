#include "bsp.h"

void ControlLoop(void)
{
//	ChassisMotor.component.VX = (RC_Ctl.rc.ch2-1024)*10;
//	ChassisMotor.component.VY = -(RC_Ctl.rc.ch3-1024)*10;
//	ChassisMotor.component.W0 = (RC_Ctl.rc.ch0-1024)*10;
/*	
	Speed_Solving(ChassisMotor.component.VX,ChassisMotor.component.VY,ChassisMotor.component.W0);
	
	ChassisMotor.current.c1 += ChassisIncPID_1(ChassisMotor.velocity.v1,ChassisMotor.SetSpeed.w1);
	ChassisMotor.current.c2 += ChassisIncPID_2(ChassisMotor.velocity.v2,ChassisMotor.SetSpeed.w2);
	ChassisMotor.current.c3 += ChassisIncPID_3(ChassisMotor.velocity.v3,ChassisMotor.SetSpeed.w3);
	ChassisMotor.current.c4 += ChassisIncPID_4(ChassisMotor.velocity.v4,ChassisMotor.SetSpeed.w4);
	
	if(CurrentSensor_I <= Imin)
	{ 
		ChassisMotor.CurrentFeedBack.I1 = (int16_t)((CurrentSensor_I - Imin) * coefficient * ChassisMotor.current.c1);
		ChassisMotor.CurrentFeedBack.I2 = (int16_t)((CurrentSensor_I - Imin) * coefficient * ChassisMotor.current.c2);
		ChassisMotor.CurrentFeedBack.I3 = (int16_t)((CurrentSensor_I - Imin) * coefficient * ChassisMotor.current.c3);
		ChassisMotor.CurrentFeedBack.I4 = (int16_t)((CurrentSensor_I - Imin) * coefficient * ChassisMotor.current.c4);

	}
	else if(CurrentSensor_I >= Imax)
	{ 
		ChassisMotor.CurrentFeedBack.I1 = -(int16_t)((CurrentSensor_I - Imax) * coefficient * ChassisMotor.current.c1);
		ChassisMotor.CurrentFeedBack.I2 = -(int16_t)((CurrentSensor_I - Imax) * coefficient * ChassisMotor.current.c2);
		ChassisMotor.CurrentFeedBack.I3 = -(int16_t)((CurrentSensor_I - Imax) * coefficient * ChassisMotor.current.c3);
		ChassisMotor.CurrentFeedBack.I4 = -(int16_t)((CurrentSensor_I - Imax) * coefficient * ChassisMotor.current.c4);
	}
	else
	{
		ChassisMotor.CurrentFeedBack.I1 = 0;
		ChassisMotor.CurrentFeedBack.I2 = 0;
		ChassisMotor.CurrentFeedBack.I3 = 0;
		ChassisMotor.CurrentFeedBack.I4 = 0;
	}
	
	ChassisMotor.current.c1 = ChassisCurrentLimit(ChassisMotor.current.c1) + ChassisMotor.CurrentFeedBack.I1;
	ChassisMotor.current.c2 = ChassisCurrentLimit(ChassisMotor.current.c2) + ChassisMotor.CurrentFeedBack.I2;
	ChassisMotor.current.c3 = ChassisCurrentLimit(ChassisMotor.current.c3) + ChassisMotor.CurrentFeedBack.I3;
	ChassisMotor.current.c4 = ChassisCurrentLimit(ChassisMotor.current.c4) + ChassisMotor.CurrentFeedBack.I4;
	
	Set_Current(ChassisMotor.current.c1,ChassisMotor.current.c2,ChassisMotor.current.c3,ChassisMotor.current.c4);
	
*/
}
