#ifndef _EEPROM_H_
#define _EEPROM_H_



unsigned char read_one_byte(unsigned int readadd);
void write_one_byte(unsigned int WriteAdd,unsigned char date);
void write_len_byte(unsigned int WriteAdd,unsigned int date,unsigned char len);
unsigned int read_len_byte(unsigned int ReadAdd,unsigned char len);
void Read_String(unsigned int ReadAdd,unsigned char *p,unsigned int len);
void Writ_String(unsigned int WriteAdd,unsigned char *p,unsigned int len);





#endif



