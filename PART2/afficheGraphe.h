#ifndef _affiche
#define _affiche
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void afficheArc(T_ARC arc);
int estVide(L_ARC l);
int nbVoisins(T_SOMMET *tmp, int n);
void afficheVoisins(T_SOMMET *tmp, int n);
void afficheNomline(T_SOMMET *tmp, int n);
void afficheNumline(T_SOMMET *tmp, int n);

#endif
