#include <stdio.h>

#define TAMANIO_ARR 5

void modificarArreglo(int arreglo[]);
void imprimirArreglo(int arreglo[]);

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5};

    printf("Arreglo original: ");
    imprimirArreglo(arreglo);

    modificarArreglo(arreglo);
    printf("Arreglo modificado: ");
    imprimirArreglo(arreglo);

    return 0;
}

void modificarArreglo(int arreglo[])
{
    for (int i = 0; i < TAMANIO_ARR; i++) {
        arreglo[i] = arreglo[i] * 2;
    }
}

void imprimirArreglo(int arreglo[])
{
    for (int i = 0; i < TAMANIO_ARR; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}