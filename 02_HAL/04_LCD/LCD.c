/* **************************************************************************************
**       Author      :	Michael  S. Ibrahim
**       Date        :	April 06, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD driver files
** **************************************************************************************/
/* **************************** Headers Inclusion *************************************** */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "RCC.h"
#include "GPIO.h"
/* Own headers */
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"
/* ************************************************************************************** */
/* **************************** Interface Fns Implementations *************************** */
/* 
  Description         :     Init the LCD Module by setting the State as LCD_enuInit_C1
  Parameter(s)        :     void
  Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
LCD_tenuError LCD_vidInit(void)
{
  LCD_tenuError Loc_enuError = LCD_enuOk;
  GPIO_tstrPinConfig Loc_strLCDPins;
  u8 Loc_u8Counter = ZERO_INIT;

  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    switch(LCD_astrLCDsConfig[Loc_u8Counter].Port)
    {
    case(GPIO_u16PORT0):
      RCC_enuPerClk(RCC_enuGPIOA, RCC_enuOn);
      break;
    case(GPIO_u16PORT1):
      RCC_enuPerClk(RCC_enuGPIOB, RCC_enuOn);
      break;
    case(GPIO_u16PORT2):
      RCC_enuPerClk(RCC_enuGPIOC, RCC_enuOn);
      break;
    case(GPIO_u16PORT3):
      RCC_enuPerClk(RCC_enuGPIOD, RCC_enuOn);
      break;
    default:
      Loc_enuError = LCD_enuNok;         
    }/* switch */
    /* Init the Gpio pin */
    Loc_strLCDPins.Mode     = GPIO_u8GP_OUT;
    Loc_strLCDPins.OutType  = GPIO_u8PUSH_PULL;
    Loc_strLCDPins.OutSpeed = GPIO_u8LOW_SPEED;
    Loc_strLCDPins.PullRes  = GPIO_u8NO_PUPD;
    Loc_strLCDPins.Port     = LCD_astrLCDsConfig[Loc_u8Counter].Port;
    Loc_strLCDPins.Pins     = (LCD_astrLCDsConfig[Loc_u8Counter].RS_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].RW_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].E_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].DB4_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].DB5_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].DB6_Pin) | (LCD_astrLCDsConfig[Loc_u8Counter].DB7_Pin);
    GPIO_enuInitPin(&Loc_strLCDPins);
    /* Init LCD Parameters */
    LCD_astrLCDsConfig[Loc_u8Counter].State           = LCD_enuInit_C1;
    LCD_astrLCDsConfig[Loc_u8Counter].Request         = LCD_enuIdle;
    LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag       = FLAG_LOW;
    LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag       = FLAG_LOW;
    LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag       = FLAG_LOW;
    LCD_astrLCDsConfig[Loc_u8Counter].InitTimer       = ZERO_INIT;
    LCD_astrLCDsConfig[Loc_u8Counter].SendTimer       = ZERO_INIT;
    LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1    = ZERO_INIT;
    LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1    = ZERO_INIT;
  }/* for */

  return(Loc_enuError);
}/* LCD_vidInit */
/* 
  Description         :     send command to the LCD Module by setting the request as "LCD_enuSendCMD"
  Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Parameter2          :     the command to execute, options are in "LCD.h" under "Commands"
  Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
LCD_tenuError LCD_vidSendCommand(u8 Loc_u8LCD_Name, u8 Copy_u8Command)
{
  LCD_tenuError Loc_enuError = LCD_enuOk;/* Initializing the error status */

  if((LCD_astrLCDsConfig[Loc_u8LCD_Name].State == LCD_enuRunning) && (LCD_astrLCDsConfig[Loc_u8LCD_Name].Request == LCD_enuIdle))/* Set the request to "LCD_enuSendCM", and buffer the command  */
  {
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Request = LCD_enuSendCMD;
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Buffer.Data1 = Copy_u8Command;
  }/* if */ 
  else/* The LCD is busy now */
  {
    Loc_enuError = LCD_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* LCD_vidSendCommand */
/* 
  Description         :     Display char on the LCD Module by setting the request as "LCD_enuDispChar"
  Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Parameter2          :     the char to execute, options are the ASCII characters or the "Custom Characters Display Addresses" in "LCD.h"
  Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
LCD_tenuError LCD_vidDisplayChar(u8 Loc_u8LCD_Name, u8 Copy_u8Char)
{
  LCD_tenuError Loc_enuError = LCD_enuOk;/* Initializing the error status */

  if((LCD_astrLCDsConfig[Loc_u8LCD_Name].State == LCD_enuRunning) && (LCD_astrLCDsConfig[Loc_u8LCD_Name].Request == LCD_enuIdle))/* Set the request to "LCD_enuDispChar", and buffer the command  */
  {
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Request = LCD_enuDispChar;
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Buffer.Data1 = Copy_u8Char;
  }/* if */
  else/* The LCD is busy now */
  {
    Loc_enuError = LCD_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* LCD_vidDisplayChar */
/* 
  Description         :     Create custom characters in the memory of the LCD
  Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Parameter2          :     Custom Character Creation Address, Available Options are in "LCD.h" under the section "Custom Characters Creation Addresses"
  Parameter3          :     pointer to int array of size '8', which hold the custom character needed to be printed
  Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
LCD_tenuError LCD_vidCreateCustomCharacter(u8 Loc_u8LCD_Name, u8 Copy_u8CustomCharAdd, pu8 Copy_pu8CustomCharacter)
{
  LCD_tenuError Loc_enuError = LCD_enuOk;/* Initializing the error status */

  if((LCD_astrLCDsConfig[Loc_u8LCD_Name].State == LCD_enuRunning) && (LCD_astrLCDsConfig[Loc_u8LCD_Name].Request == LCD_enuIdle))/* Set the request to "LCD_enuCreateCustChar", and buffer the arguments  */
  {
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Request = LCD_enuCreateCustChar;
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Buffer.Data1 = Copy_u8CustomCharAdd;
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Buffer.Data3Ptr = Copy_pu8CustomCharacter;
  }/* if */
  else/* The LCD is busy now */
  {
    Loc_enuError = LCD_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* LCD_vidCreateCustomCharacter */
/* 
  Description         :     Change location on LCD display
  Parameter1          :     the LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Parameter2          :     the row   , available options are in "LCD.h" under the section "LCD Rows"
  Parameter3          :     the column, available options are in "LCD.h" under the section "LCD Columns"
  Return              :     Error status of type "LCD_tenuError", defined in "LCD.h" under "Error type" section
  ////////////////////// Synchronous //////////////////////
*/
LCD_tenuError LCD_vidGoTo(u8 Loc_u8LCD_Name, u8 Copy_u8Row, u8 Copy_u8Column)
{
  LCD_tenuError Loc_enuError = LCD_enuOk;/* Initializing the error status */

  if((LCD_astrLCDsConfig[Loc_u8LCD_Name].State == LCD_enuRunning) && (LCD_astrLCDsConfig[Loc_u8LCD_Name].Request == LCD_enuIdle))/* Set the request to "LCD_enuCreateCustChar", and buffer the arguments  */
  {
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Request = LCD_enuSendCMD;
    LCD_astrLCDsConfig[Loc_u8LCD_Name].Buffer.Data1 = (LCD_u8DDRAM_ADD_SET | (Copy_u8Row+Copy_u8Column));
  }/* if */  
  else/* The LCD is busy now */
  {
    Loc_enuError = LCD_enuNok;
  }/* else */

  return(Loc_enuError);/* returning the error status */
}/* LCD_vidGoTo */
/* ************************************************************************************** */
/* **************************** Runnables *********************************************** */
/* 
  Description     : Runnable to master the LCD and handle its requests
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
void LCD_vidMasterLCD_R(void)
{
  u8 Loc_u8Counter = ZERO_INIT;
  
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    if(LCD_astrLCDsConfig[Loc_u8Counter].State != LCD_enuRunning)
    {
      LCD_vidInit_P();
    }/* if */
    else
    {
      switch(LCD_astrLCDsConfig[Loc_u8Counter].Request)
      {
      case(LCD_enuSendCMD):
        LCD_vidCommand_P();
        break;
      case(LCD_enuDispChar):
        LCD_vidDisplay_P();
        break;
      case(LCD_enuCreateCustChar):
        LCD_vidCreateChar_P();   
        break;
      default:
        /* MISRA */
        break;
      }/* switch */
    }/* else */
  }/* for */
}/* LCD_vidMasterLCD_R */
/* ************************************************************************************** */
/* ****************************** Processes ********************************************* */
/* 
  Description     : Process to Init the LCD
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
static void LCD_vidInit_P(void)
{
  u8 Loc_u8Counter = ZERO_INIT;
 
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)/* looping over connected LCDs */
  {
    if(LCD_astrLCDsConfig[Loc_u8Counter].State != LCD_enuRunning)
    {
      switch(LCD_astrLCDsConfig[Loc_u8Counter].State)
      {
      case(LCD_enuInit_C1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          if(LCD_astrLCDsConfig[Loc_u8Counter].InitTimer == LCD_u8INIT_CMD1_DELAY)
          {
            LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8FN_DL8_N1_F8;
            LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
          }/* if */
          else
          {
            LCD_astrLCDsConfig[Loc_u8Counter].InitTimer += LCD_u8TICK_TIME;
          }/* else */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].InitTimer = ZERO_INIT;
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuInit_C2;
        }/* else */
        break;
      case(LCD_enuInit_C2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          if(LCD_astrLCDsConfig[Loc_u8Counter].InitTimer == LCD_u8INIT_CMD2_DELAY)
          {
            LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8FN_DL8_N1_F8;
            LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
          }/* if */
          else
          {
            LCD_astrLCDsConfig[Loc_u8Counter].InitTimer += LCD_u8TICK_TIME;
          }/* else */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].InitTimer = ZERO_INIT;
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuInit_C3;
        }/* else */
        break;
      case(LCD_enuInit_C3):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          if(LCD_astrLCDsConfig[Loc_u8Counter].InitTimer == LCD_u8INIT_CMD3_DELAY)
          {
            LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8FN_DL8_N1_F8;
            LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
          }/* if */
          else
          {
            LCD_astrLCDsConfig[Loc_u8Counter].InitTimer += LCD_u8TICK_TIME;
          }/* else */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].InitTimer = ZERO_INIT;
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuInit_4Pins;
        }/* else */
        break;          
      case(LCD_enuInit_4Pins):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8FN_DL4_N1_F8;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuFnSet1;
        }/* else */
        break;
      case(LCD_enuFnSet1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8FN_DL4_N2_F8;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuFnSet2;
        }/* else */
        break;
      case(LCD_enuFnSet2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = (u8)(LCD_u8FN_DL4_N2_F8<<LCD_u8SWAP_NIB_FACTOR);
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuDisplayOff1;
        }/* else */
        break;
      case(LCD_enuDisplayOff1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8SET_DIS0_CUR0_BLINK0;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuDisplayOff2;
        }/* else */
        break;      
      case(LCD_enuDisplayOff2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = (u8)(LCD_u8SET_DIS0_CUR0_BLINK0<<LCD_u8SWAP_NIB_FACTOR);
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuDisplayClear1;
        }/* else */
        break;      
      case(LCD_enuDisplayClear1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8CLEAR;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuDisplayClear2;
        }/* else */
        break;      
      case(LCD_enuDisplayClear2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = (u8)(LCD_u8CLEAR<<LCD_u8SWAP_NIB_FACTOR);
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuEntryModeSet1;
        }/* else */
        break;      
      case(LCD_enuEntryModeSet1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8MODE_INC_NO_SHFT;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuEntryModeSet2;
        }/* else */
        break; 
      case(LCD_enuEntryModeSet2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = (u8)(LCD_u8MODE_INC_NO_SHFT<<LCD_u8SWAP_NIB_FACTOR);
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuOnDisplay1;
        }/* else */
        break; 
      case(LCD_enuOnDisplay1):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8SET_DIS1_CUR0_BLINK0;
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuOnDisplay2;
        }/* else */
        break; 
      case(LCD_enuOnDisplay2):
        if(LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag == FLAG_LOW)
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = (u8)(LCD_u8SET_DIS1_CUR0_BLINK0<<LCD_u8SWAP_NIB_FACTOR);
          LCD_vidCommandInit_P();/* calling the command process to send the commmand and raise the flag */
        }/* if */
        else
        {
          LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_LOW;
          LCD_astrLCDsConfig[Loc_u8Counter].State = LCD_enuRunning;
        }/* else */
        break; 
      default:
        /* MISRA */
        break;
      }/* switch */
    }/* if */
  }/* for */
}/* LCD_vidInit_P */
/* 
  Description     : Process to send init commands to the LCDs
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
static void LCD_vidCommandInit_P(void)
{
  u8 Loc_u8Counter = ZERO_INIT;

  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit = LCD_u8DEFAULT_SMALL_CMD_DELAY;
    if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
    {
      LCD_vidSendCMD_Nib1(Loc_u8Counter);
    }/* if */
    else/* waiting Phase */
    {
      LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
      if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
      {
        LCD_astrLCDsConfig[Loc_u8Counter].DelayFlag = FLAG_HIGH;
        LCD_astrLCDsConfig[Loc_u8Counter].SendTimer = ZERO_INIT;
        LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag = FLAG_LOW;
        LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag = FLAG_LOW;
      }/* if */
    }/* else */
  }/* for */
}/* LCD_vidCommandInit_P */
/* 
  Description     : Process to send command to the LCD
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
static void LCD_vidCommand_P(void)
{
  u8 Loc_u8Counter = ZERO_INIT;

  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    if(LCD_astrLCDsConfig[Loc_u8Counter].Request == LCD_enuSendCMD)
    {
      if((LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 == LCD_u8RET_HOME) || (LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 == LCD_u8CLEAR))
      {
        LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit = LCD_u8DEFAULT_BIG_CMD_DELAY;
      }/* if */
      else
      {
        LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit = LCD_u8DEFAULT_SMALL_CMD_DELAY;
      }/* else */
      if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
      {
        LCD_vidSendCMD_Nib1(Loc_u8Counter);/* synchronous fn */
      }/* if */
      else if(LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag == FLAG_LOW)/* sending the second nibble */
      {
        LCD_vidSendCMD_Nib2(Loc_u8Counter);/* synchronous fn */
      }/* else if */
      else/* waiting Phase */
      {
        LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
        if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
        {
          LCD_vidReqReset(Loc_u8Counter);/* synchronous fn */
        }/* if */
      }/* else */
    }/* if */
  }/* for */
}/* LCD_vidCommand_P */
/* 
  Description     : Process to display char on the LCD
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
static void LCD_vidDisplay_P(void)
{
  u8 Loc_u8Counter = ZERO_INIT;

  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    if(LCD_astrLCDsConfig[Loc_u8Counter].Request == LCD_enuDispChar)
    {
      LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit = LCD_u8DEFAULT_SMALL_CMD_DELAY;
      if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
      {
        LCD_vidSendDataNib1(Loc_u8Counter);
      }/* if */
      else if(LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag == FLAG_LOW)/* sending the second nibble */
      {
        LCD_vidSendDataNib2(Loc_u8Counter);
      }/* else if */
      else/* waiting Phase */
      {
        LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
        if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
        {
          LCD_vidReqReset(Loc_u8Counter);
        }/* if */
      }/* else */
    }/* if */
  }/* for */
}/* LCD_vidDisplay_P */
/* 
  Description     : Process to create custom char on the LCD
  Parameter(s)    : void
  Return          : Void
  ////////////////////// Asynchronous //////////////////////
*/
static void LCD_vidCreateChar_P(void)
{
  static u8 Loc_u8Phase = LCD_u8PHASE_ONE;
  static u8 Loc_u8DigitSizeCounter = ZERO_INIT;
  u8 Loc_u8Counter = ZERO_INIT;

  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LCD_u8CONN_LCD; Loc_u8Counter++)
  {
    if(LCD_astrLCDsConfig[Loc_u8Counter].Request == LCD_enuCreateCustChar)
    {
      if(Loc_u8Phase == LCD_u8PHASE_ONE) /* Phase One in custom char creation */
      {
        if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 |= LCD_u8CGRAM_ADD_SET;
          LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit = LCD_u8DEFAULT_SMALL_CMD_DELAY;
          LCD_vidSendCMD_Nib1(Loc_u8Counter);/* synchronous fn */
        }/* if */
        else if(LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag == FLAG_LOW)/* sending the second nibble */
        {
          LCD_vidSendCMD_Nib2(Loc_u8Counter);/* synchronous fn */
        }/* else if */
        else/* waiting Phase */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
          if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
          {
            LCD_astrLCDsConfig[Loc_u8Counter].SendTimer = ZERO_INIT;
            LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag = FLAG_LOW;
            LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag = FLAG_LOW;
            Loc_u8Phase = LCD_u8PHASE_TWO;
            Loc_u8DigitSizeCounter =  ZERO_INIT;
          }/* if */
        }/* else */
      }/* if */
      else if(Loc_u8Phase == LCD_u8PHASE_TWO) /* Phase two in custom char creation */
      {
        if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = *(LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data3Ptr);
          LCD_vidSendDataNib1(Loc_u8Counter);/* synchronous fn */
        }/* if */
        else if(LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag == FLAG_LOW)/* sending the second nibble */
        {
          LCD_vidSendDataNib2(Loc_u8Counter);/* synchronous fn */
        }/* else if */
        else/* waiting Phase */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
          if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
          {
            LCD_astrLCDsConfig[Loc_u8Counter].SendTimer = ZERO_INIT;
            LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag = FLAG_LOW;
            LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag = FLAG_LOW;
            (LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data3Ptr)++;
            Loc_u8DigitSizeCounter++;
            if(Loc_u8DigitSizeCounter == 8)
            {
              Loc_u8Phase = LCD_u8PHASE_THREE;
            }/* if */
          }/* if */
        }/* else */
      }/* else if */
      else/* Phase Three in custom char creation */
      {
        if(LCD_astrLCDsConfig[Loc_u8Counter].Nib1_Flag == FLAG_LOW)/* sending the first nibble */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].Buffer.Data1 = LCD_u8DDRAM_ADD_SET;
          LCD_vidSendCMD_Nib1(Loc_u8Counter);/* synchronous fn */
        }/* if */
        else if(LCD_astrLCDsConfig[Loc_u8Counter].Nib2_Flag == FLAG_LOW)/* sending the second nibble */
        {
          LCD_vidSendCMD_Nib2(Loc_u8Counter);/* synchronous fn */
        }/* else if */
        else/* waiting Phase */
        {
          LCD_astrLCDsConfig[Loc_u8Counter].SendTimer += LCD_u8TICK_TIME;
          if(LCD_astrLCDsConfig[Loc_u8Counter].SendTimer == LCD_astrLCDsConfig[Loc_u8Counter].SendTimerLimit)/* raising the DelayFlag */
          {
            LCD_vidReqReset(Loc_u8Counter);
            Loc_u8Phase = LCD_u8PHASE_ONE;
          }/* if */
        }/* else */
      }/* else */
    }/* if */
  }/* for */

  // LCD_vidSendCommand(LCD_u8DDRAM_ADD_SET);
  // LCD_astrLCDsConfig[Loc_u8Counter].Request = LCD_enuIdle;
}/* LCD_vidCreateChar_P */
/* ************************************************************************************** */
/* ************************ Private Fns ************************************************* */
/* 
  Description     : Private Fn to send command first nibble to the LCD
  Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Return          : Void
  ////////////////////// Synchronous //////////////////////
*/
static void LCD_vidSendCMD_Nib1(u8 Copy_u8LCD_Name)
{
  GPIO_tstrPin Loc_strPinCfg;/* Pin configurations to use in setting the pin value */
  Loc_strPinCfg.Port = LCD_astrLCDsConfig[Copy_u8LCD_Name].Port;
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RS_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RW_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);/* Raising the enable pin */
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB7_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT7)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB6_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT6)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB5_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT5)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB4_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT4)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);/* Lowering the enable pin */
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib1_Flag = FLAG_HIGH; 
}/* LCD_vidSendCMD_Nib1 */
/* 
  Description     : Private Fn to send command second nibble to the LCD
  Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Return          : Void
  ////////////////////// Synchronous //////////////////////
*/
static void LCD_vidSendCMD_Nib2(u8 Copy_u8LCD_Name)
{
  GPIO_tstrPin Loc_strPinCfg;/* Pin configurations to use in setting the pin value */
  Loc_strPinCfg.Port = LCD_astrLCDsConfig[Copy_u8LCD_Name].Port;
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RS_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RW_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);/* Raising the enable pin */
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB7_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT3)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB6_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT2)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB5_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT1)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB4_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT0)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);/* Lowering the enable pin */
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib2_Flag = FLAG_HIGH;
}/* LCD_vidSendCMD_Nib2 */
/* 
  Description     : Private Fn to send data first nibble to the LCD
  Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Return          : Void
  ////////////////////// Synchronous //////////////////////
*/
static void LCD_vidSendDataNib1(u8 Copy_u8LCD_Name)
{
  GPIO_tstrPin Loc_strPinCfg;/* Pin configurations to use in setting the pin value */
  Loc_strPinCfg.Port = LCD_astrLCDsConfig[Copy_u8LCD_Name].Port;
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RS_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RW_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);/* Raising the enable pin */
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB7_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT7)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB6_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT6)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB5_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT5)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB4_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT4)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);/* Lowering the enable pin */
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib1_Flag = FLAG_HIGH;
}/* LCD_vidSendDataNib1 */
/* 
  Description     : Private Fn to send data second nibble to the LCD
  Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Return          : Void
  ////////////////////// Synchronous //////////////////////
*/
static void LCD_vidSendDataNib2(u8 Copy_u8LCD_Name)
{
  GPIO_tstrPin Loc_strPinCfg;/* Pin configurations to use in setting the pin value */
  Loc_strPinCfg.Port = LCD_astrLCDsConfig[Copy_u8LCD_Name].Port;
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RS_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].RW_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuHigh);/* Raising the enable pin */
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB7_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT3)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB6_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT2)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB5_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT1)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].DB4_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, ((LCD_astrLCDsConfig[Copy_u8LCD_Name].Buffer.Data1)>>LCD_u8BIT0)&LCD_u8CMD_SPLIT);
  Loc_strPinCfg.Pins = LCD_astrLCDsConfig[Copy_u8LCD_Name].E_Pin;
  GPIO_enuSetPinValue(&Loc_strPinCfg, GPIO_enuLow);/* Lowering the enable pin */
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib2_Flag = FLAG_HIGH;
}/* LCD_vidSendDataNib2 */
/* 
  Description     : Private Fn to send LCD request and lower flags and reset the tick timer of the LCD
  Parameter1      : LCD name, options are in "LCD_cfg.h" under "Connected LCDs"
  Return          : Void
  ////////////////////// Synchronous //////////////////////
*/
static void LCD_vidReqReset(u8 Copy_u8LCD_Name)
{
  LCD_astrLCDsConfig[Copy_u8LCD_Name].SendTimer = ZERO_INIT;
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib1_Flag = FLAG_LOW;
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Nib2_Flag = FLAG_LOW;
  LCD_astrLCDsConfig[Copy_u8LCD_Name].Request = LCD_enuIdle;
}/* LCD_vidReqReset */
/* ************************************************************************************** */
