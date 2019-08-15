#include"key.h"
#include"pid.h"
#include"stm32f10x.h"
#include "lcd.h"




unsigned int numbeer_acccumulation=0;  //定义按键数据累计变量
unsigned char Kp_flag=0; //定义按键Kp改变标志位
unsigned char Ki_flag=0;//定义按键Ki改变标志位
unsigned char Kd_flag=0;//定义按键Kd改变标志位
unsigned char speed_flag=0;//定义按键速度改变标志位
unsigned char angle_flag=0;//定义按键角度改变标志位
extern float pid_change_value_numbeer;//全局变量，声明按键改变的PID参数
float pid_result;//定义PID结果变量
extern unsigned int speed_angle_change_value_number; //全居变量，速度角度变量
unsigned char point_sunm=0; //定义小数点计数器
unsigned char point_flag=0; //定义小数点标志位
unsigned char point_digit=0; //定义小数点位数 
unsigned char wait_change_String[20]="Waiting..."; //定义提醒标志字符型数组
unsigned char clan_waiting_lcd[500]="                                                                 ";//清零数组
unsigned int Digit=0; //定义触摸屏显示X坐标变量
unsigned char point_lcd_show_String[3]="."; //小数点数组


extern unsigned char kp_usart_change_flag; //定义串口Kp改变标志位
extern unsigned char ki_usart_change_flag; //定义串口Ki改变标志位
extern unsigned char kd_usart_change_flag; //定义串口Kd改变标志位
extern unsigned char speed_usart_change_flag; //定义串口速度改变标志位
extern unsigned char angle_usart_change_flag; //定义串口角度改变标志位




void key16_init(void)  //按键初始化函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //定义GPIO初始化结构体变量
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE); //使能IO口时钟
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU; //上拉输入
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_All; //PF0到PF15
	
	GPIO_Init(GPIOF,&GPIO_InitTypeString); //初始化GPIOF
}

