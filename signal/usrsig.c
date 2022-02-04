#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("\nReceived SIGINT, quitting ... \n");
        exit(0);
    } else if (signo == SIGUSR1) {
        printf("\n Someone is knocking. \n");
    }
}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        printf("\nError: Can't catch SIGINT\n");
        return -1;
    }
    if (signal(SIGUSR1, sig_handler) == SIG_ERR) {
        printf("\nError: Can't catch SIGINT\n");
        return -1;
    }
    // A long long wait so that we can easily issue a signal to this process
    while(1) {}
    return 0;
}
