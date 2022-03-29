/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
/* ********************************************************************************* */
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "H_LED.h"
#include "H_LED_cfg.h"
#include "H_LED_prv.h"

/* *************************** Interface Fns *************************************** */
/* 
  Fn        :   Init the led(s) configurations
  Return    :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
*/
H_Led_tenuStatus H_Led_enuInit(void)
{
  H_Led_tenuStatus Loc_enuError = H_Led_enuOk;
  GPIO_tstrPinConfig Loc_enuLedPinConfig;
  u16 Loc_u8Counter;
  for(Loc_u8Counter = H_LED_u8COUNTER_INIT; Loc_u8Counter < H_LED_u16LEDS_NUM; Loc_u8Counter++)
  {
    switch(H_Led_astrLeds[Loc_u8Counter].Port)
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
      Loc_enuError = H_Led_enuNok; 
    }/* switch */
    Loc_enuLedPinConfig.Mode = GPIO_u8GP_OUT;
    Loc_enuLedPinConfig.OutType = H_Led_astrLeds[Loc_u8Counter].OType;
    Loc_enuLedPinConfig.OutSpeed = GPIO_u8LOW_SPEED;
    Loc_enuLedPinConfig.PullRes = GPIO_u8NO_PUPD;
    Loc_enuLedPinConfig.Pins = H_Led_astrLeds[Loc_u8Counter].Pin;
    Loc_enuLedPinConfig.Port = H_Led_astrLeds[Loc_u8Counter].Port;
    /* Initializing GPIO */
    GPIO_enuInitPin(&Loc_enuLedPinConfig);
  }/* for */

  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuInit */
/* 
  Fn         :   Set the lvl of specific led number
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "H_Led_cfg.h" under "Connected Leds"
  Parameter2 :   Level of the LED, options are in "H_Led.h" under "Led levels"
  Return     :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
  **Caution**:   The leds must be initialized using "H_Led_enuInit"
*/
H_Led_tenuStatus H_Led_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl)
{
  H_Led_tenuStatus Loc_enuError = H_Led_enuOk;
  GPIO_tstrPin Loc_strPin = {
    .Pins = H_Led_astrLeds[Copy_u16LedNum].Pin,
    .Port = H_Led_astrLeds[Copy_u16LedNum].Port 
  };
  GPIO_enuSetPinValue(&Loc_strPin, (H_Led_astrLeds[Copy_u16LedNum].ActiveState ^ Copy_u8LedLvl));
  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuSet */
/* ********************************************************************************* */