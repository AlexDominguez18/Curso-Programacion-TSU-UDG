#include <stdio.h>

#include "lista.h"

#define POSICION 6

int main()
{
    Lista listaNumeros;

    inicializar(&listaNumeros);

    for (int i = 0; i < 10; i++)
        agregar(&listaNumeros, i + 1);

    printf("Longitud de la lista: %d\n", longitud(&listaNumeros));
    imprimir(&listaNumeros);

    Nodo *elemento = obtener(&listaNumeros, POSICION);

    if (elemento != NULL)
        printf("Elemento en la posición %d: %d\n", POSICION, elemento->dato);
    else
        printf("No se encontró el elemento en la posición %d\n", POSICION);

    eliminar(&listaNumeros, POSICION);
    imprimir(&listaNumeros);

    return 0;
}