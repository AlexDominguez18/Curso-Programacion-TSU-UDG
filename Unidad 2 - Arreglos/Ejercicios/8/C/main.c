#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main()
{
    int matriz[FILAS][COLUMNAS];
    int vectorFilas[FILAS] = {0, 0, 0};
    int vectorColumnas[COLUMNAS] = {0, 0, 0};
    int i, j;

    // Inicializar la matriz
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Ingrese el valor de la matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);   
        }
    }

    // Sumamos cada fila y la guardamos en el vectorFilas
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            vectorFilas[i] += matriz[i][j];
        }
    }

    // Sumamos cada columna y la guardamos en el vectorColumnas
    for (i = 0; i < COLUMNAS; i++) {
        for (j = 0; j < FILAS; j++) {
            vectorColumnas[i] += matriz[j][i];
        }
    }

    // Mostramos ambos vectores
    printf("El vector de la suma de las filas:\n");
    for (i = 0; i < FILAS; i++) {
        printf(" %d", vectorFilas[i]);
    }

    printf("\nEl vector de la suma de las columnas: \n");
    for (i = 0; i < COLUMNAS; i++) {
        printf(" %d", vectorColumnas[i]);
    }

    return 0;
}