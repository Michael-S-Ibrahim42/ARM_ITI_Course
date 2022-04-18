/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	DcMotor
**       Description :	DcMotor software component
** **************************************************************************************/
/* //////////////////////////////////////// Headers inclusion /////////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "DcMotor.h"
#include "DcMotor_cfg.h"
#include "DcMotor_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////// Global Extern /////////////////////////////////////// */
extern DcMotor_tstrConfig DcMotor_astrMotorConfig[DCMOTOR_u8MOTOR_NUM];
/* ////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////// Interface Fns /////////////////////////////////////// */
/*
  Description         :           Move the right-pin motor or the motors to right in case of using H-bridge
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           void
*/
void DcMotor_enuMoveRight(u8 DcMotor_u8MotorID)
{
  if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft == DCMOTOR_u8FORCED_GND) || (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft == DCMOTOR_u8FORCED_VCC))
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight, DIO_u8PIN_HIGH^DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft);
  }/* if */
  else if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight != DCMOTOR_u8FORCED_GND) && (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight != DCMOTOR_u8FORCED_VCC))
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft, DIO_u8PIN_LOW);
  }/* else if */
  else
  {
    /* MISRA */
  }/* else */
}/* DcMotor_enuMoveRight */
/*
  Description         :           Move the left-pin motor or the motors to left in case of using H-bridge
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           void
*/
void DcMotor_enuMoveLeft(u8 DcMotor_u8MotorID)
{
  if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight == DCMOTOR_u8FORCED_GND) || (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight == DCMOTOR_u8FORCED_VCC))
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft, DIO_u8PIN_HIGH^DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight);
  }/* if */
  else if((DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft != DCMOTOR_u8FORCED_GND) && (DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft != DCMOTOR_u8FORCED_VCC))
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft, DIO_u8PIN_HIGH);
  }/* else if */
  else
  {
    /* MISRA */
  }/* else */
}/* DcMotor_enuMoveLeft */
/*
  Description         :           stop the motor(s)
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Return              :           void
*/
void DcMotor_enuStop(u8 DcMotor_u8MotorID)
{
  if(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight != DCMOTOR_u8FORCED_GND &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight != DCMOTOR_u8FORCED_VCC &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft != DCMOTOR_u8FORCED_GND &&
     DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft != DCMOTOR_u8FORCED_VCC )
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft , DIO_u8PIN_LOW);
  }/* if */
  else if(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight == DCMOTOR_u8FORCED_GND || DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight == DCMOTOR_u8FORCED_VCC)
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft , DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight);
  }/* else if */
  else 
  {
    Dio_enuWriteChannel(DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinRight , DcMotor_astrMotorConfig[DcMotor_u8MotorID].u8PinLeft);
  }/* else */
}/* DcMotor_enuStop */
/*
  Description         :           Control speed
  Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
  Parameter2          :
  Return              :           void
*/
void DcMotor_enuControlSpeed(u8 DcMotor_u8MotorID, u8 DcMotor_u8Speed)
{

}/* DcMotor_enuControlSpeed */
/* ////////////////////////////////////////////////////////////////////////////////////////////// */
