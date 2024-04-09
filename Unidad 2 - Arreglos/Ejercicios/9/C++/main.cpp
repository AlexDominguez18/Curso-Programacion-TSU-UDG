#include <iostream>

#define FILAS 2
#define COLUMNAS 2

using namespace std;

int main()
{
    int matrizA[FILAS][COLUMNAS];
    int matrizB[FILAS][COLUMNAS];
    int resultado[FILAS][COLUMNAS];
    int i, j;

    // Inicializar la matriz resultado y la matriz A
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = 0;
            cout << "Ingrese el valor de la matrizA[" << i << "][" << j << "]: ";
            cin >> matrizA[i][j];
        }
    }

    // Inicializar la matriz B
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            cout << "Ingrese el valor de la matrizB[" << i << "][" << j << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // El primer for es para recorrer las filas de la matriz A y B
    for (i = 0; i < FILAS; i++) {
        // El segundo for es para recorrer las columnas de la matriz A y B
        for (j = 0; j < COLUMNAS; j++) {
            /**
             * Este for es para poder tener el indice de la fila para la matriz A y
             * el indice de la columna para la matriz B, de esta manera se puede
             * multiplicar los valores correspondientes (fila de A y columna de B)
             */
            for (int k = 0; k < COLUMNAS; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Mostramos el resultado
    cout << "El resultado de la multiplicacion de las matrices es:\n";
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            cout << " " << resultado[i][j];
        }
        cout << "\n";
    }

    return 0;
}