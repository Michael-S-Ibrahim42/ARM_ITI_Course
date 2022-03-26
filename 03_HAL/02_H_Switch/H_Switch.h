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
    u16 u16Port;      /* Options in "H_Switch.h", under "Available Ports" section */
    u16 u16Pin;       /* Options in "H_Switch.h", under "Available Pins" section  */
    u8  u8PullRes;    /*  Options in "H_Switch.h", under "Available Pull Resistors" section */
  }H_Switch_tstrSwConfig;
  /* ************************************************************************************** */
  /* ******************************** Arguments MACROs ************************************ */
  /* Available Ports */
  #define H_SWITCH_u16PORT0                     0x0000
  #define H_SWITCH_u16PORT1                     0x0400                   
  #define H_SWITCH_u16PORT2                     0x0800
  #define H_SWITCH_u16PORT3                     0x0C00
  #define H_SWITCH_u16PORT4                     0x1000
  /* Available Pins */
  #define H_SWITCH_u16PIN0                      0x1    
  #define H_SWITCH_u16PIN1                      0x2                  
  #define H_SWITCH_u16PIN2                      0x4
  #define H_SWITCH_u16PIN3                      0x8
  #define H_SWITCH_u16PIN4                      0x10
  #define H_SWITCH_u16PIN5                      0x20
  #define H_SWITCH_u16PIN6                      0x40
  #define H_SWITCH_u16PIN7                      0x80
  #define H_SWITCH_u16PIN8                      0x100
  #define H_SWITCH_u16PIN9                      0x200
  #define H_SWITCH_u16PIN10                     0x400
  #define H_SWITCH_u16PIN11                     0x800
  #define H_SWITCH_u16PIN12                     0x1000
  #define H_SWITCH_u16PIN13                     0x2000
  #define H_SWITCH_u16PIN14                     0x4000
  #define H_SWITCH_u16PIN15                     0x8000
  /* Available Pull Resistors */
  #define H_SWITCH_u8NO_PUPD                    0x00
  #define H_SWITCH_u8PULL_UP                    0x01
  #define H_SWITCH_u8PULL_DOWN                  0x10
  /* Switch Levels */
  #define H_SWITCH_u8LVL_LOW                    0
  #define H_SWITCH_u8LVL_HIGH                   1
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          : Init the switch which is defined by the passed parameter
    Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
    **Caution** : The clock of the GPIO must be enabled before and the configuration files updated
  */
  H_Switch_tenuStatus H_Switch_enuInitSw(void);
  /* 
    Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing
    Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
    Parameter2  : the switch lvl, options are in "H_Switch.h" under the section "Switch Levels"
    Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
    **Caution** : The clock of the GPIO must be enabled before and the switch initialized 
  */
  H_Switch_tenuStatus H_Switch_enuReadSwitch(u8 Copy_u8Switch, pu8 Copy_pu8SwitchLvl);

  /* ************************************************************************************** */








#endif
