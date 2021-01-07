#include "Tim.h"

static void TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef    NVIC_InitStruct;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    NVIC_InitStruct.NVIC_IRQChannel = TIM_A_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = TIM_B_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
    NVIC_Init(&NVIC_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = TIM_C_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 12;
    NVIC_Init(&NVIC_InitStruct);

}

static void TIM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;    
    RCC_APB2PeriphClockCmd(TIM_A_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(TIM_B_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(TIM_C_GPIO_CLK, ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_A_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_A_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_A_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_A_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_A_PORT, &GPIO_InitStruct);  

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_B_PORT, &GPIO_InitStruct);    

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_B_PORT, &GPIO_InitStruct); 

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TIM_C_PORT, &GPIO_InitStruct);                	
}


static void TIM_Mode_Config(void)
{
    RCC_APB1PeriphClockCmd(TIM_A_CLK,ENABLE);
    RCC_APB1PeriphClockCmd(TIM_B_CLK,ENABLE);
    RCC_APB1PeriphClockCmd(TIM_C_CLK,ENABLE);

/*--------------------时基结构体初始化-------------------------*/	
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStruct;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStruct.TIM_Period=TIM_A_Period;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStruct.TIM_Prescaler= TIM_A_Prescaler;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStruct.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStruct.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStruct.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(TIM_A, &TIM_TimeBaseStruct);

	TIM_TimeBaseStruct.TIM_Period=TIM_B_Period;	
	TIM_TimeBaseStruct.TIM_Prescaler= TIM_B_Prescaler;	
	TIM_TimeBaseStruct.TIM_ClockDivision=TIM_CKD_DIV1;		
	TIM_TimeBaseStruct.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStruct.TIM_RepetitionCounter=0;	
	TIM_TimeBaseInit(TIM_B, &TIM_TimeBaseStruct);


	TIM_TimeBaseStruct.TIM_Period=TIM_C_Period;	
	TIM_TimeBaseStruct.TIM_Prescaler= TIM_C_Prescaler;	
	TIM_TimeBaseStruct.TIM_ClockDivision=TIM_CKD_DIV1;		
	TIM_TimeBaseStruct.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStruct.TIM_RepetitionCounter=0;	
	TIM_TimeBaseInit(TIM_C, &TIM_TimeBaseStruct);

/*------------输出比较结构体初始化---------------*/
    TIM_OCInitTypeDef   TIM_OCInitStruct;
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC2Init(TIM_A,&TIM_OCInitStruct);
    TIM_OC2PreloadConfig(TIM_A,TIM_OCPreload_Enable);    //使能输出比较预装载

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC3Init(TIM_A,&TIM_OCInitStruct);
    TIM_OC3PreloadConfig(TIM_A,TIM_OCPreload_Enable);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC4Init(TIM_A,&TIM_OCInitStruct);
    TIM_OC4PreloadConfig(TIM_A,TIM_OCPreload_Enable);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC1Init(TIM_B,&TIM_OCInitStruct);
    TIM_OC1PreloadConfig(TIM_B,TIM_OCPreload_Enable);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC2Init(TIM_B,&TIM_OCInitStruct);
    TIM_OC2PreloadConfig(TIM_B,TIM_OCPreload_Enable);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC3Init(TIM_B,&TIM_OCInitStruct);
    TIM_OC3PreloadConfig(TIM_B,TIM_OCPreload_Enable);    

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC4Init(TIM_B,&TIM_OCInitStruct);
    TIM_OC4PreloadConfig(TIM_B,TIM_OCPreload_Enable);    

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_Pulse = 1500;//比较值  
    TIM_OC2Init(TIM_C,&TIM_OCInitStruct);
    TIM_OC2PreloadConfig(TIM_C,TIM_OCPreload_Enable);    

    TIM_ClearFlag(TIM_A, TIM_FLAG_Update);
    TIM_ClearFlag(TIM_B, TIM_FLAG_Update);
    TIM_ClearFlag(TIM_C, TIM_FLAG_Update);

    TIM_ITConfig(TIM_A, TIM_IT_Update,ENABLE);
    TIM_ITConfig(TIM_B, TIM_IT_Update,ENABLE);
    TIM_ITConfig(TIM_C, TIM_IT_Update,ENABLE);
    
    TIM_Cmd(TIM_A, ENABLE);   
    TIM_Cmd(TIM_B, ENABLE);    
    TIM_Cmd(TIM_C, ENABLE);
}

void GeneralTim_Init(void)
{
    TIM_NVIC_Config();
    TIM_GPIO_Config();
    TIM_Mode_Config();
}


