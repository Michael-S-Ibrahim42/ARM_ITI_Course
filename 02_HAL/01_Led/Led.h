/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	LED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _LED_H
#define _LED_H
  /* ********************************* Inclusion Part ************************************* */
  #include "Led_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Led levels */ 
  #define LED_u8ON                                    0
  #define LED_u8OFF                                   1
  /* led connection active state */                 
  #define LED_u8HIGH_ACTIVE_STATE                     1
  #define LED_u8LOW_ACTIVE_STATE                      0
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Led_enuOk,
    Led_enuNok
  }Led_tenuStatus;
  /* Led Configurations */
  typedef struct
  {
    u16 Port;                /* Options are in "GPIO.h" under "Available Ports"                 */
    u16 Pin;                 /* Options are in "GPIO.h" under "Available Pins"                  */
    u8  ActiveState;         /* Options are in "Led.h" under "led connection active state"    */
    u8  OType;               /* Options are in "GPIO.h" under "Output type"                     */
  }Led_tstrCfg;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn        :   Init the led(s) configurations
    Return    :   Error status of the fn, Error type is in "Led.h" under "Error Type"
  */
  extern Led_tenuStatus Led_enuInit(void);
  /* 
    Fn         :   Set the lvl of specific led number
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
    Parameter2 :   Level of the LED, options are in "Led.h" under "Led levels"
    Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
    **Caution**:   The leds must be initialized using "Led_enuInit"
  */
  extern Led_tenuStatus Led_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl);
  /* ********************************************************************************* */
  /* *********************** Runnables *********************************************** */
  /* 
    Fn         :   Led runnable task
    Parameters :   void
    Return     :   void
    **Caution**:   The leds must be initialized using "Led_enuInit" before calling "Sched_vidStart"
  */  
  extern void Led_vidToggleLed_R(void);
  /* ********************************************************************************* */

#endif