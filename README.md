#######################################################

# RESOLUTION DU PROBLEME DU PLUS COURT CHEMIN

#######################################################

CE TRAVAIL A ETE ELABORE PAR:
JEDOUI Kacem
SFAR Sarra

#######################################################

    On retrouve ici
      les scripts.c
      un dossier Include contenant tout les fichier d'en-tête
    	un MAKEFILE
    	un Rapport.pdf

########################################################

    Concernant le script de test testLectureGraphe.c :
      Il s'agit d'un test unitaire permettant la verification de la lecture du fichier,
      il vérifie l'ensemble des fonctions réalisées dans lecture.c
      Ici On a utilise graphe2.txt
    pour compiler et excecuter ce fichier (Sans le Makefile)

#gcc testLectureGraphe.c lectureGraphe.c afficheGraphe.c -o testLectureGraphe

##################################################################################

    Concernant le fichier testAfficheGraphe.c :
      Il permet d'afficher les sommets et leurs voisins et vérifier l'ensemble des fonctions réalisées dans affiche.c
    pour compiler et excecuter ce fichier (Sans le Makefile)

#gcc testAfficheGraphe.c lectureGraphe.c afficheGraphe.c -o testAfficheGraphe

#################################################################################

    Concernant le fichier testaStar.c
      C'est le fichier test du script il permet de vérifier les fonctions réalisées dans aStar.c
    pour compiler et excecuter ce fichier (Sans le Makefile)

#gcc testaStar.c lectureGraphe.c afficheGraphe.c aStar.c -o testaStar

#################################################################################

    Concernant le fichier ReseauRoutierAmericain.c
      Il permet d'afficher le chemain entre un point a et un point b saisi au clavier sur un réseau
    Pour compiler et excecuter ce fichier (Sans le Makefile) : il faut vérifier qu'un fichier csv est bien dans le dossier !!

#gcc ReseauRoutierAmerican.c aStar.c lectureGraphe.c afficheGraphe.c -o ReseauRoutierAmericain

###################################################################################

    Concernant le Make:
      il suffit de taper "make" dans le terminal pour compiler tous les fichiers tests.
        voilà un résultat du make qui confirme la compilation:
        {
          gcc -o testAfficheGraphe testAfficheGraphe.o lectureGraphe.o afficheGraphe.o
          gcc -o testLectureGraphe testLectureGraphe.o lectureGraphe.o afficheGraphe.o
          gcc -o testaStar testaStar.o lectureGraphe.o afficheGraphe.o aStar.o

          gcc -c -I Include ReseauRoutierAmericain.c
          gcc -o ReseauRoutierAmericain ReseauRoutierAmericain.o lectureGraphe.o afficheGraphe.o aStar.o
          }

      pour executer:
        ReseauRoutierAmericain : "./ReseauRoutierAmericain"
        testaStar : "./testaStar"
        testAfficheGraphe : "./testAfficheGraphe"
        testLectureGraphe : "./testLectureGraphe"
