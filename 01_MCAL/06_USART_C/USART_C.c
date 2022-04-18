/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 12, 2022
**       Version     :	V01
**       SWC         :	USART_C
**       Description :	USART Control module
** **************************************************************************************/
/* ///////////////////////////////////// Headers inclusion //////////////////////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
#include "STM32F401CC.h"
#include "USART.h"
/* Own headers */
#include "USART_C.h"
#include "USART_C_cfg.h"
#include "USART_C_prv.h"
/* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////// Interface Fns /////////////////////////////////////////////////////// */
/* 
  Description         :     start sending buffer on the USART with no copy
  Parameter1          :     The bus no, options are in "USART_C_cfg.h" under "USART modules"
  Parameter2          :     the Buffer first byte address
  Return              :     Error status of type "USART_C_tenuError", defined in "USART_C.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_C_tenuError USART_enuSendBufferZeroCopy(u8 Copy_u8BusID, tstrBuffer* Copy_pstrBuffer)
{
  USART_C_tenuError Loc_enuError = USART_C_enuOk;
  if(Copy_pstrBuffer != NULL)
  {
    USART_C_astrBuses[Copy_u8BusID].USART_C_pstrBuffer = Copy_pstrBuffer;
    if(USART_C_astrBuses[Copy_u8BusID].BusStatus == USART_C_BUS_AVAILABLE)
    {
      USART_enuRegTxCallbackFn(USART_u8NUM1, USART_enuSendBufferCallbackFn);
      USART_C_astrBuses[Copy_u8BusID].BusStatus = USART_C_BUS_BUSY;
      USART_enuSendByte(USART_C_astrBuses[Copy_u8BusID].BusNumber, USART_C_astrBuses[Copy_u8BusID].USART_C_pstrBuffer->Buffer[USART_C_astrBuses[Copy_u8BusID].USART_C_pstrBuffer->Index]);  
      USART_C_astrBuses[Copy_u8BusID].USART_C_pstrBuffer->Index++;
    }/* if */
    else/* Bus is busy now */
    {
      Loc_enuError = USART_C_enuBusy;
    }/* else */
  }/* if */
  else
  {
    Loc_enuError = USART_C_enuNok;
  }/* else */
  
  return(Loc_enuError);/* returning the error status */
}/* USART_enuSendBufferZeroCopy */
/* 
  Description         :     Send other buffer bytes on the USART with no copy
  Parameter(s)        :     void
  Return              :     void
  **Caution**         :     It must be registered as "USART" call back fn 
  ////////////////////// Synchronous //////////////////////
*/
void USART_enuSendBufferCallbackFn(void)
{
  u8 Loc_u8Counter = ZERO_INIT; /* Initialize counter to iterate over the connected USARTs */
  USART_tstrRegisters* Loc_pstrRegisters = NULL; /* Initializing registers pointer */
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < USART_C_u8CONN_MOD; Loc_u8Counter++)
  {
    Loc_pstrRegisters = ((USART_tstrRegisters*)(USART_C_astrBuses[Loc_u8Counter].BusNumber));
    if(USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Index == USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Size)/* double check that the buffer has been completely sent */
    {
      USART_C_astrBuses[Loc_u8Counter].BusStatus = USART_C_BUS_AVAILABLE;
      USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Index = ZERO_INIT;
      USART_C_astrBuses[Loc_u8Counter].USART_C_pfCallbackFn();
      Loc_pstrRegisters->SR  &= ~((u16)0x0040);
    }/* if */
    else
    { 
      USART_enuSendByte(USART_C_astrBuses[Loc_u8Counter].BusNumber, USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Buffer[USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Index]);  
      USART_C_astrBuses[Loc_u8Counter].USART_C_pstrBuffer->Index++;
    }/* else if */
  }/* for */
}/* USART_enuSendBufferCallbackFn */ 
/* 
  Description         :     Register the Buffer complete sending callback fn
  Parameter1          :     The Bus ID, options are in "USART_C_cfg.h" under "USART modules"
  Parameter2          :     Address of the callback fn
  Return              :     Error status of type "USART_C_tenuError", defined in "USART_C.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_C_tenuError USART_enuRegBufferTransCallbackFn(u8 Copy_u8BusID, tpfCallback Copy_pfCallbackFn)
{
  if(Copy_pfCallbackFn)/* validate arguments */
  {
    USART_C_astrBuses[Copy_u8BusID].USART_C_pfCallbackFn = Copy_pfCallbackFn;
  }/* if */
}/* USART_enuRegBufferTransCallbackFn */
/* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
