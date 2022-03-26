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
#include "HLED.h"
#include "HLED_cfg.h"
#include "HLED_prv.h"

/* Extern Global */
extern const HLED_tstrCfg HLED_astrLeds[HLED_u8LEDS_NUM];
/* static global */
static H_Led_tpfCallback H_Led_pfCallback;
/* ********************************************************************************* */
/* *************************** Interface Fns *************************************** */
/* 
  Fn        :   Init the specific led configurations
  Return    :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
  **Caution**:  The GPIO clock must be enabled
*/
HLED_tenuStatus HLED_enuInit(void)
{
  HLED_tenuStatus Loc_enuError = HLED_enuOk;
  GPIO_tstrPinConfig Loc_enuLedPinConfig;
  u16 Loc_u8Counter;
  for(Loc_u8Counter = HLED_u8COUNTER_INIT; Loc_u8Counter < HLED_u8LEDS_NUM; Loc_u8Counter++)
  {
    Loc_enuLedPinConfig.Mode = GPIO_u8GP_OUT;
    Loc_enuLedPinConfig.OutType = HLED_astrLeds[Loc_u8Counter].HLED_u8OType;
    Loc_enuLedPinConfig.OutSpeed = GPIO_u8LOW_SPEED;
    Loc_enuLedPinConfig.PullRes = GPIO_u8NO_PUPD;
    Loc_enuLedPinConfig.Pins = HLED_astrLeds[Loc_u8Counter].HLED_u16Pin;
    Loc_enuLedPinConfig.Port = HLED_astrLeds[Loc_u8Counter].HLED_u16Port;
    /* Initializing GPIO */
    GPIO_enuInitPin(&Loc_enuLedPinConfig);
  }/* for */

  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuInit */
/* 
  Fn         :   Set the lvl of specific led number
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "HLED_cfg.h" under "Connected Leds"
  Parameter2 :   Level of the LED, options are in "HLED.h" under "Led levels"
  Return     :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
  **Caution**:  The GPIO clock must be enabled
*/
HLED_tenuStatus HLED_enuSet(u16 Copy_u16LedNum, u8 Copy_u8LedLvl)
{
  HLED_tenuStatus Loc_enuError = HLED_enuOk;
  GPIO_tstrPin Loc_strPin = {
    .Pins = HLED_astrLeds[Copy_u16LedNum].HLED_u16Pin,
    .Port = HLED_astrLeds[Copy_u16LedNum].HLED_u16Port 
  };
  GPIO_enuSetPinValue(&Loc_strPin, (HLED_astrLeds[Copy_u16LedNum].HLED_u8ActiveState ^ Copy_u8LedLvl));
  return(Loc_enuError);/* Returning the error status */
}/* HLED_enuSet */
/* 
  Fn         :   Register the Application callback fn
  Parameter1 :   Address of the callback fn
  Return     :   Error status of the fn, Error type is in "HLED.h" under "Error Type"
*/
void H_Led_vidRegCallbackFn(H_Led_tpfCallback Copy_pfCallback)
{
  if(Copy_pfCallback)
  {
    H_Led_pfCallback = Copy_pfCallback;
  }/* if */
}/* H_Led_vidRegCallbackFn */
/* ********************************************************************************* */
/* ********************************************************************************* */