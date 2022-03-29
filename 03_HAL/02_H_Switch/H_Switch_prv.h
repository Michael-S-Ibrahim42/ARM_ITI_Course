/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _H_SWITCH_PRV_H
#define _H_SWITCH_PRV_H

  /* **************************** MACROS ************************************************** */
  /* Flag Values */
  #define H_SWITCH_u8FLAG_LOW                             0
  #define H_SWITCH_u8FLAG_HIGH                            1
  /* Zero Comparator */
  #define H_SWITCH_u8ZERO_COMP                            0
  /* Delay Counter values */
  #define H_SWITCH_u32COUNTER_START                        0
  #define H_SWITCH_u32COUNTER_END                          10000
  /* ************************************************************************************** */
  /* ****************************** Global variables  ************************************* */
  extern H_Switch_tstrSwConfig H_Switch_astrSysSwitches[H_SWITCH_u8BTN_NUM];
  /* ************************************************************************************** */













#endif
