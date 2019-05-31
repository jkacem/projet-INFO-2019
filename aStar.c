#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"

int estVideListe(L_SOMMET l)
{
	return l == NULL;
}

L_SOMMET ajoutTete(L_SOMMET l, int k)
{
	L_SOMMET p;
	if ((p = (L_SOMMET)calloc(1, sizeof(*p))) == NULL)
		return NULL;
	if (l != estVideListe(l))
	{
		p->val = k;
		p->suiv = l;
	}
	p->val = k;
	return p;
}

L_SOMMET creerListe(void)
{
	return NULL;
}

int rechercheElement(L_SOMMET l, int s)
{
	L_SOMMET p = l;
	while ((p != estVideListe(p)) && (p->val != s))
	{
		p = p->suiv;
	}
	if (!estVideListe(p))
		return 1;
	return 0;
}

/*

ajout � T_SOMMET :(( T_sommet.lf=1 c�d S est ds la liste ferm�e)) 
et ((T_sommet.indiceLO indice du sommet dans le tas(liste ouverte)))
T_sommet.indiceLO initialis� � -1 pour tous les sommets*
LO est un tas: changer les fct du tas tq le min est indice 0
lf est une liste, ajouter definition liste (visualiser liste/ 
recherche_element resultat booleen)
h re�oit les numeros de sommet 

//creer liste L_ARC
// fct recherche si le sommet est dans le tableau de sommet
*/
//#define INFINITY 99999

double heuristique(int s1, int s2, T_SOMMET *graphe)
{
	double h;
	double x1 = graphe[s1].x;
	double x2 = graphe[s2].x;
	double y1 = graphe[s1].y;
	double y2 = graphe[s2].y;
	h = (abs(x1 - x2) + abs(y1 - y2)) / 5;
	return (h);
}

// a et d numero de sommets demand�s � l'utilisateur

int minListe(double *f, L_SOMMET l)
{
	int min = l->val;
	L_SOMMET p;
	for (p = l->suiv; !estVideListe(l); p = p->suiv)
	{
		if (f[p->val] < min)
		{
			min = f[p->val];
		}
	}
	return min;
}
int *initTableauPeres(int *T, int nbsommet)
{
	int i;
	for (i = 0; i < nbsommet; i++)
	{
		T[i] = -1;
	}
}

L_SOMMET supprimerElement(L_SOMMET l, int s)
{
	L_SOMMET p = l, c;

	while ((!estVideListe(p)) && (p->suiv->val != s))
	{
		p = p->suiv;
	}
	c = p->suiv;
	p->suiv = p->suiv->suiv;
	free(c);
	return l;
}

void afficheChemin(int d, int a, int *pere)
{
	int i = a;
	while (i != d)
	{
		printf("pere %d = %d", i, pere[i]);
		i = pere[i];
	}
}
int *pathfinder(int d, int a, T_SOMMET *graphe, int nbsommet)
{
	int k, s, i;
	double g[nbsommet], f[nbsommet], h[nbsommet];
	L_ARC p;
	int *pere;
	L_SOMMET LO, LF; //liste initialisation -1
	int tlf = 0;
	pere = initTableauPeres(pere, nbsommet);
	//fct ajout elt dans une liste
	//fct verifie que l'element n'est pas dans le tableau LF :int verifElement(int s, int* LF, int tlf)

	LO = calloc(1, sizeof(*LO));
	LF = calloc(1, sizeof(*LO));

	//Initialisation
	g[d] = 0;
	h[d] = heuristique(d, a, graphe);
	f[d] = g[d] + h[d];
	for (k = 0; (k < nbsommet) && (k != d); k++)
	{

		g[k] = INFINITY;
		h[k] = INFINITY;
		f[k] = INFINITY;
	}

	LO = ajoutTete(LO, d);
	LF = creerListe();
	k = d;

	while ((!estVideListe(LO)) && (k != a))
	{
		k = minListe(f, LO);

		if (k == a)
		{
			printf("on a atteint l'arriv�e, et on a trouv� le plus court chemin: %lf", f[a]);
			//visualiser_liste(LF);
		}
		else
		{
			LF = ajoutTete(LF, k);
			for (p = graphe[k].voisins; p != NULL; p = p->suiv)
			{
				s = p->val.arrivee;
				if (rechercheElement(LF, s) == 0)
				{
					if (rechercheElement(LO, s) == 0)
					{
						pere[s] = k;
						g[s] = g[k] + p->val.cout;
						h[s] = heuristique(s, a, graphe);
						f[s] = g[s] + h[s];
						LO = ajoutTete(LO, s);
					}

					else
					{
						if ((g[k] + p->val.cout) < g[s])
						{
							pere[s] = k;
							g[s] = g[k] + p->val.cout;
							LO = supprimerElement(LO, s);
							h[s] = heuristique(s, a, graphe);
							f[s] = g[s] + h[s];
							LO = ajoutTete(LO, s);
						}
					}
				}
			}
		}
		return pere;
	}
}
