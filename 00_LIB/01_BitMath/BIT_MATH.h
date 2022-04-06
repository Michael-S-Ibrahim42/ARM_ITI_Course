/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	February 03, 2022
**       Version     :	V01
**       SWC         :	BIT_MATH
**       Description :	Bit Manipulation MACROS
** **************************************************************************************/
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

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
  #define SWAP_NIB(BYTE)                 (BYTE = (BYTE >> 4) | (BYTE << 4))

#endif