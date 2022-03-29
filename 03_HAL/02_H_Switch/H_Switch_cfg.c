/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
/* *************************** Headers inclusion **************************************** */
/* LIB headers */
#include "STD_TYPES.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "H_Switch.h"
#include "H_Switch_cfg.h"
/* *************************** Global Variables ***************************************** */
H_Switch_tstrSwConfig H_Switch_astrSysSwitches[] = {
  [H_SWITCH_u8ON_BTN] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN6,
    .PullRes  = GPIO_u8PULL_UP,
    .OldState = (H_SWITCH_u8PU_STATE&GPIO_u16PIN0)
  },
  [H_SWITCH_u8OFF_BTN] = {
    .Port     = GPIO_u16PORT0,
    .Pin      = GPIO_u16PIN1,
    .PullRes  = GPIO_u8PULL_UP,
    .OldState = (H_SWITCH_u8PU_STATE&GPIO_u16PIN1)
  }
};

/* ************************************************************************************** */
