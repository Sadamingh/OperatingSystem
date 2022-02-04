#include <stdio.h>
#include <string.h>

int main(void) {
    char path[200] = "/path/to/file.pdf\r\n\r\n";
    printf("%s", path);
    sscanf(path, "%[^\r]", path);
    printf("%s", path);

    return 0;
}