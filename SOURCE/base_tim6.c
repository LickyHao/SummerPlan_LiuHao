#include"base_tim6.h"
#include"stm32f10x.h"
#include "sys.h"
#include "usart.h"
#include"pid.h"
#include"lcd.h"

#include"usart_one.h"

int encoder_number;  //定义编码器计数器变量
extern int RealitySpeed;  
extern float really_speed_numbr;    //定义实际速度变量
float speed_show_lcd;  //定义触摸屏速度显示变量
extern float really_speed;  //全集变量，用于计算pid的占空比


unsigned char Speed_String[20]="speed:";  //定义触摸屏速度显示字符串
unsigned char angle_String[20]="angle:";  //定义触摸屏角度显示字符串

void tim6_base_init(void)  //初始化定时器6函数
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString; //定义定时器初始化结构体变量
	NVIC_InitTypeDef NVIC_InitTypeString;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE); //初始化定时器6时钟
	
	TIM_TimeBaseInitTypeString.TIM_Period=899;//设置自动重装载值
	TIM_TimeBaseInitTypeString.TIM_Prescaler=79; //设置预分频系数
	TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitTypeString);//初始化定时器4
	
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);//使能TIM5中断
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM6_IRQn;//设置中断通道为定时器6
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE;//使能定时器6中断
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=0;//抢占优先级为0
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;//子优先级为0
	NVIC_Init(&NVIC_InitTypeString);//初始化NVIC

	TIM_Cmd(TIM6,ENABLE); //使能定时器6
 TIM_ClearFlag(TIM6,TIM_FLAG_Update); //清零标志位


}

void TIM6_IRQHandler(void)  //定时器6中断函数
{
	static unsigned int time_1s_flag=0;  //定义静态变量，1秒标志变量
	static unsigned int time_250ms_flag=0; //定义静态变量，250毫秒标志变量
	static unsigned char tim_10ms_flag=0;//定义静态变量，10毫秒标志变量
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)==SET) //检查定时器6是否发生中断
	{
		time_1s_flag++;  //1秒标志量自加1
		time_250ms_flag++;  //250毫秒标志量自加1
		tim_10ms_flag++; //10毫秒标志量自加1
		TIM_ClearFlag(TIM6,TIM_FLAG_Update); //清零定时器6标志位
		if(time_1s_flag>=1000) //当达到1秒
		{
			 time_1s_flag=0; //清零标志位
			really_speed_numbr=(float)encoder_number/334.0;  //计算实际速度,用于显示
			really_speed=(float)encoder_number/334.0;  //计算实际速度,用于调整PID
			 speed_show_lcd=(float)encoder_number/334;  //计算实际速度，用于在触摸屏上显示
			 out_scan();  //上位机显示函数
			 encoder_number=0;  //编码器计数器清零
		}
		if(tim_10ms_flag>=10)  //当达到10毫秒
		{ 
			tim_10ms_flag=0; //清零
			lcd_show_really_speed((unsigned short int)speed_show_lcd); //在触摸屏上显示速度
		}
	}	
	
}



void lcd_show_Speed_angle(void)  //触摸屏速度角度显示函数
{
	Speed_String[6]=((int)speed_show_lcd)/100%10+'0';                      //将实际速度赋给字符串数组用于显示
	Speed_String[7]=((int)speed_show_lcd)/10%10+'0';
	Speed_String[8]=((int)speed_show_lcd)%10+'0';
	Speed_String[9]='.';
	Speed_String[10]=(int)((speed_show_lcd-(int)speed_show_lcd)*10)%10+'0';
	Speed_String[11]=(int)((speed_show_lcd-(int)speed_show_lcd)*100)%10+'0';
	Speed_String[12]='\0';
	LCD_ShowString(0,51,100,15,16,Speed_String); //在触摸屏上显示速度
	
	
	
	LCD_ShowString(0,68,100,15,16,angle_String);  //在相应位置显示角度
	
	
	
}













