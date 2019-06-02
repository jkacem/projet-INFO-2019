#ifndef _structure
#define _structure
//Les sommets : T_SOMMET est une structure

//Les arcs : un arc est une structure

typedef struct
{
  int arrivee;
  double cout;
} T_ARC;

//Les listes de successeurs : une liste classique avec un suivant, la valeur est un arc.
typedef struct lsucc
{
  T_ARC val;
  struct lsucc *suiv;
} * L_ARC;

typedef struct
{
  char *nomline;
  char *nomstation;
  int numero;
  double x, y;
  L_ARC voisins;
} T_SOMMET;

typedef struct cell1
{
  int val;
  struct cell1 *suiv;
} * L_SOMMET;

#endif