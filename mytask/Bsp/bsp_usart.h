

//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_usart.h  
/// @brief            声明和串口有关的宏定义以及串口相关函数  
/// @version 1.1      
/// @author           李华炯  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#ifndef		_BSP_USART_H_
#define		_BSP_USART_H_

#include		"stm32f10x.h"
#include		"stdio.h"



//宏定义所有串口
//其中串口1挂载在APB2总线上，其他串口挂载在APB1总线上
//波特率统一设置为115200
	
// 串口1-USART1
#define  USART1_CLK                RCC_APB2Periph_USART1
#define  USART1_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  USART1_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  USART1_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART1_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART1_TX_GPIO_PORT       GPIOA   
#define  USART1_TX_GPIO_PIN        GPIO_Pin_9
#define  USART1_RX_GPIO_PORT       GPIOA
#define  USART1_RX_GPIO_PIN        GPIO_Pin_10
//中断服务函数名和NVIC通道
#define  USART1_IRQ                USART1_IRQn
#define  USART1_funtion         	 USART1_IRQHandler


// 串口2-USART2
#define  USART2_CLK                RCC_APB1Periph_USART2
#define  USART2_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  USART2_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  USART2_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART2_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART2_TX_GPIO_PORT       GPIOA   
#define  USART2_TX_GPIO_PIN        GPIO_Pin_2
#define  USART2_RX_GPIO_PORT       GPIOA
#define  USART2_RX_GPIO_PIN        GPIO_Pin_3

#define  USART2_IRQ                USART2_IRQn
#define  USART2_funtion         	 USART2_IRQHandler

// 串口3-USART3
#define  USART3_CLK                RCC_APB1Periph_USART3
#define  USART3_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  USART3_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  USART3_GPIO_CLK           (RCC_APB2Periph_GPIOB)
#define  USART3_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART3_TX_GPIO_PORT       GPIOB   
#define  USART3_TX_GPIO_PIN        GPIO_Pin_10
#define  USART3_RX_GPIO_PORT       GPIOB
#define  USART3_RX_GPIO_PIN        GPIO_Pin_11

#define  USART3_IRQ                USART3_IRQn
#define  USART3_funtion         	 USART3_IRQHandler

// 串口4-UART4
#define  UART4_CLK                RCC_APB1Periph_UART4
#define  UART4_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  UART4_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  UART4_GPIO_CLK           (RCC_APB2Periph_GPIOC)
#define  UART4_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  UART4_TX_GPIO_PORT       GPIOC   
#define  UART4_TX_GPIO_PIN        GPIO_Pin_10
#define  UART4_RX_GPIO_PORT       GPIOC
#define  UART4_RX_GPIO_PIN        GPIO_Pin_11

#define  UART4_IRQ                UART4_IRQn
#define  UART4_funtion         		UART4_IRQHandler


// 串口5-UART5
#define  UART5_CLK                RCC_APB1Periph_UART5
#define  UART5_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  UART5_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  UART5_GPIO_CLK           (RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD)
#define  UART5_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  UART5_TX_GPIO_PORT       GPIOC   
#define  UART5_TX_GPIO_PIN        GPIO_Pin_12
#define  UART5_RX_GPIO_PORT       GPIOD
#define  UART5_RX_GPIO_PIN        GPIO_Pin_2

#define  UART5_IRQ                UART5_IRQn
#define  UART5_funtion         		UART5_IRQHandler





#define    DEBUG_USARTx												USART3 

//串口1挂载在APB2高速总线上，而其他串口挂载在APB1总线上

//定义串口1的发送引脚和接收引脚
#define    Usart3_TX_PORT											GPIOB
#define    Usart3_RX_PORT											GPIOB

#define    Usart3_TX_GPIO_Pin									GPIO_Pin_10
#define    Usart3_RX_GPIO_Pin									GPIO_Pin_11


//定义串口1的时钟
#define		 Usart3_RCC_CLK											RCC_APB1Periph_USART3
#define    Usart3_GPIO_CLK										RCC_APB2Periph_GPIOB

//串口1配置时钟的函数名
#define    Usart3_CLK_Cmd											RCC_APB1PeriphClockCmd

//宏定义DMA时钟以及时钟使能函数		这里使用串口3的DMA，属于DMA1通道2请求
#define     DMA_CLK														RCC_AHBPeriph_DMA1
#define			DMA_CLK_Cmd												RCC_AHBPeriphClockCmd

//定义外设数据寄存器地址和内存地址，用于配置DMA初始化结构体
#define   	Usart_Addr												(USART3_BASE+0x04)

//定义一次传输的数量
extern  uint8_t sendnum;

//定义串口通道
//发送通道
#define			DMASendChannel											DMA1_Channel2
//接收通道
#define			DMAReadChannel											DMA1_Channel3


//两个数组，用于发送数据和接收数据存储的地方，已经在main.c中定义
extern 			uint8_t  		 												DMA_Usart_SendData[];
extern 			uint8_t   													DMA_Usart_ReadData[];



//配置串口相关结构体
//波特率设置
#define    Usart3_BaudRate										115200


void Usart3_DMA_Config(void);
void DMA_Enable(DMA_Channel_TypeDef*DMA_CHx);




void	Usart1_Config(void);
void	Usart2_Config(void);
void 	Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t data);
void 	Usart_SendString( USART_TypeDef * pUSARTx, char *data);
void	Ussart1_Register_Config(void);



#endif		/* _BSP_USART_H_ */




















