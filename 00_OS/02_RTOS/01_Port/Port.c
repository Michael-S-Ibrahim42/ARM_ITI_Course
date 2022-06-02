/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 27, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port files
** **************************************************************************************/
/* /////////////////////////////////// Headers //////////////////////////////// */
/* LIB */
#include "StdTypes.h"
#include "STM32F401CC.h"
/* MCAL */
#include "Systick.h"
/* Data Structures */
#include "List.h"
/* OS Configurations */
#include "OS_cfg.h"
/* Own */
#include "Port.h"
#include "Port_prv.h"
/* //////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////// Global Variables ////////////////////////// */
extern strTCB_t* OS_pstrReadyList      ; /* linked list */
extern strTCB_t* OS_pstrWaitingList    ; /* linked list */
extern strTCB_t* OS_pstrCurrentTCB     ; /* one node */
extern strTCB_t* OS_pstrHighestReadyTCB; /* one node */
extern enuOS_State_t OS_enuOS_State;
/* //////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////// Interface Fns ////////////////////////// */
/* 
  Description       :       Setup the systick timer
  Parameters        :       void
  Return            :       void
*/
void Port_vidSystickSetup(void)
{
  /* Init the systick timer */
  Systick_enuInit(SYSTICK_u8AHB, SYSTICK_u8ON_INT);
  /* Set the systick callback fn timestamp */
  Systick_enuSetTickTimeMS(OS_u16TICK_TIME);
  /* Registering the systick callback fn */
  Systick_vidRegCallbackFn(Port_vidSystickCallback);
  /* Starting the systick timer */
  Systick_enuStart();/* Starting the systick timer */
}/* Port_vidSystickSetup */
/* //////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////// Private Fns ////////////////////////// */
/* 
  Description       :       Systick callback fn
  Parameters        :       void
  Return            :       void
*/
void Port_vidSystickCallback(void)
{
  /* traverse tasks, decrement ticks
    if task_ticks == 0 --> move it in ready list
    if top of ready pri < current pri ---> move current to ready, make top of ready in highest pointer then Context_Switching
  */
  strTCB_t* Loc_pstrTCB_Traverser = OS_pstrWaitingList; 
  Port_vidDisableInterrupt();
  while(Loc_pstrTCB_Traverser != NULL)
  {
    Loc_pstrTCB_Traverser->WaitTicks--;
    if(Loc_pstrTCB_Traverser->WaitTicks == ZERO_INIT)
    {
      Loc_pstrTCB_Traverser = List_pstrExtractHead(&OS_pstrWaitingList);
      List_vidInsert(&OS_pstrReadyList, Loc_pstrTCB_Traverser, enuOrderType_Pri);
      Loc_pstrTCB_Traverser = OS_pstrWaitingList;
    }/* if */
    else
    {
      Loc_pstrTCB_Traverser = Loc_pstrTCB_Traverser->Next;
    }/* else */
  }/* while */
  if((OS_enuOS_State == enuOS_State_On) && (OS_pstrReadyList != NULL) && (OS_pstrReadyList->TaskPri < OS_pstrCurrentTCB->TaskPri))
  {
    List_vidInsert(&OS_pstrReadyList, OS_pstrCurrentTCB, enuOrderType_Pri);
    OS_pstrHighestReadyTCB = List_pstrExtractHead(&OS_pstrReadyList);
    Port_vidTaskSwitch();
  }/* if */
  Port_vidEnableInterrupt();
}/* Port_vidSystickCallback */
/* //////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////// ISRs ////////////////////////// */
void SVC_Handler(void)
{
  asm("  .align 4     ");
  asm("               ");
  asm("  ldr r0, =OS_pstrCurrentTCB    ");
  asm("  ldr r0, [r0]                  ");
  asm("               ");
  asm("               ");
  asm("               ");
  asm("               ");
}/* SVC_Handler */
void PendSV_Handler(void)
{
  /* Context Switching */


}/* PendSV_Handler */
/* //////////////////////////////////////////////////////////////////////////// */
