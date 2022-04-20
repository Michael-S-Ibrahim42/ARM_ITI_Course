/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 18, 2022
**       Version     :	V01
**       SWC         :	IntSwitch
**       Description :	IntSwitch module files
** **************************************************************************************/
/* //////////////////////////////// Headers inclusion ///////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "EXTI.h"
/* Own headers */
#include "IntSwitch.h"
#include "IntSwitch_cfg.h"
#include "IntSwitch_prv.h"
/* //////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Global Variables ////////////////////////////////// */
IntSwitch_tenuState IntSwitch_enuState[INTSWITCH_u8SW_NUM] = IntSwitch_enuReleased;
/* //////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Interface Fns ///////////////////////////////////// */
/* 
  Description         :       Get switch state
  Parameter1          :       
  Parameter2          :       
  Return              :       void
*/
IntSwitch_tenuStatus IntSwitch_enuGetState(u8 Copy_u8SwitchID, IntSwitch_tenuState* Copy_penuState)
{
  IntSwitch_tenuStatus Loc_enuStatus = IntSwitch_enuOk;

  *Copy_penuState = IntSwitch_enuState[Copy_u8SwitchID];

  return(Loc_enuStatus);
}/* IntSwitch_enuGetState */
/* //////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Callback Fn /////////////////////////////////////// */
/* 
  Description         :       Callback fn, it is called on the falling edge interrupt
  Parameter(s)        :       void
  Return              :       void
*/
void IntSwitch_vidPressedCallback(void)
{
  IntSwitch_enuState = IntSwitch_enuPressed;
}/* IntSwitch_vidCallbackFn */
/* 
  Description         :       Callback fn, it is called on the rising edge interrupt
  Parameter(s)        :       void
  Return              :       void
*/
void IntSwitch_vidReleasedCallback(void)
{
  IntSwitch_enuState = IntSwitch_enuReleased;
}/* IntSwitch_vidCallbackFn */
/* //////////////////////////////////////////////////////////////////////////////////// */