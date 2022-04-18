/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	Lab5
**       Description :	Lab5 Test code
** **************************************************************************************/
/* //////////////////////////////// Headers inclusion /////////////////////////////////////// */
#include "diag/Trace.h"
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "USART.h"
#include "GPIO.h"
#include "NVIC.h"
#include "RCC.h"
/* HAL headers */
#include "Led.h"
/* Own headers */
#include "Lab5.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////// Global Variables //////////////////////////////////////// */
static u8 State = LED_u8OFF;
/* ////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////// main Fn ///////////////////////////////////////////////// */
int main(void)
{
	GPIO_tstrPin Loc_strAFPin =
	{
		.Pins = GPIO_u16PIN9,
		.Port = GPIO_u16PORT0
	};
	GPIO_tstrPinConfig Loc_strPinConfig =
	{
		.Mode = GPIO_u8AF,       /* select of the 'Available Modes' in GPIO.h          , under 'STD types options' section*/
		.OutType = GPIO_u8PUSH_PULL,    /* select of the 'Available Out Types' in GPIO.h      , under 'STD types options' section */
		.OutSpeed= GPIO_u8LOW_SPEED,   /* select of the 'Available Out Speed' in GPIO.h      , under 'STD types options' section  */
		.PullRes = GPIO_u8NO_PUPD,    /* select of the 'Available Pull Resistors' in GPIO.h , under 'STD types options' section*/
		.Pins = GPIO_u16PIN9,       /* select of the 'Available Pins' in GPIO.h           , under 'STD types options' section*/
		.Port = GPIO_u16PORT0
	};
  USART_tstrConfig Loc_strUSART_Config = 
  { 
    .BusNumber    = USART_u32BUS1,
    .StopBits     = USART_u16_ONE_BIT,
    .Parity       = USART_u16PARITY_OFF,
    .BaudRate     = (f32)9.6,
    .Oversampling = USART_u16OVERSAMP_16,
    .WordLength   = USART_u16_8BIT,
    .Frequency    = (u8)16
  };
  Led_enuInit();
  RCC_enuPerClk(RCC_enuUSART1,RCC_enuOn);
  NVIC_enuEnableIRQ(NVIC_enuUSART1);
  GPIO_enuInitPin(&Loc_strPinConfig);
  GPIO_enuSelectAF(&Loc_strAFPin, 7);
  USART_enuRegTxCallbackFn(USART_u8NUM1, Lab5_vidCallbackFn);
  USART_enuInit(&Loc_strUSART_Config);
  USART_enuSendByte(USART_u32BUS1, 0xFF);

  while(1)
  {
	  Led_enuSet(LED_u8BLUE,State);
  }
  return(0); 
}/* main */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////// App callback Fn ///////////////////////////////////////// */
void Lab5_vidCallbackFn(void)
{
	State ^= 1;
	USART_enuSendByte(USART_u32BUS1, 0xFF);

}/* Lab5_vidCallbackFn */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
