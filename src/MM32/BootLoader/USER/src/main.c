/******************** (C) COPYRIGHT 2009 MM32 ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V3.0.1
* Date               : 04/27/2009
* Description        : Custom HID demo main file
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, MM32 SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "HAL_conf.h"
#include "HAL_device.h"
#include "uart.h"
#include "dfu_mal.h"
#include "Boot.h"
#include "HAL_syscfg.h"
#include "uart_nvic.h"
#include "tim3.h"
#include "protect.h"


#define PROTECT


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : main.
* Description    : main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
//Jump Flag address 0x08001C00
#define ApplicationAddress 0x08002000	//APP Address
#define VECTOR_SIZE  0xC0   //48*4=192 = 0xC0
extern uint8_t Flag_Receive;
uint16_t DFU_state;
typedef  void (*pFunction)(void);
pFunction Jump_To_Application;
uint32_t JumpAddress;


int main(void)
{
    u16 data1,data2;
	uart_initwBaudRate(115200);
#ifdef PROTECT
	data1=*(u32*)0x1ffe0000;//地址Address必须是2的整数倍
	data2=*(u32*)0x1ffe0002;//地址Address必须是2的整数倍
	printf("Pro1=%x,Pro2=%x \r\n",data1,data2);
	if((data1 != 0x7F80)||(data2 != 0xFF00))  //块保护
	{
		FLASH_Unlock();
		if(((data1 != 0xFFFF)||(data2 != 0xFFFF)))
		{
			FLASH_EraseOptionBlock(0x1ffe0000);
		}
		FLASH_EnableReadOutProtection();
		FLASH_UserOptionByteConfig(OB_IWDG_HW,OB_STOP_NoRST,OB_STDBY_NoRST);
		FLASH_Lock();
		printf("\r\nProtect SUCCESS\r\n");
	}
#endif
    DFU_state = 0;
    DFU_state = DFU_read_state();
	printf("DFU state=%x \r\n",DFU_state);
	if(DFU_state == 0x0000)   ///	if( DFU_state == 0xAA55 )
	{
//		__set_FAULTMASK(1); 	 //
		//__disable_irq();
		/* Test if user code is programmed starting from address "ApplicationAddress" */
		if(((*(__IO uint32_t*)ApplicationAddress) & 0x2FFE0000 ) == 0x20000000)	//检查栈顶地址是否合法
		{
			/* Jump to user application */
			JumpAddress = *(__IO uint32_t*) (ApplicationAddress + 4);
			Jump_To_Application = (pFunction) JumpAddress;
			/* Initialize user application's Stack Pointer */
			__set_MSP(*(__IO uint32_t*) ApplicationAddress);
			//Jump to APP
			Jump_To_Application();
		}
	}
  	Tim3_UPCount_test(48-1,100-1);  // 100us定时
	while (1)
	{
		APP_Update();
	}
}

/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
* Output         : None
* Return         : None
*******************************************************************************/
void Delay(__IO uint32_t nCount)
{
  for(; nCount!= 0;nCount--);
}

#ifdef  USE_FULL_ASSERT
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while(1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2009 MM32 *****END OF FILE****/
