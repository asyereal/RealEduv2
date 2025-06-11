/*
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <raylib.h>

#ifndef WINDOW_H
#define WINDOW_H

typedef enum{
	GREET = 0,
	YEAR = 1,
	CATALOGUE = 2
} Screen;

void makeBox(Rectangle **border, Rectangle **padbox, /*char ***nameText, */int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos);

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, const int *scrWidth, Vector2 *mousePos, int *targetPtr, char **nameText);

int makeBack(const int *scrWidth, char ***backText, int *textPtr);
#endif
