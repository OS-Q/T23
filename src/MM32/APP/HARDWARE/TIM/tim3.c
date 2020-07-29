#include "tim3.h" 
#include "led.h"

extern uint8_t Flag_once;

uint16_t ucTim1Flag;

/********************************************************************************************************
**������Ϣ ��void TIM2_IRQHandler(void)                  
**�������� ����ʱ��2�жϺ���
**������� ����
**������� ����
********************************************************************************************************/
void TIM3_IRQHandler(void)
{
    /*�����ֶ�����жϱ�־λ*/
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    
    /*ȫ�ֱ�־*/
    ucTim1Flag++;
	
	  if(ucTim1Flag >2)  //300us û�н��յ������򱾴����ݽ������
		{
			 ucTim1Flag = 0;
			 TIM_Cmd(TIM3, DISABLE);
       Flag_Receive = 1;			
			 Flag_once = 0;
		}
	   
//    LED4_TOGGLE() ;
}

/********************************************************************************************************
**������Ϣ ��void Tim2_UPCount_test1(u16 Period,u16 Prescaler)                     
**�������� �����ö�ʱ��2���ϼ���ģʽ
**������� ��Period 16λ����������ֵ
Prescaler ʱ��Ԥ��Ƶֵ
**������� ����
********************************************************************************************************/
void Tim3_UPCount_test(u16 Prescaler,u16 Period)
{
    TIM_TimeBaseInitTypeDef TIM_StructInit;
    NVIC_InitTypeDef NVIC_StructInit;
    
    /*ʹ��TIM1ʱ��,Ĭ��ʱ��ԴΪPCLK1(PCLK1δ��Ƶʱ����Ƶ,������PCLK1��Ƶ���),��ѡ����ʱ��Դ*/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    
    
    TIM_StructInit.TIM_Period=Period;                                                                      //ARR�Ĵ���ֵ
    TIM_StructInit.TIM_Prescaler=Prescaler;                                                                //Ԥ��Ƶֵ
    /*�����˲�������Ƶ��,��Ӱ�춨ʱ��ʱ��*/
    TIM_StructInit.TIM_ClockDivision=TIM_CKD_DIV1;                                                         //������Ƶֵ
    TIM_StructInit.TIM_CounterMode=TIM_CounterMode_Up;                                                     //����ģʽ
    TIM_StructInit.TIM_RepetitionCounter=0;
    
    TIM_TimeBaseInit(TIM3, &TIM_StructInit);
    
    /* ���ö�ʱ��3�ж�ͨ�������ȼ� */
    NVIC_StructInit.NVIC_IRQChannel=TIM3_IRQn;
    NVIC_StructInit.NVIC_IRQChannelPriority=1;
    NVIC_StructInit.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_StructInit);
    
    /*���¶�ʱ��ʱ���������ʱ��,�����־λ*/
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    /*����ʱ��2�����ж�*/
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM3->CNT = 0;
//    TIM_Cmd(TIM3, ENABLE);	
		
		
}


