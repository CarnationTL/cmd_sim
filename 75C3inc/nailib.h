/*++
  Copyright (c) 2012 North Atlantic Industries, Inc.  All Rights Reserved.

File Name:
  nailib.h

Abstract:
  Generic interface library header file for the
  North Atlantic Industries device driver.

Revision History:
  Created October 8, 1999
  9/28/2012		MEL	Added Ethernet Type Codes for FPGA access
--*/

#ifndef _NAILIB_H
#define _NAILIB_H

/*********************************************************
*             INCLUDE DECLARATIONS
**********************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#include "nailib_BuildOption.h"
#ifdef NAI_VISA /* NI LabView only */
#define NIVISA_PXI
#include "visa.h"
#endif

#ifdef NAI_VXWORKS
 #include "nai_vxWorks.h"
#endif

#ifdef WIN32
/* Suppress "warning C4201: nonstandard extension used : nameless struct/union" */
#pragma warning(disable : 4201)
/* Suppress "warning C4127: conditional expression is constant" for FD_SET and while(FALSE) */
#pragma warning(disable : 4127)
/* Suppress "warning C4706: assignment within conditional expression" in the wspiapi.h file */
#pragma warning(disable : 4706)
/*warning C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. */
#pragma warning(disable : 4996)

#ifndef XPCTARGET
#ifndef NAI_LVRT
#include <winsock2.h>
#endif
#endif

#include <windows.h>
#include <winioctl.h>
#include <Winnt.h>

#ifndef NAI_LVRT
#include <initguid.h>
#include <setupapi.h>
#include <ws2tcpip.h>
#endif

#endif

#if defined(LINUX) || defined(LYNX)
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <errno.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/select.h>
#endif

#ifdef LYNX
#include <ioctl.h>
#endif

#ifdef NAI_VISA /* NI LabView only */
#define NIVISA_PXI
#include "visa.h"
#include "toolbox.h"
#include <windows.h>
#include <winioctl.h>
#endif

#ifdef XPCTARGET
#include "rtwtypes.h"
#endif

/*********************************************************
*             EXPORT DECLARATIONS
**********************************************************/
#ifdef WIN32 /* Windows platform */
#define NAIAPI __stdcall
   #ifdef __NAIDLL32__
   /* Compiling DLL from source. */
      #define NAIBASEAPI __declspec(dllexport)
   #elif __NAIIMP32__
   /* Importing from a DLL. */
      #define NAIBASEAPI __declspec(dllimport)
   #else
   /* Default is link statically. */
      #define NAIBASEAPI
   #endif
#else /* Linux, Lynx platforms */
   #define NAIBASEAPI
#endif

/*********************************************************
*             TYPE DECLARATIONS
**********************************************************/
#if defined(LINUX) || defined(LYNX) || defined(XPCTARGET)
#define UINT   unsigned int
#define BOOL   unsigned char
#define VOID   void
#define PVOID  void*
#define LPVOID void*
#define HANDLE LPVOID
#define FDTOHANDLE(fd) ((HANDLE)(long)(fd))
#define HANDLETOFD(h) ((int)(long)(h))
#define USHORT unsigned short
#define UCHAR  unsigned char
#define ULONG  unsigned int
#define LONG   int
#define DWORD  unsigned int
#define CHAR   char
#define INVALID_HANDLE_VALUE (HANDLE)-1
#define __stdcall
#define __cdecl
#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR   -1
/* #define SOCKADDR_IN struct sockaddr_in */
#define NAIAPI
#define WINAPI
#else
 #ifdef NAI_VISA
  #define SOCKET int
  #define BOOL int
 #endif
#endif

/*********************************************************
*             CONSTANT DECLARATIONS
**********************************************************/
#define NAI_DEVICE_NUMBER_MAX	99
#define NAI_PCI_VID 		0x15AC
#define NAI_MAX_NUM_CARDS  	20

