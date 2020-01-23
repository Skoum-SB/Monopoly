#include "monopoly.h"

void *jeu(void *sock){
	char buffer[BUF_SIZE];
	int socket = (int)sock;
	int i,j;

	int d;//double

	j = infoJeu.nbJoueurs;
	while(!statut)
	bzero(buffer, BUF_SIZE);
	strcpy(buffer, "INF\0");
	memcpy(buffer + 4, &infoJeu, sizeof(infoJeu));
	if(send(socket, buffer, BUF_SIZE, 0) < 0){
		printf("Error send\n");
	}

	envoyerPlateau(socket);

	for(;statut;){		
		if(plateauJeu.tourj == j){
			d = lancerDes();
			deplacerPion();
			envoyerPlateau(socket);
			tourJeu(1, socket);
			envoyerPlateau(socket);
			while(d == 1){
				d = lancerDes();
				deplacerPion();
				envoyerPlateau(socket);
				tourJeu(1, socket);
				envoyerPlateau(socket);
			}
			finDeTour(1, socket);
			envoyerPlateau(socket);
			tourSuivant();
		}
		else{
			sleep(1);
			envoyerPlateau(socket);
		}
	}

	envoyerPlateau(socket);
	bzero(buffer, BUF_SIZE);
	strcpy(buffer, "FIN\0");
	if(send(socket, buffer, BUF_SIZE, 0) < 0){
		printf("Error send\n");
		exit(1);
	}
}

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

void tourSuivant(){
	if(plateauJeu.tourj == infoJeu.nbJoueurs){
		plateauJeu.tourj = 1;
		plateauJeu.tour++;
	}
	else
		plateauJeu.tourj++;
}

int lancerDes(){//Renvoie 1 en cas de doubles
	int d1, d2;
	d1 = rand() % 6;
	d2 = rand() % 6;
	plateauJeu.de1 = d1 + 1;
	plateauJeu.de2 = d2 + 1;

	if(d1 == d2)
		return 1;
	return 0;
}

void deplacerPion(){
	if((plateauJeu.posJoueur[plateauJeu.tourj - 1] + plateauJeu.de1 + plateauJeu.de2) > 39){
		plateauJeu.posJoueur[plateauJeu.tourj - 1] += plateauJeu.de1 + plateauJeu.de2 - 40;
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] += 200;
	}
	else
		plateauJeu.posJoueur[plateauJeu.tourj - 1] += plateauJeu.de1 + plateauJeu.de2;
}

void tourJeu(int mode, int socket){
	if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 4)//Impots
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= 200;

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 38){//TDL
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= 100;
	}

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 0)//Départ
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] += 200;

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 2 || plateauJeu.posJoueur[plateauJeu.tourj - 1] == 7 || plateauJeu.posJoueur[plateauJeu.tourj - 1] == 17 || plateauJeu.posJoueur[plateauJeu.tourj - 1] == 22 || plateauJeu.posJoueur[plateauJeu.tourj - 1] == 33 || plateauJeu.posJoueur[plateauJeu.tourj - 1] == 36){//Chance
		int r, s;
		r = rand() % 201;
		s = rand() % 2;
		if(s)
			r *= -1;
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] += r;
	}

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 30)//TP
		plateauJeu.posJoueur[plateauJeu.tourj - 1] = 10;

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] == 10)//TP
		plateauJeu.posJoueur[plateauJeu.tourj - 1] = 30;

	else if(plateauJeu.posJoueur[plateauJeu.tourj - 1] != 0 && plateauJeu.posJoueur[plateauJeu.tourj - 1] != 10 && plateauJeu.posJoueur[plateauJeu.tourj - 1] != 20 && plateauJeu.posJoueur[plateauJeu.tourj - 1] != 40){//Propriétés
		int n = posToNumT(plateauJeu.posJoueur[plateauJeu.tourj - 1]);
		if(plateauJeu.terrains[n].proprietaire == 0){//Achat propriété ?
			achat(n, mode, socket);
		}
		else if(plateauJeu.terrains[n].proprietaire != plateauJeu.tourj){//Propriété adverse
			loyer(n);
		}
	}

	while(plateauJeu.argentJoueur[plateauJeu.tourj - 1] < 0){
		dette(mode, socket);
	}
}

int posToNumT(int pos){
	int tab[28] = {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39,5,15,25,35,12,28};
	int i;
	for(i = 0 ; tab[i] != pos ; i++){}
	return i;
}

