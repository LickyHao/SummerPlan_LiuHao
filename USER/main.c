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



//int RealitySpeed;
int count;
int really_speed_angle;



int main(void)
{
	uart_init(9600);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	time1_motor_init();
	encoder_init();
	tim6_base_init();
	PID_init();
	tim4_motor_init();
	exti_key16_init();
	key16_init();
	uart_init(9600);
	TFTLCD_Init();
	//really_speed_angle=0;
	LCD_Fill(0,0,319,479,WHITE);
	while(1)
	{
		lcd_show_PID();
		
		lcd_show_Speed_angle();
		/*RealitySpeed=pid_rectify(count);
		TIM_SetCompare1(TIM1,RealitySpeed);*/
		/*TIM_SetCompare1(TIM4,800);
		delay_ms(5000);*/
		//count=(int)pid_rectify(80.0)/5*118;
		//count=(int)pid_rectify(110);
		count=(int)pid_rectify(really_speed_angle);
		TIM_SetCompare1(TIM4,count);
		//TIM_SetCompare1(TIM4,really_speed_angle);
				/*TIM_SetCompare1(TIM4,200);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,300);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,400);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,500);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,600);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,700);
		delay_ms(5000);
				TIM_SetCompare1(TIM4,800);
		delay_ms(5000);*/

		LCD_DrawLine(50,100,50,250);
		LCD_DrawLine(50,250,319,250);
		LCD_ShowNum(37,244,0,1,12);
		LCD_ShowNum(37,224,20,2,12);
		LCD_ShowNum(37,204,40,2,12);
		LCD_ShowNum(37,184,60,2,12);
		LCD_ShowNum(37,164,80,2,12);
		LCD_ShowNum(30,144,100,3,12);
		LCD_ShowNum(30,124,120,3,12);
		LCD_DrawRectangle(50,300,200,350);
	}
}







