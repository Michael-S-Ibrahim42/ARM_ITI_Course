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
  #include "LCD.h"
  #include "Lab5.h"
  /* Own headers */
  #include "Sched.h"
  #include "Sched_cfg.h"
  /* **************************************************************** */
  /* *********************** Global ********************************* */
  const Sched_tstrRunnable Sched_astrRunnableList[] = 
  {
    [SCHED_u8LAB5_TASK] = 
    {
      .CallbackFn   = Lab5_vidLedToggle_R,
      .CyclicTimeMS = 1
    }
  };
  /* **************************************************************** */
  