#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#define FIFO_FILE "/tmp/myfifo"
  
int main() 
{ 
    int fd; 
    char str[80];
    char *data; 
  
    mkfifo(FIFO_FILE, DEFFILEMODE); 
    printf("Named pipe established! ============== \n");

    fd = open(FIFO_FILE, O_RDONLY); 
    read(fd, str, 80); 
    printf("Server: %s", str); 
    close(fd); 

    fd = open(FIFO_FILE, O_WRONLY); 
    data = "Hello Server\n";
    printf("Client: send %s\n", data);
    write(fd, data, strlen(data)+1); 
    close(fd); 
  
    return 0; 
} 