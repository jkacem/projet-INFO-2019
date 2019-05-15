#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "structure.h"
#include "lectureGraphe.h"
#include "afficheGraphe.h"

int testnbsommet(const char *file_name)
{
  int tmp;
  tmp = nombre_sommets(file_name);
  if (file_name == "graphe2.txt")
  {
    if (tmp == 19)
    {
      return 1;
    }
    else
      return 0;
  }
  else if (file_name == "graphe1.txt")
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
  if (file_name == "graphe2.txt")
  {
    if (tmp == 29)
    {
      return 1;
    }
    else
      return 0;
  }
  else if (file_name == "graphe1.txt")
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
  char *T1[8] = {"Aaa", "Baa", "Caa", "Daa", "Eaa", "Faa", "Gaa", "Haa"};
  int voisins1[8] = {3, 3, 2, 0, 2, 0, 1, 1};
  printf("On commence le test pour graphe1.txt\n");
  if (testnbsommet("grpahe1.txt") && testnbarcs("graphe1.txt"))
  {
    printf("Le nombre de sommets et d'arcs est correct\n");
    T_SOMMET *graphe;
    graphe = lectureGraphe("graphe1.txt");

    for (int i = 0; i < 8; i++)
    {
      if (graphe[i].numero == i)
      {
        printf("Le numero du sommet %d est correct\n", i);
        if (graphe[i].nomline == T1[i])
        {
          printf("graphe[%d].nomline est correct\n", i);
                }
        else
        {
          printf("probleme avec graphe[%d].nomline\n");
          if (nbVoisins(graphe, i) == voisins1[i])
          {
            printf("le nombre des voisins pour le sommet %d est correct\n", i);
          }
          else
          {
            printf("probleme avec le nombre des voisins pour le sommet %d\n", i);
          }
        }
      }
      else
      {
        printf("Probleme avec le numéro du sommet %d \n", i);
      }
    }
  }
  else
  {
    printf("Probleme avec les nombres d'arcs et de sommets\n");
  }
}