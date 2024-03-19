#include <stdio.h>

#define N 2

int main()
{
    // Declaracion de arreglo tridimensional x, y, z
    int arreglo[N][N][N] = {
        { {0, 1}, {2, 3} },
        { {4, 5}, {6, 7} }
    };

    /**
     * Cuando recorremos un arreglo tridimensional, el primer ciclo for recorre
     * el eje x, el segundo ciclo for recorre el eje y y el tercer ciclo for
     * recorre el eje z.
     * 
     * A mayor cantidad de dimensiones, mayor cantidad de ciclos for anidados
     * y mayor complejidad para entender el recorrido del arreglo.
    */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                printf("%d ", arreglo[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Presiona una tecla para terminar...");
    getchar();

    return 0;
}