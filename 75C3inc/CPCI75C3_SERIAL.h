/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_SERIAL.h

Description:

 Include file to the CPCI75C3 - Serial RS-232, RS-422 and RS-485 Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_SER_H
#define _CPCI75C3_SER_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef MSG_MAX_SIZE
#define MSG_MAX_SIZE         4150	 /* max 4K words +  some overhead */
#endif
#define P8_MAX_CHAN        4

/*      P8 definintions      */

/* Number of bytes that can be stored in a FIFO. */
#define P8_MAX_FIFO_COUNT       32767	  /* 32k Bytes*/

/* Max baud rate for sync channels. */
#define P8_MAX_SYNCBAUD       8000000  /* 8 Mbps */

/* Max baud rate for async channels. */
#define P8_MAX_ASYNCBAUD      1000000  /* 1 Mbps */

/* Max # of data to be read in a buffer */
#define SER_MAX_RECEIVE			4096

/* Status byte of data */
#define SER_PARITY_ERROR		0x8000
#define SER_FRAMING_ERROR		0x4000
#define SER_OVERRUN_ERROR		0x2000
#define SER_EOF					0x0400
#define SER_PARITY_BIT			0x0200
#define SER_SYNC_EOF          0x0200
#define SER_SYNC_BOF          0x4000
#define SER_SYNC_ER0          0x0400
#define SER_SYNC_ER1          0x0800
#define SER_SYNC_ER2          0x1000

/* Configuration settings */
/* Protocol */
#define ASYNC						0x0000
#define MONOSYNC					0x0001
#define BISYNC						0x0002
#define HDLC						0x0003
#define PPP_ASYNC					0x0004
#define EXT_TRANSPARENT			0x0005

/* Clock Mode */
#define TXINT_RXINT				0x0000
#define TXEXT_RXEXT				0x0001
#define TXCLKA_RXINT				0x0001

/* Interface Levels */
#define RS232						0x0000
#define RS422						0x0002
#define RS485						0x0003
#define LOOPBACK					0x0004
#define TRISTATE					0x0005

/* Parity */
#define SER_PARITY_NONE       0
#define SER_PARITY_SPACE      1
#define SER_PARITY_ODD        3
#define SER_PARITY_EVEN       5
#define SER_PARITY_MARK       7

/* Tx-Rx Configuration */
/* Config High */
#define SER_RTX_CTS           0x0001
#define SER_DTS_DSR           0x0002
#define SER_ADDR_LEN_16       0x0080
#define SER_ADDR_REC          0x0040
#define SER_TERMCHAR_DETECT   0x1000
#define SER_XON_XOFF_CNTL     0x2000
#define SER_XON_ASDATA        0x4000
#define SER_TIMEOUT_DETECT    0x8000

/* Config Low */
#define SER_HDLC_CRC16        0x0002
#define SER_APPEND_CRC        0x0004
#define SER_IDLE_FLAG         0x0020
#define SER_DATA_INVERT       0x0040

/* Interrupts */
#define SER_INT_PARITY_ERROR		0x0001
#define SER_INT_RXBUF_ALMOST_FULL	0x0002
#define SER_INT_CRC_ERROR			0x0004
#define SER_INT_RXCOMPLETE			0x0008
#define SER_INT_RXAVAILABLE			0x0010
#define SER_INT_RXOVERRUN			0x0020
#define SER_INT_HIGH_WATERMARK		0x0040
#define SER_INT_LOW_WATERMARK		0x0080
#define SER_INT_TXBUF_ALMOST_EMPTY	0x0100
#define SER_INT_TXCOMPLETE			0x0200
#define SER_INT_TIMEOUT				0x0400
#define SER_INT_BREAK_ABORT			0x0800
#define SER_INT_SYNCDETECT			0x1000

/* TxRx Configuration Word */
#define SER_CFG_TIMEOUT				0x8000