void achat(int n, int mode, int socket){//0 = serveur, 1 = client
	int prix[28] = {60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400,200,200,200,200,150,150};
	char r;
	char buffer[BUF_SIZE];

	if(mode == 0){
		if(plateauJeu.argentJoueur[plateauJeu.tourj - 1] >= prix[n]){
			printf("Voulez-vous acheter cette propriété pour %d k€ ? (o/n)\n", prix[n]);
			scanf("%c", &r);
			viderBuffer();
			while(r != 'o' && r != 'n'){
				printf("Réponse incorrecte (o/n)");
				scanf("%c", &r);
				viderBuffer();
			}
			if(r == 'o'){
				plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= prix[n];
				plateauJeu.terrains[n].proprietaire = plateauJeu.tourj;
			}
		}
		else{
			printf("Vous n'avez pas assez d'argent pour acheter cette propriété !\n");
		}
	}
	else{
		bzero(buffer, BUF_SIZE);
		strcpy(buffer, "ACH\0");
		if(send(socket, buffer, BUF_SIZE, 0) < 0){
			printf("Error send\n");
			exit(1);
		}

		if(recv(socket, buffer, BUF_SIZE, 0) < 0){
			printf("Error recv\n");
			exit(1);
		}

		if(strcmp("o",buffer) == 0){
			if(plateauJeu.argentJoueur[plateauJeu.tourj - 1] >= prix[n]){
				plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= prix[n];
				plateauJeu.terrains[n].proprietaire = plateauJeu.tourj;
			}
		}
	}
}

void loyer(int n){
	int loyer;
	int d = 0;
	int tab[22][6] = {	{2,10,30,90,160,250},
						{4,20,60,180,320,450},
						{6,30,90,270,400,550},
						{6,30,90,270,400,550},
						{8,40,100,300,450,600},
						{10,50,150,450,625,750},
						{10,50,150,450,625,750},
						{12,60,180,500,700,900},
						{14,70,200,550,700,900},
						{14,70,200,550,700,950},
						{16,80,220,600,800,1000},
						{18,90,250,700,875,1050},
						{18,90,250,700,875,1050},
						{20,100,300,750,925,1100},
						{22,110,330,800,975,1150},
						{22,110,330,800,975,1150},
						{24,120,360,850,1025,1200},
						{26,130,390,900,1100,1275},
						{26,130,390,900,1100,1275},
						{28,150,450,1000,1200,1400},
						{35,175,500,1100,1300,1500},
						{50,200,600,1400,1700,2000}};

	if(n < 22){
		loyer = tab[n][plateauJeu.terrains[n].constructions];
	}

	else if(n < 26){
		loyer = 25;
		if(plateauJeu.terrains[22].proprietaire == plateauJeu.terrains[n].proprietaire)
			loyer *= 2;
		if(plateauJeu.terrains[23].proprietaire == plateauJeu.terrains[n].proprietaire)
			loyer *= 2;
		if(plateauJeu.terrains[24].proprietaire == plateauJeu.terrains[n].proprietaire)
			loyer *= 2;
		if(plateauJeu.terrains[25].proprietaire == plateauJeu.terrains[n].proprietaire)
			loyer *= 2;
		loyer /= 2;
	}

	else{
		if(plateauJeu.terrains[26].proprietaire == plateauJeu.terrains[n].proprietaire)
			d++;
		if(plateauJeu.terrains[27].proprietaire == plateauJeu.terrains[n].proprietaire)
			d++;

		loyer = plateauJeu.de1 + plateauJeu.de2;

		if(d == 1)
			loyer *= 4;
		else
			loyer *= 10;
	}

	plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= loyer;
	plateauJeu.argentJoueur[plateauJeu.terrains[n].proprietaire - 1] += loyer;
}

void envoyerPlateau(int socket){
	char buffer[BUF_SIZE];

	bzero(buffer, BUF_SIZE);
	strcpy(buffer, "PLT\0");
	memcpy(buffer + 4, &plateauJeu, sizeof(plateauJeu));

	if(send(socket, buffer, BUF_SIZE, 0) < 0){
		printf("Error send\n");
		exit(1);
	}
}

void viderBuffer(){
    int c; 
    do{ 
        c = getchar(); 
    }while(c != '\n' && c != EOF);
}

