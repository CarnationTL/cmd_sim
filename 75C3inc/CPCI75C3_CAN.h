/**
 *=========================================================================
 *
 * Copyright (c) 2011 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: CPCI75C3
 *
 * SubSystem: CANbus Module
 *
 * FileName: CPCI75C3_CAN.h
 *
 * $Archive: /SW Code Base/NAI_CPCI75C3/LibSrc/include/CPCI75C3_CAN.h $
 *
 * $Revision: 7 $
 *
 * $Date: 7/18/11 1:42p $
 *
 * $NoKeywords: $
 *=========================================================================
 **/
#ifndef _CPCI75C3_CAN_H_
#define _CPCI75C3_CAN_H_

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 


/**************************/
/*  CAN Module Registers  */
/**************************/
#define CPCI75C3_REG_CAN_CTRL_ADD {\
 0x000 << ADDR_SHIFT, 0x020 << ADDR_SHIFT, 0x040 << ADDR_SHIFT, 0x060 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_RX_BUFFER_ADD {\
 0x002 << ADDR_SHIFT, 0x022 << ADDR_SHIFT, 0x042 << ADDR_SHIFT, 0x062 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_RX_BUFFER_COUNT_ADD {\
 0x004 << ADDR_SHIFT, 0x024 << ADDR_SHIFT, 0x044 << ADDR_SHIFT, 0x064 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_RX_FRAME_COUNT_ADD {\
 0x006 << ADDR_SHIFT, 0x026 << ADDR_SHIFT, 0x046 << ADDR_SHIFT, 0x066 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_TX_BUFFER_ADD {\
 0x008 << ADDR_SHIFT, 0x028 << ADDR_SHIFT, 0x048 << ADDR_SHIFT, 0x068 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_TX_BUFFER_COUNT_ADD {\
 0x00A << ADDR_SHIFT, 0x02A << ADDR_SHIFT, 0x04A << ADDR_SHIFT, 0x06A << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_TX_FRAME_COUNT_ADD {\
 0x00C << ADDR_SHIFT, 0x02C << ADDR_SHIFT, 0x04C << ADDR_SHIFT, 0x06C << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_PRIO_FILTER_ADD {\
 0x00E << ADDR_SHIFT, 0x02E << ADDR_SHIFT, 0x04E << ADDR_SHIFT, 0x06E << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_PGN_HI_FILTER_ADD {\
 0x00E << ADDR_SHIFT, 0x02E << ADDR_SHIFT, 0x04E << ADDR_SHIFT, 0x06E << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_PGN_LO_FILTER_ADD {\
 0x010 << ADDR_SHIFT, 0x030 << ADDR_SHIFT, 0x050 << ADDR_SHIFT, 0x070 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_SRC_FILTER_ADD {\
 0x012 << ADDR_SHIFT, 0x032 << ADDR_SHIFT, 0x052 << ADDR_SHIFT, 0x072 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_LAST_ERROR_ADD {\
 0x014 << ADDR_SHIFT, 0x034 << ADDR_SHIFT, 0x054 << ADDR_SHIFT, 0x074 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_COMM_STATUS_ADD {\
 0x016 << ADDR_SHIFT, 0x036 << ADDR_SHIFT, 0x056 << ADDR_SHIFT, 0x076 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ADDRESS_ADD {\
 0x018 << ADDR_SHIFT, 0x038 << ADDR_SHIFT, 0x058 << ADDR_SHIFT, 0x078 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_BAUDRATE_ADD {\
 0x01A << ADDR_SHIFT, 0x03A << ADDR_SHIFT, 0x05A << ADDR_SHIFT, 0x07A << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_PRESCALER_EXT_ADD {\
 0x01C << ADDR_SHIFT, 0x03C << ADDR_SHIFT, 0x05C << ADDR_SHIFT, 0x07C << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ERROR_COUNTER_ADD {\
 0x01E << ADDR_SHIFT, 0x03E << ADDR_SHIFT, 0x05E << ADDR_SHIFT, 0x07E << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ACCEPT_MASK_HI_ADD {\
 0x00E << ADDR_SHIFT, 0x02E << ADDR_SHIFT, 0x04E << ADDR_SHIFT, 0x06E << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ACCEPT_MASK_LO_ADD {\
 0x010 << ADDR_SHIFT, 0x030 << ADDR_SHIFT, 0x050 << ADDR_SHIFT, 0x070 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ACCEPT_CODE_HI_ADD {\
 0x012 << ADDR_SHIFT, 0x032 << ADDR_SHIFT, 0x052 << ADDR_SHIFT, 0x072 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_ACCEPT_CODE_LO_ADD {\
 0x018 << ADDR_SHIFT, 0x038 << ADDR_SHIFT, 0x058 << ADDR_SHIFT, 0x078 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_HARDWARE_ERROR_ADD  0x080 << ADDR_SHIFT

/* right now int enable is one reg for all channels; only 1 type of int and its bit-mapped by channel (this may change) */
#define CPCI75C3_REG_CAN_INT_ENABLE_ADD {\
 0x082 << ADDR_SHIFT, 0x082 << ADDR_SHIFT, 0x082 << ADDR_SHIFT, 0x082 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_INT_STATUS_ADD {\
 0x092 << ADDR_SHIFT, 0x094 << ADDR_SHIFT, 0x096 << ADDR_SHIFT, 0x098 << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_LEVEL_CTRL_ADD                0x37A << ADDR_SHIFT

#define CPCI75C3_REG_CAN_FPGA1_REV_ADD {\
 0x388 << ADDR_SHIFT, 0x38A << ADDR_SHIFT, 0x38C << ADDR_SHIFT, 0x38E << ADDR_SHIFT\
}

#define CPCI75C3_REG_CAN_COMPILE_TIME                  0x390 << ADDR_SHIFT
#define CPCI75C3_REG_CAN_DSP_REV_ADD                   0x3B8 << ADDR_SHIFT
#define CPCI75C3_REG_CAN_FPGA_REV_ADD                  0x3BA << ADDR_SHIFT
#define CPCI75C3_REG_CAN_MODULE_ID_ADD                 0x3BC << ADDR_SHIFT

#define CPCI75C3_REG_CAN_INT_VECTOR_ADD {\
 0x3C0 << ADDR_SHIFT, 0x3C2 << ADDR_SHIFT, 0x3C4 << ADDR_SHIFT, 0x3C6 << ADDR_SHIFT\
}


/**************************/
/*    CAN Definitions     */
/**************************/
#define CAN_MAX_MSG_LEN                      255

#define CAN_MAX_FIFO_COUNT                    32767
#define CAN_FRAME_SIZE                        5

#define CAN_CHANNEL_MASK(v)                  (1<<((v)-1))
#define CAN_MSG_START                        0x8000
#define CAN_MSG_END                          0x4000
#define CAN_MSG_STD_A                        0x2000

#define CAN_ADDR_CLAIM                       0x8000
#define CAN_ADDR_CLAIM_OK                    0x4000
#define CAN_ADDR_CLAIM_FAIL                  0x2000

#define CAN_CTRL_ENABLE_TX                   0x0001
#define CAN_CTRL_ENABLE_RX                   0x0004
#define CAN_CTRL_ENABLE_SRC_FILTER           0x0020
#define CAN_CTRL_ENABLE_PRIO_FILTER          0x0040
#define CAN_CTRL_RESET                       0x8000
#define CAN_CTRL_ENABLE_ACC_CODE             0x0008
#define CAN_CTRL_ENABLE_AB_FILTER            0x0010
#define CAN_CTRL_ENABLE_STDEXT_FILT          0x0020

#define CAN_HARDWARE_ERROR_FPGA1             0x0001
#define CAN_HARDWARE_ERROR_FPGA2             0x0002
#define CAN_HARDWARE_ERROR_FPGA3             0x0004
#define CAN_HARDWARE_ERROR_FPGA4             0x0008
#define CAN_HARDWARE_ERROR_WRONG_FPGA_FILE   0x0010

#define CAN_COMM_STATUS_PARITY               0x0100
#define CAN_COMM_STATUS_BUSOFF               0x0080
#define CAN_COMM_STATUS_WARNING              0x0040
#define CAN_COMM_STATUS_EPASSIVE             0x0020
#define CAN_COMM_STATUS_RXSUCCESS            0x0010
#define CAN_COMM_STATUS_TXSUCCESS            0x0008

#define CAN_ERROR_NO_ERROR                   0
#define CAN_ERROR_STUFF_ERROR                1
#define CAN_ERROR_FORM_ERROR                 2
#define CAN_ERROR_ACK_ERROR                  3
#define CAN_ERROR_BIT1_ERROR                 4
#define CAN_ERROR_BIT0_ERROR                 5
#define CAN_ERROR_CRC_ERROR                  6
#define CAN_ERROR_NO_CHANGE                  7


/****************************************/
/******  CANbus Specific Functions ******/
/****************************************/
_75C3FUNC int CPCI75C3_CAN_GetMaxChan(unsigned short ModuleID, int *outMaxChan);
_75C3FUNC int CPCI75C3_CAN_GetMaxFifoCount(unsigned short ModuleID, int *outMaxFifoCount);
_75C3FUNC int CPCI75C3_CAN_GetFrameSize(unsigned short ModuleID, int* outFrameSize);

/******      Bit Timing      ******/
_75C3FUNC int CPCI75C3_CAN_SetBitTiming( int Card, int Module, int Channel, int Prescaler, int SJW, int TSeg1, int TSeg2 );
_75C3FUNC int CPCI75C3_CAN_GetBitTiming( int Card, int Module, int Channel, int* outPrescaler, int* outSJW, int* outTSeg1, int* outTSeg2 );

/******      Transmit and Receive      ******/
_75C3FUNC int CPCI75C3_CAN_QueueTransmit_J1939( int Card, int Module, int Channel, int PGN, int Priority, int Destination, unsigned char* Buffer, int Length );
_75C3FUNC int CPCI75C3_CAN_Transmit_J1939( int Card, int Module, int Channel, int PGN, int Priority, int Destination, unsigned char* Buffer, int Length );
_75C3FUNC int CPCI75C3_CAN_Receive_J1939( int Card, int Module, int Channel, int* outPGN, int* outSource, int* outDestination, unsigned char* Buffer, int* Length );
_75C3FUNC int CPCI75C3_CAN_QueueTransmit( int Card, int Module, int Channel, int isModeA, int MsgId, unsigned char* Buffer, int Length );
_75C3FUNC int CPCI75C3_CAN_Transmit( int Card, int Module, int Channel, int isModeA, int MsgId, unsigned char* Buffer, int Length );
_75C3FUNC int CPCI75C3_CAN_Receive( int Card, int Module, int Channel, int* outIsModeA, int* outMsgId, unsigned char* Buffer, int* Length );

/******      Message Parsing      ******/
_75C3FUNC int CPCI75C3_CAN_ConvertChannel( unsigned char* Buffer, int nStartBit, int nNumBits, int nOrder, float fScale, float fOffset, float* fValue );
_75C3FUNC int CPCI75C3_CAN_ConvertValuesToMessage( unsigned char* Buffer, int nCount, int* nStartBit, int* nNumBits, int* nOrder, float* fScale, float* fOffset, float* fValue );
_75C3FUNC int CPCI75C3_CAN_GetChannelListItem( unsigned int TaskRef, char* ChannelListItem, int nIndex );
_75C3FUNC int CPCI75C3_CAN_SetChannelListItem( unsigned int TaskRef, char* ChannelListItem, int nIndex );
_75C3FUNC int CPCI75C3_CAN_ClearChannelList( unsigned int TaskRef );
_75C3FUNC int CPCI75C3_CAN_GetChannelListCount( unsigned int TaskRef, int *nCount );
_75C3FUNC int CPCI75C3_CAN_GetCardModuleChannelInterface( unsigned int TaskRef, int* nCard, int* nModule, int* nChannel, int* nDirection );
_75C3FUNC int CPCI75C3_CAN_SetCardModuleChannelInterface( unsigned int TaskRef, int nInterfaceChannel, int nDirection );

/******      Buffer And Channel Status      ******/
_75C3FUNC int CPCI75C3_CAN_GetTxBufferCount( int Card, int Module, int Channel, int* outCount );
_75C3FUNC int CPCI75C3_CAN_GetRxBufferCount( int Card, int Module, int Channel, int* outCount );
_75C3FUNC int CPCI75C3_CAN_GetTxFrameCount( int Card, int Module, int Channel, int* outCount );
_75C3FUNC int CPCI75C3_CAN_GetRxFrameCount( int Card, int Module, int Channel, int* outCount );
_75C3FUNC int CPCI75C3_CAN_GetTxMessageWaiting( int Card, int Module, int Channel, int* outMsgWaiting );
_75C3FUNC int CPCI75C3_CAN_GetRxMessageWaiting( int Card, int Module, int Channel, int* outMsgWaiting );

_75C3FUNC int CPCI75C3_CAN_GetControl( int Card, int Module, int Channel, int* outCtrl );
_75C3FUNC int CPCI75C3_CAN_SetControl( int Card, int Module, int Channel, int Ctrl );
_75C3FUNC int CPCI75C3_CAN_ResetChannel( int Card, int Module, int Channel );

_75C3FUNC int CPCI75C3_CAN_GetCommStatus( int Card, int Module, int Channel, int* outStatus );
_75C3FUNC int CPCI75C3_CAN_GetLastError( int Card, int Module, int Channel, int* outLastError );
_75C3FUNC int CPCI75C3_CAN_GetHardwareError( int Card, int Module, int* outHError );

_75C3FUNC int CPCI75C3_CAN_GetErrorCount( int Card, int Module, int Channel, int* outIsErrorPassive, int* outRxErrors, int* outTxErrors);

/******      Address      ******/
_75C3FUNC int CPCI75C3_CAN_SetAddress( int Card, int Module, int Channel, int Address );
_75C3FUNC int CPCI75C3_CAN_GetAddress( int Card, int Module, int Channel, int* outAddress, int* outStatus );

/******    Interrupts    ******/
_75C3FUNC int CPCI75C3_CAN_SetIntEnable( int Card, int Module, int Channel, int nIntEnable );
_75C3FUNC int CPCI75C3_CAN_GetIntEnable( int Card, int Module, int Channel, int* nIntEnable );
_75C3FUNC int CPCI75C3_CAN_GetIntStatus( int Card, int Module, int Channel, int* outStatus );
_75C3FUNC int CPCI75C3_CAN_SetIntVector( int Card, int Module, int Channel, int nIntVector );
_75C3FUNC int CPCI75C3_CAN_GetIntVector( int Card, int Module, int Channel, int* nIntVector );

/******      Filters      ******/
_75C3FUNC int CPCI75C3_CAN_SetRxEnable( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_CAN_GetRxEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetTxEnable( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_CAN_GetTxEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetPrioFilterEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_CAN_GetPrioFilterEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetSrcFilterEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_CAN_GetSrcFilterEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetPrioFilter( int Card, int Module, int Channel, int PrioFilter );
_75C3FUNC int CPCI75C3_CAN_GetPrioFilter( int Card, int Module, int Channel, int* outPrioFilter );
_75C3FUNC int CPCI75C3_CAN_SetSrcFilter( int Card, int Module, int Channel, int SrcFilter );
_75C3FUNC int CPCI75C3_CAN_GetSrcFilter( int Card, int Module, int Channel, int* outSrcFilter );

_75C3FUNC int CPCI75C3_CAN_SetAcceptCodeEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_CAN_GetAcceptCodeEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetABFilterEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_CAN_GetABFilterEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetStdExtFilterEn( int Card, int Module, int Channel, int  Enable );
_75C3FUNC int CPCI75C3_CAN_GetStdExtFilterEn( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_CAN_SetAcceptMask( int Card, int Module, int Channel, int AcceptMask );
_75C3FUNC int CPCI75C3_CAN_GetAcceptMask( int Card, int Module, int Channel, int* AcceptMask );
_75C3FUNC int CPCI75C3_CAN_SetAcceptCode( int Card, int Module, int Channel, int AcceptCode );
_75C3FUNC int CPCI75C3_CAN_GetAcceptCode( int Card, int Module, int Channel, int* AcceptCode );

/******      Diagnostics      ******/
_75C3FUNC int CPCI75C3_CAN_SetLevelControl( int Card, int Module, int Channel, int Enable );


/* #################################### */
/*  Internal Use Only                   */
/*  Utility functions                   */
/* #################################### */
int CPCI75C3_CAN_CheckCardModuleChannel( int Card, int Module, int Channel );
int CPCI75C3_CAN_CheckCardModule( int Card, int Module );


#ifdef __cplusplus
}
#endif

#endif
