#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main()
{
    int matriz[FILAS][COLUMNAS];
    int vector[FILAS];
    int resultado[FILAS] = {0, 0, 0};
    int i, j;

    // Inicializar la matriz
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Ingrese el valor de la matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);   
        }
    }

    // Inicializar el vector
    for (i = 0; i < FILAS; i++) {
        printf("Ingrese el valor del vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }

    // Multiplicar la matriz por el vector
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    printf("El vector resultante es:\n");
    for (i = 0; i < FILAS; i++) {
        printf(" %d", resultado[i]);
    }

    return 0;
}