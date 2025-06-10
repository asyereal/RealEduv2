#include "fetch.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream){
	return fwrite(ptr, size, nmemb, stream);
}

void fetchFile(const char *url, const char *outPath){
	CURL *curl = curl_easy_init();
	if(curl){
		FILE *fp = fopen(outPath, "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(fp);
	}
	return;
}

const char *getPath(char *filename){
	static char path[512];
#ifdef _WIN3
	snprintf(path, sizeof(path), "%s\\RealEdu\\%s", getenv("APPDATA"), filename);
#else
	snprintf(path, sizeof(path), "%s/Documents/c/again/list/%s", getenv("HOME"), filename);
#endif
	return path;
}
