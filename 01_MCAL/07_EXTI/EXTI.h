/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 18, 2022
**       Version     :	V011
**       SWC         :	EXTI
**       Description :	EXTI driver files
** **************************************************************************************/
#ifndef _EXTI_H
#define _EXTI_H


/*
 * Function : EXTI initialization "Pre-build init"
 * argument : void
 * return   : void
 * */
//void EXTI_vidInit(void);


/*
 * Function : EXTI set signal latch
 * argument : Exti line and EXTI sense mode (Edge,Level,IOC)
 * return   : void
 * */
void EXTI_vidSetSignalLatch(u8 Copy_u8ExtiLine,u8 Copy_u8SenseMode);

/*
 * Function : Enable EXTI
 * argument : EXTI line
 * return   : void
 * */
void EXTI_vidEnableExti(u8 Copy_u8ExtiLine);


/*
 * Function : Disable EXTI
 * argument : EXTI line
 * return   : void
 * */

void EXTI_vidDisableExti(u8 Copy_u8ExtiLine);

/*
 * Function : Software trigger "interrupt"
 * argument : EXTI line
 * return   : void
 * */

void EXTI_vidSoftwareTrigger(u8 Copy_u8ExtiLine);



/*
 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI
 * */
void EXTI_vidSetCallBack(void (*ptr) (void),u8 Copy_u8EXTINum);

/*
 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI0
 * */
//void EXTI0_vidSetCallBack(void (*ptr) (void));

/*
 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI1
 * */
//void EXTI1_vidSetCallBack(void (*ptr) (void));

/*
 * Function : Set call back function
 * argument : Pointer to function of type (argument void and return void)
 * return   : void
 * Description : call back function for EXTI2
 * */
//void EXTI2_vidSetCallBack(void (*ptr) (void));

#endif