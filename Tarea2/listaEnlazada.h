#include <stdio.h>
#include <stdlib.h>

typedef tElemLista;

typedef struct
{
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
} tLista;

typedef struct nodo
{
    tElemLista info;
    struct nodo* sig;
} tNodo;


void initList(tLista* L);

void clear(tLista* L);

void insert(tLista* L, tElemLista item);

void moveToStart(tLista* L);

void moveToEnd(tLista* L);

void prev(tLista* L);

void next(tLista* L);

void moveToPos(tLista* L, unsigned int posicion);
