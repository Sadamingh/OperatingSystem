#include <stdio.h>
#include <string.h>
#include <unistd.h>

void check(char *pBuffer) {
    if (strstr(pBuffer, "\r\n\r\n")) {
        printf("rnrn flag exists!\n");
    } else {
        printf("NO rnrn flag!\n");
    }
}

int main(void) {
    char pBuffer[200] = "GETFILE OK 3456\r\n\r\nsafsdfdsgfdgfgfdghfd";
    check(pBuffer);
    char pBuffer1[200] = "GETFILE OK ";
    check(pBuffer1);

    return 0;
}
 
