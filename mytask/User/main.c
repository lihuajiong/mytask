

#include		"include.h"
#include		"bsp.h"
//#include		"Tool_PID.h"

//uint16_t 	time;
uint8_t  	sendnum = 0;
uint8_t   DMA_Usart_SendData[100];
uint8_t   DMA_Usart_ReadData[100];

CanTxMsg TxMessage;			     //Can���ͻ�����
CanRxMsg RxMessage;				 	 //Can���ջ�����



uint16_t Receive;
uint8_t num = 0;
osThreadId thread7_id;
void	thread7(void const *argument)
{
	uint8_t mailbox;
	uint16_t C;
	while(1)
	{
		if(num==2)
		{
				CAN_SetMsg(&TxMessage);
				printf("\r\n��ӡcan�յ�������\r\n");
				mailbox = CAN_Transmit(CAN1, &TxMessage);
				while( CAN_TransmitStatus( CAN1 , mailbox ) == CAN_TxStatus_Failed )
				{
					LED_RED;
				}
				LED_GREEN;
				C = RxMessage.Data[0]&(RxMessage.Data[1]<<8);
				printf("��е�Ƕȣ�%d\t",C);
				C = RxMessage.Data[2]&(RxMessage.Data[3]<<8);
				printf("ת�٣�%d\t",C);
				num=0;
		}
		osDelay(100);
	}
	
}

osThreadDef(thread7, osPriorityNormal, 1, 0);

int main(void)
{	
	
  osKernelInitialize (); 

	//����NVIC����Ϊ��4����ռ���ȼ�0-15��
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	
//	RGB_GPIO_Config();
	
//	AdvanceTim_Config();
//	//��ʱ��1��ms�ظ�������¼time
//	time = 0;
	

//	Usart1_Config();
//	Usart2_Config();

//	CAN_Config();
	
	
		
//	mail1 = osMailCreate(osMailQ(mail1), NULL);
	
//	thread1_id = osThreadCreate (osThread(thread1), NULL);
//	thread2_id = osThreadCreate (osThread(thread2), NULL);
//	thread3_id = osThreadCreate (osThread(thread3), NULL);
//	thread4_id = osThreadCreate (osThread(thread4), NULL);
//	thread5_id = osThreadCreate (osThread(thread5), NULL);
//	thread6_id = osThreadCreate (osThread(thread6), NULL);
	
	
//PWN���������ʼ��������20ms��ռ�ձ�75	
//	TIM3_GPIO_Config();
//	TIM3_CH4_PWN_Config(20,75);
	

	Usart1_Config();
	CAN_Config();
	thread7_id = osThreadCreate (osThread(thread7), NULL);


	osKernelStart (); 
	
	while(1)
	{
		osDelay(100);
	}
	
	
}


/*********************************************END OF FILE************************************************/





