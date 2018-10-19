
//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_tim.h  
/// @brief         		宏定义通用定时器相关结构和函数的声明
///	定时器3的通道2可用PB5复用功能，然后用来控制RGB灯
/// 定时器3的通道2,3,4对应开发板RGB灯GPIO的管脚
/// @version 1.1  
/// @author           李华炯  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#ifndef		_BSP_TIM_H_
#define		_BSP_TIM_H_

#include	"stm32f10x.h"

//定时器的宏定义
//定义通用定时器2,3,4,5的定义

//通用定时器2
#define            TIM2_APBxClock_FUN     	RCC_APB1PeriphClockCmd
#define            TIM2_CLK               	RCC_APB1Periph_TIM2
//#define            TIM2_Period            	9
//#define            TIM2_Prescaler         	71
// TIM2 输出比较通道2
#define            TIM2_CH2_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH2_PORT          	GPIOA
#define            TIM2_CH2_PIN           	GPIO_Pin_1
// TIM2 输出比较通道3
#define            TIM2_CH3_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH3_PORT          	GPIOA
#define            TIM2_CH3_PIN           	GPIO_Pin_2
// TIM2 输出比较通道4
#define            TIM2_CH4_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH4_PORT          	GPIOA
#define            TIM2_CH4_PIN           	GPIO_Pin_3

//通用定时器3
#define            TIM3_APBxClock_FUN     	RCC_APB1PeriphClockCmd
#define            TIM3_CLK               	RCC_APB1Periph_TIM3
//#define            TIM3_Period            	9
//#define            TIM3_Prescaler         	71
// TIM3 输出比较通道1
#define            TIM3_CH1_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM3_CH1_PORT          	GPIOA
#define            TIM3_CH1_PIN           	GPIO_Pin_6
// TIM3 输出比较通道2
#define            TIM3_CH2_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM3_CH2_PORT          	GPIOA
#define            TIM3_CH2_PIN           	GPIO_Pin_7
// TIM3 输出比较通道3
#define            TIM3_CH3_GPIO_CLK      	RCC_APB2Periph_GPIOB
#define            TIM3_CH3_PORT          	GPIOB
#define            TIM3_CH3_PIN           	GPIO_Pin_0
// TIM3 输出比较通道4
#define            TIM3_CH4_GPIO_CLK      	RCC_APB2Periph_GPIOB
#define            TIM3_CH4_PORT          	GPIOB
#define            TIM3_CH4_PIN           	GPIO_Pin_1



//有关高级定时器1NVIC配置结构体宏定义和中断服务函数定义
#define						 TIM1_NVIC_Channel				TIM1_UP_IRQn
#define						 TIM1_IRQHandler					TIM1_UP_IRQHandler



void	TIM3_GPIO_Config(void);
void  TIM3_CH4_PWN_Config(uint32_t T,uint32_t rate);
void  AdvanceTim_Config(void);
extern void  TIM1_IRQHandler(void);

#endif		/* _BSP_TIM_H_ */











