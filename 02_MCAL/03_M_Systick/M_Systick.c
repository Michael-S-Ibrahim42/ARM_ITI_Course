/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	M_Systick
**       Description :	Systick timer module files
** **************************************************************************************/
/* ************************** Headers inclusion   ************************************** */
/* LIB headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* Own headers */
#include "M_Systick.h"
#include "M_Systick_cfg.h"
#include "M_Systick_prv.h"
/* ****************************** Global *********************************************** */
static M_Systick_tpfCallback M_Systick_pfCallback;
static u32 M_Systick_u32OverflowsNumber;
static u32 M_Systick_u32TempOverflowsNumber;
static u32 M_Systick_u32ReloadValue;
/* ************************************************************************************* */
/* **************************** Interface Fns ****************************************** */
/* 
  Fn           :     Init the systick timer
  Parameter1   :     The Source clk, options are in "M_Systick.h" under "Timer Clk Sources" 
  Parameter2   :     Interrupt Activation, options are in "M_Systick.h" under "Timer Interrupt Activation" 
  Return       :     The status error, options are in "M_Systick.h" under "Error Type" 
*/
M_Systick_tenuError M_Systick_enuInit(u8 Copy_u8TimerSrc, u8 Copy_u8IntActivation)
{
  M_Systick_tenuError Loc_enuError = M_Systick_enuOk;
  /* Input validation */
  if((Copy_u8TimerSrc > M_SYSTICK_u8AHB) || (Copy_u8IntActivation > M_SYSTICK_u8ON_INT))
  {
    Loc_enuError = M_Systick_enuNok;
  }/* if */
  else
  {
    /* Selecting the clock source */
    if(Copy_u8TimerSrc == M_SYSTICK_u8AHB_OVER_8)
    {
      M_SYSTICK_pstrRegisters->CTRL &= ~M_SYSTICK_u32CLK_SRC;
    }/* if */
    else
    {
        M_SYSTICK_pstrRegisters->CTRL |= M_SYSTICK_u32CLK_SRC;
    }/* else */
    /* Activate/Deactivate the interrupt */
    if(Copy_u8IntActivation == M_SYSTICK_u8OFF_INT)
    {
      M_SYSTICK_pstrRegisters->CTRL &= ~M_SYSTICK_u32INT;
    }/* if */
    else
    {
      M_SYSTICK_pstrRegisters->CTRL |= M_SYSTICK_u32INT;
    }/* else */
  }/* else */

  return(Loc_enuError);
}/* M_Systick_enuInit */
/* 
  Fn           :     Start timer with specific delay
  Parameter    :     The delay time in milliseconds
  Return       :     The status error, options are in "M_Systick.h" under "Error Type" 
*/  
M_Systick_tenuError M_Systick_enuSetTickTimeMS(u32 Copy_u32Time_MS)
{
  M_Systick_tenuError Loc_enuError = M_Systick_enuOk;
  f64 Loc_f64TickTime;
  u64 Loc_u64NeededTicks;

  Loc_f64TickTime = (f64)1 / (M_SYSTICK_u8CLOCK * (u64)1000); /* The tick time in Milliseconds */
  Loc_u64NeededTicks = Copy_u32Time_MS / Loc_f64TickTime; /* Needed ticks to achieve required delay */
  M_Systick_u32OverflowsNumber = (Loc_u64NeededTicks / (u32)M_SYSTICK_u32MAX_RELOAD); /* Number of needed overflows */
  if(M_Systick_u32OverflowsNumber > 0)
  {
    M_Systick_u32OverflowsNumber -= 1;
  }
  M_Systick_u32TempOverflowsNumber = M_Systick_u32OverflowsNumber;
  M_Systick_u32ReloadValue = (Loc_u64NeededTicks % M_SYSTICK_u32MAX_RELOAD); /* Number of reload value */
  if(M_Systick_u32OverflowsNumber > 0)
  {
    M_SYSTICK_pstrRegisters->LOAD = M_SYSTICK_u32MAX_RELOAD-1; /* You have to encounter the overflow time */
  }/* if */
  else
  {
    M_SYSTICK_pstrRegisters->LOAD = M_Systick_u32ReloadValue-1; 
  }/* else */
  
  return(Loc_enuError);/* returning the error status */
}/* M_Systick_enuDelay */
/* 
  Fn         :   Register the callback fn
  Parameter1 :   Address of the callback fn
  Return     :   Error status of the fn, Error type is in "M_Systick.h" under "Error Type"
*/
M_Systick_tenuError M_Systick_vidRegCallbackFn(M_Systick_tpfCallback Copy_pfCallback)
{
  M_Systick_tenuError Loc_enuError = M_Systick_enuOk;
  if(Copy_pfCallback)
  {
    M_Systick_pfCallback = Copy_pfCallback;
  }/* if */
  else
  {
    Loc_enuError = M_Systick_enuNok;
  }/* else */

  return(Loc_enuError);/* return error status */
}/* M_Systick_vidRegCallbackFn */
/* 
  Fn           :     Start timer
  **caution**  :     You should set the tick time before using the "M_Systick_enuSetTickTimeMS" fn in "M_Systick.h"
*/  
void M_Systick_enuStart(void)
{
  /* Enable the systick */
  M_SYSTICK_pstrRegisters->CTRL |= M_SYSTICK_u32ENABLE;
}/* M_Systick_enuStart */
/* ************************************************************************************* */
/* ***************************** Systick Timer Handler ********************************* */
void SysTick_Handler(void)
{
  if(M_Systick_u32TempOverflowsNumber)
  {
    if(M_Systick_u32TempOverflowsNumber == M_Systick_u32OverflowsNumber + 1)
    {
      M_Systick_pfCallback();
      M_SYSTICK_pstrRegisters->LOAD = M_SYSTICK_u32MAX_RELOAD-1;
      M_SYSTICK_pstrRegisters->VAL  = M_SYSTICK_u32VAL_CLEAR;
    }/* if */
    M_Systick_u32TempOverflowsNumber--;
  }/* if */
  else
  {
    if(M_Systick_u32OverflowsNumber)
    {
      M_SYSTICK_pstrRegisters->LOAD = M_Systick_u32ReloadValue - 1;
      M_SYSTICK_pstrRegisters->VAL  = M_SYSTICK_u32VAL_CLEAR;
      M_Systick_u32TempOverflowsNumber = M_Systick_u32OverflowsNumber + 1;
    }/* if */
    else
    {
      M_Systick_pfCallback();
    }/* else */
  }/* else */
}/* SysTick_Handler */
/* ************************************************************************************* */
