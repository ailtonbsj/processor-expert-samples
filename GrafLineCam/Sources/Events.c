/* ###################################################################
 **     Filename    : Events.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-08-23, 13:26, # CodeGen: 0
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
extern byte clockCam;
extern byte contClock;
extern byte idleCam;
extern unsigned long amostra;
extern unsigned long linhaBruta[128];
extern unsigned long maiorValorAmostra;

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
 **     Event       :  TimerInt1_OnInterrupt (module Events)
 **
 **     Component   :  TimerInt1 [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void TimerInt1_OnInterrupt(void) {
	/* Write your code here ... */
	if (contClock <= 128) {
		if (clockCam == 1) {
			if (contClock <= 1)
				SI1_PutVal(0);
			contClock++;
		}

		clockCam = !clockCam;
	} else {
		clockCam = 0;
		idleCam++;
		if (idleCam >= 6) {
			contClock = 0;
			idleCam = 0;
		}
	}
	if (contClock == 0 && clockCam == 0) {
		SI1_PutVal(1);
	}
	Clock1_PutVal(clockCam);
}

/*
 ** ===================================================================
 **     Event       :  AO1_OnEnd (module Events)
 **
 **     Component   :  AO1 [ADC]
 **     Description :
 **         This event is called after the measurement (which consists
 **         of <1 or more conversions>) is/are finished.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AO1_OnEnd(void) {
	/* Write your code here ... */
	if(contClock >= 0 && contClock <= 128)
		{
			AO1_GetValue(&amostra);
			linhaBruta[contClock] = amostra;
			if(amostra > maiorValorAmostra) maiorValorAmostra = amostra;
					
			/* PRA TESTE - CAPTURA TOTAL DE AMOSTRAS
			if(contClock == 0) contAmostra = 0;
			contAmostra++;
			if(contAmostra >= totalAmostra) totalAmostra = contAmostra;
			if(contClock == 127) contAmostra = 0;
			*/
			
		}
		else
		{
			maiorValorAmostra=0;
		}
}

/*
 ** ===================================================================
 **     Event       :  AO1_OnCalibrationEnd (module Events)
 **
 **     Component   :  AO1 [ADC]
 **     Description :
 **         This event is called when the calibration has been finished.
 **         User should check if the calibration pass or fail by
 **         Calibration status method./nThis event is enabled only if
 **         the <Interrupt service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AO1_OnCalibrationEnd(void) {
	/* Write your code here ... */
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
