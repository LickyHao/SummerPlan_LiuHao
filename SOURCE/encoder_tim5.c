#include"encoder_tim5.h"
#include"stm32f10x.h"

extern int encoder_number;

void encoder_init(void)
{
	GPIO_InitTypeDef GPIO_InitTypeString;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString;
	TIM_ICInitTypeDef TIM_ICInitTypeString;
	NVIC_InitTypeDef NVIC_InitTypeString;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeString);

	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitTypeString.TIM_Period=899;
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0;
	TIM_TimeBaseInitTypeString.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitTypeString);

	TIM_ICInitTypeString.TIM_Channel=TIM_Channel_1;
	TIM_ICInitTypeString.TIM_ICFilter=0x00;
	TIM_ICInitTypeString.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitTypeString.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitTypeString.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM5,&TIM_ICInitTypeString);
	
	TIM_ITConfig(TIM5,TIM_IT_CC1,ENABLE);
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM5_IRQn;
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE; 
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitTypeString);

	TIM_Cmd(TIM5,ENABLE);
	

	
}



void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_CC1)==SET)
	{
		
		encoder_number++;
		TIM_ClearITPendingBit(TIM5,TIM_IT_CC1);
	}
}






