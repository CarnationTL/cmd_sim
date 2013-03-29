/**
 *=========================================================================
 *
 * Copyright (c) 2010 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: NAI Ethernet Library
 *
 * FileName: NAIEthernet.h
 *=========================================================================
 **/

#ifndef _NAIETHERNET_H
#define _NAIETHERNET_H

#include "nailib.h"

#ifdef WIN32
#ifndef _NAIERRNO
#define _NAIERRNO
#define NAIerrno WSAGetLastError()
#define EWOULDBLOCK WSAEWOULDBLOCK
#endif
#endif /* WIN32 */

#if defined(VXWORKS) || defined(NAI_RTP)
#ifndef _NAIERRNO
#define _NAIERRNO
#define NAIerrno errno
#endif
#endif

#if defined(LINUX) || defined(LYNX)
#define ERROR -1
#ifndef _NAIERRNO
#define _NAIERRNO
#define NAIerrno errno
#endif
#endif

#ifdef NAI_RTP
#include "strings.h"
#endif

/* The following will specify to include the decoding of the NAIETHER_STATUS for the XXX_StatusString() API */
#define ETHER_INCLUDE_STATUS_STRINGS

/* The following are the default maximum wait time for receiving an Ethernet message (TCP and UDP) */
#ifdef WIN32
#define ETHER_WAIT_RECV 1000
#endif
#if defined(VXWORKS) || defined(NAI_RTP)
#define ETHER_WAIT_RECV 1000
#endif
#if defined(LYNX)
#define ETHER_WAIT_RECV 500
#endif
#if defined(LINUX)
/* On the Linux system with TCP, one message took 6 seconds to receive, the majority was less than 50 msec */
#define ETHER_WAIT_RECV 10000
#endif

#ifdef _WITH_IPV4_SUPPORT_ONLY
#define nai_sockaddr_storage sockaddr_in
#else
#define nai_sockaddr_storage sockaddr_storage
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* General Ethernet Functions */
int NAI_GetEthernetLibVersion(double* ver);
char* NAI_GetEthernetStatusString(NAIETHER_STATUS Status);

int EtherSetMsWait(int milliseconds);
int EtherGetMsWait(void);

#define IP_PING_TIMEOUT_MS   10

/*********************************************/
/*  Note all the "make" functions return the */
/*  message length in bytes.                 */
/*********************************************/

/****************************************/
/* NAI SLAVE Boards Ethernet Messages   */
/* These APIs use 24-bit addressing     */
/****************************************/
int makeReadMsg(unsigned short seq, int regAddrs, unsigned char* data);
int decodeReadResponse(unsigned short seq, unsigned char data[], unsigned short* regValue);

int makeWriteMsg(unsigned short seq, int regAddrs, unsigned short regValue, unsigned char data[]);
int decodeWriteResponse(unsigned short seq, unsigned char data[]);

