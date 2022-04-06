/* /////////////////////////////////// LCD /////////////////////////////////////////// */
static u32 initstate;
static u32 BusyFlag; /* Must be set as long as there is asynchronous fn running and you should buffer the request */
/* list of the status */
enum{
  none, 
  start, 
  fnSet, 
  setDisplay, 
  clear, 
  mode, 
  done
}
LCD_task()/* Will come each 2ms */
{
  /* AutoTrasaction State Machine */
  /* States are in switch cases and transactions are using if_condition */
  // switch(initState)
  // {
  //   case fnSet:
  //     /* COde */
  //     break;
    
  // }
  // initstate++; // you should write the specific next state
  if(initState!=Done)
  {
    initProcess();
  }
  else
  {/* For write Actions */
    if(writeProcess==1){
      writeProcess();/* Write the char of the current pos() */
      /* in this, write char then raise "Enable",,, in the next enter lower "Enable" */
    }
  }
}

LCD_init()
{
  //lcd_task create
  initstate=start

}
/* Global var to buffer the user data */
struct userData{
  u8* Data;
  u8 posX;
  u8 posY;
}
LCD_writeString(u8* str, posX, posY)
{
  busyFlag=1
  //save user string and position
  writeProcess=1;
  req=write;/* check on the req in the else of the LCD_task */
}