typedef enum {
 NAI_PHY_BUS         = 0,  /* It can be PCI, cPCI, PC104+, ISA, PC104, VME, ... */
 VME_BIT3_WINDOWS    = 1,
 VME_LYNX            = 2,
 VME_LINUX           = 3,
 VME_VXWORKS         = 4,
 VME_VXWORKS_RTP     = 5,
 VME_SBC_WINDOWS     = 6,  /* For SBC running Windows, with UniverseII or Tsi148 chip */
 VME_USB_WIENER      = 7,
 PCI_VXWORKS         = 8,
 PCI_WINDOWS         = 9,
 ETHER_TCP_24_ADR    = 10, /* Ethernet Communication with TCP/IP Protocol 24 Bit Address (Slave) */
 ETHER_TCP_32_ADR    = 11, /* Ethernet Communication with TCP/IP Protocol 32 Bit Address (Master) */
 ETHER_UDP_24_ADR    = 12, /* Ethernet Communication with UDP Protocol 24 Bit Address (Slave) */
 ETHER_UDP_32_ADR    = 13, /* Ethernet Communication with UDP Protocol 32 Bit Address (Master) */
 PCI_XPCTARGET       = 14,  /* Matlab xPC Target */
 VPX_LINUX      	 = 15,
 VPX_LYNX	     	 = 16
 } INTERFACE_MODE;

typedef enum {
   IDR_TCP = 1,   /* TCP/IP Protocol */
   IDR_UDP = 2    /* UDP Protocol */
} IDR_InterfaceProtocol_e;

typedef enum {
   NAI_SLAVE_MODE = 0,                /* Set to Slave Mode  */
   NAI_MASTER_MODE_JUMPER_VERIFY = 1, /* Set to Master Mode (confirm with Jumper setting) */
   NAI_MASTER_MODE = 2                /* Set to Master Mode */
} MasterSlaveMode_e;

#define ISA_WINDOWS NAI_PHY_BUS

#define VMECOM_BIT3     ETHER_TCP_32_ADR
#define VMECOM_ETHERNET ETHER_UDP_32_ADR

/* Module Types */
#define NO_MODULE            0
#define AD_MODULE            1
#define DA_MODULE            2
#define RTD_MODULE           3
#define DT_MODULE            4
#define TTL_MODULE           5
#define SD_MODULE            6
#define DS_MODULE            7
#define LD_MODULE            8
#define DL_MODULE            9
#define SIG_MODULE           10
#define DIF_MODULE           11
#define MUL_MODULE           12
#define SCF_MODULE           13
#define M1553_MODULE         14
#define REF_MODULE           15
#define LVDT_MODULE          16
#define PROC_MODULE          17
#define CBY2_MODULE          18   /* Combo Module with 4 ch AD, 12 chan output only DT, 4 Chan Input/Output DT, 12 chan Input only DT. */
#define KA_MODULE            19   /*KA_DT of KA module*/
#define KA_AD_MODULE         20   /*KA_AD of KA module*/
#define SER_MODULE           21
#define PRF_MODULE           22
#define AR_MODULE            23
#define VME64PW2_MODULE      24
#define DSW_MODULE           25
#define CAN_MODULE           26
#define ENC_MODULE           27
#define USB_MODULE           28
#define PS_MODULE            29
#define VME64PW3_MODULE      30
#define SG_MODULE            31
#define MC_MODULE            32
#define SER_DT_MODULE        33   /* PD, KB modules*/
#define PROFIBUS_MODULE      34   /* M1 */
#define ESW_MODULE           35
#define KA_MODULE_16         36
#define RLY_MODULE           37

