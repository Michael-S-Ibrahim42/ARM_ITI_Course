/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 27, 2022
**       Version     :	V01
**       SWC         :	Core
**       Description :	Core files
** **************************************************************************************/
/* //////////////////////// Headers ////////////////////////////////// */
/* LIB */
#include "StdTypes.h"
/* Own Headers */
#include "List.h"
#include "Port.h"
#include "Core.h"
#include "Core_cfg.h"
/* //////////////////////////////////////////////////////////////////////// */

/* //////////////////////// Global Variables ///////////////////////////////// */
/* TCB */
u32       OS_TCB_Index = ZERO_INIT;
strTCB_t  OS_astrTCB[OS_u8TASKS_MAX];
strTCB_t* OS_pstrReadyList       = NULL;
strTCB_t* OS_pstrWaitingList     = NULL;
strTCB_t* OS_pstrCurrentTCB      = NULL;
strTCB_t* OS_pstrHighestReadyTCB = NULL;
/* OS start Flag  */ 
/* Indicate the state of OS (started or not started yet) */
u8 OS_u8OS_State = OS_u8OS_OFF;
/* Idle Task stack */
u32 OS_aIdleTaskStack[OS_u16IDLE_TASK_STACK_SIZE];
/* //////////////////////////////////////////////////////////////////////// */

/* //////////////////////// Interface Fns ///////////////////////////////// */
void OS_vidCreateTask(pfTask_t Copy_pfTask, u32 Copy_u32TaskPri, u32* Copy_TaskStack, u32* Copy_TaskStackSize)
{

}/* OS_vidCreateTask */
void OS_vidDelay(u32 Copy_u32WaitTicks)
{

}/* OS_vidDelay */
void OS_vidStart(void)
{

}/* OS_vidStart */
void OS_vidRunIdle_T(void)
{

  while(1)
  {

  }/* while */
}/* OS_vidRunIdle_T */
/* //////////////////////////////////////////////////////////////////////// */
