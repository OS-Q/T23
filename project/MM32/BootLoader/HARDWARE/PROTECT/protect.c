#include "sys.h"
#include "protect.h"



void FLASH_EnableReadOutProtection(void)
{
		if(0xffff!=*(u16*)(0x1ffe0000+0))//??????? //0x1ffe0000
	{
		FLASH_EraseOptionBlock(0x1ffe0000);
	}
	FLASH_ProgramOptionHalfWord(0x1ffff800,0,0x807F);
	FLASH_ProgramOptionHalfWord(0x1ffe0000,0,0x7F80);
	FLASH_ProgramOptionHalfWord(0x1ffe0000,2,0xFF00);
	
}


/**
* @brief  Erases the FLASH option bytes.
* @param  None
* @retval : FLASH Status: The returned value can be: FLASH_BUSY, 
*   FLASH_ERROR_PG, FLASH_ERROR_WRP, FLASH_COMPLETE or 
*   FLASH_TIMEOUT.
*/
FLASH_Status FLASH_EraseOptionBlock(unsigned int u32addressBase)
{
    FLASH_Status status = FLASH_COMPLETE;
    
    FLASH->AR = u32addressBase;
    
    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation(0x00000FFF);
    if(status == FLASH_COMPLETE)
    {
        /* Authorize the small information block programming */
        FLASH->OPTKEYR = 0x45670123;
        FLASH->OPTKEYR = 0xCDEF89AB;
        
        /* if the previous operation is completed, proceed to erase the option bytes */
        FLASH->CR |= 0x00000020;
        FLASH->CR |= 0x00000040;
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation(0x00000FFF);
        
        if(status == FLASH_COMPLETE)
        {
            /* if the erase operation is completed, disable the OPTER Bit */
            FLASH->CR &= 0x00001FDF;
            
            {
                /* if the program operation is completed, disable the OPTPG Bit */
                FLASH->CR &= 0x00001FEF;
            }
        }
        else
        {
            if (status != FLASH_BUSY)
            {
                /* Disable the OPTPG Bit */
                FLASH->CR &= 0x00001FEF;
            }
        }  
    }
    
    /* Return the erase status */
    return status;
}

FLASH_Status FLASH_ProgramOptionHalfWord(unsigned int u32addressBase,unsigned int u32addressoffset,unsigned short u16Data)
{
  FLASH_Status status = FLASH_COMPLETE;
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  status = FLASH_WaitForLastOperation(0x00000FFF);
  if(status == FLASH_COMPLETE)
  {
      /* Authorize the FPEC Access */
    FLASH->KEYR = 0x45670123;
    FLASH->KEYR = 0xCDEF89AB;
	  
    /* Authorizes the small information block programming */
    FLASH->OPTKEYR = 0x45670123;
    FLASH->OPTKEYR = 0xCDEF89AB;

	/* if the program operation is completed, disable the OPTPG Bit */

	if(0xffff!=*(u16*)(u32addressBase+u32addressoffset))//??????? //0x1ffe0000
	{
		FLASH_EraseOptionBlock(u32addressBase);
	}
	{
		FLASH->CR &= 0x00001FEF;
		  /* Enables the Option Bytes Programming operation */
		FLASH->CR |= 0x00000010; 
		*(__IO uint16_t*)(u32addressBase+u32addressoffset) =u16Data;//0x01FE;//0x00FF;//0x807F;//0x817E;// 0x7E81;//0x807F;//
		
		/* Wait for last operation to be completed */
		status = FLASH_WaitForLastOperation(0x0000000F);
		if(status == FLASH_COMPLETE)
		{
		}
		else{
			if(status != FLASH_BUSY)
			{
				/* if the program operation is completed, disable the OPTPG Bit */
				FLASH->CR &= 0x00001FEF;
				/* Enables the Option Bytes Programming operation */
			}
		}
	}
  }

  /* Return the protection operation Status */
  return status;      
}


