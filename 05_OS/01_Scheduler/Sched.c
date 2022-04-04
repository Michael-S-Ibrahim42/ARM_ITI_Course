/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/
/* ********************** Headers inclusion ******************************************* */
/* LIB headers */
#include "STD_TYPES.h"
/* MCAL headers */
#include "M_Systick.h"
/* Own headers */
#include "Sched.h"
#include "Sched_cfg.h"
#include "Sched_prv.h"
/* ************************************************************************************* */
/* ***************************** Global ************************************************ */
/* The Tick Firing flag */
u8 Sched_u8TickFiring = SCHED_u8FlagLowered; /* Initially the flag is lowered */
/* ************************************************************************************* */
/* ********************** Interface Fns **************************************************** */
/* 
  Fn            :       Init the scheduler           
  Parameters    :       void
  Return        :       void
*/
void Sched_vidInit(void)
{
  /* Init the systick timer */
  M_Systick_enuInit(M_SYSTICK_u8AHB, M_SYSTICK_u8ON_INT);
  /* Set the systick callback fn timestamp */
  M_Systick_enuSetTickTimeMS(SCHED_u8TICK_MS);
  /* Registering the systick callback fn */
  M_Systick_vidRegCallbackFn(Sched_vidTickCBF);
}/* Sched_vidInit */
/* 
  Fn            :       Start the scheduler
  Parameters    :       void
  Return        :       void
  **caution**   :       This is a blocking fn with no return
*/  
void Sched_vidStart(void)
{
  M_Systick_enuStart();/* Starting the systick timer */
  while(TRUE)
  {
    if(Sched_u8TickFiring)/* If the flag has been raised by the systick callback fn*/
    {
      Sched_u8TickFiring = SCHED_u8FlagLowered;/* Lowering the flag again */
      Sched_vidSchedule();/* calling the schedule Fn to call the runnable in turn */
    }/* if */
  }/* while */
}/* Sched_vidStart */

/* ************************ Static fns ***************************************************** */
/* 
  Fn            :       static fn, used as the systick callback fn
  Parameters    :       void
  Return        :       void
*/
static void Sched_vidTickCBF(void)
{
  Sched_u8TickFiring = SCHED_u8FlagRaised;
}/* Sched_vidTickCBF */
/* 
  Fn            :       static fn, used to determine which runnable should be called at the current timestamp and call it
  Parameters    :       void
  Return        :       void
*/
static void Sched_vidSchedule(void)
{
  static u32 Loc_u32TimeMS = SCHED_u8ZERO_INIT;
  u8 Loc_u8Index;

  for(Loc_u8Index = SCHED_u8ZERO_INIT; Loc_u8Index < SCHED_u8RUNN_NUM; Loc_u8Index++)/* looping over the runnables list */
  {
    if(Loc_u32TimeMS%Sched_astrRunnableList[Loc_u8Index].CyclicTimeMS == ZERO_REM)/* checking if the runnable should be run or not */
    {
      (Sched_astrRunnableList[Loc_u8Index].CallbackFn)();/* calling the runnable */
    }/* if */
  }/* for */
  Loc_u32TimeMS += SCHED_u8TICK_MS;
}/* Sched_vidSchedule */  