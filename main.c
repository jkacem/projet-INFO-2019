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
  int d = 0;
  int a = 5;
  printf("le depart = %d && arrivee = %d\n", d, a);
  T_SOMMET *graphe;
  int nbsommet, nbsarcs, i;
  int *path;
  graphe = creerSommet();
  nbsarcs = nombre_arcs("graphetest.txt");
  nbsommet = nombre_sommets("graphetest.txt");
  printf(" NBA = %d , NBS = %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphetest.txt");

  path = pathfinder(d, a, graphe, nbsommet);
  //afficheChemin(d, a, path);

  for (i = 0; i < nbsommet; i++)
  {
    printf("pere[%d] = %d\n", i, path[i]);
  }

  printf("Affichons le chemin\n");
  afficheChemin(d, a, path);
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
