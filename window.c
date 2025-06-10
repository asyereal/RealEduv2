#include <stdlib.h>
#include <raylib.h>
#include "window.h"

void listOptions(Rectangle **border, Rectangle **padbox, /*char ***nameText, */int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos, int *year){
	int nameSize = 30;
	*border[*optionPtr] = (Rectangle){26, *scrollOffset + *Ypos, *scrWidth - 50, 88};
	*padbox[*optionPtr] = (Rectangle){28, *scrollOffset + *Ypos + 2, *scrWidth - 54, 84};
	DrawRectangleRounded(*border[*optionPtr], 0.35f, 10, WHITE);
	DrawRectangleRounded(*padbox[*optionPtr], 0.35f, 10, BLACK);
	//DrawText(*nameText[*optionPtr], (*scrWidth / 2) - (MeasureText(*nameText[*optionPtr], nameSize) / 2), *scrollOffset + *Ypos + 27, nameSize, WHITE);
	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(*mousePos, *padbox[*optionPtr]))
		*year = *optionPtr + 1;
}

int main(){
	int scrWidth = 1200;
	int scrHeight = 740;
	int scrollOffset = 0;
	int scrollSpeed = 20;
	Vector2 mousePos;
	int year = 0;
	int Ypos = 316;

	Rectangle *border = malloc(sizeof(Rectangle)*6);
	Rectangle *padbox = malloc(sizeof(Rectangle)*6);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(scrWidth, scrHeight, "RealEdu");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		for(int i = 0; i < 6; i++){
			listOptions(&border, &padbox, &i, &Ypos, &scrollOffset, &scrWidth, &mousePos, &year);
		}
		EndDrawing();
	}
	CloseWindow();
	free(border);
	free(padbox);
}

