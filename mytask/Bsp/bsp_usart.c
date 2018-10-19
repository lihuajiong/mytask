
//////////////////////////////////////////////////////////////////////// 
/// @file              bsp_usart.c 
/// @brief             初始化串口以及串口相关函数的编写
/// 编写串口的初始化函数，串口发送数据函数，接受中断的配置  
///	编写串口与printf和scanf的接口函数
/// @version 1.1     
/// @author           李华炯  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#include		"bsp_usart.h"



/**
* @brief	初始化串口1的发送和接受引脚的GPIO
* @param 	无
* @return 无
* @author 李华炯
*/
static void	usart1_GPIO_Config(void)
{
	USART1_GPIO_APBxClkCmd( USART1_GPIO_CLK , ENABLE );
	GPIO_InitTypeDef		Usart_GPIO_InitStruct;
	
	Usart_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	Usart_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	Usart_GPIO_InitStruct.GPIO_Pin = USART1_TX_GPIO_PIN;
	GPIO_Init( USART1_TX_GPIO_PORT , &Usart_GPIO_InitStruct );
	
	Usart_GPIO_InitStruct.GPIO_Pin = USART1_RX_GPIO_PIN;
	Usart_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init( USART1_TX_GPIO_PORT , &Usart_GPIO_InitStruct );
}

/**
* @brief	初始化串口2的发送和接受引脚的GPIO
* @param 	无
* @return 无
* @author 李华炯
*/
static void	usart2_GPIO_Config(void)
{
	USART1_GPIO_APBxClkCmd( USART2_GPIO_CLK , ENABLE );
	GPIO_InitTypeDef		Usart_GPIO_InitStruct;
	
	Usart_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	Usart_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	Usart_GPIO_InitStruct.GPIO_Pin = USART2_TX_GPIO_PIN;
	GPIO_Init( USART2_TX_GPIO_PORT , &Usart_GPIO_InitStruct );
	
	Usart_GPIO_InitStruct.GPIO_Pin = USART2_RX_GPIO_PIN;
	Usart_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init( USART2_TX_GPIO_PORT , &Usart_GPIO_InitStruct );
}

