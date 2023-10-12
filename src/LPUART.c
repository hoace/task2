#include "S32K144_LibGroup4.h"

void LPUART1_init(void)
{
	PCC_UART1 |= (1<<24);			//Choose SOSC source
	PCC_UART1 |= (1<<30);			//Enable clock

	LPUART1->BAUD |= (15<<24)		// Choose Oversampling ratio of 16.
				  |  (52<<0); 		//Choose Baud Rate Modulo Divisor.

	LPUART1->CTRL |= (3<<18);		//Enable TX, RX, M = 0 (8bit data)
}

void LPUART1_transmit(char send) {

	while(!(LPUART1->STAT & (1<<23)));
	/* Wait for transmit buffer to be empty */
	LPUART1->DATA=send;				// Send data //
}

