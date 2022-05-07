/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 30, 2022
**       Version     :	V01
**       SWC         :	BL
**       Description :	Bootloader
** **************************************************************************************/
#ifndef _BL_H
#define _BL_H

typedef struct
{
  u32 Size;
  u32 Add;
  u32 CRC;
  void (*entry)(void);
}Appinfo_t;

Appinfo_t Appinfo = 0x0800000A;













#endif