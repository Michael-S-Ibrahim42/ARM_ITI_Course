/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _SWITCH_PRV_H
#define _SWITCH_PRV_H
  /* ****************************** MACROS  *********************************************** */
  /* Initial Values */
  #define SWITCH_u8MAX_SWITCHES                                       255
  #define SWITCH_u8READING_INIT                                       0
  #define SWITCH_u8COUNTER_INIT                                       0
  /* Entry Levels */
  #define SWITCH_u8PREPRESS_ENTRY                                     3
  #define SWITCH_u8PRESS_ENTRY                                        5
  #define SWITCH_u8PRERELEASE_ENTRY                                   3
  #define SWITCH_u8RELEASE_ENTRY                                      5
  /* ************************************************************************************** */
  /* ****************************** Global variables  ************************************* */
  extern Switch_tstrConfig Switch_astrSwitch[SWITCH_u8BTN_NUM];
  /* ************************************************************************************** */

#endif
