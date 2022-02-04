#include <stdio.h>

int foo1(int a, int b) {
    return a > b;
}

int foo2(int a, int b) {
    return a < b;
}

int func(int a, int b, int (*p)(int, int)) {
    return p(a, b)?(a - b):(a + b);
}

int main(void) {
    printf("%d\n", func(1, 2, foo1));
    printf("%d\n", func(1, 2, foo2));
    return 0;
}