#include "Transimperativer.h"

int main(){
    int entrada;
    int salir = 0;
    Transimperativer** array_TranSimp = (Transimperativer**)malloc(sizeof(Transimperativer*)*20);
    void* funcionesMezclar[4] = {MezclarMitad, NULL, NULL, NULL}; //reemplazar NULL's
    void* funcionesSeparar[4] = {SepararMitad, NULL, NULL, NULL}; //reemplazar NULL's
    
    do
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Seleccione una opcion: (debe introducir el nuemro correspondiente)\n");
        printf("\n");
        printf("1. Crear\n");
        printf("2. Mezclar\n");
        printf("3. Separar\n");
        printf("4. Mostrar\n");
        printf("5. Borrar\n");
        printf("6. Pelear\n");
        printf("7. Anadir Atributo\n");
        printf("8. Quitar Atributo\n");
        printf("9. Salir\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        scanf("%d", &entrada);

        switch (entrada)
        {
        case 1:
            printf("Crear un Transimperativer\n");
            printf("\n");
            int t, m , s;
            scanf("%d", &t);
            scanf("%d", &m);
            scanf("%d", &s);
            printf("Se 'hace' la funcion CrearTransimperativer");

            CrearTransimperativer(array_TranSimp[t], funcionesMezclar[m], funcionesSeparar[s]);
            break;
        
        case 2:
            printf("Mezclar Transimperativer\n");
            printf("Se hace la funcion MezclarTransimperativer\n");

            break;

        case 3:
            printf("Separar Transimperativer\n");
            printf("Se hace la funcion SepararTransimperativer\n");

            break;

        case 4:
            printf("Mostrar Transimperativer\n");
            printf("Se hace la funcion MostrarTransimperativer");
            
            break;

        case 5:
            printf("Borrar Transimperativer\n");
            printf("Se hace la funcion BorrarTransimperativer");

            break;

        case 6:
            printf("Pelear Transimperativers\n");
            printf("Se hace la funcion Pelear");

            break;

        case 7:
            printf("Añadir Atributo\n");
            printf("Se hace la funcion AnadirAtributo");

            break;

        case 8:
            printf("Quitar Atributo\n");
            printf("Se hace la funcion QuitarAtributo");

            break;

        case 9:
            printf("Fin del Programa\n");
            salir = 1;
            free(array_TranSimp);
            break;
        
        default:
            printf("Entrada Invalida\n");
            salir = 1;
            free(array_TranSimp);
            break;
        }
        
        
    } while (salir == 0);
    
    printf("Vuelva Pronto :)\n");

    return 0;
}