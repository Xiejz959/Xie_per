#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)//读取按钮的状态
{
	uint8_t KeyNum=0;
	if  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0)//低电平为0，高电平为1
	{
		Delay_ms(20);//按键开始和结尾有一个电压抖动，需要delay去抖
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0);
		Delay_ms(20);
		KeyNum=1;
	}
	if  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==0)//低电平为0，高电平为1
	{
		Delay_ms(20);//按键开始和结尾有一个电压抖动，需要delay去抖
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)==0);
		Delay_ms(20);
		KeyNum=2;
	}
	return KeyNum;
}
