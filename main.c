#include <stdio.h>
#include <stdlib.h>

#include "read.h"
//#include "fetch.h"
#include "window.h"

int main()
{
	// placeholding variables
	char **buff;
	char **bookTitle;
	char **bookFile;
	char **bookUrl;
	int fileRead = 0;
	int maxLine = 0;

	//window.h variables
	const int scrWidth = 1200;
	const int scrHeight = 740;
	Screen scr = 0;
	int scrollOffset = 0;
	int scrollSpeed = 20;
	Vector2 mousePos;
	int year = 0;
	int Ypos = 116;
	int eduLvl = 0;
	int bookPtr = 0;

	Rectangle *border = malloc(sizeof(Rectangle)*6);
	Rectangle *padbox = malloc(sizeof(Rectangle)*6);
	Rectangle *tempBox;

	//fetch the file
	//fetchFile();

	// read and parse it
	//readFile(&eduLvl, &year, &fileRead, &buff, &maxLine);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(scrWidth, scrHeight, "RealEdu");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		mousePos = GetMousePosition();
		BeginDrawing();
		ClearBackground(BLACK);

		// Page Polling
		Ypos = 116;	
		switch (scr) {
			case GREET:
				for(int i = 0; i < 2; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &eduLvl);
					Ypos += 100;
				}
				break;
			case YEAR:
				for(int i = 0; i < 6; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &year);
					Ypos += 100;
				}
				break;
			case CATALOGUE:
				//printf("eduLvl: %d\nyear: %d\nscr: %d\n", eduLvl, year, scr);
				if(!fileRead){
					readFile(&eduLvl, &year, &fileRead, &buff, &maxLine);
					parseBuff(&buff, &bookTitle, &bookUrl, &bookFile, &maxLine);

					if((tempBox = realloc(border, sizeof(Rectangle) * maxLine)) != NULL) border = tempBox;
					if((tempBox = realloc(padbox, sizeof(Rectangle) * maxLine)) != NULL) padbox = tempBox;
				}
				//peek at file content
				//for(int j=0; j<maxLine; j++) printf("%d: %s, %s, %s\n", j,bookTitle[j], bookFile[j], bookUrl[j]);
				for(int i = 0; i < maxLine; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &bookPtr);
					Ypos += 100;
				}
				break;
			default:
				perror("Something's very wrong\n");
				break;
		}
		if(year) scr = CATALOGUE;
		else if(eduLvl)	scr = YEAR;
		
		EndDrawing();
	}
	CloseWindow();

	// Free dynamic memory
	//read.h memory
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
	
	//window.h memory
	free(border);
	free(padbox);
	
	return 0;
}

