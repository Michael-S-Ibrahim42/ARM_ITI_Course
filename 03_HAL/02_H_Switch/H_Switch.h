/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _H_SWITCH_H
#define _H_SWITCH_H
  /* ********************************* Inclusion Part ************************************* */
  #include "H_Switch_cfg.h"
  /* ************************************************************************************** */

  /* ********************************* Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    H_Switch_enuOk,
    H_Switch_enuNok
  }H_Switch_tenuStatus;
  /* Switch Config */
  typedef struct
  {
    u16 Port;       /* Options in "GPIO.h", under "Available Ports" section */
    u16 Pin;        /* Options in "GPIO.h", under "Available Pins" section  */
    u8  PullRes;    /*  Options in "GPIO.h", under "Available Pull Resistors" section */
    u8  OldState;   /*  Options in "H_Switch.h", under "Switch Old States" section, put the selection 'anding' with your pins selection */
  }H_Switch_tstrSwConfig;
  /* ************************************************************************************** */
  /* ******************************** Arguments MACROs ************************************ */
  /* Switch Levels */
  #define H_SWITCH_u8LVL_LOW                    0
  #define H_SWITCH_u8LVL_HIGH                   1
  /* Switch Old States */
  #define H_SWITCH_u8PU_STATE                             0x0000FFFF
  #define H_SWITCH_u8PD_STATE                             0x0
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          : Init the switch which is defined in "H_Switch_cfg.c"
    Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
    **Caution** : The configuration files updated
  */
  H_Switch_tenuStatus H_Switch_enuInitSw(void);
  /* 
    Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing
    Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
    Parameter2  : the switch lvl, options are in "H_Switch.h" under the section "Switch Levels"
    Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
    **Caution** : The switch must be initialized 
  */
  H_Switch_tenuStatus H_Switch_enuReadSwitch(u8 Copy_u8Switch, pu8 Copy_pu8SwitchLvl);

  /* ************************************************************************************** */








#endif
