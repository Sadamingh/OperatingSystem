#include <curl/curl.h>

int main() {
    if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
        fprintf(stderr, "Can't initialize Libcurl.\n");
    }
    printf("Libcurl Version: %s\n", curl_version());
    curl_global_cleanup();
    return 0;
}