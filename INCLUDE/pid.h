#ifndef _PID_H_
#define _PID_H_

 
void PID_init(void); //PID参数初始化函数
void out_scan(void); //串口发送函数，用于向上位机发送速,PID参数
void KP_Change(void);//按键Kp改变函数，将按键改变的数值赋值给Kp参数
void KI_Change(void); //按键Ki改变函数，将按键改变的数值赋值给Ki参数
void KD_Change(void);//按键Kd改变函数，将按键改变的数值赋值给Kd参数
void Speed_Change(void); //按键速度改变函数，将按键改变的数值赋值给设定速度
void Angle_Change(void);//按键角度改变函数，将按键改变的数值赋值给设定角度
void lcd_show_PID(void);//PID参数显示函数，用于在触摸屏上显示PID参数
void lcd_show_set_speed(unsigned short int x);//设定速度显示函数，用于在触摸屏上显示设定速度
void lcd_show_really_speed(unsigned short int x);//实际速度显示函数，用于在触摸屏上显示实际速度
void usart_kp_change(void);//串口改变函数，用于改变PID参数Kp
void usart_ki_change(void); //串口改变函数，用于改变PID参数Ki
void usart_kd_change(void);//串口改变函数，用于改变PID参数Kd
void usart_speed_change(void);//串口改变函数，用于改变设定速度
void usart_angle_change(void);//串口改变函数，用于改变设定角度
void kp_eeprom_write(void);//pid参数保存函数，将Kp值保存到eeprom中
void ki_eeprom_write(void);//pid参数保存函数，将Ki值保存到eeprom中
void kd_eeprom_write(void); //pid参数保存函数，将Kd值保存到eeprom中
void speed_eeprom_write(void);//设定速度保存函数，将设定速度保存到eeprom中
float pid_algorithm(float SetSpeed,float ReallySpeed) ;//PID算法






#endif



