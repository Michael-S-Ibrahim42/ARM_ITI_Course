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
#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
//#include "USART.h"
/* Tracing */
#include "diag/Trace.h"
/* Own headers */
#include "OS_Test.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////// MACROS //////////////////////////////////////////////// */
#define SIZE				10
/* /////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Global Variables //////////////////////////////////////// */
/* Tasks Stacks */
u32 T1_Stack[TASK_STACK_SIZE];
u32 T2_Stack[TASK_STACK_SIZE];
// u32 T3_Stack[TASK_STACK_SIZE];
// u32 T4_Stack[TASK_STACK_SIZE];
// u32 T5_Stack[TASK_STACK_SIZE];

strOSSem_t* SemaphorePtr = NULL;
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Entry Point ////////////////////// */
int main(void)
{
  RCC_enuTurnClk(RCC_u8HSI, RCC_enuOn);
  RCC_enuSelectSysClk(RCC_u8RUN_HSI);

  SemaphorePtr = OS_pstrCreateSem(enuSemType_Binary, 0);
  OS_vidCreateTask(T1, 0, T1_Stack, TASK_STACK_SIZE);
  OS_vidCreateTask(T2, 1, T2_Stack, TASK_STACK_SIZE);
  // OS_vidCreateTask(T3, 2, T3_Stack, TASK_STACK_SIZE);
  // OS_vidCreateTask(T4, 3, T4_Stack, TASK_STACK_SIZE);
  // OS_vidCreateTask(T5, 4, T5_Stack, TASK_STACK_SIZE);

  OS_vidStart();

  while(1)
  {

  }/* while */

  return(0);
}/* main */

/* //////////////////////////////////////// Tasks /////////////////////////////////////////// */
void T1(void)
{
	trace_printf("T1 Started\n");
	while(1)
  {
		// trace_printf("T1 give semaphore\n");
    OS_vidGiveSem(SemaphorePtr);
    OS_vidDelay(10000);
  }/* while */
}/* T1 */
void T2(void)
{
	trace_printf("T2 Started\n");
	while(1)
  {
    if(OS_enuTakeSem(SemaphorePtr, 5000))
    {
      trace_printf("T2 took Semaphore\n");
    }
    else
    {
      trace_printf("T2 timeout\n");      
    }
  }/* while */
}/* T2 */
// void T3(void)
// {
// 	trace_printf("T3 Started\n");
// 	while(1)
//   {
// 		trace_printf("T3\n");
//     OS_vidDelay(5000);
//   }/* while */
// }/* T3 */
// void T4(void)
// {
// 	trace_printf("T4 Started\n");
// 	while(1)
//   {
// 		trace_printf("T4\n");
//     OS_vidDelay(5000);
//   }/* while */
// }/* T4 */
// void T5(void)
// {
// 	trace_printf("T5 Started\n");
// 	while(1)
//   {
// 		trace_printf("T5\n");
//     OS_vidDelay(5000);
//   }/* while */
// }/* T5 */
/* ////////////////////////////////////////////////////////////////////////////////////////// */



