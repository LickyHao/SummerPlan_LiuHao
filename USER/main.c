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


int count; //设置pid算法返回值变量，用于输出PWM
int really_speed_angle; //全局变量，用于设置指定速度
float really_speed;  //全集变量，用于计算pid的占空比

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断优先级分组
	uart_init(9600); //初始化串口1,9600波特率
	iic_GPIO_init(); //初始化IIC的GPIO口
	delay_init();  //初始化延时函数
	TFTLCD_Init(); //初始化触摸屏
	encoder_init(); //初始化编码器定时器5
	tim6_base_init(); //初始化定时器6
	PID_init(); //初始化PID参数
	tim4_motor_init(); //初始化定时器4
	exti_key16_init(); //初始化按键的外部中断
	key16_init(); //初始化按键的GPIO口
	LCD_Fill(0,0,319,479,WHITE); //清屏触摸屏
	really_speed_angle=(int)read_len_byte(0x0F,3);  //从eeprom中提取存储的速度设定值
	while(1)
	{
		usart_order_execute();  //串口执行函数，用于改变PID参数，速度
		lcd_show_PID(); //PID参数显示函数，用于在触摸屏上显示PID参数
		lcd_show_Speed_angle(); //触摸屏速度角度显示函数

		
		count=(int)pid_algorithm(really_speed_angle,really_speed);//调用PID算法，返回值为PWM占空比
		TIM_SetCompare1(TIM4,count); //调整TIM4的占空比，用于输出指定速度


		LCD_DrawLine(50,100,50,250); //划线，波形的Y坐标
		LCD_DrawLine(50,250,319,250); //划线，波形的横坐标
		LCD_ShowNum(37,244,0,1,12);     ////////////////////////// 
		LCD_ShowNum(37,224,20,2,12);    //                      // 
		LCD_ShowNum(37,204,40,2,12);    //                      //     
		LCD_ShowNum(37,184,60,2,12);    //对波形的纵坐标进行标号//
		LCD_ShowNum(37,164,80,2,12);    //                      //        
		LCD_ShowNum(30,144,100,3,12);   //                      //         
		LCD_ShowNum(30,124,120,3,12);   //////////////////////////
		LCD_DrawRectangle(50,300,200,350); //画矩形，用于显示按键的调整数值
	}
}







