#include "Boot.h"
#include "dfu_mal.h"

#include "dfu_mal.h"

#include "HAL_device.h"
#include "uart_nvic.h"
#include "string.h"

#define JUMP_Flag_address  0x08001C00

extern uint8_t Flag_Receive;
extern uint8_t UART_Receive_Buffer[250];;
extern uint8_t UART_Send_Buffer[250];
extern uint8_t Uart2_Rx_Write;


uint8_t LEN = 0;



/*************************************************************************************************************************/

void Boot_MAL_Erase_app()     // 
{
   uint32_t Address;
   uint8_t index,temp;
   UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;
	 temp = 57;  //57 K
   Address = JUMP_Flag_address+0x400;         // APP flash   0x08002000 -- 0x08010000  (57K app 空间 0x0E400)  APP起始地址
	 FLASH_Unlock();  
	 FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
   for(index=0;index<temp;index++ )   //把需要使用到的APP空间擦除
   	{   	
     FLASH_ErasePage(Address);
	   Address = Address + 0x400;   
   	}
   FLASH_Lock();
   UART2_Send_BUFF(UART_Send_Buffer,LEN);
}

/*
uint16_t MAL_Erase(uint32_t SectorAddress)	//´æ´¢Éè±¸²Á³ýµ÷ÓÃº¯Êý
{
	FLASH_ErasePage(SectorAddress);	//Ñ¡ÔñÒ³²Á³ýº¯Êý

	return MAL_OK;
}
*/

/**********************************************************************************/
/*
uint16_t MAL_Write (uint32_t SectorAddress, uint32_t DataLength)	//ÍùFLASHÐ´ÈëÊý¾Ý
{
	uint32_t idx = 0;

	if(DataLength & 0x3)	//Êý¾Ý¶ÔÆë
	{
		for(idx = DataLength; idx < ((DataLength & 0xFFFC) + 4); idx++)
		{
			MAL_Buffer[idx] = 0xFF;
		}
	}

	//¿ªÊ¼Ð´ÈëDataLength³¤¶ÈÊý¾Ý    
	for (idx = 0; idx <  DataLength; idx = idx + 4)
	{
		FLASH_ProgramWord(SectorAddress, *(uint32_t *)(MAL_Buffer + idx));  
		SectorAddress += 4;
	}

	return MAL_OK;
}
*/
/**********************************************************************************/

/*
void FLASH_WriteByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num)
{
	uint32_t HalfWord;
	Byte_Num = Byte_Num/2;
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	while(Byte_Num --)
	{
		HalfWord=*(p++);
		HalfWord|=*(p++)<<8;
		MAL_Write(addr, HalfWord);
		addr += 2;
	}
	FLASH_Lock();
}


*/

void FLASH_WriteByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num)
{
	uint32_t HalfWord;
	Byte_Num = Byte_Num/2;
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	while(Byte_Num --)
	{
		HalfWord=*(p++);
		HalfWord|=*(p++)<<8;
	//	MAL_Write(addr, HalfWord);
		addr += 2;
	}
	FLASH_Lock();
}



void DFU_MAL_Write_onebulk()

{
	uint32_t HalfWord;
//  uint8_t  *writeBuff=NULL;	
  uint16_t  temp ,writeNumber;
  uint32_t WriteAddress;
	


	writeNumber = UART_Receive_Buffer[1];
	writeNumber = writeNumber - 8;
	writeNumber = writeNumber/2;
  WriteAddress = ((UART_Receive_Buffer[5]<<24)+(UART_Receive_Buffer[4]<<16)+(UART_Receive_Buffer[3]<<8)+UART_Receive_Buffer[2]);
	
  FLASH_Unlock();
  FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
for(temp=0;temp<writeNumber;temp++)
{
   HalfWord =  UART_Receive_Buffer[(2*temp)+6];
	 HalfWord = HalfWord | (UART_Receive_Buffer[(2*temp)+7]<<8);
   FLASH_ProgramHalfWord(WriteAddress, HalfWord);
	 WriteAddress = WriteAddress + 2;
}
			 
  FLASH_Lock();
	UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;		
	UART2_Send_BUFF(UART_Send_Buffer,LEN); 
    
}


