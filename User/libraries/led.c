#include "led.h"

void LED_Init_Config(void)
{
	GPIO_InitTypeDef    GPIO_InitTypeStruct;
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK,ENABLE);
	
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitTypeStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_Init(LED1_GPIO_PORT,&GPIO_InitTypeStruct);
	
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitTypeStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT,&GPIO_InitTypeStruct);

	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitTypeStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_Init(LED3_GPIO_PORT,&GPIO_InitTypeStruct);

	GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
    GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
    GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);
}

