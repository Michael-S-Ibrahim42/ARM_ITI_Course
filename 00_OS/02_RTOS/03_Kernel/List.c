/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	May 27, 2022
**       Version     :	V01
**       SWC         :	List
**       Description :	List files
** **************************************************************************************/
/* ////////////////////////////// Headers ////////////////////////// */
/* LIB */
#include "StdTypes.h"
/* Own headers */
#include "List.h"
/* ////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////// Interface Fns //////////////////////// */
void List_vidInsert(strTCB_t** Copy_ppstrList, strTCB_t* Copy_pstrNode, enuOrderType_t Copy_enuOrderType)
{
  
}/* List_vidInsert */
strTCB_t* List_pstrExtractHead(strTCB_t** Copy_ppstrList)
{
  strTCB_t* Loc_pstrHead = NULL;
  if((Copy_ppstrList != NULL) && (*Copy_ppstrList != NULL))
  {
    Loc_pstrHead = *Copy_ppstrList;
    *Copy_ppstrList = *Copy_ppstrList->Next;
    Loc_pstrHead->Next = NULL;
    if(*Copy_ppstrList != NULL)
    {
      *Copy_ppstrList->Prev = NULL;
    }/* if */
  }/* if */

  return(Loc_pstrHead);
}/* List_pstrExtractHead */
/* ////////////////////////////////////////////////////////////////////// */
