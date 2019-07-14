/* ###################################################################
 **     Filename    : ProcessorExpert.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-09-03, 19:42, # CodeGen: 0
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
#include "PWM1.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "ButtonA.h"
#include "BitIoLdd1.h"
#include "ButtonB.h"
#include "BitIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */

{
	/* Write your local variable definition here */
	unsigned long tempoDuty = 18700; //   17.7ms    18.2ms  18.7ms   19.2ms  19.7ms
	short btA = 0;
	short btB = 0;
	int cont1,cont2;


	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	while (1) {
		// PWM1_SetDutyUS(18920);
		for(cont2=0;cont2<=254;cont2++){
			for(cont1=0;cont1<=154;cont1++){
				
			}
		}
		btA = ButtonA_GetVal();
		btB = ButtonB_GetVal();

		if (btA == 1) {
			tempoDuty += 10;
		}
		if (btB == 1) {
			tempoDuty -= 10;
		}
		btA = 0;
		btB = 0;
		PWM1_SetDutyUS(tempoDuty);
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
