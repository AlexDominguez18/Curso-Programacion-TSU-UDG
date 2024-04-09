#include <iostream>

#define FILAS 3
#define COLUMNAS 3

using namespace std;

int main()
{
    int matriz[FILAS][COLUMNAS];
    int vectorFilas[FILAS] = {0, 0, 0};
    int vectorColumnas[COLUMNAS] = {0, 0, 0};
    int i, j;

    // Inicializar la matriz
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            cout << "Ingrese el valor de la matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
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
    cout << "El vector de la suma de las filas:" << endl;
    for (i = 0; i < FILAS; i++) {
        cout << " " << vectorFilas[i];
    }

    cout << endl << "El vector de la suma de las columnas: " << endl;
    for (i = 0; i < COLUMNAS; i++) {
        cout << " " << vectorColumnas[i];
    }

    return 0;
}