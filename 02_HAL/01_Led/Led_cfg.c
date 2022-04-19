/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	LED
**       Description :	Led module files
** **************************************************************************************/
/* ***************************** Headers Inclusion ********************************* */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "Led.h"
#include "Led_cfg.h"

/* ********************************************************************************* */
/* ******************** Configurations Variables *********************************** */
const Led_tstrCfg Led_astrLeds[] = {
  [LED_u8BLUE] = {
    .Port         = GPIO_u16PORT0,      
    .Pin          = GPIO_u16PIN3,       
    .ActiveState  = LED_u8HIGH_ACTIVE_STATE,
    .OType        = GPIO_u8PUSH_PULL      
  },
};
/* ********************************************************************************* */
