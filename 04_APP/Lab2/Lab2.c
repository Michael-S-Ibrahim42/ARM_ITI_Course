/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 03, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	main file of lab2
** **************************************************************************************/
/* STD headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* HAL headers */
#include "H_Led.h"
#include "Switch.h"
/* OS headers */
#include "Sched.h"
/* main fn */
int main(void)
{
  H_Led_enuInit();
  Switch_enuInit();
  Sched_vidInit();
  Sched_vidStart();
  
  return(0);
}/* main */

void Lab2_LedControlTask(void)
{
  Switch_tenuStatus Loc_enuSwitchStatus;
  Switch_enuGetStatus(SWITCH_u8ON_BTN, &Loc_enuSwitchStatus);
  if(Loc_enuSwitchStatus == Switch_enuPressed)
  {
    H_Led_enuSet(H_LED_u8BLUE, H_LED_u8ON);
  }/* if */
  else
  {
    H_Led_enuSet(H_LED_u8BLUE, H_LED_u8OFF);
  }/* else */
}
