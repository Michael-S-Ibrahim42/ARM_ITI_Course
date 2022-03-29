/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
/* ****************************** Headers Inclusion ************************************* */
/* LIB headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "H_Switch.h"
#include "H_Switch_cfg.h"
#include "H_Switch_prv.h"

/* ************************** Interface Fns ********************************************* */
/* 
  Fn          : Init the switch which is defined in "H_Switch_cfg.c"
  Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
  **Caution** : The configuration files updated
*/
H_Switch_tenuStatus H_Switch_enuInitSw(void)
{
  H_Switch_tenuStatus Loc_enuError = H_Switch_enuOk; 
  GPIO_tstrPinConfig Loc_astrSwitch[H_SWITCH_u8BTN_NUM];
  u8 Loc_u8Counter;

  /* looping over the switches */
  for(Loc_u8Counter = 0; Loc_u8Counter < H_SWITCH_u8BTN_NUM; Loc_u8Counter++)
  {
    switch(Loc_astrSwitch[Loc_u8Counter].Port)
    {
    case(GPIO_u16PORT0):
      RCC_enuPerClk(RCC_enuGPIOA, RCC_enuOn);
      break;
    case(GPIO_u16PORT1):
      RCC_enuPerClk(RCC_enuGPIOB, RCC_enuOn);
      break;
    case(GPIO_u16PORT2):
      RCC_enuPerClk(RCC_enuGPIOC, RCC_enuOn);
      break;
    case(GPIO_u16PORT3):
      RCC_enuPerClk(RCC_enuGPIOD, RCC_enuOn);
      break;
    default:
      Loc_enuError = H_Switch_enuNok; 
    }/* switch */
    Loc_astrSwitch[Loc_u8Counter].Mode     = GPIO_u8Input;
    Loc_astrSwitch[Loc_u8Counter].OutType  = GPIO_u8NA_TYPE;
    Loc_astrSwitch[Loc_u8Counter].OutSpeed = GPIO_u8NA_SPEED;
    Loc_astrSwitch[Loc_u8Counter].PullRes  = H_Switch_astrSysSwitches[Loc_u8Counter].PullRes;
    Loc_astrSwitch[Loc_u8Counter].Pins     = H_Switch_astrSysSwitches[Loc_u8Counter].Pin;
    Loc_astrSwitch[Loc_u8Counter].Port     = H_Switch_astrSysSwitches[Loc_u8Counter].Port;
    GPIO_enuInitPin(&Loc_astrSwitch[Loc_u8Counter]);
  }/* for */

  return(Loc_enuError);/* returning the error status */
}/* H_Switch_enuInitSw */

/* 
  Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing
  Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
  Parameter2  : the switch lvl, options are in "H_Switch.h" under the section "Switch Levels"
  Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
  **Caution** : The switch must be initialized 
*/
H_Switch_tenuStatus H_Switch_enuReadSwitch(u8 Copy_u8Switch, pu8 Copy_pu8SwitchLvl)
{
  H_Switch_tenuStatus Loc_enuError = H_Switch_enuOk; 
  GPIO_tstrPin Loc_strSwitch;
  u16 Loc_u16ReturnVal, Loc_u16TempReturnVal, Loc_u8DebFlag = H_SWITCH_u8FLAG_LOW;
  u32 Loc_u32DelayCounter = H_SWITCH_u32COUNTER_START;

  Loc_strSwitch.Pins = H_Switch_astrSysSwitches[Copy_u8Switch].Pin;
  Loc_strSwitch.Port = H_Switch_astrSysSwitches[Copy_u8Switch].Port;
  Loc_u32DelayCounter = H_SWITCH_u32COUNTER_START;
  while(!Loc_u8DebFlag)/* Loop to over the debouncing */
  {
    GPIO_enuGetPinValue(&Loc_strSwitch, &Loc_u16ReturnVal);
    Loc_u16TempReturnVal = Loc_u16ReturnVal & Loc_strSwitch.Pins;
    /* Delay for some time to check on debouncing */
    if((Loc_u16TempReturnVal == H_Switch_astrSysSwitches[Copy_u8Switch].OldState) && (Loc_u32DelayCounter > H_SWITCH_u32COUNTER_START))
    {
      Loc_u32DelayCounter--;
    }/* if */
    else if(Loc_u16TempReturnVal != H_Switch_astrSysSwitches[Copy_u8Switch].OldState)
    {
      Loc_u32DelayCounter++;
    }/* else if */
    if((Loc_u32DelayCounter == H_SWITCH_u32COUNTER_START) || (Loc_u32DelayCounter >= H_SWITCH_u32COUNTER_END))
    {
      H_Switch_astrSysSwitches[Copy_u8Switch].OldState = Loc_u16TempReturnVal;
      Loc_u8DebFlag = H_SWITCH_u8FLAG_HIGH;
    }
  }/* while */

  /* Setting the switch lvl */
  if(Loc_u16TempReturnVal == H_SWITCH_u8ZERO_COMP)
  {
    *Copy_pu8SwitchLvl = H_SWITCH_u8LVL_LOW;
  }/* if */
  else
  {
    *Copy_pu8SwitchLvl = H_SWITCH_u8LVL_HIGH;
  }/* else */

  return(Loc_enuError);/* returning the error status */  
}/* H_Switch_enuReadSwitch */
/* ************************************************************************************** */
