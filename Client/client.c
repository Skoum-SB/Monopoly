#include "monopoly.h"

int main(int argc, char**argv){
	struct sockaddr_in addr, cl_addr;
	int sockfd;
	char buffer[BUF_SIZE];
	struct hostent * server;
	char username[NAME_SIZE];
	char r;
	int prix[28] = {60,60,100,100,120,140,140,160,180,180,200,220,220,240,260,260,280,300,300,320,350,400,200,200,200,200,150,150};

	if(argc < 4) {
		printf("Usage: %s host port username\n", argv[0]);
		exit(1);
	}
	strcpy(username, argv[3]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Error socket\n");
		exit(1);
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));;
	if(connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0){
		printf("Error connect\n");  
		exit(1);
	}
	printf("Connected to the server...\n");
	
	if(send(sockfd, username, sizeof username, 0) < 0){
		printf("Error send\n");
		exit(1);
	}

	bzero(buffer, BUF_SIZE);
	if(recv(sockfd, buffer, BUF_SIZE, 0) < 0){
		printf("Error recv\n");
		exit(1);
	}

	if(strcmp("INF",buffer) == 0){
		memcpy(&infoJeu, buffer + 4, sizeof(infoJeu));
	}
	printf("Nombre de joueurs : %d\n", infoJeu.nbJoueurs);

	for(int i = 0 ; i < infoJeu.nbJoueurs ; i++){
		printf("Joueur %d : %s\n", i+1, infoJeu.nomJoueur[i]);
	}

	int ret, c, numT;

	for(;;){
		if(recv(sockfd, buffer, BUF_SIZE, 0) < 0){
			printf("Error recv\n");
			exit(1);
		}

		if(strcmp("PLT",buffer) == 0){
			memcpy(&plateauJeu, buffer + 4, sizeof(plateauJeu));
			afficherPlateau(plateauJeu, infoJeu);
		}

		if(strcmp("ACH",buffer) == 0){
			if(plateauJeu.argentJoueur[plateauJeu.tourj - 1] < prix[posToNumT(plateauJeu.posJoueur[plateauJeu.tourj - 1])]){
				printf("Vous n'avez pas assez d'argent pour acheter cette propriété !\n");
				bzero(buffer, BUF_SIZE);
				strcpy(buffer, "n\0");
				if(send(sockfd, buffer, BUF_SIZE, 0) < 0){
					printf("Error send\n");
					exit(1);
				}
			}

			else{
				printf("Voulez-vous acheter cette propriété pour %d k€ ? (o/n)\n", prix[posToNumT(plateauJeu.posJoueur[plateauJeu.tourj - 1])]);
				scanf("%c", &r);
				viderBuffer();
				while(r != 'o' && r != 'n'){
					printf("Réponse incorrecte (o/n)\n");
					scanf("%c", &r);
					viderBuffer();
				}
				bzero(buffer, BUF_SIZE);
				if(r == 'o')
					strcpy(buffer, "o\0");
				else
					strcpy(buffer, "n\0");

				if(send(sockfd, buffer, sizeof username, 0) < 0){
					printf("Error send\n");
					exit(1);
				}
			}
		}

		if(strcmp("ACT",buffer) == 0){
			printf("Que souhaitez-vous faire ? (Construire/Vendre/Rien) (C/V/R)\n");
			scanf("%c", &r);
			viderBuffer();
			while(r != 'C' && r != 'V' && r != 'R'){
				printf("Réponse incorrecte (C/V/R)");
				scanf("%c", &r);
				viderBuffer();
			}

			bzero(buffer, BUF_SIZE);

			if(r == 'C'){//Construire
				ret = construireClient(socket);
				numT = ret / 10;
				c = ret % 10;//Nombre de constructions à faire
				strcpy(buffer, "CST\0");
				memcpy(buffer + 4, &numT, sizeof(int));
				memcpy(buffer + 8, &c, sizeof(int));
			}

			else if(r == 'V'){//Vendre
				ret = vendreClient(socket);
				numT = ret / 10;
				c = ret % 10;//Nombre de vente à faire
				strcpy(buffer, "VEN\0");
				memcpy(buffer + 4, &numT, sizeof(int));
				memcpy(buffer + 8, &c, sizeof(int));
			}

			else
				strcpy(buffer, "R\0");

			if(send(sockfd, buffer, BUF_SIZE, 0) < 0){
				printf("Error send\n");
				exit(1);
			}
		}

		if(strcmp("VEN",buffer) == 0){
			printf("Vous devez vendre des habitations !\n");
			ret = vendreClient(socket);
			numT = ret / 10;
			c = ret % 10;//Nombre de vente à faire
			strcpy(buffer, "VEN\0");
			memcpy(buffer + 4, &numT, sizeof(int));
			memcpy(buffer + 8, &c, sizeof(int));

			if(send(sockfd, buffer, BUF_SIZE, 0) < 0){
				printf("Error send\n");
				exit(1);
			}
		}

		if(strcmp("FIN",buffer) == 0){
			finDeJeu();
			close(sockfd);
			exit(0);
		}
	}
}

void viderBuffer(){
    int c; 
    do{ 
        c = getchar(); 
    }while(c != '\n' && c != EOF);
}

int posToNumT(int pos){
	int tab[28] = {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39,5,15,25,35,12,28};
	int i;
	for(i = 0 ; tab[i] != pos ; i++){}
	return i;
}

int construireClient(){
	char g, n, c;
	int numT, prix;

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
		return 0;
	}

	if(plateauJeu.terrains[numT].constructions == 5){
		printf("Vous n'avez rien à construire en plus ici !\n");
		return 0;
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
		return 0;
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
		return 0;
	}

	return (numT * 10) + c;
}

int vendreClient(){
	char g, n, c;
	int numT;

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
		return 0;
	}

	if(plateauJeu.terrains[numT].constructions == 0){
		printf("Vous n'avez rien à vendre ici !\n");
		return 0;
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
		return 0;
	}

	return (numT * 10) + c;
}

int convert(int g, int n){
	int tab[8][3] = {{0,1,0},{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16},{17,18,19},{20,21,0}};
	return tab[g][n];
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
}