/**
 *=========================================================================
 *
 * Copyright (c) 2010 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: NAI Ethernet Library
 *
 * FileName: NAIEthernetTCP.h
 *=========================================================================
 **/

#ifndef _NAIETHERNET_TCP_H
#define _NAIETHERNET_TCP_H

#include "NAIEthernet.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************/
/* NAI SLAVE Boards Only TCP Functions  */
/* These APIs use 24-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_ReadReg(SOCKET sfd, unsigned int regAddrs, unsigned short *regValue);
int Ether_WriteReg(SOCKET sfd, unsigned int regAddrs, unsigned short regValue);

int Ether_BankReadReg(SOCKET sfd, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_BankWriteReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_MultipleReadReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteRegForUChar(SOCKET sfd, unsigned int regAddrs, int count, unsigned char multiData[]);

int Ether_ReadFifo(SOCKET sfd, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR_ReadRegWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR_MultiReadRegWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR_ReadFifoWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR_WriteRegWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (Currently available for IPv4 only) */
int Ether_SetPRP_ReadRegWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP_WriteRegWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned short DataToWrite, int nProtocol);

/****************************************/
/* NAI MASTER Boards Only TCP Functions */
/* These APIs use 32-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_ReadReg32(SOCKET sfd, unsigned int regAddrs, unsigned short *regValue);
int Ether_WriteReg32(SOCKET sfd, unsigned int regAddrs, unsigned short regValue);

int Ether_BankReadReg32(SOCKET sfd, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_BankWriteReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_MultipleReadReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg32ForUChar(SOCKET sfd, unsigned int regAddrs, int count, unsigned char multiData[]);

int Ether_ReadFifo32(SOCKET sfd, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR_ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR_MultiReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR_ReadFifo32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR_WriteReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (Currently available for IPv4 only) */
int Ether_SetPRP_ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP_WriteReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned short DataToWrite, int nProtocol);
int Ether_SetPRP_ReadBlockWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, int nProtocol);
int Ether_SetPRP_WriteBlockWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], int nProtocol);

/****************************************/
/* NAI GENERATION 3 TCP Functions       */
/* These APIs use 32-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_Bank3ReadReg32(SOCKET sfd, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_Bank3WriteReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_Multiple3ReadReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_Multiple3WriteReg32(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR3_ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR3_Bank3ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_Multi3ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_ReadFifo32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR3_WriteReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

#ifndef _WITH_IPV4_SUPPORT_ONLY
/* Interrupt Driven Response Functions - (for IPv6) */
int Ether_SetIDR3_IPv6_ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR3_IPv6_Multi3ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_IPv6_Bank3ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_IPv6_ReadFifo32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR3_IPv6_WriteReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (for IPv6) */
int Ether_SetPRP3_IPv6_ReadReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP3_IPv6_WriteReg32WithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned short DataToWrite, int nProtocol);
int Ether_SetPRP3_IPv6_ReadBlockWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, int nProtocol);
int Ether_SetPRP3_IPv6_WriteBlockWithProtocol(SOCKET sfd, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], int nProtocol);
#endif

/*********************************************/
/* NAI MASTER and SLAVE Boards TCP Functions */
/*********************************************/
/* Log In and Log Out Functions */
int Ether_LogIn( unsigned char* szIP, int nPort, SOCKET* sfd);
int Ether_LogOut(SOCKET sfd);

/* No Operation Function */
int Ether_SendNOP(SOCKET sfd);

/******   Ethernet Unprompted Responses (UPR) Functions for Interrupt Driven Responses and Periodic Responses   ******/
int Ether_SetupUPR(SOCKET* sockUPR, struct nai_sockaddr_storage* UPRServerAddr, unsigned char* ip, int port);
int Ether_ReadUPR(SOCKET sockUPR, unsigned short UPRData[], int WordCount, int *WordsReceived);
int Ether_ReadUPRForUChar(SOCKET sockUPR, unsigned char UPRData[], int ByteCount, int *BytesReceived);

/******   Ethernet Functions for Interrupt Driven Responses (IDR)   ******/
int Ether_DirectInterrupts(SOCKET sfd, int direction);
int Ether_QueryDirectInterrupts(SOCKET sfd, int *direction);

/* Message Blocks Functions */
int Ether_SendMsgBlockCfgPayload(SOCKET sfd, int MsgBlockID, int BlockID, int RegAddrCnt, unsigned int regAddrData[]);
int Ether_ReadMsgBlock(SOCKET sfd, int MsgBlockID, int* RegAddrCnt, unsigned short regValueData[]);
int Ether_WriteMsgBlock(SOCKET sfd, int MsgBlockID, int RegAddrCnt, unsigned short regValueData[]);

/* Miscellaneous functions */
BOOL Ether_GetBusy_TCP(void);
void Ether_ResetBusy_TCP(void);
void Ether_WaitOnBusy(BOOL bWaitOnBusy) ;

/****************************************/
/*     FPGA Access Support              */
/****************************************/
int Ether_FPGA_ReadReg(SOCKET sfd, unsigned int regAddrs, unsigned short *regValue);
int Ether_FPGA_WriteReg(SOCKET sfd, unsigned int regAddrs, unsigned short regValue);

int Ether_FPGA_BankReadReg(SOCKET sfd, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_FPGA_BankWriteReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_FPGA_MultipleReadReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_FPGA_MultipleWriteReg(SOCKET sfd, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_FPGA_ReadFifo(SOCKET sfd, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/************************************/
/*     Internal TCP functions       */
/************************************/
int CreateClientSocket(unsigned char* szIP, int nPort, SOCKET* sfd);
int CloseClientSocket(SOCKET sfd);
#ifndef _WITH_IPV4_SUPPORT_ONLY
int CreateServerSocket( unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_storage* UDPServerAddr);
#else
int CreateServerSocket( unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_in* UDPServerAddr);
#endif
int CloseServerSocket(SOCKET sfd);

int SendEthernetMsg(SOCKET sfd, unsigned char *pszMessage, int nMessageLen);
int ReadEthernetMsg(SOCKET sfd, int nMessageLenToBeRead, unsigned char *pszMessage, int *nMessageLen);
int Ether_TestModBusVmeIO(SOCKET sfd, unsigned int StartAddr, unsigned short WordCount, unsigned short Iterations, unsigned int ErrorAddr, unsigned short TestValue, unsigned short *FailCount, unsigned int *FailAddr1, unsigned int *FailAddr2, unsigned int *FailAddr3);
int Ether_SendGenericCommandMsg(SOCKET sfd, int nCmdLen, unsigned char ucCmdData[],unsigned char szMessage[], int * pnMsgLength);

#ifdef __cplusplus
}
#endif

#endif

