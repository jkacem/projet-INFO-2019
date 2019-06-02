#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lectureGraphe.h"
#include "afficheGraphe.h"
#include "aStar.h"

int main()
{
  printf(" *******************************************\n");
  printf(" ***** On verifie l'algorithme ASTAR  ****** \n");
  printf(" *******************************************\n");
  printf("On commence le test pour 'graphe2.txt' \n");

  int i, nbsommet, d, a;
  T_SOMMET *graphe;
  graphe = creerSommet();

  printf("On commence par afficher les sommets de notre fichier\n");
  nbsommet = nombre_sommets("graphe2.txt");
  graphe = lectureGraphe("graphe2.txt");
  for (i = 0; i < nbsommet; i++)
  {
    afficheSommet(graphe, i);
    printf(" \n");
  }
  printf("Il faudra choisir entre 0 et 13\n");

  do
  {
    printf("Depart de \n");
    scanf("%d", &d);
  } while ((d <= 0) || (d >= 13));

  do
  {
    printf("Arriver a \n");
    scanf("%d", &a);
  } while (a <= d || a >= 13);

  int *path = pathfinder(d, a, graphe, nbsommet);
  printf("On affiche le tableau des peres trouve\n");
  for (i = 0; i < nbsommet; i++)
  {
    printf("pere[%d] = %d\n", i, path[i]);
  }
  printf("\n");

  printf("Affichons le chemin\n");
  afficheChemin(d, a, path);
  return 0;
}
