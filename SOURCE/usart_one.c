#include"stm32f10x.h"
#include"usart_one.h"
#include "usart.h"	
#include"pid.h"






unsigned char kp_usart_change_flag;  //���崮��Kp�ı��־λ
unsigned char ki_usart_change_flag;//���崮��Ki�ı��־λ
unsigned char kd_usart_change_flag;//���崮��Kd�ı��־λ
unsigned char speed_usart_change_flag;//���崮���ٶȸı��־λ
unsigned char angle_usart_change_flag;//���崮�ڽǶȸı��־λ

void usart1_send_string(unsigned char *buf,unsigned int len) //�����ַ������ͺ���
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		 while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);   
		USART_SendData(USART1,buf[i]);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);          
}



void usart_order_execute(void) //���ɿڽ��պ���
{
	if(USART_RX_STA&0x8000)  //����Ƿ�������
	{
		if(kp_usart_change_flag==1) //�������Kp�ı��־λΪ1����ı�PID�����е�Kp�������浽eeprom
		{
			usart_kp_change();
			kp_eeprom_write();
		}
		
		if(ki_usart_change_flag==1)//�������Ki�ı��־λΪ1����ı�PID�����е�Ki�������浽eeprom
		{
			usart_ki_change();
			ki_eeprom_write();
		}
		
		if(kd_usart_change_flag==1)//�������Kd�ı��־λΪ1����ı�PID�����е�Kd�������浽eeprom
		{
			usart_kd_change();
			kd_eeprom_write();
		}
		
		if(speed_usart_change_flag==1)//��������ٶȸı��־λΪ1����ı��趨�ٶȣ������浽eeprom��
		{
			usart_speed_change();
			speed_eeprom_write();
		}
		
		if(angle_usart_change_flag==1)//������ڽǶȸı��־λΪ1����ı��趨�Ƕȣ������浽eeprom��
		{
			
			
			
		usart_angle_change();
		}
		
		
		
		
		
		
		
		
		
		USART_RX_STA=0;//�����־λ
	}
}














