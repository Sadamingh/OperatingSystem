#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned long numblocks = 0;

fd = open("./a.txt", O_RDONLY);
ioctl()