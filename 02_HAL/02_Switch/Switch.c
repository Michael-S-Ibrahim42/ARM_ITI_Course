/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	Switch
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
#include "Switch.h"
#include "Switch_cfg.h"
#include "Switch_prv.h"
/* ************************************************************************************** */
/* ************************** Interface Fns ********************************************* */
/* 
  Fn          : Init the switch which is defined in "H_Switch_cfg.c"
  Return      : The error status of type "Switch_tenuError", exist in "H_Switch.h" under "Error Type"
  **Caution** : The configuration files must be updated
*/
Switch_tenuError Switch_enuInit(void)
{
  Switch_tenuError Loc_enuError = Switch_enuOk; 
  GPIO_tstrPinConfig Loc_astrSwitch;
  u8 Loc_u8Counter;

  /* looping over the switches */
  for(Loc_u8Counter = SWITCH_u8COUNTER_INIT; Loc_u8Counter < SWITCH_u8BTN_NUM; Loc_u8Counter++)
  {
    /* Enabling the clock */
    switch(Switch_astrSwitch[Loc_u8Counter].Port)
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
      Loc_enuError = Switch_enuNok; 
    }/* switch */
    /* Init the Gpio pin */
    Loc_astrSwitch.Mode     = GPIO_u8Input;
    Loc_astrSwitch.OutType  = GPIO_u8NA_TYPE;
    Loc_astrSwitch.OutSpeed = GPIO_u8NA_SPEED;
    Loc_astrSwitch.PullRes  = Switch_astrSwitch[Loc_u8Counter].PullRes;
    Loc_astrSwitch.Pins     = Switch_astrSwitch[Loc_u8Counter].Pin;
    Loc_astrSwitch.Port     = Switch_astrSwitch[Loc_u8Counter].Port;
    GPIO_enuInitPin(&Loc_astrSwitch);
    /* initializing the counter */
    Switch_astrSwitch[Loc_u8Counter].Counter = SWITCH_u8COUNTER_INIT;
  }/* for */

  return(Loc_enuError);/* returning the error status */
}/* Switch_enuInit */
/* 
  Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing
  Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
  Parameter2  : the switch status, options are in "H_Switch.h" under the section "Switch Status"
  Return      : The error status of type "Switch_tenuError", exist in "H_Switch.h" under "Error Type"
  **Caution** : The switch must be initialized 
*/
Switch_tenuError Switch_enuGetStatus(u8 Copy_u8Switch, Switch_tenuStatus* Copy_penuStatus)
{
  Switch_tenuError Loc_enuError = Switch_enuOk; 

  if(Copy_penuStatus != NULL)
  {
    *Copy_penuStatus = Switch_astrSwitch[Copy_u8Switch].Status;
  }/* if */ 
  else
  {
    Loc_enuError = Switch_enuNok;
  }/* else */
  
  return(Loc_enuError);/* returning the error status */  
}/* Switch_enuGetStatus */
/* ************************************************************************************** */
/* ****************************** Runnables ********************************************* */
/* 
  Runnable   :   Update status of the switches
  Parameters :   void
  Return     :   void
  **Caution**:   The switches must be initialized using "Switch_enuInit" before calling "Sched_vidStart"
*/  
void Switch_RUpdateStatus(void)
{
  u16 Loc_u16Reading = SWITCH_u8READING_INIT;/* Variable to receive the immediate reading */
  u8  Loc_u8Iterator = SWITCH_u8COUNTER_INIT;/* Variable to loop over the connected switches */
  GPIO_tstrPin Loc_strPin;/* Structure to get the pin lvl */
  for(Loc_u8Iterator = SWITCH_u8COUNTER_INIT; Loc_u8Iterator < SWITCH_u8BTN_NUM; Loc_u8Iterator++)
  {
    Loc_strPin.Port = Switch_astrSwitch[Loc_u8Iterator].Port;
    Loc_strPin.Pins = Switch_astrSwitch[Loc_u8Iterator].Pin;
    GPIO_enuGetPinValue(&Loc_strPin, &Loc_u16Reading);
    /* CHECK on the switch state and take the suitable action */
    switch(Switch_astrSwitch[Loc_u8Iterator].Status)
    {
    case(Switch_enuReleased):
      /* If pullUp && read = 0 || pulldown && read=1 --->> Counter++ then if(counter==20)--->Status=prepressed
          else ---> Counter = 0 */    
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_UP) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) == 0)) || ((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_DOWN) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) != 0)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PREPRESS_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuPrePressed;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
      }/* else */
      break;
    case(Switch_enuPrePressed):
      /* If pullUp && read = 0 || pulldown && read=1 --->> Counter++ then if(counter==25)--->Status=pressed &  counter=0
      else -->counter=0 & status=Released */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_UP) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) == 0))||((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_DOWN) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) != 0)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PRESS_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuPressed;
          Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuReleased;
      }/* else */
      break;
    case(Switch_enuPressed):
      /* If pullUp && read = 1 || pulldown && read=0 --->> Counter++ then if(counter==20)--->Status=PreReleased
      else -->counter=0  */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_UP) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) != 0))||((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_DOWN) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) == 0)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PRERELEASE_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuPreReleased;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
      }/* else */      
      break;
    case(Switch_enuPreReleased):
      /* If pullUp && read = 1 || pulldown && read=0 --->> Counter++ then if(counter==25)--->Status=released &  counter=0
      else -->counter=0 & status=Pressed */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_UP) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) != 0))||((Switch_astrSwitch[Loc_u8Iterator].PullRes == GPIO_u8PULL_DOWN) && ((Loc_u16Reading&Switch_astrSwitch[Loc_u8Iterator].Pin) == 0)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8RELEASE_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuReleased;
          Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        Switch_astrSwitch[Loc_u8Iterator].Status = Switch_enuPressed;
      }/* else */      
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
  }/* for */
}/* Switch_RUpdateStatus */
/* ************************************************************************************** */