#include <stdio.h>

#define TAMANIO_ARREGLO 10

int main()
{
    int arreglo[TAMANIO_ARREGLO], resultados[TAMANIO_ARREGLO];
    int i, multiplicador;

    // Pedimos los valores del arreglo
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        printf("Ingrese el valor para la posición %d: ", i);
        scanf("%d", &arreglo[i]);
    }

    printf("Ingrese el multiplicador: ");
    scanf("%d", &multiplicador);

    // Calculamos el resultado y lo guardamos en el arreglo resultados
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        resultados[i] = arreglo[i] * multiplicador;
    }

    // Mostramos el resultado
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        printf("%d * %d = %d\n", arreglo[i], multiplicador, resultados[i]);
    }

    getchar(); // Limpiamos el buffer del teclado
    printf("Presione enter para terminar...");
    getchar();

    return 0;
}