#include"eeprom.h"
#include"stm32f10x.h"
#include "iic.h"
#include "delay.h"


unsigned char read_one_byte(unsigned int readadd)
{
	unsigned char temp;
	
	I2C_start();
	send_byte(0xA0+((readadd/256)<<1));
	IIC_wait_ack();
	send_byte(readadd%256);
	IIC_wait_ack();
	I2C_start();
	send_byte(0xA1);
	IIC_wait_ack();
	temp=read_byte(0);
	I2C_stop();
	return temp;
}


void write_one_byte(unsigned int WriteAdd,unsigned char date)
{
	I2C_start();
	send_byte(0xA0+((WriteAdd/256)<<1));
	IIC_wait_ack();
	send_byte(WriteAdd%256);
	IIC_wait_ack();
	send_byte(date);
	IIC_wait_ack();
	I2C_stop();
	delay_ms(10);
}

void write_len_byte(unsigned int WriteAdd,unsigned int date,unsigned char len)
{
	unsigned char i;
	for(i=0;i<len;i++)
	{
		write_one_byte(WriteAdd+i,(date>>(8*i))&0xFF);
	}
}

unsigned int read_len_byte(unsigned int ReadAdd,unsigned char len)
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

void Read_String(unsigned int ReadAdd,unsigned char *p,unsigned int len)
{
	while(len)
	{
		*p++=read_one_byte(ReadAdd++);
		len--;
	}
}

void Writ_String(unsigned int WriteAdd,unsigned char *p,unsigned int len)
{
	while(len--)
	{
		write_one_byte(WriteAdd,*p);
		WriteAdd++;
		p++;
	}
}
































