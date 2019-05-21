#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
T_SOMMET *creerSommet()
{
  return NULL;
}

int nombre_arcs(const char *file_name)
{
  int nb_sommets, nb_arcs;
  FILE *f;
  f = fopen(file_name, "r");
  if (f != NULL)
  {
    fseek(f, 0, SEEK_SET);
    fscanf(f, " %d %d ", &nb_sommets, &nb_arcs);
  }
  fclose(f);
  return nb_arcs;
}

int nombre_sommets(const char *file_name)
{
  int nb_sommets, nb_arcs;
  FILE *f;
  f = fopen(file_name, "r");
  if (f != NULL)
  {
    fseek(f, 0, SEEK_SET);
    fscanf(f, " %d %d ", &nb_sommets, &nb_arcs);
  }
  fclose(f);

  return nb_sommets;
}

L_ARC ajoutListeArc(L_ARC larc, int a, double c)
{
  L_ARC p = calloc(1, sizeof(*p));
  if (p != NULL)
  {
    p->val.arrivee = a;
    p->val.cout = c;
    p->suiv = larc;
  }
  return p;
}
/*
int estVide(T_SOMMET *l)
{
  return !l;
}
*/
T_SOMMET *alloueGraphe(int n)
{
  T_SOMMET *t = creerSommet();
  t = calloc(n, sizeof(*t));
  return t;
}

T_SOMMET ajoutSommet(int num, char *nom)
{
  T_SOMMET tmp;
  tmp.nomline = nom;
  tmp.numero = num;
  tmp.voisins = NULL;
  return tmp;
}
T_SOMMET *initGraphe(int n)
{
  int i;
  T_SOMMET *tmp;
  for (i; i < n; i++)
  {
    strcpy(tmp[i].nomline, "");
    tmp[i].numero = 0;
    tmp[i].voisins = NULL;
  }
  return tmp;
}

T_SOMMET *lectureGraphe(const char *file_name)
{
  int i, j;
  int depart, arrivee;
  int numero;
  char nomligne[512];
  char nomstation[512];
  double cout, x, y;
  T_SOMMET *graphe;
  FILE *f;
  char mot[512];

  int nbsommet, nbarc;

  f = fopen(file_name, "r");
  if (f == NULL)
  {
    printf("Impossible d’ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }

  fgets(mot, 511, f);
  sscanf(mot, "%d %d", &nbsommet, &nbarc);
  graphe = alloueGraphe(nbsommet);
  strcpy(nomligne, "");
  strcpy(nomstation, "");
  fgets(mot, 511, f); //Sauter la ligne "Sommet"
  for (i = 0; i < nbsommet; i++)
  {
    fgets(mot, 511, f);

    sscanf(mot, "%d %lf %lf %s %[^n]", &numero, &x, &y, nomligne, nomstation);

    graphe[i].nomline = nomligne;
    graphe[i].nomstation = strdup(nomstation);
    //printf("graphe[%d].nomline = %s\n", i, graphe[i].nomline);
    graphe[i].numero = numero;
    graphe[i].x = x;
    graphe[i].y = y;
  }

  fgets(mot, 511, f); //Sauter la ligne "Sommet"

  for (j = 0; j < nbarc; j++)
  {
    fgets(mot, 511, f);
    if (sscanf(mot, "%d %d %lf", &depart, &arrivee, &cout) == 3)
    {
      graphe[depart].voisins = ajoutListeArc(graphe[depart].voisins, arrivee, cout);
    }
    else
    {
      graphe[depart].voisins = NULL;
    }
  }
  fclose(f);

  return graphe;
}
/*
int main()
{
  printf("Hello main()\n");
  T_SOMMET *graphe = creerSommet();

  int nbsommet, nbsarcs, k;
  nbsarcs = nombre_arcs("graphetest.txt");
  nbsommet = nombre_sommets("graphetest.txt");
  printf("%d , %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphetest.txt");
  printf("\n Apres la lecture\n");
  for (k = 0; k < nbsommet; k++)
  {
    printf("graphe[%d].nomline= %s \n", k, graphe[k].nomline);
    printf("graphe[%d].nomstation = %s\n", k, graphe[k].nomstation);
    printf("graphe[%d].x = %lf\n", k, graphe[k].x);
    printf("graphe[%d].y = %lf\n", k, graphe[k].y);
    printf("\n");
  }
  printf("\n");
  return (0);
}
*/