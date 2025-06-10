#include "fetch.h"
#include <curl/curl.h>
#include <curl/easy.h>
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

int main(){
	char path[512];
	const char *url = "http://localhost/Pri_db/year2.csv";

/*
#ifdef _WIN32
	snprintf(path, sizeof(path), "%s\\RealEdu\\year2.csv", getenv("APPDATA"));
#else
	snprintf(path, sizeof(path), "%s/.Documents/c/again/sandbox/year2.csv", getenv("HOME"));
#endif
*/
	snprintf(path, sizeof(path), "%s/Documents/c/again/sandbox/year2.csv", getenv("HOME"));
	printf("%s\n", path);
	fetchFile(url, path);

	return 0;
}
