#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
  char *chaine1[3] = {"M1", "M1", "M1"};
  char *chaine2 = "M1";

  int res;
  for (int i = 0; i < 3; i++)
  {
    res = strcmp(chaine1[i], chaine2);
    if (res == 0)
    {
      printf("{%d} Les deux chaines sont indentiques\n", i);
    }
  }
}