/* /////////////////////////////  Frame  /////////////////////////////////////////// */
typedef enum
{
  cmd_x,
  cmd_y,
  cmd_z
}cmd_t;

/* ///////////////////////////////////////////////// */
typedef struct{
  u8 sync;
  cmd_t cmd;
  u8 len;
  u8 Data[8];
  u8 EOF;
}frame_t;
typedef struct{
  u8 sync;
  cmd_t cmd;
  u8 len;
  u8 Data[1]; /* In case of Ethernet and if you want byte number 300 --> Data[400] = .... */
}frame_t;
/* ///////////////////////////////////////////////// */

#define CMD_IDX      1
#define CMD_GET_TEMP 6

uint8_t  Buffer[12];
frame_t* Frame = (frame_t*) Buffer;

/* Constructing frame */
Frame->cmd = cmd_x;
Frame->len = 8;

/* Receiving Frame */
callback(*Rx, len)
{
  frame_t* Frame = Rx;

  if(Frame->cmd == ....)
  {

  }
}


/* Frame with EOF after variable data length(the length known by the cmd type) */
typedef struct{
  u32 CMD;
  union{
    struct{
      Data[4];
      u8 EOF;
    }set_cmd;
    struct{
      Data[2];
      u8 EOF;
    }get_cmd;
  };
  .
  .
  .
  .
  .
}Frame_t;

Frame_t* Frame->set_cmd.Data[0] = .....;


/* ////////////////////////////////////////////////////////////////////////////  OS Session //////////////////////////////////////// */
OS_SP task1Stack[1024]
struct TCB{
  /* One of the two */
  OS_SP TOS; /* Defined in Cfg */
  void* TOS;
  /* ///////////// */
  void* args; /* To not add here porting code */
  u8 Prio;
  struct tcb* next;
  struct tcb* prev;
  BitX;
  BitY;
}
TCB->BitY = Prio >> 3    //Prio / 8;
TCB->BitX = Prio & 0x07  //Prio % 8;
typedef void Task(void* Param);

OS_createTask(myTask, (void*)&Ledinfo1, Prio_0,&Task1Stack[1023]);

static struct TCB TcbTable[64];
struct TCB* TcbTablePrio[64];
*freeList;
*List;