#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lecture.h"
#include "affiche.h"
/*
----------------------------------------------------------------
JEDOUI Kacem                                      2018/2019

                  ****** PROJET INFO 2019 ******
-----------------------------------------------------------------
*/

void main()
{
  int i, nbarc, nbsommet;
  T_SOMMET *graphe;
  nbarc = nombre_arcs("graphe1.txt");
  nbsommet = nombre_sommets("graphe1.txt");
  printf("le nombre d'arcs est %d et le nombre de sommets est %d\n", nbarc, nbsommet);
  graphe = alloueGraphe(nbsommet);
  printf("1\n");
  graphe = lectureGraphe("graphe1.txt");
  printf("2\n");
  for (i; i < nbsommet; i++)
  {
    printf("Le sommet %d\n", i);
    afficheNomline(graphe, i);
    afficheNumline(graphe, i);
    afficheVoisins(graphe, i);
  }
}
