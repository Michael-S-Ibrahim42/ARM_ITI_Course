/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
/* *************************** Headers inclusion **************************************** */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "Switch.h"
#include "Switch_cfg.h"
/* ************************************************************************************** */
/* *************************** Global Variables ***************************************** */
Switch_tstrConfig Switch_astrSwitch[] = {
  [SWITCH_u8BTN] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN6,
    .PullRes  = GPIO_u8PULL_UP,
    .Status   = Switch_enuReleased
  }
};
/* ************************************************************************************** */