/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 12, 2022
**       Version     :	V01
**       SWC         :	GPIO
**       Description :	GPIO module files
** **************************************************************************************/
/* Header files inclusion */
#include "StdTypes.h"
#include "STM32F401CC.h"
#include "GPIO.h"
#include "GPIO_prv.h" 
#include "GPIO_cfg.h"
/* ******************************************************************************************* */
/* *********************** Interface Fns ***************************************************** */
/* 
  Fn: Init the passed pin(s) configurations
  Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Defined Types' section
  Parameter: 'GPIO_tstrPinConfig' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
*/
GPIO_tenuStatus GPIO_enuInitPin(GPIO_tstrPinConfig* Copy_pstrPinConfig)
{
  GPIO_tenuStatus Loc_enuStatus = GPIO_enuOk;
  GPIO_tstrRegisters* Loc_pstrGPIO;
  u32 Loc_u32ModeTemp;
  u32 Loc_u32SpeedTemp;
  u32 Loc_u32ResistorTemp;

  if(Copy_pstrPinConfig != NULL)
  {
    Loc_pstrGPIO = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrPinConfig->Port);/* Defining a pointer the required port registers */
    Loc_u32ModeTemp = Loc_pstrGPIO->MODER;/* Temp var to hold bits modes before setting to actual register */
    Loc_u32SpeedTemp = Loc_pstrGPIO->OSPEEDR;/* Temp var to hold bits modes before setting to actual register */
    Loc_u32ResistorTemp = Loc_pstrGPIO->PUPDR;/* Temp var to hold bits modes before setting to actual register */
    /* Setting the mode and output speed of the passed pins */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN0)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT0);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT0);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT0);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT0);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT0);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT0);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN1)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT1);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT1);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT1);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT1);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT1);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT1);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN2)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT2);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT2);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT2);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT2);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT2);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT2);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN3)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT3);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT3);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT3);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT3);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT3);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT3);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN4)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT4);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT4);
      Loc_u32SpeedTemp &= ~(Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT4);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT4);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT4);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT4);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN5)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT5);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT5);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT5);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT5);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT5);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT5);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN6)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT6);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT6);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT6);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT6);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT6);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT6);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN7)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT7);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT7);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT7);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT7);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT7);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT7);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN8)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT8);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT8);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT8);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT8);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT8);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT8);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN9)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT9);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT9);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT9);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT9);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT9);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT9);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN10)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT10);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT10);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT10);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT10);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT10);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT10);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN11)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT11);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT11);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT11);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT11);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT11);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT11);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN12)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT12);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT12);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT12);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT12);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT12);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT12);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN13)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT13);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT13);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT13);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT13);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT13);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT13);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN14)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT14);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT14);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT14);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT14);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT14);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT14);
    }/* if */
    if(Copy_pstrPinConfig->Pins&GPIO_u16PIN15)
    {
      Loc_u32ModeTemp &= ~(GPIO_u8CLR_MODE << GPIO_u8BIT15);
      Loc_u32ModeTemp |= (Copy_pstrPinConfig->Mode << GPIO_u8BIT15);
      Loc_u32SpeedTemp &= ~(GPIO_u8CLR_SPEED << GPIO_u8BIT15);
      Loc_u32SpeedTemp |= (Copy_pstrPinConfig->OutSpeed << GPIO_u8BIT15);
      Loc_u32ResistorTemp &= ~(GPIO_u8CLR_Resistor << GPIO_u8BIT15);
      Loc_u32ResistorTemp |= (Copy_pstrPinConfig->PullRes << GPIO_u8BIT15);
    }/* if */
    Loc_pstrGPIO->MODER   =  Loc_u32ModeTemp;/* Setting the local variable to the actual register */
    Loc_pstrGPIO->OSPEEDR =  Loc_u32SpeedTemp;
    Loc_pstrGPIO->PUPDR   =  Loc_u32ResistorTemp;
    /* Setting Output type */
    switch(Copy_pstrPinConfig->OutType)
    {
    case (GPIO_u8OPEN_DRAIN):
      Loc_pstrGPIO->OTYPER |= Copy_pstrPinConfig->Pins;
      break;
    case (GPIO_u8PUSH_PULL):
      Loc_pstrGPIO->OTYPER &= ~(Copy_pstrPinConfig->Pins);
      break;
    case (GPIO_u8NA_TYPE):
      break;
    default:
      Loc_enuStatus = GPIO_enuNok;
    }/* switch */
  }/* if */
  else
  {
    Loc_enuStatus = GPIO_enuNok;
  }/* else */
  
  return(Loc_enuStatus);
}/* GPIO_enuInitPin */

