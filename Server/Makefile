Serveur: server.o jeu.o
	gcc -o Serveur server.o jeu.o -lpthread

server.o: server.c jeu.c monopoly.h
	gcc -o  server.o -c server.c

jeu.o: jeu.c monopoly.h
	gcc -o jeu.o -c jeu.c

clean:
	rm -v -f *.o *~core

mrproper: clean
	rm -v -f Serveur