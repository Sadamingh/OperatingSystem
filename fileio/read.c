#include <stdio.h>

int main(void) {
    
    // set the file pointer
    FILE *fp;
    // create a buffer
    char buff[255];

    // open the file
    fp = fopen("test.txt", "r+");

    // get the first character
    printf("%c\n", fgetc(fp));

    // get the first string
    fgets(buff, 255, fp);
    printf("%s", buff);

    // get the second string
    fgets(buff, 255, fp);
    printf("%s", buff);

    // get the third string
    fgets(buff, 255, fp);
    printf("%s\n", buff);

    fclose(fp);

    return 0;
}