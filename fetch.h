/*
 * SPDX-FileCopyrightText: 2025 Muhammad Asyraf Bin Mohd Nuriman <asyraf50107@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <curl/curl.h>
#ifndef FETCH_H
#define FETCH_H

void fetchFile(const char *url, const char *outPath);
const char *getPath(char *filename);

#endif
