#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structure.h"
#include "lectureGraphe.h"

#define INFINITY 99999

double heuristique(graphe, int d, int s)
{
  return sqrtf((graphe[d].) + (a * a));
}
double fheuristique(int s, int a)
{
}

int min(T_SOMMET *l, int i)
{
}
void aSearch(T_SOMMET *graphe, int d, int a, int nbs)
{

  double H[nbs];
  double G[nbs];
  double F[nbs];
  T_SOMMET *LO;
  T_SOMMET *LF;

  LO = calloc(1, sizeof(*LO));
  LF = calloc(1, sizeof(*LF));

  H[d] = heuristique(graphe[d].voisins->val.cout, graphe[a].voisins->val.cout);

  G[d] = 0;
  for (int i; i < nbs; i++)
  {
    if (i != d)
    {
      G[i] = INFINITY;
      F[i] = INFINITY;
      H[i] = INFINITY;
    }
  }
  LO->numero = graphe[d].numero;
  LO->nomline = graphe[d].nomline;
  LF = NULL;
  int k = d;

  while (!estVide(LO) && (k != a))
  {
    k = min(LO);
  }
}