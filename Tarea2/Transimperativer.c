#include "Transimperativer.h"

void CrearTransimperativer(Transimperativer* t, void (*Mezclar)(Transimperativer* t1, Transimperativer* t2), void (*Separar)(Transimperativer* t1, Transimperativer* t2)){
    t = (Transimperativer*)malloc(sizeof(Transimperativer));
    initList(t->cuerpo);
    t->mezclar = Mezclar;
    t->separar = Separar;
}

void MezclarTransimperativer(Transimperativer* t1, Transimperativer* t2);

void SepararTransimperativer(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);

void MostrarTransimperativer(Transimperativer* t){
    moveToStart(t->cuerpo);
    printf("Caracteristicas: \n");

    for (int i = 0; i < t->cuerpo->length; i++)
    {
        if (t->cuerpo->curr->tipo == 'i')
        {
            printf("%d\n", t->cuerpo->curr->caracteristica);
        }
        else if (t->cuerpo->curr->tipo == 'c')
        {
            printf("%c\n", t->cuerpo->curr->caracteristica);
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

void BorrarTransimperativer(Transimperativer* t1){
    clear(t1->cuerpo);
    free(t1->cuerpo);
    free(t1->mezclar);
    free(t1->separar);
    free(t1);
}

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
            suma_t1 = suma_t1 + ((int)(t1->cuerpo->curr->caracteristica) * 2);
        }
        else if (t1->cuerpo->curr->tipo == 'c')
        {
            suma_t1 = suma_t1 + ((int)(t1->cuerpo->curr->caracteristica) / 2);
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
            suma_t2 = suma_t2 + ((int)(t2->cuerpo->curr->caracteristica) * 2);
        }
        else if (t2->cuerpo->curr->tipo == 'c')
        {
            suma_t2 = suma_t2 + ((int)(t2->cuerpo->curr->caracteristica) / 2);
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

void AnadirAtributo(Transimperativer* t1, char tipo, void* caracteristica){
    moveToEnd(t1->cuerpo);
    insert(t1->cuerpo, caracteristica, tipo);
}

void QuitarAtributo(Transimperativer* t1, int indice){
    moveToPos(t1->cuerpo, indice);
    delete(t1->cuerpo, indice);
}

void MezclarMitad(Transimperativer* t1, Transimperativer* t2);

void SepararMitad(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);