/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/

#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "stm32f10x.h"
#include "stm32f10x_flash.h"
#include "common.h"


extern u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字
extern void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
extern void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据

#endif


/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/














