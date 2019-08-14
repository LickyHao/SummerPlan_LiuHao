#ifndef _IIC_H_
#define _IIC_H_

void iic_GPIO_init(void);
void I2C_start(void);
void I2C_stop(void);
void SDA_IIC_out(void);
void SDA_IIC_in(void);
unsigned char IIC_wait_ack(void);
void IIC_ack(void);
void IIC_not_ack(void);
unsigned char read_byte(unsigned char ack);
void send_byte(unsigned char u);









#endif



