#include "S32K144_LibGroup4.h"


void FTM0_init(void)
{
	/* Select clock SOSCDIV1_CLK for FTM0 */
	PCC_FTM0 |= (1<<24);
	/* Enable clock for FTM0 */
	PCC_FTM0 |= (1<<30);
	/* Set PORTD pins for FTM0 */
	PortD->PCR[1] |= (2<<8);				// FTM0, Channel3
	/* Enable registers updating from write buffers */
	FTM0->MODE |= (1<<0);
	/* Set Modulo in initialization stage */
	FTM0->MOD = (2000-1);						// 4kHz PWM frequency @8MHz SOSCDIV1
	/* Set CNTIN in initialization stage */
	FTM0->CNTIN = 0;
	/* Enable high-true pulses of PWM signals */
	FTM0->CONTROLS[3].CnSC |= (1<<3) | (1<<5);
	FTM0->CONTROLS[3].CnV = 1000;				// 50% duty cycle
	/* Reset FTM counter */
	FTM0->CNT = 0;
	/* Clock selection and enabling PWM generation */
	FTM0->SC |= (1<<0) | (3<<3) | (8<<16);		// prescale = 2
}
