#include "listaEnlazada.h"

/*inicializa el cuerpo del Transimperativer */
void initList(Cuerpo* L){
    L->head = L->curr = L->tail = (nodo*)malloc(sizeof(nodo));
    L->length = 0;
    L->posCurr = 0;
}

/*vacía el contenido del cuerpo */
void clear(Cuerpo* L){
    nodo* aux;
    while (L->head != NULL)
    {
        aux = L->head;
        L->head = L->head->next;
        free(aux);
    }
    L->length = 0;
    L->posCurr = 0;

}

/*inserta un elemento en el cuerpo del Transimperativer */
void insert(Cuerpo* L, tElemLista item, char tipo){
    nodo* aux = L->tail;
    L->tail->next = (nodo*)malloc(sizeof(nodo));
    L->tail->next->caracteristica = item;
    L->tail->next->tipo = tipo;
    L->tail->next->next = NULL;
    L->tail = aux->next;
    L->length++;
}

/*elimina un elemento del cuerpo del Transimperativer */
void delete(Cuerpo* L, unsigned int posicion){
    if (L->head == NULL)
    {
        return;
    }
    nodo* temp = L->head;
    if (posicion == 0)
    {
        L->head = temp->next;
        free(temp);
        L->length--;
        return;
    }
    for (int i = 0; temp != NULL && i < posicion - 1 ; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    nodo* next = temp->next->next;
    free(temp->next);
    L->length--;
    temp->next = next;
    
    
}

/*mueve el curr al inicio del cuerpo del Transimperativer */
void moveToStart(Cuerpo* L){
    L->curr = L->head;
    L->posCurr = 0;
}

/*mueve el curr al final del cuerpo del Transimperativer */
void moveToEnd(Cuerpo* L){
    L->curr = L->tail;
    L->posCurr = L->length;
}


/*mueve el curr a la posicion siguiente */
void next(Cuerpo* L){
    if (L->curr != L->tail)
    {
        L->curr = L->curr->next;
        L->posCurr++;
    }
    
}

/*mueve el curr al final del cuerpo del Transimperativer */
void moveToPos(Cuerpo* L, unsigned int posicion){
    unsigned int i;
    if (posicion > 0 || posicion > L->length)
    {
        return;
    }
    L->curr = L->head;
    L->posCurr = 0;
    for (i = 0; i < posicion; i++)
    {
        L->curr = L->curr->next;
        L->posCurr++;
    }
    

}
