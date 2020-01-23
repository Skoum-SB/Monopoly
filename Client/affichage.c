#include "monopoly.h"

void afficherPlateau(plateau jeu, info infoJeu){
	system("clear");
	printf("┏━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┓\n");
	printf("┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃\n",afficherPion(jeu, infoJeu, 0, 0),afficherPion(jeu, infoJeu, 0, 1),afficherPion(jeu, infoJeu, 0, 2),afficherPion(jeu, infoJeu, 1, 0),afficherPion(jeu, infoJeu, 1, 1),afficherPion(jeu, infoJeu, 1, 2),afficherPion(jeu, infoJeu, 2, 0),afficherPion(jeu, infoJeu, 2, 1),afficherPion(jeu, infoJeu, 2, 2),afficherPion(jeu, infoJeu, 3, 0),afficherPion(jeu, infoJeu, 3, 1),afficherPion(jeu, infoJeu, 3, 2),afficherPion(jeu, infoJeu, 4, 0),afficherPion(jeu, infoJeu, 4, 1),afficherPion(jeu, infoJeu, 4, 2),afficherPion(jeu, infoJeu, 5, 0),afficherPion(jeu, infoJeu, 5, 1),afficherPion(jeu, infoJeu, 5, 2),afficherPion(jeu, infoJeu, 6, 0),afficherPion(jeu, infoJeu, 6, 1),afficherPion(jeu, infoJeu, 6, 2),afficherPion(jeu, infoJeu, 7, 0),afficherPion(jeu, infoJeu, 7, 1),afficherPion(jeu, infoJeu, 7, 2),afficherPion(jeu, infoJeu, 8, 0),afficherPion(jeu, infoJeu, 8, 1),afficherPion(jeu, infoJeu, 8, 2),afficherPion(jeu, infoJeu, 9, 0),afficherPion(jeu, infoJeu, 9, 1),afficherPion(jeu, infoJeu, 9, 2),afficherPion(jeu, infoJeu, 10, 0),afficherPion(jeu, infoJeu, 10, 1),afficherPion(jeu, infoJeu, 10, 2));
	printf("┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃\n",afficherPion(jeu, infoJeu, 0, 3),afficherPion(jeu, infoJeu, 0, 4),afficherPion(jeu, infoJeu, 0, 5),afficherPion(jeu, infoJeu, 1, 3),afficherPion(jeu, infoJeu, 1, 4),afficherPion(jeu, infoJeu, 1, 5),afficherPion(jeu, infoJeu, 2, 3),afficherPion(jeu, infoJeu, 2, 4),afficherPion(jeu, infoJeu, 2, 5),afficherPion(jeu, infoJeu, 3, 3),afficherPion(jeu, infoJeu, 3, 4),afficherPion(jeu, infoJeu, 3, 5),afficherPion(jeu, infoJeu, 4, 3),afficherPion(jeu, infoJeu, 4, 4),afficherPion(jeu, infoJeu, 4, 5),afficherPion(jeu, infoJeu, 5, 3),afficherPion(jeu, infoJeu, 5, 4),afficherPion(jeu, infoJeu, 5, 5),afficherPion(jeu, infoJeu, 6, 3),afficherPion(jeu, infoJeu, 6, 4),afficherPion(jeu, infoJeu, 6, 5),afficherPion(jeu, infoJeu, 7, 3),afficherPion(jeu, infoJeu, 7, 4),afficherPion(jeu, infoJeu, 7, 5),afficherPion(jeu, infoJeu, 8, 3),afficherPion(jeu, infoJeu, 8, 4),afficherPion(jeu, infoJeu, 8, 5),afficherPion(jeu, infoJeu, 9, 3),afficherPion(jeu, infoJeu, 9, 4),afficherPion(jeu, infoJeu, 9, 5),afficherPion(jeu, infoJeu, 10, 3),afficherPion(jeu, infoJeu, 10, 4),afficherPion(jeu, infoJeu, 10, 5));
	printf("┃DEPART ┃\033[100m   1   \033[0m┃   ?   ┃\033[100m   2   \033[0m┃ IMPOT ┃\033[40m   1   \033[0m┃\033[106m   1   \033[0m┃   ?   ┃\033[106m   2   \033[0m┃\033[106m   3   \033[0m┃TP     ┃\n");
	printf("┣━━━━━━━╋━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━╋━━━━━━━┫\n");
	printf("┃ %c %c \033[44m  \033[0m┃",afficherPion(jeu, infoJeu, 39, 0),afficherPion(jeu, infoJeu, 39, 1));afficherNomJoueur(jeu, infoJeu, 1); printf("                                   ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 11, 0),afficherPion(jeu, infoJeu, 11, 1));
	printf("┃ %c %c \033[44m 2\033[0m┃",afficherPion(jeu, infoJeu, 39, 2),afficherPion(jeu, infoJeu, 39, 3));afficherNomJoueur(jeu, infoJeu, 2); printf("                                   ┃\033[105m1 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 11, 2),afficherPion(jeu, infoJeu, 11, 3));
	printf("┃ %c %c \033[44m  \033[0m┃",afficherPion(jeu, infoJeu, 39, 4),afficherPion(jeu, infoJeu, 39, 5));afficherNomJoueur(jeu, infoJeu, 3); printf("                                   ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 11, 4),afficherPion(jeu, infoJeu, 11, 5));
	printf("┣━━━━━━━┫");afficherNomJoueur(jeu, infoJeu, 4); printf("                                   ┣━━━━━━━┫\n");
	printf("┃ %c %c  T┃",afficherPion(jeu, infoJeu, 38, 0),afficherPion(jeu, infoJeu, 38, 1));afficherNomJoueur(jeu, infoJeu, 5); printf("                                   ┃   %c %c ┃\n",afficherPion(jeu, infoJeu, 12, 0),afficherPion(jeu, infoJeu, 12, 1));
	printf("┃ %c %c  D┃",afficherPion(jeu, infoJeu, 38, 2),afficherPion(jeu, infoJeu, 38, 3));afficherNomJoueur(jeu, infoJeu, 6); printf("                                   ┃1  %c %c ┃\n",afficherPion(jeu, infoJeu, 12, 2),afficherPion(jeu, infoJeu, 12, 3));
	printf("┃ %c %c  L┃      ┏━━━┓   ┏━━━┓                                                    ┃   %c %c ┃\n",afficherPion(jeu, infoJeu, 38, 4),afficherPion(jeu, infoJeu, 38, 5),afficherPion(jeu, infoJeu, 12, 4),afficherPion(jeu, infoJeu, 12, 5));
	printf("┣━━━━━━━┫Dés : ┃ %d ┃ + ┃ %d ┃     Tour N°%4d (Joueur %d)                         ┣━━━━━━━┫\n", jeu.de1, jeu.de2, jeu.tour, jeu.tourj);
	printf("┃ %c %c \033[44m  \033[0m┃      ┗━━━┛   ┗━━━┛                                                    ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 37, 0),afficherPion(jeu, infoJeu, 37, 1),afficherPion(jeu, infoJeu, 13, 0),afficherPion(jeu, infoJeu, 13, 1));
	printf("┃ %c %c \033[44m 1\033[0m┃                                                                       ┃\033[105m2 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 37, 2),afficherPion(jeu, infoJeu, 37, 3),afficherPion(jeu, infoJeu, 13, 2),afficherPion(jeu, infoJeu, 13, 3));
	printf("┃ %c %c \033[44m  \033[0m┃",afficherPion(jeu, infoJeu, 37, 4),afficherPion(jeu, infoJeu, 37, 5));afficherProp(jeu, infoJeu, 0);printf("        ");afficherProp(jeu, infoJeu, 17);printf("             ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 13, 4),afficherPion(jeu, infoJeu, 13, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 1);printf("        ");afficherProp(jeu, infoJeu, 18);printf("             ┣━━━━━━━┫\n");
	printf("┃ %c %c   ┃                                 ",afficherPion(jeu, infoJeu, 36, 0),afficherPion(jeu, infoJeu, 36, 1));afficherProp(jeu, infoJeu, 19);printf("             ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 14, 0),afficherPion(jeu, infoJeu, 14, 1));
	printf("┃ %c %c  ?┃",afficherPion(jeu, infoJeu, 36, 2),afficherPion(jeu, infoJeu, 36, 3));afficherProp(jeu, infoJeu, 2);printf("                                              ┃\033[105m3 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 14, 2),afficherPion(jeu, infoJeu, 14, 3));
	printf("┃ %c %c   ┃",afficherPion(jeu, infoJeu, 36, 4),afficherPion(jeu, infoJeu, 36, 5));afficherProp(jeu, infoJeu, 3);printf("        ");afficherProp(jeu, infoJeu, 20);printf("             ┃\033[105m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 14, 4),afficherPion(jeu, infoJeu, 14, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 4);printf("        ");afficherProp(jeu, infoJeu, 21);printf("             ┣━━━━━━━┫\n");
	printf("┃ %c %c \033[40m  \033[0m┃                                                                       ┃\033[40m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 35, 0),afficherPion(jeu, infoJeu, 35, 1),afficherPion(jeu, infoJeu, 15, 0),afficherPion(jeu, infoJeu, 15, 1));
	printf("┃ %c %c \033[40m 4\033[0m┃",afficherPion(jeu, infoJeu, 35, 2),afficherPion(jeu, infoJeu, 35, 3));afficherProp(jeu, infoJeu, 5);printf("        ");afficherProp(jeu, infoJeu, 22);printf("             ┃\033[40m2 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 15, 2),afficherPion(jeu, infoJeu, 15, 3));
	printf("┃ %c %c \033[40m  \033[0m┃",afficherPion(jeu, infoJeu, 35, 4),afficherPion(jeu, infoJeu, 35, 5));afficherProp(jeu, infoJeu, 6);printf("        ");afficherProp(jeu, infoJeu, 23);printf("             ┃\033[40m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 15, 4),afficherPion(jeu, infoJeu, 15, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 7);printf("        ");afficherProp(jeu, infoJeu, 24);printf("             ┣━━━━━━━┫\n");
	printf("┃ %c %c \033[42m  \033[0m┃                                 ",afficherPion(jeu, infoJeu, 34, 0),afficherPion(jeu, infoJeu, 34, 1));afficherProp(jeu, infoJeu, 25);printf("             ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 16, 0),afficherPion(jeu, infoJeu, 16, 1));
	printf("┃ %c %c \033[42m 3\033[0m┃",afficherPion(jeu, infoJeu, 34, 2),afficherPion(jeu, infoJeu, 34, 3));afficherProp(jeu, infoJeu, 8);printf("                                              ┃\033[43m1 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 16, 2),afficherPion(jeu, infoJeu, 16, 3));
	printf("┃ %c %c \033[42m  \033[0m┃",afficherPion(jeu, infoJeu, 34, 4),afficherPion(jeu, infoJeu, 34, 5));afficherProp(jeu, infoJeu, 9);printf("        ");afficherProp(jeu, infoJeu, 26);printf("             ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 16, 4),afficherPion(jeu, infoJeu, 16, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 10);printf("        ");afficherProp(jeu, infoJeu, 27);printf("             ┣━━━━━━━┫\n");
	printf("┃ %c %c   ┃                                                                       ┃   %c %c ┃\n",afficherPion(jeu, infoJeu, 33, 0),afficherPion(jeu, infoJeu, 33, 1),afficherPion(jeu, infoJeu, 17, 0),afficherPion(jeu, infoJeu, 17, 1));
	printf("┃ %c %c  ?┃",afficherPion(jeu, infoJeu, 33, 2),afficherPion(jeu, infoJeu, 33, 3));afficherProp(jeu, infoJeu, 11);printf("                                              ┃?  %c %c ┃\n",afficherPion(jeu, infoJeu, 17, 2),afficherPion(jeu, infoJeu, 17, 3));
	printf("┃ %c %c   ┃",afficherPion(jeu, infoJeu, 33, 4),afficherPion(jeu, infoJeu, 33, 5));afficherProp(jeu, infoJeu, 12);printf("                                              ┃   %c %c ┃\n",afficherPion(jeu, infoJeu, 17, 4),afficherPion(jeu, infoJeu, 17, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 13);printf("                                              ┣━━━━━━━┫\n");
	printf("┃ %c %c \033[42m  \033[0m┃                                                                       ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 32, 0),afficherPion(jeu, infoJeu, 32, 1),afficherPion(jeu, infoJeu, 18, 0),afficherPion(jeu, infoJeu, 18, 1));
	printf("┃ %c %c \033[42m 2\033[0m┃",afficherPion(jeu, infoJeu, 32, 2),afficherPion(jeu, infoJeu, 32, 3));afficherProp(jeu, infoJeu, 14);printf("                                              ┃\033[43m2 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 18, 2),afficherPion(jeu, infoJeu, 18, 3));
	printf("┃ %c %c \033[42m  \033[0m┃",afficherPion(jeu, infoJeu, 32, 4),afficherPion(jeu, infoJeu, 32, 5));afficherProp(jeu, infoJeu, 15);printf("                                              ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 18, 4),afficherPion(jeu, infoJeu, 18, 5));
	printf("┣━━━━━━━┫");afficherProp(jeu, infoJeu, 16);printf("                                              ┣━━━━━━━┫\n");
	printf("┃ %c %c \033[42m  \033[0m┃                                                                       ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 31, 0),afficherPion(jeu, infoJeu, 31, 1),afficherPion(jeu, infoJeu, 19, 0),afficherPion(jeu, infoJeu, 19, 1));
	printf("┃ %c %c \033[42m 1\033[0m┃                                                                       ┃\033[43m3 \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 31, 2),afficherPion(jeu, infoJeu, 31, 3),afficherPion(jeu, infoJeu, 19, 2),afficherPion(jeu, infoJeu, 19, 3));
	printf("┃ %c %c \033[42m  \033[0m┃                                                                       ┃\033[43m  \033[0m %c %c ┃\n",afficherPion(jeu, infoJeu, 31, 4),afficherPion(jeu, infoJeu, 31, 5),afficherPion(jeu, infoJeu, 19, 4),afficherPion(jeu, infoJeu, 19, 5));
	printf("┣━━━━━━━╋━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━╋━━━━━━━┫\n");
	printf("┃     TP┃\033[103m   3   \033[0m┃   2   ┃\033[103m   2   \033[0m┃\033[103m   1   \033[0m┃\033[40m   3   \033[0m┃\033[41m   3   \033[0m┃\033[41m   2   \033[0m┃   ?   ┃\033[41m   1   \033[0m┃PARC   ┃\n");
	printf("┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃\n",afficherPion(jeu, infoJeu, 30, 0),afficherPion(jeu, infoJeu, 30, 1),afficherPion(jeu, infoJeu, 30, 2),afficherPion(jeu, infoJeu, 29, 0),afficherPion(jeu, infoJeu, 29, 1),afficherPion(jeu, infoJeu, 29, 2),afficherPion(jeu, infoJeu, 28, 0),afficherPion(jeu, infoJeu, 28, 1),afficherPion(jeu, infoJeu, 28, 2),afficherPion(jeu, infoJeu, 27, 0),afficherPion(jeu, infoJeu, 27, 1),afficherPion(jeu, infoJeu, 27, 2),afficherPion(jeu, infoJeu, 26, 0),afficherPion(jeu, infoJeu, 26, 1),afficherPion(jeu, infoJeu, 26, 2),afficherPion(jeu, infoJeu, 25, 0),afficherPion(jeu, infoJeu, 25, 1),afficherPion(jeu, infoJeu, 25, 2),afficherPion(jeu, infoJeu, 24, 0),afficherPion(jeu, infoJeu, 24, 1),afficherPion(jeu, infoJeu, 24, 2),afficherPion(jeu, infoJeu, 23, 0),afficherPion(jeu, infoJeu, 23, 1),afficherPion(jeu, infoJeu, 23, 2),afficherPion(jeu, infoJeu, 22, 0),afficherPion(jeu, infoJeu, 22, 1),afficherPion(jeu, infoJeu, 22, 2),afficherPion(jeu, infoJeu, 21, 0),afficherPion(jeu, infoJeu, 21, 1),afficherPion(jeu, infoJeu, 21, 2),afficherPion(jeu, infoJeu, 20, 0),afficherPion(jeu, infoJeu, 20, 1),afficherPion(jeu, infoJeu, 20, 2));
	printf("┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃ %c %c %c ┃\n",afficherPion(jeu, infoJeu, 30, 3),afficherPion(jeu, infoJeu, 30, 4),afficherPion(jeu, infoJeu, 30, 5),afficherPion(jeu, infoJeu, 29, 3),afficherPion(jeu, infoJeu, 29, 4),afficherPion(jeu, infoJeu, 29, 5),afficherPion(jeu, infoJeu, 28, 3),afficherPion(jeu, infoJeu, 28, 4),afficherPion(jeu, infoJeu, 28, 5),afficherPion(jeu, infoJeu, 27, 3),afficherPion(jeu, infoJeu, 27, 4),afficherPion(jeu, infoJeu, 27, 5),afficherPion(jeu, infoJeu, 26, 3),afficherPion(jeu, infoJeu, 26, 4),afficherPion(jeu, infoJeu, 26, 5),afficherPion(jeu, infoJeu, 25, 3),afficherPion(jeu, infoJeu, 25, 4),afficherPion(jeu, infoJeu, 25, 5),afficherPion(jeu, infoJeu, 24, 3),afficherPion(jeu, infoJeu, 24, 4),afficherPion(jeu, infoJeu, 24, 5),afficherPion(jeu, infoJeu, 23, 3),afficherPion(jeu, infoJeu, 23, 4),afficherPion(jeu, infoJeu, 23, 5),afficherPion(jeu, infoJeu, 22, 3),afficherPion(jeu, infoJeu, 22, 4),afficherPion(jeu, infoJeu, 22, 5),afficherPion(jeu, infoJeu, 21, 3),afficherPion(jeu, infoJeu, 21, 4),afficherPion(jeu, infoJeu, 21, 5),afficherPion(jeu, infoJeu, 20, 3),afficherPion(jeu, infoJeu, 20, 4),afficherPion(jeu, infoJeu, 20, 5));
	printf("┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┛\n");
}

void afficherNomJoueur(plateau jeu, info infoJeu, int nJoueur){
	if(nJoueur <= infoJeu.nbJoueurs){
		printf("Joueur %d : %s", nJoueur, infoJeu.nomJoueur[nJoueur - 1]);
		int l = 16 - strlen(infoJeu.nomJoueur[nJoueur - 1]);
		while(l > 0){
			printf(" ");
			l--;
		}
		printf(": %4d k€",jeu.argentJoueur[nJoueur - 1]);
	}
	else{
		printf("                                    ");
	}
	return;
}

void afficherProp(plateau jeu, info infoJeu, int nprop){
	switch(nprop){
		case 0://grise
		printf(" \033[100m1\033[0m : ");
		break;
		case 1:
		printf(" \033[100m2\033[0m : ");
		break;
		case 2://cyan
		printf(" \033[106m1\033[0m : ");
		break;
		case 3:
		printf(" \033[106m2\033[0m : ");
		break;
		case 4:
		printf(" \033[106m3\033[0m : ");
		break;
		case 5://rose
		printf(" \033[105m1\033[0m : ");
		break;
		case 6:
		printf(" \033[105m2\033[0m : ");
		break;
		case 7:
		printf(" \033[105m3\033[0m : ");
		break;
		case 8://orange
		printf(" \033[43m1\033[0m : ");
		break;
		case 9:
		printf(" \033[43m2\033[0m : ");
		break;
		case 10:
		printf(" \033[43m3\033[0m : ");
		break;
		case 11://rouge
		printf(" \033[41m1\033[0m : ");
		break;
		case 12:
		printf(" \033[41m2\033[0m : ");
		break;
		case 13:
		printf(" \033[41m3\033[0m : ");
		break;
		case 14://jaune
		printf(" \033[103m1\033[0m : ");
		break;
		case 15:
		printf(" \033[103m2\033[0m : ");
		break;
		case 16:
		printf(" \033[103m3\033[0m : ");
		break;
		case 17://vert
		printf(" \033[42m1\033[0m : ");
		break;
		case 18:
		printf(" \033[42m2\033[0m : ");
		break;
		case 19:
		printf(" \033[42m3\033[0m : ");
		break;
		case 20://bleu
		printf(" \033[44m1\033[0m : ");
		break;
		case 21:
		printf(" \033[44m2\033[0m : ");
		break;
		case 22://noir
		printf(" \033[40m1\033[0m : ");
		break;
		case 23:
		printf(" \033[40m2\033[0m : ");
		break;
		case 24:
		printf(" \033[40m3\033[0m : ");
		break;
		case 25:
		printf(" \033[40m4\033[0m : ");
		break;
		case 26://rien
		printf(" 1 : ");
		break;
		case 27:
		printf(" 2 : ");
		break;
	}

	switch(jeu.terrains[nprop].proprietaire){
		case 0:
		printf("                ");
		break;
		default:
		printf("%s",infoJeu.nomJoueur[jeu.terrains[nprop].proprietaire - 1]);
		for(int i = strlen(infoJeu.nomJoueur[jeu.terrains[nprop].proprietaire - 1]); i < 16 ; i++)
			printf(" ");
		break;
	}

	switch(jeu.terrains[nprop].constructions){
		case 5:
		printf(" / H");
		break;
		default:
		printf(" / %d",jeu.terrains[nprop].constructions);
		break;
	}
}

char afficherPion(plateau jeu, info infoJeu, int c, int j){
	if(j >= infoJeu.nbJoueurs)
		return ' ';
	if((jeu.posJoueur[j] == c))
		return j + '1';
	else
		return ' ';
}