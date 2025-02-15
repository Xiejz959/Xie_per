#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include <Buzzer.h>
#include <Lightsensor.h>


int main(void)
{
	Buzzer_Init();
	Lightsensor_Init();
	
	while(1)
	{
		if(Lightsensor_Get()==1)
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
	}
}
