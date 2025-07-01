/*
 * RealEdu - Malaysian education e-textbook manager  
 * Copyright (C) 2025  Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "window.h"

int main()
{
	// placeholding variables
	char **buff;
	char **bookTitle;
	char **bookFile;
	char **bookUrl;
	char **greetTitle = (char *[]){strdup("NULL"), strdup("Primary School"), strdup("Secondary School")};
	char **yearTitle = (char *[]){strdup("NULL"), strdup("Year 1"), strdup("Year 2"), strdup("Year 3"), strdup("Year 4"), strdup("Year 5"), strdup("Year 6")};

	// window.h variables
	const int scrWidth = 1200;
	const int scrHeight = 740;
	Screen scr = 0;
	int scrollOffset = 0;
	int scrollSpeed = 20;
	Vector2 mousePos;
	int Ypos = 116;

	Rectangle *border = malloc(sizeof(Rectangle)*7);
	Rectangle *padbox = malloc(sizeof(Rectangle)*7);
	Rectangle *tempBox;

	/*
	Image bgImg = LoadImage("list/plum.png");
	if (!IsImageValid(bgImg))
		perror("Image is invalid\n");
	Texture2D bg = LoadTextureFromImage(bgImg);
	UnloadImage(bgImg);
	*/

	// page handling variables
	int year = 0;
	int eduLvl = 0;
	int bookPtr = 0;

	// fetch.h variables
	int fileRead = 0;
	int maxLine = 0;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(scrWidth, scrHeight, "RealEdu");
	SetTargetFPS(60);

	while(!WindowShouldClose()){
		mousePos = GetMousePosition();
		scrollOffset += GetMouseWheelMove() * scrollSpeed;

		if(scrollOffset>0)
			scrollOffset = 0;
		// Event Polling
		if(IsKeyPressed(KEY_A))
			scr = GREET;
		if(IsKeyPressed(KEY_S))
			scr = YEAR;
		if(IsKeyPressed(KEY_D))
			scr = CATALOGUE;
		if(IsKeyPressed(KEY_Q))
			break;
		if(IsKeyPressed(KEY_Z)){
			eduLvl = 0;
			year = 0;
			scr = GREET;
		}
		if(IsKeyPressed(KEY_X)){
			year = 0;
			scr = YEAR;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		//DrawTextureEx(bg, (Vector2){0, 0}, 0, 1.0f, WHITE);

		// Page Polling
		Ypos = 116;	
		switch (scr) {
			case GREET:
				for(int i = 1; i < 3; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &eduLvl, greetTitle);
					Ypos += 100;
				}
				break;
			case YEAR:
				if(makeBack(&scrWidth, &greetTitle, &eduLvl)){
					eduLvl = 0;
					year = 0;
					scr = GREET;

					scrollOffset = 0;
				}
				for(int i = 1; i < 7; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &year, yearTitle);
					Ypos += 100;
				}
				break;
			case CATALOGUE:
				if(!fileRead){
					readFile(&eduLvl, &year, &fileRead, &buff, &maxLine);
					parseBuff(&buff, &bookTitle, &bookUrl, &bookFile, &maxLine);

					if((tempBox = realloc(border, sizeof(Rectangle) * maxLine)) != NULL) border = tempBox;
					if((tempBox = realloc(padbox, sizeof(Rectangle) * maxLine)) != NULL) padbox = tempBox;
				}
				if(makeBack(&scrWidth, &yearTitle, &year)){
					year = 0;
					scr = YEAR;

					scrollOffset = 0;
				}
				for(int i = 1; i < maxLine; i++){
					makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth);
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &bookPtr, bookTitle);
					Ypos += 100;
					if(bookPtr){
						printf("bookTitle: %s\nbookUrl: %s\n", bookTitle[bookPtr], bookUrl[bookPtr]);
						bookPtr = 0;
					}
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
	for(int i = 0; i<3; i++) free(greetTitle[i]);
	for(int i = 0; i<7; i++) free(yearTitle[i]);
	free(buff);
	free(bookTitle);
	free(bookFile);
	free(bookUrl);
	
	//window.h memory
	free(border);
	free(padbox);

	
	return 0;
}

