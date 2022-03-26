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
/* Own headers */
#include "HLED.h"
#include "HLED_cfg.h"

/* ********************************************************************************* */
/* ******************** Configurations Variables *********************************** */
const HLED_tstrCfg HLED_astrLeds[] = {
  [HLED_u8BLUE] = {
    .HLED_u16Port = HLED_u16PORT0,      
    .HLED_u16Pin = HLED_u16PIN0,       
    .HLED_u8ActiveState = HLED_u8HIGH_ACTIVE_STATE,
    .HLED_u8OType = HLED_u8OTYPE_PP      
  },
};

/* ********************************************************************************* */
/* ********************************************************************************* */
