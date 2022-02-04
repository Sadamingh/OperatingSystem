#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    printf("hello");
    printf("%lu", strlen("hello"));
    return 0;
}