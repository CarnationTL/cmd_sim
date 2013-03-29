/*+++

Copyright (c) 2009 North Atlantic Industries,

File Name:

  CPCI75C3_1553.h

Description:

  CPCI75C3 - MIL-STD 1553 (N7) module Library functions header file.
*/
#ifndef _CPCI75C3_1553_H_
#define _CPCI75C3_1553_H_

#include "CPCI75C3.h"

#include  "CPCI75C3_include.h"

/*************************/
/* 1553 Module Registers */
/*************************/
#define CPCI75C3_REG_1553_COREREG_ADD {\
 0x0000 << ADDR_SHIFT, 0x0080 << ADDR_SHIFT \
}

#define CPCI75C3_REG_1553_DATA_ADD {\
 0x0100 << ADDR_SHIFT, 0x0200 << ADDR_SHIFT \
}

#define CPCI75C3_REG_1553_PAGE_ADD {\
 0x0060 << ADDR_SHIFT, 0x00E0 << ADDR_SHIFT \
}

#define CPCI75C3_REG_1553_INT_VECTOR_ADD {\
 0x03C2 << ADDR_SHIFT, 0x03C4 << ADDR_SHIFT \
}

#define N7_MAX_CHAN  2

#define MIL_1553_MIN_RAM_ADDR_OFFSET            0x00000000			
#define MIL_1553_MAX_RAM_ADDR_OFFSET            0x0001FFFE		

/* Bus Monitor Command Block and Data Block */
#define MIL_1553_BM_CMDBLKSIZE          8             /* 8  words per command block                  */
#define MIL_1553_BM_DATABLKSIZE         32            /* 32 words max per data block                 */

/* **** Note: 1023 gives you 1024 blocks (0 to 1023) */
#define MIL_1553_BM_CMDBLK_CNT          1023          /* Number of BM Command Blocks (8 words/block) */
#define MIL_1553_BM_DATABLK_CNT         1023          /* Number of BM Data Blocks (32 words/block)   */

#define MIL_1553_BM_CMDBLKOFFSET        0x00000       /* Command Block Start Address                 */
#define MIL_1553_BM_DATABLKOFFSET       0x04000       /* Data Block Start Address                    */

/* Bus Controller Command Block and Data Block */
#define MIL_1553_BC_CMDBLKSIZE          8             /* 8  words per command block                  */
#define MIL_1553_BC_DATABLKSIZE         32            /* 32 words per data block                     */
#define MIL_1553_BC_CMDBLK_CNT          2048          /* Number of BC Command Blocks (8 words/block) */
#define MIL_1553_BC_DATABLK_CNT         1024          /* Number of BC Data Blocks (32 words/block)   */

#define MIL_1553_BC_CMDBLKOFFSET        0x00000       /* Command Block Start Address                 */
#define MIL_1553_BC_DATABLKOFFSET       0x04000       /* Data Block Start Address                    */

/* Mode 1 circular buffers (not PingPong) */
#define MIL_1553_MAX_WAIT_CNT           10            /* Maximum counts to wait for channel to reset */
#define MIL_1553_RT_DATABLKSIZE_SA     34             /* 34 words per SubAddress data block          */
#define MIL_1553_RT_DATABLKSIZE_MC      3             /* 3 words per ModeCode data block             */
#define MIL_1553_RT_RECV_SA            0x0200         /* SA Recv Bufs (32SA * 16msgs * 34words = 17408) */
#define MIL_1553_NUM_MSGS_RSA          36
#define MIL_1553_NUM_MSGS_XSA          16
#define MIL_1553_NUM_MSGS_MC            8
#define MIL_1553_MSG_WORDS_SA          34
#define MIL_1553_MSG_WORDS_MC           3


/* Remote Terminal Descriptor Table and RT Data Block */
#define MIL_1553_RT_DESCRBLKSIZE        4             /* 4 words per descriptor block                */
#define MIL_1553_RT_DATABLKSIZE         34            /* 34 words per data block                     */

/* Buffer Modes */
#define MIL_1553_BUFFER_MODE_0_MASK	 0x0000			
#define MIL_1553_BUFFER_MODE_1_MASK	 0x0100			
#define MIL_1553_BUFFER_MODE_2_MASK  0x0180

#define MIL_1553_BUFFER_MODE_0	 0
#define MIL_1553_BUFFER_MODE_1	 1
#define MIL_1553_BUFFER_MODE_2    2
#define MIL_1553_BUFFER_MODE_PP   3

