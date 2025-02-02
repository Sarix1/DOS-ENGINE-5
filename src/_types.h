#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stddef.h>
#include "_watcom.h"

//#include <stdbool.h>
typedef unsigned char bool;
#define true 1
#define false 0

typedef int32_t  fix16_16;
typedef fix16_16 fixp;
typedef int16_t  brad;
typedef uint8_t  byte;
typedef uint16_t word;
typedef int16_t  sword;
typedef uint32_t dword;
typedef int32_t  time_t;
typedef uint16_t flags_t;
typedef uint16_t id_t;
typedef uint8_t  action_id_t;
typedef uint32_t controldata_t;

typedef void (*fnp)(void);
typedef void (*fnp_i)(int);
typedef int (*i_fnp)(void);
typedef int (*i_fnp_i)(void);
typedef void (*fnp_p)(void*);
typedef void* (*p_fnp)(void);
typedef void* (*p_fnp_p)(void*);
typedef int (*i_fnp_p)(void*);
typedef void* (*p_fnp_i)(int);

typedef unsigned char FAR* farptr_t;
typedef unsigned char NEAR* nearptr_t;

#endif/* TYPES_H */
