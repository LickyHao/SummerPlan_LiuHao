#include"stm32f10x.h"
#include"usart_one.h"
#include "usart.h"	
#include"pid.h"






unsigned char kp_usart_change_flag;
unsigned char ki_usart_change_flag;
unsigned char kd_usart_change_flag;
unsigned char speed_usart_change_flag;
unsigned char angle_usart_change_flag;

void usart1_send_string(unsigned char *buf,unsigned int len)
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		 while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);   
		USART_SendData(USART1,buf[i]);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);          
}



void usart_order_execute(void)
{
	if(USART_RX_STA&0x8000)
	{
		if(kp_usart_change_flag==1)
		{
			usart_kp_change();
			kp_eeprom_write();
		}
		
		if(ki_usart_change_flag==1)
		{
			usart_ki_change();
			ki_eeprom_write();
		}
		
		if(kd_usart_change_flag==1)
		{
			usart_kd_change();
			kd_eeprom_write();
		}
		
		if(speed_usart_change_flag==1)
		{
			usart_speed_change();
			speed_eeprom_write();
		}
		
		if(angle_usart_change_flag==1)
		{
			
			
			
		usart_angle_change();
		}
		
		
		
		
		
		
		
		
		
		USART_RX_STA=0;
	}
}














