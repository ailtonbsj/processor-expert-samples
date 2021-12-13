/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BitIoLdd12.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitIO_LDD
**     Version     : Component 01.033, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-25, 10:58, # CodeGen: 107
**     Abstract    :
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : BitIoLdd12
**          Pin for I/O                                    : PTB10/SPI1_PCS0
**          Pin signal                                     : 
**          Direction                                      : Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 0
**            Auto initialization                          : yes
**          Safe mode                                      : yes
**     Contents    :
**         Init   - LDD_TDeviceData* BitIoLdd12_Init(LDD_TUserData *UserDataPtr);
**         GetVal - bool BitIoLdd12_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void BitIoLdd12_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);
**         ClrVal - void BitIoLdd12_ClrVal(LDD_TDeviceData *DeviceDataPtr);
**         SetVal - void BitIoLdd12_SetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file BitIoLdd12.h
** @version 01.00
** @brief
**         The HAL BitIO component provides a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL BitIO API are simpler and more
**         portable to various microprocessors.
*/         
/*!
**  @addtogroup BitIoLdd12_module BitIoLdd12 module documentation
**  @{
*/         

#ifndef __BitIoLdd12_H
#define __BitIoLdd12_H

/* MODULE BitIoLdd12. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 



/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define BitIoLdd12_PRPH_BASE_ADDRESS  0x400FF040U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define BitIoLdd12_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_BitIoLdd12_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define BitIoLdd12_Init_METHOD_ENABLED /*!< Init method of the component BitIoLdd12 is enabled (generated) */
#define BitIoLdd12_GetVal_METHOD_ENABLED /*!< GetVal method of the component BitIoLdd12 is enabled (generated) */
#define BitIoLdd12_PutVal_METHOD_ENABLED /*!< PutVal method of the component BitIoLdd12 is enabled (generated) */
#define BitIoLdd12_ClrVal_METHOD_ENABLED /*!< ClrVal method of the component BitIoLdd12 is enabled (generated) */
#define BitIoLdd12_SetVal_METHOD_ENABLED /*!< SetVal method of the component BitIoLdd12 is enabled (generated) */

/* Definition of implementation constants */
#define BitIoLdd12_MODULE_BASE_ADDRESS FPTB_BASE_PTR /*!< Name of macro used as the base address */
#define BitIoLdd12_PORTCONTROL_BASE_ADDRESS PORTB_BASE_PTR /*!< Name of macro used as the base address */
#define BitIoLdd12_PORT_MASK 0x0400U   /*!< Mask of the allocated pin from the port */



/*
** ===================================================================
**     Method      :  BitIoLdd12_Init (component BitIO_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* BitIoLdd12_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  BitIoLdd12_GetVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Returns the input/output value. If the direction is [input]
**         then the input value of the pin is read and returned. If the
**         direction is [output] then the last written value is read
**         and returned (see <Safe mode> property for limitations).
**         This method cannot be disabled if direction is [input].
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Input or output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
*/
/* ===================================================================*/
bool BitIoLdd12_GetVal(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  BitIoLdd12_PutVal (component BitIO_LDD)
*/
/*!
**     @brief
**         The specified output value is set. If the direction is <b>
**         input</b>, the component saves the value to a memory or a
**         register and this value will be written to the pin after
**         switching to the output mode (using <tt>SetDir(TRUE)</tt>;
**         see <a href="BitIOProperties.html#SafeMode">Safe mode</a>
**         property for limitations). If the direction is <b>output</b>,
**         it writes the value to the pin. (Method is available only if
**         the direction = <u><tt>output</tt></u> or <u><tt>
**         input/output</tt></u>).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Val             - Output value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
*/
/* ===================================================================*/
void BitIoLdd12_PutVal(LDD_TDeviceData *DeviceDataPtr, bool Val);

/*
** ===================================================================
**     Method      :  BitIoLdd12_ClrVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Clears (set to zero) the output value. It is equivalent to
**         the [PutVal(FALSE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void BitIoLdd12_ClrVal(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  BitIoLdd12_SetVal (component BitIO_LDD)
*/
/*!
**     @brief
**         Sets (to one) the output value. It is equivalent to the
**         [PutVal(TRUE)]. This method is available only if the
**         direction = _[output]_ or _[input/output]_.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure returned by <Init> method.
*/
/* ===================================================================*/
void BitIoLdd12_SetVal(LDD_TDeviceData *DeviceDataPtr);

/* END BitIoLdd12. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __BitIoLdd12_H */
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
