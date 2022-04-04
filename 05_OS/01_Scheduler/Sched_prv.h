/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/
#ifndef _SCHED_PRV_H
#define _SCHED_PRV_H
  /* ************************ Global Externing  ****************************************** */
  extern const Sched_tstrRunnable Sched_astrRunnableList[SCHED_u8RUNN_NUM];
  /* ************************************************************************************* */
  /* ************************ MACROS ***************************************************** */
  /* Tick flag states */
  #define SCHED_u8FlagLowered                               0
  #define SCHED_u8FlagRaised                                1
  /* initialize value */
  #define SCHED_u8ZERO_INIT                                 0
  /* ************************************************************************************* */
  /* ************************ Static fns prototypes ***************** */
  /* 
    Fn            :       static fn, used as the systick callback fn
    Parameters    :       void
    Return        :       void
  */
  static void Sched_vidTickCBF(void);
  /* 
    Fn            :       static fn, used to determine which runnable should be called at the current timestamp and call it
    Parameters    :       void
    Return        :       void
  */
  static void Sched_vidSchedule(void);  
  /* **************************************************************** */

#endif