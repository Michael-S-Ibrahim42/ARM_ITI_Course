/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
/* *************************** Headers inclusion **************************************** */
/* LIB headers */
#include "STD_TYPES.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "Switch.h"
#include "Switch_cfg.h"
/* ************************************************************************************** */
/* *************************** Global Variables ***************************************** */
Switch_tstrConfig Switch_astrSwitch[] = {
  [SWITCH_u8IGNITION] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN3,
    .PullRes  = GPIO_u8PULL_UP,
    .Status   = Switch_enuReleased
  },
  [SWITCH_u8DOOR] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN4,
    .PullRes  = GPIO_u8PULL_UP,
    .Status   = Switch_enuReleased
  }
};
/* ************************************************************************************** */
  
      