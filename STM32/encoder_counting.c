#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"
#include "Encoder.h"

int16_t NUM;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	
	OLED_ShowString(1,1,"Num:");
	
	
	while(1)
	{
		NUM +=Encoder_Get();
		OLED_ShowSignedNum(1,5,NUM,5);
	}
}
