#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // assign the address value
    long nHostAddress = 5;
    // define a string for storing the IP string
    char ipstr[INET6_ADDRSTRLEN];
    // use inet_ntop to translate the affess value to IP string, store in ipstr
    inet_ntop(AF_INET6, &nHostAddress, ipstr, sizeof ipstr);
    // print the result
    printf("%ld result: %s\n", nHostAddress, ipstr);

    unsigned char buf[sizeof(struct in6_addr)];
    int result = getaddrinfo("localhost", NULL, NULL, buf);
    printf("%d", result);

    return 0;
}