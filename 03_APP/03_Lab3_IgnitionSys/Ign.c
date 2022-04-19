/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 19, 2022
**       Version     :	V01
**       SWC         :	Ign
**       Description :	Ignition system logic
** **************************************************************************************/
/* /////////////////////////////////// Headers inclusion /////////////////////////////////// */
/* LIB headers */
#include "StdTypes.h"
/* HAL headers */
#include "Buzzer.h"
#include "IntSwitch"
#include "DcMotor.h"
#include "Switch.h"
#include "Led.h"
/* ///////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////////////// Global Variables  ////////////////////////////// */
static Ign_tenuState Ign_enuState = Ign_enuStopped;
/* ///////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////////////// Runnable /////////////////////////////////////// */
/* 
  Description       :     Runnable to check on switches and take the appropriate action
  Parameter(s)      :     void
  Return            :     void
*/
void Ign_vidCheckIgn_R(void)
{
  Switch_tenuStatus    Loc_enuPrevIgnitionState;
  Switch_tenuStatus    Loc_enuCurrentIgnitionState;
  IntSwitch_tenuState  Loc_enuDoorState;
  /* Get switch status */
  Switch_enuGetStatus(SWITCH_u8Ignition, &Loc_enuCurrentIgnitionState);
  IntSwitch_enuGetState(SWITCH_u8Door, &Loc_enuDoorState);  
  switch(Ign_enuState)
  {
  case(Ign_enuStopped):
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    break;
  case(Ign_enuRunning):
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    if((Loc_enuPrevIgnitionState == Switch_enuPreReleased) && (Loc_enuCurrentIgnitionState == Switch_enuReleased) && (Loc_enuDoorState == IntSwitch_enuOpen))
    {
      Ign_vidRunCase3();
    }/* if */
    break;
  default:
    /* MISRA */
    break;
  }/* switch */
  Loc_enuPrevIgnitionState = Loc_enuCurrentIgnitionState;
}/* Ign_vidCheckIgn_R */
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