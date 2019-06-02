#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lectureGraphe.h"
#include "afficheGraphe.h"
#include "aStar.h"

int main()
{
  printf(" **************************************************\n");
  printf(" ***** On Passe au Reseau routier americain  ****** \n");
  printf(" **************************************************\n");

  char s[100];
  printf("Saisir le reseau americain souhaite\n");
  scanf("%s", &s);

  printf("On utilise le fichier %s \n", s);

  int i, nbsommet, nbsarcs, d, a;
  T_SOMMET *graphe;
  graphe = creerSommet();

  nbsarcs = nombre_arcs(s);
  nbsommet = nombre_sommets(s);
  printf("On affiche le nombre de sommets et d'arcs\n");
  printf(" NBA = %d , NBS = %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe(s);
  printf("Votre trajet ?\n");
  printf("Il faudra choisir entre 0 et %d\n", nbsommet);

  do
  {
    printf("Depart de \n");
    scanf("%d", &d);
  } while ((d <= 0) || (d >= nbsommet));

  do
  {
    printf("Arriver a \n");
    scanf("%d", &a);
  } while (a <= d || a >= nbsommet);

  int *path = pathfinder(d, a, graphe, nbsommet);

  printf("Affichons le chemin\n");
  afficheChemin(d, a, path);
  return 0;
}