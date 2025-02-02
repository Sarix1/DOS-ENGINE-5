#ifndef _BUFFER_H
#define _BUFFER_H

#include "_watcom.h"
#include "_types.h"

typedef struct
{
    farptr_t start;
    farptr_t end;
    size_t size;
} Buffer_t;

Buffer_t* createBuffer(size_t size);
void freeBuffer(Buffer_t* buffer);
int copyToFar(farptr_t dest, const void* src, size_t size);
int copyFromFar(void* dest, const farptr_t src, size_t size);

#endif/* _BUFFER_H */