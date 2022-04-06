/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 12, 2022
**       Version     :	V01
**       SWC         :	GPIO
**       Description :	GPIO module files
** **************************************************************************************/
#ifndef _GPIO_PRV_H
#define _GPIO_PRV_H

  /* ********************************************************************************* */
  /* *********************** Shift Masks ********************************************* */
  /* Default Pins Shift Masks */
  #define GPIO_u8BIT0                         0
  #define GPIO_u8BIT1                         2
  #define GPIO_u8BIT2                         4
  #define GPIO_u8BIT3                         6
  #define GPIO_u8BIT4                         8
  #define GPIO_u8BIT5                         10
  #define GPIO_u8BIT6                         12
  #define GPIO_u8BIT7                         14
  #define GPIO_u8BIT8                         16
  #define GPIO_u8BIT9                         18
  #define GPIO_u8BIT10                        20
  #define GPIO_u8BIT11                        22
  #define GPIO_u8BIT12                        24
  #define GPIO_u8BIT13                        26
  #define GPIO_u8BIT14                        28
  #define GPIO_u8BIT15                        30
  /* AF registers pins shift masks */
  #define GPIO_u8AF_BIT0                      0
  #define GPIO_u8AF_BIT1                      4
  #define GPIO_u8AF_BIT2                      8
  #define GPIO_u8AF_BIT3                      12
  #define GPIO_u8AF_BIT4                      16
  #define GPIO_u8AF_BIT5                      20
  #define GPIO_u8AF_BIT6                      24
  #define GPIO_u8AF_BIT7                      28
  #define GPIO_u8AF_BIT8                      0
  #define GPIO_u8AF_BIT9                      4
  #define GPIO_u8AF_BIT10                     8
  #define GPIO_u8AF_BIT11                     12
  #define GPIO_u8AF_BIT12                     16
  #define GPIO_u8AF_BIT13                     20
  #define GPIO_u8AF_BIT14                     24
  #define GPIO_u8AF_BIT15                     28
  /* Atomic set reset register, resetting shift value */
  #define GPIO_u8SHIFT_VAL                    16
  /* Temp Variable Initial Value */
  #define GPIO_u32TEMP_INIT                   0
  /* Locking Register Sequence Applying Mask */
  #define GPIO_u32LCK_MASK                    0x10000
  /* Set Mask */
  #define GPIO_u8SET_4BIT                     0xF
  /* Clr masks */
  /* Mode clear mask */
  #define GPIO_u8CLR_MODE                     0x03
  #define GPIO_u8CLR_SPEED                    0x07
  #define GPIO_u8CLR_Resistor                 0x03

  
  /* ********************************************************************************* */







#endif