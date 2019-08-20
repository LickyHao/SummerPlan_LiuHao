#include"motor_time1.h"
#include"stm32f10x.h"




void tim4_motor_init(void)  //初始化定时器4函数
{
	GPIO_InitTypeDef GPIO_InitTypeString;  //定义GPIO口初始化结构体变量
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeString; //定义定时器初始化结构体变量
	TIM_OCInitTypeDef TIM_OCInitTypeString;  //定义初始化输出比较参数结构体变量
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  //使能定时器4的时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO,ENABLE);  //使能GPIO口的时钟
	
	GPIO_InitTypeString.GPIO_Mode=GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitTypeString.GPIO_Pin=GPIO_Pin_12;  //使能PD12
	GPIO_InitTypeString.GPIO_Speed=GPIO_Speed_50MHz;  //IO口速度为50MHZ
	GPIO_Init(GPIOD,&GPIO_InitTypeString);  //初始化IO口
	
	
	GPIO_PinRemapConfig(GPIO_Remap_TIM4,ENABLE);  //设置重映射
	
	TIM_TimeBaseInitTypeString.TIM_ClockDivision=TIM_CKD_DIV1;  //设置时钟分割
	TIM_TimeBaseInitTypeString.TIM_CounterMode=TIM_CounterMode_Up;  //向上计数模式
	TIM_TimeBaseInitTypeString.TIM_Period=899; //设置自动重装载值
	TIM_TimeBaseInitTypeString.TIM_Prescaler=0; //设置预分频系数
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitTypeString);  //初始化定时器4
	
	TIM_OCInitTypeString.TIM_OCMode=TIM_OCMode_PWM2;    //设置为PWM模式2
	TIM_OCInitTypeString.TIM_OutputState=TIM_OutputState_Enable; //输出时能
	TIM_OCInitTypeString.TIM_OCPolarity=TIM_OCPolarity_High;//输出极性为高
	TIM_OC1Init(TIM4,&TIM_OCInitTypeString); //初始化输出比较参数
	
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable); //使能预装载寄存器
	TIM_Cmd(TIM4,ENABLE); //使能定时器4
}











