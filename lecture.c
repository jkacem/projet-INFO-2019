#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

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

T_SOMMET initGraphe(int i, T_SOMMET *tsom)
{
  tsom[i].numero = i;
  tsom[i].nomline = "\0";
  tsom[i].voisins = NULL;
  return tsom[i];
}

T_SOMMET *alloueGraphe(int n)
{
  T_SOMMET *t = NULL;
  if ((t = calloc(n, sizeof(*t))) == NULL)
    return NULL;
  else
    return t;
}

T_SOMMET ajoutSommet(T_SOMMET *tmp, int i, int num, char *nom)
{
  tmp[i] = initGraphe(i, tmp);
  tmp[i].nomline = nom;
  tmp[i].numero = num;
  return tmp[i];
}

T_SOMMET *lectureGraphe(const char *file_name)
{
  int depart, arrivee;
  int numero;
  char nomline[128];
  double cout;
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

  fgets(mot, 511, f); //Sauter la ligne "Sommet"

  graphe = alloueGraphe(nbsommet);

  for (int i = 0; i < nbsommet; i++)
  {
    fgets(mot, 511, f);
    sscanf(mot, "%d %s", &numero, nomline);
    graphe[i] = ajoutSommet(graphe, i, numero, nomline);
    printf("nomline = %s && numero = %d\n", graphe[i].nomline, graphe[i].numero);
  }
  fgets(mot, 511, f); //Sauter la ligne "Sommet"

  for (int j = 0; j < nbarc; j++)
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
  for (int l = 0; l < nbsommet; l++)
  {
    printf(" [APRES//] nomline = %s && numero = %d\n", graphe[l].nomline, graphe[l].numero);

    if (graphe[l].voisins != NULL)
    {
      printf("arrivee = %d cout = %.2lf\n", graphe[l].voisins->val.arrivee, graphe[l].voisins->val.cout);
    }
  }

  fclose(f);
  return graphe;
}

void main()
{
  T_SOMMET *graphe;
  int nbsommet;
  nbsommet = nombre_sommets("graphe1.txt");
  graphe = alloueGraphe(nbsommet);
  graphe = lectureGraphe("graphe1.txt");
}
