/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 29, 2022
**       Version     :	V01
**       SWC         :	OS_Test
**       Description :	OS Test App layer
** **************************************************************************************/
/* ///////////////////////////// Headers /////////////////////////// */
/* LIB */
#include "StdTypes.h"
/* OS */
#include "Core.h"
/* MCAL */
#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "USART.h"
/* Tracing */
#include "diag/Trace.h"
/* Own headers */
#include "OS_Test.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////// MACROS //////////////////////////////////////////////// */
#define SIZE				1
/* /////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Global Variables //////////////////////////////////////// */
u8 Characters[SIZE] = {0};
USART_tstrSpecs strUSART_Specs =
{
	  .Callback = vidTxCompleteCallbackFn,
	  .Buffer   =
	  {
      .Data  = Characters,
      .Size  = (u32)SIZE,
      .Index = (u32)0
	  },
	  .BusID    = USART_u8BUS1
};
/* Tasks Stacks */
u32 T1_Stack[TASK_STACK_SIZE];
u32 T2_Stack[TASK_STACK_SIZE];

/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Entry Point ////////////////////// */
int main(void)
{
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
  RCC_enuTurnClk(RCC_u8HSI, RCC_enuOn);
  RCC_enuSelectSysClk(RCC_u8RUN_HSI);
  RCC_enuPerClk(RCC_enuUSART1,RCC_enuOn);
  NVIC_enuEnableIRQ(NVIC_enuUSART1);
  GPIO_enuInitPin(&Loc_strTxConfig);
  GPIO_enuInitPin(&Loc_strRxConfig);
  GPIO_enuSelectAF(&Loc_strTxAFPin, 7);
  GPIO_enuSelectAF(&Loc_strRxAFPin, 7);
  USART_enuInit(&strUSART_Specs, &Loc_strUSART_Config);
  
  OS_vidCreateTask(T1, 0, T1_Stack, TASK_STACK_SIZE);
  OS_vidCreateTask(T2, 1, T2_Stack, TASK_STACK_SIZE);
  OS_vidStart();

  // USART_enuSendBufferZeroCopy(&strUSART_Specs);
  // USART_enuReceiveBuffer(&strUSART_Specs);

  while(1)
  {

  }/* while */

  return(0);
}/* main */

/* //////////////////////////////// App callback Fn ///////////////////////////////////////// */
void vidTxCompleteCallbackFn(void)
{
	static u8 Turn = 0;
	if(Turn == 0)
	{
		Turn = 1;
	}
	else
	{
		Turn = 0;
	}
}/* vidTxCompleteCallbackFn */
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////////////// Tasks /////////////////////////////////////////// */
void T1(void)
{
  Characters[0] = 'A';
  USART_enuSendBufferZeroCopy(&strUSART_Specs);
  while(1)
  {
    Characters[0] = 1;
    USART_enuSendBufferZeroCopy(&strUSART_Specs);
    OS_vidDelay(1000);
  }/* while */
}/* T1 */
void T2(void)
{
  Characters[0] = 'B';
  USART_enuSendBufferZeroCopy(&strUSART_Specs);
  while(1)
  {
    Characters[0] = 2;
    USART_enuSendBufferZeroCopy(&strUSART_Specs);
    OS_vidDelay(1000);
  }/* while */
}/* T2 */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
