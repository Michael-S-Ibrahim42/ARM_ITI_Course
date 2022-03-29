/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 26, 2022
**       Version     :	V01
**       SWC         :	M_NVIC
**       Description :	NVIC module files
** **************************************************************************************/
/* **************************** Inclusion part ****************************************** */
/* LIB headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* Own headers */
#include "M_NVIC.h"
#include "M_NVIC_cfg.h"
#include "M_NVIC_prv.h"
/* ************************************************************************************** */
/* ******************************* Interface Fns **************************************** */
/* 
  Fn          :         Enable specific Interrupt
  Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
*/
M_NVIC_tenuError M_NVIC_enuEnableIRQ(M_NVIC_tenuIRQn Copy_enuIRQn)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    M_NVIC_strRegisters->ISER[Copy_enuIRQn/M_NVIC_u8REG_SIZE] |= (1<<(Copy_enuIRQn%M_NVIC_u8REG_SIZE));
  }/* else */

  return(Loc_enuError);
}/* M_NVIC_enuEnableIRQ */
/* 
  Fn          :         Disable specific Interrupt
  Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
*/
M_NVIC_tenuError M_NVIC_enuDisableIRQ(M_NVIC_tenuIRQn Copy_enuIRQn)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    M_NVIC_strRegisters->ICER[Copy_enuIRQn/M_NVIC_u8REG_SIZE] |= (1<<(Copy_enuIRQn%M_NVIC_u8REG_SIZE));
  }/* else */

  return(Loc_enuError);
}/* M_NVIC_enuDisableIRQ */
/* 
  Fn          :         Set pending flag for specific Interrupt
  Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
*/
M_NVIC_tenuError M_NVIC_enuSetPendingIRQ(M_NVIC_tenuIRQn Copy_enuIRQn)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    M_NVIC_strRegisters->ISPR[Copy_enuIRQn/M_NVIC_u8REG_SIZE] |= (1<<(Copy_enuIRQn%M_NVIC_u8REG_SIZE));
  }/* else */

  return(Loc_enuError);  
}/* M_NVIC_enuSetPendingIRQ */
/* 
  Fn          :         clear pending flag for specific Interrupt
  Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
*/
M_NVIC_tenuError M_NVIC_enuClearPendingIRQ(M_NVIC_tenuIRQn Copy_enuIRQn)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    M_NVIC_strRegisters->ICPR[Copy_enuIRQn/M_NVIC_u8REG_SIZE] |= (1<<(Copy_enuIRQn%M_NVIC_u8REG_SIZE));
  }/* else */

  return(Loc_enuError);  
}/* M_NVIC_enuClearPendingIRQ */
/* 
  Fn          :         Get the active flag status for specific Interrupt
  Parameter1   :        The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Parameter2   :        Pointer to receive the active flag status, options are in "M_NVIC.h" under "Active flag status"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
*/
M_NVIC_tenuError M_NVIC_enuGetActiveStateIRQ(M_NVIC_tenuIRQn Copy_enuIRQn, pu8 Copy_pu8ActiveFlag)
{
  u8 Loc_u8ActiveFlag;
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    Loc_u8ActiveFlag = M_NVIC_strRegisters->ICPR[Copy_enuIRQn/M_NVIC_u8REG_SIZE] & (1<<(Copy_enuIRQn%M_NVIC_u8REG_SIZE));
    if(Loc_u8ActiveFlag)
    {
      *Copy_pu8ActiveFlag = M_NVIC_u8ACTIVE;
    }/* if */
    else
    {
      *Copy_pu8ActiveFlag = M_NVIC_u8NOT_ACTIVE;
    }/* else */
  }/* else */

  return(Loc_enuError);  
}/* M_NVIC_enuGetActiveStateIRQ */
/* 
  Fn          :         Encode the given priority
  Parameter1  :         The group priority, options are in "M_NVIC_cfg.h" under "group priority options"
  Parameter2  :         The subgroup priority, options are in "M_NVIC_cfg.h" under "subgroup priority options"
  Parameter3   :        Pointer to receive the encoded priority
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  **Caution** :         The priority binary point in the register "SCB->AIRCR" must be configured
*/
M_NVIC_tenuError M_NVIC_enuEncodePriority(u8 Copy_u8GroupPri, u8 Copy_u8SubgroupPri, pu8 Copy_pu8Priority)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if(!Copy_pu8Priority)
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    if(M_NVIC_u8G_LVLS == M_NVIC_u8_16_LVL)
    {
      *Copy_pu8Priority = (Copy_u8GroupPri<<M_NVIC_u8_SHIFT_4);
    }/* if */
    else if(M_NVIC_u8G_LVLS == M_NVIC_u8_8_LVL)
    {
      *Copy_pu8Priority = (Copy_u8GroupPri<<M_NVIC_u8_SHIFT_5) | (Copy_u8SubgroupPri<<M_NVIC_u8_SHIFT_4);
    }/* else if */
    else if(M_NVIC_u8G_LVLS == M_NVIC_u8_4_LVL)
    {
      *Copy_pu8Priority = (Copy_u8GroupPri<<M_NVIC_u8_SHIFT_6) | (Copy_u8SubgroupPri<<M_NVIC_u8_SHIFT_4);
    }/* else if */
    else if(M_NVIC_u8G_LVLS == M_NVIC_u8_2_LVL)
    {
      *Copy_pu8Priority = (Copy_u8GroupPri<<M_NVIC_u8_SHIFT_7) | (Copy_u8SubgroupPri<<M_NVIC_u8_SHIFT_4);
    }/* else if */ 
    else
    {
      Loc_enuError = M_NVIC_enuNok;
    }/* else */
  }/* else */

  return(Loc_enuError);  
}/* M_NVIC_enuEncodePriority */
/* 
  Fn          :         set the priority for specific Interrupt
  Parameter1  :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
  Parameter2  :         The priority to set, use the output of the fn "M_NVIC_enuEncodePriority"
  Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  **Caution** :         The priority binary point in the register "SCB->AIRCR" must be configured
*/
M_NVIC_tenuError M_NVIC_enuSetPriorityIRQ(M_NVIC_tenuIRQn Copy_enuIRQn, pu8 Copy_pu8Priority)
{
  M_NVIC_tenuError Loc_enuError = M_NVIC_enuOk;
  if((!Copy_pu8Priority) || (Copy_enuIRQn > M_NVIC_u8EXT_PER_LIMIT)) /* Arguments Validation */
  {
    Loc_enuError = M_NVIC_enuNok;
  }/* if */
  else
  {
    M_NVIC_strRegisters->IPR[Copy_enuIRQn] = *Copy_pu8Priority;
  }/* else */

  return(Loc_enuError);  
}/* M_NVIC_enuSetPriorityIRQ */
/* 
  Fn          :         Enable IRQs
  Parameters  :         void
  Return      :         void
*/
void M_NVIC_enuEnableIRQs(void)
{
  asm("CPSIE i"); /* Enable interrupts and configurable fault handlers(clear PRIMASK)  */
}/* M_NVIC_enuEnableIRQs */
/* 
  Fn          :         Disable IRQs
  Parameters  :         void
  Return      :         void
*/
void M_NVIC_enuDisableIRQs(void)
{
  asm("CPSID i"); /* Disable interrupts and configurable fault handlers (set PRIMASK)  */

}/* M_NVIC_enuDisableIRQs */
/* 
  Fn          :         Enable Faults
  Parameters  :         void
  Return      :         void
*/
void M_NVIC_enuEnableFaults(void)
{
  asm("CPSIE f");   /* Enable interrupts and fault handlers (clear FAULTMASK) */
}/* M_NVIC_enuEnableFaults */
/* 
  Fn          :         Disable Faults
  Parameters  :         void
  Return      :         void
*/
void M_NVIC_enuDisableFaults(void)
{
  asm("CPSID f"); /* Disable interrupts and all fault handlers (set FAULTMASK)  */
}/* M_NVIC_enuDisableFaults */
/* ************************************************************************************** */