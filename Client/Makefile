Client: client.o affichage.o
	gcc -o Client client.o affichage.o -lpthread

client.o: client.c affichage.c monopoly.h
	gcc -o client.o -c client.c

affichage.o: affichage.c monopoly.h
	gcc -o affichage.o -c affichage.c

clean:
	rm -v -f *.o *~core

mrproper: clean
	rm -v -f Client