
//////////////////////////////////////////////////////////////////////// 
/// @file              bsp_tim.c
/// @brief             ��ʱ����ʼ�������Լ���ع��ܺ���  
///��д��ʱ����ʼ��������PWN���������ʵ���Զ����ռ�ձ�  
///�����ڵ�PWN���������ͬʱ��д��ʱ����ص���������
/// @version 1.1      
/// @author           ���  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#include		"bsp_tim.h"

/**
* @brief	��ʼ������PWN���������GPIO�������ʹ�ö�ʱ��3��ͨ��4
* @param  ��
* @return ��
* @author ���
*/
void	TIM3_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

//  //ͨ��1 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd( TIM3_CH1_GPIO_CLK , ENABLE );
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init( TIM3_CH1_PORT , &GPIO_InitStructure );
//	
//	//ͨ��2 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(TIM3_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(TIM3_CH2_PORT, &GPIO_InitStructure);
//	
//	//ͨ��3 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(TIM3_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(TIM3_CH3_PORT, &GPIO_InitStructure);
	
	//ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TIM3_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TIM3_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TIM3_CH4_PORT, &GPIO_InitStructure);
}


/* ----------------   PWM�ź� ���ں�ռ�ձȵļ���--------------- */
// ARR ���Զ���װ�ؼĴ�����ֵ
// CLK_cnt����������ʱ�ӣ����� Fck_int / (psc+1) = 72M/(psc+1)
// Fck_int:72M
// psc:Ԥ��Ƶϵ��
// PWM �źŵ����� T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// ռ�ձ�P=CCR/(ARR+1)

/**
* @brief	ʵ��PWN��ռ�ձȺ����ڵ�����
* @param  T�����ڣ���λms		0-100����
*					rate��ռ�ձ�			0-100����
* @return ��
* @author ���
*/
void  TIM3_CH4_PWN_Config( uint32_t T , uint32_t rate )
{
	//������ʱ����ʱ��
	TIM3_APBxClock_FUN( TIM3_CLK , ENABLE );
	
	//��ʼ��ʱ���ṹ��
	TIM_TimeBaseInitTypeDef TIM3_BaseInitStruct;
	
	TIM3_BaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM3_BaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM3_BaseInitStruct.TIM_Period = (T*1000-1);
	TIM3_BaseInitStruct.TIM_Prescaler = 71;
//	TIM2_BaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit( TIM3 ,&TIM3_BaseInitStruct);
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = rate*T*10;
	TIM_OC4Init( TIM3 , &TIM_OCInitStructure );
	TIM_OC4PreloadConfig( TIM3 , TIM_OCPreload_Enable );
	
	// ʹ�ܼ�����
	TIM_Cmd( TIM3 , ENABLE );
}

/**
* @brief	���ö�ʱ��1��NVIC�ṹ��
* @param 	��
* @return ��
* @author ���
*/
static void AdvanceTim_NVIC_Config(void)
{
	NVIC_InitTypeDef AdvanceTim_NVIC_InitStruct;
	AdvanceTim_NVIC_InitStruct.NVIC_IRQChannel = TIM1_NVIC_Channel;
	AdvanceTim_NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	AdvanceTim_NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 5;
//	AdvanceTim_NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	
	NVIC_Init( &AdvanceTim_NVIC_InitStruct );
}

/**
* @brief	��ʱ��1��ʼ�������ã�ʵ��1ms�Ķ�ʱ�жϣ����ж�ʱ��1�Ǹ߼���ʱ���������ڸ�������APB2�����ϣ�
* @param 	��
* @return ��
* @author ���
*/
void AdvanceTim_Config(void)
{
	//��ʱ��
	RCC_APB2PeriphResetCmd( RCC_APB2Periph_TIM1 , ENABLE );
	
	//����ʱ���ṹ��
	TIM_TimeBaseInitTypeDef TIM1_BaseInitStruct;
	//��ʱʱ�䣺��TIM_Period+1��*��1/��TIM_Prescaler+1����= 1ms
	TIM1_BaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_BaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_BaseInitStruct.TIM_Period = 999;
	TIM1_BaseInitStruct.TIM_Prescaler = 71;
	TIM1_BaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit( TIM1 , &TIM1_BaseInitStruct );
	
	//ʹ���ж�
	AdvanceTim_NVIC_Config();
	TIM_ClearFlag( TIM1 ,TIM_FLAG_Update );
	TIM_ITConfig( TIM1 , TIM_IT_Update , ENABLE );
	
	//ʹ�ܶ�ʱ��
	TIM_Cmd( TIM1 , ENABLE );
}


















