#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 20

int main(void) {
    /* local variables */
    char buffer[BUF_SIZE];         // create a buffer
    int fd;                        // file descriptor

    fd = open("test.txt", O_RDONLY);       // open the file
    
    read(fd, buffer, BUF_SIZE);    // read from the file to the buffer
    printf("%s\n", buffer);        // print the buffer     
    
    return 0;
}