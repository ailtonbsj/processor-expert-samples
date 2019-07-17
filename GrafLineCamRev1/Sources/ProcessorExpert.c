/* ###################################################################
 **     Filename    : ProcessorExpert.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-08-23, 13:26, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file ProcessorExpert.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
 **  @{
 */
/* MODULE ProcessorExpert */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Clock1.h"
#include "BitIoLdd1.h"
#include "SI1.h"
#include "BitIoLdd2.h"
#include "AO1.h"
#include "AdcLdd1.h"
#include "USART1.h"
#include "ASerialLdd1.h"
#include "TimerInt1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include <extras/extras_stdlib.h>

/* VARIAVEIS GLOBAIS INICIO */
byte clockCam = 0;
byte contClock = 0;
byte idleCam = 0;
unsigned long amostra = 0;
unsigned long linhaBruta[128];
unsigned long maiorValorAmostra = 0;
unsigned long limiar;
unsigned short linhaLimiada[128];

char asciiValor[7];
/* VARIAVEIS GLOBAIS FIM */

void delay() {
	//int delay = 0;
	int delay1 = 0;
	//for (delay = 0; delay < 255; delay++) {
	for (delay1 = 0; delay1 < 3; delay1++) {
	}
	//}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	int cont = 0;
	int aux = 0;
	for (cont = 0; cont < 128; cont++) {
		linhaBruta[cont] = 0;
	}

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */
	AO1_Start();
	while (TRUE) {
		/*
		 limiar = 6759.9; //9657
		 for(cont=0;cont<128;cont++)
		 {
		 if(linhaBruta[cont]>=limiar) linhaLimiada[cont] = 1;
		 else linhaLimiada[cont] = 0;
		 }
		 */
		for (cont = 0; cont < 128; cont++) {
			for (aux = 0; aux < 7; aux++) {
				asciiValor[aux] = '\0';
			} //limpa
			itoa(linhaBruta[cont], asciiValor, 10);
			for (aux = 0; asciiValor[aux] != '\0' && aux<7; aux++) {
				USART1_SendChar(asciiValor[aux]);
				delay();
			}
			/*USART1_SendChar('\n');
			delay();*/
			USART1_SendChar('\r');
			delay();
		}

		USART1_SendChar('X');
		delay();
		/*USART1_SendChar('\n');
		delay();*/
		USART1_SendChar('\r');
		delay();
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.2 [05.07]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
