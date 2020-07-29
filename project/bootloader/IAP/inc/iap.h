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

/* Define the Flsah area size ---------------------------------*/
#if defined (STM32F10X_MD) || defined (STM32F10X_MD_VL)
 #define PAGE_SIZE                         (0x400)    /* 1 Kbyte */
 #define FLASH_SIZE                        (0x20000)  /* 128 KBytes */
#elif defined STM32F10X_CL
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x40000)  /* 256 KBytes */
#elif defined STM32F10X_HD || defined (STM32F10X_HD_VL)
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x80000)  /* 512 KBytes */
#elif defined STM32F10X_XL
 #define PAGE_SIZE                         (0x800)    /* 2 Kbytes */
 #define FLASH_SIZE                        (0x100000) /* 1 MByte */
#else
 #error "Please select first the STM32 device to be used (in stm32f10x.h)"
#endif


typedef  void (*pFunction)(void);

extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

extern void IAP_Init(void);
extern uint16_t IAP_ReadFlag(void);
extern void IAP_WriteFlag(uint16_t flag);
extern int8_t IAP_RunApp(void);
extern void IAP_Main_Menu(void);
extern int8_t IAP_Update(void);
extern int8_t IAP_Upload(void);
extern int8_t IAP_Erase(void);


#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
