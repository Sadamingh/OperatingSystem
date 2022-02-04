#include <stdio.h>
#include <stdlib.h>

typedef struct foo {
    int a[10];
    char b[20];
}foo;

int main(void) {
    foo struct1;
    foo *struct2 = (foo *)malloc(sizeof(foo));

    free(struct2);

    return 0;
}