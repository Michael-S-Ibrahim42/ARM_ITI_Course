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
/* MCAL */
/* HAL */
#include "Led.h"
/* Tracing */
#include "diag/Trace.h"
/* /////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Entry Point ////////////////////// */
int main(void)
{

  OS_vidCreateTask()
  OS_vidStart();
  while(1)
  {

  }/* while */

  return(0);
}/* main */