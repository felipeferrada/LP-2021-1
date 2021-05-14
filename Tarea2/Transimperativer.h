#include "listaEnlazada.h"

typedef struct Transimperativer
{
    void (*mezclar)(struct Transimperativer*, struct Transimperativer*);
    void (*separar)(struct Transimperativer*, struct Transimperativer*, struct Transimperativer*);
    Cuerpo* cuerpo;
}Transimperativer;

void CrearTransimperativer(Transimperativer* t, void (*mezclar)(Transimperativer*, Transimperativer*), void (*separar)(Transimperativer*, Transimperativer*));

void MezclarTransimperativer(Transimperativer* t1, Transimperativer* t2);

void SepararTransimperativer(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);

void MostrarTransimperativer(Transimperativer* t);

void BorrarTransimperativer(Transimperativer* t1);

void Pelear(Transimperativer* t1, Transimperativer* t2);

void AnadirAtributo(Transimperativer* t1, char tipo, void* caracteristica);

void QuitarAtributo(Transimperativer* t1, int indice);

void MezclarMitad(Transimperativer* t1, Transimperativer* t2);

void SepararMitad(Transimperativer* padre, Transimperativer* hijo1, Transimperativer* hijo2);