/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/

  /* ********************** Headers inclusion *********************** */
  /* STD headers */
  #include "StdTypes.h"
  /* Runnables Prototypes inclusion */
  // #include "LCD.h"
   #include "USART_Test.h"
  /* Own headers */
  #include "Sched.h"
  #include "Sched_cfg.h"
  /* **************************************************************** */
  /* *********************** Global ********************************* */
  const Sched_tstrRunnable Sched_astrRunnableList[] = 
  {
    [SCHED_u8USART_TEST_R] = 
    {
      .CallbackFn   = USART_Test_vidCallbackFn,
      .CyclicTimeMS = 1
    }
  };
  /* **************************************************************** */
  
