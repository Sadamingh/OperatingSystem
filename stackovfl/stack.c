#include <stdio.h>

void function(char *buf) {
	printf("%s\n", buf);
}

int main() {

	char buf[4];
	scanf("%s", buf);
	function(buf);
	
	return 0;
}