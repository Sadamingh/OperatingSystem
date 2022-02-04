#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#define FIFO_FILE "/tmp/myfifo"
#define CONN_OK "Connected!\n"
  
int main() 
{ 
    int fd; 
    char data[80]; 
  
    mkfifo(FIFO_FILE, DEFFILEMODE); 
    printf("Named pipe established! ============== \n");

    fd = open(FIFO_FILE, O_WRONLY); 
    printf("Server: send %s", CONN_OK);
    write(fd, CONN_OK, strlen(CONN_OK)+1); 
    close(fd); 

    fd = open(FIFO_FILE, O_RDONLY); 
    read(fd,data, sizeof(data)); 
    printf("Client: %s\n", data); 
    close(fd); 
  
    return 0; 
} 