/* 
  Fn: set the passed pin value
  Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Defined Types' section
  Parameter1: 'GPIO_tstrPin' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
  Parameter2: 'GPIO_tenuPinLevel' enum defining the level, possible values are in GPIO.h under 'Defined Types' section
*/
GPIO_tenuStatus GPIO_enuSetPinValue(GPIO_tstrPin* Copy_pstrPin, GPIO_tenuPinLevel Copy_enuPinLevel)
{
  GPIO_tenuStatus Loc_enuStatus = GPIO_enuOk;/* Defining the error status variable */
  GPIO_tstrRegisters* Loc_pstrGPIO;
  if((Copy_pstrPin != NULL) && ((Copy_enuPinLevel == GPIO_enuHigh) || (Copy_enuPinLevel == GPIO_enuLow)))/* validate passed Arguments */
  {
    Loc_pstrGPIO = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrPin->Port); /* Defining a pointer the required port registers */
    switch(Copy_enuPinLevel)/* Validate the passed level */
    {
    case(GPIO_enuLow):
      Loc_pstrGPIO->ODR &= ~Copy_pstrPin->Pins;
      break;
    case(GPIO_enuHigh):
      Loc_pstrGPIO->ODR |=  Copy_pstrPin->Pins;
      break;
    default:
      Loc_enuStatus = GPIO_enuNok;
    }/* switch */
  }/* if */
  else
  {
    Loc_enuStatus = GPIO_enuNok;
  }/* else */

  return(Loc_enuStatus);/* Returning the status of the function functionality */
}/* GPIO_enuSetPinValue */

