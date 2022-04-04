/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _H_LED_H
#define _H_LED_H
  /* ********************************* Inclusion Part ************************************* */
  #include "H_Led_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Led levels */ 
  #define H_LED_u8ON                                    0
  #define H_LED_u8OFF                                   1
  /* led connection active state */                 
  #define H_LED_u8HIGH_ACTIVE_STATE                     1
  #define H_LED_u8LOW_ACTIVE_STATE                      0
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    H_Led_enuOk,
    H_Led_enuNok
  }H_Led_tenuStatus;
  /* Led Configurations */
  typedef struct
  {
    u16 Port;                /* Options are in "GPIO.h" under "Available Ports"                 */
    u16 Pin;                 /* Options are in "GPIO.h" under "Available Pins"                  */
    u8  ActiveState;         /* Options are in "H_Led.h" under "led connection active state"    */
    u8  OType;               /* Options are in "GPIO.h" under "Output type"                     */
  }H_Led_tstrCfg;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn        :   Init the led(s) configurations
    Return    :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
  */
  extern H_Led_tenuStatus H_Led_enuInit(void);
  /* 
    Fn         :   Set the lvl of specific led number
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "H_Led_cfg.h" under "Connected Leds"
    Parameter2 :   Level of the LED, options are in "H_Led.h" under "Led levels"
    Return     :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
    **Caution**:   The leds must be initialized using "H_Led_enuInit"
  */
  extern H_Led_tenuStatus H_Led_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl);
  /* ********************************************************************************* */
  /* *********************** Runnables *********************************************** */
  /* 
    Fn         :   Led runnable task
    Parameters :   void
    Return     :   void
    **Caution**:   The leds must be initialized using "H_Led_enuInit" before calling "Sched_vidStart"
  */  
  extern void H_Led_vidTask(void);
  /* ********************************************************************************* */
  /* ********************************************************************************* */


#endif