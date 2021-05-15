#include <stdio.h>
#include <stdlib.h>

typedef void* tElemLista;

typedef struct nodo
{
    tElemLista caracteristica;
    char tipo;
    struct nodo* next;
}nodo;

typedef struct Cuerpo
{
    nodo* curr;
    nodo* head;
    nodo* tail;
    int length;
    int posCurr;
}Cuerpo;

void initList(Cuerpo* L);

void clear(Cuerpo* L);

void insert(Cuerpo* L, tElemLista item, char tipo);

void delete(Cuerpo* L, unsigned int posicion);

void moveToStart(Cuerpo* L);

void moveToEnd(Cuerpo* L);

void next(Cuerpo* L);

void moveToPos(Cuerpo* L, unsigned int posicion);
