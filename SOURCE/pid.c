#include"stm32f10x.h"
#include"pid.h"
#include "usart.h"
#include"key.h"
#include"lcd.h"

float pid_change_value_numbeer;
unsigned int speed_angle_change_value_number;
extern int really_speed_angle;
unsigned char Kp_String[10]="Kp:";
unsigned char Ki_String[10]="Ki:";
unsigned char Kd_String[10]="Kd:";



typedef struct{

	int SetPoint;
	int ErrorSum;
	float Kp;
	float Ki;
	float Kd;
	int LastError;
	int ActualSpeed;
}PidParameterDef;


PidParameterDef PidParameterString;


void PID_init(void)
{
	PidParameterString.Kp=0.31;
	PidParameterString.Ki=0.35;
	PidParameterString.Kd=0.2;
	PidParameterString.SetPoint=0;
	PidParameterString.ErrorSum=0;
	PidParameterString.LastError=0; 
	PidParameterString.ActualSpeed=0;
}

float pid_rectify(float SetSpeed)
{
	float DifferentialError;
	float Error;
	float ChangePid;
	
	//PidParameterString.SetPoint=SetSpeed/118.0*(900.0-237.0)+250.0;
	PidParameterString.SetPoint=SetSpeed;
	lcd_show_set_speed((unsigned short int) PidParameterString.SetPoint);
	Error=PidParameterString.SetPoint-PidParameterString.ActualSpeed;
	DifferentialError=Error-PidParameterString.LastError;
	PidParameterString.ErrorSum=PidParameterString.ErrorSum+Error;
	ChangePid=PidParameterString.Kp*Error+PidParameterString.Ki*PidParameterString.ErrorSum+PidParameterString.Kd*DifferentialError;
	PidParameterString.LastError=Error;
	PidParameterString.ActualSpeed=ChangePid;
	return (ChangePid/118.0*(900.0-237.0)+250.0);
}

void out_scan(void)
{
	printf("             Kp=%.2f,Ki=%.2f,Kd=%.2f\n",PidParameterString.Kp,PidParameterString.Ki,PidParameterString.Kd);
}


void KP_Change(void)
{
	PidParameterString.Kp=pid_change_value_numbeer;
}

void KI_Change(void)
{
	PidParameterString.Ki=pid_change_value_numbeer;
}

void KD_Change(void)
{
	PidParameterString.Kd=pid_change_value_numbeer;
}


void Speed_Change(void)
{
	really_speed_angle=speed_angle_change_value_number;
}


void Angle_Change(void)
{
	really_speed_angle=speed_angle_change_value_number;
}




void lcd_show_PID(void)
{
	 Kp_String[3]=(int)PidParameterString.Kp+'0';
	 Kp_String[4]='.';
	 Kp_String[5]=(int)((PidParameterString.Kp-(int)PidParameterString.Kp)*10)%10+'0';
	 Kp_String[6]=(int)((PidParameterString.Kp-(int)PidParameterString.Kp)*100)%10+'0';
	 Kp_String[7]='\0';
	 LCD_ShowString(0,0,100,15,16,Kp_String);

	 Ki_String[3]=(int)PidParameterString.Ki+'0';
	 Ki_String[4]='.';
	 Ki_String[5]=(int)((PidParameterString.Ki-(int)PidParameterString.Ki)*10)%10+'0';
	 Ki_String[6]=(int)((PidParameterString.Ki-(int)PidParameterString.Ki)*100)%10+'0';
	 Ki_String[7]='\0';
	LCD_ShowString(0,17,100,15,16,Ki_String);
	
	 Kd_String[3]=(int)PidParameterString.Kd+'0';
	 Kd_String[4]='.';
	 Kd_String[5]=(int)((PidParameterString.Kd-(int)PidParameterString.Kd)*10)%10+'0';
	 Kd_String[6]=(int)((PidParameterString.Kd-(int)PidParameterString.Kd)*100)%10+'0';
	 Kd_String[7]='\0';
	 LCD_ShowString(0,34,100,15,16,Kd_String);
	
	
}





void lcd_show_set_speed(unsigned short int x)
{
	int i=50; 
	for(i=50;i<319;i++)
  {
		LCD_DrawFRONT_COLOR(i,250-x,RED);
	}
	if(i>=319)i=50;
}


void lcd_show_really_speed(unsigned short int x)
{
	static int i=51;
  static int j=50;
  static int z=0;	
	LCD_Fill(i,100,i,250,WHITE);
	LCD_DrawLine(j,z,i,250-x);
	i++;
	j++;
	z=250-x;
	if(i>=319)
	{
		
		i=51;
		j=50;
		//LCD_Clear(WHITE);
	}
}





























