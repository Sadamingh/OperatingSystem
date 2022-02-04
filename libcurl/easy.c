#include <curl/curl.h>

int main() {
    if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
        fprintf(stderr, "Can't initialize Libcurl.\n");
    }
    printf("Libcurl Version: %s\n", curl_version());

    CURL *easy_handle = curl_easy_init();
    curl_easy_setopt(easy_handle, CURLOPT_URL, "https://stallman.org/internet-voting.html");
    curl_easy_perform(easy_handle);
    curl_easy_cleanup(easy_handle);

    curl_global_cleanup();
    return 0;
}