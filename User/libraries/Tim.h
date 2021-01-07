#ifndef __TIM_H
#define	__TIM_H

#include "stm32f10x.h"

#define		TIM_A          	              TIM2
#define		TIM_A_IRQn                    TIM2_IRQn
#define		TIM_A_CLK                     RCC_APB1Periph_TIM2
#define	    TIM_A_Period		          (20000-1)
#define	    TIM_A_Prescaler	              (72-1)

#define		TIM_B          	              TIM3
#define		TIM_B_IRQn                    TIM3_IRQn
#define		TIM_B_CLK                     RCC_APB1Periph_TIM3
#define	    TIM_B_Period		          (20000-1)
#define	    TIM_B_Prescaler	              (72-1)

#define		TIM_C           	          TIM12
#define		TIM_C_IRQn                    TIM8_BRK_TIM12_IRQn
#define		TIM_C_CLK                     RCC_APB1Periph_TIM12
#define	    TIM_C_Period		          (20000-1)
#define	    TIM_C_Prescaler	              (72-1)


#define     TIM_A_PORT                    GPIOA
#define     TIM_B_PORT                    GPIOB
#define     TIM_C_PORT                    GPIOB
#define     TIM_A_GPIO_CLK                RCC_APB2Periph_GPIOA
#define     TIM_B_GPIO_CLK                RCC_APB2Periph_GPIOB
#define     TIM_C_GPIO_CLK                RCC_APB2Periph_GPIOB

void GeneralTim_Init(void);


#endif
