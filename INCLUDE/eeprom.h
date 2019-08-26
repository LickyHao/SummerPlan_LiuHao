#ifndef _EEPROM_H_
#define _EEPROM_H_



unsigned char read_one_byte(unsigned int readadd);//在24C02指定地址读取一个字节
void write_one_byte(unsigned int WriteAdd,unsigned char date);//在24C02指定地址写入一个字节
void write_len_byte(unsigned int WriteAdd,unsigned int date,unsigned char len);//向24C02指定地址写入指定长度的整形数据
unsigned int read_len_byte(unsigned int ReadAdd,unsigned char len);//向24C02指定地址读取指定长度的整形数据
void Read_String(unsigned int ReadAdd,unsigned char *p,unsigned int len);//向24C02指定地址读取指定长度的字符串
void Writ_String(unsigned int WriteAdd,unsigned char *p,unsigned int len);//向24C02指定地址写入指定长度的字符串





#endif