/* Control Low word */
#define SER_CONTROL_RTS                         0x0001
#define SER_CONTROL_CTS                         0x0002
#define SER_CONTROL_DTR                         0x0004
#define SER_CONTROL_DTS                         0x0008
#define SER_CONTROL_DCD                         0x0010
/*#define SER_CONTROL_TX_INITIATE                 0x0020 moved to Control Hi */
/*#define SER_CONTROL_ASYN_TX_ALWAYS              0x0040 moved to Control Hi */
#define SER_CONTROL_AUTO_TX_MODE_ENABLE         0x0080
#define SER_CONTROL_TXR_ENABLE                  0x0100
/*#define SER_CONTROL_RXR_ENABLE                  0x0200 moved to Control Hi */
#define SER_CONTROL_SEND_BREAKABORT             0x0400
/*#define SER_CONTROL_ENTER_HUNTSYNC              0x0800 moved to Control Ext */
#define SER_CONTROL_CHANNEL_FIFO_UART_RESET     0x2000
#define SER_CONTROL_CLEAR_RX_FIFO               0x4000
#define SER_CONTROL_CLEAR_TX_FIFO               0x8000

/* Control High word */
#define SER_CONTROL_TX_INITIATE                             0x0001
#define SER_CONTROL_ASYN_TX_ALWAYS									0x0002
#define SER_CONTROL_RXR_ENABLE                              0x0004

/* Control Extended word */
#define SER_CONTROL_ENTER_HUNTSYNC                          0x8000

/****************************/
/* SERIAL Module Registers  */
/****************************/
/* Note, P1 and P8 serial modules are 4 channels and P3 is 6 channels, however register map is
   configured for 6 channels */
