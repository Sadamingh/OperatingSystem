/* strstr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="This is a simple string";
  char * pch;
  pch = strstr (str,"simple");
  if (pch != NULL)
    strncpy (pch,"hellow",6);
  puts (str);
  return 0;
}