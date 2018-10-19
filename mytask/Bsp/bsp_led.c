

#include		"bsp_led.h"

/**
* @brief	��ʼ��GPIOΪ�������ģʽ,�������50MHz
* @param 	RCC_APB2Periph:��Ӧ��GPIOʱ��
*					GPIO_x��Ҫ��ʼ��GPIO�Ķ˿�
*					GPIO_Pin_x��Ҫ��ʼ����GPIO��Pin
* @return ��
* @author ���
*/
void GPIO_PP_Config(uint32_t RCC_APB2Periph, GPIO_TypeDef* GPIO_x, uint16_t GPIO_Pin_x)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	//��ʱ��
	GPIO_CLK_Cmd( RCC_APB2Periph , ENABLE );
	
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_x;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init( GPIO_x , &GPIO_Initstruct );
}


/**
* @brief	��ʼ��RGB���õ���GPIO
* @param  ��
* @return ��
* @author ���
*/
void RGB_GPIO_Config(void)
{
	
	GPIO_PP_Config( LED1_GPIO_CLK , LED1_GPIO_PORT , LED1_GPIO_PIN );
	GPIO_PP_Config( LED2_GPIO_CLK , LED2_GPIO_PORT , LED2_GPIO_PIN );
	GPIO_PP_Config( LED3_GPIO_CLK , LED3_GPIO_PORT , LED3_GPIO_PIN );
	
	LED_RGBOFF;
}







