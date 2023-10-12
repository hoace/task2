#include "S32K144_LibGroup4.h"

void SOSC_init(void)
{
	SCG->SOSCDIV |= (1<<0) | (1<<8);			// SOSCDIV1 & SOSCDIV2 =1: divide by 1
	SCG->SOSCCFG |= (3<<4) | (1<<2);			// High freq
												// External clock

	while(SCG->SOSCCSR & (1<<23));				// Ensure SOSCCSR unlocked //
	SCG->SOSCCSR |= (1<<0);						// Enable oscillator //
}