/* NAI Ethernet Type Codes */
#define TYPECODE_REGr                        0x10
#define TYPECODE_REGw                        0x90
#define TYPECODE_BANKr                       0x11
#define TYPECODE_BANKw                       0x91
#define TYPECODE_MREGr                       0x12
#define TYPECODE_MREGw                       0x92
#define TYPECODE_FIFOr                       0x17
#define TYPECODE_PRP                         0x20
#define TYPECODE_IDR                         0x23
#define TYPECODE_REGr32                      0x13
#define TYPECODE_REGw32                      0x93
#define TYPECODE_BANKr32                     0x14
#define TYPECODE_BANKw32                     0x94
#define TYPECODE_MREGr32                     0x15
#define TYPECODE_MREGw32                     0x95
#define TYPECODE_IDR3                        0x26
#define TYPECODE_BANK3r32                    0x19
#define TYPECODE_BANK3w32                    0x99
#define TYPECODE_MREG3r32                    0x1A
#define TYPECODE_MREG3w32                    0x9A
#define TYPECODE_FIFO3r32                    0x1B
#define TYPECODE_IDR3_IPv6                   0x27
#define TYPECODE_PRP3_IPv6                   0x21

#define TYPECODE_FIFOr32                     0x99
#define TYPECODE_PRP32                       0x9A
#define TYPECODE_IDR32                       0x9B

#define TYPECODE_NOP                         0x00
#define TYPECODE_LOG                         0x01
#define TYPECODE_ERR                         0x02
#define TYPECODE_DIR                         0x24
#define TYPECODE_QID                         0x25
#define TYPECODE_CFGBLK                      0x31
#define TYPECODE_BLKr                        0x18
#define TYPECODE_BLKw                        0x98

#define TYPECODE_FPGA_REGr                   0x40
#define TYPECODE_FPGA_REGw                   0x50
#define TYPECODE_FPGA_BANKr                  0x41
#define TYPECODE_FPGA_BANKw                  0x51
#define TYPECODE_FPGA_MREGr                  0x42
#define TYPECODE_FPGA_MREGw                  0x52
#define TYPECODE_FPGA_FIFOr                  0x47

/* TYPECODE_TST - Internal use ONLY */
#define TYPECODE_TST                         0x03

#define ERR_DISCONNECT_PORT                  0x80

/* Number of bytes for Ethernet Message Framework:
   Preamble(2 bytes) + Seq Number(2 bytes) + Type Code(1 byte) + Size(2 bytes) + Post-amble(2 bytes)
*/
#define NAI_GEN2_PREPAYLOAD_MSG_LEN          7
#define NAI_GEN2_POSTAMBLE_MSG_LEN           2
#define ETHER_MSG_FRAMEWORK_SIZE             NAI_GEN2_PREPAYLOAD_MSG_LEN + NAI_GEN2_POSTAMBLE_MSG_LEN

/* Number of bytes expected to be returned */
#define REGREAD_RESPONSE_SIZE                14
#define REGWRITE_RESPONSE_SIZE               9
#define REG_BANKREAD_RESPONSE_BASE_SIZE      14
#define REG_BANKWRITE_RESPONSE_SIZE          9		/* changed from 14 to 9 08-08-29 JED */
#define REG_MULTIREAD_RESPONSE_BASE_SIZE     14
#define REG_MULTIWRITE_RESPONSE_SIZE         14		/* left at 14 (should be 9 like 64D2, but 64CS4 sends 14) */

#define REGREAD32_RESPONSE_SIZE              15
#define REG_BANKREAD32_RESPONSE_BASE_SIZE    16
#define REG_MULTIREAD32_RESPONSE_BASE_SIZE   16

#define LOGIN_RESPONSE_SIZE                  9
#define LOGOUT_RESPONSE_SIZE                 10
#define NOP_RESPONSE_SIZE                    9
#define SET_IDR_RESPONSE_SIZE					   10     /* changed from 10 to 9, now back to 10 08-11-14 JED */
#define DIRECT_INTERRUPTS_RESPONSE_SIZE      10
#define SET_PRP_RESPONSE_SIZE					   9
#define CLGBLK_RESPONSE_SIZE                 9
#define BLKMSGWRITE_RESPONSE_SIZE            9

/* Generation 3 Ethernet Messages */
#define REG_BANK3READ32_RESPONSE_BASE_SIZE      18
#define REG_BANK3WRITE32_RESPONSE_SIZE          12
#define REG_MULTI3READ32_RESPONSE_BASE_SIZE     18
#define REG_MULTI3WRITE32_RESPONSE_SIZE         12
#define SET_IDR3_RESPONSE_SIZE                  11
#define SET_PRP3_RESPONSE_SIZE					   10

