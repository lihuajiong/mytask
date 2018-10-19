
//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_tim.h  
/// @brief         		�궨��ͨ�ö�ʱ����ؽṹ�ͺ���������
///	��ʱ��3��ͨ��2����PB5���ù��ܣ�Ȼ����������RGB��
/// ��ʱ��3��ͨ��2,3,4��Ӧ������RGB��GPIO�Ĺܽ�
/// @version 1.1  
/// @author           ���  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#ifndef		_BSP_TIM_H_
#define		_BSP_TIM_H_

#include	"stm32f10x.h"

//��ʱ���ĺ궨��
//����ͨ�ö�ʱ��2,3,4,5�Ķ���

//ͨ�ö�ʱ��2
#define            TIM2_APBxClock_FUN     	RCC_APB1PeriphClockCmd
#define            TIM2_CLK               	RCC_APB1Periph_TIM2
//#define            TIM2_Period            	9
//#define            TIM2_Prescaler         	71
// TIM2 ����Ƚ�ͨ��2
#define            TIM2_CH2_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH2_PORT          	GPIOA
#define            TIM2_CH2_PIN           	GPIO_Pin_1
// TIM2 ����Ƚ�ͨ��3
#define            TIM2_CH3_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH3_PORT          	GPIOA
#define            TIM2_CH3_PIN           	GPIO_Pin_2
// TIM2 ����Ƚ�ͨ��4
#define            TIM2_CH4_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM2_CH4_PORT          	GPIOA
#define            TIM2_CH4_PIN           	GPIO_Pin_3

//ͨ�ö�ʱ��3
#define            TIM3_APBxClock_FUN     	RCC_APB1PeriphClockCmd
#define            TIM3_CLK               	RCC_APB1Periph_TIM3
//#define            TIM3_Period            	9
//#define            TIM3_Prescaler         	71
// TIM3 ����Ƚ�ͨ��1
#define            TIM3_CH1_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM3_CH1_PORT          	GPIOA
#define            TIM3_CH1_PIN           	GPIO_Pin_6
// TIM3 ����Ƚ�ͨ��2
#define            TIM3_CH2_GPIO_CLK      	RCC_APB2Periph_GPIOA
#define            TIM3_CH2_PORT          	GPIOA
#define            TIM3_CH2_PIN           	GPIO_Pin_7
// TIM3 ����Ƚ�ͨ��3
#define            TIM3_CH3_GPIO_CLK      	RCC_APB2Periph_GPIOB
#define            TIM3_CH3_PORT          	GPIOB
#define            TIM3_CH3_PIN           	GPIO_Pin_0
// TIM3 ����Ƚ�ͨ��4
#define            TIM3_CH4_GPIO_CLK      	RCC_APB2Periph_GPIOB
#define            TIM3_CH4_PORT          	GPIOB
#define            TIM3_CH4_PIN           	GPIO_Pin_1



//�йظ߼���ʱ��1NVIC���ýṹ��궨����жϷ���������
#define						 TIM1_NVIC_Channel				TIM1_UP_IRQn
#define						 TIM1_IRQHandler					TIM1_UP_IRQHandler



void	TIM3_GPIO_Config(void);
void  TIM3_CH4_PWN_Config(uint32_t T,uint32_t rate);
void  AdvanceTim_Config(void);
extern void  TIM1_IRQHandler(void);

#endif		/* _BSP_TIM_H_ */











