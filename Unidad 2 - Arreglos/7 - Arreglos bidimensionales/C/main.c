#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main()
{
    // Declaracion e inicializacion de arreglo bidimensional
    int arreglo[FILAS][COLUMNAS] = { 
        {1, 2, 3}, // Fila 1 
        {4, 5, 6}, // Fila 2
        {7, 8, 9}  // Fila 3
    };

    /**
     * Para recorrer un arreglo bidimensional se utilizan dos ciclos anidados
     * El primer ciclo recorre las filas y el segundo ciclo recorre las columnas
    */
    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna < COLUMNAS; columna++) {
            // Imprimir el valor del arreglo en la fila y columna actual
            printf("%d ", arreglo[fila][columna]);
        }
        printf("\n");
    }

    printf("Presione ENTER para continuar...");
    getchar();

    return 0;
}