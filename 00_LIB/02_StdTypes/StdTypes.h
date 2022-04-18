/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	February 07, 2022
**       Version     :	V01
**       SWC         :	StdTypes
**       Description :	Definition of standard data types
** **************************************************************************************/
#ifndef _STDTYPES_H
#define _STDTYPES_H
  /* Defined STD Types */
  typedef unsigned char             u8;
  typedef signed   char             s8;
  typedef unsigned short int        u16;
  typedef signed   short int        s16;
  typedef unsigned long int         u32;
  typedef signed   long int         s32;
  typedef unsigned long long int    u64;
  typedef signed long long int      s64;
  typedef float                     f32;
  typedef double                    f64;
  typedef u8*                       pu8;
  typedef u16*                      pu16;
  typedef f64*                      pf64;
  typedef void (*tpfCallback)(void);
  /* Defined Types */
  typedef struct
  {
    u8* Buffer;
    u32 Size;
    u32 Index; 
  }tstrBuffer;
  /* NULL Pointer */
  #define NULL                      ((void*)0)
  /* Truthness Values */
  #define FALSE                     0
  #define TRUE                      1
  /* Remainder result */
  #define ZERO_REM                  0
  /* Compare Values */
  #define ZERO_COMP                 0
  /* Flag Values */
  #define FLAG_LOW                  0
  #define FLAG_HIGH                 1
  /* Init values */
  #define ZERO_INIT                 0
  /* Bit Slicers */
  #define FIRST_BIT_SLICER          0x01
#endif