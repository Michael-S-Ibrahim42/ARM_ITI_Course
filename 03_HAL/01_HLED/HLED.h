/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _HLED_H
#define _HLED_H
  /* ********************************* Inclusion Part ************************************* */
  #include "HLED_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Output type */
  #define HLED_u8OTYPE_PP             0
  #define HLED_u8OTYPE_OD             1
  /* Led levels */
  #define HLED_u8ON                   0
  #define HLED_u8OFF                  1
  /* led connection active state */
  #define HLED_u8HIGH_ACTIVE_STATE    1
  #define HLED_u8LOW_ACTIVE_STATE     0
  /* Available Ports */
  #define HLED_u16PORT0                     0x0000
  #define HLED_u16PORT1                     0x0400                   
  #define HLED_u16PORT2                     0x0800
  #define HLED_u16PORT3                     0x0C00
  #define HLED_u16PORT4                     0x1000
  /* Available Pins */
  #define HLED_u16PIN0                      0x1    
  #define HLED_u16PIN1                      0x2                  
  #define HLED_u16PIN2                      0x4
  #define HLED_u16PIN3                      0x8
  #define HLED_u16PIN4                      0x10
  #define HLED_u16PIN5                      0x20
  #define HLED_u16PIN6                      0x40
  #define HLED_u16PIN7                      0x80
  #define HLED_u16PIN8                      0x100
  #define HLED_u16PIN9                      0x200
  #define HLED_u16PIN10                     0x400
  #define HLED_u16PIN11                     0x800
  #define HLED_u16PIN12                     0x1000
  #define HLED_u16PIN13                     0x2000
  #define HLED_u16PIN14                     0x4000
  #define HLED_u16PIN15                     0x8000  
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Notify pointer to fn type */
  typedef void (*H_Led_tpfCallback)(void);
  /* Error Type */
  typedef enum
  {
    HLED_enuOk,
    HLED_enuNok
  }HLED_tenuStatus;
  /* Led Configurations */
  typedef struct
  {
    u16 HLED_u16Port;               /* Options are in "HLED.h" under "Available Ports" */
    u16 HLED_u16Pin;                /* Options are in "HLED.h" under "Available Pins" */
    u8  HLED_u8ActiveState;         /* Options are in "HLED.h" under "led connection active state" */
    u8  HLED_u8OType;               /* Options are in "HLED.h" under "Output type" */
  }HLED_tstrCfg;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn        :   Init the specific led configurations
    Return    :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
    **Caution**:  The GPIO clock must be enabled
  */
  extern HLED_tenuStatus HLED_enuInit(void);
  /* 
    Fn         :   Set the lvl of specific led number
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "HLED_cfg.h" under "Connected Leds"
    Parameter2 :   Level of the LED, options are in "HLED.h" under "Led levels"
    Return     :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
    **Caution**:  The GPIO clock must be enabled
  */
  extern HLED_tenuStatus HLED_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl);
  /* 
    Fn         :   Register the Application callback fn
    Parameter1 :   Address of the callback fn
    Return     :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
  */
  extern void H_Led_vidRegCallbackFn(H_Led_tpfCallback Copy_pfCallback);
  /* ********************************************************************************* */
  /* ********************************************************************************* */


#endif