#include <iostream>

#define FILAS 2
#define COLUMNAS 2

using namespace std;

int main()
{
    // Declaración de una matriz de 2x2
    int m1[FILAS][COLUMNAS] = {{3, 9}, {2, 7}};
    // Declaración de una matriz de 2x2
    int m2[FILAS][COLUMNAS] = {{1, 2}, {3, 4}};
    // Declaración de una matriz de 2x2 inicializada a 0
    int resultado[FILAS][COLUMNAS] = {{}};

    // Impresion de las matrices
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << m1[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }

    // Suma de matrices
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // Suma de los elementos de la misma posición de las dos matrices
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Impresión de la matriz resultado
    cout << "Suma de matrices" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
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
    cout << "Multiplicacion de matrices" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Presione una tecla para terminar...";
    cin.get();

    return 0;
}