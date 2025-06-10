#include "read.h"
//#include "fetch.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// placeholding variables
	int isPrimary = 1;
	int year = 1;
	char **buff;
	char **bookTitle;
	char **bookFile;
	char **bookUrl;
	int fileRead = 0;
	int maxLine = 0;

	//fetch the file
	//fetchFile();

	// read and parse it
	readFile(&isPrimary, &year, &fileRead, &buff, &maxLine);
	parseBuff(&buff, &bookTitle, &bookUrl, &bookFile, &maxLine);
	for(int j=0; j<maxLine; j++) printf("%d: %s, %s, %s\n", j,bookTitle[j], bookFile[j], bookUrl[j]);

	// Garbage man
	for(int i=0; i<maxLine; i++){
		free(buff[i]);
		free(bookTitle[i]);
		free(bookFile[i]);
		free(bookUrl[i]);
	}
	free(buff);
	free(bookTitle);
	free(bookFile);
	free(bookUrl);
	
	return 0;
}

