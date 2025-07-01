#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include "fetch.h"

int checkBook(const char *bookFile, char *bookUrl){
	printf("path: %s\n", bookFile);
	FILE *fp;
	fp = fopen(bookFile, "r");

	if(!fp){
		perror("Book not found!\n");
		fetchFile(bookUrl, bookFile);
		sleep(1);
	}
	printf("Opening file\n");
	fclose(fp);
	return 0;
}
