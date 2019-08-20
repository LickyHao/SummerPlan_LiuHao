#include"encoder_tim5.h"
#include"stm32f10x.h"

extern int encoder_number;  //���������������

void encoder_init(void) //��������ʼ������
{
	GPIO_InitTypeDef GPIO_InitTypeString;//����GPIO�ڳ�ʼ���ṹ�����
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString;//���嶨ʱ����ʼ���ṹ�����
	TIM_ICInitTypeDef TIM_ICInitTypeString; //�����ʼ�����趨ʱ���ṹ�����
	NVIC_InitTypeDef NVIC_InitTypeString; //����NVIC��ʼ���ṹ�����
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);//ʹ�ܶ�ʱ��5ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//ʹ��IO��ʱ��
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_0;//ʹ��PA0
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHZ
	GPIO_Init(GPIOA,&GPIO_InitTypeString); //��ʼ��IO��

	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1; //����ʱ�ӷָ�
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitTypeString.TIM_Period=899;//�����Զ���װ��ֵ
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0; //����Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitTypeString);//��ʼ����ʱ��5

	TIM_ICInitTypeString.TIM_Channel=TIM_Channel_1; //����ͨ��1
	TIM_ICInitTypeString.TIM_ICFilter=0x00;//�˲���
	TIM_ICInitTypeString.TIM_ICPolarity=TIM_ICPolarity_Rising;//�����ز���
	TIM_ICInitTypeString.TIM_ICPrescaler=TIM_ICPSC_DIV1;//���÷�Ƶϵ��Ϊ1
	TIM_ICInitTypeString.TIM_ICSelection=TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM_ICInit(TIM5,&TIM_ICInitTypeString);//��ʼ�����趨ʱ��5
	
	TIM_ITConfig(TIM5,TIM_IT_CC1,ENABLE);//ʹ��TIM5�ж�
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM5_IRQn;//�����ж�ͨ��Ϊ��ʱ��5
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE; //ʹ��
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�Ϊ1
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;//�����ȼ�Ϊ0
	NVIC_Init(&NVIC_InitTypeString);   //��ʼ��NVIC

	TIM_Cmd(TIM5,ENABLE); //ʹ�ܶ�ʱ��5
	

	
}



void TIM5_IRQHandler(void)  //��ʱ��5�жϺ���
{
	if(TIM_GetITStatus(TIM5,TIM_IT_CC1)==SET)  //����Ƿ����ж�
	{
		
		encoder_number++;  //�������������Լ�1
		TIM_ClearITPendingBit(TIM5,TIM_IT_CC1); //�����жϱ�־λ
	}
}






