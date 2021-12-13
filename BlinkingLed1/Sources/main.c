/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */


void delay(int num){
	int i;
	for (i = 0; i < num; i++) {
	}
}

int main(void)
{
	
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
	
	PORTB_PCR18 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTB_PCR19 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTD_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	
#define RED_LED_LOC (1<<18)
#define GREEN_LED_LOC (1<<19)
#define BLUE_LED_LOC (1<<1)
	
	GPIOB_PDDR |= RED_LED_LOC | GREEN_LED_LOC;
	GPIOD_PDDR |= BLUE_LED_LOC;
	
	for(;;) {	   

		GPIOB_PSOR = RED_LED_LOC;
		delay(1000000);
		GPIOB_PSOR = GREEN_LED_LOC;
		delay(1000000);
		GPIOD_PSOR = BLUE_LED_LOC;
		delay(1000000);
		GPIOB_PCOR = RED_LED_LOC;
		delay(1000000);
		GPIOB_PCOR = GREEN_LED_LOC;
		delay(1000000);
		GPIOD_PCOR = BLUE_LED_LOC;
		delay(1000000);
	}
	
	return 0;
}
