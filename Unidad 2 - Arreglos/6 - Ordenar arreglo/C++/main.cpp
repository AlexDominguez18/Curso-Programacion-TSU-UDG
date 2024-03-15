#include <iostream>

#define TAMANIO_ARREGLO 10

using namespace std;

int main()
{
    // Definimos un arreglo de enteros desordenado
    int arreglo[] = {5, 3, 2, 8, 1, 4, 9, 7, 6, 10};
    // Definimos un contador para observar la cantidad de repeticiones
    int comparaciones = 0;

    /**
     * Esta manera de ordenar un arreglo es la mas sencilla de entender
     * pero no es la mas eficiente. Se llama ordenamiento burbuja.
     * 
     * La idea es recorrer el arreglo varias veces, comparando los elementos
     * de a pares y si estan desordenados, intercambiarlos.
     * Por cada recorrido, el elemento mas grande se va al final del arreglo.
     * Usamos dos ciclos anidados para recorrer el arreglo y comparar los elementos.
    */
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        // Este segundo ciclo recorre el arreglo desde el elemento siguiente al actual
        for (int j = i + 1; j < TAMANIO_ARREGLO; j++, comparaciones++) {
            // Si el elemento actual es mayor al siguiente, los intercambiamos
            if (arreglo[i] > arreglo[j]) {
                // Usamos una variable auxiliar para guardar el valor del elemento actual
                int aux = arreglo[i];
                arreglo[i] = arreglo[j]; // Cambiamos el valor del elemento actual por el siguiente
                arreglo[j] = aux; // Cambiamos el valor del siguiente por el valor guardado en la variable auxiliar
            }
        }
    }

    cout << "El arreglo ordenado es: ";
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        cout << arreglo[i] << " ";
    }

    cout << "\nCantidad de comparaciones: " << comparaciones << endl;

    cout << "Presione enter para continuar...";
    cin.ignore();

    return 0;
}