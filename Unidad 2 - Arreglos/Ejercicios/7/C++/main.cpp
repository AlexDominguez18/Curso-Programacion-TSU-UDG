#include <iostream>

#define FILAS 3
#define COLUMNAS 3

using namespace std;

int main()
{
    int matriz[FILAS][COLUMNAS];
    int vector[FILAS];
    int resultado[FILAS] = {0, 0, 0};
    int i, j;

    // Inicializar la matriz
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            cout << "Ingrese el valor de la matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];   
        }
    }

    // Inicializar el vector
    for (i = 0; i < FILAS; i++) {
        cout << "Ingrese el valor del vector[" << i << "]: ";
        cin >> vector[i];
    }

    // Multiplicar la matriz por el vector
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    cout << "El vector resultante es:" << endl;
    for (i = 0; i < FILAS; i++) {
        cout << " " << resultado[i];
    }

    return 0;
}