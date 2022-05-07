/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	Lab5
**       Description :	Lab5 Test code
** **************************************************************************************/
/* //////////////////////////////// Headers inclusion /////////////////////////////////////// */
//#include "diag/Trace.h"
/* LIB headers */
#include "StdTypes.h"
/* MCAL headers */
#include "USART.h"
#include "GPIO.h"
#include "NVIC.h"
#include "RCC.h"
/* HAL headers */
#include "Led.h"
#include "USART_Test.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Global Variables //////////////////////////////////////// */
static u8 State = LED_u8OFF;
u8 Characters[1024] = {0};
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// main Fn ///////////////////////////////////////////////// */
int main(void)
{
	u16 Loc_u16Counter = ZERO_INIT;
	GPIO_tstrPin Loc_strTxAFPin =
	{
		.Pins = GPIO_u16PIN9,
		.Port = GPIO_u16PORT0
	};
	GPIO_tstrPin Loc_strRxAFPin =
	{
		.Pins = GPIO_u16PIN10,
		.Port = GPIO_u16PORT0
	};
	GPIO_tstrPinConfig Loc_strTxConfig =
	{
		.Mode = GPIO_u8AF,       /* select of the 'Available Modes' in GPIO.h          , under 'STD types options' section*/
		.OutType = GPIO_u8PUSH_PULL,    /* select of the 'Available Out Types' in GPIO.h      , under 'STD types options' section */
		.OutSpeed= GPIO_u8LOW_SPEED,   /* select of the 'Available Out Speed' in GPIO.h      , under 'STD types options' section  */
		.PullRes = GPIO_u8NO_PUPD,    /* select of the 'Available Pull Resistors' in GPIO.h , under 'STD types options' section*/
		.Pins = GPIO_u16PIN9,       /* select of the 'Available Pins' in GPIO.h           , under 'STD types options' section*/
		.Port = GPIO_u16PORT0
	};
	GPIO_tstrPinConfig Loc_strRxConfig =
	{
		.Mode = GPIO_u8AF,       /* select of the 'Available Modes' in GPIO.h          , under 'STD types options' section*/
		.OutType = GPIO_u8PUSH_PULL,    /* select of the 'Available Out Types' in GPIO.h      , under 'STD types options' section */
		.OutSpeed= GPIO_u8LOW_SPEED,   /* select of the 'Available Out Speed' in GPIO.h      , under 'STD types options' section  */
		.PullRes = GPIO_u8NO_PUPD,    /* select of the 'Available Pull Resistors' in GPIO.h , under 'STD types options' section*/
		.Pins = GPIO_u16PIN10,       /* select of the 'Available Pins' in GPIO.h           , under 'STD types options' section*/
		.Port = GPIO_u16PORT0
	};
  USART_tstrConfig Loc_strUSART_Config =
  { 
    .StopBits     = USART_u16_ONE_BIT,
    .Parity       = USART_u16PARITY_OFF,
    .BaudRate     = (f32)9.6,
    .Oversampling = USART_u16OVERSAMP_16,
    .WordLength   = USART_u16_8BIT,
    .Frequency    = (u8)16
  };
  USART_tstrSpecs Loc_strUSART_Specs =
  {
	  .Callback = USART_Test_vidCallbackFn,
	  .Buffer   =
	  {
		.Data  = Characters,
		.Size  = (u32)20,
		.Index = (u32)0
	  },
	  .BusID    = USART_u8BUS1
  };

  for(; Loc_u16Counter < 1024; Loc_u16Counter++)
  {
	  Characters[Loc_u16Counter] = '5';
  }

  Led_enuInit();
  RCC_enuPerClk(RCC_enuUSART1,RCC_enuOn);
  NVIC_enuEnableIRQ(NVIC_enuUSART1);
  GPIO_enuInitPin(&Loc_strTxConfig);
  GPIO_enuInitPin(&Loc_strRxConfig);
  GPIO_enuSelectAF(&Loc_strTxAFPin, 7);
  GPIO_enuSelectAF(&Loc_strRxAFPin, 7);

  USART_enuInit(&Loc_strUSART_Specs, &Loc_strUSART_Config);
  USART_enuSendBufferZeroCopy(&Loc_strUSART_Specs);

  while(1)
  {
	  Led_enuSet(LED_u8MIL,State);
	  USART_enuSendBufferZeroCopy(&Loc_strUSART_Specs);
  }
  return(0); 
}/* main */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////// App callback Fn ///////////////////////////////////////// */
void USART_Test_vidCallbackFn(void)
{
	State ^= 1;
}/* USART_Test_vidCallbackFn */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