int makeBankReadMsg(unsigned short seq, int regAddrs, int count, unsigned char data[]);
int decodeBankReadResponse(unsigned short seq, int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeBankWriteMsg(unsigned short seq, int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int decodeBankWriteResponse(unsigned short seq, unsigned char data[]);

int makeMultipleReadMsg(unsigned short seq, int regAddrs, int count, unsigned char data[]);
int decodeMultipleReadResponse(unsigned short seq, int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeMultipleWriteMsg(unsigned short seq, int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int makeMultipleWriteMsgForUChar(unsigned short seq, int regAddrs, int byteCount, unsigned char data[], unsigned char multiData[]);
int decodeMultipleWriteResponse(unsigned short seq, unsigned char data[]);

int makeReadFifoMsg(unsigned short seq, unsigned int dataRegAddrs, unsigned int countRegAddrs, int maxRead, unsigned char data[]);
int decodeReadFifoResponse(unsigned short seq, unsigned int regAddrs, unsigned char data[], int *count, int *left, int *startIndex);

int makeSetIDR_ReadReg(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int RegAddr, unsigned char data[]);
int makeSetIDR_MultiReadReg(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int RegAddr, unsigned char data[], unsigned short usNumReads);
int makeSetIDR_ReadFifo(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int FIFO_regAddr, unsigned int FIFO_countAddr, int max, unsigned char data[]);
int makeSetIDR_WriteReg(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetIDRResponse(unsigned short seq, unsigned char data[]);

int makeSetPRP_ReadReg(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned int RegAddr, unsigned char data[]);
int makeSetPRP_WriteReg(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetPRPResponse(unsigned short seq, unsigned char data[]);

int makeSetPRP_ReadBlock(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned char RegBlock, unsigned char data[]);
int makeSetPRP_WriteBlock( unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], unsigned char data[]);

/****************************************/
/* NAI MASTER Boards Ethernet Messages  */
/* These APIs use 32-bit addressing     */
/****************************************/
int makeReadMsg32(unsigned short seq, unsigned int regAddrs, unsigned char data[]);
int decodeReadResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[], unsigned short* regValue);

int makeWriteMsg32(unsigned short seq, unsigned int regAddrs, unsigned short regValue, unsigned char data[]);
int decodeWriteResponse32(unsigned short seq, unsigned char data[]);

int makeBankReadMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeBankReadResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeBankWriteMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int decodeBankWriteResponse32(unsigned short seq, unsigned char data[]);

int makeMultipleReadMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeMultipleReadResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeMultipleWriteMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int makeMultipleWriteMsg32ForUChar(unsigned short seq, unsigned int regAddrs, int byteCount, unsigned char data[], unsigned char multiData[]);
int decodeMultipleWriteResponse32(unsigned short seq, unsigned char data[]);

int makeReadFifoMsg32(unsigned short seq, unsigned int dataRegAddrs, unsigned int countRegAddrs, int maxRead, unsigned char data[]);
int decodeReadFifoResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[], int *count, int *left, int *startIndex);

int makeSetIDR_ReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int RegAddr, unsigned char data[]);
int makeSetIDR_MultiReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int RegAddr, unsigned char data[], unsigned short usNumReads);
int makeSetIDR_ReadFifo32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int FIFO_regAddr, unsigned int FIFO_countAddr, int max, unsigned char data[]);
int makeSetIDR_WriteReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetIDRResponse32(unsigned short seq, unsigned char data[]);

int makeSetPRP_ReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned int RegAddr, unsigned char data[]);
int makeSetPRP_WriteReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int TimePeriod, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetPRPResponse32(unsigned short seq, unsigned char data[]);

/****************************************/
/* NAI GENERATION 3 TCP Functions       */
/* These APIs use 32-bit addressing     */
/****************************************/
int makeBank3ReadMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeBank3ReadResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeBank3WriteMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int decodeBank3WriteResponse32(unsigned short seq, unsigned char data[]);

int makeMultiple3ReadMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeMultiple3ReadResponse32(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeMultiple3WriteMsg32(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int decodeMultiple3WriteResponse32(unsigned short seq, unsigned char data[]);

int makeSetIDR3_ReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int RegAddr, unsigned char data[]);
int makeSetIDR3_Bank3ReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int InterruptIndex, unsigned int RegAddr, int BankSize, unsigned char data[]);
int makeSetIDR3_Multi3ReadReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int RegAddr, unsigned char data[], unsigned short usNumReads);
int makeSetIDR3_ReadFifo32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int FIFO_regAddr, unsigned int FIFO_countAddr, int max, unsigned char data[]);
int makeSetIDR3_WriteReg32(unsigned short seq, int slot, int TCPorUDP, char ip[], int port, int IntIndx, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetIDR3Response(unsigned short seq, unsigned char data[]);

int makeSetIDR3_IPv6_ReadReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int IntIndx, unsigned int regAddr, unsigned char data[]);
int makeSetIDR3_IPv6_Multi3ReadReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int IntIndx, unsigned int regAddr, unsigned char data[], unsigned short usNumReads);
int makeSetIDR3_IPv6_Bank3ReadReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int InterruptIndex, unsigned int regAddr, int BankSize, unsigned char data[]);
int makeSetIDR3_IPv6_ReadFifo32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int IntIndx, unsigned int FIFO_regAddr, unsigned int FIFO_countAddr, int max, unsigned char data[]);
int makeSetIDR3_IPv6_WriteReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int IntIndx, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int decodeSetIDR3_IPv6_Response(unsigned short seq, unsigned char data[]);

