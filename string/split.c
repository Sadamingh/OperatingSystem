/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="GETFILE GET /path/to/file.pdf\r\n\r\n";
  char * pch;
  pch = strtok (str," ");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }
  return 0;
}