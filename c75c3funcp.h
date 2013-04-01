#ifndef C75C3FUNCP_H
#define C75C3FUNCP_H
/**
  the func pointer of 75c3dll
**/


typedef int(* FPTR_OPEN)(int);
typedef int(* FPTR_CLOSE)(int);

typedef void(* FPTR_INIT)(void);
typedef int(* FPTR_GETDEVCNT)(void);
typedef int(* FPTR_GETBRDREADY)(int, unsigned short);


#endif // C75C3FUNCP_H
