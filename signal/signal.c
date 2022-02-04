#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("\nReceived SIGINT, quitting ... \n");
    exit(0);
}

int main(void)
{
  if (signal(SIGINT, sig_handler) == SIG_ERR) {
      printf("\nERROR: Can't catch SIGINT\n");
      return -1;
  }
  // A long long wait so that we can easily issue a signal to this process
  while(1) {}
  return 0;
}
