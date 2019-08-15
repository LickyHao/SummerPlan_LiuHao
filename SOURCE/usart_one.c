#include"stm32f10x.h"
#include"usart_one.h"
#include "usart.h"	
#include"pid.h"






unsigned char kp_usart_change_flag;  //定义串口Kp改变标志位
unsigned char ki_usart_change_flag;//定义串口Ki改变标志位
unsigned char kd_usart_change_flag;//定义串口Kd改变标志位
unsigned char speed_usart_change_flag;//定义串口速度改变标志位
unsigned char angle_usart_change_flag;//定义串口角度改变标志位

void usart1_send_string(unsigned char *buf,unsigned int len) //串口字符串发送函数
{
	unsigned int i;
	for(i=0;i<len;i++)
	{
		 while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);   
		USART_SendData(USART1,buf[i]);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);          
}



void usart_order_execute(void) //出纳口接收函数
{
	if(USART_RX_STA&0x8000)  //检测是否接受完成
	{
		if(kp_usart_change_flag==1) //如果串口Kp改变标志位为1，则改变PID参数中的Kp，并保存到eeprom
		{
			usart_kp_change();
			kp_eeprom_write();
		}
		
		if(ki_usart_change_flag==1)//如果串口Ki改变标志位为1，则改变PID参数中的Ki，并保存到eeprom
		{
			usart_ki_change();
			ki_eeprom_write();
		}
		
		if(kd_usart_change_flag==1)//如果串口Kd改变标志位为1，则改变PID参数中的Kd，并保存到eeprom
		{
			usart_kd_change();
			kd_eeprom_write();
		}
		
		if(speed_usart_change_flag==1)//如果串口速度改变标志位为1，则改变设定速度，并保存到eeprom中
		{
			usart_speed_change();
			speed_eeprom_write();
		}
		
		if(angle_usart_change_flag==1)//如果串口角度改变标志位为1，则改变设定角度，并保存到eeprom中
		{
			
			
			
		usart_angle_change();
		}
		
		
		
		
		
		
		
		
		
		USART_RX_STA=0;//清零标志位
	}
}














