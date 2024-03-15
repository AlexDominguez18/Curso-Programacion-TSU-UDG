#include <iostream>

#define FILAS 3
#define COLUMNAS 3

using namespace std;

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
            cout << arreglo[fila][columna] << " ";
        }
        cout << endl;
    }

    cout << "Presione ENTER para continuar...";
    cin.get();

    return 0;
}
