#include "delay.h"
#include "sys.h"
#include "led.h"
#include "string.h"
#include "uart.h"
#include "uart_nvic.h"
#include "tim3.h"
/********************************************************************************************************
**������Ϣ ��main(void)                     
**�������� ��
**������� ����
**������� ����
********************************************************************************************************/
#define ApplicationAddress  0x08002000          //APP addrress

#define VECTOR_SIZE  0xC0   //48*4=192 = 0xC0   �ж�������cope�Ĵ�С

uint8_t UART_Send_BUF[250]={0x0D,0x0A,0x41,0x50,0x50,0x20,0x49,0x4E,0x49,0x54,
                           0x49,0x41,0x4C,0x20,0x53,0x55,0x43,0x43,0x45,0x53,0x53
                          };//
//0x1F40  RAM
extern uint8_t Flag_Receive;
extern uint8_t UART_Receive_Buffer[250];
extern uint8_t Uart2_Rx_Write,Uart2_Rx_Read;


													
int main(void)    
{

    u8 count;	
	
    memcpy((void*)0x20000000, (void*)ApplicationAddress, VECTOR_SIZE);  //���ж�������ӳ�䵽RAM������  ��M0��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	  SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
	
    delay_init();
    LED_Init();
	  uart_initwBaudRate(115200);
	  Tim3_UPCount_test(48-1,100-1);  // 100us
	
	  UART2_Send_BUFF(UART_Send_BUF,21);
	  
	  count =100;
	
    while(1)              //����ѭ��
    {
//        LED1_TOGGLE();
//        LED2_TOGGLE();
        LED3_TOGGLE();
        LED4_TOGGLE();
        delay_ms(count);
			  if(Flag_Receive)
				{
					Flag_Receive = 0;
					count = UART_Receive_Buffer[0];
					UART2_Send_BUFF(UART_Receive_Buffer,Uart2_Rx_Write);
					Uart2_Rx_Write = 0;					
//					memset(UART_Receive_Buffer,0,250);

				}
			 
    }
}