void key0_number_zero(void) //数字按键0，用于对所赋值数据最右端添0
{
	numbeer_acccumulation=numbeer_acccumulation*10+0; //当按键按下时，将前面所设数据*10再加0
	LCD_ShowNum(55+Digit,320,0,1,16); //在触摸屏上显示，已确定按下
	Digit=Digit+16; //触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key1_number_one(void) //数字按键1，用于对所赋值数据最右端添1
{
	numbeer_acccumulation=numbeer_acccumulation*10+1;//当按键按下时，将前面所设数据*10再加1
	LCD_ShowNum(55+Digit,320,1,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key2_number_two(void)//数字按键2，用于对所赋值数据最右端添2
{
	numbeer_acccumulation=numbeer_acccumulation*10+2;//当按键按下时，将前面所设数据*10再加2
	LCD_ShowNum(55+Digit,320,2,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}


void key3_number_three(void)//数字按键3，用于对所赋值数据最右端添3
{
	numbeer_acccumulation=numbeer_acccumulation*10+3;//当按键按下时，将前面所设数据*10再加3
	LCD_ShowNum(55+Digit,320,3,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key4_number_four(void)//数字按键4，用于对所赋值数据最右端添4
{
	numbeer_acccumulation=numbeer_acccumulation*10+4;//当按键按下时，将前面所设数据*10再加4
	LCD_ShowNum(55+Digit,320,4,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key5_number_five(void)//数字按键5，用于对所赋值数据最右端添5
{
	numbeer_acccumulation=numbeer_acccumulation*10+5;//当按键按下时，将前面所设数据*10再加5
	LCD_ShowNum(55+Digit,320,5,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key6_number_six(void)//数字按键6，用于对所赋值数据最右端添6
{
	numbeer_acccumulation=numbeer_acccumulation*10+6;//当按键按下时，将前面所设数据*10再加6
	LCD_ShowNum(55+Digit,320,6,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key7_number_seven(void)//数字按键7，用于对所赋值数据最右端添7
{
	numbeer_acccumulation=numbeer_acccumulation*10+7;//当按键按下时，将前面所设数据*10再加7
	LCD_ShowNum(55+Digit,320,7,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key8_number_eight(void)//数字按键8，用于对所赋值数据最右端添8
{
	numbeer_acccumulation=numbeer_acccumulation*10+8;//当按键按下时，将前面所设数据*10再加8
	LCD_ShowNum(55+Digit,320,8,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}


void key9_number_nine(void)//数字按键9，用于对所赋值数据最右端添9
{
	numbeer_acccumulation=numbeer_acccumulation*10+9;//当按键按下时，将前面所设数据*10再加9
	LCD_ShowNum(55+Digit,320,9,1,16);//在触摸屏上显示，已确定按下
	Digit=Digit+16;//触摸屏按键数据改变显示右移
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //检测是否在改变数据
	{
		if(point_flag==1)  //如果按下小数点，则小数点计数器自加1
		{
			point_sunm++;
		}
	}
}

void key10_Kp_change(void) //功能按键，用于改变PID参数中的Kp
{
	if(Kp_flag==0) //如果Kp标志位为0，改为1
	{
		Kp_flag=1;
	}else if(Kp_flag==1)//如果Kp标志位为1，改为0
	{
		Kp_flag=0;
	}
		if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //如果PID参数改变标志位全为0，则改变完成
	{
		pid_result=(float)numbeer_acccumulation; //赋值给PID结果变量
		for(point_digit=point_sunm;point_digit>0;point_digit--) //对结果在相应位置添加小数点
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //将结果赋给PID改变参数
		KP_Change(); //调用函数，改变Kp
		kp_eeprom_write(); //将改变的Kp写入eeprom
		numbeer_acccumulation=0; //清零按键数据累计变量
		point_sunm=0; //清零小数点位数
		Digit=0;//清零触摸屏相应位置的x坐标
	}
	if(Kp_flag==1) //当Kp标志位为1时，在相应位置显示Waiting，用来提醒正在改变Kp
	{
		LCD_ShowString(160,0,100,15,16,wait_change_String);
	}
	if(Kp_flag==0) //当Kp标志位为0时，清零提醒区域和数字显示区域
	{
		LCD_ShowString(160,0,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key11_Ki_change(void) //功能按键，用于改变PID参数中的Ki
{
	if(Ki_flag==0) //如果Ki标志位为0，改为1
	{	
	
		Ki_flag=1;
	  
	
	}else if(Ki_flag==1)//如果Ki标志位为1，改为0
	{
		
		Ki_flag=0;
	}
	
	
	
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //如果PID参数改变标志位全为0，则改变完成
	{
		pid_result=(float)numbeer_acccumulation; //赋值给PID结果变量
		for(point_digit=point_sunm;point_digit>0;point_digit--) //对结果在相应位置添加小数点
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //将结果赋给PID改变参数
		KI_Change(); //调用函数，改变Ki
		ki_eeprom_write(); //将改变的Ki写入eeprom
		numbeer_acccumulation=0; //清零按键数据累计变量
		point_sunm=0; //清零小数点位数
		Digit=0;//清零触摸屏相应位置的x坐标
	}
	if(Ki_flag==1)//当Ki标志位为1时，在相应位置显示Waiting，用来提醒正在改变Ki
	{
		LCD_ShowString(160,17,100,15,16,wait_change_String);
	}
	if(Ki_flag==0) //当Ki标志位为0时，清零提醒区域和数字显示区域
	{
		LCD_ShowString(160,17,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key12_Kd_change(void) //功能按键，用于改变PID参数中的Kd
{
	if(Kd_flag==0) //如果Kd标志位为0，改为1
	{
		
		Kd_flag=1;
	}else if(Kd_flag==1)//如果Kd标志位为1，改为0
	{
		Kd_flag=0;
		
	}
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //如果PID参数改变标志位全为0，则改变完成
	{
		pid_result=(float)numbeer_acccumulation; //赋值给PID结果变量
		for(point_digit=point_sunm;point_digit>0;point_digit--) //对结果在相应位置添加小数点
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //将结果赋给PID改变参数
		KD_Change(); //调用函数，改变Kd
		kd_eeprom_write();//将改变的Ki写入eeprom
		numbeer_acccumulation=0; //清零按键数据累计变量
		point_sunm=0; //清零小数点位数
		Digit=0;//清零触摸屏相应位置的x坐标
	}
	if(Kd_flag==1)//当Kd标志位为1时，在相应位置显示Waiting，用来提醒正在改变Kd
	{
		LCD_ShowString(160,34,100,15,16,wait_change_String);
	}
	if(Kd_flag==0) //当Ki标志位为0时，清零提醒区域和数字显示区域
	{
		LCD_ShowString(160,34,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key13_speed_set(void) //功能按键，用与改变速度
{
	if(speed_flag==0) //如果速度标志位为0，改为1
	{
		
		speed_flag=1;
	}else if(speed_flag==1) //如果速度标志位为1，改为0
	{
		
		speed_flag=0;
	}
	
	if(speed_flag==0) //如果速度标志位为0
	{
		speed_angle_change_value_number=numbeer_acccumulation; //将按键结果赋给速度改变变量
		Speed_Change(); //调用函数，改变设定速度
		
		
		speed_eeprom_write(); //调用函数，将改变的速度保存到eeprom
		numbeer_acccumulation=0; //清零按键数据累计变量
		point_sunm=0; //清零小数点位数
		Digit=0;//清零触摸屏相应位置的x坐标
	}
	if(speed_flag==1) //如果速度标志位为1，在相应位置显示Waiting，用来提醒
	{
			LCD_ShowString(160,51,100,15,16,wait_change_String);
	}
	if(speed_flag==0)//如果速度标志位为0，清零提醒区域和数字显示区域
	{
			LCD_ShowString(160,51,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key14_usart_pid_speed_angle_change(void) //功能按键，用来提醒哪一个变量将被串口改变
{
	
	static unsigned char i=0; //定义静态变量，用来设定不同的标志位
	unsigned char lcd_show_usart_kp_change_string[30]="kp change            ";  //定义串口Kp改变标志位字符型数组
	unsigned char lcd_show_usart_ki_change_string[30]="ki change            ";  //定义串口Ki改变标志位字符型数组
	unsigned char lcd_show_usart_kd_change_string[30]="kd change            ";  //定义串口Kd改变标志位字符型数组
	unsigned char lcd_show_usart_speed_change_string[30]="speed change      ";  //定义串口速度改变标志位字符型数组
	unsigned char lcd_show_usart_angle_change_string[30]="angle change      ";  //定义串口角度改变标志位字符型数组
	unsigned char lcd_usart_clean_show[30]="                     ";
	switch(i) //当检测到按键按下时，启动不同的数据改变标志位，并在触摸屏上显示，用来提醒
	{
		case 0:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;LCD_ShowString(37,410,100,15,16,lcd_usart_clean_show);i++;break;  //清零标志位
		case 1:kp_usart_change_flag=1;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_kp_change_string);break;  //开启Kp串口改变标志位
		case 2:kp_usart_change_flag=0;ki_usart_change_flag=1;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_ki_change_string);break;  //开启Ki串口改变标志位
		case 3:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=1;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_kd_change_string);break;  //开启Kd串口改变标志位
		case 4:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=1;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_speed_change_string);break;  //开启速度串口改变标志位
		case 5:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=1;i=0;LCD_ShowString(37,410,100,15,16,lcd_show_usart_angle_change_string);break;  //开启角度串口改变标志位
		default:break;
	}
		
}





void key15_decimal_point(void) //功能按键，用来添加小数点
{
	if(point_flag==0)point_flag=1; //当小数点标志位为0时，改为1
	else if(point_flag==1)point_flag=0; //当小数点标志位为1时，改为0
		LCD_ShowString(55+Digit,320,100,15,16,point_lcd_show_String); //在触摸屏上显示小数点
		Digit=Digit+16; //触摸屏按键数据改变显示右移
}
