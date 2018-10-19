
//////////////////////////////////////////////////////////////////////// 
/// @file              bsp_usart.c 
/// @brief             ��ʼ�������Լ�������غ����ı�д
/// ��д���ڵĳ�ʼ�����������ڷ������ݺ����������жϵ�����  
///	��д������printf��scanf�Ľӿں���
/// @version 1.1     
/// @author           ���  
/// @date             2018.10  
//////////////////////////////////////////////////////////////////////////

#include		"bsp_usart.h"



/**
* @brief	��ʼ������1�ķ��ͺͽ������ŵ�GPIO
* @param 	��
* @return ��
* @author ���
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
* @brief	��ʼ������2�ķ��ͺͽ������ŵ�GPIO
* @param 	��
* @return ��
* @author ���
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
* @brief	���ô���1��NVIC�ṹ��
* @param 	��
* @return ��
* @author ���
*/
static void	Usart1_NVIC_Config(void)
{
	 NVIC_InitTypeDef NVIC_InitStructure;
  /* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQ;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

/**
* @brief	���ô���2��NVIC�ṹ��
* @param 	��
* @return ��
* @author ���
*/
static void	Usart2_NVIC_Config(void)
{
	 NVIC_InitTypeDef NVIC_InitStructure;
  /* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQ;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

/**
* @brief	ʹ�ù̼��⺯����ʼ������1
* @param 	��
* @return ��
* @author ���
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
* @brief	ʹ�ù̼��⺯����ʼ������2
* @param 	��
* @return ��
* @author ���
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
* @brief	ʹ�üĴ�����ʼ������1
* @param 	��
* @return ��
* @author ���
*/
void	Ussart1_Register_Config(void)
{
	//��GPIO�ڵ�ʱ��
	RCC->APB2ENR |=	(uint32_t)0x00000004;
	//����GPIOB�Ķ˿�
	GPIOA->CRH |= (uint32_t)0x000004B0;
	
	USART1->CR1 |= (uint32_t)0x0000201C;
	USART1->BRR |=  0x171;
	
	Usart1_NVIC_Config();
}






/**
* @brief	ʹ�ô��ڷ���һ���ֽں���
* @param 	pUSARTx��ѡ�񴮿�
*					data:���͵�����
* @return ��
* @author ���
*/
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t data)
{
	/* ����һ���ֽ����ݵ�USART */
	USART_SendData( pUSARTx , data );
		
	/* �ȴ��������ݼĴ���Ϊ�� */
	while ( USART_GetFlagStatus( pUSARTx , USART_FLAG_TXE ) == RESET );	
}

/**
* @brief	ʹ�ô��ڷ����ַ���
* @param 	pUSARTx��ѡ�񴮿�
*					data:���͵����ݵ������׵�ַ
* @return ��
* @author ���
*/
void Usart_SendString( USART_TypeDef * pUSARTx, char *data)
{
	uint8_t k=0;
  do 
  {
      Usart_SendByte( pUSARTx, *(data + k) );
      k++;
  } while(*(data + k)!='\0');
  
  /* �ȴ�������� */
  while( USART_GetFlagStatus( pUSARTx , USART_FLAG_TC ) == RESET )
  {}
}




///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(USART1, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}



void Usart3_DMA_Config(void)
{
/*��ʼ��GPIO	*/
	GPIO_InitTypeDef  Usart_GPIO_Init;
	
	
//��ʱ��
	RCC_APB2PeriphClockCmd( Usart3_GPIO_CLK , ENABLE );
//�򿪴���ʱ��
	Usart3_CLK_Cmd( Usart3_RCC_CLK , ENABLE );

//���÷��ͺͽ�������GPIO	
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

/*��ʼ��DMA�ṹ�壬��������DMA����ͽ���DMA����*/
	
	//����һ��DMA��ʼ���ṹ��
	DMA_InitTypeDef  Usart_DMA_Init;
	
	//��DMAʱ��
	DMA_CLK_Cmd( DMA_CLK , ENABLE );
	
	//����DMA�ṹ��
	// ����DMAԴ��ַ���������ݼĴ�����ַ*/
	Usart_DMA_Init.DMA_PeripheralBaseAddr = Usart_Addr;
	// �ڴ��ַ(Ҫ����ı�����ָ��)
	Usart_DMA_Init.DMA_MemoryBaseAddr = ( uint32_t ) DMA_Usart_SendData;
	// ���򣺴��ڴ浽����
	Usart_DMA_Init.DMA_DIR = DMA_DIR_PeripheralDST;
	// �����С
	Usart_DMA_Init.DMA_BufferSize = sendnum;
	// �����ַ����
	Usart_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// �ڴ��ַ����
	Usart_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
	// �������ݵ�λ
	Usart_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	// �ڴ����ݵ�λ
	Usart_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	// DMAģʽ��һ�λ���ѭ��ģʽ	
	Usart_DMA_Init.DMA_Mode = DMA_Mode_Normal;
	// ���ȼ�����
	Usart_DMA_Init.DMA_Priority = DMA_Priority_Medium;
	// ��ֹ�ڴ浽�ڴ�Ĵ���
	Usart_DMA_Init.DMA_M2M = DMA_M2M_Disable;
	
	//ʹ�ú�����ʼ��DMA�ṹ��
	DMA_Init( DMASendChannel , &Usart_DMA_Init );
	
	//ʹ��DMA����
	DMA_Cmd( DMASendChannel , ENABLE );
	
	// �ڴ��ַ(Ҫ����ı�����ָ��)
	Usart_DMA_Init.DMA_MemoryBaseAddr = ( uint32_t ) DMA_Usart_ReadData;
	// ���򣺴����赽�ڴ�
	Usart_DMA_Init.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	DMA_Init( DMAReadChannel , &Usart_DMA_Init );
	
	DMA_Cmd( DMAReadChannel , ENABLE );
	//ʹ�ܴ���DMA������
	USART_DMACmd( DEBUG_USARTx , USART_DMAReq_Tx , ENABLE );
	USART_DMACmd( DEBUG_USARTx , USART_DMAReq_Rx , ENABLE );

}

//����һ������
void DMA_Enable( DMA_Channel_TypeDef*DMA_CHx )
{ 
	DMA_Cmd( DMA_CHx , DISABLE ); //�ر�USART3 TX DMA1 ��ָʾ��ͨ�� 
	DMA_SetCurrDataCounter( DMA_CHx , sendnum );//�������û����С,ָ������0
	DMA_Cmd( DMA_CHx , ENABLE ); //ʹ��USART3 TX DMA1 ��ָʾ��ͨ�� 
}










