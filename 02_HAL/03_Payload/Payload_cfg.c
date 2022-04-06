/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 05, 2022
**       Version     :	V01
**       SWC         :	Payload
**       Description :	Payload module files
** **************************************************************************************/
/* ***************************** Headers Inclusion ********************************* */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "Payload.h"
#include "Payload_cfg.h"
/* ******************************************************************************** */
/* ******************** Configurations Variables *********************************** */
const Payload_tstrCfg Payload_astrPayloadsSpecs[] = {
  [PAYLOAD_u8MOTOR] = 
  {
    .Port         = GPIO_u16PORT0,      
    .Pin          = GPIO_u16PIN0       
  },
  [PAYLOAD_u8BUZZER] = 
  {
    .Port         = GPIO_u16PORT0,      
    .Pin          = GPIO_u16PIN1       
  }
};
/* ********************************************************************************* */