#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"string.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"unistd.h"
#include"pthread.h"
#include <time.h>

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

int statut;
info infoJeu;
plateau plateauJeu;

void viderBuffer();
void afficherPlateau(plateau jeu, info infoJeu);
void afficherNomJoueur(plateau jeu, info infoJeu, int nJoueur);
void afficherProp(plateau jeu, info infoJeu, int nprop);
char afficherPion(plateau jeu, info infoJeu, int c, int j);
void *jeu(void *id);
void tourSuivant();
void deplacerPion();
int lancerDes();
void tourJeu(int mode, int socket);
int posToNumT(int pos);
void achat(int n, int mode, int socket);
void loyer(int n);
void envoyerPlateau(int socket);
void finDeTour(int mode, int socket);
int convert(int g, int n);
void vendre(int mode, int socket, int numT, int cst);
void construire(int mode, int socket, int numT, int cst);
void dette(int mode, int socket);
void finDeJeu();
int faillite();