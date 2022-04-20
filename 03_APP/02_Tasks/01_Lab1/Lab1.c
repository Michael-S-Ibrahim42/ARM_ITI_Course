/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	main file of lab1
** **************************************************************************************/
/* STD headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* HAL headers */
#include "H_Led.h"
/* OS headers */
#include "Sched.h"
/* main fn */
int main(void)
{
  H_Led_enuInit();
  Sched_vidInit();
  Sched_vidStart();
  return(0);
}/* main */