/* TEST_RESPONSE_SIZE - Internal use ONLY */
#define TEST_RESPONSE_SIZE                   23

/* Max message size for Ethernet payloads */
#define MSG_MAX_SIZE_BYTES   1500	      /* max 1500 bytes */
#define MSG_MAX_SIZE_WORDS   750	         /* max 750 words */

#define MAX_MSG_BLOCK_ID     25
#define MAX_REGADDR_FOR_CFG  350
#define MAX_MSG_REGADDR_CNT  700

#define MSG_SIZE             1500    /*16384 */
#define MAX_MULTI_RDWR_CNT   4000    /*32761;   restricted by response message size */

#define ETHENET_BASE_STAT    200
#define MSG_OVERHEAD_SIZE    9

typedef enum {
 NAIETHER_SUCCESS                      = 0,
 NAIETHER_START_ENUM                   = 1000,
 NAIETHER_INVALID_CARD                 = 1001,
 NAIETHER_INVALID_ETHER_PROTOCOL       = 1002,
 NAIETHER_INVALID_TCP_PORT             = 1003,
 NAIETHER_INVALID_UDP_PORT             = 1004,
 NAIETHER_INVALID_PREAMBLE             = 1005,
 NAIETHER_INVALID_SEQ                  = 1006,
 NAIETHER_INVALID_TYPECODE             = 1007,
 NAIETHER_INVALID_SIZE                 = 1008,
 NAIETHER_INVALID_EVENTCODE            = 1009,
 NAIETHER_INVALID_ADDRS                = 1010,
 NAIETHER_INVALID_POSTAMBLE            = 1011,
 NAIETHER_CANNOT_ESTABLISH_CONNECTION  = 1012,
 NAIETHER_SEND_ERROR                   = 1013,
 NAIETHER_RECV_ERROR                   = 1014,
 NAIETHER_TIMEOUT                      = 1015,
 NAIETHER_ETHER_ERROR                  = 1016,
 NAIETHER_INVALID_MSGBLOCKID           = 1017,
 NAIETHER_INVALID_REGADDRCNT           = 1018,
 NAIETHER_FILE_ERROR                   = 1019,
 NAIETHER_FILE_READ_FORMAT_ERROR       = 1020,
 NAIETHER_BUSY_SENDING_PREV_MSG        = 1021,
 NAIETHER_VME_BUSS_ERR                 = 1022,
 NAIETHER_VME_TIMEOUT_ERR              = 1023,
 NAIETHER_UNKNOWN                      = 1024,
 NAIETHER_INVALID_INTERFACEMODE        = 1025,
 NAIETHER_LAST                         = 1026
} NAIETHER_STATUS;

/*
 * These ASCII strings are useful for debugging but can take up
 * a lot of data space. They are optionally compiled in by way
 * of the macro shown.
 */
#define NAIETHER_STRINGS {\
 "NAIETHER_SUCCESS",\
 "NAIETHER_INVALID_CARD",\
 "NAIETHER_INVALID_ETHER_PROTOCOL",\
 "NAIETHER_INVALID_TCP_PORT",\
 "NAIETHER_INVALID_UDP_PORT",\
 "NAIETHER_INVALID_PREAMBLE",\
 "NAIETHER_INVALID_SEQ",\
 "NAIETHER_INVALID_TYPECODE",\
 "NAIETHER_INVALID_SIZE",\
 "NAIETHER_INVALID_EVENTCODE",\
 "NAIETHER_INVALID_ADDRS",\
 "NAIETHER_INVALID_POSTAMBLE",\
 "NAIETHER_CANNOT_ESTABLISH_CONNECTION",\
 "NAIETHER_SEND_ERROR",\
 "NAIETHER_RECV_ERROR",\
 "NAIETHER_TIMEOUT",\
 "NAIETHER_ETHER_ERROR",\
 "NAIETHER_INVALID_MSGBLOCKID",\
 "NAIETHER_INVALID_REGADDRCNT",\
 "NAIETHER_FILE_ERROR",\
 "NAIETHER_FILE_READ_FORMAT_ERROR",\
 "NAIETHER_BUSY_SENDING_PREV_MSG",\
 "NAIETHER_VME_BUSS_ERR",\
 "NAIETHER_VME_TIMEOUT_ERR",\
 "NAIETHER_UNKNOWN",\
 "NAIETHER_INVALID_INTERFACEMODE",\
 "NAIETHER_LAST"\
}

