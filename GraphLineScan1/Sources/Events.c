/* ###################################################################
 **     Filename    : Events.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2014-08-19, 17:49, # CodeGen: 0
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

extern uint8 cameraCont;
extern bool cameraClock;
extern volatile bool cameraFinished;
extern volatile uint16_t cameraDados[128];

uint16_t amostra;

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
 **     Event       :  CameraTimer_OnInterrupt (module Events)
 **
 **     Component   :  CameraTimer [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void CameraTimer_OnInterrupt(void) {

	/* Write your code here ... */
	if (cameraCont <= 128) {
		if (cameraClock == 1) {
			if (cameraCont <= 1) {
				CameraSI_PutVal(0);
			}
			CameraAnalog_Measure(TRUE);
			CameraAnalog_GetValue(&amostra);
			cameraDados[cameraCont] = amostra;
			cameraCont++;
		}
		cameraClock = !cameraClock;
	} else {
		cameraClock = 0;
		cameraCont = 0;
		CameraCK_PutVal(cameraClock);
		CameraTimer_Disable();
		CameraAnalog_Disable();
		cameraFinished = 1;
	}
	if (cameraCont == 0 && cameraClock == 0) {
		CameraSI_PutVal(1);
	}
	CameraCK_PutVal(cameraClock);
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
 **     This file was created by Processor Expert 10.2 [05.06]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
