
#ifndef			_TOOL_PID_H_
#define			_TOOL_PID_H_

#include		"stm32f10x.h"
#include		<math.h>

//基类pid算法结构体定义
typedef struct 
{
    float Target ;            		//定义目标值
    float Current;        				//定义实际值
    float Err;                		//定义偏差值
    float Err_last;            		//定义上一个偏差值
    float Kp,Ki,Kd;            		//定义比例、积分、微分系数
    float Out;          					//定义输出值（控制执行器的变量）
    float Integral;            		//定义积分值
}pid_base;

void	PID_Base_Init(pid_base* pid,float Kp,float Ki,float Kd);
float	PID_base_Set(pid_base* pid, float Target,float Current);


typedef struct
{
    float Target ;            		//定义目标值
		float Target_max;							//定义目标最大值
		float	Target_min;							//定义目标最小值
    float Current;        				//定义实际值
    float Err;                		//定义偏差值
    float Err_last;            		//定义上一个偏差值
    float Kp,Ki,Kd;            		//定义比例、积分、微分系数
    float Out;          					//定义输出值（控制执行器的变量）
    float Integral;            		//定义积分值
		float Inter_max;							//积分最大值
		float Inter_min;							//积分最小值
}PID;


#define		out_max							1000
#define		out_min							0
void	PID_InitStruct(PID* pid);
void	PID_Init(PID* pid,float Kp,float Ki,float Kd,float Target_max,float Target_min,float Inter_max,float Inter_min);
uint8_t PID_Set(PID* pid,float Target,float Err_max,float Err_min,float Err_mid,float Err_miss,float Current);













#endif		/* _TOOL_PID_H_ */







