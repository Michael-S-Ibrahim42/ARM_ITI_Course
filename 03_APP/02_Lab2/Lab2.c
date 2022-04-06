/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	main file of lab2
** **************************************************************************************/
/* STD headers */
#include "StdTypes.h"
#include "STM32F401CC.h"
/* HAL headers */
#include "Led.h"
#include "Switch.h"
/* OS headers */
#include "Sched.h"
/* main fn */
int main(void)
{
  Led_enuInit();
  Switch_enuInit();
  Sched_vidInit();
  Sched_vidStart();
  
  return(0);
}/* main */

void Lab2_LedControlTask_R(void)
{
  Switch_tenuStatus Loc_enuSwitchStatus;
  Switch_enuGetStatus(SWITCH_u8BTN, &Loc_enuSwitchStatus);
  if(Loc_enuSwitchStatus == Switch_enuPressed)
  {
    Led_enuSet(LED_u8BLUE, LED_u8ON);
  }/* if */
  else
  {
    Led_enuSet(LED_u8BLUE, LED_u8OFF);
  }/* else */
}
