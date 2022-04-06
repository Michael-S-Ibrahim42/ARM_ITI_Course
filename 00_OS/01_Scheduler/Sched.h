/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/
#ifndef _SCHED_H
#define _SCHED_H
  /* ************************ MACROS ******************************** */

  /* **************************************************************** */
  /* ********************* Defined types **************************** */
  /* Error type */
  typedef enum
  {
    Sched_enuOk,
    Sched_enuNok
  }Sched_tenuError;
  /* The runnable type */
  typedef struct
  {
    void (*CallbackFn)(void);
    u32  CyclicTimeMS;
  }Sched_tstrRunnable;
  /* **************************************************************** */
  /* ********************** Interface Fns prototypes **************** */
  /* 
    Fn            :       Init the scheduler           
    Parameters    :       void
    Return        :       void
  */
  void Sched_vidInit(void);
  /* 
    Fn            :       Start the scheduler
    Parameters    :       void
    Return        :       void
    **caution**   :       This is a blocking fn with no return
  */  
  void Sched_vidStart(void);
  /* **************************************************************** */

#endif