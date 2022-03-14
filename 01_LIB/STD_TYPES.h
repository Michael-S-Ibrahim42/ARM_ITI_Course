/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	February 07, 2022
**       Version     :	V01
**       SWC         :	STD_TYPES
**       Description :	Definition of standard data types
** **************************************************************************************/
#ifndef _STD_TYPES_H
#define _STD_TYPES_H
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
  /* NULL Pointer */
  #define NULL                      ((void*)0)
#endif