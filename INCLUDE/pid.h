#ifndef _PID_H_
#define _PID_H_


float pid_rectify(float SetSpeed);
void PID_init(void);
void out_scan(void);
void KP_Change(void);
void KI_Change(void);
void KD_Change(void);
void Speed_Change(void);
void Angle_Change(void);
void lcd_show_PID(void);
void lcd_show_set_speed(unsigned short int x);
void lcd_show_really_speed(unsigned short int x);





#endif



