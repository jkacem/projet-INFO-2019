#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#include "lectureGraphe.h"
#include "afficheGraphe.h"
#include "aStar.h"

int main()
{
  printf(" ***** Hello main() ****** \n");
  printf(" \n");
  int depart = 1;
  int arrivee = 5;
  printf("le depart = %d && arrivee = %d\n", depart, arrivee);
  T_SOMMET *graphe;
  int nbsommet, nbsarcs, i;
  int *path;
  graphe = creerSommet();
  nbsarcs = nombre_arcs("graphetest.txt");
  nbsommet = nombre_sommets("graphetest.txt");
  printf(" NBA = %d , NBS = %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphetest.txt");

  path = pathfinder(depart, arrivee, graphe, nbsommet);
  for (int i = 0; i < nbsommet; i++)
  {
    printf("pere[%d] = %d\n", i, path[i]);
  }

  // afficheChemin(depart, arrivee, path);
  /*
  printf("\n ***** On affiche le graphe ***** \n");
  printf(" \n");

  for (i = 0; i < nbsommet; i++)
  {
    afficheSommet(graphe, i);
    printf(" \n");
  }
  */
  return 0;
}