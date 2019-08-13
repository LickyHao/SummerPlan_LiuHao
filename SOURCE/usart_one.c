#include"stm32f10x.h"
#include"usart_one.h"
#include "usart.h"	 



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
				//len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			if(USART_RX_BUF[0]=='p');
			if(USART_RX_BUF[0]=='i');
			if(USART_RX_BUF[0]=='d');
			if(USART_RX_BUF[0]=='s');
			if(USART_RX_BUF[0]=='a');
			USART_RX_STA=0;
	}
}














