/******************************************************************************
****�汾��1.0.0
****ƽ̨��
****���ڣ�2020-07-29
****���ߣ�Qitas
****��Ȩ��
*******************************************************************************/

#ifndef __IAP_H_
#define __IAP_H_

#define USE_BKP_SAVE_FLAG       (0)
#define USE_HAL_LIBS_FLAG       (0)

#define   STM32_BASE            (0x08000000) 	//STM32 FLASH����ʼ��ַ
#define   IAP_FLASH_SIZE        (0x3000)      //Bootloader�����С
#define   ApplicationAddress    (STM32_BASE + IAP_FLASH_SIZE) //Ӧ�ó����ַ

#if (USE_BKP_SAVE_FLAG == 1)
  #define INIT_FLAG_DATA      0x0000    //Ĭ�ϱ�־������(��Ƭ�ӵ����)
  #define IAP_FLAG_ADDR       BKP_DR1
#else
  #define INIT_FLAG_DATA      0xFFFF    //Ĭ�ϱ�־������(��Ƭ�ӵ����)
  #define IAP_FLAG_ADDR     (uint32_t)(ApplicationAddress - 1024 * 2) //App�����Bootloader��������Ϣ�ĵ�ַ(�ݶ���СΪ2K)
#endif


#define   UPDATE_FLAG_DATA      0xEEEE   //���ر�־������
#define   UPLOAD_FLAG_DATA      0xDDDD   //�ϴ���־������
#define   ERASE_FLAG_DATA       0xCCCC   //������־������
#define   APPRUN_FLAG_DATA      0x5A5A   //APP����Ҫ���κδ���ֱ������״̬

void iap_init(void);
void iap_writeflag(uint16_t flag);
uint16_t iap_readflag(void);
void IAP_Handle(u8 *mark,u8 * cmd);

#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
