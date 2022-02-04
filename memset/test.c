#include <stdio.h>
#include <string.h>

struct Test {
    int a, b;
};  

int main () {
    struct Test test;
    printf("%p: a = %d, b = %d\n", &test, test.a, test.b);

    // initialize a structure
    test.a = 10001;
    test.b = 20002;

    // print structure info
    printf("%p: a = %d, b = %d\n", &test, test.a, test.b);

    // clear all the initialized values
    memset(&test, 0, sizeof test);

    // print structure info
    printf("%p: a = %d, b = %d\n", &test, test.a, test.b);
   
    return(0);
}