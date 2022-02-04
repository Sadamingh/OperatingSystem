#include <stdio.h>
#include <string.h>
#define BUFSIZE 630

int main(void) {
    char *scheme, *method, *path, *marker;
    char *token;
    char buffer[BUFSIZE] = "GETFILE GET /path/to/file.pdf\r\n\r\n";
    char markbuffer[BUFSIZE];
    printf("%s\n", buffer);
    
    strcpy(markbuffer, buffer);
    scheme = strtok(buffer, " ");
    method = strtok(NULL, " ");
    path = strtok(NULL, " ");
    token = strtok(markbuffer, "/");
    marker = strtok(NULL, " ");
    
    sscanf(path, "%[^\r]", path);
    printf("%p\n", marker);
    marker = marker + 2*sizeof(path);
    printf("%p\n", marker);

    printf("1: %s\n", scheme);
    printf("2: %s\n", method);
    printf("3: %s\n", path);
    printf("4: %s", marker);

    printf("%lu", sizeof(path));

    printf("%d", strcmp("a", "a"));

    return 0;
}