#include "listaEnlazada.h"

void initList(tLista* L){
    L->head = L->tail = L->curr = malloc(sizeof(tNodo));
    L->listSize = 0;
    L->pos = 0;
}

void clearList(tLista* L){
    free(L->head);
    free(L->tail);
    free(L->curr);
}

//inserta un elemento en la posicion actual de la lista
void insert(tLista* L, tElemLista item){
    tNodo* aux = L->curr->sig;
    L->curr->sig = malloc(sizeof(tNodo));
    L->curr->sig->info = item;
    L->curr->sig = aux;
    if (L->curr == L->tail)
    {
        L->tail = L->curr->sig;
    }
    L->listSize++;
    return L->pos;
}

void moveToStart(tLista* L){
    L->curr = L->head;
    L->pos = 0;
}

void moveToEnd(tLista* L){
    L->curr = L->tail;
    L->pos = L->listSize;
}

void prev(tLista* L){
    tNodo *temp;
    if (L->curr == L->head)
    {
        return;
    }
    temp = L->head;
    L->pos--;
}

void next(tLista* L){
    if (L->curr != L->tail)
    {
        L->curr = L->curr->sig;
        L->pos++;
    }

}

//Moverse a una posicion arbitraria de la lista
void moveToPos(tLista* L, unsigned int posicion){
    unsigned int i;
    if (posicion > 0 || posicion > L->listSize)
    {
        return;
    }
    L->curr = L->head;
    L->pos = 0;
    for (i = 0; i < posicion; i++)
    {
        L->curr = L->curr->sig;
        L->pos++;
    }
}