#define CPCI75C3_REG_SER_TX_BUFFER_ADD {\
 0x000 << ADDR_SHIFT, 0x002 << ADDR_SHIFT, 0x004 << ADDR_SHIFT, 0x006  << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_RX_BUFFER_ADD {\
 0x00C << ADDR_SHIFT, 0x00E << ADDR_SHIFT, 0x010 << ADDR_SHIFT, 0x012 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TX_BUFFER_CNT_ADD {\
 0x018 << ADDR_SHIFT, 0x01A << ADDR_SHIFT, 0x01C << ADDR_SHIFT, 0x01E << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_RX_BUFFER_CNT_ADD {\
 0x024 << ADDR_SHIFT, 0x026 << ADDR_SHIFT, 0x028 << ADDR_SHIFT, 0x02A << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_PROTOCOL_ADD {\
 0x030 << ADDR_SHIFT, 0x032 << ADDR_SHIFT, 0x034 << ADDR_SHIFT, 0x036 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_CLOCK_MODE_ADD {\
 0x03C << ADDR_SHIFT, 0x03E << ADDR_SHIFT, 0x040 << ADDR_SHIFT, 0x042 << ADDR_SHIFT \
}

/*******************************************************************/
/* Note Interface Level Registers are different for Serial modules */
/* Explicitly appended addresses as channels 5 and 6 for 6 channel modules */
/*******************************************************************/
#define CPCI75C3_REG_SER_INTERFACE_LEVEL_ADD {\
 0x048 << ADDR_SHIFT, 0x04A << ADDR_SHIFT, 0x04C << ADDR_SHIFT, 0x04E << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TXRX_CFG_LO_ADD {\
 0x054 << ADDR_SHIFT, 0x058 << ADDR_SHIFT, 0x05C << ADDR_SHIFT, 0x060 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TXRX_CFG_HI_ADD {\
 0x056 << ADDR_SHIFT, 0x05A << ADDR_SHIFT, 0x05E << ADDR_SHIFT, 0x062 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_CHAN_CTL_LO_ADD {\
 0x06C << ADDR_SHIFT, 0x070 << ADDR_SHIFT, 0x074 << ADDR_SHIFT, 0x078 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_CHAN_CTL_HI_ADD {\
 0x06E << ADDR_SHIFT, 0x072 << ADDR_SHIFT, 0x076 << ADDR_SHIFT, 0x07A << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_CHAN_CTL_EXT_ADD {\
 0x138 << ADDR_SHIFT, 0x13A << ADDR_SHIFT, 0x13C << ADDR_SHIFT, 0x13E << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_DATA_CFG_ADD {\
 0x084 << ADDR_SHIFT, 0x086 << ADDR_SHIFT, 0x088 << ADDR_SHIFT, 0x08A << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_BAUD_RATE_LO_ADD {\
 0x090 << ADDR_SHIFT, 0x094 << ADDR_SHIFT, 0x098 << ADDR_SHIFT, 0x09C << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_BAUD_RATE_HI_ADD {\
 0x092 << ADDR_SHIFT, 0x096 << ADDR_SHIFT, 0x09A << ADDR_SHIFT, 0x09E << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_PREAMBLE_ADD {\
 0x0A8 << ADDR_SHIFT, 0x0AA << ADDR_SHIFT, 0x0AC << ADDR_SHIFT, 0x0AE << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TX_BUF_ALMOST_EMPTY_ADD {\
 0x0B4 << ADDR_SHIFT, 0x0B6 << ADDR_SHIFT, 0x0B8 << ADDR_SHIFT, 0x0BA << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_RX_BUF_ALMOST_FULL_ADD {\
 0x0C0 << ADDR_SHIFT, 0x0C2 << ADDR_SHIFT, 0x0C4 << ADDR_SHIFT, 0x0C6 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_RX_BUF_HI_WATERMARK_ADD {\
 0x0CC << ADDR_SHIFT, 0x0CE << ADDR_SHIFT, 0x0D0 << ADDR_SHIFT, 0x0D2 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_RX_BUF_LO_WATERMARK_ADD {\
 0x0D8 << ADDR_SHIFT, 0x0DA << ADDR_SHIFT, 0x0DC << ADDR_SHIFT, 0x0DE << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_HDLC_ADDR_SYNC_CHAR_ADD {\
 0x0E4 << ADDR_SHIFT, 0x0E6 << ADDR_SHIFT, 0x0E8 << ADDR_SHIFT, 0x0EA << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_HDLC_ADDR_CHAR_TX_ADD {\
 0x144 << ADDR_SHIFT, 0x146 << ADDR_SHIFT, 0x148 << ADDR_SHIFT, 0x14A << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TERM_CHAR_ADD {\
 0x0F0 << ADDR_SHIFT, 0x0F2 << ADDR_SHIFT, 0x0F4 << ADDR_SHIFT, 0x0F6 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_XON_CHAR_ADD {\
 0x0FC << ADDR_SHIFT, 0x0FE << ADDR_SHIFT, 0x100 << ADDR_SHIFT, 0x102 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_XOFF_CHAR_ADD {\
 0x108 << ADDR_SHIFT, 0x10A << ADDR_SHIFT, 0x10C << ADDR_SHIFT, 0x10E << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_FIFO_STATUS_ADD {\
 0x114 << ADDR_SHIFT, 0x116 << ADDR_SHIFT, 0x118 << ADDR_SHIFT, 0x11A << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_TIMEOUT_VALUE_ADD {\
 0x120 << ADDR_SHIFT, 0x122 << ADDR_SHIFT, 0x124 << ADDR_SHIFT, 0x126 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_INTERRUPT_ENABLE_ADD {\
 0x180 << ADDR_SHIFT, 0x182 << ADDR_SHIFT, 0x184 << ADDR_SHIFT, 0x186 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_INTERRUPT_STATUS_ADD {\
 0x18C << ADDR_SHIFT, 0x18E << ADDR_SHIFT, 0x190 << ADDR_SHIFT, 0x192 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_INTERRUPT_VECTOR_ADD {\
 0x3C2 << ADDR_SHIFT, 0x3C4 << ADDR_SHIFT, 0x3C6 << ADDR_SHIFT, 0x3C8 << ADDR_SHIFT \
}

#define CPCI75C3_REG_SER_CHAN_STATUS_ADD {\
 0x1A4 << ADDR_SHIFT, 0x1A6 << ADDR_SHIFT, 0x1A8 << ADDR_SHIFT, 0x1AA << ADDR_SHIFT \
}


/*********   Serial Specific Functions   *********/

_75C3FUNC int CPCI75C3_SER_CheckCardModuleChannel( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_SER_GetMaxChan(unsigned short ModuleID, int *MaxChan);
_75C3FUNC int CPCI75C3_SER_GetMaxFifoCount(unsigned short ModuleID, int *MaxFifoCount);
_75C3FUNC int CPCI75C3_SER_GetMaxBaudRate(unsigned short ModuleID, int Synchronous, int *MaxBaudRate);

/******      Transmit and Receive      ******/
_75C3FUNC int CPCI75C3_SER_WriteByte( int Card, int Module, int Channel, unsigned char ByteValue );
_75C3FUNC int CPCI75C3_SER_WriteWord( int Card, int Module, int Channel, unsigned short WordValue );
_75C3FUNC int CPCI75C3_SER_ReadByte( int Card, int Module, int Channel, unsigned char* ByteValue );
_75C3FUNC int CPCI75C3_SER_TransmitBuffer( int Card, int Module, int Channel, unsigned char* Buffer, int* Length );
_75C3FUNC int CPCI75C3_SER_TransmitBufferWord( int Card, int Module, int Channel, unsigned short* Buffer, int* Length );
_75C3FUNC int CPCI75C3_SER_ReceiveBuffer( int Card, int Module, int Channel, unsigned char* Buffer, int* Length );
_75C3FUNC int CPCI75C3_SER_ReceiveBufferWStatus( int Card, int Module, int Channel, unsigned short* Buffer, int* Length );
_75C3FUNC int CPCI75C3_SER_ReadByteWStatus( int Card, int Module, int Channel, unsigned short* WordValue );
_75C3FUNC int CPCI75C3_SER_ReadFifo( int Card, int Module, int Channel, unsigned char* Buffer, int maxCount, int* countReceived, int* countLeft );
_75C3FUNC int CPCI75C3_SER_GetHDLCPacket( int Card, int Module, int Channel, unsigned short* DataBlock, int nMaxCount, int* nCountReceived );
_75C3FUNC int CPCI75C3_SER_GetHDLCPacketTimeout( int Card, int Module, int Channel, unsigned short* DataBlock, int nMaxCount, int* nCountReceived, int nMaxTimeMs );

/******      Buffer And Channel Status      ******/
_75C3FUNC int CPCI75C3_SER_GetTxBufferCnt( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_SER_GetRxBufferCnt( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_SER_GetFifoFlags( int Card, int Module, int Channel, int* FifoFlags );
_75C3FUNC int CPCI75C3_SER_GetChannelStatusWord( int Card, int Module, int Channel, int* ChannelStatus );

/******      Baudrate      ******/
_75C3FUNC int CPCI75C3_SER_SetBaudrate( int Card, int Module, int Channel, int  BaudRate, int Synchronous );
_75C3FUNC int CPCI75C3_SER_GetBaudrate( int Card, int Module, int Channel, int* BaudRate );
_75C3FUNC int CPCI75C3_SER_SetBaudrateLoWord( int Card, int Module, int Channel, int  BaudRateLow );
_75C3FUNC int CPCI75C3_SER_GetBaudrateLoWord( int Card, int Module, int Channel, int* BaudRateLow );
_75C3FUNC int CPCI75C3_SER_SetBaudrateHiWord( int Card, int Module, int Channel, int  BaudRateHigh );
_75C3FUNC int CPCI75C3_SER_GetBaudrateHiWord( int Card, int Module, int Channel, int* BaudRateHigh );

/******       Protcol      ******/
_75C3FUNC int CPCI75C3_SER_SetProtocol( int Card, int Module, int Channel, int Protocol );
_75C3FUNC int CPCI75C3_SER_GetProtocol( int Card, int Module, int Channel, int* Protocol );

/******       ClockMode      ******/
_75C3FUNC int CPCI75C3_SER_SetClockMode( int Card, int Module, int Channel, int ClockMode );
_75C3FUNC int CPCI75C3_SER_GetClockMode( int Card, int Module, int Channel, int* ClockMode );

/******      Channel Interface Level      ******/
_75C3FUNC int CPCI75C3_SER_SetInterfaceLevel( int Card, int Module, int Channel, int Level );
_75C3FUNC int CPCI75C3_SER_GetInterfaceLevel( int Card, int Module, int Channel, int* Level );

/******      Channel Configuration      ******/
_75C3FUNC int CPCI75C3_SER_SetConfigWord( int Card, int Module, int Channel, int  ConfigLow, int ConfigHigh );
_75C3FUNC int CPCI75C3_SER_GetConfigWord( int Card, int Module, int Channel, int* ConfigLow, int* ConfigHigh );
_75C3FUNC int CPCI75C3_SER_SetConfigLoWord( int Card, int Module, int Channel, int  ConfigLow );
_75C3FUNC int CPCI75C3_SER_GetConfigLoWord( int Card, int Module, int Channel, int* ConfigLow );
_75C3FUNC int CPCI75C3_SER_SetConfigHiWord( int Card, int Module, int Channel, int  ConfigHigh );
_75C3FUNC int CPCI75C3_SER_GetConfigHiWord( int Card, int Module, int Channel, int* ConfigHigh );
_75C3FUNC int CPCI75C3_SER_SetDataConfigWord( int Card, int Module, int Channel, int  DataConfig );
_75C3FUNC int CPCI75C3_SER_GetDataConfigWord( int Card, int Module, int Channel, int* DataConfig );
_75C3FUNC int CPCI75C3_SER_SetParity( int Card, int Module, int Channel, int Parity );
_75C3FUNC int CPCI75C3_SER_GetParity( int Card, int Module, int Channel, int* Parity );
_75C3FUNC int CPCI75C3_SER_SetDataBits( int Card, int Module, int Channel, int DataBits );
_75C3FUNC int CPCI75C3_SER_GetDataBits( int Card, int Module, int Channel, int* DataBits );
_75C3FUNC int CPCI75C3_SER_SetStopBits( int Card, int Module, int Channel, int StopBits );
_75C3FUNC int CPCI75C3_SER_GetStopBits( int Card, int Module, int Channel, int* StopBits );
_75C3FUNC int CPCI75C3_SER_SetEncoding( int Card, int Module, int Channel, int Encoding );
_75C3FUNC int CPCI75C3_SER_GetEncoding( int Card, int Module, int Channel, int* Encoding );
_75C3FUNC int CPCI75C3_SER_SetPreamble( int Card, int Module, int Channel, int Preamble );
_75C3FUNC int CPCI75C3_SER_GetPreamble( int Card, int Module, int Channel, int* Preamble );
_75C3FUNC int CPCI75C3_SER_SetTxBufferAlmostEmpty( int Card, int Module, int Channel, int Count );
_75C3FUNC int CPCI75C3_SER_GetTxBufferAlmostEmpty( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_SER_SetRxBufferAlmostFull( int Card, int Module, int Channel, int Count );
_75C3FUNC int CPCI75C3_SER_GetRxBufferAlmostFull( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_SER_SetRxBufferHiWatermark( int Card, int Module, int Channel, int Count );
_75C3FUNC int CPCI75C3_SER_GetRxBufferHiWatermark( int Card, int Module, int Channel, int* Count );
_75C3FUNC int CPCI75C3_SER_SetRxBufferLoWatermark( int Card, int Module, int Channel, int Count );
_75C3FUNC int CPCI75C3_SER_GetRxBufferLoWatermark( int Card, int Module, int Channel, int* Count );

/******      Channel Control      ******/
_75C3FUNC int CPCI75C3_SER_SetControlLoWord( int Card, int Module, int Channel, int  ControlLow );
_75C3FUNC int CPCI75C3_SER_GetControlLoWord( int Card, int Module, int Channel, int* ControlLow );
_75C3FUNC int CPCI75C3_SER_SetControlHiWord( int Card, int Module, int Channel, int  ControlHigh );
_75C3FUNC int CPCI75C3_SER_GetControlHiWord( int Card, int Module, int Channel, int* ControlHigh );
_75C3FUNC int CPCI75C3_SER_SetControlExtWord( int Card, int Module, int Channel, int  ControlExt );
_75C3FUNC int CPCI75C3_SER_GetControlExtWord( int Card, int Module, int Channel, int* ControlExt );
_75C3FUNC int CPCI75C3_SER_SetReceiverEnable( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_SER_GetReceiverEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_SER_SetRTS( int Card, int Module, int Channel, int Active );
_75C3FUNC int CPCI75C3_SER_GetRTS( int Card, int Module, int Channel, int* Active );
_75C3FUNC int CPCI75C3_SER_SetDTR( int Card, int Module, int Channel, int Active );
_75C3FUNC int CPCI75C3_SER_GetDTR( int Card, int Module, int Channel, int* Active );
_75C3FUNC int CPCI75C3_SER_GetCTS( int Card, int Module, int Channel, int* Active );
_75C3FUNC int CPCI75C3_SER_GetDCD( int Card, int Module, int Channel, int* Active );
_75C3FUNC int CPCI75C3_SER_TransmitInitiate( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_SER_TransmitStop( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_SER_AsyncTransmitControl( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_SER_EnterHuntSyncControl( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_SER_ChannelReset( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_SER_ClearRxFifo( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_SER_ClearTxFifo( int Card, int Module, int Channel );


/******      HDLC Address      ******/
_75C3FUNC int CPCI75C3_SER_SetHdlcAddrsSyncChar( int Card, int Module, int Channel, int SyncChar );
_75C3FUNC int CPCI75C3_SER_GetHdlcAddrsSyncChar( int Card, int Module, int Channel, int* SyncChar );
_75C3FUNC int CPCI75C3_SER_SetHdlcAddrsCharTx( int Card, int Module, int Channel, int SyncChar );
_75C3FUNC int CPCI75C3_SER_GetHdlcAddrsCharTx( int Card, int Module, int Channel, int* SyncChar );
_75C3FUNC int CPCI75C3_SER_SetTerminationChar( int Card, int Module, int Channel, int TermChar );
_75C3FUNC int CPCI75C3_SER_GetTerminationChar( int Card, int Module, int Channel, int* TermChar );
_75C3FUNC int CPCI75C3_SER_SetXonChar( int Card, int Module, int Channel, int XonChar );
_75C3FUNC int CPCI75C3_SER_GetXonChar( int Card, int Module, int Channel, int* XonChar );
_75C3FUNC int CPCI75C3_SER_SetXoffChar( int Card, int Module, int Channel, int XoffChar );
_75C3FUNC int CPCI75C3_SER_GetXoffChar( int Card, int Module, int Channel, int* XoffChar );

/******       TimeOut      ******/
_75C3FUNC int CPCI75C3_SER_SetTimeout( int Card, int Module, int Channel, int Timeout );
_75C3FUNC int CPCI75C3_SER_GetTimeout( int Card, int Module, int Channel, int* Timeout );

/******      Interrupts      ******/
_75C3FUNC int CPCI75C3_SER_GetInterruptStatusWord( int Card, int Module, int Channel, int* IrqStatusWord );
_75C3FUNC int CPCI75C3_SER_SetInterruptEnable( int Card, int Module, int Channel, int Enable );
_75C3FUNC int CPCI75C3_SER_GetInterruptEnable( int Card, int Module, int Channel, int* Enable );
_75C3FUNC int CPCI75C3_SER_SetInterruptVector( int Card, int Module, int Channel, int Vector );
_75C3FUNC int CPCI75C3_SER_GetInterruptVector( int Card, int Module, int Channel, int* Vector );

/* #################################### */
/*  Internal Use Only                   */
/*  Utility functions                   */
/* #################################### */
int CPCI75C3_SER_ReadRegMultipleMatch( int Card, int RegAddrs, int RegAddrsCount, unsigned short *DataBlock,
  unsigned short LastWord, int MaxWordCount, BOOL bMask, int *CountReceived, int TimeoutMs );

#ifdef __cplusplus
}
#endif

#endif

