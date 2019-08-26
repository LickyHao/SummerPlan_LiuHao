#ifndef _IIC_H_
#define _IIC_H_

void iic_GPIO_init(void);//iic��ʼ������
void I2C_start(void);//����������ʼ�ź�
void I2C_stop(void); //����������ֹ�ź�
void SDA_IIC_out(void);//PB7�������
void SDA_IIC_in(void);//PB7���뺯��
unsigned char IIC_wait_ack(void); //�ȴ�Ӧ���źŵ���
void IIC_ack(void);//����ACKӦ��
void IIC_not_ack(void);//������ACKӦ��		
unsigned char read_byte(unsigned char ack);//��ȡһ���ֽ�
void send_byte(unsigned char u);//IIC����һ���ֽ�









#endif



