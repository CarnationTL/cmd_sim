#ifndef CMDDEFS_H
#define CMDDEFS_H

#define EXE_SUCCESS 0
#define EXE_FAIL 1

#define RFM_DEV   "\\\\.\\rfm2g1"

#define BUFFER_SIZE     256
#define OFFSET_1        0x1000
#define OFFSET_2        0x2000
#define TIMEOUT         6000

#define DEV_LEN         80
#define MAX_LVDT_CH     32
#define MAX_AO_CH       12
#define T_CODE
enum sigtypes {
    T_SINE,
    T_TRI,
    T_SAW,
    T_SQUARE,
    T_SP
};				/* ----------  end of enum sigtypes  ---------- */

typedef enum sigtypes Sigtypes;





#endif // CMDDEFS_H
