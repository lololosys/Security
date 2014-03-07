#include "Parse_Database.h"

/*
	hash table
	------------
	implement a hash table which the key is the name of the virus
	the value is the signature.

	inorder on search over the files we could use Boyer–Moore string search algorithm

	Version Alpha: 
		Anti-Virus  - Viruses and signatures save into a file
		then it loads up into a struct

	Version Beta:
		more complicated program that use hash table for searching and storing the database

	Iterate over the database stream to save them into structure.
	for example:
		"virusA" - "signature"\nVirusB" - "signature"\n\r\eof
	it will parse as:
		database info[1];

		info[0]:
			name = "virusA"
			signature = "signature"
			hash = 1
		info[1]:
			name = "virusB"
			signature = "signature"
			hash = 0

*/
void ParseDatabase(char *data)	{
	//char *token = "\"\n";
	char *token = """=\n""";
	char *ptr = strtok(data, token);
	int i = 0;
	Database *database = NULL;

	while(ptr != NULL)	{
		if(i%2 == 0)
			PrintKey(ptr, database);
		else
			PrintValue(ptr, database);
		ptr = strtok(NULL, token);
		i++;
	}
}

void PrintKey(Database *database, char *name)	{
	strcpy(database->name, name);
	printf("key: %s\n", database->name);
}

void PrintValue(Database *database, char *signature)	{
	strcpy(database->signature, signature);
	printf("value: %s\n", database->signature);
}

/*
Database *ParseDatabase(char *data)	{
	Database *info = NULL;



	//info = Check_Hash(info);
	return info;
}*/