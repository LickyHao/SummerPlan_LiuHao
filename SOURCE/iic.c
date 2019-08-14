#include"iic.h"
#include"stm32f10x.h"
#include "delay.h"

void iic_GPIO_init(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_6;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeString);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
}

void SDA_IIC_out(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	
}

void SDA_IIC_in(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	
}

void I2C_start(void)  //产生总线起始信号
{
	SDA_IIC_out();
	GPIO_SetBits(GPIOB,GPIO_Pin_6);  //确保SCL为高电平
	GPIO_SetBits(GPIOB,GPIO_Pin_7);  //确保SDA为高电平
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //先拉低SDA
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);  //再拉低SCL
}

void I2C_stop(void)  //产生总线终止信号
{
	SDA_IIC_out();
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //确保SCL为低电平  
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //确保SDA为低电平
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	delay_us(5);
}

unsigned char IIC_wait_ack(void)
{
	unsigned char time=0;
	SDA_IIC_in();
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	delay_us(1);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7))
	{
		time++;
		if(time>250)
		{
			I2C_stop();
			return 1;
		}
	}	
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	return 0;
}

void IIC_ack(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	SDA_IIC_out();
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
}

void IIC_not_ack(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	SDA_IIC_out();
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);	
	
}


void send_byte(unsigned char u)
{
	unsigned char i;
	SDA_IIC_out();
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	for(i=0;i<8;i++)
	{
		if((u&0x80)>0)GPIO_SetBits(GPIOB,GPIO_Pin_7);
		else GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		u<<=1;
		delay_us(2);
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		delay_us(2);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);	
		delay_us(2);
	}	
}


unsigned char read_byte(unsigned char ack)
{
	unsigned char i;
	unsigned char y=0;
	SDA_IIC_in();
	for(i=0;i<8;i++)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);	
		delay_us(2);
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		y<<=1;
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7))
			y++;
		delay_us(1);
	}
	if(!ack)IIC_not_ack();
	else IIC_ack();
	return y;
}





































