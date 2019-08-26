#include"iic.h"
#include"stm32f10x.h"
#include "delay.h"

void iic_GPIO_init(void)  //iic��ʼ������
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //GPIO��ʼ���ṹ�����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //ʹ��GFPIOBʱ��
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP;  // �������	
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_6;//ʹ��PB6��PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);//��ʼ��GPIO
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //����PB6������״̬
	GPIO_SetBits(GPIOB,GPIO_Pin_7);//����PB7������״̬
}

void SDA_IIC_out(void) //PB7�������
{
	GPIO_InitTypeDef GPIO_InitTypeString;//GPIO��ʼ���ṹ�����
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_Out_PP; // �������	
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;//ʹ��PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	//��ʼ��GPIO
}

void SDA_IIC_in(void) //PB7���뺯��
{
	GPIO_InitTypeDef GPIO_InitTypeString;//GPIO��ʼ���ṹ�����
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU;//��������
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_7;//ʹ��PB7
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHZ
	GPIO_Init(GPIOB,&GPIO_InitTypeString);	//��ʼ��GPIO
}

void I2C_start(void)  //����������ʼ�ź�
{
	SDA_IIC_out();//SDA�������
	GPIO_SetBits(GPIOB,GPIO_Pin_6);  //ȷ��SCLΪ�ߵ�ƽ
	GPIO_SetBits(GPIOB,GPIO_Pin_7);  //ȷ��SDAΪ�ߵ�ƽ
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //������SDA
	delay_us(5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);  //������SCL
}

void I2C_stop(void)  //����������ֹ�ź�
{
	SDA_IIC_out();//SDA�������
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //ȷ��SCLΪ�͵�ƽ  
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //ȷ��SDAΪ�͵�ƽ
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //������SCL
	delay_us(5);
	GPIO_SetBits(GPIOB,GPIO_Pin_7); //������SDA
	delay_us(5);
}

unsigned char IIC_wait_ack(void) //�ȴ�Ӧ���źŵ���
{
	unsigned char time=0;
	SDA_IIC_in();  //����SDAΪ����
	GPIO_SetBits(GPIOB,GPIO_Pin_7); //����SDA
	delay_us(1);
	GPIO_SetBits(GPIOB,GPIO_Pin_6); //����SCL
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)) //���SDAΪ�ߣ�����Ч�����SDΪ�ͣ�����Ч
	{
		time++;
		if(time>250)
		{
			I2C_stop();
			return 1; //����1������ʧ��0
		}
	}	
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //ʱ�����0
	return 0; //����0�����ճɹ�
}

void IIC_ack(void) //����ACKӦ��
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//����SCL
	SDA_IIC_out();
	GPIO_ResetBits(GPIOB,GPIO_Pin_7); //����SDA
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);//����SCL
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//����SCL
}

void IIC_not_ack(void) //������ACKӦ��		
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);//����SCL
	SDA_IIC_out();
	GPIO_SetBits(GPIOB,GPIO_Pin_7);//����SDA
	delay_us(2);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);//����SCL
	delay_us(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);	//����SCL
	
}


void send_byte(unsigned char u) //IIC����һ���ֽ�
{
	unsigned char i;
	SDA_IIC_out(); //SDAΪ���
	GPIO_ResetBits(GPIOB,GPIO_Pin_6); //����SCL
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


unsigned char read_byte(unsigned char ack)  //��ȡһ���ֽ�
{
	unsigned char i;
	unsigned char y=0;
	SDA_IIC_in(); //SDAΪ����
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





































