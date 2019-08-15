#include"stm32f10x.h"
#include"pid.h"
#include "usart.h"
#include"key.h"
#include"lcd.h"
#include"usart_one.h"
#include"eeprom.h"


float pid_change_value_numbeer;      //声明按键改变的PID参数
unsigned int speed_angle_change_value_number;  //声明按键改变的速度变量
extern int really_speed_angle;  //全局变量，用于设置指定速度
unsigned char Kp_String[10]="Kp:";  //定义PID参数中的Kp显示在触摸屏上的字符型数组变量
unsigned char Ki_String[10]="Ki:"; //定义PID参数中的Ki显示在触摸屏上的字符型数组变量
unsigned char Kd_String[10]="Kd:"; //定义PID参数中的Kd显示在触摸屏上的字符型数组变量
float really_speed_numbr;  //定义实际速度变量


typedef struct{      //定义PID参数结构体内容

	int SetPoint; //设定速度
	int ErrorSum;  //误差之和
	float Kp;  //PID参数Kp
	float Ki;  //PID参数Ki
	float Kd;  //PID参数Kd
	int LastError; //上一次误差
	int ActualSpeed; //实际速度
}PidParameterDef;


PidParameterDef PidParameterString;  //定义PID参数结构体变量
 

void PID_init(void)  //初始化PID参数
{
	unsigned char kp_eeprom_read[6];  //定义Kp接收字符串，勇于接受eeprom中保存的变量
	unsigned char ki_eeprom_read[6];  //定义Ki接收字符串，勇于接受eeprom中保存的变量
	unsigned char kd_eeprom_read[6];  //定义Kd接收字符串，勇于接受eeprom中保存的变量
	
	Read_String(0x00,kp_eeprom_read,4);  //从eeprom中读取Kp
	Read_String(0x05,ki_eeprom_read,4);  //从eeprom中读取Ki
	Read_String(0x0A,kd_eeprom_read,4);  //从eeprom中读取Kd
	
	
	PidParameterString.Kp=((float)(((int)(kp_eeprom_read[0]-'0'))*100+((int)(kp_eeprom_read[2]-'0'))*10+((int)(kp_eeprom_read[3]-'0'))))/100.0;  //将从eeprom中读取的Kp值赋给PID参数中Kp
	PidParameterString.Ki=((float)(((int)(ki_eeprom_read[0]-'0'))*100+((int)(ki_eeprom_read[2]-'0'))*10+((int)(ki_eeprom_read[3]-'0'))))/100.0;  //将从eeprom中读取的Ki值赋给PID参数中Ki
	PidParameterString.Kd=((float)(((int)(kd_eeprom_read[0]-'0'))*100+((int)(kd_eeprom_read[2]-'0'))*10+((int)(kd_eeprom_read[3]-'0'))))/100.0;  //将从eeprom中读取的Kd值赋给PID参数中Kd
	PidParameterString.SetPoint=0; //初始化速度设定值
	PidParameterString.ErrorSum=0; //初始化误差累计和
	PidParameterString.LastError=0; //初始化微分变量
	PidParameterString.ActualSpeed=0; //初始化实际速度
}

float pid_rectify(float SetSpeed)  //pid算法函数
{
	float DifferentialError; //定义微分变量
	float Error;  //定义误差
	float ChangePid;  //定义PID结果变量
	
	PidParameterString.SetPoint=SetSpeed;  //赋值设定速度 
	lcd_show_set_speed((unsigned short int) PidParameterString.SetPoint); //在触摸屏上显示设定速度
	Error=PidParameterString.SetPoint-PidParameterString.ActualSpeed; //计算误差
	DifferentialError=Error-PidParameterString.LastError;//计算误差微分变量
	PidParameterString.ErrorSum=PidParameterString.ErrorSum+Error; //计算误差值之和
	ChangePid=PidParameterString.Kp*Error+PidParameterString.Ki*PidParameterString.ErrorSum+PidParameterString.Kd*DifferentialError; //计算PID结果
	PidParameterString.LastError=Error; //重新赋值微分变量
	PidParameterString.ActualSpeed=ChangePid; //重新赋值实际参数
	return (ChangePid/118.0*(900.0-237.0)+250.0); //返回PID输出值
}

void out_scan(void)    //串口发送函数，用于向上位机发送速,PID参数
{
	unsigned char speed_PidParameter_usart1_show_string[200];  //定义串口发送字符型数组，将PID的参数，速度存放在数组里，发送给上位机
	
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
	usart1_send_string(speed_PidParameter_usart1_show_string,39);  //想上位机发送

	

}


void KP_Change(void)  //按键Kp改变函数，将按键改变的数值赋值给Kp参数
{
	PidParameterString.Kp=pid_change_value_numbeer;
}

void KI_Change(void)  //按键Ki改变函数，将按键改变的数值赋值给Ki参数
{
	PidParameterString.Ki=pid_change_value_numbeer;
}

void KD_Change(void)  //按键Kd改变函数，将按键改变的数值赋值给Kd参数
{
	PidParameterString.Kd=pid_change_value_numbeer;
}


void Speed_Change(void)  //按键速度改变函数，将按键改变的数值赋值给设定速度
{
	really_speed_angle=speed_angle_change_value_number;
}


void Angle_Change(void)  //按键角度改变函数，将按键改变的数值赋值给设定角度
{
	really_speed_angle=speed_angle_change_value_number;
}




