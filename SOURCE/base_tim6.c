#include"base_tim6.h"
#include"stm32f10x.h"
#include "sys.h"
#include "usart.h"
#include"pid.h"
#include"lcd.h"

#include"usart_one.h"

int encoder_number;  //�������������������
extern int RealitySpeed;  
extern float really_speed_numbr;    //����ʵ���ٶȱ���
float speed_show_lcd;  //���崥�����ٶ���ʾ����
extern float really_speed;  //ȫ�����������ڼ���pid��ռ�ձ�


unsigned char Speed_String[20]="speed:";  //���崥�����ٶ���ʾ�ַ���
unsigned char angle_String[20]="angle:";  //���崥�����Ƕ���ʾ�ַ���

void tim6_base_init(void)  //��ʼ����ʱ��6����
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString; //���嶨ʱ����ʼ���ṹ�����
	NVIC_InitTypeDef NVIC_InitTypeString;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE); //��ʼ����ʱ��6ʱ��
	
	TIM_TimeBaseInitTypeString.TIM_Period=899;//�����Զ���װ��ֵ
	TIM_TimeBaseInitTypeString.TIM_Prescaler=79; //����Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitTypeString);//��ʼ����ʱ��4
	
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);//ʹ��TIM5�ж�
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM6_IRQn;//�����ж�ͨ��Ϊ��ʱ��6
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE;//ʹ�ܶ�ʱ��6�ж�
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�Ϊ0
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;//�����ȼ�Ϊ0
	NVIC_Init(&NVIC_InitTypeString);//��ʼ��NVIC

	TIM_Cmd(TIM6,ENABLE); //ʹ�ܶ�ʱ��6
 TIM_ClearFlag(TIM6,TIM_FLAG_Update); //�����־λ


}

void TIM6_IRQHandler(void)  //��ʱ��6�жϺ���
{
	static unsigned int time_1s_flag=0;  //���徲̬������1���־����
	static unsigned int time_250ms_flag=0; //���徲̬������250�����־����
	static unsigned char tim_10ms_flag=0;//���徲̬������10�����־����
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)==SET) //��鶨ʱ��6�Ƿ����ж�
	{
		time_1s_flag++;  //1���־���Լ�1
		time_250ms_flag++;  //250�����־���Լ�1
		tim_10ms_flag++; //10�����־���Լ�1
		TIM_ClearFlag(TIM6,TIM_FLAG_Update); //���㶨ʱ��6��־λ
		if(time_1s_flag>=1000) //���ﵽ1��
		{
			 time_1s_flag=0; //�����־λ
			really_speed_numbr=(float)encoder_number/334.0;  //����ʵ���ٶ�,������ʾ
			really_speed=(float)encoder_number/334.0;  //����ʵ���ٶ�,���ڵ���PID
			 speed_show_lcd=(float)encoder_number/334;  //����ʵ���ٶȣ������ڴ���������ʾ
			 out_scan();  //��λ����ʾ����
			 encoder_number=0;  //����������������
		}
		if(tim_10ms_flag>=10)  //���ﵽ10����
		{ 
			tim_10ms_flag=0; //����
			lcd_show_really_speed((unsigned short int)speed_show_lcd); //�ڴ���������ʾ�ٶ�
		}
	}	
	
}



void lcd_show_Speed_angle(void)  //�������ٶȽǶ���ʾ����
{
	Speed_String[6]=((int)speed_show_lcd)/100%10+'0';                      //��ʵ���ٶȸ����ַ�������������ʾ
	Speed_String[7]=((int)speed_show_lcd)/10%10+'0';
	Speed_String[8]=((int)speed_show_lcd)%10+'0';
	Speed_String[9]='.';
	Speed_String[10]=(int)((speed_show_lcd-(int)speed_show_lcd)*10)%10+'0';
	Speed_String[11]=(int)((speed_show_lcd-(int)speed_show_lcd)*100)%10+'0';
	Speed_String[12]='\0';
	LCD_ShowString(0,51,100,15,16,Speed_String); //�ڴ���������ʾ�ٶ�
	
	
	
	LCD_ShowString(0,68,100,15,16,angle_String);  //����Ӧλ����ʾ�Ƕ�
	
	
	
}













