

//////////////////////////////////////////////////////////////////////// 
/// @file             bsp_usart.h  
/// @brief            �����ʹ����йصĺ궨���Լ�������غ���  
/// @version 1.1      
/// @author           ���  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#ifndef		_BSP_USART_H_
#define		_BSP_USART_H_

#include		"stm32f10x.h"
#include		"stdio.h"



//�궨�����д���
//���д���1������APB2�����ϣ��������ڹ�����APB1������
//������ͳһ����Ϊ115200
	
// ����1-USART1
#define  USART1_CLK                RCC_APB2Periph_USART1
#define  USART1_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  USART1_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  USART1_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART1_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART1_TX_GPIO_PORT       GPIOA   
#define  USART1_TX_GPIO_PIN        GPIO_Pin_9
#define  USART1_RX_GPIO_PORT       GPIOA
#define  USART1_RX_GPIO_PIN        GPIO_Pin_10
//�жϷ���������NVICͨ��
#define  USART1_IRQ                USART1_IRQn
#define  USART1_funtion         	 USART1_IRQHandler


// ����2-USART2
#define  USART2_CLK                RCC_APB1Periph_USART2
#define  USART2_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  USART2_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  USART2_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART2_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART2_TX_GPIO_PORT       GPIOA   
#define  USART2_TX_GPIO_PIN        GPIO_Pin_2
#define  USART2_RX_GPIO_PORT       GPIOA
#define  USART2_RX_GPIO_PIN        GPIO_Pin_3

#define  USART2_IRQ                USART2_IRQn
#define  USART2_funtion         	 USART2_IRQHandler

// ����3-USART3
#define  USART3_CLK                RCC_APB1Periph_USART3
#define  USART3_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  USART3_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  USART3_GPIO_CLK           (RCC_APB2Periph_GPIOB)
#define  USART3_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART3_TX_GPIO_PORT       GPIOB   
#define  USART3_TX_GPIO_PIN        GPIO_Pin_10
#define  USART3_RX_GPIO_PORT       GPIOB
#define  USART3_RX_GPIO_PIN        GPIO_Pin_11

#define  USART3_IRQ                USART3_IRQn
#define  USART3_funtion         	 USART3_IRQHandler

// ����4-UART4
#define  UART4_CLK                RCC_APB1Periph_UART4
#define  UART4_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  UART4_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  UART4_GPIO_CLK           (RCC_APB2Periph_GPIOC)
#define  UART4_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  UART4_TX_GPIO_PORT       GPIOC   
#define  UART4_TX_GPIO_PIN        GPIO_Pin_10
#define  UART4_RX_GPIO_PORT       GPIOC
#define  UART4_RX_GPIO_PIN        GPIO_Pin_11

#define  UART4_IRQ                UART4_IRQn
#define  UART4_funtion         		UART4_IRQHandler


// ����5-UART5
#define  UART5_CLK                RCC_APB1Periph_UART5
#define  UART5_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  UART5_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  UART5_GPIO_CLK           (RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD)
#define  UART5_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  UART5_TX_GPIO_PORT       GPIOC   
#define  UART5_TX_GPIO_PIN        GPIO_Pin_12
#define  UART5_RX_GPIO_PORT       GPIOD
#define  UART5_RX_GPIO_PIN        GPIO_Pin_2

#define  UART5_IRQ                UART5_IRQn
#define  UART5_funtion         		UART5_IRQHandler





#define    DEBUG_USARTx												USART3 

//����1������APB2���������ϣ����������ڹ�����APB1������

//���崮��1�ķ������źͽ�������
#define    Usart3_TX_PORT											GPIOB
#define    Usart3_RX_PORT											GPIOB

#define    Usart3_TX_GPIO_Pin									GPIO_Pin_10
#define    Usart3_RX_GPIO_Pin									GPIO_Pin_11


//���崮��1��ʱ��
#define		 Usart3_RCC_CLK											RCC_APB1Periph_USART3
#define    Usart3_GPIO_CLK										RCC_APB2Periph_GPIOB

//����1����ʱ�ӵĺ�����
#define    Usart3_CLK_Cmd											RCC_APB1PeriphClockCmd

//�궨��DMAʱ���Լ�ʱ��ʹ�ܺ���		����ʹ�ô���3��DMA������DMA1ͨ��2����
#define     DMA_CLK														RCC_AHBPeriph_DMA1
#define			DMA_CLK_Cmd												RCC_AHBPeriphClockCmd

//�����������ݼĴ�����ַ���ڴ��ַ����������DMA��ʼ���ṹ��
#define   	Usart_Addr												(USART3_BASE+0x04)

//����һ�δ��������
extern  uint8_t sendnum;

//���崮��ͨ��
//����ͨ��
#define			DMASendChannel											DMA1_Channel2
//����ͨ��
#define			DMAReadChannel											DMA1_Channel3


//�������飬���ڷ������ݺͽ������ݴ洢�ĵط����Ѿ���main.c�ж���
extern 			uint8_t  		 												DMA_Usart_SendData[];
extern 			uint8_t   													DMA_Usart_ReadData[];



//���ô�����ؽṹ��
//����������
#define    Usart3_BaudRate										115200


void Usart3_DMA_Config(void);
void DMA_Enable(DMA_Channel_TypeDef*DMA_CHx);




void	Usart1_Config(void);
void	Usart2_Config(void);
void 	Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t data);
void 	Usart_SendString( USART_TypeDef * pUSARTx, char *data);
void	Ussart1_Register_Config(void);



#endif		/* _BSP_USART_H_ */




















