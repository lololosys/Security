#ifndef	_HASH_TABLE_H
#define _HASH_TABLE_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef struct _list_t_ {
    char *string;
    struct _list_t_ *next;
} list_t;

typedef struct _hash_table_t_ {
    int size;       /* the size of the table */
    list_t **table; /* the table elements */
} hash_table_t;

#include <stdio.h>
#include <stdlib.h>

#endif