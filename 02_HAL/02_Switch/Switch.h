/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _SWITCH_H
#define _SWITCH_H
  /* ********************************* Inclusion Part ************************************* */
  #include "Switch_cfg.h"
  /* ************************************************************************************** */
  /* ********************************* Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Switch_enuOk,
    Switch_enuNok
  }Switch_tenuError;
  /* Switch Status */
  typedef enum
  {
    Switch_enuPrePressed,
    Switch_enuPressed,
    Switch_enuPreReleased,
    Switch_enuReleased
  }Switch_tenuStatus;
  /* Switch Config */
  typedef struct
  {
    u16                Port;       /*  Options in "GPIO.h", under "Available Ports" section            */
    u16                Pin;        /*  Options in "GPIO.h", under "Available Pins" section             */
    u8                 PullRes;    /*  Options in "GPIO.h", under "Available Pull Resistors" section   */
    Switch_tenuStatus  Status;     /*  Options in "H_Switch.h", under "Switch Status" section          */
    u8                 Counter;    /*  hold the value from 0 to 5 */
  }Switch_tstrConfig;
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          : Init the switch which is defined in "H_Switch_cfg.c"
    Return      : The error status of type "Switch_tenuError", exist in "H_Switch.h" under "Error Type"
    **Caution** : The configuration files must be updated
  */
  extern Switch_tenuError Switch_enuInit(void);
  /* 
    Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing
    Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
    Parameter2  : the switch status, options are in "H_Switch.h" under the section "Switch Status"
    Return      : The error status of type "Switch_tenuError", exist in "H_Switch.h" under "Error Type"
    **Caution** : The switch must be initialized 
  */
  extern Switch_tenuError Switch_enuGetStatus(u8 Copy_u8Switch, Switch_tenuStatus* Copy_penuStatus);
  /* ************************************************************************************** */
  /* ****************************** Runnables ********************************************* */
  /* 
    Runnable   :   Update status of the switches
    Parameters :   void
    Return     :   void
    **Caution**:   The switches must be initialized using "Switch_enuInit" before calling "Sched_vidStart"
  */  
  extern void Switch_vidUpdateStatus_R(void);
  /* ************************************************************************************** */

#endif