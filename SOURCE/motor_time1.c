#include"motor_time1.h"
#include"stm32f10x.h"




void tim4_motor_init(void)  //��ʼ����ʱ��4����
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //����GPIO�ڳ�ʼ���ṹ�����
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString; //���嶨ʱ����ʼ���ṹ�����
	TIM_OCInitTypeDef TIM_OCInitTypeString;  //�����ʼ������Ƚϲ����ṹ�����
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  //ʹ�ܶ�ʱ��4��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO,ENABLE);  //ʹ��GPIO�ڵ�ʱ��
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_AF_PP;  //�����������
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_12;  //ʹ��PD12
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;  //IO���ٶ�Ϊ50MHZ
	GPIO_Init(GPIOD,&GPIO_InitTypeString);  //��ʼ��IO��
	
	
	GPIO_PinRemapConfig(GPIO_Remap_TIM4,ENABLE);  //������ӳ��
	
	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1;  //����ʱ�ӷָ�
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up;  //���ϼ���ģʽ
	TIM_TimeBaseInitTypeString.TIM_Period=899; //�����Զ���װ��ֵ
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0; //����Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitTypeString);  //��ʼ����ʱ��4
	
	TIM_OCInitTypeString.TIM_OCMode=TIM_OCMode_PWM2;    //����ΪPWMģʽ2
	TIM_OCInitTypeString.TIM_OutputState=TIM_OutputState_Enable; //���ʱ��
	TIM_OCInitTypeString.TIM_OCPolarity=TIM_OCPolarity_High;//�������Ϊ��
	TIM_OC1Init(TIM4,&TIM_OCInitTypeString); //��ʼ������Ƚϲ���
	
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable); //ʹ��Ԥװ�ؼĴ���
	TIM_Cmd(TIM4,ENABLE); //ʹ�ܶ�ʱ��4
}











