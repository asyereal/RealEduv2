/*
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <raylib.h>
#include "window.h"

#define R_PLUM 0xe501fdff

void makeBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos){
	int nameSize = 30;
	(*border)[*optionPtr] = (Rectangle){26, *scrollOffset + *Ypos, *scrWidth - 50, 88};
	(*padbox)[*optionPtr] = (Rectangle){28, *scrollOffset + *Ypos + 2, *scrWidth - 54, 84};
}

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos, int *targetPtr, char **nameText){
	int nameSize = 30;
	DrawRectangleRounded((*border)[*optionPtr], 0.35f, 10, WHITE);
	DrawRectangleRounded((*padbox)[*optionPtr], 0.35f, 10, GetColor(R_PLUM));
  	DrawText(nameText[*optionPtr], (*scrWidth / 2) - (MeasureText(nameText[*optionPtr], nameSize) / 2), *scrollOffset + *Ypos + 27, nameSize, WHITE);
	if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(*mousePos, (*padbox)[*optionPtr])){
		*targetPtr = *optionPtr + 1;
		printf("optionPtr: %d\n", *optionPtr);
	}
}

int makeBack(const int *scrWidth, char ***backText, int *textPtr){
	int nameSize = 60;
	Rectangle border = {(*scrWidth-MeasureText((*backText)[*textPtr], nameSize))-40, 16, (MeasureText(*backText[*textPtr], nameSize)+28), 88};
	Rectangle padbox = {(*scrWidth-MeasureText((*backText)[*textPtr], nameSize))-38, 18, (MeasureText(*backText[*textPtr], nameSize)+24), 84};
	DrawRectangleRounded(border, 0.35f, 10, WHITE);
	DrawRectangleRounded(padbox, 0.35f, 10, GetColor(R_PLUM));
	DrawText(*backText[*textPtr], (*scrWidth-MeasureText(*backText[*textPtr], nameSize))-24, 30, nameSize, WHITE);
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), padbox)){
		printf("Pressed\n");
		return 1;
	}
	return 0;
}