void finDeTour(int mode, int socket){
	char r;
	char buffer[BUF_SIZE];

	if(mode == 0){//Serveur
		for(;;){
			printf("Que souhaitez-vous faire ? (Construire/Vendre/Rien) (C/V/R)\n");
			scanf("%c", &r);
			viderBuffer();
			while(r != 'C' && r != 'V' && r != 'R'){
				printf("Réponse incorrecte (C/V/R)");
				scanf("%c", &r);
				viderBuffer();
			}
			if(r == 'C'){//Construire
				construire(mode, socket, 0, 0);
			}

			else if(r == 'V'){//Vendre
				vendre(mode, socket, 0, 0);
			}

			else
				break;
		}
	}
	else{
		for(;;){
			bzero(buffer, BUF_SIZE);
			strcpy(buffer, "ACT\0");

			if(send(socket, buffer, BUF_SIZE, 0) < 0){
				printf("Error send\n");
				exit(1);
			}

			if(recv(socket, buffer, BUF_SIZE, 0) < 0){
				printf("Error recv\n");
				exit(1);
			}

			if(strcmp("CST",buffer) == 0){
				construire(mode, socket, buffer[4], buffer[8]);
			}

			else if(strcmp("VEN",buffer) == 0){
				vendre(mode, socket, buffer[4], buffer[8]);
			}

			else
				break;
		}
	}
}

void vendre(int mode, int socket, int numT, int ven){
	char g, n, c;
	char buffer[BUF_SIZE];

	if(mode == 0){//Serveur
		printf("Sur quel groupe voulez-vous vendre ? (1 à 8)\n");
		scanf("%c", &g);
		viderBuffer();
		while(g < '1' || g > '8'){
			printf("Réponse incorrecte (1 à 8)");
			scanf("%c", &g);
			viderBuffer();
		}
		if(g == '1' || g == '8'){
			printf("Quelle propriété ? (1 ou 2)\n");
			scanf("%c", &n);
			viderBuffer();
			while(n < '1' || n > '2'){
				printf("Réponse incorrecte (1 ou 2)");
				scanf("%c", &n);
				viderBuffer();
			}
		}

		else{// 2 à 7
			printf("Quelle propriété ? (1 à 3)\n");
			scanf("%c", &n);
			viderBuffer();
			while(n < '1' || n > '3'){
				printf("Réponse incorrecte (1 à 3)");
				scanf("%c", &n);
				viderBuffer();
			}
		}

		numT = convert(g - '1', n - '1');

		if(plateauJeu.terrains[numT].proprietaire != plateauJeu.tourj){
			printf("Vous ne possédez pas ce terrain !\n");
			return;
		}

		if(plateauJeu.terrains[numT].constructions == 0){
			printf("Vous n'avez rien à vendre ici !\n");
			return;
		}

		printf("Combien d'habitations voulez-vous vendre ? (1 à 5)\n");
		scanf("%c", &c);
		viderBuffer();
		while(c < '1' || c > '5'){
			printf("Réponse incorrecte (1 à 5)\n");
			scanf("%c", &c);
			viderBuffer();
		}

		c -= '0';
		printf("%d\n", c);

		if((plateauJeu.terrains[numT].constructions - c ) < 0){
			printf("Vous ne pouvez pas effectuer cette opération !\n");
			return;
		}

		plateauJeu.terrains[numT].constructions -= c;

		if(numT < 5){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += c * 25;
		}

		else if(numT < 11){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += c * 50;
		}

		else if(numT < 17){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += c * 75;
		}

		else{
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += c * 100;
		}

		afficherPlateau(plateauJeu, infoJeu);

	}
	else{//Client

		plateauJeu.terrains[numT].constructions -= ven;

		if(numT < 5){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += ven * 25;
		}

		else if(numT < 11){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += ven * 50;
		}

		else if(numT < 17){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += ven * 75;
		}

		else{
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] += ven * 100;
		}

		envoyerPlateau(socket);
	}
}

int convert(int g, int n){
	int tab[8][3] = {{0,1,0},{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16},{17,18,19},{20,21,0}};
	return tab[g][n];
}

