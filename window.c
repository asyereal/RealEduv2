#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "window.h"

typedef enum{
	GREET = 0,
	PRIMARY = 1,
	SECONDARY = 3,
	CATALOGUE = 4
} Screen;

void makeBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos){
	int nameSize = 30;
	(*border)[*optionPtr] = (Rectangle){26, *scrollOffset + *Ypos, *scrWidth - 50, 88};
	(*padbox)[*optionPtr] = (Rectangle){28, *scrollOffset + *Ypos + 2, *scrWidth - 54, 84};
}

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos, int *targetPtr){
	DrawRectangleRounded((*border)[*optionPtr], 0.35f, 10, WHITE);
	DrawRectangleRounded((*padbox)[*optionPtr], 0.35f, 10, GRAY);
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
	int scrPtr = 0;
	int Ypos = 116;

	Rectangle *border = malloc(sizeof(Rectangle)*6);
	Rectangle *padbox = malloc(sizeof(Rectangle)*6);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(scrWidth, scrHeight, "RealEdu");
	SetTargetFPS(60);
	for(int i = 0; i < 6; i++){
		makeBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos);
		Ypos += 100;
	}
	while(!WindowShouldClose()){
		mousePos = GetMousePosition();
		BeginDrawing();
		ClearBackground(BLACK);
		// Page Polling
		
		switch (scr) {
			case GREET:
				for(int i = 0; i < 2; i++){
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &scrPtr);
				}
				break;
			case PRIMARY:
				for(int i = 0; i < 6; i++){
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &year);
				}
				break;
			case SECONDARY:
				for(int i = 0; i < 6; i++){
					showBox(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &year);
				}
				break;
			case CATALOGUE:
				break;
			default:
				break;
		}
		printf("scrPtr: %d\n", scrPtr);
		
		EndDrawing();
	}
	CloseWindow();
	free(border);
	free(padbox);
}

