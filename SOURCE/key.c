#include"key.h"
#include"pid.h"
#include"stm32f10x.h"
#include "lcd.h"




unsigned int numbeer_acccumulation=0;  //���尴�������ۼƱ���
unsigned char Kp_flag=0; //���尴��Kp�ı��־λ
unsigned char Ki_flag=0;//���尴��Ki�ı��־λ
unsigned char Kd_flag=0;//���尴��Kd�ı��־λ
unsigned char speed_flag=0;//���尴���ٶȸı��־λ
unsigned char angle_flag=0;//���尴���Ƕȸı��־λ
extern float pid_change_value_numbeer;//ȫ�ֱ��������������ı��PID����
float pid_result;//����PID�������
extern unsigned int speed_angle_change_value_number; //ȫ�ӱ������ٶȽǶȱ���
unsigned char point_sunm=0; //����С���������
unsigned char point_flag=0; //����С�����־λ
unsigned char point_digit=0; //����С����λ�� 
unsigned char wait_change_String[20]="Waiting..."; //�������ѱ�־�ַ�������
unsigned char clan_waiting_lcd[500]="                                                                 ";//��������
unsigned int Digit=0; //���崥������ʾX�������
unsigned char point_lcd_show_String[3]="."; //С��������


extern unsigned char kp_usart_change_flag; //���崮��Kp�ı��־λ
extern unsigned char ki_usart_change_flag; //���崮��Ki�ı��־λ
extern unsigned char kd_usart_change_flag; //���崮��Kd�ı��־λ
extern unsigned char speed_usart_change_flag; //���崮���ٶȸı��־λ
extern unsigned char angle_usart_change_flag; //���崮�ڽǶȸı��־λ




void key16_init(void)  //������ʼ������
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //����GPIO��ʼ���ṹ�����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE); //ʹ��IO��ʱ��
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IPU; //��������
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_All; //PF0��PF15
	
	GPIO_Init(GPIOF,&GPIO_InitTypeString); //��ʼ��GPIOF
}

