/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Const.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PE_Const
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-25, 10:58, # CodeGen: 107
**     Abstract    :
**         This component "PE_Const" contains internal definitions
**         of the constants.
**     Settings    :
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PE_Const.h
** @version 01.00
** @brief
**         This component "PE_Const" contains internal definitions
**         of the constants.
*/         
/*!
**  @addtogroup PE_Const_module PE_Const module documentation
**  @{
*/         

#ifndef __PE_Const_H
#define __PE_Const_H


/* Reset cause constants */
#define RSTSRC_WAKEUP     0x01U        /*!< LLWU module wakeup reset */
#define RSTSRC_LVD        0x02U        /*!< Low-voltage detect reset */
#define RSTSRC_LOC        0x04U        /*!< Loss-of-clock reset      */
#define RSTSRC_LOL        0x08U        /*!< Loss-of-lock reset     */
#define RSTSRC_COP        0x20U        /*!< Watchdog reset           */
#define RSTSRC_WDOG       0x20U        /*!< Watchdog reset           */
#define RSTSRC_PIN        0x40U        /*!< External pin reset       */
#define RSTSRC_POR        0x80U        /*!< Power-on reset          */
#define RSTSRC_JTAG       0x0100U      /*!< JTAG reset pin          */
#define RSTSRC_LOCKUP     0x0200U      /*!< Core Lock-up reset      */
#define RSTSRC_SW         0x0400U      /*!< Software reset          */
#define RSTSRC_MDM_AP     0x0800U      /*!< Reset caused by host debugger system   */
#define RSTSRC_SACKERR    0x2000U      /*!< Stop Mode Acknowledge Error Reset      */


/* Low voltage interrupt cause constants */
#define LVDSRC_LVD        0x01U        /*!< Low voltage detect       */
#define LVDSRC_LVW        0x02U        /*!< Low-voltage warning      */

#endif /* _PE_Const_H */
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
