#include <stdio.h>

#define TAMANIO_ARREGLO 10

int main()
{
    // Declaracion e inicializacion del arreglo
    int arreglo[TAMANIO_ARREGLO] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    
    /**
     * Imprimir el arreglo.
     * Para ello, se recorre el arreglo y se imprime el indice y el valor.
     * Todos los arreglos empiezan en el indice 0.
    */
    printf("Indice:\tValor:\n");
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        printf("%d\t%d\n", i, arreglo[i]);
    }

    return 0;
}