/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-08-16, 14:05, # CodeGen: 0
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

/* VARIAVEIS GLOBAIS INICO */

extern byte vetorConversao[3];
extern byte contClock;
extern unsigned long amostraAnag;
extern unsigned long int contTotalAmostra;
extern unsigned long linhaBrutaCam[150];

unsigned long int ultimaAmostra = 0;

/* VARIAVEIS GLOBAIS FIM */


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
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
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
void AO1_OnEnd(void)
{
  /* Write your code here ... */
	int8 *p1 = 0;
	if(contClock>=0 && contClock<=128) 
	{
		AO1_GetValue(&amostraAnag);
		/*
		AO1_GetValue((byte *) vetorConversao);
		p1 = &amostraAnag;
		*p1 = vetorConversao[0];
		*(p1 + 1) = vetorConversao[1];
		*(p1 + 2) = vetorConversao[2];*/
		if(contTotalAmostra <= 299)
		linhaBrutaCam[contTotalAmostra] = amostraAnag;
		/* CONTAR TOTAL DE AMOSTRAGEM */ 
		contTotalAmostra++;
		if(contClock==128){
			if(contTotalAmostra > ultimaAmostra) ultimaAmostra = contTotalAmostra;
			contTotalAmostra=0;
		}
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
void AO1_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
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
