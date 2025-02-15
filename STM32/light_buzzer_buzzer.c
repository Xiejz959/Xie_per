#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//结构体定义放在时钟前
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_ON(void)//点亮1口的灯
{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void Buzzer_OFF(void)//灭1口的灯
{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
}

void Buzzer_Turn(void)//反转1口灯的状态，达到按一下亮，按一下灭的效果
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
}
