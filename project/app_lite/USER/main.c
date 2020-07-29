/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/

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
		if(times%30==0)
		{
			LED0=!LED0;		//闪烁LED(PC13),提示系统正在运行.
			printf("Qitas APP lite\r\n");
		}
	}
}

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
