#include"motor_time1.h"
#include"stm32f10x.h"

void time1_motor_init(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString;
	TIM_OCInitTypeDef TIM_OCInitTypeString;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeString);
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeString);
	
	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitTypeString.TIM_Period=899;
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0;
	TIM_TimeBaseInitTypeString.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitTypeString);

	TIM_OCInitTypeString.TIM_OCIdleState=TIM_OCIdleState_Reset;
	TIM_OCInitTypeString.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeString.TIM_OCNIdleState=TIM_OCNIdleState_Reset;
	TIM_OCInitTypeString.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitTypeString.TIM_OutputNState=TIM_OutputNState_Enable;
	TIM_OCInitTypeString.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitTypeString.TIM_OCNPolarity=TIM_OCNPolarity_High;
	TIM_OC1Init(TIM1,&TIM_OCInitTypeString);
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	TIM_Cmd(TIM1,ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
}


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











