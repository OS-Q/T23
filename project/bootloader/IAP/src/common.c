/******************************************************************************
****版本：1.0.0
****平台：
****日期：2020-07-29
****作者：Qitas
****版权：
*******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include "common.h"


/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
void Delay_ms( uint16_t time_ms )
{
	uint16_t i,j;
	for( i=0;i<time_ms;i++ )
	{
		for( j=0;j<4784;j++ );
	}
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/

void STM_EVAL_COMInit(USART_InitTypeDef* USART_InitStruct)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Enable GPIO clock */
	RCC_APB2PeriphClockCmd(EVAL_COM1_TX_GPIO_CLK | EVAL_COM1_RX_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);
	/* Enable UART clock */
	RCC_APB2PeriphClockCmd(EVAL_COM1_CLK, ENABLE);
	/* Configure USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = EVAL_COM1_TX_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EVAL_COM1_TX_GPIO_PORT, &GPIO_InitStructure);
	/* Configure USART Rx as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = EVAL_COM1_RX_PIN;
	GPIO_Init(EVAL_COM1_RX_GPIO_PORT, &GPIO_InitStructure);
	/* USART configuration */
	USART_Init(EVAL_COM1, USART_InitStruct);
	/* Enable USART */
	USART_Cmd(EVAL_COM1, ENABLE);
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
void Int2Str(uint8_t* str, int32_t intnum)
{
	uint32_t i, Div = 1000000000, j = 0, Status = 0;

	for (i = 0; i < 10; i++)
	{
		str[j++] = (intnum / Div) + 48;

		intnum = intnum % Div;
		Div /= 10;
		if ((str[j-1] == '0') & (Status == 0))
		{
			j = 0;
		}
		else
		{
			Status++;
		}
	}
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum)
{
	uint32_t i = 0, res = 0;
	uint32_t val = 0;

	if (inputstr[0] == '0' && (inputstr[1] == 'x' || inputstr[1] == 'X'))
	{
		if (inputstr[2] == '\0')
		{
			return 0;
		}
		for (i = 2; i < 11; i++)
		{
			if (inputstr[i] == '\0')
			{
				*intnum = val;
				/* return 1; */
				res = 1;
				break;
			}
			if (ISVALIDHEX(inputstr[i]))
			{
				val = (val << 4) + CONVERTHEX(inputstr[i]);
			}
			else
			{
				/* return 0, Invalid input */
				res = 0;
				break;
			}
		}
		/* over 8 digit hex --invalid */
		if (i >= 11)
		{
			res = 0;
		}
	}
	else /* max 10-digit decimal input */
	{
		for (i = 0;i < 11;i++)
		{
			if (inputstr[i] == '\0')
			{
				*intnum = val;
				/* return 1 */
				res = 1;
				break;
			}
			else if ((inputstr[i] == 'k' || inputstr[i] == 'K') && (i > 0))
			{
				val = val << 10;
				*intnum = val;
				res = 1;
				break;
			}
			else if ((inputstr[i] == 'm' || inputstr[i] == 'M') && (i > 0))
			{
				val = val << 20;
				*intnum = val;
				res = 1;
				break;
			}
			else if (ISVALIDDEC(inputstr[i]))
			{
				val = val * 10 + CONVERTDEC(inputstr[i]);
			}
			else
			{
				/* return 0, Invalid input */
				res = 0;
				break;
			}
		}
		/* Over 10 digit decimal --invalid */
		if (i >= 11)
		{
			res = 0;
		}
	}

	return res;
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint32_t GetIntegerInput(int32_t * num)
{
	uint8_t inputstr[16];

	while (1)
	{
		GetInputString(inputstr);
		if (inputstr[0] == '\0') continue;
		if ((inputstr[0] == 'a' || inputstr[0] == 'A') && inputstr[1] == '\0')
		{
			SerialPutString(" User Cancelled.\r\n");
			return 0;
		}

		if (Str2Int(inputstr, num) == 0)
		{
			SerialPutString(" Error, Input.\r\n");
		}
		else
		{
			return 1;
		}
	}
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint32_t SerialKeyPressed(uint8_t *key)
{

	if ( USART_GetFlagStatus(EVAL_COM1, USART_FLAG_RXNE) != RESET)
	{
		*key = (uint8_t)EVAL_COM1->DR;
		return 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint8_t GetKey(void)
{
	uint8_t key = 0;
  /* Waiting for user input */
	while (1)
	{
		if (SerialKeyPressed((uint8_t*)&key)) break;
	}
	return key;

}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
void SerialPutChar(uint8_t c)
{
	USART_SendData(EVAL_COM1, c);
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TXE) == RESET)
	{
	}
}


/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
void Serial_PutString(uint8_t *s)
{
#if (ENABLE_PUTSTR == 1)
	while (*s != '\0')
	{
		SerialPutChar(*s);
		s++;
	}
#endif
}

/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
void GetInputString (uint8_t * buffP)
{
	uint32_t bytes_read = 0;
	uint8_t c = 0;
	do
	{
		//SerialPutChar('a');
		c = GetKey();
		if (c == '\n')
		{
			//SerialPutChar('n');
			if(buffP[bytes_read-1] == '\r')
				break;
		}

		if (c == '\b') /* Backspace */
		{
			if (bytes_read > 0)
			{
				//SerialPutString("\b \b");
				bytes_read --;
			}
			continue;
		}
		if (bytes_read >= CMD_STRING_SIZE )
		{
			SerialPutString(" Cmd size over.\r\n");
			bytes_read = 0;
			continue;
		}
		if ((c >= 0x20 && c <= 0x7E) || c == '\r')
		{
			buffP[bytes_read++] = c;
			//SerialPutChar(c);
		}
	}
	while (1);
	SerialPutString(("\r\n"));
	buffP[bytes_read-1] = '\0';
}



/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint32_t FLASH_PagesMask(__IO uint32_t Size)
{
	uint32_t pagenumber = 0x0;
	uint32_t size = Size;

	if ((size % PAGE_SIZE) != 0)
	{
		pagenumber = (size / PAGE_SIZE) + 1;
	}
	else
	{
		pagenumber = size / PAGE_SIZE;
	}
	return pagenumber;
}
/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
uint8_t EraseSomePages(__IO uint32_t size, uint8_t outPutCont)
{
	uint32_t EraseCounter = 0x0;
	uint32_t NbrOfPage = 0;
	uint8_t erase_cont[3] = {0};
	FLASH_Status FLASHStatus = FLASH_COMPLETE;

	NbrOfPage = FLASH_PagesMask(size);

	/* Erase the FLASH pages */
	FLASH_Unlock();
	for (EraseCounter = 0; (EraseCounter < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); EraseCounter++)
	{
		FLASHStatus = FLASH_ErasePage(ApplicationAddress + (PAGE_SIZE * EraseCounter));
		if(outPutCont == 1)
		{
			Int2Str(erase_cont, EraseCounter + 1);
			SerialPutString(erase_cont);
			SerialPutString("@");
		}
	}
	FLASH_Lock();
	if((EraseCounter != NbrOfPage) || (FLASHStatus != FLASH_COMPLETE))
	{
		return 0;
	}
	return 1;
}
/*******************************************************************************
**函数信息 ：
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
*******************************************************************************/
#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{
	while (1)
	{
	}
}
#endif

/*-------------------------(C) COPYRIGHT 2020 QITAS --------------------------*/
