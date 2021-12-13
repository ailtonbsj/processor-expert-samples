/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Analog1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ADC
**     Version     : Component 01.685, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-25, 14:43, # CodeGen: 108
**     Abstract    :
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : Analog1
**          A/D converter                                  : ADC0
**          Sharing                                        : Disabled
**          Interrupt service/event                        : Enabled
**            A/D interrupt                                : INT_ADC0
**            A/D interrupt priority                       : medium priority
**          A/D channels                                   : 1
**            Channel0                                     : 
**              A/D channel (pin)                          : ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5
**              A/D channel (pin) signal                   : 
**              Mode select                                : Single Ended
**          A/D resolution                                 : Autoselect
**          Conversion time                                : 9.615385 �s
**          Low-power mode                                 : Disabled
**          High-speed conversion mode                     : Disabled
**          Asynchro clock output                          : Disabled
**          Sample time                                    : 0 = short
**          Internal trigger                               : Disabled
**          Number of conversions                          : 1
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          High input limit                               : 1
**          Low input limit                                : 0
**          Get value directly                             : yes
**          Wait for result                                : yes
**     Contents    :
**         Enable     - byte Analog1_Enable(void);
**         Disable    - byte Analog1_Disable(void);
**         Start      - byte Analog1_Start(void);
**         Stop       - byte Analog1_Stop(void);
**         Measure    - byte Analog1_Measure(bool WaitForResult);
**         GetValue   - byte Analog1_GetValue(void* Values);
**         GetValue8  - byte Analog1_GetValue8(byte *Values);
**         GetValue16 - byte Analog1_GetValue16(word *Values);
**         Calibrate  - byte Analog1_Calibrate(bool WaitForResult);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Analog1.h
** @version 01.00
** @brief
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
*/         
/*!
**  @addtogroup Analog1_module Analog1 module documentation
**  @{
*/         

#ifndef __Analog1_H
#define __Analog1_H

/* MODULE Analog1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "AdcLdd1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* This constant contains the number of channels in the "A/D channel list"
   group */
#define Analog1_CHANNEL_COUNT           AdcLdd1_CHANNEL_COUNT



#define Analog1_SAMPLE_GROUP_SIZE 1U
void Analog1_HWEnDi(void);
/*
** ===================================================================
**     Method      :  Analog1_HWEnDi (component ADC)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

byte Analog1_Enable(void);
/*
** ===================================================================
**     Method      :  Analog1_Enable (component ADC)
**     Description :
**         Enables A/D converter component. <Events> may be generated
**         (<DisableEvent>/<EnableEvent>). If possible, this method
**         switches on A/D converter device, voltage reference, etc.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Analog1_Disable(void);
/*
** ===================================================================
**     Method      :  Analog1_Disable (component ADC)
**     Description :
**         Disables A/D converter component. No <events> will be
**         generated. If possible, this method switches off A/D
**         converter device, voltage reference, etc.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Analog1_Start(void);
/*
** ===================================================================
**     Method      :  Analog1_Start (component ADC)
**     Description :
**         This method starts continuous conversion on all channels
**         that are set in the component inspector. When each
**         measurement on all channels has finished the <OnEnd > event
**         may be invoked. This method is not available if the
**         <interrupt service> is disabled and the device doesn't
**         support the continuous mode. Note: If time of measurement is
**         too short and the instruction clock is too slow then the
**         conversion complete interrupt and its handler may cause a
**         system overflow.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/

byte Analog1_Stop(void);
/*
** ===================================================================
**     Method      :  Analog1_Stop (component ADC)
**     Description :
**         This method stops the continuous measurement or disables
**         a trigger mode (if supported by HW), which has been
**         started by one of the following methods:
**         Version specific information not for Freescale 56800 and
**         HCS08 and HC08 and HCS12 and HCS12X derivatives ] 
**         - <Start> 
**         - EnableInt(Chan)Trigger 
**         - EnableExt(Chan)Trigger
**         The Stop method is available if one of the previously
**         mentioned methods is supported by A/D converter device
**         and is enabled to be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_BUSY - No continuous measurement is
**                           running. Neither internal trigger nor
**                           external trigger have been enabled (if
**                           these are supported by HW).
** ===================================================================
*/

byte Analog1_Measure(bool WaitForResult);
/*
** ===================================================================
**     Method      :  Analog1_Measure (component ADC)
**     Description :
**         This method performs one measurement on all channels that
**         are set in the component inspector. (Note: If the <number of
**         conversions> is more than one the conversion of A/D channels
**         is performed specified number of times.)
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of a
**                           conversion. If <interrupt service> is
**                           disabled, A/D peripheral doesn't support
**                           measuring all channels at once or Autoscan
**                           mode property isn't enabled and at the same
**                           time the <number of channels> is greater
**                           than 1, then the WaitForResult parameter is
**                           ignored and the method waits for each
**                           result every time. If the <interrupt
**                           service> is disabled and a <number of
**                           conversions> is greater than 1, the
**                           parameter is ignored and the method also
**                           waits for each result every time.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/

byte Analog1_GetValue(void* Values);
/*
** ===================================================================
**     Method      :  Analog1_GetValue (component ADC)
**     Description :
**         Returns the last measured values for all channels. Format
**         and width of the value is a native format of the A/D
**         converter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data. Data type is a byte, a
**                           word or an int. It depends on the supported
**                           modes, resolution, etc. of the AD converter.
**                           See the Version specific information for
**                           the current CPU in <General Info>.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/

byte Analog1_GetValue8(byte *Values);
/*
** ===================================================================
**     Method      :  Analog1_GetValue8 (component ADC)
**     Description :
**         This method returns the last measured values of all channels
**         justified to the left. Compared with <GetValue> method this
**         method returns more accurate result if the <number of
**         conversions> is greater than 1 and <AD resolution> is less
**         than 8 bits. In addition, the user code dependency on <AD
**         resolution> is eliminated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/

byte Analog1_GetValue16(word *Values);
/*
** ===================================================================
**     Method      :  Analog1_GetValue16 (component ADC)
**     Description :
**         This method returns the last measured values of all channels
**         justified to the left. Compared with <GetValue> method this
**         method returns more accurate result if the <number of
**         conversions> is greater than 1 and <AD resolution> is less
**         than 16 bits. In addition, the user code dependency on <AD
**         resolution> is eliminated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/

byte Analog1_Calibrate(bool WaitForResult);
/*
** ===================================================================
**     Method      :  Analog1_Calibrate (component ADC)
**     Description :
**         This method starts self calibration process. Calibration is
**         typically used to remove the effects of the gain and offset
**         from a specific reading.
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of
**                           calibration. If the <interrupt service> is
**                           disabled, the WaitForResult parameter is
**                           ignored and the method waits for
**                           calibration result every time.
**     Returns     :
**         ---             - Error code
**                           ERR_OK - OK
**                           ERR_BUSY - A conversion is already running
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_FAILED - Calibration hasn't been
**                           finished correctly
** ===================================================================
*/

void AdcLdd1_OnMeasurementComplete(LDD_TUserData *UserDataPtr);

void Analog1_Init(void);
/*
** ===================================================================
**     Method      :  Analog1_Init (component ADC)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Analog1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __Analog1_H */
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
