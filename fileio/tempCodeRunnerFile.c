#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 2

int main(void) {
    /* Local variables */
    int fd;                            // file descripter
    char buffer[BUF_SIZE];             // message buffer
    char *message = "Hello World!";    // message
    int message_len = strlen(message);

    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // open the file

    while (BUF_SIZE < message_len+BUF_SIZE) {
        memcpy(buffer, message, BUF_SIZE-1);
        write(fd, buffer, strlen(buffer)); 
        message += BUF_SIZE;
        message_len = strlen(message);
    }
    return 0;
}