/*
  This object is allocated in each call to NaOpenDevice.
  It contains all the state information so the library
  can be multi-threaded  and work readily with
  multiple cards.
*/
#define NAI_DEVICE_CONTEXT_OBJ 0xFFFFFFFF

#if defined(LINUX) || defined(LYNX)
#define TRUE   1
#define FALSE  0
#ifdef LYNX_SE_DYNAMIC
#define NAI_DEVICE_NAME_TEMPLATE "/tmp/nai??"
#endif
#ifdef LINUX_ISA
#define NAI_DEVICE_NAME_TEMPLATE "/dev/naiisa?"
#define NAI_DEVICE_NUMBER_POSITION 11
#elif defined(LINUX_VME)
#define NAI_DEVICE_NAME_TEMPLATE "/dev/naivme?"
#define NAI_DEVICE_NUMBER_POSITION 11
#else
#define NAI_DEVICE_NAME_TEMPLATE "/dev/nai??"
#define NAI_DEVICE_NUMBER_POSITION 8
#endif
#endif

#ifdef WIN32
   #if defined(NAI_APEX)
      #define NAI_DEVICE_NAME_TEMPLATE "\\\\.\\ApexDev??"
      #define NAI_DEVICE_NUMBER_POSITION 11
   #elif defined(NAI_NAI)
      #define NAI_DEVICE_NAME_TEMPLATE "\\\\.\\NaiDev??"
      #define NAI_DEVICE_NUMBER_POSITION 10
   #else
      #define NAI_DEVICE_NAME_TEMPLATE "\\\\.\\NapxDev??"
      #define NAI_DEVICE_NUMBER_POSITION 11
   #endif
#endif

#ifdef NAI_VISA
#define MAX_DESCRIPTOR_SIZE 512
#endif

/* Count parameter of NaReadReg and NaWriteReg. */
#define NAI_BYTE 1
#define NAI_WORD 2

/* If NaReadReg encounters a problem, it returns this data. */
#define NAI_BAD_DATA 0xffff

#define NAISTATUS unsigned long

#if defined(LYNX)
#define NAI_SUCCESS                        000000000
#else
#define NAI_SUCCESS                        00000000l
#endif

#define NAI_CONFLICT                       00000001l
#define NAI_ERROR_BAD_HANDLE               00000002l
#define NAI_ERROR_IOCTL                    00000003l
#define NAI_ERROR_EVENT                    00000004l
#define NAI_ERROR_DEVICE_NUMBER            00000005l
#define NAI_ERROR_OPENING_DEVICE           00000006l

/*********************************************************
*             EXTERNAL AND MACRO DECLARATIONS
**********************************************************/
/* App uses nai_sleep x seconds  */
#if defined(LINUX) || defined(LYNX)
#define nai_sleep(x)	sleep(x)
#elif defined(WIN32)
#define nai_sleep(x)	Sleep(1000*x)
#define usleep(x)       Sleep(x)
#endif

/* nai mili-second delay */
#if defined(LINUX) || defined(LYNX)
#define nai_msDelay(x)	usleep(1000*x)
#elif defined(WIN32)
#define nai_msDelay(x)	Sleep(x)
#endif

/*********************************************************
*             STRUCTURE DECLARATIONS
**********************************************************/
typedef struct {

  UINT   ObjectType;
  UINT   DeviceNumber;
  UINT   dwThreadId;
  BOOL   bTrigOpened;
  BOOL   bThreadAlive;
  HANDLE hDevIn;
  HANDLE hDevOut;
  HANDLE hDevTrig;
  HANDLE hEvent;
  HANDLE hThread;

  VOID(*pIntRoutine)(HANDLE,USHORT);

} NAI_DEVICE_CONTEXT, *PNAI_DEVICE_CONTEXT;

