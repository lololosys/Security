#include "Alloc_Mem.h"


char *AllocMem(const char *filename)	{
	FILE *fp = NULL;
	char ch = EOF;
	char *buf = NULL, *tmp = NULL;
	unsigned int result= 0;
	unsigned int size=0, index=0;
	
	/*
		Mallicous use of fopen(anyone could replace filename with a malicous modified file)
	*/
	fp = fopen(filename, "r");
	if(fp == NULL)	{
		fprintf(stderr, "Can't open the signature database");
		exit(1);
	}

	while(ch)	{
		result = fread(&ch, 1, 1, fp);

		if(result != 1)	{
			ch = 0;
		}

		if(size <= index)	{
			size+=chunk;
			tmp = realloc(buf, size);
			if(!tmp)	{
				free(buf);
				buf = NULL;
				break;
			}
			buf = tmp;
		}

		buf[index++] = ch;
	}

	fclose(fp);
	return buf;
}