/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	USART
**       Description :	USART module file
** **************************************************************************************/
/* ///////////////////////////////// Headers inclusion //////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
#include "STM32F401CC.h"
/* Own headers */
#include "USART_C.h"
#include "USART.h"
#include "USART_cfg.h"
#include "USART_prv.h"
/* //////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////// Global Variables /////////////////////////////////// */
/* CallbackFn Pointer array */
tpfCallback USART_apfCallbackFn[USART_u8AVAIL_BUSES];
/* //////////////////////////////////////////////////////////////////////////////////// */
/* ///////////////////////////////// Interface Fns //////////////////////////////////// */
/* 
  Description         :     Init the USART
  Parameter1          :     Address of the configurations struct of type "USART_tstrConfig" defined in "USART.h"
  Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_tenuError USART_enuInit(USART_tstrConfig* Copy_pstrConfig)
{
  USART_tenuError Loc_enuError = USART_enuOk;
  f32 Loc_f32USART_Div = ZERO_INIT;
  f32 Loc_f32Fraction_Temp = ZERO_INIT;
  u8  Loc_u8Oversampling = ((Copy_pstrConfig->Oversampling)>>USART_u8OVER8);
  u8  Loc_u8Div_Fraction = ZERO_INIT;
  u16 Loc_u16Div_Mantissa = ZERO_INIT; 
  USART_tstrRegisters* Loc_pstrRegisters = NULL;
  
  if(Copy_pstrConfig)/* Validate Arguments */ 
  {
    Loc_pstrRegisters = ((USART_tstrRegisters*)(Copy_pstrConfig->BusNumber));
    Loc_f32USART_Div = ((f32)Copy_pstrConfig->Frequency)*(USART_u32MEGA_FACTOR);
    Loc_f32USART_Div = Loc_f32USART_Div / (8 * (2-Loc_u8Oversampling) * (Copy_pstrConfig->BaudRate * USART_u32KILO_FACTOR)); /* The numbers are the equation numbers */
    Loc_u16Div_Mantissa = (u16)Loc_f32USART_Div;
    Loc_f32Fraction_Temp = (Loc_f32USART_Div - (u32)Loc_f32USART_Div) * (USART_u8MAX_OVERSAMP - (Loc_u8Oversampling * USART_u8MIN_OVERSAMP));
    Loc_u8Div_Fraction = (u8)Loc_f32Fraction_Temp;
    if( (((u8)(Loc_f32Fraction_Temp * USART_u8SHIFT_POINT_RIGHT))%USART_u8FIRST_DIG_SLICER) >= USART_u8ROUNDING_CENTER)
    {
      Loc_u8Div_Fraction++;
    }/* if */
    if((Loc_u8Oversampling) && (Loc_u8Div_Fraction > USART_u8THREE_BIT_MAX))/* Here we are oversampling by 8 */
    {
      Loc_u8Div_Fraction = ZERO_INIT;
      Loc_u16Div_Mantissa++;
    }/* if */
    else/* Here we are oversampling by 16 */
    {
      if(Loc_u8Div_Fraction > USART_u8FOUR_BIT_MAX)
      {
        Loc_u8Div_Fraction = ZERO_INIT;
        Loc_u16Div_Mantissa++;
      }/* if */
    }/* else */
    Loc_pstrRegisters->SR  &= ~(USART_u16_TXC_ENABLE);
    Loc_pstrRegisters->CR1  = USART_u16_ENABLE;
    Loc_pstrRegisters->BRR  = (Loc_u16Div_Mantissa<<USART_u8MANT_SHIFT) | (Loc_u8Div_Fraction);
    Loc_pstrRegisters->CR2  = Copy_pstrConfig->StopBits;
    Loc_pstrRegisters->CR1 |= (USART_u16_TX_ENABLE) | (Copy_pstrConfig->Oversampling) | (Copy_pstrConfig->WordLength) | (Copy_pstrConfig->Parity) | (USART_u16_TXC_ENABLE);
  }/* if */
  else
  {
    Loc_enuError = USART_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* USART_enuInit */
/* 
  Description         :     Send byte on the USART
  Parameter1          :     The bus no, options are in "USART.h" under "Used USARTs"
  Parameter2          :     the byte
  Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_tenuError USART_enuSendByte(u32 Copy_u32BusNumber, u8 Copy_u8Byte)
{
  USART_tenuError Loc_enuError = USART_enuOk;/* Initializing error status */
  USART_tstrRegisters* Loc_pstrRegisters = ((USART_tstrRegisters*)Copy_u32BusNumber);
  if(((Loc_pstrRegisters->SR >> USART_u8TXE_SHIFT) & FIRST_BIT_SLICER) == FLAG_HIGH)
  {
    Loc_pstrRegisters->DR = Copy_u8Byte;
  }/* if */
  else/* The TX DR is not empty */
  {
    Loc_enuError = USART_enuNok;
  }/* else */

  return(Loc_enuError);/* returning error status */
}/* USART_enuSendByte */
/* 
  Description         :     Register the USART interrupt callback fn , called on DR empty and transmission complete
  Parameter1          :     The bus ID, available options are in "USART.h" under "USARTs IDs"
  Parameter2          :     Address of the callback fn
  Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_tenuError USART_enuRegTxCallbackFn(u8 Copy_u8BusID, tpfCallback Copy_pfCallbackFn)
{
  USART_tenuError Loc_enuError = USART_enuOk;
  if(Copy_pfCallbackFn)/* Validate arguments */
  {
    USART_apfCallbackFn[Copy_u8BusID] = Copy_pfCallbackFn;
  }/* if */
  else/* The Pointer to fn is not assigned right value */
  {
    Loc_enuError = USART_enuNok;
  }/* else */
  
  return(Loc_enuError);/* Returning error status */
}/* USART_enuRegTxCallbackFn */  
/* //////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////// ISR Fn ///////////////////////////////////////// */
void USART1_IRQHandler(void)
{
  USART_tstrRegisters* Loc_pstrRegisters = ((USART_tstrRegisters*)USART_u32BUS1);
  if(USART_apfCallbackFn[USART_u8NUM1])/* Check on callback fn registering */
  {
    (USART_apfCallbackFn[USART_u8NUM1])(); /* Call the callback fn */
    Loc_pstrRegisters->SR  &= ~(USART_u16_TXC_ENABLE);
  }/* if */
}/* ISR */
void USART2_IRQHandler(void)
{
  if(USART_apfCallbackFn[USART_u8NUM2])/* Check on callback fn registering */
  {
    USART_apfCallbackFn[USART_u8NUM2](); /* Call the callback fn */
  }/* if */
}/* ISR */
void USART6_IRQHandler(void)
{
  if(USART_apfCallbackFn[USART_u8NUM6])/* Check on callback fn registering */
  {
    USART_apfCallbackFn[USART_u8NUM6](); /* Call the callback fn */
  }/* if */
}/* ISR */
/* //////////////////////////////////////////////////////////////////////////////////// */
