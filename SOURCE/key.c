#include"key.h"
#include"pid.h"
#include"stm32f10x.h"
#include "lcd.h"

unsigned int numbeer_acccumulation=0;
unsigned char Kp_flag=0;
unsigned char Ki_flag=0;
unsigned char Kd_flag=0;
unsigned char speed_flag=0;
unsigned char angle_flag=0;
extern float pid_change_value_numbeer;
float pid_result;
extern unsigned int speed_angle_change_value_number;
unsigned char point_sunm=0;
unsigned char point_flag=0;
unsigned char point_digit=0;
unsigned char wait_change_String[20]="Waiting...";
unsigned char clan_waiting_lcd[500]="                                                                ";
unsigned int Digit=0;
unsigned char point_lcd_show_String[3]=".";


void key16_init(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_All;
	
	GPIO_Init(GPIOF,&GPIO_InitTypeString);
}

void key0_number_zero(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+0;
	LCD_ShowNum(55+Digit,320,0,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key1_number_one(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+1;
	LCD_ShowNum(55+Digit,320,1,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key2_number_two(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+2;
	LCD_ShowNum(55+Digit,320,2,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}


void key3_number_three(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+3;
	LCD_ShowNum(55+Digit,320,3,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key4_number_four(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+4;
	LCD_ShowNum(55+Digit,320,4,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key5_number_five(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+5;
	LCD_ShowNum(55+Digit,320,5,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key6_number_six(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+6;
	LCD_ShowNum(55+Digit,320,6,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key7_number_seven(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+7;
	LCD_ShowNum(55+Digit,320,7,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key8_number_eight(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+8;
	LCD_ShowNum(55+Digit,320,8,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}


void key9_number_nine(void)
{
	numbeer_acccumulation=numbeer_acccumulation*10+9;
	LCD_ShowNum(55+Digit,320,9,1,16);
	Digit=Digit+16;
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1))
	{
		if(point_flag==1)
		{
			point_sunm++;
		}
	}
}

void key10_Kp_change(void)
{
	if(Kp_flag==0)Kp_flag=1;
	else if(Kp_flag==1)Kp_flag=0;
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)
	{
		pid_result=(float)numbeer_acccumulation;
		for(point_digit=point_sunm;point_digit>0;point_digit--)
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result;
		KP_Change();
		numbeer_acccumulation=0;
		point_sunm=0;
		Digit=0;
	}
	if(Kp_flag==1)
	{
		LCD_ShowString(160,0,100,15,16,wait_change_String);
	}
	if(Kp_flag==0)
	{
		LCD_ShowString(160,0,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key11_Ki_change(void)
{
	if(Ki_flag==0)Ki_flag=1;
	else if(Ki_flag==1)Ki_flag=0;
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)
	{
		pid_result=(float)numbeer_acccumulation;
		for(point_digit=point_sunm;point_digit>0;point_digit--)
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result;
		KI_Change();
		numbeer_acccumulation=0;
		point_sunm=0;
		Digit=0;
	}
	if(Ki_flag==1)
	{
		LCD_ShowString(160,17,100,15,16,wait_change_String);
	}
	if(Ki_flag==0)
	{
		LCD_ShowString(160,17,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key12_Kd_change(void)
{
	if(Kd_flag==0)Kd_flag=1;
	else if(Kd_flag==1)Kd_flag=0;
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)
	{
		pid_result=(float)numbeer_acccumulation;
		for(point_digit=point_sunm;point_digit>0;point_digit--)
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result;
		KD_Change();
		numbeer_acccumulation=0;
		point_sunm=0;
		Digit=0;
	}
	if(Kd_flag==1)
	{
		LCD_ShowString(160,34,100,15,16,wait_change_String);
	}
	if(Kd_flag==0)
	{
		LCD_ShowString(160,34,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key13_speed_set(void)
{
	if(speed_flag==0)speed_flag=1;
	else if(speed_flag==1)speed_flag=0;
	if(speed_flag==0&&angle_flag==0)
	{
		speed_angle_change_value_number=numbeer_acccumulation;
		Speed_Change();
		numbeer_acccumulation=0;
		point_sunm=0;
		Digit=0;
	}
	if(speed_flag==1)
	{
			LCD_ShowString(160,51,100,15,16,wait_change_String);
	}
	if(speed_flag==0)
	{
			LCD_ShowString(160,51,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key14_angle_set(void)
{
	if(angle_flag==0)angle_flag=1;
	else if(angle_flag==1)angle_flag=0;
	if(speed_flag==0&&angle_flag==0)
	{
		speed_angle_change_value_number=numbeer_acccumulation;
		Angle_Change();
		numbeer_acccumulation=0;
		point_sunm=0;
		Digit=0;
	}
	if(angle_flag==1)
	{
		LCD_ShowString(160,68,100,15,16,wait_change_String);
	}
	if(angle_flag==0)
	{
		LCD_ShowString(160,68,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
	
}


void key15_decimal_point(void)
{
	if(point_flag==0)point_flag=1;
	else if(point_flag==1)point_flag=0;
		LCD_ShowString(55+Digit,320,100,15,16,point_lcd_show_String);
		Digit=Digit+16;
}
