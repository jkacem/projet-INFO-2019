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

T_SOMMET *alloueGraphe(int n)
{
  T_SOMMET *t = creerSommet();
  if ((t = calloc(n, sizeof(*t))) == NULL)
    return NULL;
  else
  {
    return t;
  }
}

T_SOMMET ajoutSommet(int num, char *nom)
{
  T_SOMMET tmp;
  tmp.nomline = nom;
  tmp.numero = num;
  tmp.voisins = NULL;
  return tmp;
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

  f = fopen(file_name, "r+");
  if (f == NULL)
  {
    printf("Impossible d’ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }

  fgets(mot, 511, f);
  sscanf(mot, "%d %d", &nbsommet, &nbarc);
  graphe = alloueGraphe(nbsommet);

  fgets(mot, 511, f); //Sauter la ligne "Sommet"

  for (int i = 0; i < nbsommet; i++)
  {
    //printf("Dans la fonction alloueGraphe\n");
    fgets(mot, 511, f);
    if (mot[strlen(nomline) - 1] < 32)
      mot[strlen(nomline) - 1] = 0;
    sscanf(mot, "%d %[^\n]", &numero, nomline);
    //fgetc(stdin);
    graphe[i].nomline = nomline;
    //printf("graphe[%d].nomline = %s\n", i, graphe[i].nomline);
    //fflush(stdout);
    graphe[i].numero = numero;
    //printf("graphe[%d].numero = %d\n", i, graphe[i].numero);
    //fflush(stdout);
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
  fclose(f);
  //printf("\n");

  //printf("voisins.arrivee= %d voisins.cout= %.2lf\n", graphe[i].voisins->val.arrivee, graphe[i].voisins->val.cout);

  return graphe;
}

int main()
{
  printf("Hello main()\n");
  T_SOMMET *graphe = creerSommet();

  int nbsommet, nbsarcs;
  nbsarcs = nombre_arcs("graphe2.txt");
  nbsommet = nombre_sommets("graphe2.txt");
  printf("%d , %d\n", nbsarcs, nbsommet);
  graphe = lectureGraphe("graphe2.txt");
  printf("\n Apres la lecture\n");
  for (int k = 0; k < nbsommet; k++)
  {
    printf("graphe[%d].nomline= %s \n", k, graphe[k].nomline);
    printf("graphe[%d].numero = %d\n", k, graphe[k].numero);
    printf("\n");
  }
  printf("\n");
  return (0);
}
