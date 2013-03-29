/**
 *=========================================================================
 *
 * Copyright (c) 2010 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: NAI Ethernet Library
 *
 * FileName: NAIEthernetUDP.h
 *=========================================================================
 **/

#ifndef _NAIETHERNET_UDP_H
#define _NAIETHERNET_UDP_H

#include "NAIEthernet.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************/
/* NAI SLAVE Boards Only UDP Functions  */
/* These APIs use 24-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_ReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short *regValue);
int Ether_WriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short regValue);

int Ether_BankReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_BankWriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_MultipleReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteRegForUChar_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned char multiData[]);

int Ether_ReadFifoUDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR_ReadRegUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR_MultiReadRegUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR_ReadFifoUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR_WriteRegUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (Currently available for IPv4 only) */
int Ether_SetPRP_ReadRegUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP_WriteRegUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/****************************************/
/* NAI MASTER Boards Only UDP Functions */
/* These APIs use 32-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_ReadReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short *regValue);
int Ether_WriteReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short regValue);

int Ether_BankReadReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_BankWriteReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_MultipleReadReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg32_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_MultipleWriteReg32ForUChar_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned char multiData[]);

int Ether_ReadFifo32UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR_ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR_MultiReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR_ReadFifo32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR_WriteReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (Currently available for IPv4 only) */
int Ether_SetPRP_ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP_WriteReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);
int Ether_SetPRP_ReadBlockUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* myIpAddr, int myPort, int slot, int TimePeriod, unsigned char RegBlock, int nProtocol);
int Ether_SetPRP_WriteBlockUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], int nProtocol);

/****************************************/
/* NAI GENERATION 3 UDP Functions       */
/* These APIs use 32-bit addressing     */
/****************************************/
/* Register Read/Write Functions */
int Ether_Bank3ReadReg32UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_Bank3WriteReg32UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_Multiple3ReadReg32UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_Multiple3WriteReg32UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

/* Interrupt Driven Response Functions - (Currently available for IPv4 only) */
int Ether_SetIDR3_ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR3_Bank3ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_Multi3ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_ReadFifo32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR3_WriteReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

#ifndef _WITH_IPV4_SUPPORT_ONLY
/* Interrupt Driven Response Functions - (for IPv6) */
int Ether_SetIDR3_IPv6_ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, int nProtocol);
int Ether_SetIDR3_IPv6_Multi3ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_IPv6_Bank3ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned short usNumReads, int nProtocol);
int Ether_SetIDR3_IPv6_ReadFifo32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int myPort, int slot, int IntIndx, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int nProtocol);
int Ether_SetIDR3_IPv6_WriteReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int IntIndx, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);

/* Periodic Response Functions - (for IPv6) */
int Ether_SetPRP3_IPv6_ReadReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int myPort, int slot, int TimePeriod, unsigned int RegAddr, int nProtocol);
int Ether_SetPRP3_IPv6_WriteReg32UDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int TimePeriod, unsigned int RegAddr, unsigned int DataToWrite, int nProtocol);
int Ether_SetPRP3_IPv6_ReadBlockUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int myPort, int slot, int TimePeriod, unsigned char RegBlock, int nProtocol);
int Ether_SetPRP3_IPv6_WriteBlockUDPWithProtocol(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char* ip, int port, int slot, int TimePeriod, unsigned char RegBlock, unsigned short BlockSize, unsigned short multiData[], int nProtocol);
#endif

/*********************************************/
/* NAI MASTER and SLAVE Boards UDP Functions */
/*********************************************/
/* Log In and Log Out Functions */
int Ether_LogIn_UDP(unsigned char* szIP, int nPort, SOCKET* sfd, struct nai_sockaddr_storage* UDPServerAddr);
int Ether_LogOut_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr);

/* No Operation Function */
int Ether_SendNOP_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr);

/******   Ethernet Unprompted Responses (UPR) Functions for Interrupt Driven Responses and Periodic Responses   ******/
int Ether_SetupUPR_UDP(SOCKET* sockUPR, struct nai_sockaddr_storage* UPRServerAddr, unsigned char* myIpAddr, int myPort);
int Ether_ReadUPR_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned short UPRData[], int WordCount, int *WordsReceived);
int Ether_ReadUPR_UDPForUChar(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char UPRData[], int ByteCount, int *BytesReceived);

/******   Ethernet Functions for Interrupt Driven Responses (IDR)   ******/
int Ether_DirectInterruptsUDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int direction);
int Ether_QueryDirectInterruptsUDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int *direction);

/* Message Blocks Functions */
int Ether_SendMsgBlockCfgPayload_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int MsgBlockID, int BlockID, int RegAddrCnt, unsigned int regAddrData[]);
int Ether_ReadMsgBlock_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int MsgBlockID, int* RegAddrCnt, unsigned short regValueData[]);
int Ether_WriteMsgBlock_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int MsgBlockID, int RegAddrCnt, unsigned short regValueData[]);

/* Miscellaneous functions */
BOOL Ether_GetBusy_UDP(void);
void Ether_ResetBusy_UDP(void);
void Ether_WaitOnBusy_UDP(BOOL bWaitOnBusy) ;

/****************************************/
/*     FPGA Access Support              */
/****************************************/
int Ether_FPGA_ReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short *regValue);
int Ether_FPGA_WriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, unsigned short regValue);

int Ether_FPGA_BankReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count_requested, int *count_received, unsigned short multiData[]);
int Ether_FPGA_BankWriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_FPGA_MultipleReadReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);
int Ether_FPGA_MultipleWriteReg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int regAddrs, int count, unsigned short multiData[]);

int Ether_FPGA_ReadFifoUDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, int *count_received, int *count_left, unsigned short multiData[]);

/************************************/
/*     Internal UDP functions       */
/************************************/
int Ether_PeekWordsInRecvBuf_UDP(SOCKET sockUPR, int *WordsReceived);

#ifndef _WITH_IPV4_SUPPORT_ONLY
int CreateClientSocket_UDP(unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_storage* UDPServerAddr);
#else
int CreateClientSocket_UDP(unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_in* UDPServerAddr);
#endif
int CloseClientSocket_UDP(SOCKET sfd);
#ifndef _WITH_IPV4_SUPPORT_ONLY
int CreateServerSocket_UDP(unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_storage* UDPServerAddr);
#else
int CreateServerSocket_UDP(unsigned char *szIP, int nPort, SOCKET* sfd, struct sockaddr_in* UDPServerAddr);
#endif
int CloseServerSocket_UDP(SOCKET sfd);

int SendEthernetMsg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned char *pszMessage, int nMessageLen);
int ReadEthernetMsg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int nMessageLenToBeRead, unsigned char *pszMessage, int *nMessageLen);
void Ether_ResetBusy_UDP(void);
int Ether_TestModBusVmeIO_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, unsigned int StartAddr, unsigned short WordCount, unsigned short Iterations, unsigned int ErrorAddr, unsigned short TestValue, unsigned short *FailCount, unsigned int *FailAddr1, unsigned int *FailAddr2, unsigned int *FailAddr3);

int Ether_SendGenericCommandMsg_UDP(SOCKET sfd, struct nai_sockaddr_storage ServerAddr, int nCmdLen, unsigned char ucCmdData[], unsigned char szMessage[], int * pnMsgLength);

#ifndef _WITH_IPV4_SUPPORT_ONLY
/*
   Windows does not have an implementation for inet_pton.
   This routine will provide this ability for support of IPv6.
*/
int nai_inet_pton_for_Windows(int af, char *src, struct in6_addr *dst);
#endif

#ifdef __cplusplus
}
#endif

#endif

