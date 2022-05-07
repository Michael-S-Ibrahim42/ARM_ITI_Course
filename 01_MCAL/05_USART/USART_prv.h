/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 10, 2022
**       Version     :	V01
**       SWC         :	USART
**       Description :	USART module file
** **************************************************************************************/
#ifndef _USART_PRV_H
#define _USART_PRV_H
  /* ////////////////////////////////// MACROS ////////////////////////////////////////// */
  /* USART enable */
  #define USART_u16_ENABLE                                            ((u16)0x2000)
  /* Transmitter enable */
  #define USART_u16_TX_ENABLE                                         ((u16)0x0008)
  /* Receiver enable */
  #define USART_u16_RX_ENABLE                                         ((u16)0x0004)
  /* Data Register is empty interrupt */
  #define USART_u16_TXE_ENABLE                                        ((u16)0x0080)
  /* Transmission complete interrupt */
  #define USART_u16_TXC_ENABLE                                        ((u16)0x0040)
  /* Reception complete interrupt */
  #define USART_u16_RXNE_ENABLE                                       ((u16)0x0020)
  /* Bits locations masks */
  #define USART_u8OVER8                                               ((u8)15)
  /* Units Factors */
  #define USART_u32MEGA_FACTOR                                        ((u32)1000000)
  #define USART_u16KILO_FACTOR                                        ((u16)1000)
  /* oversampling values */
  #define USART_u8MAX_OVERSAMP                                        ((u8)16)
  #define USART_u8MIN_OVERSAMP                                        ((u8)8)
  /* Slicing Values */
  #define USART_u8SHIFT_POINT_RIGHT                                   ((u8)10)
  #define USART_u8FIRST_DIG_SLICER                                    ((u8)10)
  #define USART_u8ROUNDING_CENTER                                     ((u8)5)
  /* Bits max values */
  #define USART_u8THREE_BIT_MAX                                       ((u8)7)
  #define USART_u8FOUR_BIT_MAX                                        ((u8)15)
  /* bits shift values */
  #define USART_u8MANT_SHIFT                                          ((u8)4)
  #define USART_u8TXE_SHIFT                                           ((u8)7)
  #define USART_u8TXC_SHIFT                                           ((u8)6)
  #define USART_u8RXNE_SHIFT                                          ((u8)5)
  /* Available USARTs */
  #define USART_u8AVAIL_BUSES                                         ((u8)3)
  /* Communication Flags Masks */
  #define USART_u8TXC_FLAG                                            ((u8)(0x40))
  #define USART_u8RXNE_FLAG                                           ((u8)(0x20))
  /* //////////////////////////////////////////////////////////////////////////////////// */

  /* ////////////////////////// Private fns ///////////////////////////////////////////// */
  /* 
    Description         :     Send byte on the USART
    Parameter1          :     The byte
    Return              :     Error status of type "USART_tenuStatus", defined in "USART.h" under "Status type" section
    ////////////////////// Synchronous //////////////////////
  */
  static USART_tenuStatus USART_enuSendByte(u8 Copy_u8BusID);
  /* //////////////////////////////////////////////////////////////////////////////////// */

#endif
