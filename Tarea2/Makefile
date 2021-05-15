
output: main.o Transimperativer.o listaEnlazada.o
	gcc main.o Transimperativer.o listaEnlazada.o -o output

main.o: main.c Transimperativer.h
	gcc -Wall -c main.c

Transimperativer.o: Transimperativer.c Transimperativer.h
	gcc -Wall -c Transimperativer.c

listaEnlazada.o: listaEnlazada.c listaEnlazada.h
	gcc -Wall -c listaEnlazada.c

clean:
	rm -f *.o output