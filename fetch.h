#include <curl/curl.h>
#ifndef FETCH_H
#define FETCH_H

void fetchFile(const char *url, const char *outPath);
const char *getPath(char *filename);

#endif
