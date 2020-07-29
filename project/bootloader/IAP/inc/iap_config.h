/******************************************************************************
****�汾��1.0.0
****ƽ̨��
****���ڣ�2020-07-29
****���ߣ�Qitas
****��Ȩ��
*******************************************************************************/
#ifndef __IAP_CONFIG_H__
#define __IAP_CONFIG_H__

/* Define if use bkp save flag  -------------------------------*/
#define USE_BKP_SAVE_FLAG     (0)

/* Define the APP start address -------------------------------*/
#define ApplicationAddress    0x8003000

/* Output printer switch --------------------------------------*/
#define ENABLE_PUTSTR         1

/* Bootloader command -----------------------------------------*/
#define CMD_UPDATE_STR        "update"
#define CMD_UPLOAD_STR        "upload"
#define CMD_ERASE_STR		      "erase"
#define CMD_MENU_STR          "menu"
#define CMD_RUNAPP_STR        "runapp"
#define CMD_ERROR_STR         "error"
#define CMD_DISWP_STR         "diswp"   //��ֹд����

/* IAP command------------------------------------------------ */
#if (USE_BKP_SAVE_FLAG == 1)
  #define IAP_FLAG_ADDR    BKP_DR1
#else
  #define IAP_FLAG_ADDR   (uint32_t)(ApplicationAddress - 1024 * 2)//App�����Bootloader��������Ϣ�ĵ�ַ(�ݶ���СΪ2K)
#endif

//#define IAP_FLASH_FLAG_ADDR   0x8002800

#if (USE_BKP_SAVE_FLAG == 1)
  #define INIT_FLAG_DATA      0x0000  //Ĭ�ϱ�־������(��Ƭ�ӵ����)
#else
  #define INIT_FLAG_DATA      0xFFFF   //Ĭ�ϱ�־������(��Ƭ�ӵ����)
#endif
#define UPDATE_FLAG_DATA      0xEEEE   //���ر�־������
#define UPLOAD_FLAG_DATA      0xDDDD   //�ϴ���־������
#define ERASE_FLAG_DATA       0xCCCC   //������־������
#define APPRUN_FLAG_DATA      0x5A5A   //APP����Ҫ���κδ���ֱ������״̬



/* Compute the FLASH upload image size --------------------------*/
#define FLASH_IMAGE_SIZE                   (uint32_t) (FLASH_SIZE - (ApplicationAddress - 0x08000000))

/* The maximum length of the command string -------------------*/
#define CMD_STRING_SIZE       128

#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
