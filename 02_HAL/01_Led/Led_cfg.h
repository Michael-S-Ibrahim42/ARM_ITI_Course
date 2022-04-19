/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	LED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _LED_CFG_H
#define _LED_CFG_H
  /* *************************** Connected Leds ****************************************** */
  /* Leds IDs */
  /* Add your LEDs MACROS and their values and use them in configuring the "Led_cfg.c" and in using interface fn "Led_enuSet" */
  /* IDs should start from 0 and step by 1 */
  #define LED_u8MIL                                0
  /* Number of connected leds */
  /* Change only the number, available to write from 0 to (2^8) */
  #define LED_u16LEDS_NUM                          1
  /* ************************************************************************************* */
#endif
