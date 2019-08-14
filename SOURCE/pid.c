#include"stm32f10x.h"
#include"pid.h"
#include "usart.h"
#include"key.h"
#include"lcd.h"
#include"usart_one.h"
#include"eeprom.h"


float pid_change_value_numbeer;
unsigned int speed_angle_change_value_number;
extern int really_speed_angle;
unsigned char Kp_String[10]="Kp:";
unsigned char Ki_String[10]="Ki:";
unsigned char Kd_String[10]="Kd:";
float really_speed_numbr; 


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
	unsigned char kp_eeprom_read[6]; 
	unsigned char ki_eeprom_read[6]; 
	unsigned char kd_eeprom_read[6]; 
	
	Read_String(0x00,kp_eeprom_read,4);
	Read_String(0x05,ki_eeprom_read,4);
	Read_String(0x0A,kd_eeprom_read,4);
	
	
	PidParameterString.Kp=((float)(((int)(kp_eeprom_read[0]-'0'))*100+((int)(kp_eeprom_read[2]-'0'))*10+((int)(kp_eeprom_read[3]-'0'))))/100.0;
	PidParameterString.Ki=((float)(((int)(ki_eeprom_read[0]-'0'))*100+((int)(ki_eeprom_read[2]-'0'))*10+((int)(ki_eeprom_read[3]-'0'))))/100.0;;
	PidParameterString.Kd=((float)(((int)(kd_eeprom_read[0]-'0'))*100+((int)(kd_eeprom_read[2]-'0'))*10+((int)(kd_eeprom_read[3]-'0'))))/100.0;;
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
	unsigned char speed_PidParameter_usart1_show_string[200];
	
	speed_PidParameter_usart1_show_string[0]='s';
	speed_PidParameter_usart1_show_string[1]='p';
	speed_PidParameter_usart1_show_string[2]='e';
	speed_PidParameter_usart1_show_string[3]='e';
	speed_PidParameter_usart1_show_string[4]='d';
	speed_PidParameter_usart1_show_string[5]=':';
	speed_PidParameter_usart1_show_string[6]=((int)(really_speed_numbr/100))%10+'0';
	speed_PidParameter_usart1_show_string[7]=((int)(really_speed_numbr/10))%10+'0';
	speed_PidParameter_usart1_show_string[8]=((int)(really_speed_numbr))%10+'0';
	speed_PidParameter_usart1_show_string[9]='.';
	speed_PidParameter_usart1_show_string[10]=((int)(really_speed_numbr*10))%10+'0';
	speed_PidParameter_usart1_show_string[11]=((int)(really_speed_numbr*100))%10+'0';
	
	speed_PidParameter_usart1_show_string[12]=' ';
	speed_PidParameter_usart1_show_string[13]=' ';
	speed_PidParameter_usart1_show_string[14]='k';
	speed_PidParameter_usart1_show_string[15]='p';
	speed_PidParameter_usart1_show_string[16]='=';
	speed_PidParameter_usart1_show_string[17]=(int)PidParameterString.Kp+'0';
	speed_PidParameter_usart1_show_string[18]='.';
	speed_PidParameter_usart1_show_string[19]=((int)(PidParameterString.Kp*10))%10+'0';
	speed_PidParameter_usart1_show_string[20]=((int)(PidParameterString.Kp*100))%10+'0';
	speed_PidParameter_usart1_show_string[21]=' ';
	speed_PidParameter_usart1_show_string[22]='K';
	speed_PidParameter_usart1_show_string[23]='i';
	speed_PidParameter_usart1_show_string[24]='=';
	speed_PidParameter_usart1_show_string[25]=(int)PidParameterString.Ki+'0';
	speed_PidParameter_usart1_show_string[26]='.';
	speed_PidParameter_usart1_show_string[27]=((int)(PidParameterString.Ki*10))%10+'0';
	speed_PidParameter_usart1_show_string[28]=((int)(PidParameterString.Ki*100))%10+'0';
	speed_PidParameter_usart1_show_string[29]=' ';
	speed_PidParameter_usart1_show_string[30]='K';
	speed_PidParameter_usart1_show_string[31]='d';
	speed_PidParameter_usart1_show_string[32]='=';
	speed_PidParameter_usart1_show_string[33]=(int)PidParameterString.Kd+'0';
	speed_PidParameter_usart1_show_string[34]='.';
	speed_PidParameter_usart1_show_string[35]=((int)(PidParameterString.Kd*10))%10+'0';
  speed_PidParameter_usart1_show_string[36]=((int)(PidParameterString.Kd*100))%10+'0';
	speed_PidParameter_usart1_show_string[37]='\n';
	speed_PidParameter_usart1_show_string[38]='\r';
	usart1_send_string(speed_PidParameter_usart1_show_string,39);

	
	//printf("             Kp=%.2f,Ki=%.2f,Kd=%.2f\n",PidParameterString.Kp,PidParameterString.Ki,PidParameterString.Kd);
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



void usart_kp_change(void)
{
		PidParameterString.Kp=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}


void usart_ki_change(void)
{
		PidParameterString.Ki=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}

void usart_kd_change(void)
{
		PidParameterString.Kd=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}

void usart_speed_change(void)
{
	if(USART_RX_BUF[0]=='1')
	{
		really_speed_angle=(int)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[1]-'0'))*10+((int)(USART_RX_BUF[2]-'0')));
	}else if(USART_RX_BUF[0]!='1')
	{
		really_speed_angle=(int)(((int)(USART_RX_BUF[0]-'0'))*10+((int)(USART_RX_BUF[1]-'0')));
	}
}

void usart_angle_change(void)
{
	
}



void kp_eeprom_write(void)
{
	unsigned char kp_string_eeprom[6];
	
	kp_string_eeprom[0]=(int)PidParameterString.Kp+'0';
	kp_string_eeprom[1]='.';
	kp_string_eeprom[2]=((int)(PidParameterString.Kp*10))%10+'0';
	kp_string_eeprom[3]=((int)(PidParameterString.Kp*100))%10+'0';
	Writ_String(0x00,kp_string_eeprom,4);
	
	
}


void ki_eeprom_write(void)
{
	unsigned char ki_string_eeprom[6];
	
	ki_string_eeprom[0]=(int)PidParameterString.Ki+'0';
	ki_string_eeprom[1]='.';
	ki_string_eeprom[2]=((int)(PidParameterString.Ki*10))%10+'0';
	ki_string_eeprom[3]=((int)(PidParameterString.Ki*100))%10+'0';
	Writ_String(0x05,ki_string_eeprom,4);
	
	
}


void kd_eeprom_write(void)
{
		unsigned char kd_string_eeprom[6];
	
	kd_string_eeprom[0]=(int)PidParameterString.Kd+'0';
	kd_string_eeprom[1]='.';
	kd_string_eeprom[2]=((int)(PidParameterString.Kd*10))%10+'0';
	kd_string_eeprom[3]=((int)(PidParameterString.Kd*100))%10+'0';
	Writ_String(0x0A,kd_string_eeprom,4);
	
	
}


void speed_eeprom_write(void)
{
	if((really_speed_angle/100)>=0)
	{
	
		write_len_byte(0x0F,(unsigned int)really_speed_angle,3);

	}else if((really_speed_angle/100)<0)
	{
		write_len_byte(0x0F,(unsigned int)really_speed_angle,2);
	}
}









