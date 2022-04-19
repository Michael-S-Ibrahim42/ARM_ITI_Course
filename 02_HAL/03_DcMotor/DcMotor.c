/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	DcMotor
**       Description :	DcMotor software component
** **************************************************************************************/
/* //////////////////////////////////////// Headers inclusion /////////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "DcMotor.h"
#include "DcMotor_cfg.h"
#include "DcMotor_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Interface Fns ///////////////////////////////// */
/* 
  Description         :           Init the Motors pins clock and mode
  Parameter(s)        :           void
  Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
*/
DcMotor_tenuStatus DcMotor_enuInit(void)
{
  DcMotor_tenuStatus Loc_enuError = DcMotor_enuOk;
  GPIO_tstrPinConfig Loc_enuDcMotorConfig;
  u16 Loc_u8Counter;
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < DCMOTOR_u8MOTOR_NUM; Loc_u8Counter++)
  {
    switch(DcMotor_astrMotorConfig[Loc_u8Counter].u16Port)
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
      Loc_enuError = DcMotor_enuNok; 
    }/* switch */
    Loc_enuDcMotorConfig.Mode     = GPIO_u8GP_OUT;
    Loc_enuDcMotorConfig.OutType  = GPIO_u8PUSH_PULL;
    Loc_enuDcMotorConfig.OutSpeed = GPIO_u8LOW_SPEED;
    Loc_enuDcMotorConfig.PullRes  = GPIO_u8NO_PUPD;
    Loc_enuDcMotorConfig.Pins     = DcMotor_astrMotorConfig[Loc_u8Counter].u16PinLeft;
    Loc_enuDcMotorConfig.Port     = DcMotor_astrMotorConfig[Loc_u8Counter].u16Port;
    /* Initializing GPIO */
    GPIO_enuInitPin(&Loc_enuDcMotorConfig);
  }/* for */

  return(Loc_enuError);/* Returning the error status */
}/* DcMotor_enuInit */
/* 
  Description         :           Move the right-pin motor or the motors to right in case of using H-bridge
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
*/
DcMotor_tenuStatus DcMotor_enuMoveRight(u8 DcMotor_u8MotorID)
{
  DcMotor_tenuStatus Loc_enuError = DcMotor_enuOk;
  GPIO_tstrPin Loc_strPin;
  Loc_strPin.Port = DcMotor_astrMotorConfig.u16Port;
  
  if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft == DCMOTOR_u8FORCED_GND) || 
     (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16Pinu16PinLeft == DCMOTOR_u8FORCED_VCC))
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinRight;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuHigh^DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft);
  }/* if */
  else if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight != DCMOTOR_u8FORCED_GND) && 
          (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight != DCMOTOR_u8FORCED_VCC))
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinRight;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuHigh);
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinLeft;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuLow);
  }/* else if */
  else
  {
    /* MISRA */
  }/* else */
  return(Loc_enuError);
}/* DcMotor_enuMoveRight */
/* 
  Description         :           Move the left-pin motor or the motors to left in case of using H-bridge
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
*/
DcMotor_tenuStatus DcMotor_enuMoveLeft(u8 DcMotor_u8MotorID)
{
  DcMotor_tenuStatus Loc_enuError = DcMotor_enuOk;
  GPIO_tstrPin Loc_strPin;
  Loc_strPin.Port = DcMotor_astrMotorConfig.u16Port;
  
  if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight == DCMOTOR_u8FORCED_GND) || (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight == DCMOTOR_u8FORCED_VCC))
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinLeft;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuHigh^DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight);
  }/* if */
  else if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft != DCMOTOR_u8FORCED_GND) && (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft != DCMOTOR_u8FORCED_VCC))
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinLeft;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuHigh);
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinRight;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuLow);
  }/* else if */
  else
  {
    /* MISRA */
  }/* else */
  return(Loc_enuError);
}/* DcMotor_enuMoveLeft */
/* 
  Description         :           stop the motor(s)
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
*/
DcMotor_tenuStatus DcMotor_enuStop(u8 DcMotor_u8MotorID)
{
  DcMotor_tenuStatus Loc_enuError = DcMotor_enuOk;
 if(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight != DCMOTOR_u8FORCED_GND &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight != DCMOTOR_u8FORCED_VCC &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft != DCMOTOR_u8FORCED_GND &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft != DCMOTOR_u8FORCED_VCC )
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinRight;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuLow);
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinLeft;
    GPIO_enuSetPinValue(&Loc_strPin, GPIO_enuLow);
  }/* if */
  else if(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight == DCMOTOR_u8FORCED_GND || 
          DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight == DCMOTOR_u8FORCED_VCC)
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinLeft;
    GPIO_enuSetPinValue(&Loc_strPin, DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinRight);
  }/* else if */
  else 
  {
    Loc_strPin.Pins = DcMotor_astrMotorConfig.u16PinRight;
    GPIO_enuSetPinValue(&Loc_strPin, DcMotor_astrMotorConfig[DcMotor_u8MotorID].u16PinLeft);
  }/* else */
  return(Loc_enuError);
}/* DcMotor_enuStop */
/* 
  Description         :           Control speed
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Parameter2          :           
  Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
*/
DcMotor_tenuStatus DcMotor_enuControlSpeed(u8 DcMotor_u8MotorID, u8 DcMotor_u8Speed)
{
  DcMotor_tenuStatus Loc_enuError = DcMotor_enuOk;

  return(Loc_enuError);
}/* DcMotor_enuControlSpeed */
/* /////////////////////////////////////////////////////////////////////////// */