#define MIL_1553_RT_DESCR_CONTROL		0x00000	
#define MIL_1553_RT_DESCR_DATA_A		   0x00002
#define MIL_1553_RT_DESCR_DATA_B		   0x00004
#define MIL_1553_RT_DESCR_DATA_BCAST	0x00006

/* The default buffers A & B are to be used for dumping unused SubAddresses received data */
/* The buffer to be used for any handled SubAddresses are to start 68 words later */
#define MIL_1553_RT_BUF_SIZE			34			/* # of words in each buffer */
#define MIL_1553_RT_DESCR_BUFA			0x200
#define MIL_1553_RT_DESCR_BUFB			MIL_1553_RT_DESCR_BUFA + MIL_1553_RT_BUF_SIZE	
#define MIL_1553_RT_DESCR_BCAST			MIL_1553_RT_DESCR_BUFB + MIL_1553_RT_BUF_SIZE	

/* Buffer Mode 1 definitions */
#define MIL_1553_RT_DESCR_RECV_SA       0x00000       /* Descriptor Table Receive SubAddress         */
#define MIL_1553_RT_DESCR_XMIT_SA       0x00080       /* Descriptor Table Transmit SubAddress        */       
#define MIL_1553_RT_DESCR_RECV_MC       0x00100       /* Descriptor Table Receive Mode Code          */
#define MIL_1553_RT_DESCR_XMIT_MC       0x00180       /* Descriptor Table Transmit Mode Code         */

#define MIL_1553_RT_DPA_RECV_SA         0x00200       /* Data Pointer A Receive SubAddress           */
#define MIL_1553_RT_DPA_XMIT_SA         0x00640       /* Data Pointer A Transmit SubAddress          */
#define MIL_1553_RT_DPA_RECV_MC         0x00A80       /* Data Pointer A Receive Mode Code            */
#define MIL_1553_RT_DPA_XMIT_MC         0x00EC0       /* Data Pointer A Transmit Mode Code           */

#define MIL_1553_RT_DPB_RECV_SA         0x01300       /* Data Pointer B Receive SubAddress           */
#define MIL_1553_RT_DPB_XMIT_SA         0x01740       /* Data Pointer B Transmit SubAddress          */
#define MIL_1553_RT_DPB_RECV_MC         0x01B80       /* Data Pointer B Receive Mode Code            */
#define MIL_1553_RT_DPB_XMIT_MC         0x01FC0       /* Data Pointer B Transmit Mode Code           */

#define MIL_1553_RT_BP_RECV_SA          0x02400       /* Broadcast Pointer Receive SubAddress        */
#define MIL_1553_RT_BP_XMIT_SA          0x02840       /* Broadcast Pointer Transmit SubAddress       */
#define MIL_1553_RT_BP_RECV_MC          0x02C80       /* Broadcast Pointer Receive Mode Code         */
#define MIL_1553_RT_BP_XMIT_MC          0x030C0       /* Broadcast Pointer Transmit Mode Code        */

/* Interrupt Log List Block */
/*#define MIL_1553_INTERRUPT_BLOCK_PTR    0x0FF9F */       /* Pointer to the Interrupt Log List */
/*      N3 Definitions     */

typedef struct {
  unsigned short Control;
  unsigned short Command1;
  unsigned short Command2;
  unsigned short Status1;
  unsigned short Status2;
  unsigned short TimerValue;
  unsigned short DataBlockNum;
  unsigned short BranchBlockNum;
} CPCI75C3_CMD1553BLOCK, *PCPCI75C3_CMD1553BLOCK;

typedef struct {
  unsigned short MsgInfo;
  unsigned short Command1;
  unsigned short Command2;
  unsigned short Status1;
  unsigned short Status2;
  unsigned short TimeTag;
  unsigned short Data[32];
} CPCI75C3_BM1553MSG, *PCPCI75C3_BM1553MSG;

/* Transmit or Receive 1553 message Definition*/
#define MIL_1553_TRANSMIT         0
#define MIL_1553_RECEIVE          1

/* No Broadcast or Broadcast Definition */
#define MIL_1553_NOBROADCAST      0
#define MIL_1553_BROADCAST        1

/* 1553 Mode Definition */
#define MIL_1553_BC_MODE          0x0000
#define MIL_1553_RT_MODE          0x0100
#define MIL_1553_BM_MODE          0x0200
#define MIL_1553_BM_RT_MODE       0x0300

/* Ping-Pong Enable/Disable Definition */
#define MIL_1553_PPDIS            0
#define MIL_1553_PPEN             1

