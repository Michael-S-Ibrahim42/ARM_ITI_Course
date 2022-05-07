/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	LED
**       Description :	Led module files
** **************************************************************************************/
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "StdTypes.h"
#include "STM32F401CC.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "Led.h"
#include "Led_cfg.h"
#include "Led_prv.h"

/* *************************** Interface Fns *************************************** */
/* 
  Fn        :   Init the led(s) configurations
  Return    :   Error status of the fn, Error type is in "Led.h" under "Error Type"
*/
Led_tenuStatus Led_enuInit(void)
{
  Led_tenuStatus Loc_enuError = Led_enuOk;
  GPIO_tstrPinConfig Loc_enuLedPinConfig;
  u16 Loc_u8Counter;
  for(Loc_u8Counter = LED_u8COUNTER_INIT; Loc_u8Counter < LED_u16LEDS_NUM; Loc_u8Counter++)
  {
    switch(Led_astrLeds[Loc_u8Counter].Port)
    {
    case(GPIO_u16PORT0):
      RCC_enuPerClk(RCC_enuGPIOA, RCC_enuOn);
      break;
    case(GPIO_u16PORT1):
      RCC_enuPerClk(RCC_enuGPIOB, RCC_enuOn);
      break;
    case(GPIO_u16PORT2):
      RCC_enuPerClk(RCC_enuGPIOC, RCC_enuOn);
      break;
    case(GPIO_u16PORT3):
      RCC_enuPerClk(RCC_enuGPIOD, RCC_enuOn);
      break;
    default:
      Loc_enuError = Led_enuNok; 
    }/* switch */
    Loc_enuLedPinConfig.Mode = GPIO_u8GP_OUT;
    Loc_enuLedPinConfig.OutType = Led_astrLeds[Loc_u8Counter].OType;
    Loc_enuLedPinConfig.OutSpeed = GPIO_u8LOW_SPEED;
    Loc_enuLedPinConfig.PullRes = GPIO_u8NO_PUPD;
    Loc_enuLedPinConfig.Pins = Led_astrLeds[Loc_u8Counter].Pin;
    Loc_enuLedPinConfig.Port = Led_astrLeds[Loc_u8Counter].Port;
    /* Initializing GPIO */
    GPIO_enuInitPin(&Loc_enuLedPinConfig);
  }/* for */

  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuInit */
/* 
  Fn         :   Set the lvl of specific led number
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
  Parameter2 :   Level of the LED, options are in "Led.h" under "Led levels"
  Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
  **Caution**:   The leds must be initialized using "Led_enuInit"
*/
Led_tenuStatus Led_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl)
{
  Led_tenuStatus Loc_enuError = Led_enuOk;
  GPIO_tstrPin Loc_strPin = {
    .Pins = Led_astrLeds[Copy_u16LedNum].Pin,
    .Port = Led_astrLeds[Copy_u16LedNum].Port 
  };
  GPIO_enuSetPinValue(&Loc_strPin, (Led_astrLeds[Copy_u16LedNum].ActiveState ^ Copy_u8LedLvl));
  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuSet */
/* ********************************************************************************* */
/* *********************** Runnables *********************************************** */
/* 
  Fn         :   Led runnable task
  Parameters :   void
  Return     :   void
  **Caution**:   The leds must be initialized using "Led_enuInit" before calling "Sched_vidStart"
*/  
void Led_vidToggleLed_R(void)
{
  static u8 Loc_u8LedLvl = LED_u8ON;
  Led_enuSet(LED_u8MIL, Loc_u8LedLvl);
  Loc_u8LedLvl ^= LED_u8OFF;
}
