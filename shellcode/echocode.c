#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	// for exception handling
	if (!(argc == 2)) {
		printf("The `echo` command must have 1 argument.\nUsage:\n\t./echocode argument\n");
		return -1;
	}
	// actual program
	char *sh = "/bin/echo";
	char *_argv[] = {sh, argv[1], NULL};
	char *envp[] = {NULL};
	execve(sh, _argv, envp);
	return 0;
}