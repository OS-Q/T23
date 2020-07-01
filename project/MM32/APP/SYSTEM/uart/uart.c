#include "uart.h"
#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif 

#ifdef USE_IAR
PUTCHAR_PROTOTYPE
{
    while((UART1->CSR&UART_IT_TXIEN)==0);//循环发送,直到发送完毕   
    UART1->TDR = (ch & (uint16_t)0x00FF);      
    return ch;
}

#else
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
    int handle; 
    
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
    x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
    while((UART1->CSR&UART_IT_TXIEN)==0);//循环发送,直到发送完毕   
    UART1->TDR = (ch & (uint16_t)0x00FF);      
    return ch;
}

#endif 


void uart_initwBaudRate(u32 bound){
	
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
    UART_InitTypeDef UART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
	

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART2, ENABLE);	//使能UART2
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);  //开启GPIOA时钟
    
    //UART2 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = UART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 3;		//子优先级3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
    
    //UART2 初始化设置
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_1);
    
    UART_InitStructure.UART_BaudRate = bound;//串口波特率
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;   //字长为8位数据格式
    UART_InitStructure.UART_StopBits = UART_StopBits_1;       //一个停止位
    UART_InitStructure.UART_Parity = UART_Parity_No;          //无奇偶校验位
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;  //无硬件数据流控制
    UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;	     //收发模式
    
    UART_Init(UART2, &UART_InitStructure); //初始化串口2
    UART_ITConfig(UART2, UART_IT_RXIEN, ENABLE);  //开启串口接收中断   
    UART_ClearITPendingBit(UART2,UART_IT_RXIEN);  //clear RX IT 
    UART_Cmd(UART2, ENABLE);                      //使能串口2
    
    //UART2_TX   GPIOA.2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PA.2
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.2
    
    //UART2_RX	  GPIOA.3初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.3 

}