/**
* @brief	配置串口1的NVIC结构体
* @param 	无
* @return 无
* @author 李华炯
*/
static void	Usart1_NVIC_Config(void)
{
	 NVIC_InitTypeDef NVIC_InitStructure;
  /* 配置USART为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQ;
  /* 抢断优先级*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 子优先级 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  /* 使能中断 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* 初始化配置NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

/**
* @brief	配置串口2的NVIC结构体
* @param 	无
* @return 无
* @author 李华炯
*/
static void	Usart2_NVIC_Config(void)
{
	 NVIC_InitTypeDef NVIC_InitStructure;
  /* 配置USART为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQ;
  /* 抢断优先级*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 子优先级 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  /* 使能中断 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* 初始化配置NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

/**
* @brief	使用固件库函数初始化串口1
* @param 	无
* @return 无
* @author 李华炯
*/
void	Usart1_Config(void)
{
	usart1_GPIO_Config();
	
	USART1_APBxClkCmd( USART1_CLK , ENABLE );
	
	USART_InitTypeDef	Usart_InitStruct;
	Usart_InitStruct.USART_BaudRate = USART1_BAUDRATE;
	Usart_InitStruct.USART_HardwareFlowControl = DISABLE;
	Usart_InitStruct.USART_Mode = ( USART_Mode_Rx|USART_Mode_Tx );
	Usart_InitStruct.USART_Parity = USART_Parity_No;
	Usart_InitStruct.USART_StopBits = USART_StopBits_1;
	Usart_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init( USART1 , &Usart_InitStruct );
	
	Usart1_NVIC_Config();
	USART_ITConfig( USART1 , USART_IT_RXNE , ENABLE );
	
	USART_Cmd( USART1 , ENABLE );
}

/**
* @brief	使用固件库函数初始化串口2
* @param 	无
* @return 无
* @author 李华炯
*/
void	Usart2_Config(void)
{
	usart2_GPIO_Config();
	
	USART2_APBxClkCmd( USART2_CLK , ENABLE );
	
	USART_InitTypeDef	Usart_InitStruct;
	Usart_InitStruct.USART_BaudRate = USART2_BAUDRATE;
	Usart_InitStruct.USART_HardwareFlowControl = DISABLE;
	Usart_InitStruct.USART_Mode = ( USART_Mode_Rx|USART_Mode_Tx );
	Usart_InitStruct.USART_Parity = USART_Parity_No;
	Usart_InitStruct.USART_StopBits = USART_StopBits_1;
	Usart_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init( USART2 , &Usart_InitStruct );
	
	Usart2_NVIC_Config();
	USART_ITConfig( USART2 , USART_IT_RXNE , ENABLE );
	
	USART_Cmd( USART2 , ENABLE );
}


/**
* @brief	使用寄存器初始化串口1
* @param 	无
* @return 无
* @author 李华炯
*/
void	Ussart1_Register_Config(void)
{
	//打开GPIO口的时钟
	RCC->APB2ENR |=	(uint32_t)0x00000004;
	//配置GPIOB的端口
	GPIOA->CRH |= (uint32_t)0x000004B0;
	
	USART1->CR1 |= (uint32_t)0x0000201C;
	USART1->BRR |=  0x171;
	
	Usart1_NVIC_Config();
}






/**
* @brief	使用串口发送一个字节函数
* @param 	pUSARTx：选择串口
*					data:发送的数据
* @return 无
* @author 李华炯
*/
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t data)
{
	/* 发送一个字节数据到USART */
	USART_SendData( pUSARTx , data );
		
	/* 等待发送数据寄存器为空 */
	while ( USART_GetFlagStatus( pUSARTx , USART_FLAG_TXE ) == RESET );	
}

/**
* @brief	使用串口发送字符串
* @param 	pUSARTx：选择串口
*					data:发送的数据的数组首地址
* @return 无
* @author 李华炯
*/
void Usart_SendString( USART_TypeDef * pUSARTx, char *data)
{
	uint8_t k=0;
  do 
  {
      Usart_SendByte( pUSARTx, *(data + k) );
      k++;
  } while(*(data + k)!='\0');
  
  /* 等待发送完成 */
  while( USART_GetFlagStatus( pUSARTx , USART_FLAG_TC ) == RESET )
  {}
}




///重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USART1, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}



void Usart3_DMA_Config(void)
{
/*初始化GPIO	*/
	GPIO_InitTypeDef  Usart_GPIO_Init;
	
	
//打开时钟
	RCC_APB2PeriphClockCmd( Usart3_GPIO_CLK , ENABLE );
//打开串口时钟
	Usart3_CLK_Cmd( Usart3_RCC_CLK , ENABLE );

//配置发送和接受引脚GPIO	
	Usart_GPIO_Init.GPIO_Pin = Usart3_TX_GPIO_Pin;
	Usart_GPIO_Init.GPIO_Mode = GPIO_Mode_AF_PP;
	Usart_GPIO_Init.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init( Usart3_TX_PORT , &Usart_GPIO_Init );
	
	Usart_GPIO_Init.GPIO_Pin = Usart3_RX_GPIO_Pin;
	Usart_GPIO_Init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  Usart_GPIO_Init.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init( Usart3_RX_PORT , &Usart_GPIO_Init );	
	
/*****************************************************/
	USART_InitTypeDef  Usart3_Init;
	
	Usart3_Init.USART_BaudRate = Usart3_BaudRate;
	Usart3_Init.USART_WordLength = USART_WordLength_8b;
	Usart3_Init.USART_StopBits = USART_StopBits_1;
	Usart3_Init.USART_Mode = ( USART_Mode_Rx | USART_Mode_Tx );
	Usart3_Init.USART_Parity = USART_Parity_No;
	Usart3_Init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init( USART3, &Usart3_Init );
	
	USART_Cmd( USART3 , ENABLE );
	
/*****************************************************/	

/*初始化DMA结构体，包括发送DMA请求和接收DMA请求*/
	
	//定义一个DMA初始化结构体
	DMA_InitTypeDef  Usart_DMA_Init;
	
	//打开DMA时钟
	DMA_CLK_Cmd( DMA_CLK , ENABLE );
	
	//配置DMA结构体
	// 设置DMA源地址：串口数据寄存器地址*/
	Usart_DMA_Init.DMA_PeripheralBaseAddr = Usart_Addr;
	// 内存地址(要传输的变量的指针)
	Usart_DMA_Init.DMA_MemoryBaseAddr = ( uint32_t ) DMA_Usart_SendData;
	// 方向：从内存到外设
	Usart_DMA_Init.DMA_DIR = DMA_DIR_PeripheralDST;
	// 传输大小
	Usart_DMA_Init.DMA_BufferSize = sendnum;
	// 外设地址不增
	Usart_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// 内存地址自增
	Usart_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
	// 外设数据单位
	Usart_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	// 内存数据单位
	Usart_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	// DMA模式，一次或者循环模式	
	Usart_DMA_Init.DMA_Mode = DMA_Mode_Normal;
	// 优先级：中
	Usart_DMA_Init.DMA_Priority = DMA_Priority_Medium;
	// 禁止内存到内存的传输
	Usart_DMA_Init.DMA_M2M = DMA_M2M_Disable;
	
	//使用函数初始化DMA结构体
	DMA_Init( DMASendChannel , &Usart_DMA_Init );
	
	//使能DMA功能
	DMA_Cmd( DMASendChannel , ENABLE );
	
	// 内存地址(要传输的变量的指针)
	Usart_DMA_Init.DMA_MemoryBaseAddr = ( uint32_t ) DMA_Usart_ReadData;
	// 方向：从外设到内存
	Usart_DMA_Init.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	DMA_Init( DMAReadChannel , &Usart_DMA_Init );
	
	DMA_Cmd( DMAReadChannel , ENABLE );
	//使能串口DMA请求功能
	USART_DMACmd( DEBUG_USARTx , USART_DMAReq_Tx , ENABLE );
	USART_DMACmd( DEBUG_USARTx , USART_DMAReq_Rx , ENABLE );

}

//接收一次数据
void DMA_Enable( DMA_Channel_TypeDef*DMA_CHx )
{ 
	DMA_Cmd( DMA_CHx , DISABLE ); //关闭USART3 TX DMA1 所指示的通道 
	DMA_SetCurrDataCounter( DMA_CHx , sendnum );//从新设置缓冲大小,指向数组0
	DMA_Cmd( DMA_CHx , ENABLE ); //使能USART3 TX DMA1 所指示的通道 
}










