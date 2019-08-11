#include"base_tim6.h"
#include"stm32f10x.h"
#include "sys.h"
#include "usart.h"
#include"pid.h"
#include"lcd.h"

int encoder_number;
extern int RealitySpeed;
float speed_show_lcd;
//extern int count; 


unsigned char Speed_String[20]="speed:";
unsigned char angle_String[20]="angle:";

void tim6_base_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString;
	NVIC_InitTypeDef NVIC_InitTypeString;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	TIM_TimeBaseInitTypeString.TIM_Period=899;
	TIM_TimeBaseInitTypeString.TIM_Prescaler=79;
	TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitTypeString);
	
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM6_IRQn;
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitTypeString);

	TIM_Cmd(TIM6,ENABLE);
 TIM_ClearFlag(TIM6,TIM_FLAG_Update);


}

void TIM6_IRQHandler(void)
{
	static unsigned int time_1s_flag=0;
	static unsigned int time_250ms_flag=0;
	static unsigned char tim_10ms_flag=0;
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)==SET)
	{
		time_1s_flag++;
		time_250ms_flag++;
		tim_10ms_flag++;
		TIM_ClearFlag(TIM6,TIM_FLAG_Update);
		if(time_1s_flag>=1000)
		{
			 time_1s_flag=0;
			 printf("%.2f\n",(float)encoder_number/334);
			 speed_show_lcd=(float)encoder_number/334;
			 out_scan();
			  //LCD_Fill(0,0,319,479,WHITE);
			 //count=encoder_number;
			 //RealitySpeed=pid_rectify((int)(encoder_number/334));
			// TIM_SetCompare1(TIM1,RealitySpeed);
			 encoder_number=0;
		}
		/*if(time_250ms_flag>=250)
		{
			time_250ms_flag=0;
			//count=(int)pid_rectify(60);
		}
		count=(int)pid_rectify(60);*/
		if(tim_10ms_flag>=10)
		{
			tim_10ms_flag=0;
			lcd_show_really_speed((unsigned short int)speed_show_lcd);
		}
	}	
	
}



void lcd_show_Speed_angle(void)
{
	Speed_String[6]=((int)speed_show_lcd)/100%10+'0';
	Speed_String[7]=((int)speed_show_lcd)/10%10+'0';
	Speed_String[8]=((int)speed_show_lcd)%10+'0';
	Speed_String[9]='.';
	Speed_String[10]=(int)((speed_show_lcd-(int)speed_show_lcd)*10)%10+'0';
	Speed_String[11]=(int)((speed_show_lcd-(int)speed_show_lcd)*100)%10+'0';
	Speed_String[12]='\0';
	LCD_ShowString(0,51,100,15,16,Speed_String);
	
	
	
	LCD_ShowString(0,68,100,15,16,angle_String);
	
	
	
}













