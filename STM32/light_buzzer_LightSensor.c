#include "stm32f10x.h"                  // Device header

void Lightsensor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//结构体定义放在时钟前
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

uint8_t Lightsensor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
}
