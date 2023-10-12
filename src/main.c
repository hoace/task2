#include "S32K144_LibGroup4.h"

volatile unsigned char dutyCycleVar=5;
volatile unsigned char frequencyMode=0;

int main(void)
{
	SOSC_init();

	NVIC_init();

	PORT_init();

	LPUART1_init();

	FTM0_init();

	for(;;)
	{
		/* Infinite loop */
	}

}


void PORTC_IRQHandler(void)
{
	if(	PortC->PCR[12] & (1<<24)){			//Check flag
		if(dutyCycleVar < 10)
		{
			dutyCycleVar++;
			changeDutyCycle();
			LPUART1_transmit(dutyCycleVar+0x30);
		}
		PortC->PCR[12] |= (1<<24);			//Clear flag
	}
	else if(PortC->PCR[13] & (1<<24)){		//Check flag
		if(dutyCycleVar > 0)
		{
			dutyCycleVar--;
			changeDutyCycle();
			LPUART1_transmit(dutyCycleVar+0x30);
		}
		PortC->PCR[13] |= (1<<24);			// Clear flag
	}
}

void PORTD_IRQHandler(void)
{
	if(PortD->PCR[3] & (1<<24)){		// Check flag
		frequencyMode ^=1;
		changeFrequency();
		LPUART1_transmit(dutyCycleVar+0x30);
		PortD->PCR[3] |= (1<<24);			// Clear flag
	}
}

