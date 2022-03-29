/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _H_LED_CFG_H
#define _H_LED_CFG_H
  /* ************************************************************************************* */
  /* *************************** Connected Leds ****************************************** */
  /* Leds IDs */
  /* Add your LEDs MACROS and their values and use them in configuring the "H_LED_cfg.c" and in using interface fn "H_Led_enuSet" */
  /* IDs should start from 0 and step by 1 */
  #define H_LED_u8BLUE                               0
  /* Number of connected leds */
  /* Change only the number, available to write from 0 to (2^8) */
  #define H_LED_u16LEDS_NUM                          1

  /* ************************************************************************************* */
  /* ************************************************************************************* */


  /* ************************************************************************************* */
  /* ************************************************************************************* */
#endif
