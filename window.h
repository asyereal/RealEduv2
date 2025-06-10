#include <raylib.h>

#ifndef WINDOW_H
#define WINDOW_H

void makeBox(Rectangle **border, Rectangle **padbox, /*char ***nameText, */int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos);

void showBox(Rectangle **border, Rectangle **padbox, int *optionPtr, int *Ypos, int *scrollOffset, int *scrWidth, Vector2 *mousePos, int *targetPtr);
#endif
