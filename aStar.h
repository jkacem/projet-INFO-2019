#ifndef _aStar
#define _aStar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int estVideListe(L_SOMMET l);
L_SOMMET ajoutTete(L_SOMMET l, int k);
L_SOMMET creerListe(void);
void afficheListe(L_SOMMET l);
int rechercheElement(L_SOMMET l, int s);
double heuristique(int s1, int s2, T_SOMMET *graphe);
int minListe(double *f, L_SOMMET l);
int *initTableauPeres(int *T, int nbsommet);
L_SOMMET supprimerElement(L_SOMMET l, int s);
int *pathfinder(int d, int a, T_SOMMET *graphe, int nbsommet);
void afficheChemin(int d, int a, int *pere);

#endif
