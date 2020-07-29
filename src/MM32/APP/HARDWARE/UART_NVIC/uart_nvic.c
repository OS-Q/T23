#include "uart_nvic.h"




#define	UART2_RX_MAX					250
#define	UART2_TX_MAX					250

uint8_t UART_Receive_Buffer[UART2_RX_MAX]={0};
uint8_t UART_Send_Buffer[UART2_TX_MAX]={0};

uint8_t Uart2_Rx_Write =0;
uint8_t Uart2_Rx_Read =0;


extern uint16_t ucTim1Flag;



//串口2中断服务程序

uint8_t Flag_once;

uint8_t Flag_Receive;



void UART2_IRQHandler(void)                	//串口2中断服务程序
{

  if(UART_GetITStatus(UART2, UART_IT_RXIEN))       //接收中断
	{		
        UART_ClearITPendingBit(UART2,UART_IT_RXIEN);
        UART_Receive_Buffer[Uart2_Rx_Write++] = UART_ReceiveData(UART2);
		    ucTim1Flag = 0;   //清计数器  类似于空闲中断
        if(!Flag_once)  
				{
					Flag_once = 1;
					TIM3->CNT = 0;
					TIM_Cmd(TIM3, ENABLE);					
				}	
  } 
  else if(UART_GetITStatus(UART2, UART_IT_TXIEN))  //发送中断
	{
		
		UART_ClearITPendingBit(UART2,UART_IT_TXIEN);
		
	}

		
} 



void UART2_Send_BUFF( uint8_t *Str,uint8_t len)
{
	uint8_t index;
	for(index=0;index<len;index++)
	{
		
		UART_SendData(UART2, Str[index]);
		while(UART_GetFlagStatus(UART2, UART_FLAG_TXEMPTY) == RESET)   // 等待发送缓冲为空
		{
		}
		
	}
	
	
	
	
}


