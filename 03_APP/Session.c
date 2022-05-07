/* ///////////////////////// USART.h //////////////////////////////////// */
#define UART0     0x.......



extern Res_t UART_sendBufferZeroCopy(Bus, Data, Size);
extern Res_t UART_SendByte(Bus, Byte);
typedef struct
{
  u32 BusNumber;
  u32 BaudRate;
  Buffer_t TxBuffer;
  Buffer_t RxBuffer;
  u8 TxBusy;
  u8 RxBusy;
}

extern UART_ReceiveBuffer(u8* Data, u32 Size);









/* ///////////////////////// USART.c //////////////////////////////////// */
typedef struct
{
  u8* Data;
  u32 Used;
  u32 Size;
}Buffer_t;
static Buffer_t TxBuffer, RxBuffer;
Res_t UART_sendBufferZeroCopy(Bus, Data, Size)
{
  if(TxBusy != 1)
  {
    State = Ok;
    //Save user data
    //Trigger 1st byte
    //TxBusy = 1
  }
  else
  {
    State = Nok;
  }
  return(State);
}
Res_t UART_Handler(Bus, Byte)
{
  if(TXC && TxBusy == 1)
  {
    if(TxBuffer.Used == TxBuffer.Size)
    {
      // TxBusy = 0
      //notify & reset buffer
    }
    else
    {
      DR = TxBuffer.Data[TxBuffer.Used];
      TxBuffer.Used++;
    }
  }
  if(RXNE && RxBusy == 1)
  {
    RxBuffer.Data[RxBuffer.Used] = DR;
    RxBuffer.Used++;
    if(Size == Used)
    {
      //Disable Rx interrupt & RxBusy
      //notify app
    }
  }
}
UART_ReceiveBuffer(u8* Data, u32 Size)
{
  if(RxBusy != 1)
  {
    //Clear error flags
    //Copy user buffer data & size
    //RxBusy = 1;
    // Enable RxInterrupt
  }
}





