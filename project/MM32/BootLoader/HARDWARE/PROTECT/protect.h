#ifndef   __PROTECT_H_
#define    __PROTECT_H_
#include "sys.h"

void FLASH_EnableReadOutProtection(void);
FLASH_Status FLASH_ProgramOptionHalfWord(unsigned int u32addressBase,unsigned int u32addressoffset,unsigned short u16Data);
FLASH_Status FLASH_EraseOptionBlock(unsigned int u32addressBase);




#endif


/**********************************end of file**********************************************************/


