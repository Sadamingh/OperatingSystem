#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int (*p)(int, int) = add;
    printf("%p: %d\n", add, add(2, 3));
    printf("%p: %d\n", p, p(4, 3));
    return 0;
}