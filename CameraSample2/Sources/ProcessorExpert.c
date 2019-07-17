/* ###################################################################
 **     Filename    : ProcessorExpert.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-08-16, 14:05, # CodeGen: 0
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
#include "AO1.h"
#include "AdcLdd1.h"
#include "Clock1.h"
#include "BitIoLdd1.h"
#include "SI1.h"
#include "BitIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/* VARIAVEIS GLOBAIS INICIO */

byte contClock = 0; //conta os 128 clocks
byte contIdle = 0; // conta os 20 us de ociosidade
byte clockAtual = 0; //estado atual do clock

byte vetorConversao[3]; //buffer para conversao analogica
unsigned long amostraAnag = 0; //convesaofinal da amostra
unsigned long int contTotalAmostra; //conta quantas amostra foi capturada
unsigned long linhaBrutaCam[150]; //guarda sinal analogico convertido

/* VARIAVEIS GLOBAIS FIM */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */
	AO1_Start();
	while (TRUE) {
		Clock1_PutVal(clockAtual);
		//envia sinal de clock
		if (contClock <= 129) {
			if (clockAtual == 1)
				contClock++;
			if (contClock == 0 && clockAtual == 0)
				SI1_PutVal(1);
			else
				SI1_PutVal(0);
			clockAtual = !clockAtual; // gera clock
		} else if (contIdle <= 40) { //valor tem que ser o dobro
			contIdle++;
		} else {
			contClock = 0;
			contIdle = 0;
		}
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
