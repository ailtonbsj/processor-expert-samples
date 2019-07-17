/* ###################################################################
 **     Filename    : Events.c
 **     Project     : ProcessorExpert
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-08-11, 15:12, # CodeGen: 0
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
extern unsigned int clockAtual;
extern unsigned int habilitaContagem;
extern unsigned int contagemAtual;
extern unsigned int pulsoSI;

unsigned int auxPulsoSI = 0; //auxiliar para logica de pulso SI

/*PARTE DE CONVERSAO
 #include <extras/extras_stdlib.h>

 extern unsigned int EvnCnt;
 extern byte Values[3];
 extern char Valuechar[7];
 */

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
	/* Write your code here ... 
	 int ConvFinal = 0;
	 int8 *p1 = 0;
	 char *letra = 0;
	 int aux = 0;
	 EvnCnt++;
	 AO1_GetValue((byte *) Values);
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
	 */
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

/*
 ** ===================================================================
 **     Event       :  ClockTimer1_OnInterrupt (module Events)
 **
 **     Component   :  ClockTimer1 [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void ClockTimer1_OnInterrupt(void) {
	/* Write your code here ... */
	ClockOut1_NegVal(); //gerado clock para a saida
	clockAtual = ClockOut1_GetVal(); //captura estado atual do clock

	if (clockAtual == 1 && habilitaContagem == 1) { //conta os clocks quando habilitado e automaticamente desabilita do 129 clock
		contagemAtual++;
		if (contagemAtual == 129) {
			habilitaContagem = 0;
			contagemAtual = 0;
		}
	}

	if (pulsoSI == 1) {      //Gera o pulso SI para sincronia da camera
		if (clockAtual == 0) {
			SI1_PutVal(1);
			auxPulsoSI = 1;
		} else if (clockAtual == 1 && auxPulsoSI == 1) {
			SI1_PutVal(0);
			auxPulsoSI = 0;
			pulsoSI = 0;
		}
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
