#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "window.h"

#define R_PLUM 0xe501fdff

typedef enum{
	GREET = 0,
	YEAR = 1,
	CATALOGUE = 2
} Screen;

void makeBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos){
	int nameSize = 30;
	(*border)[*optionPtr] = (Rectangle){26, *scrollOffset + *Ypos, *scrWidth - 50, 88};
	(*padbox)[*optionPtr] = (Rectangle){28, *scrollOffset + *Ypos + 2, *scrWidth - 54, 84};
}

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos, int *targetPtr){
	DrawRectangleRounded((*border)[*optionPtr], 0.35f, 10, WHITE);
	DrawRectangleRounded((*padbox)[*optionPtr], 0.35f, 10, GetColor(R_PLUM));
	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(*mousePos, (*padbox)[*optionPtr])){
		*targetPtr = *optionPtr + 1;
		printf("optionPtr: %d\n", *optionPtr);
	}
	return;
}

int main(){
	Screen scr = 0;
	int scrWidth = 1200;
	int scrHeight = 740;
	int scrollOffset = 0;
	int scrollSpeed = 20;
	Vector2 mousePos;
	int year = 0;
	int Ypos = 116;
	int eduLvl = 0;

	Rectangle *border = malloc(sizeof(Rectangle)*6);
	Rectangle *padbox = malloc(sizeof(Rectangle)*6);

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
				printf("this is the catalogue\n");
				break;
			default:
				perror("Something's very wrong\n");
				break;
		}
		printf("eduLvl: %d\n", eduLvl);
		if(year) scr = CATALOGUE;
		else if(eduLvl)	scr = YEAR;
		printf("scr: %d\n", scr);
		
		EndDrawing();
	}
	CloseWindow();
	free(border);
	free(padbox);
}

