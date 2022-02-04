#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];
    strcpy(str1, "Hello world");
    printf("%s\n", str1);
    strcpy(str2, str1);
    printf("%s\n", str2);

    char *str3, *str4;
    str3 = "Hello world";
    printf("%s\n", str3);
    str4 = str3;
    printf("%s\n", str4);

    return 0;
}