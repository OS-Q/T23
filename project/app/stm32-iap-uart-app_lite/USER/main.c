#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "iap.h"

int main(void)
{
	u16 times=0;  

	IAP_Init();
	delay_init(72);	    
	NVIC_Configuration();
	uart_init(115200);  
 	LED_Init();	       
	while(1)
	{
		if(USART_RX_STA&0x80)
		{					 
			USART_RX_STA=0;
			IAP_Handle(USART_RX_BUF);
		}else
		{
			times++;
			if(times%30==0)LED0=!LED0;//��˸LED(PC13),��ʾϵͳ��������.
			delay_ms(10);   
		}
	}	 
}

