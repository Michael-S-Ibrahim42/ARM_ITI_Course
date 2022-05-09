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
#include "USART.h"
#include "USART_cfg.h"
#include "USART_prv.h"
/* //////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////// Global Variables ///////////////////////////////// */
USART_tstrSpecs* USART_apstrTxSpecs[USART_u8AVAIL_BUSES];
USART_tstrSpecs* USART_apstrRxSpecs[USART_u8AVAIL_BUSES];
/* //////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////// Interface Fns //////////////////////////////////// */
/* 
  Description         :     Init the USART
  Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
  Parameter2          :     Address of the configurations struct of type "USART_tstrConfig" defined in "USART.h"
  Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
  ////////////////////// Synchronous //////////////////////
*/
USART_tenuStatus USART_enuInit(USART_tstrSpecs* Copy_pstrSpecs, USART_tstrConfig* Copy_pstrConfig)
{
  USART_tenuStatus       Loc_enuError              =     USART_enuOk;
  f32                    Loc_f32USART_Div          =     ZERO_INIT;
  f32                    Loc_f32Fraction_Temp      =     ZERO_INIT;
  u16                    Loc_u16Oversampling       =     ((Copy_pstrConfig->Oversampling)>>USART_u8OVER8);
  u8                     Loc_u8Div_Fraction        =     ZERO_INIT;
  u16                    Loc_u16Div_Mantissa       =     ZERO_INIT; 
  USART_tstrRegisters*   Loc_pstrRegisters         =     NULL;
  
  if((Copy_pstrConfig != NULL) && (Copy_pstrSpecs != NULL))/* Validate Arguments */ 
  {
    switch(Copy_pstrSpecs->BusID)
    {
    case(USART_u8BUS1):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART1_u32BASE_ADD));
      break;
    case(USART_u8BUS2):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART2_u32BASE_ADD));
      break;
    case(USART_u8BUS6):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART6_u32BASE_ADD));
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
    Loc_f32USART_Div       = ((f32)Copy_pstrConfig->Frequency)*(USART_u32MEGA_FACTOR);
    Loc_f32USART_Div      /= (8 * (2-Loc_u16Oversampling) * (Copy_pstrConfig->BaudRate * USART_u16KILO_FACTOR)); /* The numbers are the equation numbers */
    Loc_u16Div_Mantissa    = (u16)Loc_f32USART_Div;
    Loc_f32Fraction_Temp   = (Loc_f32USART_Div - (u32)Loc_f32USART_Div) * (USART_u8MAX_OVERSAMP - (Loc_u16Oversampling * USART_u8MIN_OVERSAMP));
    Loc_u8Div_Fraction     = (u8)Loc_f32Fraction_Temp;
    if( (((u8)(Loc_f32Fraction_Temp * USART_u8SHIFT_POINT_RIGHT))%USART_u8FIRST_DIG_SLICER) >= USART_u8ROUNDING_CENTER)
    {
      Loc_u8Div_Fraction++;
    }/* if */
    if((Loc_u16Oversampling) && (Loc_u8Div_Fraction > USART_u8THREE_BIT_MAX))/* Here we are oversampling by 8 */
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
    Loc_pstrRegisters->CR1  = USART_u16_ENABLE;
    Loc_pstrRegisters->BRR  = (Loc_u16Div_Mantissa<<USART_u8MANT_SHIFT) | (Loc_u8Div_Fraction);
    Loc_pstrRegisters->CR2  = Copy_pstrConfig->StopBits;
    Loc_pstrRegisters->CR1 |= (USART_u16_TX_ENABLE) | (USART_u16_RX_ENABLE) | (Copy_pstrConfig->Oversampling) | (Copy_pstrConfig->WordLength) | (Copy_pstrConfig->Parity);
  }/* if */
  else
  {
    Loc_enuError = USART_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* USART_enuInit */
/* 
  Description         :     starting sending of buffer on USART channel
  Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
  Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
  ////////////////////// Asynchronous //////////////////////
*/
USART_tenuStatus USART_enuSendBufferZeroCopy(USART_tstrSpecs* Copy_pstrSpecs)
{
  USART_tenuStatus     Loc_enuStatus     = USART_enuOk;
  USART_tstrRegisters* Loc_pstrRegisters = NULL;
  if(Copy_pstrSpecs != NULL)
  {
    switch(Copy_pstrSpecs->BusID)
    {
    case(USART_u8BUS1):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART1_u32BASE_ADD));
      break;
    case(USART_u8BUS2):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART2_u32BASE_ADD));
      break;
    case(USART_u8BUS6):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART6_u32BASE_ADD));
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
    if(USART_apstrTxSpecs[Copy_pstrSpecs->BusID] == NULL)/* check on bus availability to register sending buffer */
    {
      USART_apstrTxSpecs[Copy_pstrSpecs->BusID] = Copy_pstrSpecs;
      Loc_pstrRegisters->SR  &= ~(USART_u8TXC_FLAG);
      Loc_pstrRegisters->CR1 |=  (USART_u16_TXC_ENABLE);
      USART_enuSendByte(Copy_pstrSpecs->BusID);
    }/* if */
    else 
    {
      Loc_enuStatus = USART_enuNok;
    }/* else */
  }/* if */
  else
  {
    Loc_enuStatus = USART_enuNok;
  }/* else */

  return(Loc_enuStatus);/* return status of the bus */
}/* USART_enuSendBufferZeroCopy */
/* 
  Description         :     Enable receiving of buffer on USART channel
  Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
  Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
  ////////////////////// Asynchronous //////////////////////
*/
USART_tenuStatus USART_enuReceiveBuffer(USART_tstrSpecs* Copy_pstrSpecs)
{
  USART_tenuStatus     Loc_enuStatus     = USART_enuOk;
  USART_tstrRegisters* Loc_pstrRegisters = NULL;
  if(Copy_pstrSpecs != NULL)
  {
    switch(Copy_pstrSpecs->BusID)
    {
    case(USART_u8BUS1):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART1_u32BASE_ADD));
      break;
    case(USART_u8BUS2):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART2_u32BASE_ADD));
      break;
    case(USART_u8BUS6):
      Loc_pstrRegisters = ((USART_tstrRegisters*)(USART6_u32BASE_ADD));
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
    if(USART_apstrRxSpecs[Copy_pstrSpecs->BusID] == NULL)
    {
      USART_apstrRxSpecs[Copy_pstrSpecs->BusID] = Copy_pstrSpecs;
      Loc_pstrRegisters->SR  &= ~(USART_u8RXNE_FLAG);
      Loc_pstrRegisters->CR1 |= (USART_u16_RXNE_ENABLE);
    }/* if */
    else 
    {
      Loc_enuStatus = USART_enuNok;
    }/* else */
  }/* if */
  else
  {
    Loc_enuStatus = USART_enuNok;
  }/* else */

  return(Loc_enuStatus);/* return status of the bus */
}/* USART_enuReceiveBuffer */
/* 
  Description         :     Send byte on the USART
  Parameter1          :     The byte
  Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
  ////////////////////// Synchronous //////////////////////
*/
static USART_tenuStatus USART_enuSendByte(u8 Copy_u8BusID)
{
  USART_tenuStatus Loc_enuError = USART_enuOk;/* Initializing error status */
  USART_tstrRegisters* Loc_pstrRegisters = NULL;

  switch(Copy_u8BusID)
  {
  case(USART_u8BUS1):
    Loc_pstrRegisters = ((USART_tstrRegisters*)USART1_u32BASE_ADD);
    break;
  case(USART_u8BUS2):
    Loc_pstrRegisters = ((USART_tstrRegisters*)USART2_u32BASE_ADD);
    break;
  case(USART_u8BUS6):
    Loc_pstrRegisters = ((USART_tstrRegisters*)USART6_u32BASE_ADD);  
    break;
  default:
    /* MISRA */
    break;
  }/* switch */
  
  if(((Loc_pstrRegisters->SR >> USART_u8TXE_SHIFT) & FIRST_BIT_SLICER) == FLAG_HIGH)
  {
    Loc_pstrRegisters->DR = USART_apstrTxSpecs[Copy_u8BusID]->Buffer.Data[USART_apstrTxSpecs[Copy_u8BusID]->Buffer.Index];
    USART_apstrTxSpecs[Copy_u8BusID]->Buffer.Index++;
  }/* if */
  else/* The TX DR is not empty */
  {
    Loc_enuError = USART_enuNok;
  }/* else */

  return(Loc_enuError);/* returning error status */
}/* USART_enuSendByte */
/* //////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////// ISR Fn ///////////////////////////////////////// */
/* 
  Description         :     The USART1 IRQ handler
  Parameter1          :     void
  Return              :     void
  ////////////////////// Synchronous //////////////////////
*/
void USART1_IRQHandler(void)
{
  USART_tstrRegisters* Loc_pstrRegisters = ((USART_tstrRegisters*)USART1_u32BASE_ADD);
  tpfCallback Loc_pfCallback;
  if((((Loc_pstrRegisters->SR >> USART_u8TXC_SHIFT) & FIRST_BIT_SLICER) == FLAG_HIGH) && (USART_apstrTxSpecs[USART_u8BUS1] != NULL))/* Trasmission section */
  {
    if(USART_apstrTxSpecs[USART_u8BUS1]->Buffer.Index == USART_apstrTxSpecs[USART_u8BUS1]->Buffer.Size)/* Check that the hole buffer has been sent */
    {
      Loc_pfCallback = USART_apstrTxSpecs[USART_u8BUS1]->Callback;
      USART_apstrTxSpecs[USART_u8BUS1]->Buffer.Index = ZERO_INIT;
      USART_apstrTxSpecs[USART_u8BUS1] = NULL; /* Clearing the pointer to user buffer */
      Loc_pstrRegisters->CR1 &= ~(USART_u16_TXC_ENABLE);
      Loc_pfCallback();/* Notifying the user */
    }/* if */
    else
    {
      USART_enuSendByte(USART_u8BUS1);
    }/* else */
    Loc_pstrRegisters->SR &= ~(USART_u8TXC_FLAG); /* clearing the TC flag */
  }/* if */
  if((((Loc_pstrRegisters->SR >> USART_u8RXNE_SHIFT) & FIRST_BIT_SLICER) == FLAG_HIGH) && (USART_apstrRxSpecs[USART_u8BUS1] != NULL))/* Reception section */
  {
    USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Data[USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Index] = Loc_pstrRegisters->DR;
    USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Index++;
    if(USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Index == USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Size)/* the whole buffer has been received */
    {
      Loc_pstrRegisters->CR1 &= ~(USART_u16_RXNE_ENABLE); /* Disabling the receive complete interrupt */
      Loc_pfCallback = USART_apstrRxSpecs[USART_u8BUS1]->Callback;
      USART_apstrRxSpecs[USART_u8BUS1]->Buffer.Index = ZERO_INIT;
      USART_apstrRxSpecs[USART_u8BUS1] = NULL;
      Loc_pfCallback();/* Notifying the user */
    }/* if */
    Loc_pstrRegisters->SR  &= ~(USART_u8RXNE_FLAG); /* clearing the RXNE flag */
  }/* if */
}/* ISR */
/* 
  Description         :     The USART2 IRQ handler
  Parameter1          :     void
  Return              :     void
  ////////////////////// Synchronous //////////////////////
*/
void USART2_IRQHandler(void)
{

}/* ISR */
/* 
  Description         :     The USART6 IRQ handler
  Parameter1          :     void
  Return              :     void
  ////////////////////// Synchronous //////////////////////
*/
void USART6_IRQHandler(void)
{
  
}/* ISR */
/* //////////////////////////////////////////////////////////////////////////////////// */





