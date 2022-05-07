/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 30, 2022
**       Version     :	V01
**       SWC         :	BL
**       Description :	Bootloader
** **************************************************************************************/




if(App)
{
  Appinfor->entry();
}

/* Initialize clk  */
/* initialize communication */
while(1)
{
  /* looping till receiving Application on USART */
  if(FlashDone)
  {
    Reset();/* Fn using RCC */
  }
}