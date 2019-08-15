#include"exti.h"
#include"stm32f10x.h"
#include "delay.h"
#include"key.h"



void exti_key16_init(void)  //外部中断初始化函数
{
	EXTI_InitTypeDef EXTI_InitTypestring; //定义外部中断初始化结构体变量
	NVIC_InitTypeDef NVIC_InitTypestring; //初始化NVIC初始化结构体变量
	
	key16_init();  //初始化按键
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //使能引脚复用时钟
	////////////////////////////////////////////////////////0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource0);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line0;//配置中断线为外部中断0
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI0_IRQn;//设置中断通道为外部中断0
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;//使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1; //设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	////////////////////////////////////////////////////////1
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource1);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line1;//配置中断线为外部中断1
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI1_IRQn;//设置中断通道为外部中断1
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////2
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource2);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line2;//配置中断线为外部中断2
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI2_IRQn;//设置中断通道为外部中断2
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////3
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource3);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line3;//配置中断线为外部中断3
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI3_IRQn;//设置中断通道为外部中断3
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////4
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource4);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line4;//配置中断线为外部中断4
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI4_IRQn;//设置中断通道为外部中断4
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////5
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource5);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line5;//配置中断线为外部中断5
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//设置中断通道为外部中断5到9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////6
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource6);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line6;//配置中断线为外部中断6
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//设置中断通道为外部中断5到9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////7
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource7);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line7;//配置中断线为外部中断7
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//设置中断通道为外部中断5到9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////8
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource8);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line8;//配置中断线为外部中断8
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//设置中断通道为外部中断5到9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////9
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource9);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line9;//配置中断线为外部中断9
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//设置中断通道为外部中断5到9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////10
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource10);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line10;//配置中断线为外部中断10
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////11
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource11);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line11;//配置中断线为外部中断11
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;//使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////12
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource12);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line12;//配置中断线为外部中断12
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////13
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource13);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line13;//配置中断线为外部中断13
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////14
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource14);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line14;//配置中断线为外部中断14
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////15
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource15);//设置IO口与中断线的映射关系
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line15;//配置中断线为外部中断15
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //使能
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//中断请求
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypestring);//初始化外部中断
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//设置中断通道为外部中断10到15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//设置子优先级
	NVIC_Init(&NVIC_InitTypestring);//初始化NVIC
	/////////////////////////////////////////////////////////

}

void EXTI0_IRQHandler(void)  //外部中断函数0
{
	delay_ms(10); //延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==0) //检测按键0是否按下
	{
		key0_number_zero(); //调用函数，执行按键0的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line0); //清零标志位
}
	
	
void EXTI1_IRQHandler(void)//外部中断函数1
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==0) //检测按键1是否按下
	{
		key1_number_one();//调用函数，执行按键1的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line1); //清零标志位
}
	
	
	
void EXTI2_IRQHandler(void)//外部中断函数2
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==0) //检测按键2是否按下
	{
		key2_number_two();//调用函数，执行按键2的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line2); //清零标志位
}
	
	
	
void EXTI3_IRQHandler(void)//外部中断函数3
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==0) //检测按键3是否按下
	{
		key3_number_three();//调用函数，执行按键3的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line3); //清零标志位
}
	
	
	
void EXTI4_IRQHandler(void)//外部中断函数4
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)==0) //检测按键4是否按下
	{
		key4_number_four();//调用函数，执行按键4的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line4); //清零标志位
}
	
	

void EXTI9_5_IRQHandler(void)//外部中断函数5到9
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)==0) //检测按键5是否按下
	{
		key5_number_five();//调用函数，执行按键5的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line5); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)==0) //检测按键6是否按下
	{
		key6_number_six();//调用函数，执行按键6的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line6); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7)==0) //检测按键7是否按下
	{
		key7_number_seven();//调用函数，执行按键7的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line7); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8)==0) //检测按键8是否按下
	{
		key8_number_eight();//调用函数，执行按键8的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line8); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9)==0) //检测按键9是否按下
	{
		key9_number_nine();//调用函数，执行按键9的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line9); //清零标志位
}
	
	
	
void EXTI15_10_IRQHandler(void)//外部中断函数10到15
{
	delay_ms(10);//延时10ms，消抖
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10)==0) //检测按键10是否按下
	{
		key10_Kp_change();//调用函数，执行按键10的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line10); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11)==0) //检测按键11是否按下
	{
		key11_Ki_change();//调用函数，执行按键11的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line11); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12)==0) //检测按键12是否按下
	{
		key12_Kd_change();//调用函数，执行按键12的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line12); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_13)==0) //检测按键13是否按下
	{
		key13_speed_set();//调用函数，执行按键13的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line13); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14)==0) //检测按键14是否按下
	{
		
		
		key14_usart_pid_speed_angle_change();//调用函数，执行按键14的功能
	
	}	
	EXTI_ClearITPendingBit(EXTI_Line14); //清零标志位
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15)==0) //检测按键15是否按下
	{
		key15_decimal_point();//调用函数，执行按键15的功能
	}	
	EXTI_ClearITPendingBit(EXTI_Line15); //清零标志位




}

	
















