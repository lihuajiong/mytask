
#ifndef			_TOOL_PID_H_
#define			_TOOL_PID_H_

#include		"stm32f10x.h"
#include		<math.h>

//����pid�㷨�ṹ�嶨��
typedef struct 
{
    float Target ;            		//����Ŀ��ֵ
    float Current;        				//����ʵ��ֵ
    float Err;                		//����ƫ��ֵ
    float Err_last;            		//������һ��ƫ��ֵ
    float Kp,Ki,Kd;            		//������������֡�΢��ϵ��
    float Out;          					//�������ֵ������ִ�����ı�����
    float Integral;            		//�������ֵ
}pid_base;

void	PID_Base_Init(pid_base* pid,float Kp,float Ki,float Kd);
float	PID_base_Set(pid_base* pid, float Target,float Current);


typedef struct
{
    float Target ;            		//����Ŀ��ֵ
		float Target_max;							//����Ŀ�����ֵ
		float	Target_min;							//����Ŀ����Сֵ
    float Current;        				//����ʵ��ֵ
    float Err;                		//����ƫ��ֵ
    float Err_last;            		//������һ��ƫ��ֵ
    float Kp,Ki,Kd;            		//������������֡�΢��ϵ��
    float Out;          					//�������ֵ������ִ�����ı�����
    float Integral;            		//�������ֵ
		float Inter_max;							//�������ֵ
		float Inter_min;							//������Сֵ
}PID;


#define		out_max							1000
#define		out_min							0
void	PID_InitStruct(PID* pid);
void	PID_Init(PID* pid,float Kp,float Ki,float Kd,float Target_max,float Target_min,float Inter_max,float Inter_min);
uint8_t PID_Set(PID* pid,float Target,float Err_max,float Err_min,float Err_mid,float Err_miss,float Current);













#endif		/* _TOOL_PID_H_ */







