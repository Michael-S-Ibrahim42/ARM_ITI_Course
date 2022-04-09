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
  #include "Lab4.h"
  /* Own headers */
  #include "Sched.h"
  #include "Sched_cfg.h"
  /* **************************************************************** */
  /* *********************** Global ********************************* */
  const Sched_tstrRunnable Sched_astrRunnableList[] = 
  {
    [SCHED_u8LCD_TASK] = 
    {
      .CallbackFn   = LCD_vidMasterLCD_R,
      .CyclicTimeMS = 1
    },
    [SCHED_u8LAB4_TASK] = 
    {
      .CallbackFn   = Lab4_LedControlTask_R,
      .CyclicTimeMS = 20
    }
  };
  /* **************************************************************** */
  