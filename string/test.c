#include <stdio.h>
#include <string.h>
#include <unistd.h>

int hi () {
    char str[80] = "This is - www.runoob.com - website";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(str, "\r\n\r\n");
    printf("%s\n", token);

    return(0);
}


int main(void) {
    char pBuffer[200] = "GETFILE OK 3456\r\n\r\nsafsdfdsgfdgfgfdghfd";
    
    char *scheme, *status, *length, *marker, *content, *header;
    char *p;

    header = strtok(pBuffer, "\r\n\r\n");
    printf("0: %s\n", header);
    content = strtok(NULL, "\r\n\r\n");
    printf("5: %s\n", content);
    scheme = strtok(header, " ");
    printf("1: %s\n", scheme);
    status = strtok(NULL, " ");
    printf("2: %s\n", status);
    length = strtok(NULL, "\r");
    printf("3: %s\n", length);
    marker = strtok(NULL, "\r\n");
    printf("4: %s\n", marker);
    header = strtok(pBuffer, "\r\n\r\n");
    printf("0: %s\n", header);

    hi();

    return 0;
}
 
