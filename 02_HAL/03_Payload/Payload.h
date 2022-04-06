/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 05, 2022
**       Version     :	V01
**       SWC         :	Payload
**       Description :	Payload module files
** **************************************************************************************/
#ifndef _PAYLOAD_H
#define _PAYLOAD_H
  /* The Payload is any device controlled by a transistor */
  /* ********************************* Inclusion Part ************************************* */
  #include "Payload_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Payload Control */ 
  #define PAYLOAD_u8OFF                                   0
  #define PAYLOAD_u8ON                                    1
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Payload_enuOk,
    Payload_enuNok
  }Payload_tenuError;
  /* Payload Configurations */
  typedef struct
  {
    u16 Port;                /* Options are in "GPIO.h" under "Available Ports"       */
    u16 Pin;                 /* Options are in "GPIO.h" under "Available Pins"        */
  }Payload_tstrCfg;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn        :   Init the Payload(s) configurations
    Return    :   Error status of the fn, Error type is in "Payload.h" under "Error Type"
  */
  extern Payload_tenuError Payload_enuInit(void);
  /* 
    Fn         :   Turn On/Off the payload
    Parameter1 :   Name of the specific Payload to control, Write the names to pass in "Payload_cfg.h" under "Connected Payloads"
    Parameter2 :   Control signal, options are in "Payload.h" under "Payload Control"
    Return     :   Error status of the fn, Error type is in "Payload.h" under "Error Type"
    **Caution**:   The payloads must be initialized using "Payload_enuInit"
  */
  extern Payload_tenuError Payload_enuTurn(u8 Copy_u8PayloadName, u8 Copy_u8ControlSig);
  /* ********************************************************************************* */

#endif