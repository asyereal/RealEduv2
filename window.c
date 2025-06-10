#include <stdio.h>
#include <raylib.h>
#include "window.h"

#define R_PLUM 0xe501fdff

void makeBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos){
	int nameSize = 30;
	(*border)[*optionPtr] = (Rectangle){26, *scrollOffset + *Ypos, *scrWidth - 50, 88};
	(*padbox)[*optionPtr] = (Rectangle){28, *scrollOffset + *Ypos + 2, *scrWidth - 54, 84};
}

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos, int *targetPtr){
	DrawRectangleRounded((*border)[*optionPtr], 0.35f, 10, WHITE);
	DrawRectangleRounded((*padbox)[*optionPtr], 0.35f, 10, GetColor(R_PLUM));
	if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(*mousePos, (*padbox)[*optionPtr])){
		*targetPtr = *optionPtr + 1;
		printf("optionPtr: %d\n", *optionPtr);
	}
	return;
}

