#include "read.h"
#include <stdlib.h>

int main()
{
	int isPrimary = 1;
	int year = 2;
	char **buff;
	int fileRead = 0;
	int maxLine = 0;

	readFile(&isPrimary, &year, &fileRead, &buff, &maxLine);
	printf("maxLine: %d\n", maxLine);
	//parseFile(&buff);

	// Garbage man
	for(int i=0; i<maxLine; i++) free(buff[i]);
	free(buff);
	
	return 0;
}

