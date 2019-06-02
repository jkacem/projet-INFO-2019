#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#include "lectureGraphe.h"
#include "afficheGraphe.h"

int main()
{
  printf(" *********************************************\n");
  printf(" ***** On verifie l'affichage du Graphe ****** \n");
  printf(" *********************************************\n");
  printf("On commence le test pour 'graphe2.txt' \n");

  printf(" \n");

  T_SOMMET *graphe;
  int nbsommet, nbsarcs, i;
  //int *path;
  graphe = creerSommet();
  nbsarcs = nombre_arcs("graphe2.txt");
  nbsommet = nombre_sommets("graphe2.txt");
  printf("On affiche le nombre de sommets et d'arcs\n");
  printf(" NBA = %d , NBS = %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphe2.txt");
  printf("\n ***** On affiche le graphe ***** \n");
  printf(" \n");

  for (i = 0; i < nbsommet; i++)
  {
    afficheSommet(graphe, i);
    printf(" \n");
  }

  printf("CHECK ENDED\n");

  return 0;
}
