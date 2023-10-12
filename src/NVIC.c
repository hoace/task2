#include "S32K144_LibGroup4.h"

void NVIC_init(void){
	/*Button*/
	NVIC->ICPR[61/32] = 1 << (61 % 32);	//Clear Spending
										//IRQ LPIT1 = 49
	NVIC->ISER[61/32] = 1 << (61 % 32);	//Set Interrupt
	NVIC->IP[61] = 0xB0;  				//priority set 15 = F
	/*Button*/
	NVIC->ICPR[62/32] = 1 << (62 % 32);	//Clear Spending
										//
	NVIC->ISER[62/32] = 1 << (62 % 32);	//Set Interrupt
	NVIC->IP[62] = 0xB0;  				//priority set 15 = F
}
