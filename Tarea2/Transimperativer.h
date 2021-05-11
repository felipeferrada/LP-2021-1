#include <stdio.h>
#include <stdlib.h>

typedef struct Transimperativer
{
    void (*mezclar) (Transimperativer*, Transimperativer*);
    void (*separar) (Transimperativer*, Transimperativer*, Transimperativer*);
    Cuerpo cuerpo;
}Transimperativer;

typedef struct Cuerpo
{
    nodo* curr;
    nodo* head;
    nodo* tail;
    int lenght;
    int posCurr;
}Cuerpo;

typedef struct nodo
{
    void* caracteristica;
    char tipo;
    nodo* next;
}nodo;

void CrearTransimperativer(Transimperativer* t1, Transimperativer* t2);

void MezclarTransimperativer(Transimperativer* t1, Transimperativer* t2);

void SepararTransimperativer(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);

void MostrarTransimperativer(Transimperativer* t);

void BorrarTransimperativer(Transimperativer* t1);

void Pelear(Transimperativer* t1, Transimperativer* t2);

void AnadirAtributo(Transimperativer* t1, char tipo, void* caracteristica);

void QuitarAtributo(Transimperativer* t1, int indice);

void MezclarMitad(Transimperativer* t1, Transimperativer* t2);

void SepararMitad(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);
