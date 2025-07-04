/*
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#ifndef READ_H
#define READ_H

#define MAX_LINE_LEN 150
#define MAX_TITLE_LEN 40
#define MAX_LOC_LEN 120


void readFile(int *isPrimary, int *year, int *fileRead, char ***buff, int *maxLine);
void parseBuff(char ***buff, char ***bookTitle, char ***bookUrl, char ***bookFile, int *maxLine);

#endif
