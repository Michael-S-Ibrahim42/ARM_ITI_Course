/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _HLED_CFG_H
#define _HLED_CFG_H
  /* ************************************************************************************* */
  /* *************************** Connected Leds ****************************************** */
  /* Leds IDs */
  /* Add your LEDs MACROS and their values and use them in configuring the "HLED_cfg.c" and in using interface fn "HLED_enuSet" */
  /* IDs should start from 0 and step by 1 */
  #define HLED_u8BLUE                               0
  /* Number of connected leds */
  /* Change only the number, available to write from 0 to (2^16) */
  #define HLED_u8LEDS_NUM                           1

  /* ************************************************************************************* */
  /* ************************************************************************************* */


  /* ************************************************************************************* */
  /* ************************************************************************************* */
#endif
