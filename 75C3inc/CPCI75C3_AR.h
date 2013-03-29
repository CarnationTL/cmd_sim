/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_AR.h

Description:

 Include file to the CPCI75C3 - ARINC 429/575 Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_AR_H
#define _CPCI75C3_AR_H

#include "CPCI75C3_include.h" 

#ifdef __cplusplus
extern "C" {
#endif 

#define A4_MAX_CHAN        6

/*      A4 definintions      */

/* Number of bytes that can be stored in a FIFO. */
#define A4_MAX_FIFO_COUNT     255	  /* 255 Words */

/* Max data rate */
#define A4_MAX_DATARATE       100000  /* 100K bps */

/* Max # of data to be read in a buffer */
#define AR_MAX_RECEIVE			255

#define AR_MIN_INTERVAL_RATE  4
#define AR_MAX_INTERVAL_RATE  1048575  /* 0xFFFFF, 20bits*/

#define AR_RX_FIFO_MODE   	   0 
#define AR_RX_MBOX_MODE   	   1 
#define AR_TX_SENDMODE_IMMED  0
#define AR_TX_SENDMODE_SCHED  1
#define AR_TX_SENDMODE_TRGF   2

/* Tx Schedule Commands (to mask with data, if applicable) */
#define AR_SCHED_STOP      0x0000
#define AR_SCHED_MESSAGE   0x1000
#define AR_SCHED_GAP       0x2000
#define AR_SCHED_FIXEDGAP  0x3000
#define AR_SCHED_PAUSE     0x4000
#define AR_SCHED_INTERRUPT 0x5000
#define AR_SCHED_JUMP      0x6000

#define AR_ENABLE          1
#define AR_DISABLE         0

/* Data Rates (for function call) */
#define AR_SPEED_HIGH      1        /* 100 kHz */
#define AR_SPEED_LOW       0        /* 12.5-14.5 kHz */

/* Parity (Odd, None) (for function call) */
#define AR_PAR_ODD         0        /* odd parity */
#define AR_PAR_NONE        1        /* parity as data; no parity */

/*CHANNEL CONTROL LO BITS */
#define AR_CTL_RX_FIFO_MODE      0x0000
#define AR_CTL_RX_ENABLE   		0x0001
#define AR_CTL_RX_MODE           0x0002
#define AR_CTL_RX_MBOX_MODE   	0x0002  /* default is fifo mode */
#define AR_CTL_TX_ENABLE			0x0004

#define AR_CTL_TX_MODE           0x0018 /* default is fifo mode */
#define AR_CTL_TX_FIFO_MODE   	0x0000
#define AR_CTL_TX_SCH_MODE   	   0x0008
#define AR_CTL_TX_TRGF_MODE   	0x0010 

#define AR_CTL_DATARATE_100K	   0x0020	/*  default - 12.5kbps / 100kbps */
#define AR_CTL_PARITY_DISABLE	   0x0040	/* default ODD parity-on=429 MODE */
#define AR_CTL_MATCH_ENABLE		0x0080
#define AR_CTL_TIMESTAMP_EN		0x0100
#define AR_CTL_BIT_DISABLE		   0x0200
#define AR_CTL_RX_STORE_ERR_DIS 0x0400

/*CHANNEL CONTROL HI BITS */
#define TX_FIFO_CLEAR  		0x0001  
#define RX_FIFO_CLEAR 		0x0002  
#define MATCH_MEM_CLEAR 	0x0004
#define TX_RX_CHANNEL_RST  0x0008 
#define BIT_ERROR_CLEAR    0x0010


/*TIMESTAMP CONTROL BITS */
#define TSTAMP_1US		   0x0000
#define TSTAMP_10US		   0x0001
#define TSTAMP_100US	      0x0002
#define TSTAMP_1MS		   0x0003
#define TSTAMP_RSLN_MASK   0x0003
#define TSTAMP_RESET	      0x0004
#define PLL_LOCKED_CNT	   0x0018

/* Interrupt and Channel Status Bits*/
#define AR_RX_DATA_AVAIL		0x0001  
#define AR_RX_FIFO_ALM_FULL	0x0002  
#define AR_RX_FIFO_FULL		   0x0004
#define AR_RX_FIFO_OVERFLOW   0x0008 
#define AR_TX_FIFO_EMPTY   	0x0010
#define AR_TX_FIFO_ALM_EMPTY  0x0020  
#define AR_TX_FIFO_FULL		   0x0040
#define AR_PARITY_ERROR		   0x0080	
#define AR_RX_ERROR			   0x0100
#define AR_BIT_ERROR			   0x0200
#define AR_SCHED_INT_BIT      0x0400
#define AR_ASYNC_DATA_SENT	   0x0800
#define AR_TX_COMPLETE  	   0x1000
#define AR_TX_RUN				   0x1000
#define AR_TX_PAUSE			   0x2000

/**************************/
/* ARINC Module Registers */
/**************************/
#define CPCI75C3_REG_AR_TX_BUFFER_HI_ADD {\
 0x000 << ADDR_SHIFT, 0x030 << ADDR_SHIFT, 0x060 << ADDR_SHIFT,\
 0x090 << ADDR_SHIFT, 0x0C0 << ADDR_SHIFT, 0x0F0 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_BUFFER_HI_ADD {\
 0x004 << ADDR_SHIFT, 0x034 << ADDR_SHIFT, 0x064 << ADDR_SHIFT,\
 0x094 << ADDR_SHIFT, 0x0C4 << ADDR_SHIFT, 0x0F4 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_FIFO_THRESHOLD_ADD {\
 0x008 << ADDR_SHIFT, 0x038 << ADDR_SHIFT, 0x068 << ADDR_SHIFT,\
 0x098 << ADDR_SHIFT, 0x0C8 << ADDR_SHIFT, 0x0F8 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_TX_FIFO_THRESHOLD_ADD {\
 0x00A << ADDR_SHIFT, 0x03A << ADDR_SHIFT, 0x06A << ADDR_SHIFT,\
 0x09A << ADDR_SHIFT, 0x0CA << ADDR_SHIFT, 0x0FA << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_FIFO_LEVEL_ADD {\
 0x00C << ADDR_SHIFT, 0x03C << ADDR_SHIFT, 0x06C << ADDR_SHIFT,\
 0x09C << ADDR_SHIFT, 0x0CC << ADDR_SHIFT, 0x0FC << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_TX_FIFO_LEVEL_ADD {\
 0x00E << ADDR_SHIFT, 0x03E << ADDR_SHIFT, 0x06E << ADDR_SHIFT,\
 0x09E << ADDR_SHIFT, 0x0CE << ADDR_SHIFT, 0x0FE << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_CH_CONTROL_LO_ADD {\
 0x010 << ADDR_SHIFT, 0x040 << ADDR_SHIFT, 0x070 << ADDR_SHIFT,\
 0x0A0 << ADDR_SHIFT, 0x0D0 << ADDR_SHIFT, 0x100 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_CH_CONTROL_HI_ADD {\
 0x012 << ADDR_SHIFT, 0x042 << ADDR_SHIFT, 0x072 << ADDR_SHIFT,\
 0x0A2 << ADDR_SHIFT, 0x0D2 << ADDR_SHIFT, 0x102 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_CH_STATUS_ADD {\
 0x014 << ADDR_SHIFT, 0x044 << ADDR_SHIFT, 0x074 << ADDR_SHIFT,\
 0x0A4 << ADDR_SHIFT, 0x0D4 << ADDR_SHIFT, 0x104 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_CH_INTERRUPT_ENABLE_ADD {\
 0x016 << ADDR_SHIFT, 0x046 << ADDR_SHIFT, 0x076 << ADDR_SHIFT,\
 0x0A6 << ADDR_SHIFT, 0x0D6 << ADDR_SHIFT, 0x106 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_CH_INTERRUPT_STATUS_ADD {\
 0x018 << ADDR_SHIFT, 0x048 << ADDR_SHIFT, 0x078 << ADDR_SHIFT,\
 0x0A8 << ADDR_SHIFT, 0x0D8 << ADDR_SHIFT, 0x108 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_TX_INTERVAL_HI_ADD {\
 0x01A << ADDR_SHIFT, 0x04A << ADDR_SHIFT, 0x07A << ADDR_SHIFT,\
 0x0AA << ADDR_SHIFT, 0x0DA << ADDR_SHIFT, 0x10A << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_TX_INTERVAL_LO_ADD {\
 0x01C << ADDR_SHIFT, 0x04C << ADDR_SHIFT, 0x07C << ADDR_SHIFT,\
 0x0AC << ADDR_SHIFT, 0x0DC << ADDR_SHIFT, 0x10C << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_MBOX_SEL_REG_ADD {\
 0x01E << ADDR_SHIFT, 0x04E << ADDR_SHIFT, 0x07E << ADDR_SHIFT,\
 0x0AE << ADDR_SHIFT, 0x0DE << ADDR_SHIFT, 0x10E << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_MBOX_STSWD_ADD {\
 0x020 << ADDR_SHIFT, 0x050 << ADDR_SHIFT, 0x080 << ADDR_SHIFT,\
 0x0B0 << ADDR_SHIFT, 0x0E0 << ADDR_SHIFT, 0x110 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_MBOX_DATAWD_ADD {\
 0x022 << ADDR_SHIFT, 0x052 << ADDR_SHIFT, 0x082 << ADDR_SHIFT,\
 0x0B2 << ADDR_SHIFT, 0x0E2 << ADDR_SHIFT, 0x112 << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_INTERRUPT_VECTOR_ADD_ADD {\
 0x3C2 << ADDR_SHIFT, 0x3C4 << ADDR_SHIFT, 0x3C6 << ADDR_SHIFT,\
 0x3C8 << ADDR_SHIFT, 0x3CA << ADDR_SHIFT, 0x3CC << ADDR_SHIFT \
}

#define CPCI75C3_REG_AR_RX_UNBUFFER_ADD       (0x12C << ADDR_SHIFT)

#define CPCI75C3_REG_AR_TX_SEND_TRIGGER_ADD   (0x130 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_TX_SEND_PAUSE_ADD     (0x132 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_TX_SEND_STOP_ADD      (0x134 << ADDR_SHIFT)

#define CPCI75C3_REG_AR_TSTAMP_CONTROL_ADD    (0x136 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_TSTAMP_HI_ADD         (0x138 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_TSTAMP_LO_ADD         (0x13A << ADDR_SHIFT)
#define CPCI75C3_REG_MODULE_RESET_ADD         (0x13C << ADDR_SHIFT)

#define CPCI75C3_REG_MEMORY_PAGE_REG_ADD      (0x1FE << ADDR_SHIFT)
#define CPCI75C3_REG_MEMORY_WINDOW_BOTTOM_ADD (0x200 << ADDR_SHIFT)
#define CPCI75C3_REG_MEMORY_WINDOW_TOP_ADD    (0x2FE << ADDR_SHIFT)

/*#define CPCI75C3_REG_AR_FPGA1_REV_ADD       {0x388 << ADDR_SHIFT, 0x38A << ADDR_SHIFT, 0x38C << ADDR_SHIFT, 0x38E << ADDR_SHIFT}
*/
#define CPCI75C3_REG_AR_BIT_STATUS_ADD        (0x380 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_COMPILE_TIME          (0x390 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_DSP_REV_ADD           (0x3B8 << ADDR_SHIFT)
#define CPCI75C3_REG_AR_FPGA_REV_ADD          (0x3BA << ADDR_SHIFT)
#define CPCI75C3_REG_AR_MODULE_ID_ADD         (0x3BC << ADDR_SHIFT)

/*********   ARINC Specific Functions   *********/

_75C3FUNC int CPCI75C3_AR_CheckCardModuleChannel( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_AR_CheckCardModule( int Card, int Module );

_75C3FUNC int CPCI75C3_AR_GetMaxChan(unsigned short ModuleID, int *MaxChan);
_75C3FUNC int CPCI75C3_AR_GetMaxFifoCount(unsigned short ModuleID, int *MaxFifoCount);
_75C3FUNC int CPCI75C3_AR_GetMaxDataRate(unsigned short ModuleID, int *MaxDataRate);

/******  Device Control  ******/
_75C3FUNC int CPCI75C3_AR_ResetModule( int Card, int Module );

/******  Time Stamping  ******/
_75C3FUNC int CPCI75C3_AR_ResetTimeStamp( int Card, int Module );
_75C3FUNC int CPCI75C3_AR_SetTimeStampRsln( int Card, int Module, int Resolution );
_75C3FUNC int CPCI75C3_AR_GetTimeStampRsln( int Card, int Module, int* Resolution );
_75C3FUNC int CPCI75C3_AR_SetTimeCtrlReg( int Card, int Module, int Value  );
_75C3FUNC int CPCI75C3_AR_GetTimeCtrlReg( int Card, int Module, int* Value );
_75C3FUNC int CPCI75C3_AR_GetModuleTimeStamp( int Card, int Module, int* Timestamp );

/******  Page / Memory I/O  ******/
_75C3FUNC int CPCI75C3_AR_SetPageReg( int Card, int Module,  int  Page );
_75C3FUNC int CPCI75C3_AR_GetPageReg( int Card, int Module,  int* Page );
_75C3FUNC int CPCI75C3_AR_WrMemLoc( int Card, int Module,  int  Address, unsigned short Data );
_75C3FUNC int CPCI75C3_AR_RdMemLoc( int Card, int Module,  int Address, unsigned short* Data );
_75C3FUNC int CPCI75C3_AR_SetMemPage( int Card, int Module, int Channel,  int Memtype, int  Page );
_75C3FUNC int CPCI75C3_AR_GetMemPage( int Card, int Module, int* Channel,  int* Memtype, int* Page );
_75C3FUNC int CPCI75C3_AR_SetDataBlock( int Card, int Module, int AddrOffset, unsigned short *Data, int NumWords );
_75C3FUNC int CPCI75C3_AR_GetDataBlock( int Card, int Module, int AddrOffset, unsigned short *Data, int NumWords );

/******  Message, Schedule, Validation I/O  ******/
_75C3FUNC int CPCI75C3_AR_WrTxMsgMem( int Card, int Module, int Channel, int Address, unsigned int Data );
_75C3FUNC int CPCI75C3_AR_RdTxMsgMem( int Card, int Module, int Channel, int Address, unsigned int* Data );
_75C3FUNC int CPCI75C3_AR_WrTxSchMem( int Card, int Module, int Channel, int Address, unsigned short Data );
_75C3FUNC int CPCI75C3_AR_RdTxSchMem( int Card, int Module, int Channel, int Address, unsigned short* Data );
_75C3FUNC int CPCI75C3_AR_WrRxValMem( int Card, int Module, int Channel, int Label, unsigned char Data );
_75C3FUNC int CPCI75C3_AR_RdRxValMem( int Card, int Module, int Channel, int Label, unsigned char* Data );
_75C3FUNC int CPCI75C3_AR_WrTxAsyncWd( int Card, int Module, int Channel, unsigned int Data );
_75C3FUNC int CPCI75C3_AR_RdTxAsyncWd( int Card, int Module, int Channel, unsigned int* Data );

/******      Channel Configuration      ******/
_75C3FUNC int CPCI75C3_AR_SetControlLoWord( int Card, int Module, int Channel, int  ControlLow );
_75C3FUNC int CPCI75C3_AR_GetControlLoWord( int Card, int Module, int Channel, int* ControlLow );
_75C3FUNC int CPCI75C3_AR_SetControlHiWord( int Card, int Module, int Channel, int  ControlHigh );
_75C3FUNC int CPCI75C3_AR_GetControlHiWord( int Card, int Module, int Channel, int* ControlHigh );
_75C3FUNC int CPCI75C3_AR_SetParityAsData( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetParityAsData( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetDataRate( int Card, int Module, int Channel, int  DataRate );
_75C3FUNC int CPCI75C3_AR_GetDataRate( int Card, int Module, int Channel, int* DataRate );
_75C3FUNC int CPCI75C3_AR_SetTxEnable( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetTxEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetRxEnable( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetRxEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetBITdisable( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetBITdisable( int Card, int Module, int Channel, int* Enable );

/* Receive Configuration and Control*/
_75C3FUNC int CPCI75C3_AR_SetRxFifoThreshold( int Card, int Module, int Channel, int  RxFifoThreshold );
_75C3FUNC int CPCI75C3_AR_GetRxFifoThreshold( int Card, int Module, int Channel, int* RxFifoThreshold );
_75C3FUNC int CPCI75C3_AR_SetRxMode( int Card, int Module, int Channel, int  TxSendMode );
_75C3FUNC int CPCI75C3_AR_GetRxMode( int Card, int Module, int Channel, int* TxSendMode );
_75C3FUNC int CPCI75C3_AR_SetRxValidationEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetRxValidationEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetRxTimeStampEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetRxTimeStampEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetRxStoreErrorDisable( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_AR_GetRxStoreErrorDisable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_ClearRxFifo( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_AR_ClearRxValMem( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_AR_SetRxValMem( int Card, int Module, int Channel );

/* Transmit Configuration and Control */
_75C3FUNC int CPCI75C3_AR_SetTxFifoThreshold( int Card, int Module, int Channel, int  TxFifoThreshold );
_75C3FUNC int CPCI75C3_AR_GetTxFifoThreshold( int Card, int Module, int Channel, int* TxFifoThreshold );
_75C3FUNC int CPCI75C3_AR_SetTxIntervalRate( int Card, int Module, int Channel, int  TxRate );
_75C3FUNC int CPCI75C3_AR_GetTxIntervalRate( int Card, int Module, int Channel, int* TxRate );
_75C3FUNC int CPCI75C3_AR_SetTxSendMode( int Card, int Module, int Channel, int  TxSendMode );
_75C3FUNC int CPCI75C3_AR_GetTxSendMode( int Card, int Module, int Channel, int* TxSendMode );
_75C3FUNC int CPCI75C3_AR_SetTxSendTrigger( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_AR_SetTxPause( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_AR_SetTxStop( int Card, int Module, int Channel );

_75C3FUNC int CPCI75C3_AR_ClearTxFifo( int Card, int Module, int Channel );

/******      Transmit and Receive      ******/
_75C3FUNC int CPCI75C3_AR_TransmitBuffer( int Card, int Module, int Channel, unsigned int* Buffer, int* Length );
_75C3FUNC int CPCI75C3_AR_WriteWord( int Card, int Module, int Channel, unsigned int WordValue );
_75C3FUNC int CPCI75C3_AR_ReadWord( int Card, int Module, int Channel, unsigned short* StatusWord, unsigned int* WordValue );
_75C3FUNC int CPCI75C3_AR_ReadWordWTStmp( int Card, int Module, int Channel, unsigned short* StatusWord, unsigned int* WordValue, unsigned int* TimeStamp );
_75C3FUNC int CPCI75C3_AR_ReadFifo( int Card, int Module, int Channel, unsigned short* Status, unsigned int* Data, unsigned int* TimeStamp, int *NumWords);
_75C3FUNC int CPCI75C3_AR_ReadFifoMBox( int Card, int Module, int Channel, unsigned short* WordValue );

_75C3FUNC int CPCI75C3_AR_ReadMBox( int Card, int Module, int Channel, int Label, unsigned short* StatusWord, unsigned int* WordValue );
_75C3FUNC int CPCI75C3_AR_ReadMBoxWTStmp( int Card, int Module, int Channel, int Label, unsigned short* StatusWord, unsigned int* WordValue, unsigned int* TimeStamp );


/******      Status      ******/
_75C3FUNC int CPCI75C3_AR_GetChannelStatus( int Card, int Module, int Channel, int* StatusWd );
_75C3FUNC int CPCI75C3_AR_GetBITstatus( int Card, int Module, int* StatusWd );
_75C3FUNC int CPCI75C3_AR_GetTxSendSeqStatus( int Card, int Module, int Channel, int* StatusWd );
_75C3FUNC int CPCI75C3_AR_GetTxFifoStatus( int Card, int Module, int Channel, int* FifoStatus );
_75C3FUNC int CPCI75C3_AR_GetRxFifoStatus( int Card, int Module, int Channel, int* FifoStatus );
_75C3FUNC int CPCI75C3_AR_GetTxBufferCnt( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_AR_GetRxBufferCnt( int Card, int Module, int Channel, int* Count );

/******      Interrupts      ******/
_75C3FUNC int CPCI75C3_AR_GetInterruptStatusWord( int Card, int Module, int Channel, int* IrqStatusWord );
_75C3FUNC int CPCI75C3_AR_SetInterruptEnable( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_AR_GetInterruptEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_AR_SetInterruptVector( int Card, int Module, int Channel, int Vector );
_75C3FUNC int CPCI75C3_AR_GetInterruptVector( int Card, int Module, int Channel, int* Vector );

#ifdef __cplusplus
}
#endif

#endif