int makeSetPRP3_IPv6_ReadReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int TimePeriod, unsigned int regAddr, unsigned char data[]);
int makeSetPRP3_IPv6_WriteReg32(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int TimePeriod, unsigned int regAddr, unsigned int dataToWrite, unsigned char data[]);
int makeSetPRP3_IPv6_ReadBlock(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int TimePeriod, unsigned char RegBlock, unsigned char data[]);
int makeSetPRP3_IPv6_WriteBlock(unsigned short seq, int slot, int TCPorUDP, unsigned char ip[], int port, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], unsigned char data[]);
int decodeSetPRP3_IPv6_Response(unsigned short seq, unsigned char data[]);

/*************************************************/
/* NAI MASTER and SLAVE Boards Ethernet Messages */
/*************************************************/
int makeLogInMsg(unsigned short seq, unsigned char* password, unsigned char* data);
int decodeLogInResponse(unsigned short seq, unsigned char* data);

int makeLogOutMsg(unsigned short seq, unsigned char data[]);
int decodeLogOutResponse(unsigned short seq, unsigned char* data);

int makeNOPMsg(unsigned short seq, unsigned char data[]);
int decodeNOPResponse(unsigned short seq, unsigned char* data);

int makeDirectInterruptsMsg(unsigned short seq, int direction, unsigned char data[]);
int decodeDirectInterruptsResponse(unsigned short seq, unsigned char data[]);

int makeQueryDirectInterruptsMsg(unsigned short seq, unsigned char data[]);
int decodeQueryDirectInterruptsResponse(unsigned short seq, unsigned char data[], int* direction);

int makeCfgBlkMsg(unsigned short seq, int MsgBlockID, int BlockID, int RegAddrCnt, unsigned int regAddrData[], unsigned char data[]);
int decodeCfgBlkMsg(unsigned short seq, unsigned char data[]);

int makeReadBlkMsg(unsigned short seq, int MsgBlockID, unsigned char data[]);
int decodeReadBlkMsg(unsigned short seq, int MsgBlockID, unsigned char data[], int *RegAddrCnt, int *startIndex);

int makeWriteBlkMsg(unsigned short seq, int MsgBlockID, int RegAddrCnt, unsigned short regData[], unsigned char data[]);
int decodeWriteBlkMsg(unsigned short seq, unsigned char data[]);

/****************************************/
/*     FPGA Access Support              */
/****************************************/
int makeFPGAReadMsg(unsigned short seq, unsigned int regAddrs, unsigned char data[]);
int decodeFPGAReadResponse(unsigned short seq, unsigned int regAddrs, unsigned char data[], unsigned short* regValue);

int makeFPGAWriteMsg(unsigned short seq, unsigned int regAddrs, unsigned short regValue, unsigned char data[]);
int decodeFPGAWriteResponse(unsigned short seq, unsigned char data[]);

int makeFPGABankReadMsg(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeFPGABankReadResponse(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeFPGABankWriteMsg(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
int decodeFPGABankWriteResponse(unsigned short seq, unsigned char data[]);

int makeFPGAMultipleReadMsg(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[]);
int decodeFPGAMultipleReadResponse(unsigned short seq, unsigned int regAddrs, unsigned char data[] , int *count, int *startIndex);

int makeFPGAMultipleWriteMsg(unsigned short seq, unsigned int regAddrs, int count, unsigned char data[], unsigned short multiData[]);
//int makeMultipleWriteMsg32ForUChar(unsigned short seq, unsigned int regAddrs, int byteCount, unsigned char data[], unsigned char multiData[]);
int decodeFPGAMultipleWriteResponse(unsigned short seq, unsigned char data[]);

int makeFPGAReadFifoMsg(unsigned short seq, unsigned int dataRegAddrs, unsigned int countRegAddrs, int maxRead, unsigned char data[]);
int decodeFPGAReadFifoResponse(unsigned short seq, unsigned int regAddrs, unsigned char data[], int *count, int *left, int *startIndex);

/**********************/
/* Internal Functions */
/**********************/
int selectTimeOut(SOCKET socket, long sec, long usec);
void EmptySocketRX(SOCKET sfd);
int makeTestMsg(unsigned short seq, unsigned int StartAddr, unsigned short WordCount, unsigned short Iterations, unsigned int ErrorAddr, unsigned short TestValue, unsigned char data[]);
int decodeTestResponse(unsigned short seq, unsigned char data[], unsigned short *FailCount, unsigned int *FailAddr1, unsigned int *FailAddr2, unsigned int *FailAddr3);

int NAICloseSocket(SOCKET sfd, BOOL bCleanUp);
int decodeGenericMsg(unsigned char data[]);

#ifdef __cplusplus
}
#endif

#endif

