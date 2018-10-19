
#ifndef		_BSP_CAN_H_
#define		_BSP_CAN_H_

#include		"stm32f10x.h"

////定义的can引脚使用PB8和PB9，需要进行引脚的复用功能定义

//#define			CAN_GPIO_CLK_Cmd						RCC_APB2PeriphClockCmd

//#define			CAN_RX_GPIO_PORT						GPIOB
//#define			CAN_RX_GPIO_PIN							GPIO_Pin_8
//#define			CAN_RX_GPIO_CLK							RCC_APB2Periph_GPIOB

//#define			CAN_TX_GPIO_PORT						GPIOB
//#define			CAN_TX_GPIO_PIN							GPIO_Pin_9
//#define			CAN_TX_GPIO_CLK							RCC_APB2Periph_GPIOB

//#define			CAN_CLK_Cmd									RCC_APB1PeriphClockCmd
//#define			CAN_CLK											RCC_APB1Periph_CAN1
//#define 		CAN_RX_IRQ									USB_LP_CAN1_RX0_IRQn
//#define 		CAN_RX_IRQHandler						USB_LP_CAN1_RX0_IRQHandler





//void CAN_Config(void);
//void RxMes_Init(CanRxMsg *RxMessage);
//void CAN_SetMsg(CanTxMsg *TxMessage);



#define 					CANx                       	CAN1
#define 					CAN_CLK                    RCC_APB1Periph_CAN1
#define 					CAN_RX_IRQ									USB_LP_CAN1_RX0_IRQn
#define 					CAN_RX_IRQHandler					USB_LP_CAN1_RX0_IRQHandler

#define 					CAN_RX_PIN                 GPIO_Pin_8
#define 					CAN_TX_PIN                 GPIO_Pin_9
#define 					CAN_TX_GPIO_PORT          GPIOB
#define 					CAN_RX_GPIO_PORT          GPIOB
#define 					CAN_TX_GPIO_CLK           (RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB)
#define 					CAN_RX_GPIO_CLK           RCC_APB2Periph_GPIOB






/*debug*/

#define CAN_DEBUG_ON          1
#define CAN_DEBUG_ARRAY_ON   1
#define CAN_DEBUG_FUNC_ON    1
   
   
// Log define
#define CAN_INFO(fmt,arg...)           printf("<<-CAN-INFO->> "fmt"\n",##arg)
#define CAN_ERROR(fmt,arg...)          printf("<<-CAN-ERROR->> "fmt"\n",##arg)
#define CAN_DEBUG(fmt,arg...)          do{\
                                         if(CAN_DEBUG_ON)\
                                         printf("<<-CAN-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                       }while(0)

#define CAN_DEBUG_ARRAY(array, num)    do{\
                                         int32_t i;\
                                         uint8_t* a = array;\
                                         if(CAN_DEBUG_ARRAY_ON)\
                                         {\
                                            printf("<<-CAN-DEBUG-ARRAY->>\n");\
                                            for (i = 0; i < (num); i++)\
                                            {\
                                                printf("%02x   ", (a)[i]);\
                                                if ((i + 1 ) %10 == 0)\
                                                {\
                                                    printf("\n");\
                                                }\
                                            }\
                                            printf("\n");\
                                        }\
                                       }while(0)

#define CAN_DEBUG_FUNC()               do{\
                                         if(CAN_DEBUG_FUNC_ON)\
                                         printf("<<-CAN-FUNC->> Func:%s@Line:%d\n",__func__,__LINE__);\
                                       }while(0)


void 	CAN_Config(void);
void 	CAN_SetMsg(CanTxMsg *TxMessage);
void 	Init_RxMes(CanRxMsg *RxMessage);

#endif		/* _BSP_CAN_H_ */
























