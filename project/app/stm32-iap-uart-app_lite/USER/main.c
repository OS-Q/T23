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
		IAP_Handle(&USART_RX_STA,USART_RX_BUF);
		times++;
		delay_ms(10);
		if(times%50==0)
		{
			LED0=!LED0;			//��˸LED(PC13),��ʾϵͳ��������.
			printf("qitas test app lite\r\n");
		}
	}
}

