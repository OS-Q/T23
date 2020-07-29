/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/
#ifndef __IAP_H__
#define __IAP_H__

#include "stm32f10x.h"


#define UPDATE_FLAG_DATA      0xEEEE   //下载标志的数据
#define UPLOAD_FLAG_DATA      0xDDDD   //上传标志的数据
#define ERASE_FLAG_DATA       0xCCCC   //擦除标志的数据
#define APPRUN_FLAG_DATA      0x5A5A   //APP直接运行


typedef  void (*pFunction)(void);

extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

extern void iap_init(void);
extern uint16_t iap_readflag(void);
extern void iap_writeflag(uint16_t flag);
extern int8_t app_run(void);
extern void iap_menu(void);
extern int8_t iap_update(void);
extern int8_t iap_upload(void);
extern int8_t iap_erase(void);


#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
