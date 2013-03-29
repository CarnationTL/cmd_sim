#ifndef _75C3_INCLUDE_H
#define _75C3_INCLUDE_H

#include "CPCI75C3_BuildOption.h"

#ifdef _BUILD_75C3DLL
  #define _75C3CLASS __declspec( dllexport )
  #define _75C3FUNC  __declspec( dllexport )
#else
  #define _75C3CLASS __declspec( dllimport )
  #ifdef WIN32
    #define _75C3FUNC __declspec( dllimport )
  #else
    #define _75C3FUNC
  #endif
#endif


#endif
