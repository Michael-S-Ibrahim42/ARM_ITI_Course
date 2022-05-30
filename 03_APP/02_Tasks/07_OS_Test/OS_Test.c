/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 29, 2022
**       Version     :	V01
**       SWC         :	OS_Test
**       Description :	OS Test App layer
** **************************************************************************************/
/* ///////////////////////////// Headers /////////////////////////// */
/* LIB */
#include "StdTypes.h"
/* OS */
#include "Core.h"
#include "List.h"
/* MCAL */
/* HAL */
#include "Led.h"
/* Tracing */
#include "diag/Trace.h"
/* /////////////////////////////////////////////////////////////////// */
extern strTCB_t* OS_pstrReadyList  ;
extern strTCB_t* OS_pstrWaitingList;

/* /////////////////////////// Entry Point ////////////////////// */
int main(void)
{

//  OS_vidCreateTask()
//  OS_vidStart();
  strTCB_t TCB1 = {NULL,NULL,NULL,NULL,NULL,1,100};
  strTCB_t TCB2 = {NULL,NULL,NULL,NULL,NULL,2,200};
  strTCB_t TCB3 = {NULL,NULL,NULL,NULL,NULL,3,300};
  strTCB_t TCB4 = {NULL,NULL,NULL,NULL,NULL,4,400};

  List_vidInsert(&OS_pstrReadyList, &TCB3, enuOrderType_Pri);
  List_vidInsert(&OS_pstrReadyList, &TCB2, enuOrderType_Pri);
  List_vidInsert(&OS_pstrReadyList, &TCB4, enuOrderType_Pri);
  List_vidInsert(&OS_pstrReadyList, &TCB1, enuOrderType_Pri);

  List_pstrExtractHead(&OS_pstrReadyList); 
  List_pstrExtractHead(&OS_pstrReadyList); 
  List_pstrExtractHead(&OS_pstrReadyList); 
  List_pstrExtractHead(&OS_pstrReadyList); 

  List_vidInsert(&OS_pstrWaitingList, &TCB3, enuOrderType_Tick);
  List_vidInsert(&OS_pstrWaitingList, &TCB2, enuOrderType_Tick);
  List_vidInsert(&OS_pstrWaitingList, &TCB4, enuOrderType_Tick);
  List_vidInsert(&OS_pstrWaitingList, &TCB1, enuOrderType_Tick);

  List_pstrExtractHead(&OS_pstrWaitingList); 
  List_pstrExtractHead(&OS_pstrWaitingList); 
  List_pstrExtractHead(&OS_pstrWaitingList); 
  List_pstrExtractHead(&OS_pstrWaitingList); 
  while(1)
  {

  }/* while */

  return(0);
}/* main */
