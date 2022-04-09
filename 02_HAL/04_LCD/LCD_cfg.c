/* **************************************************************************************
**       Author      :	Michael  S. Ibrahim
**       Date        :	April 06, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD driver files
** **************************************************************************************/
/* ************************ Headers inclusion ***************************** */
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "GPIO.h"
/* Own headers */
#include "LCD.h"
#include "LCD_cfg.h"
/* ************************************************************************ */
/* *********************** Global variables ******************************* */
/* Configurations array */
LCD_tstrConfig LCD_astrLCDsConfig[] = 
{
  [LCD_u8LCD_ONE] = 
  {
    .Port    = GPIO_u16PORT0,  
    .RS_Pin  = GPIO_u16PIN0,     
    .RW_Pin  = GPIO_u16PIN1,    
    .E_Pin   = GPIO_u16PIN2,   
    .DB4_Pin = GPIO_u16PIN3, 
    .DB5_Pin = GPIO_u16PIN4, 
    .DB6_Pin = GPIO_u16PIN5, 
    .DB7_Pin = GPIO_u16PIN6,
    .State   = LCD_enuNone
  }
};
/* ************************************************************************ */