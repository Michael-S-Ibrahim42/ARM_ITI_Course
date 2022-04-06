/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 06, 2022
**       Version     :	V0
**       SWC         :	BitMath
**       Description :	BitMath source file
** **************************************************************************************/
/* /////////////////////////////////// Headers inclusion ////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
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
BitMath_tenuError BitMath_enuDivider(f64 Copy_f64Dividend, f64 Copy_f64Divisor, pf64 Copy_pf64Quot, pf64 Copy_pf64Rem)
{
  BitMath_tenuError Loc_enuError = BitMath_enuOk;
  if((Copy_pf64Quot != NULL) && (Copy_pf64Rem != NULL) && (Copy_f64Divisor != ZERO_COMP))
  {
    *Copy_pf64Quot = Copy_f64Dividend / Copy_f64Divisor;
    *Copy_pf64Rem  = Copy_f64Dividend % Copy_f64Divisor;
  }/* if */
  else
  {
    Loc_enuError = BitMath_enuNok;
  }/* else */

  return(Loc_enuError);
}/* BitMath_enuDivider */
/* /////////////////////////////////////////////////////////////////////////////////////////// */