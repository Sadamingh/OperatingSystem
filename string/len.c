#include <stdio.h>
#include <string.h>

int main() {
    printf("%ld\n", sizeof("GETFILE OK "));
    printf("%ld\n", sizeof("\r\n\r\n"));
    char* tok1, *tok2, tok3;

    char buf[20] = "abcdefghijklmn";
    tok1 = strtok(buf, "d");
    printf("%s\n", tok1);
    tok2 = strtok(NULL, "j");
    printf("%s\n", tok2);
    tok3 = strtok(NULL, "n");
    printf("%s\n", tok3);
    
    printf("tok1: %ld\n", strlen(tok1));
    printf("tok2: %ld\n", strlen(tok2));

    return 0;
}