void key0_number_zero(void) //���ְ���0�����ڶ�����ֵ�������Ҷ���0
{
	numbeer_acccumulation=numbeer_acccumulation*10+0; //����������ʱ����ǰ����������*10�ټ�0
	LCD_ShowNum(55+Digit,320,0,1,16); //�ڴ���������ʾ����ȷ������
	Digit=Digit+16; //�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key1_number_one(void) //���ְ���1�����ڶ�����ֵ�������Ҷ���1
{
	numbeer_acccumulation=numbeer_acccumulation*10+1;//����������ʱ����ǰ����������*10�ټ�1
	LCD_ShowNum(55+Digit,320,1,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key2_number_two(void)//���ְ���2�����ڶ�����ֵ�������Ҷ���2
{
	numbeer_acccumulation=numbeer_acccumulation*10+2;//����������ʱ����ǰ����������*10�ټ�2
	LCD_ShowNum(55+Digit,320,2,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}


void key3_number_three(void)//���ְ���3�����ڶ�����ֵ�������Ҷ���3
{
	numbeer_acccumulation=numbeer_acccumulation*10+3;//����������ʱ����ǰ����������*10�ټ�3
	LCD_ShowNum(55+Digit,320,3,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key4_number_four(void)//���ְ���4�����ڶ�����ֵ�������Ҷ���4
{
	numbeer_acccumulation=numbeer_acccumulation*10+4;//����������ʱ����ǰ����������*10�ټ�4
	LCD_ShowNum(55+Digit,320,4,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key5_number_five(void)//���ְ���5�����ڶ�����ֵ�������Ҷ���5
{
	numbeer_acccumulation=numbeer_acccumulation*10+5;//����������ʱ����ǰ����������*10�ټ�5
	LCD_ShowNum(55+Digit,320,5,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key6_number_six(void)//���ְ���6�����ڶ�����ֵ�������Ҷ���6
{
	numbeer_acccumulation=numbeer_acccumulation*10+6;//����������ʱ����ǰ����������*10�ټ�6
	LCD_ShowNum(55+Digit,320,6,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key7_number_seven(void)//���ְ���7�����ڶ�����ֵ�������Ҷ���7
{
	numbeer_acccumulation=numbeer_acccumulation*10+7;//����������ʱ����ǰ����������*10�ټ�7
	LCD_ShowNum(55+Digit,320,7,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key8_number_eight(void)//���ְ���8�����ڶ�����ֵ�������Ҷ���8
{
	numbeer_acccumulation=numbeer_acccumulation*10+8;//����������ʱ����ǰ����������*10�ټ�8
	LCD_ShowNum(55+Digit,320,8,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}


void key9_number_nine(void)//���ְ���9�����ڶ�����ֵ�������Ҷ���9
{
	numbeer_acccumulation=numbeer_acccumulation*10+9;//����������ʱ����ǰ����������*10�ټ�9
	LCD_ShowNum(55+Digit,320,9,1,16);//�ڴ���������ʾ����ȷ������
	Digit=Digit+16;//�������������ݸı���ʾ����
	if((Kp_flag==1&&Ki_flag==0&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==1&&Kd_flag==0)||(Kp_flag==0&&Ki_flag==0&&Kd_flag==1)) //����Ƿ��ڸı�����
	{
		if(point_flag==1)  //�������С���㣬��С����������Լ�1
		{
			point_sunm++;
		}
	}
}

void key10_Kp_change(void) //���ܰ��������ڸı�PID�����е�Kp
{
	if(Kp_flag==0) //���Kp��־λΪ0����Ϊ1
	{
		Kp_flag=1;
	}else if(Kp_flag==1)//���Kp��־λΪ1����Ϊ0
	{
		Kp_flag=0;
	}
		if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //���PID�����ı��־λȫΪ0����ı����
	{
		pid_result=(float)numbeer_acccumulation; //��ֵ��PID�������
		for(point_digit=point_sunm;point_digit>0;point_digit--) //�Խ������Ӧλ�����С����
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //���������PID�ı����
		KP_Change(); //���ú������ı�Kp
		kp_eeprom_write(); //���ı��Kpд��eeprom
		numbeer_acccumulation=0; //���㰴�������ۼƱ���
		point_sunm=0; //����С����λ��
		Digit=0;//���㴥������Ӧλ�õ�x����
	}
	if(Kp_flag==1) //��Kp��־λΪ1ʱ������Ӧλ����ʾWaiting�������������ڸı�Kp
	{
		LCD_ShowString(160,0,100,15,16,wait_change_String);
	}
	if(Kp_flag==0) //��Kp��־λΪ0ʱ���������������������ʾ����
	{
		LCD_ShowString(160,0,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key11_Ki_change(void) //���ܰ��������ڸı�PID�����е�Ki
{
	if(Ki_flag==0) //���Ki��־λΪ0����Ϊ1
	{	
	
		Ki_flag=1;
	  
	
	}else if(Ki_flag==1)//���Ki��־λΪ1����Ϊ0
	{
		
		Ki_flag=0;
	}
	
	
	
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //���PID�����ı��־λȫΪ0����ı����
	{
		pid_result=(float)numbeer_acccumulation; //��ֵ��PID�������
		for(point_digit=point_sunm;point_digit>0;point_digit--) //�Խ������Ӧλ�����С����
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //���������PID�ı����
		KI_Change(); //���ú������ı�Ki
		ki_eeprom_write(); //���ı��Kiд��eeprom
		numbeer_acccumulation=0; //���㰴�������ۼƱ���
		point_sunm=0; //����С����λ��
		Digit=0;//���㴥������Ӧλ�õ�x����
	}
	if(Ki_flag==1)//��Ki��־λΪ1ʱ������Ӧλ����ʾWaiting�������������ڸı�Ki
	{
		LCD_ShowString(160,17,100,15,16,wait_change_String);
	}
	if(Ki_flag==0) //��Ki��־λΪ0ʱ���������������������ʾ����
	{
		LCD_ShowString(160,17,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key12_Kd_change(void) //���ܰ��������ڸı�PID�����е�Kd
{
	if(Kd_flag==0) //���Kd��־λΪ0����Ϊ1
	{
		
		Kd_flag=1;
	}else if(Kd_flag==1)//���Kd��־λΪ1����Ϊ0
	{
		Kd_flag=0;
		
	}
	if(Kp_flag==0&&Ki_flag==0&&Kd_flag==0)  //���PID�����ı��־λȫΪ0����ı����
	{
		pid_result=(float)numbeer_acccumulation; //��ֵ��PID�������
		for(point_digit=point_sunm;point_digit>0;point_digit--) //�Խ������Ӧλ�����С����
		{
			pid_result=pid_result/10.0;
		}
		pid_change_value_numbeer=pid_result; //���������PID�ı����
		KD_Change(); //���ú������ı�Kd
		kd_eeprom_write();//���ı��Kiд��eeprom
		numbeer_acccumulation=0; //���㰴�������ۼƱ���
		point_sunm=0; //����С����λ��
		Digit=0;//���㴥������Ӧλ�õ�x����
	}
	if(Kd_flag==1)//��Kd��־λΪ1ʱ������Ӧλ����ʾWaiting�������������ڸı�Kd
	{
		LCD_ShowString(160,34,100,15,16,wait_change_String);
	}
	if(Kd_flag==0) //��Ki��־λΪ0ʱ���������������������ʾ����
	{
		LCD_ShowString(160,34,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key13_speed_set(void) //���ܰ���������ı��ٶ�
{
	if(speed_flag==0) //����ٶȱ�־λΪ0����Ϊ1
	{
		
		speed_flag=1;
	}else if(speed_flag==1) //����ٶȱ�־λΪ1����Ϊ0
	{
		
		speed_flag=0;
	}
	
	if(speed_flag==0) //����ٶȱ�־λΪ0
	{
		speed_angle_change_value_number=numbeer_acccumulation; //��������������ٶȸı����
		Speed_Change(); //���ú������ı��趨�ٶ�
		
		
		speed_eeprom_write(); //���ú��������ı���ٶȱ��浽eeprom
		numbeer_acccumulation=0; //���㰴�������ۼƱ���
		point_sunm=0; //����С����λ��
		Digit=0;//���㴥������Ӧλ�õ�x����
	}
	if(speed_flag==1) //����ٶȱ�־λΪ1������Ӧλ����ʾWaiting����������
	{
			LCD_ShowString(160,51,100,15,16,wait_change_String);
	}
	if(speed_flag==0)//����ٶȱ�־λΪ0���������������������ʾ����
	{
			LCD_ShowString(160,51,100,15,16,clan_waiting_lcd);
		LCD_ShowString(55,320,300,15,16,clan_waiting_lcd);
	}
}

void key14_usart_pid_speed_angle_change(void) //���ܰ���������������һ�������������ڸı�
{
	
	static unsigned char i=0; //���徲̬�����������趨��ͬ�ı�־λ
	unsigned char lcd_show_usart_kp_change_string[30]="kp change            ";  //���崮��Kp�ı��־λ�ַ�������
	unsigned char lcd_show_usart_ki_change_string[30]="ki change            ";  //���崮��Ki�ı��־λ�ַ�������
	unsigned char lcd_show_usart_kd_change_string[30]="kd change            ";  //���崮��Kd�ı��־λ�ַ�������
	unsigned char lcd_show_usart_speed_change_string[30]="speed change      ";  //���崮���ٶȸı��־λ�ַ�������
	unsigned char lcd_show_usart_angle_change_string[30]="angle change      ";  //���崮�ڽǶȸı��־λ�ַ�������
	unsigned char lcd_usart_clean_show[30]="                     ";
	switch(i) //����⵽��������ʱ��������ͬ�����ݸı��־λ�����ڴ���������ʾ����������
	{
		case 0:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;LCD_ShowString(37,410,100,15,16,lcd_usart_clean_show);i++;break;  //�����־λ
		case 1:kp_usart_change_flag=1;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_kp_change_string);break;  //����Kp���ڸı��־λ
		case 2:kp_usart_change_flag=0;ki_usart_change_flag=1;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_ki_change_string);break;  //����Ki���ڸı��־λ
		case 3:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=1;speed_usart_change_flag=0;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_kd_change_string);break;  //����Kd���ڸı��־λ
		case 4:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=1;angle_usart_change_flag=0;i++;LCD_ShowString(37,410,100,15,16,lcd_show_usart_speed_change_string);break;  //�����ٶȴ��ڸı��־λ
		case 5:kp_usart_change_flag=0;ki_usart_change_flag=0;kd_usart_change_flag=0;speed_usart_change_flag=0;angle_usart_change_flag=1;i=0;LCD_ShowString(37,410,100,15,16,lcd_show_usart_angle_change_string);break;  //�����Ƕȴ��ڸı��־λ
		default:break;
	}
		
}





void key15_decimal_point(void) //���ܰ������������С����
{
	if(point_flag==0)point_flag=1; //��С�����־λΪ0ʱ����Ϊ1
	else if(point_flag==1)point_flag=0; //��С�����־λΪ1ʱ����Ϊ0
		LCD_ShowString(55+Digit,320,100,15,16,point_lcd_show_String); //�ڴ���������ʾС����
		Digit=Digit+16; //�������������ݸı���ʾ����
}
