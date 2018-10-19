
//////////////////////////////////////////////////////////////////////// 
/// @file              bsp_tim.c
/// @brief             定时器初始化函数以及相关功能函数  
///编写定时器初始化函数，PWN输出函数，实现自定义的占空比  
///和周期的PWN方波输出，同时编写定时器相关的其他函数
/// @version 1.1      
/// @author           李华炯  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#include		"bsp_tim.h"

/**
* @brief	初始化用于PWN方波输出的GPIO，这里仅使用定时器3的通道4
* @param  无
* @return 无
* @author 李华炯
*/
void	TIM3_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

//  //通道1 GPIO 初始化
//	RCC_APB2PeriphClockCmd( TIM3_CH1_GPIO_CLK , ENABLE );
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init( TIM3_CH1_PORT , &GPIO_InitStructure );
//	
//	//通道2 GPIO 初始化
//	RCC_APB2PeriphClockCmd(TIM3_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(TIM3_CH2_PORT, &GPIO_InitStructure);
//	
//	//通道3 GPIO 初始化
//	RCC_APB2PeriphClockCmd(TIM3_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  TIM3_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(TIM3_CH3_PORT, &GPIO_InitStructure);
	
	//通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(TIM3_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TIM3_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TIM3_CH4_PORT, &GPIO_InitStructure);
}


/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// Fck_int:72M
// psc:预分频系数
// PWM 信号的周期 T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

/**
* @brief	实现PWN波占空比和周期的配置
* @param  T：周期，单位ms		0-100整型
*					rate：占空比			0-100整型
* @return 无
* @author 李华炯
*/
void  TIM3_CH4_PWN_Config( uint32_t T , uint32_t rate )
{
	//开启定时器的时钟
	TIM3_APBxClock_FUN( TIM3_CLK , ENABLE );
	
	//初始化时基结构体
	TIM_TimeBaseInitTypeDef TIM3_BaseInitStruct;
	
	TIM3_BaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM3_BaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM3_BaseInitStruct.TIM_Period = (T*1000-1);
	TIM3_BaseInitStruct.TIM_Prescaler = 71;
//	TIM2_BaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit( TIM3 ,&TIM3_BaseInitStruct);
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = rate*T*10;
	TIM_OC4Init( TIM3 , &TIM_OCInitStructure );
	TIM_OC4PreloadConfig( TIM3 , TIM_OCPreload_Enable );
	
	// 使能计数器
	TIM_Cmd( TIM3 , ENABLE );
}

/**
* @brief	配置定时器1的NVIC结构体
* @param 	无
* @return 无
* @author 李华炯
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
* @brief	定时器1初始化和配置，实现1ms的定时中断（其中定时器1是高级定时器，挂载在高速总线APB2总线上）
* @param 	无
* @return 无
* @author 李华炯
*/
void AdvanceTim_Config(void)
{
	//打开时钟
	RCC_APB2PeriphResetCmd( RCC_APB2Periph_TIM1 , ENABLE );
	
	//配置时基结构体
	TIM_TimeBaseInitTypeDef TIM1_BaseInitStruct;
	//定时时间：（TIM_Period+1）*（1/（TIM_Prescaler+1））= 1ms
	TIM1_BaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_BaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_BaseInitStruct.TIM_Period = 999;
	TIM1_BaseInitStruct.TIM_Prescaler = 71;
	TIM1_BaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit( TIM1 , &TIM1_BaseInitStruct );
	
	//使能中断
	AdvanceTim_NVIC_Config();
	TIM_ClearFlag( TIM1 ,TIM_FLAG_Update );
	TIM_ITConfig( TIM1 , TIM_IT_Update , ENABLE );
	
	//使能定时器
	TIM_Cmd( TIM1 , ENABLE );
}


















