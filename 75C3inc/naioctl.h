#ifndef NAIOCTL_H
#define NAIOCTL_H

#ifdef WIN32
/* Suppress "warning C4201: nonstandard extension used : nameless struct/union" */
#pragma warning( disable : 4201)
#endif

#ifndef ULONG
#ifdef NAI_VISA
#define ULONG unsigned long
#else
#define ULONG unsigned int
#endif
#endif

#ifndef USHORT
#define USHORT unsigned short
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#endif

#if defined(LINUX) || defined(VXWORKS) || defined(LYNX)|| defined(NAI_RTP)

#define NAI_TYPE 0x44

#define IOCTL_NAI_READ_PORT_UCHAR     _IOWR(NAI_TYPE, 0, NAI_READ_OUTPUT)
#define IOCTL_NAI_READ_PORT_USHORT    _IOWR(NAI_TYPE, 1, NAI_READ_OUTPUT)
#define IOCTL_NAI_WRITE_PORT_UCHAR    _IOWR(NAI_TYPE, 2, NAI_WRITE_INPUT)
#define IOCTL_NAI_WRITE_PORT_USHORT   _IOWR(NAI_TYPE, 3, NAI_WRITE_INPUT)
#define IOCTL_NAI_READ_INFO           _IOWR(NAI_TYPE, 4, NAI_DEVICE_CONFIG)
#define IOCTL_NAI_INT_TRIGGER_ENABLE  _IOWR(NAI_TYPE, 5, NAI_WRITE_INPUT)
#define IOCTL_NAI_INT_CONFIGURE       _IOWR(NAI_TYPE, 6, NAI_INT_CONFIG)
#define IOCTL_NAI_INT_HOOK            _IOWR(NAI_TYPE, 7, NAI_INT_HOOK)
#define IOCTL_NAI_INT_DATA            _IOWR(NAI_TYPE, 8, NAI_INT_DATA)
#define IOCTL_NAI_INT_DISABLE         _IOWR(NAI_TYPE, 9, NAI_INT_DATA)

/* for VME Address, LynxOS */
#define IOCTL_NAI_GET_VME_BASE_ADDR   _IOWR(NAI_TYPE, 10, NAI_READ_OUTPUT)
#define IOCTL_NAI_GET_VME_ADDR        _IOWR(NAI_TYPE, 11, NAI_READ_OUTPUT)
#define IOCTL_NAI_SET_VME_ADDR        _IOWR(NAI_TYPE, 12, NAI_READ_OUTPUT)

#define IOCTL_NAI_READ_PORT_ULONG     _IOWR(NAI_TYPE, 13, NAI_READ_OUTPUT)
#define IOCTL_NAI_WRITE_PORT_ULONG    _IOWR(NAI_TYPE, 14, NAI_WRITE_INPUT)
#define IOCTL_NAI_READ_PCIINFO        _IOWR(NAI_TYPE, 15, NAI_DEVICE_CONFIG)

#else /* WIN32 */

/* Device type in the "User Defined" range. */
#define NAI_TYPE 50000

#define IOCTL_NAI_READ_PORT_USHORT \
CTL_CODE(NAI_TYPE, 0x0, METHOD_BUFFERED, FILE_READ_ACCESS )

#define IOCTL_NAI_WRITE_PORT_USHORT \
CTL_CODE(NAI_TYPE, 0x1, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_NAI_READ_PORT_UCHAR \
CTL_CODE(NAI_TYPE, 0x2, METHOD_BUFFERED, FILE_READ_ACCESS )

#define IOCTL_NAI_WRITE_PORT_UCHAR \
CTL_CODE(NAI_TYPE, 0x3, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_NAI_INT_TRIGGER_ENABLE \
CTL_CODE(NAI_TYPE, 0x4, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_NAI_READ_INFO \
CTL_CODE(NAI_TYPE, 0x5, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_NAI_INT_CONFIGURE \
CTL_CODE(NAI_TYPE, 0x6, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_NAI_READ_PORT_ULONG \
CTL_CODE(NAI_TYPE, 0x7, METHOD_BUFFERED, FILE_READ_ACCESS )

#define IOCTL_NAI_WRITE_PORT_ULONG \
CTL_CODE(NAI_TYPE, 0x8, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_NAI_READ_PCIINFO \
CTL_CODE(NAI_TYPE, 0x9, METHOD_BUFFERED, FILE_READ_ACCESS)

#endif

typedef struct _NAI_WRITE_INPUT
{
  ULONG   PortNumber; /* Offset to write */
  union               /* Data to be written */
  {
    ULONG   LongData;
    USHORT  ShortData;
    UCHAR   CharData;
#if defined (LINUX) || defined (WIN32)
  };
#else
  } data;  /* VxWorks needs union name */
#endif
} NAI_WRITE_INPUT;

typedef struct _NAI_READ_OUTPUT
{
  union               /* Data to be read */
  {
	ULONG   LongData;
	USHORT  ShortData;
	UCHAR   CharData;
#if defined (LINUX) || defined (WIN32)
  };
#else
  } data;  /* VxWorks needs union name */
#endif
} NAI_READ_OUTPUT;

/*
   This structure is used with IOCTL_NAI_READ_INFO to
   obtain configuration information from the device.
*/

typedef struct _NAI_DEVICE_CONFIG {

  ULONG BaseAdr;
  ULONG PortCount;
  UCHAR IrqLine;
  UCHAR Status;
  ULONG bPCIDevice;
  ULONG BusNum;
  ULONG DeviceId;

} NAI_DEVICE_CONFIG, *PNAI_DEVICE_CONFIG;

/*
   This structure is used with IOCTL_NAI_READ_PCIINFO to
   obtain configuration information from the device.
   Note, this structure is an extension of the NAI_DEVICE_CONFIG
   structure, with additional fields for the Device Number,
   Function Number and Slot Number.
*/

typedef struct _NAI_DEVICE_CONFIG_EX {

  ULONG BaseAdr;
  ULONG PortCount;
  UCHAR IrqLine;
  UCHAR Status;
  ULONG bPCIDevice;
  ULONG BusNum;
  ULONG DeviceId;
  ULONG DeviceNum;
  ULONG FunctionNum;
  ULONG SlotNum;

} NAI_DEVICE_CONFIG_EX, *PNAI_DEVICE_CONFIG_EX;

/*
   These flags are used on NAI_DEVICE_CONFIG.Status.
*/
#define NAI_STATUS_READY    0x00000000
#define NAI_STATUS_CONFLICT 0x00000001

typedef struct _NAI_READ_INFO
{
   NAI_DEVICE_CONFIG DeviceConfig;

} NAI_INFO_BUFFER;

typedef struct _NAI_READ_PCIINFO
{
   NAI_DEVICE_CONFIG_EX DeviceConfig;

} NAI_PCIINFO_BUFFER;

/*
   This structure is used with IOCTL_NAI_INT_CONFIGURE to
   change the interrupt handling behavior on the device.
*/

typedef struct _NAI_INT_CONFIG {
  ULONG  ReadAddr;
  ULONG  WriteAddr;
  ULONG  WriteValue;
} NAI_INT_CONFIG, *PNAI_INT_CONFIG;

typedef struct _NAI_INT_HOOK {
	ULONG Level;
	ULONG Vector;
	ULONG tid;
} NAI_INT_HOOK, *PNAI_INT_HOOK;

typedef struct _NAI_INT_DATA {
	ULONG Level;
	ULONG Vector;
} NAI_INT_DATA, *PNAI_INT_DATA;

#endif /*NAIOCTL.H */
