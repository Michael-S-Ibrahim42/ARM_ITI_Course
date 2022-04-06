/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	February 03, 2022
**       Version     :	V01
**       SWC         :	BitMath
**       Description :	Bit Manipulation MACROS
** **************************************************************************************/
#ifndef _BITMATH_H
#define _BITMATH_H
  /* //////////////////////////////////// MACROS /////////////////////////////////////////////// */
  #define REG_SIZE                      32
  #define SET_BIT(REG, BIT)             (REG |=  (1 << BIT))
  #define CLR_BIT(REG, BIT)             (REG &= ~(1 << BIT))
  #define GET_BIT(REG, BIT)             ((REG >> BIT) & 1)
  #define RSHFT_REG(REG, NO)            (REG >>= NO)
  #define LSHFT_REG(REG, NO)            (REG <<= NO)
  #define CRSHFT_REG(REG, NO)           (REG = (REG >> NO) | (REG << (REG_SIZE - NO)))
  #define CLSHFT_REG(REG, NO)           (REG = (REG << NO) | (REG >> (REG_SIZE - NO)))
  #define ASSIGN_REG(REG, VALUE)        (REG = VALUE)
  #define TGL_BIT(REG, BIT)             (REG ^= (1<<BIT))
  #define TGL_REG(REG)                  (REG ^= ~(0x00))
  #define SET_H_NIB(BYTE)               (BYTE |= 0xF0)
  #define SET_L_NIB(BYTE)               (BYTE |= 0x0F)
  #define CLR_H_NIB(BYTE)               (BYTE &= 0x0F)
  #define CLR_L_NIB(BYTE)               (BYTE &= 0xF0)
  #define GET_H_NIB(BYTE)               ((BYTE >> 4) & 0x0F)
  #define GET_L_NIB(BYTE)               (BYTE & 0x0F)
  #define ASSIGN_H_NIB(BYTE, VALUE)     (BYTE |= 0xF0)   
  #define ASSIGN_L_NIB(BYTE, VALUE)     (BYTE |= 0x0F)   
  #define TGL_H_NIB(BYTE)               (BYTE ^= 0xF0)
  #define TGL_L_NIB(BYTE)               (BYTE ^= 0x0F)
  #define SWAP_NIB(BYTE)                (BYTE = (BYTE >> 4) | (BYTE << 4))
  /* /////////////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////////////// Defined Types ////////////////////////////////////////// */
  /* Error type */
  typedef enum
  {
    BitMath_enuOk,
    BitMath_enuNok
  }BitMath_tenuError;
  /* /////////////////////////////////////////////////////////////////////////////////////////// */
  /* /////////////////////////////////// Interface Fns ////////////////////////////////////////// */
  /* 
    Fn              :      Division Operation
    Parameter1      :      Dividend, double data type range
    Parameter2      :      Divisor, double data type range
    Parameter3      :      Pointer to double to receive the quotient 
    Parameter3      :      Pointer to double to receive the remainder
    return          :      return error status, options are in "BitMath.h" under "Error type"
  */
  extern BitMath_tenuError BitMath_enuDivider(f64 Copy_f64Dividend, f64 Copy_f64Divisor, pf64 Copy_pf64Quot, pf64 Copy_pf64Rem); 
  /* /////////////////////////////////////////////////////////////////////////////////////////// */
#endif