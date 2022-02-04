#include <stdio.h>

int main(void) {
    
    // set the file pointer
    FILE *fp;
    // open the file
    fp = fopen("test.txt", "w+");

    // write by fprintf
    fprintf(fp, "Hello World!\n");
    // write by fputs
    fputs("Hello World!\n", fp);
    // write by fputc
    fputc(65, fp);

    return 0;
}