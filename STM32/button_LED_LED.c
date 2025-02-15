#include "stm32f10x.h"                  // Device header
/*
初始化LED_Init，开了1,2两个端口，推挽输出模式
*/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//结构体定义放在时钟前
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}

void LED1_ON(void)//点亮1口的灯
{
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED1_OFF(void)//灭1口的灯
{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED1_Turn(void)//反转1口灯的状态，达到按一下亮，按一下灭的效果
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_ON(void)//亮2口的灯
{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void LED2_OFF(void)//灭2口的灯
{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED2_Turn(void)//反转2口灯的状态，达到按一下亮，按一下灭的效果
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}
