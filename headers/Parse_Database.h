#ifndef	_PARSE_DATABASE_H
#define _PARSE_DATABASE_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ParseDatabase(char *);
void PrintKey(struct Database *, char *);
void PrintValue(struct Database *, char *);


typedef struct Database	{
	char *name;
	char *signature;
} Database;

#endif