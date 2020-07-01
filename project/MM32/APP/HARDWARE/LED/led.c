#include "led.h"

/********************************************************************************************************
**函数信息 ：LED_Init(void)                        
**功能描述 ：LED初始化
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/
void LED_Init(void)
{
 
    /********************
	  LED  PWM  
	  HIGH
	  PWM0  PWMA PA8     TIM1_CH1  
	  PWM1  PWMB PA7     TIM3_CH2
	  PWM2  PA9     TIM1_CH2
	  PWM3  PB0     TIM3_CH3
	 
	  LOW
	
		
	 ****/
	
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOB, ENABLE);  //开启GPIOA,GPIOB时钟

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);  //开启GPIOD
	
 	
    GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_8 | GPIO_Pin_15;  //|GPIO_Pin_13|GPIO_Pin_14
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
		
//	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource13, GPIO_AF_7);   //PA13 PA14 配置成普通IO口
//    GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_7);		
		
  

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1;   // PD口配置普通IO口
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
		
	
	
    GPIO_SetBits(GPIOB,GPIO_Pin_5);  //点亮LED
  	GPIO_SetBits(GPIOA,GPIO_Pin_8); 
  	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		  	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
//	  GPIO_SetBits(GPIOA,GPIO_Pin_15);  //system power on

}

