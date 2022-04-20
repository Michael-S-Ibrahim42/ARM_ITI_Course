/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 18, 2022
**       Version     :	V011
**       SWC         :	EXTI
**       Description :	EXTI driver files
** **************************************************************************************/
#include "Std_Types.h"
#include "GPIO.h"

#include "Exti_cfg.h"
#include "Exti_prv.h"
#include "Exti.h"
#include "SYSCFG_prv.h"
#include "SYSCFG.h"


#define NULL	(void*)0x00

/*static void (*EXTI0_CallBack)(void)=NULL;
static void (*EXTI1_CallBack)(void)=NULL;
static void (*EXTI2_CallBack)(void)=NULL;
*/
static void (*EXTI_CallBack[16])(void);//=NULL;

static u8 EXTINum=0;
/*
 * Function : EXTI initialization "Pre-build init"
 * argument : void
 * return   : void
 * */
/*void  EXTI_vidInit(void)
{
	#if	  EXTI_LINE==EXTI_LINE0
	#elif EXTI_LINE==EXTI_LINE1
	#elif EXTI_LINE==EXTI_LINE2
	#elif EXTI_LINE==EXTI_LINE3
	#elif EXTI_LINE==EXTI_LINE4
	#elif EXTI_LINE==EXTI_LINE5
	#elif EXTI_LINE==EXTI_LINE6
	#elif EXTI_LINE==EXTI_LINE7
	#elif EXTI_LINE==EXTI_LINE8
	#elif EXTI_LINE==EXTI_LINE9
	#elif EXTI_LINE==EXTI_LINE10
	#elif EXTI_LINE==EXTI_LINE11
	#elif EXTI_LINE==EXTI_LINE12
	#elif EXTI_LINE==EXTI_LINE13
	#elif EXTI_LINE==EXTI_LINE14
	#elif EXTI_LINE==EXTI_LINE15
	#else
		#error ("WRONG EXTERNAL INTERRUPT LINE")


	#if EXTI_SENSE_MODE==RISING_EDGE
	#elif EXTI_SENSE_MODE==FALLING_EDGE
	#elif EXTI_SENSE_MODE==ON_CHANGE
	#else
		#error ("WRONG SENSE MODE")
}

*/
/*
 * Function : EXTI set signal latch
 * argument : Exti line and EXTI sense mode (Edge,Level,IOC)
 * return   : void
 *	Description : Initialization function but in run time
 * */

void  EXTI_vidSetSignalLatch(u8 Copy_u8ExtiLine,u8 Copy_u8SenseMode)
{
	switch (Copy_u8SenseMode)
	{
		case FALLING_EDGE:
			EXTI->FTSR |= 1<<Copy_u8ExtiLine;
			break;

		case RISING_EDGE:
			EXTI->RTSR |= 1<<Copy_u8ExtiLine;
			break;

		case ON_CHANGE:
			EXTI->RTSR |= 1<<Copy_u8ExtiLine;
			EXTI->FTSR |= 1<<Copy_u8ExtiLine;
			break;

	}
	EXTI->IMR |= 1<<Copy_u8ExtiLine;

}


/*
 * Function : Enable EXTI
 * argument : EXTI line
 * return   : void
 * */
void  EXTI_vidEnableExti(u8 Copy_u8ExtiLine)
{
	EXTI->IMR |=1<<Copy_u8ExtiLine;			//set bit EXTI line number
}

/*
 * Function : Disable EXTI
 * argument : EXTI line
 * return   : void
 * */

void  EXTI_vidDisableExti(u8 Copy_u8ExtiLine)
{
	EXTI->IMR &= ~(1<<Copy_u8ExtiLine);		//clear bit

}

/*
 * Function : Software trigger "interrupt"
 * argument : EXTI line
 * return   : void
 * */

void  EXTI_vidSoftwareTrigger(u8 Copy_u8ExtiLine)
{
	EXTI->SWIER|=1<<Copy_u8ExtiLine;
}

/*
 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI
 * */
void EXTI_vidSetCallBack(void (*ptr) (void),u8 Copy_u8EXTINum)
{
	EXTINum=Copy_u8EXTINum;
	if(ptr!=NULL)
		EXTI_CallBack[EXTINum]=ptr;
}


/*
 * Function : EXTI_Handler  function
 * argument : void
 * return   : void
 * Description : EXTI Handler
 * */
void EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack[EXTINum]!=NULL)
		EXTI_CallBack[EXTINum]();
	EXTI->PR|=1<<EXTINum;
}


/*
 * Function : EXTI_Handler  function
 * argument : void
 * return   : void
 * Description : EXTI1 Handler
 * */
/*void EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[1]!=NULL)
		EXTI_CallBack[1]();
	EXTI->PR|=1<<1;
}


/*
 * Function : EXTI_Handler  function
 * argument : void
 * return   : void
 * Description : EXTI2 Handler
 * */
/*void EXTI2_IRQHandler(void)
{
	if(EXTI_CallBack[2]!=NULL)
		EXTI_CallBack[2]();
	EXTI->PR|=1<<2;
}*/


/*void EXTI0_vidSetCallBack(void (*ptr) (void))
{
	if(ptr!=NULL)
		EXTI0_CallBack=ptr;
}




void EXTI1_vidSetCallBack(void (*ptr) (void))
{
	if(ptr!=NULL)
		EXTI_CallBack=ptr;
}



 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI2
 * */
/*void EXTI2_vidSetCallBack(void (*ptr) (void))
{
	if(ptr!=NULL)
		EXTI2_CallBack=ptr;
}

*/


