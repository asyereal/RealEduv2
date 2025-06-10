#include "read.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int isPrimary = 1;
	int year = 2;
	char **buff;
	char **bookTitle;
	char **bookUrl;
	int fileRead = 0;
	int maxLine = 0;

	readFile(&isPrimary, &year, &fileRead, &buff, &maxLine);
	//printf("maxLine: %d\n", maxLine);

	parseBuff(&buff, &bookTitle, &bookUrl, &maxLine);
	for(int j=0; j<maxLine; j++) printf("%d: %s, %s\n", j,bookTitle[j], bookUrl[j]);

	// Garbage man
	for(int i=0; i<maxLine; i++) free(buff[i]);
	for(int i=0; i<maxLine; i++) free(bookTitle[i]);
	for(int i=0; i<maxLine; i++) free(bookUrl[i]);
	free(buff);
	free(bookTitle);
	free(bookUrl);
	
	return 0;
}

