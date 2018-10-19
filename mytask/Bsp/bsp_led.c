

#include		"bsp_led.h"

/**
* @brief	初始化GPIO为推挽输出模式,输出速率50MHz
* @param 	RCC_APB2Periph:相应的GPIO时钟
*					GPIO_x：要初始化GPIO的端口
*					GPIO_Pin_x：要初始化的GPIO的Pin
* @return 无
* @author 李华炯
*/
void GPIO_PP_Config(uint32_t RCC_APB2Periph, GPIO_TypeDef* GPIO_x, uint16_t GPIO_Pin_x)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	//打开时钟
	GPIO_CLK_Cmd( RCC_APB2Periph , ENABLE );
	
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_x;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init( GPIO_x , &GPIO_Initstruct );
}


/**
* @brief	初始化RGB灯用到的GPIO
* @param  无
* @return 无
* @author 李华炯
*/
void RGB_GPIO_Config(void)
{
	
	GPIO_PP_Config( LED1_GPIO_CLK , LED1_GPIO_PORT , LED1_GPIO_PIN );
	GPIO_PP_Config( LED2_GPIO_CLK , LED2_GPIO_PORT , LED2_GPIO_PIN );
	GPIO_PP_Config( LED3_GPIO_CLK , LED3_GPIO_PORT , LED3_GPIO_PIN );
	
	LED_RGBOFF;
}







