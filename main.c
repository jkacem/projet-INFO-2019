#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lecture.h"
/*
JEDOUI Kacem 
2018/2019
PROJET INFO 2019
*/
void main()
{
  int i, nbarc, nbsommet;
  T_SOMMET *graphe;
  nbarc = nombre_arcs("graphe1.txt");
  nbsommet = nombre_sommets("graphe1.txt");
  printf("le nombre d'arcs est %d et le nombre de sommets est %d\n", nbarc, nbsommet);
  graphe = alloueGraphe(nbsommet);
  graphe = lectureGraphe("graphe1.txt");
  for (i = 0; i < nbsommet; i++)
  {
    printf("nomline = %s\n", graphe[i].nomline);

    if (graphe[i].voisins != NULL)
    {
      printf("arrivee = %d cout = %lf\n", graphe[i].voisins->val.arrivee, graphe[i].voisins->val.cout);
    }
  }
}