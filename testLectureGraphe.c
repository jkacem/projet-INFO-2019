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
  if (file_name == "graphe2.txt")
  {
    if (tmp == 14)
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
  if (file_name == "graphe2.txt")
  {
    if (tmp == 29)
    {
      return 1;
    }
    else
      return 0;
  }
}

int main()
{
  printf(" ********************************************\n");
  printf(" ***** On verifie la lecture du Graphe ****** \n");
  printf(" ********************************************\n");
  printf("On commence le test pour 'graphe2.txt' \n");

  int i;
  char *T1[14] = {"Sommet 1", "Sommet 2", "Sommet 3", "Sommet 4", "Sommet 5", "Sommet 6", "Sommet 7", "Sommet 8", "Sommet 9", "Sommet 10", "Sommet 11", "Sommet 12", "Sommet 13", "Sommet 14"};
  //printf("T[0]='%s' de lenght = %d \n", T1[0], strlen(T1[0]));
  char *nomline = "M1";
  char nomstation[512];
  int compt = 0;

  int voisins1[14] = {2, 1, 1, 3, 2, 3, 3, 2, 1, 4, 2, 1, 3, 1};
  printf("\n");
  if (testnbsommet("graphetest.txt") && testnbarcs("graphetest.txt"))
  {
    printf("Le nombre de sommets et d'arcs est correct\n");
    printf("\n");
  }
  T_SOMMET *graphe;
  graphe = lectureGraphe("graphe2.txt");
  //printf("LA longeur de graphe[0].nomstation est = %d\n", strlen(graphe[0].nomstation));

  for (i = 0; i < 14; i++)
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

  if (compt == 14)
  {
    printf("\n");
    printf("La lecture de tout le graphe est correcte :D\n");
  }
  printf("Fin du test \n");
  return 0;
}