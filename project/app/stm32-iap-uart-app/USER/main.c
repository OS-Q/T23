#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "usmart.h"
#include "iap.h"

int main(void)
{	 
	u16 i=0;
	IAP_Init();
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	 //���ڳ�ʼ��Ϊ9600
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();	             //��ʼ��LCD
	usmart_dev.init(SystemCoreClock/1000000);	//��ʼ��USMART
	   
	printf("\r\n ����:help��ѯָ��\r\n");	
	while(1)
	{
		i++;
		delay_ms(50);  
		if(i==10)
		{
			LED0=!LED0;//��ʾϵͳ��������	
			i=0;
		}		   
	}   	   
}


