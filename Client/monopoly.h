#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"string.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"unistd.h"
#include"pthread.h"

#define BUF_SIZE 1024
#define CLADDR_LEN 100
#define NAME_SIZE 17

typedef struct propriete{
	int proprietaire;
	int constructions;
}propriete;

typedef struct info{
	int nbJoueurs;
	char nomJoueur[6][17];
}info;

typedef struct plateau{
	int posJoueur[6];
	int argentJoueur[6];
	propriete terrains[28];
	int de1;
	int de2;
	int tour;
	int tourj;
}plateau;

typedef struct players{
	char name[11];
}players;

plateau plateauJeu;
info infoJeu;

void viderBuffer();
void afficherPlateau(plateau jeu, info infoJeu);
void afficherNomJoueur(plateau jeu, info infoJeu, int nJoueur);
void afficherProp(plateau jeu, info infoJeu, int nprop);
char afficherPion(plateau jeu, info infoJeu, int c, int j);
void *jeu(void *id);
int posToNumT(int pos);
int construireClient();
int vendreClient();
int convert(int g, int n);
void finDeJeu();