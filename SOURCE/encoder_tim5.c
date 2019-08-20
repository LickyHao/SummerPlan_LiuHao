#include"encoder_tim5.h"
#include"stm32f10x.h"

extern int encoder_number;  //定义编码器计数器

void encoder_init(void) //编码器初始化函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;//定义GPIO口初始化结构体变量
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString;//定义定时器初始化结构体变量
	TIM_ICInitTypeDef TIM_ICInitTypeString; //定义初始化外设定时器结构体变量
	NVIC_InitTypeDef NVIC_InitTypeString; //定义NVIC初始化结构体变量
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);//使能定时器5时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);//使能IO口时钟
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_IN_FLOATING;//设置浮空输入
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_0;//使能PA0
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;//IO口速度为50MHZ
	GPIO_Init(GPIOA,&GPIO_InitTypeString); //初始化IO口

	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1; //设置时钟分割
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitTypeString.TIM_Period=899;//设置自动重装载值
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0; //设置预分频系数
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitTypeString);//初始化定时器5

	TIM_ICInitTypeString.TIM_Channel=TIM_Channel_1; //设置通道1
	TIM_ICInitTypeString.TIM_ICFilter=0x00;//滤波器
	TIM_ICInitTypeString.TIM_ICPolarity=TIM_ICPolarity_Rising;//上升沿捕获
	TIM_ICInitTypeString.TIM_ICPrescaler=TIM_ICPSC_DIV1;//设置分频系数为1
	TIM_ICInitTypeString.TIM_ICSelection=TIM_ICSelection_DirectTI; //映射到TI1上
	TIM_ICInit(TIM5,&TIM_ICInitTypeString);//初始化外设定时器5
	
	TIM_ITConfig(TIM5,TIM_IT_CC1,ENABLE);//使能TIM5中断
	
	NVIC_InitTypeString.NVIC_IRQChannel=TIM5_IRQn;//设置中断通道为定时器5
	NVIC_InitTypeString.NVIC_IRQChannelCmd=ENABLE; //使能
	NVIC_InitTypeString.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级为1
	NVIC_InitTypeString.NVIC_IRQChannelSubPriority=0;//子优先级为0
	NVIC_Init(&NVIC_InitTypeString);   //初始化NVIC

	TIM_Cmd(TIM5,ENABLE); //使能定时器5
	

	
}



void TIM5_IRQHandler(void)  //定时器5中断函数
{
	if(TIM_GetITStatus(TIM5,TIM_IT_CC1)==SET)  //检查是否发生中断
	{
		
		encoder_number++;  //编码器计数器自加1
		TIM_ClearITPendingBit(TIM5,TIM_IT_CC1); //清零中断标志位
	}
}






