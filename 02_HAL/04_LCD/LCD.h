/* **************************************************************************************
**       Author      :	Michael  S. Ibrahim
**       Date        :	April 06, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD driver files
** **************************************************************************************/
#ifndef _LCD_H
#define _LCD_H
  /* **************************** Headers inclusion ************************* */
  #include "LCD_cfg.h"
  /* ************************************************************************ */
  /* **************************** Interface MACROS ************************** */
  /* Commands */
  #define LCD_u8CLEAR                         0x01
  #define LCD_u8RET_HOME                      0x02
  #define LCD_u8MODE_INC_SHFT                 0x07
  #define LCD_u8MODE_INC_NO_SHFT              0x06
  #define LCD_u8MODE_DEC_SHFT                 0x05
  #define LCD_u8MODE_DEC_NO_SHFT              0x04
  #define LCD_u8SET_DIS0_CUR0_BLINK0          0x08    
  #define LCD_u8SET_DIS0_CUR0_BLINK1          0x09    
  #define LCD_u8SET_DIS0_CUR1_BLINK0          0x0A    
  #define LCD_u8SET_DIS0_CUR1_BLINK1          0x0B    
  #define LCD_u8SET_DIS1_CUR0_BLINK0          0x0C    
  #define LCD_u8SET_DIS1_CUR0_BLINK1          0x0D    
  #define LCD_u8SET_DIS1_CUR1_BLINK0          0x0E    
  #define LCD_u8SET_DIS1_CUR1_BLINK1          0x0F    
  #define LCD_u8SHFT_CUR_LEFT                 0x10  
  #define LCD_u8SHFT_CUR_RIGHT                0x14 
  #define LCD_u8SHFT_DISP_LEFT                0x18 
  #define LCD_u8SHFT_DISP_RIGHT               0x1C
  #define LCD_u8FN_DL4_N1_F8                  0x20
  #define LCD_u8FN_DL4_N1_F11                 0x24                  
  #define LCD_u8FN_DL4_N2_F8                  0x28
  #define LCD_u8FN_DL4_N2_F11                 0x2C
  #define LCD_u8FN_DL8_N1_F8                  0x30
  #define LCD_u8FN_DL8_N1_F11                 0x34 
  #define LCD_u8FN_DL8_N2_F8                  0x38
  #define LCD_u8FN_DL8_N2_F11                 0x3C
  #define LCD_u8CGRAM_ADD_SET                 0x40
  #define LCD_u8DDRAM_ADD_SET                 0x80
  /* Custom Characters Creation Addresses */
  #define LCD_u8CGRAM_CH0                     0x00
  #define LCD_u8CGRAM_CH1                     0x08   
  #define LCD_u8CGRAM_CH2                     0x10
  #define LCD_u8CGRAM_CH3                     0x18          
  #define LCD_u8CGRAM_CH4                     0x20      
  #define LCD_u8CGRAM_CH5                     0x28          
  #define LCD_u8CGRAM_CH6                     0x30             
  #define LCD_u8CGRAM_CH7                     0x38
  /* Custom Characters Display Addresses */
  #define LCD_u8CGRAM_CODE0                   0x0
  #define LCD_u8CGRAM_CODE1                   0x1
  #define LCD_u8CGRAM_CODE2                   0x2
  #define LCD_u8CGRAM_CODE3                   0x3
  #define LCD_u8CGRAM_CODE4                   0x4
  #define LCD_u8CGRAM_CODE5                   0x5
  #define LCD_u8CGRAM_CODE6                   0x6
  #define LCD_u8CGRAM_CODE7                   0x7
  /* LCD Rows */
  #define LCD_u8ROW0                          0x00
  #define LCD_u8ROW1                          0x40
  /* LCD Columns */
  #define LCD_u8COL0                          0x0
  #define LCD_u8COL1                          0x1 
  #define LCD_u8COL2                          0x2 
  #define LCD_u8COL3                          0x3 
  #define LCD_u8COL4                          0x4 
  #define LCD_u8COL5                          0x5 
  #define LCD_u8COL6                          0x6 
  #define LCD_u8COL7                          0x7 
  #define LCD_u8COL8                          0x8 
  #define LCD_u8COL9                          0x9
  #define LCD_u8COL10                         0xA
  #define LCD_u8COL11                         0xB
  #define LCD_u8COL12                         0xC
  #define LCD_u8COL13                         0xD
  #define LCD_u8COL14                         0xE
  #define LCD_u8COL15                         0xF
  /* ************************************************************************ */
  /* **************************** Defined types **************************** */
  /* Error type */
  typedef enum
  {
    LCD_enuOk,
    LCD_enuNok
  }LCD_tenuError;
  /* LCD states type */
  typedef enum
  {
    LCD_enuNone, /* Set it in the configuration file */
    LCD_enuInit_C1, /* Can do the "The first cycle of basic initialization" actions */
    LCD_enuInit_C2, /* Can do the "The second cycle of basic initialization" actions */
    LCD_enuInit_C3, /* Can do the "The third cycle of basic initialization" actions */
    LCD_enuInit_4Pins, /* Can do the "Fn set" actions */
    LCD_enuFnSet1, /* Can do the "Fn set" actions */
    LCD_enuFnSet2, /* Can do the "Fn set" actions */
    LCD_enuDisplayOff1, /* Can do the "Display off" actions */
    LCD_enuDisplayOff2, /* Can do the "Display off" actions */
    LCD_enuDisplayClear1, /* Can do the "Display clear" actions */
    LCD_enuDisplayClear2, /* Can do the "Display clear" actions */
    LCD_enuEntryModeSet1, /* Can do the "Entry mode set" actions */
    LCD_enuEntryModeSet2, /* Can do the "Entry mode set" actions */
    LCD_enuOnDisplay1,/* set display on before start the running state */
    LCD_enuOnDisplay2,/* set display on before start the running state */
    LCD_enuRunning /* Can do the "running state" actions */
  }LCD_tenuState;
  /* LCD Request type */
  typedef enum
  {
    LCD_enuIdle,
    LCD_enuSendCMD,
    LCD_enuDispChar,
    LCD_enuCreateCustChar
  }LCD_tenuRequest;
  /* Data type for buffer */
  typedef struct
  {
    u8 Data1;
    u8 Data2;
    pu8 Data3Ptr;
  }LCD_tstrBuffer;
  /* LCD Config struct */
  typedef struct
  {
    u16             Port; /* You have to choose one port for the LCD */
    u16             RS_Pin;
    u16             RW_Pin;
    u16             E_Pin;
    u16             DB4_Pin;
    u16             DB5_Pin;
    u16             DB6_Pin;
    u16             DB7_Pin;
    LCD_tenuState   State;   /* The current state of LCD, at power on should be "LCD_enuNone" before handling any request should be "LCD_enuRunning" */
    LCD_tenuRequest Request; /* The request to handle, as long as LCD state is not "LCD_enuRunning", the request should be "LCD_enuIdle" also this is the idle value */
    LCD_tstrBuffer  Buffer;
    u8              Nib1_Flag;/* second nibble enable flag */
    u8              Nib2_Flag;/* second nibble enable flag */
    u8              DelayFlag;/* second nibble enable flag */
    u8              InitTimer;
    u8              SendTimer;
    u8              SendTimerLimit;
  }LCD_tstrConfig;
  /* ************************************************************************ */
  /* **************************** Interface Fns Prototypes **************************** */
  /* 
    Description         :     Init the LCD Module by setting the State as LCD_enuInit_C1
    Parameter(s)        :     void
    Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  extern LCD_tenuError LCD_vidInit(void);
  /* 
    Description         :     send command to the LCD Module by setting the request as "LCD_enuSendCMD"
    Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Parameter2          :     the command to execute, options are in "LCD.h" under "Commands"
    Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  extern LCD_tenuError LCD_vidSendCommand(u8 Loc_u8LCD_Name, u8 Copy_u8Command);
  /* 
    Description         :     Display char on the LCD Module by setting the request as "LCD_enuDispChar"
    Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Parameter2          :     the char to execute, options are the ASCII characters or the "Custom Characters Display Addresses" in "LCD.h"
    Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  extern LCD_tenuError LCD_vidDisplayChar(u8 Loc_u8LCD_Name, u8 Copy_u8Char);
  /* 
    Description         :     Create custom characters in the memory of the LCD
    Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Parameter2          :     Custom Character Creation Address, Available Options are in "LCD.h" under the section "Custom Characters Creation Addresses"
    Parameter3          :     pointer to int array of size '8', which hold the custom character needed to be printed
    Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  extern LCD_tenuError LCD_vidCreateCustomCharacter(u8 Loc_u8LCD_Name, u8 Copy_u8CustomCharAdd, pu8 Copy_pu8CustomCharacter);
  /* 
    Description         :     Change location on LCD display
    Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
    Parameter2          :     the row   , available options are in "LCD.h" under the section "LCD Rows"
    Parameter3          :     the column, available options are in "LCD.h" under the section "LCD Columns"
    Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  extern LCD_tenuError LCD_vidGoTo(u8 Loc_u8LCD_Name, u8 Copy_u8Row, u8 Copy_u8Column);
  /* ************************************************************************ */
  /* *********************** Runnables ************************************** */
  /* 
    Description     : Runnable to master the LCD and handle its requests
    Parameter(s)    : void
    Return          : Void
    ////////////////////// Asynchronous //////////////////////
  */
  extern void LCD_vidMasterLCD_R(void);
  /* ************************************************************************ */
#endif