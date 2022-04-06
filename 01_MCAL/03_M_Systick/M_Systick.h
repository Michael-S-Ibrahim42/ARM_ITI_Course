/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	M_Systick
**       Description :	Systick timer module files
** **************************************************************************************/
#ifndef _M_SYSTICK_H
#define _M_SYSTICK_H
  /* ************************** Arguments MACROS  **************************************** */
  /* Timer Clk Sources */
  #define M_SYSTICK_u8AHB_OVER_8          0
  #define M_SYSTICK_u8AHB                 1 
  /* Timer Interrupt Activation */
  #define M_SYSTICK_u8OFF_INT             0
  #define M_SYSTICK_u8ON_INT              1
  /* ************************************************************************************* */
  /* *************************** Defined Types ******************************************* */
  /* callback fn pointer type */
  typedef void (*M_Systick_tpfCallback)(void);
  /* Error Type */
  typedef enum
  {
    M_Systick_enuOk,
    M_Systick_enuNok
  }M_Systick_tenuError;
  /* ************************************************************************************* */
  /* ************************** Interface Fns Headers ************************************ */
  /* 
    Fn           :     Init the systick timer
    Parameter1   :     The Source clk, options are in "M_Systick.h" under "Timer Clk Sources" 
    Parameter2   :     Interrupt Activation, options are in "M_Systick.h" under "Timer Interrupt Activation" 
    Return       :     The status error, options are in "M_Systick.h" under "Error Type" 
  */
  extern M_Systick_tenuError M_Systick_enuInit(u8 Copy_u8TimerSrc, u8 Copy_u8IntActivation);
  /* 
    Fn           :     Start timer with specific delay
    Parameter    :     The delay time in milliseconds
    Return       :     The status error, options are in "M_Systick.h" under "Error Type" 
  */  
  extern M_Systick_tenuError M_Systick_enuSetTickTimeMS(u32 Copy_u32Time_MS);
  /* 
    Fn           :     Start timer
    **caution**  :     You should set the tick time before using the "M_Systick_enuSetTickTimeMS" fn in "M_Systick.h"
  */  
  extern void M_Systick_enuStart(void);
  /* 
    Fn         :   Register the callback fn
    Parameter1 :   Address of the callback fn
    Return     :   Error status of the fn, Error type is in "M_Systick.h" under "Error Type"
  */
  extern M_Systick_tenuError M_Systick_vidRegCallbackFn(M_Systick_tpfCallback Copy_pfCallback);
  /* ************************************************************************************* */

#endif
