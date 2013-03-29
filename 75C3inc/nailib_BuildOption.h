/**
*=========================================================================
*
* Copyright (c) 2012 North Atlantic Industries, Inc.  All Rights Reserved.
*
* Author: North Atlantic Industries, Inc.
*
* FileName: nailib_BuildOptions.h
*
* $Archive: /SW Code Base/NAI_CPCI78C2/LibSrc/include/nailib_BuildOption.h $
*
* $Revision: 2 $
*
* $Date: 9/26/12 4:47p $
*
* $NoKeywords: $
*=========================================================================
**/
#ifndef _NAILIB_BUILDOPTIONS_H
#define _NAILIB_BUILDOPTIONS_H

/* For Linux and LynxOS systems,
 * the following compiler switches are associated with the values returned after
 * invoking the routine:
 *     fopen( "/proc/bus/pci/devices", "r" )
 * The CONFIG_HAVE_LONG_LONG_ADDRESS compiler switch
 * will change the default type definition from
 *     unsigned int
 *  to
 *     unsigned long long
 * The CONFIG_HAVE_LONG_ADDRESS compiler switch
 * will change the default type definition from
 *     unsigned int
 *  to
 *     unsigned long
*/
/*
#define CONFIG_HAVE_LONG_LONG_ADDRESS
#define CONFIG_HAVE_LONG_ADDRESS
*/

/* The following compiler switches will display debug printf messages. */
/*
#define NAI_DBG
*/

/* The following compiler switch enable National Instrument VISA support. */
/*
#define NAI_VISA
*/

/* The following compiler switch enable vxWorks support. */
/*
#define NAI_VXWORKS
*/

#endif /* _NAILIB_H */
