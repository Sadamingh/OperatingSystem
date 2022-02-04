#include <stdio.h>

int func1(int a, int b) {
    return (a > b)?(a - b):(a + b);
}

int func2(int a, int b) {
    return (a < b)?(a - b):(a + b);
}

int main(void) {
    printf("%d\n", func1(1, 2));
    printf("%d\n", func2(1, 2));
    return 0;
}