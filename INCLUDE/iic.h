#ifndef _IIC_H_
#define _IIC_H_

void iic_GPIO_init(void);//iic初始化函数
void I2C_start(void);//产生总线起始信号
void I2C_stop(void); //产生总线终止信号
void SDA_IIC_out(void);//PB7输出函数
void SDA_IIC_in(void);//PB7输入函数
unsigned char IIC_wait_ack(void); //等待应答信号到来
void IIC_ack(void);//产生ACK应答
void IIC_not_ack(void);//不产生ACK应答		
unsigned char read_byte(unsigned char ack);//读取一个字节
void send_byte(unsigned char u);//IIC发送一个字节









#endif



