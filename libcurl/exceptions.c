#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>


typedef struct memory {
   char *response;
   size_t size;
} datamemory;


size_t writecb (void *buffer, size_t size, size_t nmemb, void *user_p) {
    size_t realsize = size * nmemb;

    datamemory *chunk = (datamemory *) user_p;
    chunk->response = realloc(chunk->response, chunk->size + realsize + 1);
    if (chunk->response == NULL) {
        printf("Out of memory!");
        return 0;
    }

    memcpy(&(chunk->response[chunk->size]), buffer, realsize);
    chunk->size += realsize;
    // printf("%s", chunk->response);
    // printf("This is from the modified callback.\n");

    return realsize;
}


int main() {
    if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
        fprintf(stderr, "Can't initialize Libcurl.\n");
    }
    printf("Libcurl Version: %s\n", curl_version());

    CURL *easy_handle = curl_easy_init();

    datamemory *chunk = (datamemory *) malloc(sizeof(datamemory));
    memset(chunk, 0, sizeof(datamemory));

    curl_easy_setopt(easy_handle, CURLOPT_URL, "https://raw.githubusercontent.com/gt-cs6200/image_data/master/1kb-sample-file-1.html");
    curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, writecb);
    curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, chunk);

    curl_easy_perform(easy_handle);
    long status;
    curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &status);
    printf("code: %zu\n", status);
    if (status == 404) {
        fprintf(stderr, "ERROR: Can't find the resource.\n");
        return 0;
    }

    curl_easy_cleanup(easy_handle);

    curl_global_cleanup();

    printf("\nCheck the existence of the data =================== \n");
    char data[256];
    strncpy(data, chunk->response, 100);
    data[100] = '\0';
    printf("%s\n", data);
    printf("end ================================================= \n");
    
    return 0;
}