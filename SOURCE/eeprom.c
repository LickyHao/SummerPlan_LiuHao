#include"eeprom.h"
#include"stm32f10x.h"
#include "iic.h"
#include "delay.h"


unsigned char read_one_byte(unsigned int readadd) //在24C02指定地址读取一个字节
{
	unsigned char temp;
	
	I2C_start(); //产生总线起始信号
	send_byte(0xA0+((readadd/256)<<1));//器件地址+数据地址
	IIC_wait_ack();//等待应答
	send_byte(readadd%256);//发送低地址
	IIC_wait_ack();//等待应答
	I2C_start();//产生总线起始信号
	send_byte(0xA1);//进入接收状态
	IIC_wait_ack();//等待应答
	temp=read_byte(0);
	I2C_stop(); //产生总线终止信号
	return temp;
}


void write_one_byte(unsigned int WriteAdd,unsigned char date)//在24C02指定地址写入一个字节
{
	I2C_start();//产生总线起始信号
	send_byte(0xA0+((WriteAdd/256)<<1));
	IIC_wait_ack();//等待应答
	send_byte(WriteAdd%256);//发送低地址
	IIC_wait_ack();//等待应答
	send_byte(date);//发送字节
	IIC_wait_ack();//等待应答
	I2C_stop(); //产生总线终止信号
	delay_ms(10);
}

void write_len_byte(unsigned int WriteAdd,unsigned int date,unsigned char len) //向24C02指定地址写入指定长度的整形数据
{
	unsigned char i;
	for(i=0;i<len;i++)
	{
		write_one_byte(WriteAdd+i,(date>>(8*i))&0xFF);
	}
}

unsigned int read_len_byte(unsigned int ReadAdd,unsigned char len)//向24C02指定地址读取指定长度的整形数据
{
	unsigned char i=0;
	unsigned int y=0;
	for(i=0;i<len;i++)
	{
		y<<=8;
		y=y+read_one_byte(ReadAdd+len-i-1);
	}
	return y;
}

void Read_String(unsigned int ReadAdd,unsigned char *p,unsigned int len)//向24C02指定地址读取指定长度的字符串
{
	while(len)
	{
		*p++=read_one_byte(ReadAdd++);
		len--;
	}
}

void Writ_String(unsigned int WriteAdd,unsigned char *p,unsigned int len)//向24C02指定地址写入指定长度的字符串
{
	while(len--)
	{
		write_one_byte(WriteAdd,*p);
		WriteAdd++;
		p++;
	}
}
































