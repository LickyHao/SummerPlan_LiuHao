#ifndef _EEPROM_H_
#define _EEPROM_H_



unsigned char read_one_byte(unsigned int readadd);//��24C02ָ����ַ��ȡһ���ֽ�
void write_one_byte(unsigned int WriteAdd,unsigned char date);//��24C02ָ����ַд��һ���ֽ�
void write_len_byte(unsigned int WriteAdd,unsigned int date,unsigned char len);//��24C02ָ����ַд��ָ�����ȵ���������
unsigned int read_len_byte(unsigned int ReadAdd,unsigned char len);//��24C02ָ����ַ��ȡָ�����ȵ���������
void Read_String(unsigned int ReadAdd,unsigned char *p,unsigned int len);//��24C02ָ����ַ��ȡָ�����ȵ��ַ���
void Writ_String(unsigned int WriteAdd,unsigned char *p,unsigned int len);//��24C02ָ����ַд��ָ�����ȵ��ַ���





#endif