/* 1553 Protocol Definition */
#define MIL_1553_MIL_STD_1553B    0
#define MIL_1553_MIL_STD_1553A    1

/* 1553 Message Type Defintion */
#define MIL_1553_STDMSG           0
#define MIL_1553_MODEMSG          1
#define MIL_1553_STDBRDCAST       2
#define MIL_1553_MODEBRDCAST      3

/* Interface Type Defintion */
#define MIL_1553_ACCESS_INT       0
#define MIL_1553_BROADCAST_INT    1

/* Mode Code versus SubAddress Definition */
#define MIL_1553_NOMODECODE       0
#define MIL_1553_MODECODE         32

/* Legal and Illegal Definition */
#define MIL_1553_ILLEGAL          0
#define MIL_1553_LEGAL            1

/* Interrupt Enable/Disable Definition */
#define MIL_1553_DISABLE_INT      0
#define MIL_1553_ENABLE_INT       1

/* CORE1553BRM Control Register (REGISTER 0) */
#define MIL_1553_CTL_START_EXECUTION   0x8000  /* STEX bit in Control register    */
#define MIL_1553_CTL_RESET             0x2000  /* Reset CORE1553BRM               */
#define MIL_1553_CTL_BUAEN             0x1000  /* Bus A enable                    */
#define MIL_1553_CTL_BUBEN             0x0800  /* Bus B enable                    */
#define MIL_1553_CTL_PPHS              0x0200  /* Ping Pong Handshake; 0 = disabled, 1 = enabled */
#define MIL_1553_CTL_BMC               0x0020  /* Bus Monitor Control             */
#define MIL_1553_CTL_BROADCAST         0x0010  /* set to make RT31 Broadcast      */
#define MIL_1553_CTL_NOBROADCAST       0x0000  /* RT 31 is normal RT              */
#define MIL_1553_CTL_PPEN		         0x0004  /* Ping Pong enable		          */

/* CORE1553BRM Operation and Status Register (REGISTER 1) */
#define MIL_1553_CTL_MIL_STD_A           0x0080  /* MIL-STD-1553A if set to 1, otherwise MIL-STD-1553B  */

#define MIL_1553_RT_CTL_BAC              0x0010  /* Block Accessed in RT Descriptor Control Word */
#define MIL_1553_RT_CTL_A_BUFFER         0x0004  /* Use A Buffer in RT Descriptor Control Word */
#define MIL_1553_RT_CTL_IWA              0x0040  /* Interrupt when Accessed in RT Descriptor Control Word */
#define MIL_1553_RT_CTL_IBRD             0x0020  /* Interrupt Broadcast Received in RT Descriptor Control Word */

/* BC Bus Controller Command Block Control Word definitions */
#define MIL_1553_BC_CNTL_OP_ENDOFLIST              0x0000
#define MIL_1553_BC_CNTL_OP_SKIP                   0x1000
#define MIL_1553_BC_CNTL_OP_GOTO                   0x2000 
#define MIL_1553_BC_CNTL_OP_EXEBLK_CONT            0x4000
#define MIL_1553_BC_CNTL_OP_EXEBLK_BRNCH           0x5000
#define MIL_1553_BC_CNTL_OP_EXEBLK_BRNCH_COND      0x6000
#define MIL_1553_BC_CNTL_OP_RETRY_COND             0x7000
#define MIL_1553_BC_CNTL_OP_RETRY_COND_BRNCH       0x8000
#define MIL_1553_BC_CNTL_OP_RETRY_COND_BRNCH_FAIL  0x9000
#define MIL_1553_BC_CNTL_OP_INT_CONT               0xA000
#define MIL_1553_BC_CNTL_OP_CALL                   0xB000
#define MIL_1553_BC_CNTL_OP_RETURN_TO_CALL         0xC000
#define MIL_1553_BC_CNTL_OP_LOAD_MINOR_FRAME_TIMER 0xE000
#define MIL_1553_BC_CNTL_OP_RETURN_TO_BRANCH       0xF000
#define MIL_1553_BC_CNTL_RETRY1                    0x0000
#define MIL_1553_BC_CNTL_RETRY2                    0x0400
#define MIL_1553_BC_CNTL_RETRY3                    0x0800
#define MIL_1553_BC_CNTL_RETRY4                    0x0C00
#define MIL_1553_BC_CNTL_BUSA                      0x0200
#define MIL_1553_BC_CNTL_BUSB                      0x0000
#define MIL_1553_BC_CNTL_RTRT                      0x0100
#define MIL_1553_BC_CNTL_MSG_RT_ERROR              0x0080
#define MIL_1553_BC_CNTL_MSG_ERROR                 0x0040
#define MIL_1553_BC_CNTL_BUSY_BIT                  0x0020
#define MIL_1553_BC_CNTL_TERMINAL_FLAG             0x0010
#define MIL_1553_BC_CNTL_SUBSYSTEM_FAIL            0x0008
#define MIL_1553_BC_CNTL_INSTRUMENTATION_BIT       0x0004
#define MIL_1553_BC_CNTL_SERVICE_REQUEST           0x0002
#define MIL_1553_BC_CNTL_BAME                      0x0001

