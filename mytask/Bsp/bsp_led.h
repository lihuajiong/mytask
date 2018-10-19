
//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_led.h  
/// @brief            �궨��Ҫʹ�õ�GPIO����ؽṹ��  
/// �궨����Ӳ����ص�GPIO�ṹ�壬���ļ���ָ���߿�����RGB��IO�Ķ��� 
/// ͬʱ����"bsp_led.c"�ж���ĺ��������Ҫʹ�ô��ļ���ʼ������GPIO
/// ���ĺ궨�弴��
/// @version 1.1       
/// @author           ���
/// @date             2018.10.12
//////////////////////////////////////////////////////////////////////////

#ifndef			_BSP_LED_H_
#define			_BSP_LED_H_


#include		"stm32f10x.h"

/* ����RGB�����ӵ�GPIO�˿� */
// R-��ɫ
#define 		LED1_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define 		LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define 		LED1_GPIO_PIN				GPIO_Pin_5			        /* GPIO��Pin */

// G-��ɫ
#define 		LED2_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define 		LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define 		LED2_GPIO_PIN				GPIO_Pin_0			        /* GPIO��Pin */

// B-��ɫ
#define 		LED3_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define 		LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define 		LED3_GPIO_PIN				GPIO_Pin_1			        /* GPIO��Pin */

//����ʱ�Ӻ�ʱ��ʹ�ܺ�����
#define			GPIO_CLK_Cmd				RCC_APB2PeriphClockCmd		
#define			GPIO_CLK						RCC_APB2Periph_GPIOB

//���忪����ֵ
#define 		ON  								0
#define 		OFF 								1


//�͵�ƽ����
#define 		LED1_OFF						(GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN))
#define			LED1_ON							(GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN))

#define 		LED2_OFF						(GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN))
#define			LED2_ON							(GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN))

#define 		LED3_OFF						(GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN))
#define			LED3_ON							(GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN))


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define			digitalHi(p,i)		 	{p->BSRR=i;}	 																	//���Ϊ�ߵ�ƽ		
#define 		digitalLo(p,i)		 	{p->BRR=i;}	 																		//����͵�ƽ
#define 		digitalToggle(p,i) 	{p->ODR ^=i;} 																	//�����ת״̬

#define 		LED1_TOGGLE		 			digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define 		LED2_TOGGLE		 			digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define 		LED3_TOGGLE		 			digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)


//��
#define LED_RED  \
					LED1_ON;\
					LED2_OFF;\
					LED3_OFF

//��
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON;\
					LED3_OFF

//��
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_ON

					
//��(��+��)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON;\
					LED3_OFF
//��(��+��)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF;\
					LED3_ON

//��(��+��)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON;\
					LED3_ON
					
//��(��+��+��)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON;\
					LED3_ON
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_OFF


void GPIO_PP_Config(uint32_t RCC_APB2Periph, GPIO_TypeDef* GPIO_x, uint16_t GPIO_Pin_x);
void RGB_GPIO_Config(void);


#endif		/* _BSP_LED_H_ */



