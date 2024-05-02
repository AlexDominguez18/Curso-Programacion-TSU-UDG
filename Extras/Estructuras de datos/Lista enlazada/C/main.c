#include <stdio.h>

#include "lista.h"

int main()
{
    Lista listaNumeros;

    inicializar(&listaNumeros);

    for (int i = 0; i < 10; i++)
        agregar(&listaNumeros, i + 1);

    printf("Longitud de la lista: %d\n", longitud(&listaNumeros));
    imprimir(&listaNumeros);

    return 0;
}