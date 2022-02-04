#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // assign the address value
    int nHostAddress = 16777343;
    // define a string for storing the IP string
    char ipstr[INET_ADDRSTRLEN];
    // use inet_ntop to translate the affess value to IP string, store in ipstr
    inet_ntop(AF_INET, &nHostAddress, ipstr, sizeof ipstr);
    // print the result
    printf("%d result: %s\n", nHostAddress, ipstr);

    return 0;
}