/*  
  Fn: return the passed pin(s) input value as a u16 value and each bit represent the corresponding bit
  Return: 'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Defined Types' section
  Parameter1: 'GPIO_tstrPin' structure defining the pin, possible values are in GPIO.h under 'Defined Types' section
  Parameter2: pointer to u8 variable to store the pin value
*/
GPIO_tenuStatus GPIO_enuGetPinValue(GPIO_tstrPin* Copy_pstrPin, pu16 Copy_pu16PinValue)
{
  GPIO_tenuStatus Loc_enuStatus = GPIO_enuOk;
  GPIO_tstrRegisters* Loc_pstrRegisters;
  if((Copy_pstrPin != NULL) && (Copy_pu16PinValue != NULL))/* validate passed arguments */
  {
    Loc_pstrRegisters = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrPin->Port);/* initialize the pointer to point to the needed port registers */
    *Copy_pu16PinValue = Loc_pstrRegisters->IDR;
  }/* if */
  else
  {
    Loc_enuStatus = GPIO_enuNok;
  }/* else */
  return(Loc_enuStatus);/* Returning the error status of the fn */
}/* GPIO_enuGetPinValue */
/* 
  Fn: set and reset the passed pins
  Return:     'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
  Parameter1: 'GPIO_tstrPin' structure defining the pins to be set, possible values are in GPIO.h under 'Pins selection structure' section
  Parameter2: 'GPIO_tstrPin' structure defining the pins to be reset, possible values are in GPIO.h under 'Pins selection structure' section
  ****Caution****: The port you send in the SetPins is the dominant port (will be selected for reset)
*/
GPIO_tenuStatus GPIO_enuSetResetPins(GPIO_tstrPin* Copy_pstrSetPins, GPIO_tstrPin* Copy_pstrResetPins)
{
  GPIO_tenuStatus Loc_enuError = GPIO_enuOk;/* Initializing the error variable */
  GPIO_tstrRegisters* Loc_pstrGPIO;
  if((Copy_pstrSetPins != NULL) && (Copy_pstrResetPins != NULL))/* validate passed Arguments */
  {
    Loc_pstrGPIO = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrSetPins->Port); /* Defining a pointer the required port registers */
    Loc_pstrGPIO->BSRR = (Copy_pstrSetPins->Pins) | (Copy_pstrResetPins->Pins << GPIO_u8SHIFT_VAL);
  }/* if */
  else
  {
    Loc_enuError = GPIO_enuNok;
  }/* else */ 

  return(Loc_enuError); /* returning the error status */
}/* GPIO_enuSetResetPins */
/* 
  Fn: Lock the passed pins configuration tell next reset
  Return:     'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
  Parameter1: 'GPIO_tstrPin' structure defining the pins, possible values are in GPIO.h under 'Pins selection structure' section
*/
GPIO_tenuStatus GPIO_enuLockPinConfig(GPIO_tstrPin* Copy_pstrPin)
{
  GPIO_tenuStatus Loc_enuError = GPIO_enuOk;/* Initial error variable */
  u32 Loc_u32Temp = GPIO_u32TEMP_INIT;
  GPIO_tstrRegisters* Loc_pstrRegisters;
  if(Copy_pstrPin != NULL) /* Validating arguments */
  {
    Loc_pstrRegisters = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrPin->Port);
    Loc_u32Temp = Copy_pstrPin->Pins;/* Applying the bits to lock its config */
    Loc_pstrRegisters->LCKR = Loc_u32Temp;
    /* Applying the locking sequence */
    Loc_u32Temp |= GPIO_u32LCK_MASK;/* Applying '1' */
    Loc_pstrRegisters->LCKR = Loc_u32Temp;
    Loc_u32Temp &= ~GPIO_u32LCK_MASK;/* Applying '0' */
    Loc_pstrRegisters->LCKR = Loc_u32Temp;
    Loc_u32Temp |= GPIO_u32LCK_MASK;/* Applying '1' */
    Loc_pstrRegisters->LCKR = Loc_u32Temp;
    Loc_u32Temp  = Loc_pstrRegisters->LCKR;
    Loc_u32Temp  = Loc_pstrRegisters->LCKR;
  }/* if */
  else
  {
    Loc_enuError = GPIO_enuNok;
  }/* else */

  return(Loc_enuError);/* Returning Error status */
}/* GPIO_enuLockPinConfig */
/* 
  Fn        :  Select the pin alternate function
  Return    :  'GPIO_tenuStatus' status, possible values are in GPIO.h under 'Error Types' section
  Parameter1:  'GPIO_tstrPin' structure defining the pins, possible values are in GPIO.h under 'Pins selection structure' section
  Parameter2:  The alternate function number, options are from 0(defaule=GPIO) to 15 
*/
GPIO_tenuStatus GPIO_enuSelectAF(GPIO_tstrPin* Copy_pstrPin, u8 Copy_u8AF)
{
  u32 Loc_u32Temp;
  GPIO_tenuStatus Loc_enuError = GPIO_enuOk;
  GPIO_tstrRegisters* Loc_pstrRegisters;
  if((Copy_pstrPin != NULL) && (Copy_u8AF <= 15)) /* Validate Arguments */
  {
    Loc_pstrRegisters = (GPIO_tstrRegisters*)(GPIO_u32BASE_ADD+Copy_pstrPin->Port);
    if(Copy_pstrPin->Pins&GPIO_u16PIN0)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT0));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT0);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN1)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT1));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT1);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN2)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT2));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT2);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN3)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT3));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT3);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN4)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT4));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT4);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN5)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT5));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT5);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN6)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT6));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT6);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN7)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRL;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT7));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT7);
      Loc_pstrRegisters->AFRL = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN8)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT8));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT8);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN9)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT9));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT9);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN10)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT10));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT10);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN11)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT11));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT11);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN12)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT12));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT12);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN13)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT13));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT13);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN14)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT14));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT14);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */
    if(Copy_pstrPin->Pins&GPIO_u16PIN15)
    {
      Loc_u32Temp = Loc_pstrRegisters->AFRH;
      Loc_u32Temp &= (~(GPIO_u8SET_4BIT << GPIO_u8AF_BIT15));
      Loc_u32Temp |= (Copy_u8AF << GPIO_u8AF_BIT15);
      Loc_pstrRegisters->AFRH = Loc_u32Temp;
    }/* if */      
  }/* if */
  else
  {
    Loc_enuError = GPIO_enuNok;
  }/* else */

  return(Loc_enuError);
}/* GPIO_enuSelectAF */
/* ******************************************************************************************* */
/* ******************************************************************************************* */