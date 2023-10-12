#include "S32K144_LibGroup4.h"

void PORT_init(void)
{
	PCC_PortC |= (1<<30);	//Enable Clock for Port C
	PCC_PortD |= (1<<30);	//Enable Clock for Port D

	PortC->PCR[12] |= (1<<4) | (1<<8) | (9<<16);	// Set Pin 12 Port C as GPIO, Enable Passive Filter, Interrupt rising edge
	PortC->PCR[13] |= (1<<4) | (1<<8) | (11<<16) ;	// Set Pin 13 Port C as GPIO, Enable Passive Filter, Interrupt both edge

	PortC->PCR[6]  |= (2<<8);		//RX UART1
	PortC->PCR[7]  |= (2<<8);		//TX UART1

	PortD->PCR[3]  |= (1<<4) | (1<<8) | (10<<16);			// Set Pin 4 Port D as GPIO
	PortD->PCR[3]  |= (1<<1);			// Enable pull-up, pull-down
	PortD->PCR[3]  |= (1<<0);			// Select pull-up
	PortD->PCR[15] |= (1<<8);			// Set Pin 15 Port D as GPIO
	PortD->PCR[16] |= (1<<8);			// Set Pin 16 Port D as GPIO
	PortD->PCR[14] |= 0x700;				// Set Pin 14 Port D as CLKOUT

	GPIO_C->PDDR &= ~(1<<12);		// Set Pin 12 Port C as Input
	GPIO_C->PDDR &= ~(1<<13);		// Set Pin 13 Port C as Input
	GPIO_D->PDDR &= ~(1<<3);

	GPIO_D->PDDR |= (1<<0) | (1<<15) | (1<<16);		// Set Pin 0|Pin 15|Pin 16 Port D as Output

	GPIO_D->PSOR |= (1<<0) | (1<<16);		// Set logic 1 for Pin 0|Pin 15|Pin 16 Port D (LED Off)
}
