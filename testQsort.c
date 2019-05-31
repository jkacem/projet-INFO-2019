#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "astar.h"
int compare(const void *a, const void *b)
{
  /* definir des pointeurs type's et initialise's
      avec les parametres */

  return *(int *)a - *(int *)b;
}

void afficheListe2019(L_SOMMET l)
{
  while (!estVideListe(l))
  {
    printf("%d\n", l->val);
  }
}
int main()
{
  L_SOMMET l = (L_SOMMET)calloc(1, sizeof(*l));
  L_SOMMET p;
  for (int i = 0; i < 5; i++)
  {
    printf("Sasir l->val\n");
    scanf("%d", &(l->val));
    l->suiv = calloc(1, sizeof(*l));
    l = l->suiv;
  }
  l->suiv = NULL;
  afficheListe2019(l);
  /*
  qsort(t, 5, sizeof(int), compare);
  printf("Apres tri\n");
  for (int k = 0; k < 5; k++)
  {
    printf("t[%d] = %d\n", k, t[k]);
  }
  */
  return 0;
}