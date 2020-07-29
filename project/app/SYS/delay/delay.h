#ifndef __DELAY_H
#define __DELAY_H

#include "sys.h"
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos 使用
#endif

void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/























