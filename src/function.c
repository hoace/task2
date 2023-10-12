#include "S32K144_LibGroup4.h"

void changeDutyCycle(void)
{
	extern volatile unsigned char dutyCycleVar;
	FTM0->SC &= ~(3<<3);
	FTM0->CONTROLS[3].CnV = 200*dutyCycleVar;
	FTM0->SC |= (3<<3);
}

void changeFrequency(void)
{
	extern volatile unsigned char frequencyMode;
	FTM0->SC &= ~(3<<3);
	if(frequencyMode)
	{
		FTM0->SC &= ~(7<<0);					// prescale = 1
	}
	else
	{
		FTM0->SC |= (1<<0);						// prescale = 2
	}
	FTM0->CONTROLS[3].CnV = 1000;				// 50% duty cycle
	FTM0->SC |= (3<<3);

}
