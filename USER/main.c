#include"stm32f10x.h"
#include"motor_time1.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include"encoder_tim5.h"
#include"base_tim6.h"
#include"pid.h"
#include"key.h"
#include"exti.h"
#include"lcd.h"
#include"usart_one.h"
#include"iic.h"
#include"eeprom.h"


int count; //����pid�㷨����ֵ�������������PWM
int really_speed_angle; //ȫ�ֱ�������������ָ���ٶ�
float really_speed;  //ȫ�����������ڼ���pid��ռ�ձ�

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж����ȼ�����
	uart_init(9600); //��ʼ������1,9600������
	iic_GPIO_init(); //��ʼ��IIC��GPIO��
	delay_init();  //��ʼ����ʱ����
	TFTLCD_Init(); //��ʼ��������
	encoder_init(); //��ʼ����������ʱ��5
	tim6_base_init(); //��ʼ����ʱ��6
	PID_init(); //��ʼ��PID����
	tim4_motor_init(); //��ʼ����ʱ��4
	exti_key16_init(); //��ʼ���������ⲿ�ж�
	key16_init(); //��ʼ��������GPIO��
	LCD_Fill(0,0,319,479,WHITE); //����������
	really_speed_angle=(int)read_len_byte(0x0F,3);  //��eeprom����ȡ�洢���ٶ��趨ֵ
	while(1)
	{
		usart_order_execute();  //����ִ�к��������ڸı�PID�������ٶ�
		lcd_show_PID(); //PID������ʾ�����������ڴ���������ʾPID����
		lcd_show_Speed_angle(); //�������ٶȽǶ���ʾ����

		
		count=(int)pid_algorithm(really_speed_angle,really_speed);//����PID�㷨������ֵΪPWMռ�ձ�
		TIM_SetCompare1(TIM4,count); //����TIM4��ռ�ձȣ��������ָ���ٶ�


		LCD_DrawLine(50,100,50,250); //���ߣ����ε�Y����
		LCD_DrawLine(50,250,319,250); //���ߣ����εĺ�����
		LCD_ShowNum(37,244,0,1,12);     ////////////////////////// 
		LCD_ShowNum(37,224,20,2,12);    //                      // 
		LCD_ShowNum(37,204,40,2,12);    //                      //     
		LCD_ShowNum(37,184,60,2,12);    //�Բ��ε���������б��//
		LCD_ShowNum(37,164,80,2,12);    //                      //        
		LCD_ShowNum(30,144,100,3,12);   //                      //         
		LCD_ShowNum(30,124,120,3,12);   //////////////////////////
		LCD_DrawRectangle(50,300,200,350); //�����Σ�������ʾ�����ĵ�����ֵ
	}
}







