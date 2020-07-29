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
	iap_init();
	while(1)
	{
		switch(iap_readflag())
		{
			case APPRUN_FLAG_DATA:
				if(app_run()) iap_writeflag(INIT_FLAG_DATA);
				break;
			case INIT_FLAG_DATA:
				iap_menu();
				break;
			case UPDATE_FLAG_DATA:
				if(!iap_update()) iap_writeflag(APPRUN_FLAG_DATA);
				else iap_writeflag(INIT_FLAG_DATA);
				break;
			case UPLOAD_FLAG_DATA:
				if(!iap_upload()) iap_writeflag(APPRUN_FLAG_DATA);
				else iap_writeflag(INIT_FLAG_DATA);
				break;
			case ERASE_FLAG_DATA:
				iap_erase();
				iap_writeflag(INIT_FLAG_DATA);
				break;
			default:
				break;
		}
	}
}


/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
