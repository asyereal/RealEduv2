/*
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "fetch.h"

static int countLine(FILE *fp){
	int lines = 0;
	char buff;
	long curPos = ftell(fp);

	while((buff = fgetc(fp)) != EOF) {
		if(buff == '\n') lines++;
	}
	fseek(fp, curPos, SEEK_SET);
	return lines;
}

void readFile(int *eduLvl, int *year, int *fileRead, char ***buff, int *maxLine){
	FILE *fp;
	char filename[20];
	int lineCount = 0;
	int i;
	int retryLimit = 0;

	if(*eduLvl == 1) snprintf(filename, 20, "year%d.csv", *year);
	else if (*eduLvl == 2) snprintf(filename, 20, "form%d.csv", *year);
	char url[100];
	snprintf(url, sizeof(url), "http://localhost/Pri_db/%s", filename);

	//fp = fopen(filename, "r");
	while(!(fp = fopen(getPath(filename), "r")) && retryLimit < 5){
		perror("File doesn't exist! Downloading...\n");
		fetchFile(url, getPath(filename));
		++retryLimit;
	}
	*maxLine = countLine(fp);
	*buff = malloc(*maxLine * sizeof(char *));
	if(!*buff){
		perror("Mem Alloc failed\n");
		fclose(fp);
		*fileRead = 0;
		return;
	}

	for(i=0; i<*maxLine; i++){
		(*buff)[i] = malloc(MAX_LINE_LEN);
		if(!(*buff)[i]){
			perror("Line Alloc failed");
			/*
			for(int j = 0; j < i; j++){
				free((*buff)[j]);
			}
			free(*buff);
			*/
			fclose(fp);
			*fileRead = 0;
			return;
		}
	}
	while(fgets((*buff)[lineCount], MAX_LINE_LEN, fp) != NULL && lineCount < *maxLine){
		(*buff)[lineCount][strcspn((*buff)[lineCount], "\n")] = '\0';
		lineCount++;
	}
	*fileRead = 1;
	fclose(fp);
}

void parseBuff(char ***buff, char ***bookTitle, char ***bookUrl, char ***bookFile, int *maxLine){
	*bookTitle = malloc(*maxLine * sizeof(char *));
	*bookFile = malloc(*maxLine * sizeof(char *));
	*bookUrl = malloc(*maxLine * sizeof(char *));
	for(int i=0; i<*maxLine; i++){
		(*bookTitle)[i] = malloc(MAX_LINE_LEN);
		(*bookFile)[i] = malloc(MAX_LINE_LEN);
		(*bookUrl)[i] = malloc(MAX_LINE_LEN);
	}
	for(int j=0; j<*maxLine; j++){
		strcpy((*bookTitle)[j], strtok((*buff)[j], ","));
		strcpy((*bookFile)[j], strtok(NULL, ","));
		strcpy((*bookUrl)[j], strtok(NULL, ","));
	}
	return;
}

