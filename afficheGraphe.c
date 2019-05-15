#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lectureGraphe.h"

void afficheArc(T_ARC arc)
{
  printf(" arrivee = %d && cout = %.2lf\n", arc.arrivee, arc.cout);
}

int estVide(L_ARC l)
{
  return l == NULL;
}

int nbVoisins(T_SOMMET *tmp, int n)
{
  int count = 0;
  L_ARC p = NULL;
  p = tmp[n].voisins;
  while (!estVide(p))
  {
    count++;
    p = p->suiv;
  }
  return count;
}

void afficheVoisins(T_SOMMET *tmp, int n)
{
  L_ARC p = NULL;
  p = tmp[n].voisins;
  printf("Pour ce sommet on a %d voisins \n", nbVoisins(tmp, n));
  while (!estVide(p))
  {
    afficheArc(p->val);
    p = p->suiv;
  }
}

void afficheNomline(T_SOMMET *tmp, int n)
{
  printf("Le nom de la ligne %s \n", tmp[n].nomline);
}
void afficheNumline(T_SOMMET *tmp, int n)
{
  printf("le numero de la ligne = %d\n", tmp[n].numero);
}

void main()
{
  int nbsommets;
  T_SOMMET *graphe;
  nbsommets = nombre_sommets("graphe2.txt");
  graphe = lectureGraphe("graphe2.txt");
  for (int i = 0; i < nbsommets; i++)
  {
    afficheNomline(graphe, i);
    afficheNumline(graphe, i);
    afficheVoisins(graphe, i);
  }
}

/*
#ifndef _structure
#define _structure
//Les sommets : T_SOMMET est une structure

//Les arcs : un arc est une structure

typedef struct
{
  int arrivee;
  double cout;
} T_ARC;

//Les listes de successeurs : une liste classique avec un suivant, la valeur est un arc.
typedef struct lsucc
{
  T_ARC val;
  struct lsucc *suiv;
} * L_ARC;

typedef struct
{
  char *nomline;
  int numero;
  L_ARC voisins;
} T_SOMMET;

#endif
*/