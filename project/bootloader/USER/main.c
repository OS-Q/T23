/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/

#include "common.h"
#include "iap.h"

int main(void)
{
	IAP_Init();
	while(1)
	{
		switch(IAP_ReadFlag())
		{
			case APPRUN_FLAG_DATA:	//jump to app
				if( IAP_RunApp()) IAP_WriteFlag(INIT_FLAG_DATA);
				break;
			case INIT_FLAG_DATA://initialze state (blank mcu)
				IAP_Main_Menu();
				break;
			case UPDATE_FLAG_DATA:	// download app state
				if( !IAP_Update()) IAP_WriteFlag(APPRUN_FLAG_DATA);
				else IAP_WriteFlag(INIT_FLAG_DATA);
				break;
			case UPLOAD_FLAG_DATA:	// upload app state
				if( !IAP_Upload())IAP_WriteFlag(APPRUN_FLAG_DATA);
				else IAP_WriteFlag(INIT_FLAG_DATA);
				break;
			case ERASE_FLAG_DATA:	// erase app state
				IAP_Erase();
				IAP_WriteFlag(INIT_FLAG_DATA);
				break;
			default:
				break;
		}
	}
}


/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
