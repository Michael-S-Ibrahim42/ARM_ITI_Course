/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 23, 2022
**       Version     :	V01
**       SWC         :	HLED
**       Description :	Led module files
** **************************************************************************************/
/* ***************************** Headers Inclusion ********************************* */
/* LIB headers */
#include "STD_TYPES.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "H_Led.h"
#include "H_Led_cfg.h"

/* ********************************************************************************* */
/* ******************** Configurations Variables *********************************** */
const H_Led_tstrCfg H_Led_astrLeds[] = {
  [H_LED_u8MIL] = {
    .Port         = GPIO_u16PORT0,      
    .Pin          = GPIO_u16PIN2,       
    .ActiveState  = H_LED_u8HIGH_ACTIVE_STATE,
    .OType        = GPIO_u8PUSH_PULL      
  },
};

/* ********************************************************************************* */
