/* ###################################################################
 **     Filename    : Events.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-08-10, 17:27, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <extras/extras_stdlib.h>

extern unsigned int EvnCnt;
extern byte Values[3];
extern char Valuechar[7];
double dutyPwm1=1;

/*
 ** ===================================================================
 **     Event       :  Cpu_OnNMIINT (module Events)
 **
 **     Component   :  Cpu [MKL25Z128LK4]
 **     Description :
 **         This event is called when the Non maskable interrupt had
 **         occurred. This event is automatically enabled when the <NMI
 **         interrupt> property is set to 'Enabled'.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void Cpu_OnNMIINT(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  AD1_OnEnd (module Events)
 **
 **     Component   :  AD1 [ADC]
 **     Description :
 **         This event is called after the measurement (which consists
 **         of <1 or more conversions>) is/are finished.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AD1_OnEnd(void) {
	/* Write your code here ... */
	int ConvFinal = 0;
	int8 *p1 = 0;
	char *letra = 0;
	int aux = 0;
	EvnCnt++;
	AD1_GetValue((byte *) Values);
	ConvFinal = 0;
	letra = Valuechar;
	while (aux <= 6) {
		*(letra + aux) = 0;
		aux++;
		if(aux==6) *(letra + aux)='\0';
	}
	p1 = &ConvFinal;
	*p1 = Values[0];
	*(p1 + 1) = Values[1];
	*(p1 + 2) = Values[2];

	ltoa(ConvFinal, Valuechar, 10);
	if(ConvFinal>35000) ConvFinal = 35000;
	//Servo1_SetRatio16(ConvFinal);
	//Servo1_SetDutyMS((double)((ConvFinal/35000)+18));
	Servo1_SetDutyUS((word)(20000-((ConvFinal/35)+1000)));
}

/*
 ** ===================================================================
 **     Event       :  AD1_OnCalibrationEnd (module Events)
 **
 **     Component   :  AD1 [ADC]
 **     Description :
 **         This event is called when the calibration has been finished.
 **         User should check if the calibration pass or fail by
 **         Calibration status method./nThis event is enabled only if
 **         the <Interrupt service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AD1_OnCalibrationEnd(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  TI1_OnInterrupt (module Events)
 **
 **     Component   :  TI1 [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void TI1_OnInterrupt(void) {
	char mensagem[] = "\n\rValor: ";
	int cont = 0;
	while (mensagem[cont] != '\0') {
		delay();
		Serial1_SendChar(mensagem[cont]);
		cont++;
	}
	cont = 0;
	while (Valuechar[cont] != '\0') {
			delay();
			Serial1_SendChar(Valuechar[cont]);
			cont++;
		}
}

/* END Events */

#ifdef __cplusplus
} /* extern "C" */
#endif 

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
