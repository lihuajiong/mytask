
//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_led.h  
/// @brief            宏定义要使用的GPIO的相关结构体  
/// 宏定义与硬件相关的GPIO结构体，本文件是指南者开发板RGB灯IO的定义 
/// 同时声明"bsp_led.c"中定义的函数，如果要使用此文件初始化其他GPIO
/// 更改宏定义即可
/// @version 1.1       
/// @author           李华炯
/// @date             2018.10.12
//////////////////////////////////////////////////////////////////////////

#ifndef			_BSP_LED_H_
#define			_BSP_LED_H_


#include		"stm32f10x.h"

/* 定义RGB灯连接的GPIO端口 */
// R-红色
#define 		LED1_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define 		LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define 		LED1_GPIO_PIN				GPIO_Pin_5			        /* GPIO的Pin */

// G-绿色
#define 		LED2_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define 		LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define 		LED2_GPIO_PIN				GPIO_Pin_0			        /* GPIO的Pin */

// B-蓝色
#define 		LED3_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define 		LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define 		LED3_GPIO_PIN				GPIO_Pin_1			        /* GPIO的Pin */

//定义时钟和时钟使能函数名
#define			GPIO_CLK_Cmd				RCC_APB2PeriphClockCmd		
#define			GPIO_CLK						RCC_APB2Periph_GPIOB

//定义开关数值
#define 		ON  								0
#define 		OFF 								1


//低电平灯亮
#define 		LED1_OFF						(GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN))
#define			LED1_ON							(GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN))

#define 		LED2_OFF						(GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN))
#define			LED2_ON							(GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN))

#define 		LED3_OFF						(GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN))
#define			LED3_ON							(GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN))


/* 直接操作寄存器的方法控制IO */
#define			digitalHi(p,i)		 	{p->BSRR=i;}	 																	//输出为高电平		
#define 		digitalLo(p,i)		 	{p->BRR=i;}	 																		//输出低电平
#define 		digitalToggle(p,i) 	{p->ODR ^=i;} 																	//输出反转状态

#define 		LED1_TOGGLE		 			digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define 		LED2_TOGGLE		 			digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define 		LED3_TOGGLE		 			digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)


//红
#define LED_RED  \
					LED1_ON;\
					LED2_OFF;\
					LED3_OFF

//绿
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON;\
					LED3_OFF

//蓝
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_ON

					
//黄(红+绿)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON;\
					LED3_OFF
//紫(红+蓝)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF;\
					LED3_ON

//青(绿+蓝)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON;\
					LED3_ON
					
//白(红+绿+蓝)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON;\
					LED3_ON
					
//黑(全部关闭)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_OFF


void GPIO_PP_Config(uint32_t RCC_APB2Periph, GPIO_TypeDef* GPIO_x, uint16_t GPIO_Pin_x);
void RGB_GPIO_Config(void);


#endif		/* _BSP_LED_H_ */



