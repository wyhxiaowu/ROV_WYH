#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PORT    	GPIOD			            /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED1_GPIO_PIN		GPIO_Pin_12			        /* 连接到SCL时钟线的GPIO */

#define LED2_GPIO_PORT    	GPIOD			            /* GPIO端口 */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED2_GPIO_PIN		GPIO_Pin_13			        /* 连接到SCL时钟线的GPIO */

#define LED3_GPIO_PORT    	GPIOD			            /* GPIO端口 */
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED3_GPIO_PIN		GPIO_Pin_14		            /* 连接到SCL时钟线的GPIO */

#define ON   1
#define OFF  0

#define LED1(a)    if(a) GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
				    else  GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
#define LED2(a)    if(a) GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
				    else  GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
#define LED3(a)    if(a) GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
				    else  GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);


#define LED1_TOGGLE   {LED1_GPIO_PORT->ODR ^= LED1_GPIO_PIN;} 
#define LED2_TOGGLE   {LED2_GPIO_PORT->ODR ^= LED2_GPIO_PIN;} 
#define LED3_TOGGLE   {LED3_GPIO_PORT->ODR ^= LED3_GPIO_PIN;} 

void LED_Init_Config(void);

#endif