/*
  This must be kept up to date with NAI_DEVICE_CONFIG
  in naioctl.h. We include it here so a program does not
  have to include this additional file.
*/

typedef struct _NAI_CONFIG {
   ULONG BaseAdr;
   ULONG PortCount;
   UCHAR IrqLine;
   UCHAR Status;
   ULONG bPCIDevice;
   ULONG BusNum;
   ULONG DeviceId;
} NAI_CONFIG, *PNAI_CONFIG;

/* _NAI_CONFIG_EX has been added to include Device, Function and Slot
   information.  For legacy system (like Napx View), we need to still support the original
   _NAI_CONFIG structure.
*/
typedef struct _NAI_CONFIG_EX {

   ULONG BaseAdr;
   ULONG PortCount;
   UCHAR IrqLine;
   UCHAR Status;
   ULONG bPCIDevice;
   ULONG BusNum;
   ULONG DeviceId;

  /* Additional fields for Device, Function, and Slot Information */
  ULONG DeviceNum;
  ULONG FunctionNum;
  ULONG SlotNum;

} NAI_CONFIG_EX, *PNAI_CONFIG_EX;

/* This structure was initially for Linux PCI devices */
typedef struct _NAI_DEV_CFG {

   ULONG nCard;            /* NAI card index */
   ULONG nVid;		   	   /* PCI Vendor ID 0x15AC */
   ULONG nDid;             /* PCI Device ID */
   ULONG nBusNo;           /* PCI Bus number */
   ULONG nDevNo;           /* PCI Device number */
   ULONG nFuncNo;          /* PCI Function number */
   ULONG nChassis;         /* Labview RT NI PXI chassis */
   ULONG nSlot;            /* Labview RT NI PXI slot */
   ULONG nIndex;           /* same nDid, instance */
   ULONG nBAR0;            /* Base Address Register 0 */
   USHORT nIrqLevel;       /* Interrupt level */
} NAI_DEV_CFG, *PNAI_DEV_CFG;

/*********************************************************
*        FUNCTION DECLARATIONS FOR ALL OS PLATFORMS
**********************************************************/
NAIBASEAPI
void
NAIAPI
InitNAIPci(void);

NAIBASEAPI
int
NAIAPI
GetNAIPciCnt(void);

NAIBASEAPI
int
NAIAPI
GetNAIPciDevID(int nCardIndex);

NAIBASEAPI
int
NAIAPI
GetNAIPciBusNo(int nCardIndex);

NAIBASEAPI
int
NAIAPI
GetNAIPciDevNo(int nCardIndex);

NAIBASEAPI
int
NAIAPI
GetNAIPciFunctionNo(int nCardIndex);

/* DANT MOVED HERE FROM VISA SPECIFIC */
NAIBASEAPI
int
NAIAPI
NaiGetCardbyBusDev(unsigned int busnum, unsigned int devnum);
/*END DANT */

/* DANT ADDED */
NAIBASEAPI
int
NAIAPI
NaiInit(unsigned int deviceID);

NAIBASEAPI
int
NAIAPI
NaiInit_Ex(int nDeviceIDCnt, unsigned int aDeviceID[]);

NAIBASEAPI
int
NAIAPI
NaiGetCardbyDevIdBusDev(unsigned int deviceID, unsigned int busnum, unsigned int devnum);

NAIBASEAPI
void
NAIAPI
NaiGetBusDevInfo(int nCardIndex, int *pDevID, int *pSlotNum, int *pBusNum, int *pDevNum,
				 int *pFuncNum, int *pBaseAddr);

NAIBASEAPI
void
NAIAPI
NaiAddDevice(NAI_DEV_CFG* pNewDeviceConfig);

NAIBASEAPI
void
NAIAPI
NaiSortDevices(void);
/*END DANT */

