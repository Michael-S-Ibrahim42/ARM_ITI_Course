/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler module files
** **************************************************************************************/
#ifndef _SCHED_CFG_H
#define _SCHED_CFG_H

  /* *********************** MACROS ********************************* */
  /* The scheduler tick time in milliseconds */
  #define SCHED_u8TICK_MS                           1
  /* The Runnables Priorities, type your Runnables names attached with your selected priority(options are from 0 to 255) */
  #define SCHED_u8LCD_TASK                          0
  #define SCHED_u8LAB4_TASK                         1
  /* Enter the number of runnables */
  #define SCHED_u8RUNN_NUM                          2
  /* **************************************************************** */

#endif