#include <stdio.h>

#define FILAS 2
#define COLUMNAS 2

int main()
{
    // Declaración de una matriz de 2x2
    int m1[FILAS][COLUMNAS] = {{1, 2}, {-3, 0}};
    // Declaración de una matriz de 2x2
    int m2[FILAS][COLUMNAS] = {{3, 5}, {4, 1}};
    // Declaración de una matriz de 2x2 inicializada a 0
    int resultado[FILAS][COLUMNAS] = {{}};

    // Impresion de las matrices
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\t");
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    // Suma de matrices
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // Suma de los elementos de la misma posición de las dos matrices
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Impresión de la matriz resultado
    printf("Suma de matrices\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    // Reseteamos los valores de la matriz resultado
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = 0;
        }
    }

    // Multiplicación de matrices
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            for (int k = 0; k < COLUMNAS; k++) {
                // Multiplicación de los elementos de la misma posición de las dos matrices
                resultado[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Impresión de la matriz resultado
    printf("Multiplicacion de matrices\n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    printf("Presione una tecla para terminar...");
    getchar();

    return 0;
}