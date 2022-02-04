#include <stdio.h>

typedef int (*fp)(int, int);

int foo(int a, int b) {
    return a > b;
}

fp func() {
    return foo;
}

int main(void) {
    printf("%p\n", foo);
    printf("%p\n", func());
    
    return 0;
}