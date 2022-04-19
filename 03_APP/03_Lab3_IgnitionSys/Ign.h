/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 19, 2022
**       Version     :	V01
**       SWC         :	Ign
**       Description :	Ignition system
** **************************************************************************************/
#ifndef _IGN_H
#define _IGN_H
  /* //////////////////////////////////////// Defined types /////////////////////////////////// */
  typedef enum
  {
    Ign_enuStopped,
    Ign_enuRunning
  }Ign_tenuState;
  /* ///////////////////////////////////////////////////////////////////////////////////////// */

  /* //////////////////////////////////////// Runnable /////////////////////////////////////// */
  /* 
    Description       :     Runnable to check on switches and take the appropriate action
    Parameter(s)      :     void
    Return            :     void
  */
  void Ign_vidCheckIgn_R(void);
  /* ///////////////////////////////////////////////////////////////////////////////////////// */
  
  /* //////////////////////////////////////// Private Fns //////////////////////////////////// */
  /* 
    Description       :     Private Fn to make case 1 actions
    Parameter(s)      :     void
    Return            :     void
  */
  void Ign_vidRunCase1(void);
  /* 
    Description       :     Private Fn to make case 2 actions
    Parameter(s)      :     void
    Return            :     void
  */
  void Ign_vidRunCase2(void);
  /* 
    Description       :     Private Fn to make case 3 actions
    Parameter(s)      :     void
    Return            :     void
  */
  void Ign_vidRunCase3(void);
  /* 
    Description       :     Private Fn to make case 4 actions
    Parameter(s)      :     void
    Return            :     void
  */
  void Ign_vidRunCase4(void);
  /* ///////////////////////////////////////////////////////////////////////////////////////// */
#endif