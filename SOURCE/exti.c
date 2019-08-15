#include"exti.h"
#include"stm32f10x.h"
#include "delay.h"
#include"key.h"



void exti_key16_init(void)  //�ⲿ�жϳ�ʼ������
{
	EXTI_InitTypeDef EXTI_InitTypestring; //�����ⲿ�жϳ�ʼ���ṹ�����
	NVIC_InitTypeDef NVIC_InitTypestring; //��ʼ��NVIC��ʼ���ṹ�����
	
	key16_init();  //��ʼ������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //ʹ�����Ÿ���ʱ��
	////////////////////////////////////////////////////////0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource0);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line0;//�����ж���Ϊ�ⲿ�ж�0
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI0_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�0
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;//ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1; //������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	////////////////////////////////////////////////////////1
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource1);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line1;//�����ж���Ϊ�ⲿ�ж�1
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI1_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�1
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////2
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource2);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line2;//�����ж���Ϊ�ⲿ�ж�2
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI2_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�2
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////3
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource3);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line3;//�����ж���Ϊ�ⲿ�ж�3
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI3_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�3
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////4
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource4);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line4;//�����ж���Ϊ�ⲿ�ж�4
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI4_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�4
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////5
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource5);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line5;//�����ж���Ϊ�ⲿ�ж�5
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�5��9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////6
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource6);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line6;//�����ж���Ϊ�ⲿ�ж�6
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�5��9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////7
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource7);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line7;//�����ж���Ϊ�ⲿ�ж�7
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�5��9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////8
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource8);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line8;//�����ж���Ϊ�ⲿ�ж�8
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�5��9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////9
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource9);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line9;//�����ж���Ϊ�ⲿ�ж�9
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI9_5_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�5��9
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////10
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource10);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line10;//�����ж���Ϊ�ⲿ�ж�10
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////11
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource11);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line11;//�����ж���Ϊ�ⲿ�ж�11
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE;//ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////12
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource12);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line12;//�����ж���Ϊ�ⲿ�ж�12
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////13
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource13);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line13;//�����ж���Ϊ�ⲿ�ж�13
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////14
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource14);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line14;//�����ж���Ϊ�ⲿ�ж�14
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////15
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF,GPIO_PinSource15);//����IO�����ж��ߵ�ӳ���ϵ
	
	EXTI_InitTypestring.EXTI_Line=EXTI_Line15;//�����ж���Ϊ�ⲿ�ж�15
	EXTI_InitTypestring.EXTI_LineCmd=ENABLE; //ʹ��
	EXTI_InitTypestring.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�����
	EXTI_InitTypestring.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&EXTI_InitTypestring);//��ʼ���ⲿ�ж�
	
	NVIC_InitTypestring.NVIC_IRQChannel=EXTI15_10_IRQn;//�����ж�ͨ��Ϊ�ⲿ�ж�10��15
	NVIC_InitTypestring.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypestring.NVIC_IRQChannelPreemptionPriority=1;//������ռ���ȼ�
	NVIC_InitTypestring.NVIC_IRQChannelSubPriority=1;//���������ȼ�
	NVIC_Init(&NVIC_InitTypestring);//��ʼ��NVIC
	/////////////////////////////////////////////////////////

}

void EXTI0_IRQHandler(void)  //�ⲿ�жϺ���0
{
	delay_ms(10); //��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)==0) //��ⰴ��0�Ƿ���
	{
		key0_number_zero(); //���ú�����ִ�а���0�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line0); //�����־λ
}
	
	
void EXTI1_IRQHandler(void)//�ⲿ�жϺ���1
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)==0) //��ⰴ��1�Ƿ���
	{
		key1_number_one();//���ú�����ִ�а���1�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line1); //�����־λ
}
	
	
	
void EXTI2_IRQHandler(void)//�ⲿ�жϺ���2
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)==0) //��ⰴ��2�Ƿ���
	{
		key2_number_two();//���ú�����ִ�а���2�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line2); //�����־λ
}
	
	
	
void EXTI3_IRQHandler(void)//�ⲿ�жϺ���3
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)==0) //��ⰴ��3�Ƿ���
	{
		key3_number_three();//���ú�����ִ�а���3�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line3); //�����־λ
}
	
	
	
void EXTI4_IRQHandler(void)//�ⲿ�жϺ���4
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)==0) //��ⰴ��4�Ƿ���
	{
		key4_number_four();//���ú�����ִ�а���4�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line4); //�����־λ
}
	
	

void EXTI9_5_IRQHandler(void)//�ⲿ�жϺ���5��9
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)==0) //��ⰴ��5�Ƿ���
	{
		key5_number_five();//���ú�����ִ�а���5�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line5); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)==0) //��ⰴ��6�Ƿ���
	{
		key6_number_six();//���ú�����ִ�а���6�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line6); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7)==0) //��ⰴ��7�Ƿ���
	{
		key7_number_seven();//���ú�����ִ�а���7�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line7); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8)==0) //��ⰴ��8�Ƿ���
	{
		key8_number_eight();//���ú�����ִ�а���8�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line8); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9)==0) //��ⰴ��9�Ƿ���
	{
		key9_number_nine();//���ú�����ִ�а���9�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line9); //�����־λ
}
	
	
	
void EXTI15_10_IRQHandler(void)//�ⲿ�жϺ���10��15
{
	delay_ms(10);//��ʱ10ms������
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10)==0) //��ⰴ��10�Ƿ���
	{
		key10_Kp_change();//���ú�����ִ�а���10�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line10); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11)==0) //��ⰴ��11�Ƿ���
	{
		key11_Ki_change();//���ú�����ִ�а���11�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line11); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12)==0) //��ⰴ��12�Ƿ���
	{
		key12_Kd_change();//���ú�����ִ�а���12�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line12); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_13)==0) //��ⰴ��13�Ƿ���
	{
		key13_speed_set();//���ú�����ִ�а���13�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line13); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14)==0) //��ⰴ��14�Ƿ���
	{
		
		
		key14_usart_pid_speed_angle_change();//���ú�����ִ�а���14�Ĺ���
	
	}	
	EXTI_ClearITPendingBit(EXTI_Line14); //�����־λ
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15)==0) //��ⰴ��15�Ƿ���
	{
		key15_decimal_point();//���ú�����ִ�а���15�Ĺ���
	}	
	EXTI_ClearITPendingBit(EXTI_Line15); //�����־λ




}

	
















