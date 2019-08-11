#include"exti.h"
#include"stm32f10x.h"
#include "delay.h"
#include"key.h"



void exti_key16_init(void)
{
	EXTI_InitTypeDef EXTI_InitTypestring;
	NVIC_InitTypeDef NVIC_InitTypestring;
	
	key16_init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	////////////////////////////////////////////////////////0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource0);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line0;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	////////////////////////////////////////////////////////1
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource1);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line1;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////2
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource2);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line2;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI2_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////3
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource3);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line3;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////4
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource4);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line4;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////5
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource5);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line5;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////6
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource6);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line6;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////7
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource7);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line7;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////8
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource8);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line8;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////9
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource9);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line9;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////10
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource10);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line10;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////11
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource11);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line11;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////12
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource12);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line12;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////13
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource13);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line13;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////14
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource14);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line14;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////15
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource15);
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line15;
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE;
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypestring);
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitTypestring);
	/////////////////////////////////////////////////////////

}

void EXTI0_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==0)
	{
		key0_number_zero();
	}	
	EXTI_ClearITPendingBit(EXTI_Line0);
}
	
	
void EXTI1_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==0)
	{
		key1_number_one();
	}	
	EXTI_ClearITPendingBit(EXTI_Line1);
}
	
	
	
void EXTI2_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==0)
	{
		key2_number_two();
	}	
	EXTI_ClearITPendingBit(EXTI_Line2);
}
	
	
	
void EXTI3_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==0)
	{
		key3_number_three();
	}	
	EXTI_ClearITPendingBit(EXTI_Line3);
}
	
	
	
void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)==0)
	{
		key4_number_four();
	}	
	EXTI_ClearITPendingBit(EXTI_Line4);
}
	
	

void EXTI9_5_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)==0)
	{
		key5_number_five();
	}	
	EXTI_ClearITPendingBit(EXTI_Line5);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)==0)
	{
		key6_number_six();
	}	
	EXTI_ClearITPendingBit(EXTI_Line6);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7)==0)
	{
		key7_number_seven();
	}	
	EXTI_ClearITPendingBit(EXTI_Line7);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8)==0)
	{
		key8_number_eight();
	}	
	EXTI_ClearITPendingBit(EXTI_Line8);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9)==0)
	{
		key9_number_nine();
	}	
	EXTI_ClearITPendingBit(EXTI_Line9);
}
	
	
	
void EXTI15_10_IRQHandler(void)
{
	delay_ms(10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10)==0)
	{
		key10_Kp_change();
	}	
	EXTI_ClearITPendingBit(EXTI_Line10);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11)==0)
	{
		key11_Ki_change();
	}	
	EXTI_ClearITPendingBit(EXTI_Line11);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12)==0)
	{
		key12_Kd_change();
	}	
	EXTI_ClearITPendingBit(EXTI_Line12);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_13)==0)
	{
		key13_speed_set();
	}	
	EXTI_ClearITPendingBit(EXTI_Line13);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14)==0)
	{
		key14_angle_set();
	}	
	EXTI_ClearITPendingBit(EXTI_Line14);
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15)==0)
	{
		key15_decimal_point();
	}	
	EXTI_ClearITPendingBit(EXTI_Line15);




}

	
















