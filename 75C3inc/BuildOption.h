#ifndef _BUILD_OPTION_H
#define _BUILD_OPTION_H

#define NAI_DBG
#undef NAI_DBG

/***** WINDOWS OS DEFINES ****/
#define _BUILD_75C3DLL
#define __NAIDLL32__

/***** VXWORKS OS DEFINES ****/
/*
#define NAI_VXWORKS
#define VXWORKS
#define APEX_BSP_CW_SCP122
*/

/* When we're dealing with PCI/CPCI bus, module register address needs to be shifted one to left
*/
#define ADDR_SHIFT               1
#define CPCI75C3_ADDR_SHIFT               1


/* The following compiler switch will compile in the code that performs parameter
   checking (such as Card, module, channel and data range) in each of the functions.
*/
#define _VERIFY_PARAM

/***** ETHERNET IPV4 and IPV6 SUPPORT ****/
/* If the OS only support IPV4, uncomment out the #define below */
/* #define _WITH_IPV4_SUPPORT_ONLY */

/* The following compiler switch will compile in the code that support access to
   the board via Ethernet.  By default this should not be commented out, however,
   in order to support multiple-builds (CPCI75C3Dll.dll, CPCI75C3Dll_Visa.dll and
   CPCI75C3Dll_Visa_NoEther.dll, this option is commented out here and the Preprocessor
   options for the project are used instead.
*/
/*
#define _HAS_ETHERNET
*/

#endif

