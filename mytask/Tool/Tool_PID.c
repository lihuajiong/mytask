

#include		"Tool_PID.h"

/**
* @brief	������pid�ṹ������
* @param 	pid��PID�ṹ��
* @return ��
* @author ���
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
* @brief	�趨����PID�㷨������ϵ��
* @param 	pid��PID�ṹ��
*					Kp,Ki,Kd:���������֣�΢��ϵ��
* @return ��
* @author ���
*/
void	PID_Base_Init(pid_base* pid,float Kp,float Ki,float Kd)
{
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kp = Kp;
}

/**
* @brief	�趨PID��Ŀ��ֵ��Ȼ�����Ŀǰֵ���ִ�еı���
* @param	pid��PID�ṹ��
*					Target:Ŀ��ֵ
*					Current����ǰֵ
* @return ���ִ�б���
* @author ���
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
* @brief	��pid�ṹ������
* @param 	pid��PID�ṹ��
* @return ��
* @author ���
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
* @brief	�趨PID�㷨������ϵ������ֵ
* @param 	pid��PID�ṹ��
*					Kp,Ki,Kd:���������֣�΢��ϵ��
* @return ��
* @author ���
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
	//�ж��趨��Ŀ��ֵ�Ƿ�������Χ��
	if((Target>pid->Target_max)||(Target<pid->Target_min))
	{
		return 0;
	}
	//Ŀǰƫ��ֵ
	pid->Err = Target - Current;
	//Ŀǰƫ��ܴ󣬿���ֱ��������ֵ������Сֵ
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
	//ƫ��Ƚϴ�����PD�㷨���ƣ����ǲ�������ֱ���
	if( (pid->Err > (-Err_mid) )&&(pid->Err < Err_mid ) )
	{
		pid->Out = pid->Kp*pid->Err + pid->Kd*(pid->Err - pid->Err_last);
		pid->Err_last = pid->Err;
		return 1;
	}
	//ƫ��ֵ��С��������ֿ��ƣ�ͬʱ�жϻ������Ƿ񱥺ͣ�����ﵽ���޻����ޣ���������ֻ�ӻ��
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





























