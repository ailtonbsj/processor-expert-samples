/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Serial1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : AsynchroSerial
**     Version     : Component 02.602, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-02, 13:57, # CodeGen: 125
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**         Serial channel              : UART0
**
**         Protocol
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : UART0_D   [0x4006A007]
**             Output buffer           : UART0_D   [0x4006A007]
**
**
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Output  |     28               |  TSI0_CH3/PTA2/UART0_TX/TPM2_CH1
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         SendChar        - byte Serial1_SendChar(Serial1_TComData Chr);
**         GetCharsInTxBuf - word Serial1_GetCharsInTxBuf(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Serial1.h
** @version 01.01
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup Serial1_module Serial1 module documentation
**  @{
*/         

#ifndef __Serial1
#define __Serial1

/* MODULE Serial1. */

/* Include inherited components */
#include "ASerialLdd1.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 



#ifndef __BWUserType_Serial1_TError
#define __BWUserType_Serial1_TError
  typedef union {
  byte err;
  struct {
    bool OverRun  : 1;                 /* Overrun error flag */
    bool Framing  : 1;                 /* Framing error flag */
    bool Parity   : 1;                 /* Parity error flag */
    bool RxBufOvf : 1;                 /* Rx buffer full error flag */
    bool Noise    : 1;                 /* Noise error flag */
    bool Break    : 1;                 /* Break detect */
    bool LINSync  : 1;                 /* LIN synchronization error */
    bool BitError  : 1;                /* Bit error flag - mismatch to the expected value happened. */
  } errName;
} Serial1_TError;                      /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
#endif

#ifndef __BWUserType_Serial1_TComData
#define __BWUserType_Serial1_TComData
  typedef byte Serial1_TComData;       /* User type for communication. Size of this type depends on the communication data witdh */
#endif

/*
** ===================================================================
**     Method      :  Serial1_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte Serial1_SendChar(Serial1_TComData Chr);

/*
** ===================================================================
**     Method      :  Serial1_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word Serial1_GetCharsInTxBuf(void);

/*
** ===================================================================
**     Method      :  Serial1_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Serial1_Init(void);


/* END Serial1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif /* ifndef __Serial1 */
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
