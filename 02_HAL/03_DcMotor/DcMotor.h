/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	DcMotor
**       Description :	DcMotor software component
** **************************************************************************************/
#ifndef _DCMOTOR_H
#define _DCMOTOR_H
  /* /////////////////////////////////// Headers inclusion ///////////////////// */
  #include "DcMotor_cfg.h"
  /* /////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////////////// Defined Types ///////////////////////// */
  typedef struct
  {
    u8 u8PinLeft; /* the pin number from "Dio.h" or the options from "Pin Disconnected" */
    u8 u8PinRight;
    u8 u8SpeedPin;
  }DcMotor_tstrConfig;
  /* /////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////// MACROS //////////////////////////////////////// */
  /* Pin Disconnected */ 
  /* Motor Pin */ /* Your selection will indicate the needed power to drive the motor on which is the complementary of you choice */
  #define DCMOTOR_u8FORCED_GND                                      0
  #define DCMOTOR_u8FORCED_VCC                                      1
  /* Speed Pin */
  #define DCMOTOR_u8DISCONNECTED                                    2
  /* /////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////// Interface Fns ///////////////////////////////// */
  /* 
    Description         :           Move the right-pin motor or the motors to right in case of using H-bridge
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           void
  */
  void DcMotor_enuMoveRight(u8 DcMotor_u8MotorID);
  /* 
    Description         :           Move the left-pin motor or the motors to left in case of using H-bridge
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           void
  */
  void DcMotor_enuMoveLeft(u8 DcMotor_u8MotorID);
  /* 
    Description         :           stop the motor(s)
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           void
  */
  void DcMotor_enuStop(u8 DcMotor_u8MotorID);
  /* 
    Description         :           Control speed
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Parameter2          :           
    Return              :           void
  */
  void DcMotor_enuControlSpeed(u8 DcMotor_u8MotorID, u8 DcMotor_u8Speed);
  /* /////////////////////////////////////////////////////////////////////////// */
#endif