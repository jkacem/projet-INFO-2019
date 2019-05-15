#ifndef _lecture
#define _lecture
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int nombre_arcs(const char *file_name);
int nombre_sommets(const char *file_name);
L_ARC ajoutListeArc(L_ARC larc, int a, double c);
T_SOMMET ajoutSommet(T_SOMMET *tmp, int i, int num, char *nom);
T_SOMMET *alloueGraphe(int n);
T_SOMMET *initGraphe(int i, T_SOMMET *tsom);
T_SOMMET *lectureGraphe(const char *file_name);

#endif