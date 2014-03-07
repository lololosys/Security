#include <stdio.h>
#include "Get_Signature.h"

int main()	{
	
	char *filename = "C:\\signature.txt";
	int error;

	error = Get_Signature(filename);
	if(!error)	{
		printf("Get_Signature Problem..");
		exit(1);
	}


	return 0;
}