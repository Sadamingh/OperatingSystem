#include<stdio.h>
#include<unistd.h>

#define STREAM_SIZE 6

int main() {
    int pipefd[2];
    char readmessage[STREAM_SIZE];

    if (pipe(pipefd) == -1) {
        printf("Unable to create pipe\n");
        return -1;
    }

    int pid = fork();

    // Child process
    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], readmessage, sizeof(readmessage));
        printf("Child Process - Reading from pipe – Message 1 is %s\n", readmessage);
        read(pipefd[0], readmessage, sizeof(readmessage));
        printf("Child Process - Reading from pipe – Message 2 is %s\n", readmessage);
    } else { //Parent process
        close(pipefd[0]);
        printf("Parent Process - Message writing to pipe\n");
        write(pipefd[1], "Hi ", STREAM_SIZE);
        printf("Parent Process - Message writing to pipe\n");
        write(pipefd[1], "Pipe!", STREAM_SIZE);
    }
    return 0;
}
