#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 3

int main(void) {
    /* local variables */
    char buffer[BUF_SIZE];         // create a buffer
    int fd;                        // file descriptor

    fd = open("test.txt", O_RDONLY);       // open the file

    while (read(fd, buffer, BUF_SIZE) > 0) {
        printf("%s", buffer);        // print the buffer     
    }
    printf("\n");
    
    return 0;
}