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
  [SWITCH_u8ON_BTN] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN6,
    .PullRes  = GPIO_u8PULL_UP,
    .Status   = Switch_enuReleased
  },
  [SWITCH_u8OFF_BTN] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN1,
    .PullRes  = GPIO_u8PULL_UP,
    .Status   = Switch_enuReleased
  }
};
/* ************************************************************************************** */
