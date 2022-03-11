/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 7, 2022
**       Version     :	V01
**       SWC         :	STM32F401CC
**       Description :	STM32F401CC Registers
** **************************************************************************************/
#ifndef _STM32F401CC_H
#define _STM32F401CC_H

/* ******************************* RCC ************************************************ */
  #define RCC_u32BASE_ADD                           0x40023800
  typedef struct
  {
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1;
    volatile u32 Reserved2;
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved3;
    volatile u32 Reserved4;
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved5;
    volatile u32 Reserved6;
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved7;
    volatile u32 Reserved8;
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved9;
    volatile u32 Reserved10;
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved11;
    volatile u32 Reserved12;
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved13;
    volatile u32 Reserved14;
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved15;
    volatile u32 DCKCFGR;
  }RCC_tstrRegisters;
  #define RCC_pstrRegisters                  ((RCC_tstrRegisters*)(RCC_u32BASE_ADD))
/* ************************************************************************************ */


#endif