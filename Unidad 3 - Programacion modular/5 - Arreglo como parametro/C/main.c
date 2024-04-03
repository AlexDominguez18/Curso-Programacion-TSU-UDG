#include <stdio.h>

#define TAMANIO_ARR 5

int sumar(int arreglo[]);

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5};
    int resultado;
    
    resultado = sumar(arreglo);

    printf("El resultado de la suma es: %d\n", resultado);

    return 0;
}

int sumar(int arreglo[])
{
    int suma = 0;
    for (int i = 0; i < TAMANIO_ARR; i++) {
        suma += arreglo[i];
    }
    return suma;
}