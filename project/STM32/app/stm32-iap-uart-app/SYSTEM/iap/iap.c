/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/

#include "iap.h"
#include "stmflash.h"
#include <string.h>

/***************************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
****************************************************************************************/
void IAP_WriteFlag(uint16_t flag)
{
#if (USE_BKP_SAVE_FLAG == 1)
	PWR->CR |= PWR_CR_DBP;
	BKP_WriteBackupRegister(IAP_FLAG_ADDR, flag);
	PWR->CR &= ~PWR_CR_DBP;
#else
	FLASH_Unlock();
	STMFLASH_Write(IAP_FLAG_ADDR, &flag, 1);
	FLASH_Lock();
#endif
}
/***************************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
****************************************************************************************/
uint16_t IAP_ReadFlag(void)
{
#if (USE_BKP_SAVE_FLAG == 1)
	return BKP_ReadBackupRegister(IAP_FLAG_ADDR);
#else
	return STMFLASH_ReadHalfWord(IAP_FLAG_ADDR);
#endif
}

/***************************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
****************************************************************************************/
void IAP_Init(void)
{
#if (USE_BKP_SAVE_FLAG == 1)
	RCC->APB1ENR |= (RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN );
#endif
	SCB->VTOR = STM32_FLASH_BASE | IAP_FLASH_SIZE;
}

/***************************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
****************************************************************************************/

void IAP_Handle(u8 * cmd)
{
	if(strcmp((char *)cmd, "update") == 0)
	{
		IAP_WriteFlag(UPDATE_FLAG_DATA);
		NVIC_SystemReset();
	}
	else if(strcmp((char *)cmd, "erase") == 0)
	{
		IAP_WriteFlag(ERASE_FLAG_DATA);
		NVIC_SystemReset();
	}
	else if(strcmp((char *)cmd, "menu") == 0)
	{
		IAP_WriteFlag(INIT_FLAG_DATA);
		NVIC_SystemReset();
	}
	else if(strcmp((char *)cmd, "runapp") == 0)//reset
	{
		NVIC_SystemReset();
	}
	else
	{
		//printf("指令有误\r\n");
		NVIC_SystemReset();
	}
}

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
