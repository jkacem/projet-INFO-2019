#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#include "lectureGraphe.h"
#include "afficheGraphe.h"

int main()
{
  printf(" ***** Hello main() ****** \n");
  printf(" \n");

  T_SOMMET *graphe;
  int nbsommet, nbsarcs, i;

  graphe = creerSommet();

  nbsarcs = nombre_arcs("graphetest.txt");
  nbsommet = nombre_sommets("graphetest.txt");
  printf(" NBA = %d , NBS = %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphetest.txt");
  printf("\n ***** On affiche le graphe ***** \n");
  printf(" \n");

  for (i = 0; i < nbsommet; i++)
  {
    afficheSommet(graphe, i);
    printf(" \n");
  }

  return (0);
}