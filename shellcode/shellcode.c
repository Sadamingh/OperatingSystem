#include <stdio.h>
#include <unistd.h>

int main() {
	char *sh = "/bin/sh";
	char *argv[] = {sh, NULL};
	char *envp[] = {NULL};
	execve(sh, argv, envp);
	return 0;
}