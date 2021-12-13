/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "mcg.h"

#define RED_LED_LOC (1<<18)
#define GREEN_LED_LOC (1<<19)
#define BLUE_LED_LOC (1<<1)

#define TIME 1000000

void wait(int value){
	int i;
	for(i = 0; i < value; i++){
	}
}

int main(void) {
	
	//Habilita Core Clock para 48MHz com cristal de 8MHz
	pll_init(8000000, LOW_POWER, CRYSTAL, 4, 24, MCGOUT);
	
	//Habilita o clock nas portas
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
	
	//Multiplexa pinos para alternativa GPIO
	PORTB_PCR18 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTB_PCR19 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	PORTD_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;
	
	//Seta pinos como saida
	GPIOB_PDDR |= RED_LED_LOC | GREEN_LED_LOC;
	GPIOD_PDDR |= BLUE_LED_LOC;
	
	//Coloca pinos em Nivel Alto
	GPIOB_PSOR = RED_LED_LOC;
	GPIOB_PSOR = GREEN_LED_LOC;
	GPIOD_PSOR = BLUE_LED_LOC;
	
	for(;;){
		//Coloca pino BLUE em Nivel Alto
		GPIOD_PSOR = BLUE_LED_LOC;
		wait(TIME);

		//Coloca pino BLUE em Nivel Baixo
		GPIOD_PCOR = BLUE_LED_LOC;
		wait(TIME);
	}
	
	return 0;
}
