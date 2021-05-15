#include "Transimperativer.h"

/*Crea un Transimperativer y le asigna sus des funciones correspondientes*/
void CrearTransimperativer(Transimperativer* t, void (*Mezclar)(Transimperativer* t1, Transimperativer* t2), void (*Separar)(Transimperativer* t1, Transimperativer* t2, Transimperativer* t3)){
    t = (Transimperativer*)malloc(sizeof(Transimperativer));
    initList(t->cuerpo);
    t->mezclar = Mezclar;
    t->separar = Separar;
}

/*Mezcla partes de t1 y de t2*/
void MezclarTransimperativer(Transimperativer* t1, Transimperativer* t2){
    t1->mezclar(t1, t2);
}

/*Separa un Transimperativer en 2*/
void SepararTransimperativer(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2){
    padre->separar(padre, hijo1, hijo2);
}

/*Muestra las caractertisticas un Transimperativer por pantalla*/
void MostrarTransimperativer(Transimperativer* t){
    moveToStart(t->cuerpo);
    printf("Caracteristicas: \n");

    for (int i = 0; i < t->cuerpo->length; i++)
    {
        if (t->cuerpo->curr->tipo == 'i')
        {
            printf("%d\n", *(int*)t->cuerpo->curr->caracteristica);
        }
        else if (t->cuerpo->curr->tipo == 'c')
        {
            printf("%c\n", *(char*)t->cuerpo->curr->caracteristica);
        }
        else if (t->cuerpo->curr->tipo == 'h')
        {
            char* arreglo = t->cuerpo->curr->caracteristica;
            int largo = arreglo[0] - '0';

            for (int j = 1; j < largo; j++)
            {
                printf("%c", arreglo[j]);
            }

            printf("\n");
            
        }
        else if (t->cuerpo->curr->tipo == 'a')
        {
            int* arreglo = t->cuerpo->curr->caracteristica;
            int largo = arreglo[0];

            for (int j = 1; j < largo; j++)
            {
                printf("%d", arreglo[j]);
            }
            
            printf("\n");
        }

        next(t->cuerpo);
        
    }
    
}

/*Borra la informacion contenida en el Transimperativer*/
void BorrarTransimperativer(Transimperativer* t1){
    clear(t1->cuerpo);
    free(t1->cuerpo);
    free(t1->mezclar);
    free(t1->separar);
    free(t1);
}

/*Muestra por pantalla el Transimperativer con mejores caracteristicas*/
void Pelear(Transimperativer* t1, Transimperativer* t2){
    int suma_t1;
    int suma_t2;
    moveToStart(t1->cuerpo);
    moveToStart(t2->cuerpo);
    int largo_t1 = t1->cuerpo->length, largo_t2 = t2->cuerpo->length;

    for (int i = 0; i < largo_t1; i++)
    {
        if (t1->cuerpo->curr->tipo == 'i')
        {
            suma_t1 = suma_t1 + (*(int*)(t1->cuerpo->curr->caracteristica) * 2);
        }
        else if (t1->cuerpo->curr->tipo == 'c')
        {
            suma_t1 = suma_t1 + (*(int*)(t1->cuerpo->curr->caracteristica) / 2);
        }
        else if (t1->cuerpo->curr->tipo == 'h')
        {
            int suma;
            int promedio;
            char* arreglo = t1->cuerpo->curr->caracteristica;
            int largo = arreglo[0] - '0';

            for (int j = 1; j < largo; j++)
            {
                suma = suma + (int)(arreglo[j]);
            }
            promedio = suma / largo;

            suma_t1 = suma_t1 + promedio;

        }
        else if (t1->cuerpo->curr->tipo == 'a')
        {
            int suma;
            int promedio;
            int* arreglo = t1->cuerpo->curr->caracteristica;
            int largo = arreglo[0];

            for (int j = 1; j < largo; j++)
            {
                suma = suma + ((int)(arreglo[j]) * 2);
            }
            promedio = suma / largo;

            suma_t1 = suma_t1 + promedio;
        }
        
    }
    
    for (int i = 0; i < largo_t2; i++)
    {
        if (t2->cuerpo->curr->tipo == 'i')
        {
            suma_t2 = suma_t2 + (*(int*)(t2->cuerpo->curr->caracteristica) * 2);
        }
        else if (t2->cuerpo->curr->tipo == 'c')
        {
            suma_t2 = suma_t2 + (*(int*)(t2->cuerpo->curr->caracteristica) / 2);
        }
        else if (t2->cuerpo->curr->tipo == 'h')
        {
            int suma;
            int promedio;
            char* arreglo = t2->cuerpo->curr->caracteristica;
            int largo = arreglo[0] - '0';

            for (int j = 1; j < largo; j++)
            {
                suma = suma + (int)(arreglo[j]);
            }
            promedio = suma / largo;

            suma_t2 = suma_t2 + promedio;

        }
        else if (t2->cuerpo->curr->tipo == 'a')
        {
            int suma;
            int promedio;
            int* arreglo = t2->cuerpo->curr->caracteristica;
            int largo = arreglo[0];

            for (int j = 1; j < largo; j++)
            {
                suma = suma + ((int)(arreglo[j]) * 2);
            }
            promedio = suma / largo;

            suma_t2 = suma_t2 + promedio;
        }
        
    }
    
    if (suma_t1 > suma_t2)
    {
        printf("El ganador, despues de una dura pelea es el Transimperativer 1\n");
    }
    else if (suma_t2 > suma_t1)
    {
        printf("El ganador, despues de una dura pelea es el Transimperativer 2\n");
    }
    else
    {
        printf("No puede ser.. Es un... EMPATE!!!\n");
    }
    
    
    
}

