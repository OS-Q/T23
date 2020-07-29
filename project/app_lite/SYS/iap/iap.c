/******************************************************************************
****�汾��1.0.0
****ƽ̨��
****���ڣ�2020-07-29
****���ߣ�Qitas
****��Ȩ��
*******************************************************************************/

#include <string.h>

#include "stmflash.h"
#include "iap.h"

/*******************************************************************************
**������Ϣ ��
**�������� ��
**������� ����
**������� ����
*******************************************************************************/
void iap_reset(void)
{
#if (USE_HAL_LIBS_FLAG == 1)
	HAL_NVIC_SystemReset();
#else
	NVIC_SystemReset();
#endif
}
/*******************************************************************************
**������Ϣ ��
**�������� ��
**������� ����
**������� ����
*******************************************************************************/
void iap_writeflag(uint16_t flag)
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

/*******************************************************************************
**������Ϣ ��
**�������� ��
**������� ����
**������� ����
*******************************************************************************/
uint16_t iap_readflag(void)
{
#if (USE_BKP_SAVE_FLAG == 1)
	return BKP_ReadBackupRegister(IAP_FLAG_ADDR);
#else
	return STMFLASH_ReadHalfWord(IAP_FLAG_ADDR);
#endif
}


/*******************************************************************************
**������Ϣ ��
**�������� ��
**������� ����
**������� ����
*******************************************************************************/
void iap_init(void)
{
#if (USE_BKP_SAVE_FLAG == 1)
	RCC->APB1ENR |= (RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN );
#endif
	SCB->VTOR = STM32_FLASH_BASE | IAP_FLASH_SIZE;
}



/*******************************************************************************
**������Ϣ ��
**�������� ��
**������� ����
**������� ����
*******************************************************************************/
void IAP_Handle(u8 *mark,u8 * cmd)
{
	if(mark[0]&0x80)
	{
		mark[0]=0;
		if(strcmp((char *)cmd, "update") == 0)
		{
			iap_writeflag(UPDATE_FLAG_DATA);
			iap_reset();
		}
		else if(strcmp((char *)cmd, "erase") == 0)
		{
			iap_writeflag(ERASE_FLAG_DATA);
			iap_reset();
		}
		else if(strcmp((char *)cmd, "menu") == 0)
		{
			iap_writeflag(INIT_FLAG_DATA);
			iap_reset();
		}
		else if(strcmp((char *)cmd, "runapp") == 0)//reset
		{
			iap_reset();
		}
		else
		{
			printf("ָ������\r\n");
			iap_reset();
		}
	}
}

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
