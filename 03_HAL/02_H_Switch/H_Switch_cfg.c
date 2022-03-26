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
/* Own headers */
#include "H_Switch.h"
#include "H_Switch_cfg.h"
/* ************************************************************************************** */
extern const H_Switch_tstrSwConfig H_Switch_astrSysSwitches[H_SWITCH_u8BTN_NUM];
/* ************************************************************************************** */
/* *************************** Global Variables ***************************************** */
const H_Switch_tstrSwConfig H_Switch_astrSysSwitches[] = {
  [H_SWITCH_u8INC_BTN] = {
    .u16Port    = H_SWITCH_u16PORT0,
    .u16Pin     = H_SWITCH_u16PIN6,
    .u8PullRes  = H_SWITCH_u8PULL_UP
  },
  [H_SWITCH_u8DEC_BTN] = {
    .u16Port    = H_SWITCH_u16PORT0,
    .u16Pin     = H_SWITCH_u16PIN7,
    .u8PullRes  = H_SWITCH_u8PULL_UP
  }
};

/* ************************************************************************************** */
