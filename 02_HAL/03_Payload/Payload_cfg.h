/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 05, 2022
**       Version     :	V01
**       SWC         :	Payload
**       Description :	Payload module files
** **************************************************************************************/
#ifndef _PAYLOAD_CFG_H
#define _PAYLOAD_CFG_H

  /* *************************** Connected Leds ****************************************** */
  /* Connected Payloads */
  /* Add your Payloads MACROS and their values and use them in configuring the "Payload_cfg.c" and in using interface fn "Payload_enuTurn" */
  /* IDs should start from 0 and step by 1 */
  #define PAYLOAD_u8MOTOR                                0
  #define PAYLOAD_u8BUZZER                               1
  /* Number of connected payloads */
  /* Change only the number, available to write from 1 to (256) */
  #define PAYLOAD_u8PAYLOADS_NUM                          2
  /* ************************************************************************************* */













#endif