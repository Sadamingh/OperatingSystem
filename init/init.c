#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *a, *b;
    b = malloc(sizeof(char));
    *b = 'a';
    a = b;
    printf("%c", *a);
    return 0;
}