#ifndef __LED_H
#define __LED_H	 
#include "HAL_conf.h"

//////////////////////////////////////////////////////////////////////////////////	 
//开发板
//LED驱动代码	   
////////////////////////////////////////////////////////////////////////////////// 



#define LED4_TOGGLE()  (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_15))?(GPIO_ResetBits(GPIOA,GPIO_Pin_15)):(GPIO_SetBits(GPIOA,GPIO_Pin_15))	// PA15



#define LED3_ON()  GPIO_ResetBits(GPIOD,GPIO_Pin_1)	// PD1
#define LED3_OFF()  GPIO_SetBits(GPIOD,GPIO_Pin_1)	// PD1
#define LED3_TOGGLE()  (GPIO_ReadOutputDataBit(GPIOD,GPIO_Pin_1))?(GPIO_ResetBits(GPIOD,GPIO_Pin_1)):(GPIO_SetBits(GPIOD,GPIO_Pin_1))	// PD1



#define LED2_ON()  GPIO_ResetBits(GPIOD,GPIO_Pin_0)	// PD0
#define LED2_OFF()  GPIO_SetBits(GPIOD,GPIO_Pin_0)	// PD0
#define LED2_TOGGLE()  (GPIO_ReadOutputDataBit(GPIOD,GPIO_Pin_0))?(GPIO_ResetBits(GPIOD,GPIO_Pin_0)):(GPIO_SetBits(GPIOD,GPIO_Pin_0))	// PD0



#define LED1_ON()  GPIO_ResetBits(GPIOB,GPIO_Pin_5)	// PB5
#define LED1_OFF()  GPIO_SetBits(GPIOB,GPIO_Pin_5)	// PB5
#define LED1_TOGGLE()  (GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5))?(GPIO_ResetBits(GPIOB,GPIO_Pin_5)):(GPIO_SetBits(GPIOB,GPIO_Pin_5))	// PB5

void LED_Init(void);//初始化

		 				    
#endif
