

#include		"include.h"
#include		"bsp.h"
#include		"Tool_PID.h"

uint16_t 	time;
uint8_t  	sendnum = 0;
uint8_t   DMA_Usart_SendData[100];
uint8_t   DMA_Usart_ReadData[100];

CanTxMsg TxMessage;			     //Can发送缓冲区
CanRxMsg RxMessage;				 	 //Can接收缓冲区

typedef struct
{
	uint8_t	data;
	uint16_t	num;
}Mail_Struct;

osThreadId thread1_id;
osThreadId thread2_id;
osThreadId thread3_id;
osThreadId thread4_id;
osThreadId thread5_id;
osThreadId thread6_id;

osMailQDef( mail1 , 100 , Mail_Struct );
osMailQId mail1;
void	thread1(void const *argument)
{
	uint32_t i=0;
	Mail_Struct *Data;
	Data->num = 0;
	for(;;i++)
	{
		Data = osMailAlloc(mail1,osWaitForever);
		Data->data = i;
		Data->num = i+1;
		osMailPut(mail1,Data);
		osDelay(500);
	}
}

void	thread2(void const *argument)
{
	Mail_Struct	*Data;
	osEvent	evt;
	for (;;) 
	{
    evt = osMailGet(mail1, osWaitForever);        // wait for mail
    if (evt.status == osEventMail) 
		{
      Data = evt.value.p;
      if((Data->data)%2==0)
			{
				LED_GREEN;
			}
			else
			{
				LED_RED;
			}
      osMailFree(mail1, Data);                    
    }
		osDelay(500);
	}
}



void	thread3(void const *argument)
{
	uint32_t timing;
	timing = osKernelSysTick();
	while(1)
	{
		
		if( osKernelSysTick() - timing > 10000000 )
		{
			timing = osKernelSysTick();
			LED1_TOGGLE;
		}
		osDelay(10);
	}
}

void	thread4(void const *argument)
{
	uint8_t send = 0;
	uint32_t	signs;
	while(1)
	{
		Usart_SendByte( USART1 , send );
		switch(send%4)
		{
			case 1:
				signs = osSignalSet( thread5_id , 0x0001 );
			break;
			case 2:
				signs = osSignalSet( thread5_id , 0x0002 );
			break;
			case 3:
				signs = osSignalSet( thread5_id , 0x0004 );
			break;
			case 0:
				signs = osSignalSet( thread5_id , 0x0008 );
			break;
		}
		send++;
		osDelay(500);
	}
}

void	thread5(void const *argument)
{
	uint32_t signal;
	osEvent evt;
	while(1)
	{
		evt = osSignalWait (0x0001, 10);
		if (evt.status == osEventSignal)
		{
			LED_GREEN;
			signal = osSignalClear (thread5_id, 0x0001);
		}
		evt = osSignalWait (0x0002, 10);
		if (evt.status == osEventSignal)
		{
			LED_RED;
			signal = osSignalClear (thread5_id, 0x0002);
		}
		evt = osSignalWait (0x0004, 10);
		if (evt.status == osEventSignal)
		{
			LED_BLUE;
			signal = osSignalClear (thread5_id, 0x0004);
		}
		evt = osSignalWait (0x0008, 10);
		if (evt.status == osEventSignal)
		{
			LED_YELLOW;
			signal = osSignalClear (thread5_id, 0x0008);
		}
		osDelay(10);
	}
}

void	thread6(void const *argument)
{
	uint8_t mailbox;
	uint8_t i=0;
	while(1)
	{
		printf("\r\n打印can回环数据\r\n");
		CAN_SetMsg(&TxMessage);
		mailbox = CAN_Transmit(CAN1, &TxMessage);
		while( CAN_TransmitStatus( CAN1 , mailbox ) == CAN_TxStatus_Failed )
		{
			LED_RED;
		}
		LED_GREEN;
		for( i = 0 ; i<8 ; i++ )
		{
			printf("%d\t",RxMessage.Data[i]);
		}
		osDelay(1500);
	}
}

osThreadDef(thread1, osPriorityNormal, 1, 0);
osThreadDef(thread2, osPriorityNormal, 1, 0);
osThreadDef(thread3, osPriorityNormal, 1, 0);
osThreadDef(thread4, osPriorityNormal, 1, 0);
osThreadDef(thread5, osPriorityNormal, 1, 0);
osThreadDef(thread6, osPriorityNormal, 1, 0);

int main(void)
{	
	
  osKernelInitialize (); 

	//设置NVIC分组为组4，抢占优先级0-15；
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	
	RGB_GPIO_Config();
	
//	AdvanceTim_Config();
//	//定时器1的ms重复次数记录time
//	time = 0;
	

	Usart1_Config();
//	Usart2_Config();

	CAN_Config();
	
	
		
	mail1 = osMailCreate(osMailQ(mail1), NULL);
	
//	thread1_id = osThreadCreate (osThread(thread1), NULL);
//	thread2_id = osThreadCreate (osThread(thread2), NULL);
//	thread3_id = osThreadCreate (osThread(thread3), NULL);
//	thread4_id = osThreadCreate (osThread(thread4), NULL);
//	thread5_id = osThreadCreate (osThread(thread5), NULL);
	thread6_id = osThreadCreate (osThread(thread6), NULL);
	
	
//PWN方波输出初始化，周期20ms，占空比75	
//	TIM3_GPIO_Config();
//	TIM3_CH4_PWN_Config(20,75);
	
	
	osKernelStart (); 
	
	while(1)
	{
		osDelay(100);
	}
	
	
}


/*********************************************END OF FILE************************************************/





