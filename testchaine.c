#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  char ch1[8] = "Bonjour";
  char ch2[8];

  strcpy(ch2, "");
  printf("ch2 = %s\n", ch2);
  strcpy(ch2, ch1);
  printf("ch2 = %s", ch2);
}