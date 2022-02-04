#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(void) {
    char *hostname = "localhost";
    char ipstr[INET_ADDRSTRLEN];
    char ipstr6[INET6_ADDRSTRLEN];

    struct hostent* pHostInfo;
    long nHostAddress;

    pHostInfo = gethostbyname(hostname);
    memcpy(&nHostAddress, pHostInfo->h_addr, pHostInfo->h_length);
    inet_ntop(AF_INET, &nHostAddress, ipstr, sizeof ipstr);

    pHostInfo = gethostbyname(hostname);
    memcpy(&nHostAddress, pHostInfo->h_addr, pHostInfo->h_length);
    inet_ntop(AF_INET6, &nHostAddress, ipstr6, sizeof ipstr6);

    if (strcmp(ipstr, "127.0.0.1")) {
        printf("IPv4 test fail.\n");
    }
    if (strcmp(ipstr6, "::1")) {
        printf("IPv6 test fail.\n");
    } 
    if (strcmp(ipstr, "127.0.0.1") && strcmp(ipstr6, "::1")) {
        printf("All tests pass!\n");
    }

    printf("============ %s: ===========\nIPv4: %s\nIPv6: %s\nReal Address: %ld\n", pHostInfo->h_name, ipstr, ipstr6, nHostAddress);


    return 0;
}