#ifndef _PID_H_
#define _PID_H_

 
void PID_init(void); //PID������ʼ������
void out_scan(void); //���ڷ��ͺ�������������λ��������,PID����
void KP_Change(void);//����Kp�ı亯�����������ı����ֵ��ֵ��Kp����
void KI_Change(void); //����Ki�ı亯�����������ı����ֵ��ֵ��Ki����
void KD_Change(void);//����Kd�ı亯�����������ı����ֵ��ֵ��Kd����
void Speed_Change(void); //�����ٶȸı亯�����������ı����ֵ��ֵ���趨�ٶ�
void Angle_Change(void);//�����Ƕȸı亯�����������ı����ֵ��ֵ���趨�Ƕ�
void lcd_show_PID(void);//PID������ʾ�����������ڴ���������ʾPID����
void lcd_show_set_speed(unsigned short int x);//�趨�ٶ���ʾ�����������ڴ���������ʾ�趨�ٶ�
void lcd_show_really_speed(unsigned short int x);//ʵ���ٶ���ʾ�����������ڴ���������ʾʵ���ٶ�
void usart_kp_change(void);//���ڸı亯�������ڸı�PID����Kp
void usart_ki_change(void); //���ڸı亯�������ڸı�PID����Ki
void usart_kd_change(void);//���ڸı亯�������ڸı�PID����Kd
void usart_speed_change(void);//���ڸı亯�������ڸı��趨�ٶ�
void usart_angle_change(void);//���ڸı亯�������ڸı��趨�Ƕ�
void kp_eeprom_write(void);//pid�������溯������Kpֵ���浽eeprom��
void ki_eeprom_write(void);//pid�������溯������Kiֵ���浽eeprom��
void kd_eeprom_write(void); //pid�������溯������Kdֵ���浽eeprom��
void speed_eeprom_write(void);//�趨�ٶȱ��溯�������趨�ٶȱ��浽eeprom��
float pid_algorithm(float SetSpeed,float ReallySpeed) ;//PID�㷨






#endif