/*


void DFU_MAL_Write_onebulk()

{
	uint32_t HalfWord;
  uint8_t  *writeBuff=NULL;	
  uint16_t  temp ,writeNumber;
  uint32_t WriteAddress;
	
  UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;		

	writeNumber = UART_Receive_Buffer[1];
	writeNumber = writeNumber - 8;
  WriteAddress = ((UART_Receive_Buffer[5]<<24)+(UART_Receive_Buffer[4]<<16)+(UART_Receive_Buffer[3]<<8)+UART_Receive_Buffer[2]);
	for(temp=0;temp<writeNumber;temp++)
	{ 
  	*(writeBuff+temp) =  UART_Receive_Buffer[6+temp];
	}
	
	FLASH_WriteByte(WriteAddress , writeBuff , writeNumber);
	
	UART2_Send_BUFF(UART_Send_Buffer,LEN); 
    
}




*/

void Clear_DFU_State()   // 把BOOT 标志位清除
{
         uint32_t HalfWord;
         FLASH_Unlock();
         FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
		     FLASH_ErasePage(JUMP_Flag_address);
         HalfWord = 0xFFFF;
         FLASH_ProgramHalfWord(JUMP_Flag_address, HalfWord);

         FLASH_Lock();
}


void DFU_MAL_Read()   // 读取Flash数据
{
  uint8_t  *readBuff=NULL;	
  uint32_t  temp,ReadNumber;
  uint32_t  ReadAddress;

	UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;
	UART_Send_Buffer[1] = UART_Receive_Buffer[1];
  UART_Send_Buffer[2] = UART_Receive_Buffer[2];
  UART_Send_Buffer[3] = UART_Receive_Buffer[3];
	UART_Send_Buffer[4] = UART_Receive_Buffer[4];
	UART_Send_Buffer[5] = UART_Receive_Buffer[5];
	
  ReadNumber = UART_Receive_Buffer[1];
	ReadNumber = ReadNumber - 8;
  ReadAddress = ((UART_Receive_Buffer[5]<<24)+(UART_Receive_Buffer[4]<<16)+(UART_Receive_Buffer[3]<<8)+UART_Receive_Buffer[2]); 	
  readBuff = MAL_Read (ReadAddress, ReadNumber);
	
	 for(temp=0;temp<ReadNumber;temp++)
	 {	
		UART_Send_Buffer[6+temp]   = (*(readBuff+temp))&0xff;
	 }
	 
	UART2_Send_BUFF(UART_Send_Buffer,LEN);  
}


void Setting_flags()  //设置BOOT标志位
{ 

   FLASH_Unlock();   
   FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
   FLASH_ErasePage(JUMP_Flag_address);
   FLASH_ProgramHalfWord(JUMP_Flag_address, 0x0000);
   FLASH_Lock(); 
}




