#include "monopoly.h"

int main(int argc, char* argv[]) {
	struct sockaddr_in addr, cl_addr;
	int sockfd, len, ret, newsockfd, i;
	char buffer[BUF_SIZE];
	char username[NAME_SIZE];
	pid_t childpid;
	char clientAddr[CLADDR_LEN];

	pthread_t thread;

	if(argc < 4) {
		printf("Usage: %s port username nbPlayers\n", argv[0]);
		exit(1);
	}

	bzero(infoJeu.nomJoueur[0], sizeof(char) * 6 * NAME_SIZE);
	strcpy(infoJeu.nomJoueur[0], argv[2]);
	infoJeu.nbJoueurs = 1;
	statut = 0;
	srand(time(NULL));

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Error creating socket!\n");
		exit(1);
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	addr.sin_port = htons(atoi(argv[1]));

	ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
	if(ret < 0){
		printf("Error bind\n");
		exit(1);
	}

	printf("Waiting for a connection...\n");
	listen(sockfd, 5);
	for(;infoJeu.nbJoueurs < atoi(argv[3]);){

		for(i = 0 ; i < infoJeu.nbJoueurs ; i++){
			printf("Joueur %d : %s\n", i+1, infoJeu.nomJoueur[i]);
		}

		len = sizeof(cl_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cl_addr, &len);
		if(newsockfd < 0){
			printf("Error accept\n");
			exit(1);
		}
		printf("Connection accepted...\n");
		inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);

		bzero(username, NAME_SIZE);
		if(recv(newsockfd, username, NAME_SIZE, 0) < 0){
			printf("Error recv\n");
			exit(1);
		}

		printf("Nom : %s\n\n",username);
		strcpy(infoJeu.nomJoueur[infoJeu.nbJoueurs], username);
		infoJeu.nbJoueurs++;

		if(pthread_create(&thread, NULL, jeu, (void*)newsockfd) < 0){
			printf("Error thread 1\n");
			exit(1);
		}
	}

	statut = 1;
	int j = 1;

	//Initialisation plateau
	for(i = 0 ; i < infoJeu.nbJoueurs ; i++){
		plateauJeu.posJoueur[i] = 0;
		plateauJeu.argentJoueur[i] = 1500;
	}
	for(i = 0 ; i < 28 ; i++){
		plateauJeu.terrains[i].proprietaire = 0;
		plateauJeu.terrains[i].constructions = 0;
	}

	plateauJeu.tour = 1;
	plateauJeu.tourj = 1;

	bzero(buffer, BUF_SIZE);
	strcpy(buffer, "PLT\0");
	memcpy(buffer + 4, &plateauJeu, sizeof(plateauJeu));

	for(int i = 0 ; i < infoJeu.nbJoueurs ; i++){
		printf("Joueur %d : %s\n", i+1, infoJeu.nomJoueur[i]);
	}

	int d; //double

	for(;statut;){
		if(plateauJeu.tourj == 1){
			d = lancerDes();
			deplacerPion();
			afficherPlateau(plateauJeu, infoJeu);
			tourJeu(0, 0);
			afficherPlateau(plateauJeu, infoJeu);
			while(d == 1){
				d = lancerDes();
				deplacerPion();
				afficherPlateau(plateauJeu, infoJeu);
				tourJeu(0, 0);
				afficherPlateau(plateauJeu, infoJeu);
			}
			finDeTour(0, 0);
			afficherPlateau(plateauJeu, infoJeu);
			tourSuivant();
		}
		else{
			sleep(1);
			afficherPlateau(plateauJeu, infoJeu);
		}
	}

	finDeJeu();
	
}