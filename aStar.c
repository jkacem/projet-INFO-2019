#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"

int estVideListe(L_SOMMET l)
{
	return !l;
}
/*
L_SOMMET ajout_somm_ordre(int id, L_SOMMET l, double *vals)
{ // liste (d'indices) l sera en ordre croissant en fonction des valeurs associées dans vals
	L_SOMMET p = NULL;
	p = l;
	if (lsomm_vide(l) || vals[l->val] > vals[id])
	{ // si id est la nouvelle tete de liste
		l = ajout_somm_tete(id, l);
	}
	else
	{
		while (!lsomm_vide(p->suiv) && vals[p->suiv->val] <= vals[id])
		{ // on verifie d'abord que p->suiv n'est pas nul
			p = p->suiv;
		} // a la fin on a soit vals[p->suiv->val] > vals[id] soit p en queue de liste
		L_SOMMET e = creer_lsomm();
		e = ajout_somm_tete(id, p->suiv);
		p->suiv = e;
	}
	return l;
}
*/
L_SOMMET ajoutTete(L_SOMMET l, int k)
{
	L_SOMMET p;
	if ((p = (L_SOMMET)calloc(1, sizeof(*p))) == NULL)
		return NULL;

	p->val = k;
	p->suiv = l;
	return p;
}

L_SOMMET creerListe(void)
{
	return NULL;
}

int rechercheElement(L_SOMMET l, int s)
{
	L_SOMMET p = l;
	while ((!estVideListe(p)) && (p->val != s))
	{
		p = p->suiv;
	}
	if (!estVideListe(p))
		return 1;
	return 0;
}

double heuristique(int s1, int s2, T_SOMMET *graphe)
{
	double h;
	double x1 = graphe[s1].x;
	double x2 = graphe[s2].x;
	double y1 = graphe[s1].y;
	double y2 = graphe[s2].y;
	h = (fabs(x1 - x2) + fabs(y1 - y2)) / 5.0;
	return (h);
}

int minListe(double *f, L_SOMMET l)
{
	if (estVideListe(l))
		return 0;

	int min = l->val;
	//printf("Dans minListe : min = %d \n", min);
	L_SOMMET p;
	for (p = l->suiv; !estVideListe(p); p = p->suiv)
	{
		if (f[p->val] < f[min])
		{
			min = p->val;
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
	return T;
}
L_SOMMET supprimerElement(L_SOMMET l, int s)
{
	L_SOMMET n, prec;
	if (!estVideListe(l))
	{
		if (l->val == s)
		{
			n = l;
			l = l->suiv;
			free(n);
		}
		else
		{
			prec = l;
			n = l->suiv;
			while (!estVideListe(n))
			{
				if (n->val == s)
				{
					prec->suiv = n->suiv;
					free(n);
					break;
				}
				prec = n;
				n = n->suiv;
			}
		}
	}
	return l;
}
/*
L_SOMMET supprimerElement(L_SOMMET l, int s)
{
	L_SOMMET p, c;

	if (estVideListe(l)) // S'il y'a un element dans la liste ==> on n'a pas de p->suiv !!
		return NULL;

	if ((l->val != s))
	{
		c = l;
		l = l->suiv;
		free(c);
		return l;
	}
	for (p = l; !estVideListe(p) && !estVideListe(p->suiv) && (c->val != s); p = p->suiv)
		;

	c = p->suiv;
	p->suiv = c ? c->suiv : NULL;
	free(c);
	return l;
}
*/

void afficheListe(L_SOMMET l)
{
	L_SOMMET p;
	int i = 0;
	if (estVideListe(l))
	{
		printf("La liste est vide\n");
	}
	else
	{
		for (p = l; !estVideListe(p); p = p->suiv)
		{
			printf("liste[%d] = %d\n", i, p->val);
			i++;
		}
	}
}
void afficheChemin(int d, int a, int *pere)
{
	printf("On part de %d\n", d);
	int i = a;
	while (i != d)
	{
		printf("\tOn passe par %d \n", i);
		i = pere[i];
	}
	printf("Pour atteindre %d\n", a);
}
int *pathfinder(int d, int a, T_SOMMET *graphe, int nbsommet)
{
	int k, s, i, w, jk;
	double *g = NULL, *f = NULL, *h = NULL;
	L_ARC p;
	int *pere = NULL;
	L_SOMMET LO, LF; //liste initialisation -1

	//int tlf = 0;
	g = calloc(nbsommet, sizeof(*g));
	f = calloc(nbsommet, sizeof(*f));
	h = calloc(nbsommet, sizeof(*h));
	pere = calloc(nbsommet, sizeof(*pere));
	pere = initTableauPeres(pere, nbsommet);
	//fct ajout elt dans une liste
	//fct verifie que l'element n'est pas dans le tableau LF :int verifElement(int s, int* LF, int tlf)
	LO = calloc(1, sizeof(*LO));
	LF = calloc(1, sizeof(*LF));
	LO = creerListe();
	LF = creerListe();

	//Initialisation
	g[d] = 0;
	h[d] = heuristique(d, a, graphe);
	//printf("h[%d] = %lf\n", d, h[d]);
	f[d] = g[d] + h[d];
	for (jk = 0; jk < nbsommet; jk++)
	{
		if (jk != d)
		{
			g[jk] = INFINITY;
			h[jk] = INFINITY;
			f[jk] = INFINITY;
		}
	}
	/*
	for (w = 0; w < nbsommet; w++)
	{
		printf("F[%d] = %lf\n", w, f[w]);
	}
	*/
	//pere[d] = d;

	LO = ajoutTete(LO, d);
	printf("ajout tete de LO \n");
	afficheListe(LO);
	k = d;
	int kjb = 0;
	while ((!estVideListe(LO)) && (k != a))
	{
		kjb++;
		k = minListe(f, LO);
		printf("k apres minListe = %d\n", k);
		if (k == a)
		{
			printf("on a atteint l'arrivee, et on a trouve le plus court chemin FIN \n");
		}
		else
		{
			LF = ajoutTete(LF, k);
			printf("ajout tete de LF\n");
			afficheListe(LF);
			LO = supprimerElement(LO, k);
			printf("LO supprime\n");
			afficheListe(LO);
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
						printf("Apres l'ajout des voisins dans LO \n");
						afficheListe(LO);
					}

					else
					{
						if ((g[k] + p->val.cout) < g[s])
						{
							pere[s] = k;
							g[s] = g[k] + p->val.cout;
							LO = supprimerElement(LO, s);
							printf("Apres suppression de l'element dans LO\n");

							afficheListe(LO);
							h[s] = heuristique(s, a, graphe);
							f[s] = g[s] + h[s];
							LO = ajoutTete(LO, s);
							printf("Apres l'ajout de l'element dans LO\n");
							afficheListe(LO);
						}
					}
				}
			}
		}
	}
	free(g);
	free(f);
	free(h);
	return pere;
}
