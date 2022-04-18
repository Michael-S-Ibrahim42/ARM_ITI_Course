/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 12, 2022
**       Version     :	V01
**       SWC         :	USART_C
**       Description :	USART Control module
** **************************************************************************************/
#ifndef _USART_C_H
#define _USART_C_H
  /* /////////////////////////////////// Headers inclusion /////////////////////////////////////////////////////////////////// */
  /* Configurations header */
  #include "USART_C_cfg.h"
  /* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////////////// Defined Types //////////////////////////////////////////////////////////////////////// */
  /* Error type */
  typedef enum
  {
    USART_C_enuOk,
    USART_C_enuNok,
    USART_C_enuBusy
  }USART_C_tenuError;
  /* USART Specs structure */
  typedef struct  
  {
    u8          BusNumber;/* options are in "USART.h" under "Used USARTs" */
    u8          BusStatus;/* Options are in "USART_C.h" under "Bus status" */
    tstrBuffer* USART_C_pstrBuffer;
    tpfCallback USART_C_pfCallbackFn;
  }USART_C_tstrBus;
  /* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
  /* //////////////////////////////////////////////// MACROS ///////////////////////////////////////////////////////////////// */
  /* Bus status */
  #define USART_C_BUS_AVAILABLE                                                 0
  #define USART_C_BUS_BUSY                                                      1
  /* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////////////// Interface Fns //////////////////////////////////////////////////////////////////////// */
  /* 
    Description         :     start sending buffer on the USART with no copy
    Parameter1          :     The bus no, options are in "USART_C_cfg.h" under "USART modules"
    Parameter2          :     the Buffer first byte address
    Return              :     Error status of type "USART_C_tenuError", defined in "USART_C.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_C_tenuError USART_enuSendBufferZeroCopy(u8 Copy_u8BusID, tstrBuffer* Copy_pstrBuffer);  
  /* 
    Description         :     Send other buffer bytes on the USART with no copy
    Parameter(s)        :     void
    Return              :     void
    **Caution**         :     It must be registered as "USART" call back fn 
    ////////////////////// Synchronous //////////////////////
  */
  void USART_enuSendBufferCallbackFn(void);
  /* 
    Description         :     Register the Buffer complete sending callback fn
    Parameter1          :     The Bus ID, options are in "USART_C_cfg.h" under "USART modules"
    Parameter2          :     Address of the callback fn
    Return              :     Error status of type "USART_C_tenuError", defined in "USART_C.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_C_tenuError USART_enuRegBufferTransCallbackFn(u8 Copy_u8BusID, tpfCallback Copy_pfCallbackFn);
  /* //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
#endif