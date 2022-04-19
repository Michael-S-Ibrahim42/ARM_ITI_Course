/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	DcMotor
**       Description :	DcMotor software component
** **************************************************************************************/
/* ////////////////////////////////////// Headers inclusion ///////////////////////////////// */
#include "GPIO.h"
#include "DcMotor.h"
#include "DcMotor_cfg.h"
#include "DcMotor_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////// Configuration array //////////////////////////////// */
DcMotor_tstrConfig DcMotor_astrMotorConfig[] = 
{
  [DCMOTOR_u8IGNITION_MOTOR] =
  {
    .u16Port     = GPIO_u16PORT0,
    .u16PinLeft  = DIO_u8PIN2,
    .u16PinRight = DCMOTOR_u8FORCED_GND,
    .u16SpeedPin = DCMOTOR_u8DISCONNECTED
  }
};
/* ////////////////////////////////////////////////////////////////////////////////////////// */
