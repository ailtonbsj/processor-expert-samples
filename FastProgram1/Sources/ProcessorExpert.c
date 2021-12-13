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
#include "Analog1.h"
#include "AdcLdd1.h"
#include "TracaoA1PWM.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "TracaoB2.h"
#include "BitIoLdd5.h"
#include "TracaoEnable.h"
#include "BitIoLdd6.h"
#include "Servo1.h"
#include "PwmLdd2.h"
#include "TU3.h"
#include "SW1.h"
#include "BitIoLdd7.h"
#include "SW2.h"
#include "BitIoLdd9.h"
#include "SW3.h"
#include "BitIoLdd10.h"
#include "SW4.h"
#include "BitIoLdd11.h"
#include "LED1.h"
#include "BitIoLdd8.h"
#include "TU4.h"
#include "LED2.h"
#include "BitIoLdd4.h"
#include "LED3.h"
#include "BitIoLdd12.h"
#include "LED4.h"
#include "BitIoLdd13.h"
#include "Serial1.h"
#include "ASerialLdd1.h"
#include "TracaoA2.h"
#include "BitIoLdd3.h"
#include "TracaoB1PWM.h"
#include "PwmLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
byte cameraClock = 0;
byte cameraCont = 0;
byte cameraFinished = 0;
unsigned short int linhaBruta[128];
uint8 maiorAmostra = 0;
uint8 menorAmostra = 255;

uint8 linha[100];
//18200 - 18500 - 18800
#define CENTRO_SERVO 18500
#define LIDERDADE_SERVO 270
#define ESQUERDA_SERVO (CENTRO_SERVO-LIDERDADE_SERVO)
#define DIREITO_SERVO (CENTRO_SERVO+LIDERDADE_SERVO)

int acenderLeds(uint8 num) {
	if (num & 1)
		LED1_PutVal(TRUE);
	else
		LED1_PutVal(FALSE);
	if (num & 2)
		LED2_PutVal(TRUE);
	else
		LED2_PutVal(FALSE);
	if (num & 4)
		LED3_PutVal(TRUE);
	else
		LED3_PutVal(FALSE);
	if (num & 8)
		LED4_PutVal(TRUE);
	else
		LED4_PutVal(FALSE);
	return 0;
}

int rangeLeds(int8 valor, int8 min, int8 max) {
	int8 a = (int8) (((float) 4 / (max - min)) * (valor - min));
	switch (a) {
	case 0:
		acenderLeds(0);
		break;
	case 1:
		acenderLeds(1);
		break;
	case 2:
		acenderLeds(3);
		break;
	case 3:
		acenderLeds(7);
		break;
	case 4:
		acenderLeds(15);
		break;
	}
	return 0;
}

int captaValueSwitch() {
	int saida = 0;
	if (SW1_GetVal()) {
		saida = saida | 1;
	}
	if (SW2_GetVal()) {
		saida = saida | 2;
	}
	if (SW3_GetVal()) {
		saida = saida | 4;
	}
	if (SW4_GetVal()) {
		saida = saida | 8;
	}
	return saida;
}

void setServo(int16 giro) {
	if (giro < ESQUERDA_SERVO) {
		giro = ESQUERDA_SERVO;
	}
	if (giro > DIREITO_SERVO) {
		giro = DIREITO_SERVO;
	}
	Servo1_SetDutyUS(giro);
}

void setTracao(int16 motor1, int16 motor2){
	if(motor1 <= 0) motor1 = 1;
	if(motor1 >= 1000) motor1 = 999;
	if(motor2 <= 0) motor2 = 1;
	if(motor2 >= 1000) motor2 = 999;
	TracaoA1PWM_SetDutyUS(motor1);
	TracaoB1PWM_SetDutyUS(motor2);
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	//## VARIAVEIS
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	Analog1_Start();
	TracaoEnable_PutVal(1);
	TracaoA1PWM_SetDutyUS(1000);
	TracaoB1PWM_SetDutyUS(1000);
	TracaoA2_PutVal(0);
	TracaoB2_PutVal(0);

	while (TRUE) {
		if (cameraFinished == 1) {
			cameraFinished = 0;
			
			setServo(CENTRO_SERVO);
			setTracao(1000,1000);
			
			maiorAmostra = 0;
			menorAmostra = 255;
			Analog1_Enable();
			Analog1_Start();
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
