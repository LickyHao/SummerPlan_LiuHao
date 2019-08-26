#include"iic.h"
#include"stm32f10x.h"
#include "delay.h"

void iic_GPIO_init(void)  //iic初始化函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //GPIO初始化结构体变量
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //使能GFPIOB时钟
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP;  // 推挽输出	
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_6;//使能PB6和PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO口速度为50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);//初始化GPIO
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //拉高PB6，空闲状态
	GPIO_SetBits(GPIOB,GPIO_Pin_7);//拉高PB7，空闲状态
}

void SDA_IIC_out(void) //PB7输出函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;//GPIO初始化结构体变量
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP; // 推挽输出	
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;//使能PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO口速度为50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	//初始化GPIO
}

void SDA_IIC_in(void) //PB7输入函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;//GPIO初始化结构体变量
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;//使能PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO口速度为50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	//初始化GPIO
}

void I2C_start(void)  //产生总线起始信号
{
	SDA_IIC_out();//SDA设置输出
	GPIO_SetBits(GPIOB,GPIO_Pin_6);  //确保SCL为高电平
	GPIO_SetBits(GPIOB,GPIO_Pin_7);  //确保SDA为高电平
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //先拉低SDA
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);  //再拉低SCL
}

void I2C_stop(void)  //产生总线终止信号
{
	SDA_IIC_out();//SDA设置输出
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //确保SCL为低电平  
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //确保SDA为低电平
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //先拉高SCL
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_7); //在拉高SDA
	delay_us(5);
}

unsigned char IIC_wait_ack(void) //等待应答信号到来
{
	unsigned char time=0;
	SDA_IIC_in();  //设置SDA为输入
	GPIO_SetBits(GPIOB,GPIO_Pin_7); //拉高SDA
	delay_us(1);
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //拉高SCL
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)) //如果SDA为高，则无效，如果SD为低，则有效
	{
		time++;
		if(time>250)
		{
			I2C_stop();
			return 1; //返回1，接受失败0
		}
	}	
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //时钟输出0
	return 0; //返回0，接收成功
}

void IIC_ack(void) //产生ACK应答
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//拉低SCL
	SDA_IIC_out();
	GPIO_ResetBits(GPIOB,GPIO_Pin_7); //拉低SDA
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);//拉高SCL
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//拉低SCL
}

void IIC_not_ack(void) //不产生ACK应答		
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//拉低SCL
	SDA_IIC_out();
	GPIO_SetBits(GPIOB,GPIO_Pin_7);//拉高SDA
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);//拉高SCL
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);	//拉低SCL
	
}


void send_byte(unsigned char u) //IIC发送一个字节
{
	unsigned char i;
	SDA_IIC_out(); //SDA为输出
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //拉低SCL
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


unsigned char read_byte(unsigned char ack)  //读取一个字节
{
	unsigned char i;
	unsigned char y=0;
	SDA_IIC_in(); //SDA为输入
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





