void DFU_writeoneword_state()  
{   
   FLASH_Unlock();   
   FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	 FLASH_ErasePage(JUMP_Flag_address);
   FLASH_ProgramHalfWord(JUMP_Flag_address, 0x0000);
   FLASH_Lock();   
   UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;	
   UART2_Send_BUFF(UART_Send_Buffer,LEN);

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

uint16_t DFU_read_state()  //把对应地址的BOOT标志位读出来
{
	uint8_t  *Buff = NULL;
	  
	uint16_t ReadDATA = 0;

	Buff = MAL_Read (JUMP_Flag_address, 2);

	ReadDATA = (Buff[1]<<8)+Buff[0];

	return ReadDATA;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void DFU_read_state_UP()   //把BOOT标志位读出来上传给上位机软件
{

  uint8_t  *Buff = NULL;	
  uint32_t  temp;

  UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;
  
   Buff = MAL_Read (JUMP_Flag_address, 2);	
 
	 for(temp=0;temp<2;temp++)
	 {	
		UART_Send_Buffer[1+temp]  = (*(Buff+temp))&0xff;
	 }
	 
   UART2_Send_BUFF(UART_Send_Buffer,LEN);  
}




void Write_BOOT_Data()  // 写Flash数据
{
   DFU_MAL_Write_onebulk();
}


void Reset_Boot_Firmware()   // 复位Boot程序
{

   UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;   
   UART2_Send_BUFF(UART_Send_Buffer,LEN);	
   Setting_flags();
	

//   __set_FAULTMASK(1);      // ¹Ø±ÕËùÓÐÖÐ¶Ï
   NVIC_SystemReset();  // ¸´Î»
	
}

void Boot_Firmware()  
{
	 UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;   
   UART2_Send_BUFF(UART_Send_Buffer,LEN);	
	 FLASH_Unlock();   
   FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	 FLASH_ErasePage(JUMP_Flag_address);
// FLASH_ProgramHalfWord(JUMP_Flag_address, 0xFFFF);
   FLASH_Lock();
	
//   __set_FAULTMASK(1);      // ¹Ø±ÕËùÓÐÖÐ¶Ï
   NVIC_SystemReset();  // ¸´Î»
}

void Verify_Boot_Firmware()   //校验Flash数据
{
   DFU_MAL_Read();
}

void Repuly_version_number()   //把当前boot版本号上传给上位机软件
{
   UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;
	 UART_Send_Buffer[1] = UART_Receive_Buffer[1];
	 UART_Send_Buffer[2] = 0x11;
	 UART_Send_Buffer[3] = 0x00;
	 UART_Send_Buffer[4] = 0x00;
	 UART_Send_Buffer[5] = 0xFF;
   UART2_Send_BUFF(UART_Send_Buffer,LEN);
}


void Reset_Firmware()
{
 	 UART_Send_Buffer[0] = UART_Receive_Buffer[0] | 0xC0;   
   UART2_Send_BUFF(UART_Send_Buffer,LEN);	

//   __set_FAULTMASK(1);      // ¹Ø±ÕËùÓÐÖÐ¶Ï
   NVIC_SystemReset();  // ¸´Î»
}


/*************************************************************************************************************************/



void APP_Update(void)
{
	uint8_t host_cmd = 0;

	if(Flag_Receive)
		{

		 Flag_Receive=0;			
 		 LEN = UART_Receive_Buffer[1];       // 第二个字节代表有效字符长度
		 host_cmd = UART_Receive_Buffer[0];  // 第一个字节代表指令
             
 			switch(host_cmd)        // Call correct subroutine to handle each kind of
			{                             // standard request
				case 0x00:
         Repuly_version_number(); //回复当前software 版本号
					break;
				
				 case 0x20:
		    Boot_Firmware();         //
					
				case 0x21:
			  Write_BOOT_Data();  //Boot模式下写APP程序
					break;
					
				case 0x22:
					Reset_Boot_Firmware();  //APP校验正确写好Boot标志位并复位系统
					break;
					
				case 0x23:
					Boot_MAL_Erase_app();  //Boot模式下擦除APP程序区数据
					break;
					
			    case 0x24:
 		    Verify_Boot_Firmware();  //校验Boot程序数据
					break;
					
					case 0x25:
						Reset_Firmware();   //在Boot升级模式下复位系统
					
				case 0x31:
		     DFU_read_state_UP();  //读Boot标志位
					break;
					
				case 0x32:
			DFU_writeoneword_state(); //写标志位
					break;
					
				case 0x33:
			Clear_DFU_State();       //清除Boot标志位
					break;
					
				default:
						// unknow command, do nothing.
					break;
				} 
			
				memset(UART_Send_Buffer, 0, sizeof(UART_Send_Buffer));        //clear send buff
				memset(UART_Receive_Buffer, 0, sizeof(UART_Receive_Buffer));  //clear receive buff
        Uart2_Rx_Write = 0;
		}

		
		
}




/***************************end of file****************************************************/



