/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	USART
**       Description :	USART module file
** **************************************************************************************/
#ifndef _USART_H
#define _USART_H
  /* ////////////////////////// Headers inclusion /////////////////////////////////////// */
  #include "STM32F401CC.h"
  /* ///////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////// Defined Types /////////////////////////////////////////// */
  /* Error type */
  typedef enum
  {
    USART_enuOk,
    USART_enuNok
  }USART_tenuError;
  /* USART configurations */
  typedef struct
  { 
    f32 BaudRate;       /* Set your baud rate, the unit is kbps                           */
    u32 BusNumber;      /* available options are in "USART.h" under "Used USARTs"         */
    u16 StopBits;       /* available options are in "USART.h" under "Stop bits"           */
    u16 Parity;         /* availabe options are in "USART.h" under "Parity options"       */   
    u16 Oversampling;   /* availabe options are in "USART.h" under "Oversampling options" */
    u16 WordLength;     /* availabe options are in "USART.h" under "Word length options"  */
    u8  Frequency;      /* Set your working frequency in "MHZ" */
  }USART_tstrConfig;
  /* //////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////////////// MACROS ////////////////////////////////////////// */
  /* Used USARTs */
  #define USART_u32BUS1                                             ((u32)USART1_u32BASE_ADD)  /* connected on APB2 */
  #define USART_u32BUS2                                             ((u32)USART2_u32BASE_ADD)  /* connected on APB1 */
  #define USART_u32BUS6                                             ((u32)USART6_u32BASE_ADD)  /* connected on APB2 */
  /* USARTs IDs */
  #define USART_u8NUM1                                              0
  #define USART_u8NUM2                                              1
  #define USART_u8NUM6                                              2
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
    Parameter1          :     Address of the configurations struct of type "USART_tstrConfig" defined in "USART.h"
    Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_tenuError USART_enuInit(USART_tstrConfig* Copy_pstrConfig);
  /* 
    Description         :     Send byte on the USART
    Parameter1          :     The bus no, options are in "USART.h" under "Used USARTs"
    Parameter2          :     the byte
    Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_tenuError USART_enuSendByte(u32 Copy_u32BusNumber, u8 Copy_u8Byte);
  /* 
    Description         :     Register the USART interrupt callback fn , called on DR empty and transmission complete
    Parameter1          :     The bus ID, available options are in "USART.h" under "USARTs IDs"
    Parameter2          :     Address of the callback fn
    Return              :     Error status of type "USART_tenuError", defined in "USART.h" under "Error type" section
    ////////////////////// Synchronous //////////////////////
  */
  USART_tenuError USART_enuRegTxCallbackFn(u8 Copy_u8BusID, tpfCallback Copy_pfCallbackFn);
  /* //////////////////////////////////////////////////////////////////////////////////// */
#endif