NAIBASEAPI
HANDLE
NAIAPI
NaiOpenDevice(
  UINT DeviceNumber
  );

NAIBASEAPI
HANDLE
NAIAPI
NaiOpenDevice_Ex(
  UINT DeviceNumber,
  unsigned long * pulDutBase
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiCloseHandle(
   HANDLE hDevice
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiProbeDevice(
   UINT DeviceNumber,
   PNAI_CONFIG pConfig
  );

NAIBASEAPI
USHORT
NAIAPI
NaiReadReg(
  HANDLE hDevice,
  UINT Offset,
  UINT Count
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiWriteReg(
  HANDLE hDevice,
  UINT Offset,
  USHORT Data,
  UINT Count
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiReadPciInfo(
   UINT DeviceNumber,
   PNAI_CONFIG_EX pConfig
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiOpenTrigger(
  HANDLE hDevice
  );

NAIBASEAPI
USHORT
NAIAPI
NaiIntTrigger(
  HANDLE hDevice
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiIntConfigure(
               HANDLE hDevice,
               UINT ReadAddr,
               UINT WriteAddr,
               USHORT WriteValue
               );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiHookInterrupt(
  HANDLE hDevice,
  VOID(*pIntRoutine)(HANDLE hDevice,USHORT IntStatus)
  );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiHookInterruptEx(
  HANDLE hDevice,
  VOID(*pIntRoutine)(HANDLE DeviceNumber,USHORT IntStatus)
  );

/* GE Fanuc VR11/VP11 SBC running Windows */
#ifdef VME_GEF_WINDOWS
#include "gefcmn_vme.h"
#include "gefcmn_errno.h"
/* clean up warnings */
#pragma warning(disable : 4702)
#pragma warning(disable : 4996)

NAISTATUS NaiGefHookInterruptEx(HANDLE hDevice, int nLevel, int nVector, void(*pMyIsr)(GEF_CALLBACK_HDL int_hdl, GEF_VME_INT_INFO int_info, void *Arg) );
NAISTATUS NaiGefRemoveInterruptEx(HANDLE hDevice);
#endif

/*********************************************************
*         FUNCTION DECLARATIONS FOR
*         LINUX, LYNX PLATFORMS
**********************************************************/
#if defined(LINUX) || defined(LYNX)
void *NaiIntHookThread(
  LPVOID lpdwParam
  );

void *NaiIntHookThreadEx(
  LPVOID lpdwParam
  );
#elif defined(WIN32)
DWORD
WINAPI
NaiIntHookThread(
  LPVOID lpdwParam
  );

DWORD
WINAPI
NaiIntHookThreadEx(
  LPVOID lpdwParam
  );

BOOL
GetPnPDeviceName (
        GUID guid,
        UINT deviceNumber,
        PCHAR* deviceName
      ) ;

#endif

#ifdef LINUX
int GetTickCount(void);
#endif

/*********************************************************
*             FUNCTIONS FOR NI LABVIEW ONLY
**********************************************************/
#ifdef NAI_VISA
NAIBASEAPI
NAISTATUS
NAIAPI
NaiViEnableEvent( HANDLE hDevice );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiViDisableEvent(HANDLE hDevice );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiTranslateVISAErrorCode( ViStatus status );

NAIBASEAPI
NAISTATUS
NAIAPI
NaiSenseInterrupt(HANDLE hDevice, unsigned int timeoutValue, unsigned short *timedOut);

NAIBASEAPI
NAISTATUS
NAIAPI
NaiVisaInit(unsigned int deviceID);

NAIBASEAPI 
int
NAIAPI
NaiGetCardbyChassisSlot(unsigned int chassis, unsigned int slot);

NAIBASEAPI
USHORT
NAIAPI
NaiReadReg_Pci(HANDLE hDevice, UINT Offset, UINT Count);

NAIBASEAPI
HANDLE
NAIAPI
NaiOpenDevice(UINT DeviceNumber);

#endif /* NAI_VISA */

#endif /* _NAILIB_H */
