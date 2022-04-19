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
  /* Configuration structure */
  typedef struct
  {
    u16 u16Port    ;     /* the port number from "GPIO.h" under "Available Ports" */
    u16 u16PinLeft ;     /* the pin number from "GPIO.h" under "Available Ports" or the options from "Pin Disconnected" */
    u16 u16PinRight;     /* the pin number from "GPIO.h" under "Available Ports" or the options from "Pin Disconnected" */
    u16 u16SpeedPin;     /* the pin number from "GPIO.h" under "Available Ports" or the options from "Pin Disconnected" */
  }DcMotor_tstrConfig;
  /* Functions return status */
  typdef enum
  {
    DcMotor_enuOk,
    DcMotor_enuNok
  }DcMotor_tenuStatus;
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
    Description         :           Init the Motors pins clock and mode
    Parameter(s)        :           void
    Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
  */
  DcMotor_tenuStatus DcMotor_enuInit(void);
  /* 
    Description         :           Move the right-pin motor or the motors to right in case of using H-bridge
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
  */
  DcMotor_tenuStatus DcMotor_enuMoveRight(u8 DcMotor_u8MotorID);
  /* 
    Description         :           Move the left-pin motor or the motors to left in case of using H-bridge
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
  */
  DcMotor_tenuStatus DcMotor_enuMoveLeft(u8 DcMotor_u8MotorID);
  /* 
    Description         :           stop the motor(s)
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
  */
  DcMotor_tenuStatus DcMotor_enuStop(u8 DcMotor_u8MotorID);
  /* 
    Description         :           Control speed
    Parameter1          :           the motor(s) ID, options are in "DcMotor_cfg.h" under "Motors IDs"
    Parameter2          :           
    Return              :           Error status of type "DcMotor_tenuStatus" in "DcMotor.h"
  */
  DcMotor_tenuStatus DcMotor_enuControlSpeed(u8 DcMotor_u8MotorID, u8 DcMotor_u8Speed);
  /* /////////////////////////////////////////////////////////////////////////// */
#endif