/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 26, 2022
**       Version     :	V01
**       SWC         :	M_NVIC
**       Description :	NVIC module files
** **************************************************************************************/
#ifndef _M_NVIC_H
#define _M_NVIC_H
  /* ****************************** MACROS ************************************************ */
  /* Active flag status */
  #define M_NVIC_u8NOT_ACTIVE                             0
  #define M_NVIC_u8ACTIVE                                 1
  /* ************************************************************************************** */
  /* ****************************** Defined Types ***************************************** */
  /* peripherals IRQ numbers */
  typedef enum
  {
    M_NVIC_enuWWDG = 0,
    M_NVIC_enuEXTI0 = 6,
    M_NVIC_enuDMA1_S0 = 11,
    M_NVIC_enuADC = 18
  }M_NVIC_tenuIRQn;
  /* Error type */
  typedef enum
  {
    M_NVIC_enuOk,
    M_NVIC_enuNok
  }M_NVIC_tenuError;
  /* ************************************************************************************** */
  /* ***************************** Interface Fns ****************************************** */
  /* 
    Fn          :         Enable specific Interrupt
    Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  */
  M_NVIC_tenuError M_NVIC_enuEnableIRQ(M_NVIC_tenuIRQn Copy_enuIRQn);
  /* 
    Fn          :         Disable specific Interrupt
    Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  */
  M_NVIC_tenuError M_NVIC_enuDisableIRQ(M_NVIC_tenuIRQn Copy_enuIRQn);
  /* 
    Fn          :         Set pending flag for specific Interrupt
    Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  */
  M_NVIC_tenuError M_NVIC_enuSetPendingIRQ(M_NVIC_tenuIRQn Copy_enuIRQn);
  /* 
    Fn          :         clear pending flag for specific Interrupt
    Parameter   :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  */
  M_NVIC_tenuError M_NVIC_enuClearPendingIRQ(M_NVIC_tenuIRQn Copy_enuIRQn);
  /* 
    Fn          :         Get the active flag status for specific Interrupt
    Parameter1   :        The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Parameter2   :        Pointer to receive the active flag status, options are in "M_NVIC.h" under "Active flag status"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
  */
  M_NVIC_tenuError M_NVIC_enuGetActiveStateIRQ(M_NVIC_tenuIRQn Copy_enuIRQn, pu8 Copy_pu8ActiveFlag);
  /* 
    Fn          :         Encode the given priority
    Parameter1  :         The group priority, options are in "M_NVIC_cfg.h" under "group priority options"
    Parameter2  :         The subgroup priority, options are in "M_NVIC_cfg.h" under "subgroup priority options"
    Parameter3   :        Pointer to receive the encoded priority
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
    **Caution** :         The priority binary point in the register "SCB->AIRCR" must be configured
  */
  M_NVIC_tenuError M_NVIC_enuEncodePriority(u8 Copy_u8GroupPri, u8 Copy_u8SubgroupPri, pu8 Copy_pu8Priority);
  /* 
    Fn          :         set the priority for specific Interrupt
    Parameter1  :         The IRQ number, options are in "M_NVIC.h" under "peripherals IRQ numbers"
    Parameter2  :         The priority to set, use the output of the fn "M_NVIC_enuEncodePriority"
    Return      :         The error status, options are in "M_NVIC.h" under "Error type"
    **Caution** :         The priority binary point in the register "SCB->AIRCR" must be configured
  */
  M_NVIC_tenuError M_NVIC_enuSetPriorityIRQ(M_NVIC_tenuIRQn Copy_enuIRQn, pu8 Copy_pu8Priority);
  /* 
    Fn          :         Enable IRQs
    Parameters  :         void
    Return      :         void
  */
  void M_NVIC_enuEnableIRQs(void);
  /* 
    Fn          :         Disable IRQs
    Parameters  :         void
    Return      :         void
  */
  void M_NVIC_enuDisableIRQs(void);
  /* 
    Fn          :         Enable Faults
    Parameters  :         void
    Return      :         void
  */
  void M_NVIC_enuEnableFaults(void);
  /* 
    Fn          :         Disable Faults
    Parameters  :         void
    Return      :         void
  */
  void M_NVIC_enuDisableFaults(void);

  /* ************************************************************************************** */


#endif