void construire(int mode, int socket, int numT, int cst){
	char g, n, c;
	int prix;

	if(mode == 0){//Serveur
		printf("Sur quel groupe voulez-vous construire ? (1 à 8)\n");
		scanf("%c", &g);
		viderBuffer();
		while(g < '1' || g > '8'){
			printf("Réponse incorrecte (1 à 8)");
			scanf("%c", &g);
			viderBuffer();
		}
		if(g == '1' || g == '8'){
			printf("Quelle propriété ? (1 ou 2)\n");
			scanf("%c", &n);
			viderBuffer();
			while(n < '1' || n > '2'){
				printf("Réponse incorrecte (1 ou 2)");
				scanf("%c", &n);
				viderBuffer();
			}
		}

		else{// 2 à 7
			printf("Quelle propriété ? (1 à 3)\n");
			scanf("%c", &n);
			viderBuffer();
			while(n < '1' || n > '3'){
				printf("Réponse incorrecte (1 à 3)");
				scanf("%c", &n);
				viderBuffer();
			}
		}

		numT = convert(g - '1', n - '1');

		if(plateauJeu.terrains[numT].proprietaire != plateauJeu.tourj){
			printf("Vous ne possédez pas ce terrain !\n");
			return;
		}

		if(plateauJeu.terrains[numT].constructions == 5){
			printf("Vous n'avez rien à construire en plus ici !\n");
			return;
		}

		printf("Combien d'habitations voulez-vous construire ? (1 à 5)\n");
		scanf("%c", &c);
		viderBuffer();
		while(c < '1' || c > '5'){
			printf("Réponse incorrecte (1 à 5)\n");
			scanf("%c", &c);
			viderBuffer();
		}

		c -= '0';

		if((plateauJeu.terrains[numT].constructions + c ) > 5){
			printf("Vous ne pouvez pas effectuer cette opération !\n");
			return;
		}

		if(numT < 5){
			prix = c * 50;
		}

		else if(numT < 11){
			prix = c * 100;
		}

		else if(numT < 17){
			prix = c * 150;
		}

		else{
			prix = c * 200;
		}

		if(plateauJeu.argentJoueur[plateauJeu.tourj - 1] < prix){
			printf("Vous n'avez pas assez d'argent !\n");
			return;
		}

		plateauJeu.terrains[numT].constructions += c;
		plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= prix;
		afficherPlateau(plateauJeu, infoJeu);

	}
	else{//Client

		plateauJeu.terrains[numT].constructions += cst;

		if(numT < 5){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= cst * 50;
		}

		else if(numT < 11){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= cst * 100;
		}

		else if(numT < 17){
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= cst * 150;
		}

		else{
			plateauJeu.argentJoueur[plateauJeu.tourj - 1] -= cst * 200;
		}

		envoyerPlateau(socket);
	}
}

void dette(int mode, int socket){
	char buffer[BUF_SIZE];

	if(mode == 0){
		if(faillite()){
			printf("Vous avez fait faillite !\n");
			statut = 0;
			finDeJeu();
		}
		else{
			printf("Vous êtes endetté, vous devez vendre des habitations !\n");
			vendre(mode, socket, 0, 0);
		}
	}
	else{
		if(faillite()){
			statut = 0;
		}
		
		else{
			bzero(buffer, BUF_SIZE);
			strcpy(buffer, "VEN\0");

			if(send(socket, buffer, BUF_SIZE, 0) < 0){
				printf("Error send\n");
				exit(1);
			}

			if(recv(socket, buffer, BUF_SIZE, 0) < 0){
				printf("Error send\n");
				exit(1);
			}

			vendre(mode, socket, buffer[4], buffer[8]);
		}
	}
}

int faillite(){
	int j = plateauJeu.tourj;
	int i;
	for(i = 0; i < 22 ; i++){
		if(plateauJeu.terrains[i].proprietaire == j && plateauJeu.terrains[i].constructions > 0)
			return 0;
	}
	return 1;
}

void finDeJeu(){
	int prix[28] = {60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400,200,200,200,200,150,150};
	int patrimoine[6];
	int i, j, g, v;

	for(i = 0 ; i < infoJeu.nbJoueurs ; i++){
		patrimoine[i] = plateauJeu.argentJoueur[i];
	}

	for(i = 0 ; i < 6 ; i++){
		for(j = 0 ; j < 28 ; j++){
			if(plateauJeu.terrains[j].proprietaire - 1 == i){
				patrimoine[i] += prix[j];

				if(j < 5){
					patrimoine[i] += 50 * plateauJeu.terrains[j].constructions;
				}

				else if(j < 11){
					patrimoine[i] += 100 * plateauJeu.terrains[j].constructions;
				}

				else if(j < 17){
					patrimoine[i] += 150 * plateauJeu.terrains[j].constructions;
				}

				else if(j < 22){
					patrimoine[i] += 200 * plateauJeu.terrains[j].constructions;
				}
			}
		}
	}

	for(i = 0 ; i < infoJeu.nbJoueurs ; i++){
		printf("Total patrimoine joueur %d : %dk€\n", i + 1, patrimoine[i]);
	}

	for(i = 0 ; i < infoJeu.nbJoueurs ; i++){
		if(g < patrimoine[i]){
			g = patrimoine[i];
			v = i;
		}
	}

	printf("Le joueur %d gagne la partie !\n", v + 1);
	for(;;){}
}