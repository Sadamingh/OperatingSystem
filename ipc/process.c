#include <stdio.h>
#include <unistd.h>

int main() {

    int pid = fork();
    if (pid == 0) {
        printf("%d: This is the parent process.\n", pid);
    } else {
        printf("%d: This is the child process.\n", pid);
    }

    return 0;
}