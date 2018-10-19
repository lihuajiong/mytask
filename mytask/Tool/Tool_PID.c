

#include		"Tool_PID.h"

/**
* @brief	将基类pid结构体清零
* @param 	pid：PID结构体
* @return 无
* @author 李华炯
*/
void	PID_Base_InitStruct(pid_base* pid)
{
	pid->Kp = 0;
	pid->Ki = 0;
	pid->Kp = 0;
	pid->Target = 0;
	pid->Current = 0;
	pid->Err = 0;
	pid->Err_last = 0;
	pid->Integral = 0;
	pid->Out = 0;
}
/**
* @brief	设定基类PID算法的三个系数
* @param 	pid：PID结构体
*					Kp,Ki,Kd:比例，积分，微分系数
* @return 无
* @author 李华炯
*/
void	PID_Base_Init(pid_base* pid,float Kp,float Ki,float Kd)
{
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kp = Kp;
}

/**
* @brief	设定PID的目标值，然后根据目前值输出执行的变量
* @param	pid：PID结构体
*					Target:目标值
*					Current：当前值
* @return 输出执行变量
* @author 李华炯
*/
float	PID_base_Set(pid_base* pid, float Target,float Current)
{
	pid->Target = Target;
	pid->Current = Current;
	pid->Err = pid->Target - pid->Current;
  pid->Integral += pid->Err;
  pid->Out = pid->Kp*pid->Err+pid->Ki*pid->Integral+pid->Kd*(pid->Err-pid->Err_last);
  pid->Err_last = pid->Err;

  return pid->Out;
}




/**
* @brief	将pid结构体清零
* @param 	pid：PID结构体
* @return 无
* @author 李华炯
*/
void	PID_InitStruct(PID* pid)
{
	pid->Kp = 0;
	pid->Ki = 0;
	pid->Kp = 0;
	pid->Target = 0;
	pid->Target_max = 0;
	pid->Target_min = 0;
	pid->Current = 0;
	pid->Err = 0;
	pid->Err_last = 0;
	pid->Integral = 0;
	pid->Inter_max = 0;
	pid->Inter_min = 0;
	pid->Out = 0;
}

/**
* @brief	设定PID算法的三个系数和阈值
* @param 	pid：PID结构体
*					Kp,Ki,Kd:比例，积分，微分系数
* @return 无
* @author 李华炯
*/
void	PID_Init(PID* pid,float Kp,float Ki,float Kd,float Target_max,float Target_min,float Inter_max,float Inter_min)
{
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kp = Kp;
	pid->Inter_max = Inter_max;
	pid->Inter_min = Inter_min;
	pid->Target_max = Target_max;
	pid->Target_min = Target_min;
}



uint8_t PID_Set(PID* pid,float Target,float Err_max,float Err_min,float Err_mid,float Err_miss,float Current)
{
	//判断设定的目标值是否在允许范围内
	if((Target>pid->Target_max)||(Target<pid->Target_min))
	{
		return 0;
	}
	//目前偏差值
	pid->Err = Target - Current;
	//目前偏差很大，可以直接输出最大值或者最小值
	if(pid->Err > Err_max)
	{
		pid->Out = out_max;
		pid->Err_last = pid->Err;
		return 1;
	}
	if( pid->Err < (-Err_max) )
	{
		pid->Out = out_min;
		pid->Err_last = pid->Err;
		return 1;
	}
	//偏差比较大，引入PD算法控制，但是不引入积分变量
	if( (pid->Err > (-Err_mid) )&&(pid->Err < Err_mid ) )
	{
		pid->Out = pid->Kp*pid->Err + pid->Kd*(pid->Err - pid->Err_last);
		pid->Err_last = pid->Err;
		return 1;
	}
	//偏差值较小，加入积分控制，同时判断积分量是否饱和，如果达到上限或下限，积分量就只加或减
	else
	{
		if(pid->Integral>pid->Inter_max)
		{
			if(pid->Err<0)
			{
				pid->Integral += pid->Err;
			}
			pid->Out = pid->Kp*pid->Err + pid->Ki*pid->Integral + pid->Kd*(pid->Err - pid->Err_last);
			pid->Err_last = pid->Err;
			return 1;
		}
		if(pid->Integral<pid->Inter_min)
		{
			if(pid->Err>0)
			{
				pid->Integral += pid->Err;
			}
			pid->Out = pid->Kp*pid->Err + pid->Ki*pid->Integral + pid->Kd*(pid->Err - pid->Err_last);
			pid->Err_last = pid->Err;
			return 1;
		}
	}
	return 1;
}





























