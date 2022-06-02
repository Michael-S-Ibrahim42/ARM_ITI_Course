/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 27, 2022
**       Version     :	V01
**       SWC         :	OS
**       Description :	OS files
** **************************************************************************************/
#ifndef _OS_CFG_H
#define _OS_CFG_H
  /* ///////////////////////////////// MACROS ////////////////////////////// */
  #define OS_u8TASKS_MAX                      ((u8)(10))
  #define OS_u8IDLE_TASK_STACK_SIZE           ((u8)(85))
  #define OS_u16TICK_TIME                     ((u16)(1))
                                                  // /* Define your clock in 'MHZ' */
                                                  // #define OS_u8CPU_CLOCK                      ((u8)(16))
                                                  // /* Define the OS tick rate in 'HZ' */
                                                  // #define OS_u16TICK_RATE                     ((u16)(1000))
  /* /////////////////////////////////////////////////////////////////////// */
#endif