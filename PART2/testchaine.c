#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
  double tmp;
  double a = 2.0;
  double n = 3.0;
  tmp = sqrtf((a * a) + (n * n));

  printf("%lf", tmp);
}