#ifndef	_ALLOC_MEM_H
#define _ALLOC_MEM_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define chunk 255

#include <stdio.h>
#include <stdlib.h>

char *AllocMem(const char *);

#endif