/* **************************************************************************************
**       Author      :	Michael  S. Ibrahim
**       Date        :	April 06, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD driver files
** **************************************************************************************/
#ifndef _LCD_PRV_H
#define _LCD_PRV_H
  /* **************************** Private Masks ********************************** */
  /* Initial Values */
  #define LCD_u8LCD_NUM_INIT                  0
  /* Bit masks */
  #define LCD_u8BIT0                          0
  #define LCD_u8BIT1                          1
  #define LCD_u8BIT2                          2
  #define LCD_u8BIT3                          3
  #define LCD_u8BIT4                          4
  #define LCD_u8BIT5                          5
  #define LCD_u8BIT6                          6
  #define LCD_u8BIT7                          7
  /* Bit slicer mask */
  #define LCD_u8CMD_SPLIT                     0x1
  /* Nibble swapping factor */
  #define LCD_u8SWAP_NIB_FACTOR               4
  /* Number Divider */
  #define LCD_u8NUM_DIV                       10
  /* ASCII Shifter */
  #define LCD_u8LCD_ASCII_SHIFT               48
  /* Delays */
  #define LCD_u8INIT_CMD1_DELAY               15
  #define LCD_u8INIT_CMD2_DELAY               5
  #define LCD_u8INIT_CMD3_DELAY               1
  #define LCD_u8DEFAULT_BIG_CMD_DELAY         5  
  #define LCD_u8DEFAULT_SMALL_CMD_DELAY       1
  /* Counter */
  #define LCD_u8CUSTOM_COUNTER_MAX            8
  /* Custom Character Phases */
  #define LCD_u8PHASE_ONE                     0
  #define LCD_u8PHASE_TWO                     1
  #define LCD_u8PHASE_THREE                   2
  /* String Terminator */
  #define LCD_u8NULL_CHAR                     '\0'
  /* ************************************************************************ */
  /* **************************** Externed Variables ************************ */
  extern LCD_tstrConfig LCD_astrLCDsConfig[LCD_u8CONN_LCD];
  /* ************************************************************************ */
  /* ************************ Processes prototypes ************************** */
  /* 
    Description     : Process to Init the LCD
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  static void LCD_vidInit_P(void);
  /* 
    Description     : Process to send init commands to the LCDs
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  static void LCD_vidCommandInit_P(void);
  /* 
    Description     : Process to send command to the LCD
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  static void LCD_vidCommand_P(void);
  /* 
    Description     : Process to display char on the LCD
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  static void LCD_vidDisplay_P(void);
  /* 
    Description     : Process to create custom char on the LCD
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  static void LCD_vidCreateChar_P(void);
  /* ************************************************************************ */
  /* ************************ Private Fns Prototypes ************************ */
  /* 
    Description     : Private Fn to send LCD request and lower flags and reset the tick timer of the LCD
    Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Return          : Void
    ////////////////////// Synchronous //////////////////////
  */
  static void LCD_vidReqReset(u8 Copy_u8LCD_Name);
  /* 
    Description     : Private Fn to send data second nibble to the LCD
    Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Return          : Void
    ////////////////////// Synchronous //////////////////////
  */
  static void LCD_vidSendDataNib2(u8 Copy_u8LCD_Name);
  /* 
    Description     : Private Fn to send data first nibble to the LCD
    Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Return          : Void
    ////////////////////// Synchronous //////////////////////
  */
  static void LCD_vidSendDataNib1(u8 Copy_u8LCD_Name);
  /* 
    Description     : Private Fn to send command second nibble to the LCD
    Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Return          : Void
    ////////////////////// Synchronous //////////////////////
  */
  static void LCD_vidSendCMD_Nib2(u8 Copy_u8LCD_Name);
  /* 
    Description     : Private Fn to send command first nibble to the LCD
    Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Return          : Void
    ////////////////////// Synchronous //////////////////////
  */
  static void LCD_vidSendCMD_Nib1(u8 Copy_u8LCD_Name);
  /* ************************************************************************ */

#endif