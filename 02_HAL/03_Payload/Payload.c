/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 05, 2022
**       Version     :	V01
**       SWC         :	Payload
**       Description :	Payload module files
** **************************************************************************************/
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "STD_TYPES.h"
#include "STM32F401CC.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "Payload.h"
#include "Payload_cfg.h"
#include "Payload_prv.h"

/* *************************** Interface Fns *************************************** */
/* 
  Fn        :   Init the Payload(s) configurations
  Return    :   Error status of the fn, Error type is in "Payload.h" under "Error Type"
*/
Payload_tenuError Payload_enuInit(void)
{
  Payload_tenuError Loc_enuError = Payload_enuOk;
  GPIO_tstrPinConfig Loc_strPinConfig;
  u16 Loc_u8Counter;
  for(Loc_u8Counter = PAYLOAD_u8COUNTER_INIT; Loc_u8Counter < PAYLOAD_u8PAYLOADS_NUM; Loc_u8Counter++)
  {
    switch(Payload_astrPayloadsSpecs[Loc_u8Counter].Port)
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
      Loc_enuError = Payload_enuNok; 
    }/* switch */
    Loc_strPinConfig.Mode      = GPIO_u8GP_OUT;
    Loc_strPinConfig.OutType   = GPIO_u8PUSH_PULL;
    Loc_strPinConfig.OutSpeed  = GPIO_u8LOW_SPEED;
    Loc_strPinConfig.PullRes   = GPIO_u8NO_PUPD;
    Loc_strPinConfig.Pins      = Payload_astrPayloadsSpecs[Loc_u8Counter].Pin;
    Loc_strPinConfig.Port      = Payload_astrPayloadsSpecs[Loc_u8Counter].Port;
    /* Initializing GPIO */
    GPIO_enuInitPin(&Loc_strPinConfig);
  }/* for */

  return(Loc_enuError);/* Returning the error status */
}/* Payload_enuInit */
/* 
  Fn         :   Turn On/Off the payload
  Parameter1 :   Name of the specific Payload to control, Write the names to pass in "Payload_cfg.h" under "Connected Payloads"
  Parameter2 :   Control signal, options are in "Payload.h" under "Payload Control"
  Return     :   Error status of the fn, Error type is in "Payload.h" under "Error Type"
  **Caution**:   The payloads must be initialized using "Payload_enuInit"
*/
extern Payload_tenuError Payload_enuTurn(u8 Copy_u8PayloadName, u8 Copy_u8ControlSig)
{
  Payload_tenuError Loc_enuError = Payload_enuOk;
  GPIO_tstrPin Loc_strPin = {
    .Pins = Payload_astrPayloadsSpecs[Copy_u8PayloadName].Pin,
    .Port = Payload_astrPayloadsSpecs[Copy_u8PayloadName].Port 
  };
  GPIO_enuSetPinValue(&Loc_strPin, Copy_u8ControlSig);
  
  return(Loc_enuError);/* Returning the error status */
}/* Payload_enuTurn */
/* ********************************************************************************* */