/*Agraga una caracteristica al Transimperativer*/
void AnadirAtributo(Transimperativer* t1, char tipo, void* caracteristica){
    moveToEnd(t1->cuerpo);
    insert(t1->cuerpo, caracteristica, tipo);
}

/*Elimina una caracteristica del Transimperativer*/
void QuitarAtributo(Transimperativer* t1, int indice){
    moveToPos(t1->cuerpo, indice);
    delete(t1->cuerpo, indice);
}

/*Mezcla la primera mitad de un Transimperativer con la segunda mitad de otro*/
void MezclarMitad(Transimperativer* t1, Transimperativer* t2){
    int largo_t1 = t1->cuerpo->length, largo_t2 = t2->cuerpo->length;
    int mitad_largot1, mitad_largot2;

    if (largo_t1 % 2 == 0)
    {
        mitad_largot1 = largo_t1 / 2;
    }
    else
    {
        mitad_largot1 = (largo_t1 / 2) + 1;
    }
    
    if (largo_t2 % 2 == 0)
    {
        mitad_largot2 = largo_t2 / 2;
    }
    else
    {
        mitad_largot2 = (largo_t2 / 2) + 1;
    }
    
    moveToPos(t1->cuerpo, mitad_largot1);
    moveToPos(t2->cuerpo, mitad_largot2);

    nodo* primera_mitad_t1 = t1->cuerpo->curr;
    nodo* segunda_mitad_t2 = t2->cuerpo->curr;

    t1->cuerpo->curr->next = segunda_mitad_t2;
    t2->cuerpo->curr->next = primera_mitad_t1;

}

/*Separa un Transimperativer en sus dos mitades*/
void SepararMitad(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2){
    nodo* mitad_padre1;
    nodo* mitad_padre2;

    int largo_padre = padre->cuerpo->length;
    int mitad_largoPadre;

    if (largo_padre % 2 == 0)
    {
        mitad_largoPadre = (largo_padre / 2);
    }
    else
    {
        mitad_largoPadre = (largo_padre / 2) + 1;
    }

    moveToPos(padre->cuerpo, mitad_largoPadre);
    mitad_padre1 = padre->cuerpo->head;
    mitad_padre2 = padre->cuerpo->curr->next;

    hijo1->cuerpo->head = mitad_padre1;
    moveToPos(hijo1->cuerpo, mitad_largoPadre);
    hijo1->cuerpo->curr->next = hijo1->cuerpo->tail;
    hijo2->cuerpo->head = mitad_padre2;

    hijo1->cuerpo->length = mitad_largoPadre;
    hijo2->cuerpo->length = largo_padre - mitad_largoPadre;

    moveToStart(hijo1->cuerpo);
    moveToStart(hijo2->cuerpo);

}