void lcd_show_PID(void)  //PID参数显示函数，用于在触摸屏上显示PID参数
{
	 Kp_String[3]=(int)PidParameterString.Kp+'0'; //将PID参数中的Kp转化字符型
	 Kp_String[4]='.';
	 Kp_String[5]=(int)((PidParameterString.Kp-(int)PidParameterString.Kp)*10)%10+'0';
	 Kp_String[6]=(int)((PidParameterString.Kp-(int)PidParameterString.Kp)*100)%10+'0';
	 Kp_String[7]='\0';
	 LCD_ShowString(0,0,100,15,16,Kp_String);  //将PID参数中的Kp显示在触摸屏指定位置上

	 Ki_String[3]=(int)PidParameterString.Ki+'0'; //将PID参数中的Ki转化字符型
	 Ki_String[4]='.';
	 Ki_String[5]=(int)((PidParameterString.Ki-(int)PidParameterString.Ki)*10)%10+'0';
	 Ki_String[6]=(int)((PidParameterString.Ki-(int)PidParameterString.Ki)*100)%10+'0';
	 Ki_String[7]='\0';
	 LCD_ShowString(0,17,100,15,16,Ki_String);  //将PID参数中的Ki显示在触摸屏指定位置上
	
	 Kd_String[3]=(int)PidParameterString.Kd+'0'; //将PID参数中的Kd转化字符型
	 Kd_String[4]='.';
	 Kd_String[5]=(int)((PidParameterString.Kd-(int)PidParameterString.Kd)*10)%10+'0';
	 Kd_String[6]=(int)((PidParameterString.Kd-(int)PidParameterString.Kd)*100)%10+'0';
	 Kd_String[7]='\0';
	 LCD_ShowString(0,34,100,15,16,Kd_String);  //将PID参数中的Kd显示在触摸屏指定位置上
	
	
}





void lcd_show_set_speed(unsigned short int x)  //设定速度显示函数，用于在触摸屏上显示设定速度
{
	int i=50; 
	for(i=50;i<319;i++)
  {
		LCD_DrawFRONT_COLOR(i,250-x,RED);
	}
	if(i>=319)i=50;
}


void lcd_show_really_speed(unsigned short int x)  //实际速度显示函数，用于在触摸屏上显示实际速度
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
	}
}



void usart_kp_change(void) //串口改变函数，用于改变PID参数Kp
{
		PidParameterString.Kp=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}


void usart_ki_change(void) //串口改变函数，用于改变PID参数Ki
{
		PidParameterString.Ki=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}

void usart_kd_change(void) //串口改变函数，用于改变PID参数Kd
{
		PidParameterString.Kd=((float)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[2]-'0'))*10+((int)(USART_RX_BUF[3]-'0'))))/100.0;
}

void usart_speed_change(void) //串口改变函数，用于改变设定速度
{
	if(USART_RX_BUF[0]=='1')
	{
		really_speed_angle=(int)(((int)(USART_RX_BUF[0]-'0'))*100+((int)(USART_RX_BUF[1]-'0'))*10+((int)(USART_RX_BUF[2]-'0')));
	}else if(USART_RX_BUF[0]!='1')
	{
		really_speed_angle=(int)(((int)(USART_RX_BUF[0]-'0'))*10+((int)(USART_RX_BUF[1]-'0')));
	}
}

void usart_angle_change(void) //串口改变函数，用于改变设定角度
{
	
}



void kp_eeprom_write(void)  //pid参数保存函数，将Kp值保存到eeprom中
{
	unsigned char kp_string_eeprom[6];  //定义PID参数中的Kp参数字符型保存数组，将浮点型变量Kp转化成字符型保存到eeprom
	
	kp_string_eeprom[0]=(int)PidParameterString.Kp+'0';
	kp_string_eeprom[1]='.';
	kp_string_eeprom[2]=((int)(PidParameterString.Kp*10))%10+'0';
	kp_string_eeprom[3]=((int)(PidParameterString.Kp*100))%10+'0';
	Writ_String(0x00,kp_string_eeprom,4);  //将浮点型的Kp保存到eeprom的指定位置
	
	
}


void ki_eeprom_write(void)  //pid参数保存函数，将Ki值保存到eeprom中
{
	unsigned char ki_string_eeprom[6];  //定义PID参数中的Ki参数字符型保存数组，将浮点型变量Ki转化成字符型保存到eeprom  
	
	ki_string_eeprom[0]=(int)PidParameterString.Ki+'0';
	ki_string_eeprom[1]='.';
	ki_string_eeprom[2]=((int)(PidParameterString.Ki*10))%10+'0';
	ki_string_eeprom[3]=((int)(PidParameterString.Ki*100))%10+'0';
	Writ_String(0x05,ki_string_eeprom,4);  //将浮点型的Ki保存到eeprom的指定位置
	
	
}


void kd_eeprom_write(void)  //pid参数保存函数，将Kd值保存到eeprom中
{
		unsigned char kd_string_eeprom[6];  //定义PID参数中的Kd参数字符型保存数组，将浮点型变量Kd转化成字符型保存到eeprom
	
	kd_string_eeprom[0]=(int)PidParameterString.Kd+'0';
	kd_string_eeprom[1]='.';
	kd_string_eeprom[2]=((int)(PidParameterString.Kd*10))%10+'0';
	kd_string_eeprom[3]=((int)(PidParameterString.Kd*100))%10+'0';
	Writ_String(0x0A,kd_string_eeprom,4);  //将浮点型的Kd保存到eeprom的指定位置
	
	
}


void speed_eeprom_write(void)  //设定速度保存函数，将设定速度保存到eeprom中
{
	if((really_speed_angle/100)>=0)
	{
	
		write_len_byte(0x0F,(unsigned int)really_speed_angle,3);

	}else if((really_speed_angle/100)<0)
	{
		write_len_byte(0x0F,(unsigned int)really_speed_angle,2);
	}
}









