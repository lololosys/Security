#include "Parse_Database.h"
#include "Alloc_Mem.h"
#include "Get_Signature.h"


int Get_Signature(const char *filename)	{
	char *database = AllocMem(filename);
	int error=0;

	//printf("data = %s", database);
	ParseDatabase(database);
	
	return 1;
}