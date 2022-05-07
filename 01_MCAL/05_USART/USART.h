/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	USART
**       Description :	USART module file
** **************************************************************************************/
#ifndef _USART_H
#define _USART_H
  /* ////////////////////////// Headers inclusion //////////////////////////////////////// */
  #include "STM32F401CC.h"
  /* ///////////////////////////////////////////////////////////////////////////////////// */
  
  /* ////////////////////////// Defined Types //////////////////////////////////////////// */
  /* Status type */
  typedef enum
  {
    USART_enuOk,
    USART_enuNok
  }USART_tenuStatus;
  /* USART configurations */
  typedef struct
  { 
    f32 BaudRate;       /* Set your baud rate, the unit is kbps                           */
    u16 StopBits;       /* available options are in "USART.h" under "Stop bits"           */
    u16 Parity;         /* availabe options are in "USART.h" under "Parity options"       */   
    u16 Oversampling;   /* availabe options are in "USART.h" under "Oversampling options" */
    u16 WordLength;     /* availabe options are in "USART.h" under "Word length options"  */
    u8  Frequency;      /* Set your working frequency in "MHZ"                            */
  }USART_tstrConfig;
  /* USART Specs */
  typedef struct
  {
    tpfCallback Callback;    /* Address of callback fn                                        */
    tstrBuffer  Buffer;      /* the buffer                                                    */
    u8          BusID;       /* available options are in "USART.h" under "USARTs Busses IDs"  */
  }USART_tstrSpecs;
  /* //////////////////////////////////////////////////////////////////////////////////// */
  
  /* ////////////////////////////////// MACROS ////////////////////////////////////////// */
  /* USARTs Busses IDs */
  #define USART_u8BUS1                                              ((u8)0)  /* connected on APB2 */
  #define USART_u8BUS2                                              ((u8)1)  /* connected on APB1 */
  #define USART_u8BUS6                                              ((u8)2)  /* connected on APB2 */
  /* Parity options */
  #define USART_u16PARITY_OFF                                       ((u16)0x0000)
  #define USART_u16PARITY_EVEN                                      ((u16)0x0400)
  #define USART_u16PARITY_ODD                                       ((u16)0x0600)
  /* Oversampling options */
  #define USART_u16OVERSAMP_8                                       ((u16)0x8000)
  #define USART_u16OVERSAMP_16                                      ((u16)0x0000)
  /* Word length options */
  #define USART_u16_8BIT                                            ((u16)0x0000)
  #define USART_u16_9BIT                                            ((u16)0x1000)
  /* Stop bits */
  #define USART_u16_ONE_BIT                                         ((u16)0x0000)
  #define USART_u16_TWO_BIT                                         ((u16)0x2000)
  /* //////////////////////////////////////////////////////////////////////////////////// */

  /* ///////////////////////////////// Interface Fns //////////////////////////////////// */
  /* 
    Description         :     Init the USART
    Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
    Parameter2          :     Address of the configurations struct of type "USART_tstrConfig" defined in "USART.h"
    Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_tenuStatus USART_enuInit(USART_tstrSpecs* Copy_pstrSpecs, USART_tstrConfig* Copy_pstrConfig);
  /* 
    Description         :     starting sending of buffer on USART channel
    Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
    Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
    ////////////////////// Asynchronous //////////////////////
  */
  USART_tenuStatus USART_enuSendBufferZeroCopy(USART_tstrSpecs* Copy_pstrSpecs);
  /* 
    Description         :     Enable receiving of buffer on USART channel
    Parameter1          :     Address of the specs struct of type "USART_tstrSpecs" defined in "USART.h"
    Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
    ////////////////////// Asynchronous //////////////////////
  */
  USART_tenuStatus USART_enuReceiveBuffer(USART_tstrSpecs* Copy_pstrSpecs);
  /* //////////////////////////////////////////////////////////////////////////////////// */
#endif
