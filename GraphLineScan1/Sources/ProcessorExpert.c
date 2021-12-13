/* ###################################################################
 **     Filename    : ProcessorExpert.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-09-18, 19:23, # CodeGen: 0
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
#include "CameraClock1.h"
#include "BitIoLdd1.h"
#include "CameraSI1.h"
#include "BitIoLdd2.h"
#include "CameraTimer1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "Analog1.h"
#include "AdcLdd1.h"
#include "TU2.h"
#include "TU3.h"
#include "TU4.h"
#include "Serial1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include <extras/extras_stdlib.h>

/* Modulo Camera */
byte cameraClock = 0;
byte cameraCont = 0;
byte cameraFinished = 0; //flag
unsigned long linhaBruta[128];
unsigned long linha[93];
unsigned long maiorAmostra = 0;
unsigned long menorAmostra = 65535;

/* Modulo Servo */
unsigned long tempoDuty = 18700;
short detectLine = 0;
short numLine = 0; //Quatidade de linha encontradas
short widLine = 0; //Tamanho da linha

/* Modulo Controle */
int TracaoCurveMenor = 12000;
int TracaoCurveMaior = 12000;
int TracaoReta = 12000;
short divisao = 4;
short limiador = 2;
long cortador = 0;

void delayUp(unsigned long num) {
	unsigned long a = 0;
	for (a = 0; a < num; a++) {
	}
}

void sendStringSerial(signed long value, unsigned long t_num) {
	char asciiValor[9];
	int aux = 0;
	for (aux = 0; aux < 9; aux++) {
		asciiValor[aux] = '\0';
	} //limpa
	itoa(value, asciiValor, 10);
	for (aux = 0; asciiValor[aux] != '\0' && aux < 9; aux++) {
		Serial1_SendChar(asciiValor[aux]);
		delayUp(t_num);
	}

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	int i = 0;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	/* Modulo de Acionamento de Componentes */
	Analog1_Start();
	while (TRUE) {
		/*int cont;*/

		/* Modulo Camera */
		if (cameraFinished == 1) {
			cameraFinished = 0;

			for (i = 0; i < 128; i++) {
				sendStringSerial(linhaBruta[i], 1800);
				Serial1_SendChar('\r');
				delayUp(1800);
			}
			Serial1_SendChar('X');
			delayUp(1800);
			Serial1_SendChar('\r');
			delayUp(1800);
			for (i = 0; i < 128; i++) {
				linhaBruta[i] = 0;
			}
			maiorAmostra = 0;
			menorAmostra = 65535;
			Analog1_Enable();
			Analog1_Start();
			CameraTimer1_Enable();
		}

	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
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
