/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 12, 2022
**       Version     :	V01
**       SWC         :	GPIO
**       Description :	GPIO module files
** **************************************************************************************/
#ifndef _GPIO_H
#define _GPIO_H


  /* ******************************************************************************** */
  /* *********************** Defined Types ****************************************** */
  /* Error Types */
  typedef enum
  {
    GPIO_enuOk = 0,
    GPIO_enuNok
  }GPIO_tenuStatus;
  /* Pin Level */
  typedef enum
  {
    GPIO_enuLow = 0,
    GPIO_enuHigh
  }GPIO_tenuPinLevel;
  typedef struct
  {
    u8  Mode;       /* select of the 'Available Modes' in GPIO.h          , under 'STD types options' section*/
    u8  OutType;    /* select of the 'Available Out Types' in GPIO.h      , under 'STD types options' section */
    u8  OutSpeed;   /* select of the 'Available Out Speed' in GPIO.h      , under 'STD types options' section  */
    u8  PullRes;    /* select of the 'Available Pull Resistors' in GPIO.h , under 'STD types options' section*/
    u16 Pins;       /* select of the 'Available Pins' in GPIO.h           , under 'STD types options' section*/
    u16 Port;       /* select of the 'Available Ports' in GPIO.h          , under 'STD types options' section*/
  }GPIO_tstrPinConfig;
  /* Pins selection structure */
  typedef struct 
  {
    u16 Pins;       /* select of the 'Available Pins' in GPIO.h           , under 'STD types options' section*/
    u16 Port;       /* select of the 'Available Ports' in GPIO.h          , under 'STD types options' section*/
  }GPIO_tstrPin;
  /* ********************************************************************************* */
  /* *********************** STD types options *************************************** */
  /* Available Modes */
  #define GPIO_u8Input                      0x00
  #define GPIO_u8GP_OUT                     0x01
  #define GPIO_u8AF                         0x10
  #define GPIO_u8ANALOG                     0x11
  /* Available Out Types */
  #define GPIO_u8PUSH_PULL                  0x0 
  #define GPIO_u8OPEN_DRAIN                 0x1
  #define GPIO_u8NA_TYPE                    0x10  /* select it in case of being input */
  /* Available Out Speed */
  #define GPIO_u8LOW_SPEED                  0x000
  #define GPIO_u8MEDIUM_SPEED               0x001
  #define GPIO_u8HIGH_SPEED                 0x010
  #define GPIO_u8VERY_HIGH_SPEED            0x011
  #define GPIO_u8NA_SPEED                   0x000 /* select it in case of being input */
  /* Available Pull Resistors */
  #define GPIO_u8NO_PUPD                    0x00
  #define GPIO_u8PULL_UP                    0x01
  #define GPIO_u8PULL_DOWN                  0x10
  /* Available Ports */
  #define GPIO_u16PORT0                     0x0000
  #define GPIO_u16PORT1                     0x0400                   
  #define GPIO_u16PORT2                     0x0800
  #define GPIO_u16PORT3                     0x0C00
  #define GPIO_u16PORT4                     0x1000
  /* Available Pins */
  #define GPIO_u16PIN0                      0x1    
  #define GPIO_u16PIN1                      0x2                  
  #define GPIO_u16PIN2                      0x4
  #define GPIO_u16PIN3                      0x8
  #define GPIO_u16PIN4                      0x10
  #define GPIO_u16PIN5                      0x20
  #define GPIO_u16PIN6                      0x40
  #define GPIO_u16PIN7                      0x80
  #define GPIO_u16PIN8                      0x100
  #define GPIO_u16PIN9                      0x200
  #define GPIO_u16PIN10                     0x400
  #define GPIO_u16PIN11                     0x800
  #define GPIO_u16PIN12                     0x1000
  #define GPIO_u16PIN13                     0x2000
  #define GPIO_u16PIN14                     0x4000
  #define GPIO_u16PIN15                     0x8000
                                            
  
  /* ********************************************************************************* */
  /* *********************** Fns Prototypes ****************************************** */
  /* 
    Fn: Init the passed pin(s) configurations
    Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Defined Types' section
    Parameter: 'GPIO_tstrPinConfig' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
  */
  GPIO_tenuStatus GPIO_enuInitPin(GPIO_tstrPinConfig* Copy_pstrPinConfig);
  /* 
    Fn: set the passed pin value
    Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Defined Types' section
    Parameter1: 'GPIO_tstrPin' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
    Parameter2: 'GPIO_tenuPinLevel' enum defining the level, possible values are in GPIO.h under 'Defined Types' section
  */
  GPIO_tenuStatus GPIO_enuSetPinValue(GPIO_tstrPin* Copy_pstrPin, GPIO_tenuPinLevel Copy_enuPinLevel);
  /* 
    Fn: set and reset the passed pins
    Return:     'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
    Parameter1: 'GPIO_tstrPin' structure defining the pins to be set, possible values are in GPIO.h under 'Pins selection structure' section
    Parameter2: 'GPIO_tstrPin' structure defining the pins to be reset, possible values are in GPIO.h under 'Pins selection structure' section
  */
  GPIO_tenuStatus GPIO_enuSetResetPins(GPIO_tstrPin* Copy_pstrSetPins, GPIO_tstrPin* Copy_pstrResetPins);
  /* 
    Fn: return the passed pin input value
    Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
    Parameter1: 'GPIO_tstrPin' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
    Parameter2: pointer to u8 variable to store the pin value
  */
  GPIO_tenuStatus GPIO_enuGetPinValue(GPIO_tstrPin* Copy_pstrPin, pu16 Copy_pu16PinValue);
  /* 
    Fn: Lock the passed pins configuration tell next reset
    Return:     'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
    Parameter1: 'GPIO_tstrPin' structure defining the pins, possible values are in GPIO.h under 'Pins selection structure' section
  */
  GPIO_tenuStatus GPIO_enuLockPinConfig(GPIO_tstrPin* Copy_pstrPin);
  /* 
    Fn        :  Select the pin alternate function
    Return    :  'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
    Parameter1:  'GPIO_tstrPin' structure defining the pins, possible values are in GPIO.h under 'Pins selection structure' section
    Parameter2:  The alternate function number, options are from 0(defaule=GPIO) to 15 
  */
  GPIO_tenuStatus GPIO_enuSelectAF(GPIO_tstrPin* Copy_pstrPin, u8 Copy_u8AF);

  /* ********************************************************************************* */
  /* ********************************************************************************* */

#endif