/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 26, 2022
**       Version     :	V01
**       SWC         :	M_NVIC
**       Description :	NVIC module files
** **************************************************************************************/
#ifndef _M_NVIC_PRV_H
#define _M_NVIC_PRV_H
  /* **************************** MACROS ************************************************** */
  /* Limit of connected external peripherals */
  #define M_NVIC_u8EXT_PER_LIMIT                          85
  /* Register size */
  #define M_NVIC_u8REG_SIZE                               32
  /* Group lvls */
  #define M_NVIC_u8_16_LVL                                16
  #define M_NVIC_u8_8_LVL                                 8
  #define M_NVIC_u8_4_LVL                                 4
  #define M_NVIC_u8_2_LVL                                 2
  /* Shift masks */
  #define M_NVIC_u8_SHIFT_4                               4
  #define M_NVIC_u8_SHIFT_5                               5
  #define M_NVIC_u8_SHIFT_6                               6
  #define M_NVIC_u8_SHIFT_7                               7
  /* ************************************************************************************** */
#endif