/* RT Message Information Word (MIW) definitions */
#define MIL1553_RT_MIW_RETRY1                      0x0800
#define MIL1553_RT_MIW_RETRY0                      0x0400
#define MIL1553_RT_MIW_BUSA                        0x0200
#define MIL1553_RT_MIW_BUSB                        0x0000
#define MIL1553_RT_MIW_RTRT                        0x0100
#define MIL1553_RT_MIW_MESSAGE_ERROR               0x0080
#define MIL1553_RT_MIW_MODECODE_NODATA             0x0040
#define MIL1553_RT_MIW_BROADCAST                   0x0020
#define MIL1553_RT_MIW_TIMEOUT                     0x0008
#define MIL1553_RT_MIW_OVERRUN                     0x0004
#define MIL1553_RT_MIW_PARITY                      0x0002
#define MIL1553_RT_MIW_MANCHESTER                  0x0001

/******      1553 Specific Functions      ******/
/* General 1553 Module Functions */
_75C3FUNC int CPCI75C3_1553_CheckCardModuleChannel(int Card, int Module, int Channel);
_75C3FUNC int CPCI75C3_1553_GenerateCommandWord( int RTAddress, int TxOrRcv, int Subaddress, int WordCntModeCode, unsigned short *CommandWord );
_75C3FUNC int CPCI75C3_1553_GetBit( int Card, int Module, int Channel, unsigned short *Bit );
_75C3FUNC int CPCI75C3_1553_GetBroadcast( int Card, int Module, int Channel, unsigned short *Broadcast );
_75C3FUNC int CPCI75C3_1553_GetOpStatus( int Card, int Module, int Channel, unsigned short *OpStatus );
_75C3FUNC int CPCI75C3_1553_GetPending( int Card, int Module, int Channel, unsigned short *PendingInt );
_75C3FUNC int CPCI75C3_1553_SetBroadcast( int Card, int Module, int Channel, unsigned short Broadcast );
_75C3FUNC int CPCI75C3_1553_SetInterruptMask( int Card, int Module, int Channel, unsigned short InterruptMask );
_75C3FUNC int CPCI75C3_1553_GetMode( int Card, int Module, int Channel, unsigned short *Mode, unsigned short *BufferMode );
_75C3FUNC int CPCI75C3_1553_SetMode( int Card, int Module, int Channel, unsigned short Mode, unsigned short BufferMode );	/* 08-03-12 JED added BufferMode */
_75C3FUNC int CPCI75C3_1553_SetPingPong( int Card, int Module, int Channel, unsigned short PingPongFlag );
_75C3FUNC int CPCI75C3_1553_SetProtocol( int Card, int Module, int Channel, unsigned short Protocol );
_75C3FUNC int CPCI75C3_1553_StopExecution( int Card, int Module, int Channel );

/* Low Level 1553 Module Functions */
_75C3FUNC int CPCI75C3_1553_GetData( int Card, int Module, int Channel, int AddrOffset, int *Data );
_75C3FUNC int CPCI75C3_1553_GetInterruptVector( int Card, int Module, int Channel, int *Vector );
_75C3FUNC int CPCI75C3_1553_GetRAMSize( int Card, int Module, int Channel, int *RAMSize );
_75C3FUNC int CPCI75C3_1553_SetData( int Card, int Module, int Channel, int AddrOffset, int Data );
_75C3FUNC int CPCI75C3_1553_SetInterruptVector( int Card, int Module, int Channel, int Vector );
_75C3FUNC int CPCI75C3_1553_GetRegister( int Card, int Module, int Channel, int Register, int *Data);
_75C3FUNC int CPCI75C3_1553_SetRegister( int Card, int Module, int Channel, int Register, int Data);
_75C3FUNC int CPCI75C3_1553_GetDataRegister( int Card, int Module, int Channel, int Addr );
_75C3FUNC int CPCI75C3_1553_GetDataRegisterEx( int Card, int Module, int Channel, int Addr, int *Data );
_75C3FUNC int CPCI75C3_1553_SetDataRegister( int Card, int Module, int Channel, int Addr, int Data );
_75C3FUNC int CPCI75C3_1553_SetPageRegister( int Card, int Module, int Channel, int Addr );
_75C3FUNC void CPCI75C3_1553_SetWaitForPageMs( int MsToWait);
_75C3FUNC int CPCI75C3_1553_GetWaitForPageMs(void);

