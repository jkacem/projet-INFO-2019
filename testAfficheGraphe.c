#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "lectureGraphe.h"
#include "afficheGraphe.h"

int testnbsommet(const char *file_name)
{
  int tmp;
  tmp = nombre_sommets(file_name);
  if (file_name == "graphetest.txt")
  {
    if (tmp == 8)
    {
      return 1;
    }
    else
      return 0;
  }
}

int testnbarcs(const char *file_name)
{
  int tmp;
  tmp = nombre_arcs(file_name);
  if (file_name == "graphetest.txt")
  {
    if (tmp == 12)
    {
      return 1;
    }
    else
      return 0;
  }
}

int main()
{
  char *T1[8] = {"Aaaa 1", "Baaa 2", "Caaa 3", "Daaa 4", "Eaaa 5", "Faaa 6", "Gaaa 7", "Haaa 8"};
  //printf("T[0]='%s' de lenght = %d \n", T1[0], strlen(T1[0]));
  char *nomline = "M1";
  char nomstation[512];
  int compt = 0;

  int voisins1[8] = {3, 3, 2, 0, 2, 0, 1, 1};
  printf("On commence le test pour 'grapheest.txt' \n");
  printf("\n");
  if (testnbsommet("grpahetest.txt") && testnbarcs("graphetest.txt"))
  {
    printf("Le nombre de sommets et d'arcs est correct\n");
    printf("\n");
  }
  T_SOMMET *graphe;
  graphe = lectureGraphe("graphetest.txt");
  //printf("LA longeur de graphe[0].nomstation est = %d\n", strlen(graphe[0].nomstation));

  for (int i = 0; i < 8; i++)
  {
    //afficheNomline(graphe, i);
    //afficheNomStation(graphe, i);
    strcpy(nomstation, graphe[i].nomstation);
    int retnomline = strcmp(graphe[i].nomline, nomline);
    int retnomstation = strncmp(nomstation, T1[i], 6);
    //printf("{%d}'%s'\n", i, nomstation);
    //printf("{%d} retnomline = %d && retnomstation= %d \n", i, retnomline, retnomstation);
    if ((graphe[i].numero == i) && (retnomline == 0) && (retnomstation == 0) && (nbVoisins(graphe, i) == voisins1[i]))
    {
      printf(" Lecture du sommet %d OK \n", i);
      compt++;
    }

    else
    {
      printf("Il y'a un probleme pour la lecture du Sommet {%d}\n", i);
      if (graphe[i].numero != i)
        printf(" WARNING numéro du sommet %d \n");
      if (retnomline != 0)
        printf("WARNING nomLine \n");
      if (retnomstation != 0)
        printf("WARNING nomStation \n");
      if (nbVoisins(graphe, i) != voisins1[i])
        printf("WARNING nbVoisisn\n");
      printf("\n");
    }
  }

  if (compt == 8)
  {
    printf("\n");
    printf("La lecture de tout le graphe est correcte :D\n");
  }
  printf("Fin du test \n");
  return 0;
}