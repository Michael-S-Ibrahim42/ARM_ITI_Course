/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 12, 2022
**       Version     :	V01
**       SWC         :	USART_C
**       Description :	USART Control module
** **************************************************************************************/
/* //////////////////////////////////////////// Headers inclusion /////////////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
/* MCAL Headers */
#include "USART.h"
/* Own headers */
#include "USART_C.h"
#include "USART_C_cfg.h"
/* ////////////////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////// Configurations Variable /////////////////////////////////////// */
USART_C_tstrBus USART_C_astrBuses[] = 
{ 
  [USART_C_u8BUS1] =
  {
    .BusNumber = USART_u32BUS1,
    .BusStatus = USART_C_BUS_AVAILABLE,
    .USART_C_pstrBuffer = NULL,
    .USART_C_pfCallbackFn = NULL
  },
  [USART_C_u8BUS2] =
  {
    .BusNumber = USART_u32BUS2,
    .BusStatus = USART_C_BUS_AVAILABLE,
    .USART_C_pstrBuffer = NULL,
    .USART_C_pfCallbackFn = NULL    
  },
  [USART_C_u8BUS6] =
  {
    .BusNumber = USART_u32BUS6,
    .BusStatus = USART_C_BUS_AVAILABLE,
    .USART_C_pstrBuffer = NULL,
    .USART_C_pfCallbackFn = NULL
  }
};
/* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
