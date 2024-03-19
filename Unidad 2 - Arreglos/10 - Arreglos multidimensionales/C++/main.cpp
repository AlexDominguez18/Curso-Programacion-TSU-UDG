#include <iostream>

#define N 2

using namespace std;

int main()
{
    // Declaracion de arreglo tridimensional x, y, z
    int arreglo[N][N][N];

    // Inicializacion de arreglo tridimensional
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                arreglo[i][j][k] = i + j + k;
            }
        }
    }

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
                cout << arreglo[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Presiona una tecla para terminar...";
    cin.get();

    return 0;
}