/* added block functions to speed up read / writes (for ethernet) */
_75C3FUNC int CPCI75C3_1553_SetDataBlock( int Card, int Module, int Channel, int AddrOffset, unsigned short *Data, int NumWords );
_75C3FUNC int CPCI75C3_1553_GetDataBlock( int Card, int Module, int Channel, int AddrOffset, unsigned short *Data, int NumWords );
_75C3FUNC int CPCI75C3_1553_GetDataMultiple( int Card, int Module, int Channel, int AddrOffset, unsigned short *Data, int NumWords );

/* Bus Controller (BC) Functions */
_75C3FUNC int CPCI75C3_1553_GetBCCmd( int Card, int Module, int Channel, unsigned short CmdBlkNum, PCPCI75C3_CMD1553BLOCK CmdBlk );
_75C3FUNC int CPCI75C3_1553_GetLastExecutedBCCmd( int Card, int Module, int Channel, unsigned short *CmdBlkNum );
_75C3FUNC int CPCI75C3_1553_LoadBCDataBlock( int Card, int Module, int Channel, unsigned short DataBlkNum, unsigned short WordCnt, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_ReadBCDataBlock( int Card, int Module, int Channel, unsigned short DataBlkNum, unsigned short WordCnt, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_RunBC( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_1553_SetBCCmd( int Card, int Module, int Channel, unsigned short CmdBlkNum, PCPCI75C3_CMD1553BLOCK CmdBlk );

/* Remote Terminal (RT) Functions */
_75C3FUNC int CPCI75C3_1553_GetDataBlockAccessed( int Card, int Module, int Channel, unsigned short SubAddress, unsigned short MsgType, unsigned short TxOrRcv, unsigned short *DataBlkAccessed );
_75C3FUNC int CPCI75C3_1553_SetDataBlockAccessed( int Card, int Module, int Channel, unsigned short SubAddress, unsigned short MsgType, unsigned short TxOrRcv, unsigned short ControlWord );
_75C3FUNC int CPCI75C3_1553_LoadDataBlock( int Card, int Module, int Channel, unsigned short SAorMC, unsigned short MsgType, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_ReadDataBlock( int Card, int Module, int Channel, unsigned short SAorMC, unsigned short MsgType,
                                        unsigned short TxOrRcv, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_RunRT( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_1553_SetLegalCmd( int Card, int Module, int Channel, unsigned short IsMode, unsigned short SAorMC, unsigned short Broadcast,
                                      unsigned short TxOrRcv, unsigned short Legal );
_75C3FUNC int CPCI75C3_1553_SetRTAddr( int Card, int Module, int Channel, unsigned short RTAddr );
_75C3FUNC int CPCI75C3_1553_SetRTStatus( int Card, int Module, int Channel, unsigned short Status );
_75C3FUNC int CPCI75C3_1553_SubAddrInterruptEnabled( int Card, int Module, int Channel, unsigned short SubAddress, unsigned short TxOrRcv,
                                                  unsigned short MsgType, unsigned short InterfaceType, unsigned short Enable );
_75C3FUNC int CPCI75C3_1553_SetupRTDescriptorTable(int Card, int Module, int Channel, unsigned short RTmode);

/* Bus Monitor (BM) Functions */
_75C3FUNC int CPCI75C3_1553_GetLastCmdMonitored( int Card, int Module, int Channel, unsigned short *CommandWord );
_75C3FUNC int CPCI75C3_1553_MonitorAllRT( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_1553_MonitorRTs( int Card, int Module, int Channel, unsigned short RTAddr31_16, unsigned short RTAddr15_0 );
_75C3FUNC int CPCI75C3_1553_ReadNextMessage( int Card, int Module, int Channel, PCPCI75C3_BM1553MSG Message, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_ReadBMMessage( int Card, int Module, int Channel, int BlockNum, PCPCI75C3_BM1553MSG Message, unsigned short *Data );
_75C3FUNC int CPCI75C3_1553_RunBM( int Card, int Module, int Channel );

#endif  /* _CPCI75C3_1553_H_ */
