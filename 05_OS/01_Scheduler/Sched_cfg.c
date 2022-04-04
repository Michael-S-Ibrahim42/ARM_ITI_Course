/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/

  /* ********************** Headers inclusion *********************** */
  /* STD headers */
  #include "STD_TYPES.h"
  /* Runnables Prototypes inclusion */
  #include "H_Led.h"
  #include "Switch.h"
  #include "Lab2.h"
  /* Own headers */
  #include "Sched.h"
  #include "Sched_cfg.h"
  /* **************************************************************** */
  /* *********************** Global ********************************* */
  const Sched_tstrRunnable Sched_astrRunnableList[] = 
  {
    [SCHED_u8SWITCH_TASK] = 
    {
      .CallbackFn   = Switch_RUpdateStatus,
      .CyclicTimeMS = 5
    },
    [SCHED_u8LAB2_TASK] = 
    {
      .CallbackFn   = Lab2_LedControlTask,
      .CyclicTimeMS = 5
    }
  };
  /* **************************************************************** */
  