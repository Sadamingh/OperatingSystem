#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 20

int main(void) {
    /* Local variables */
    int fd;                            // file descripter
    char buffer[BUF_SIZE];             // message buffer
    char *message = "Hello World!";    // message

    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // open the file

    strcpy(buffer, message);             // copy the string to buffer
    write(fd, buffer, strlen(buffer));   // write to the file from buffer
    
    return 0;
}