#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"


 
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��3
 ��������ʵ��     
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	LED0=0;					//�ȵ������
	while(1)
	{
 		key=KEY_Scan(0);	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//���Ʒ�����
					LED0=0;
				  LED1=1;
				  LED2=1;
				  LED3=1; 
					break; 
				case KEY1_PRES:	//����LED1��ת	 
					LED0=1;
				  LED1=0;
				  LED2=1;
				  LED3=1; 
					break;
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					LED0=1;
				  LED1=1;
				  LED2=0;
				  LED3=1; 
					break;
			}
		}else delay_ms(10); 
	}	 
}

