#include <iostream>

#define TAMANIO_ARREGLO 10

using namespace std;

int main()
{

    // Declaracion e inicializacion del arreglo
    int arreglo[TAMANIO_ARREGLO] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    
    /**
     * Imprimir el arreglo.
     * Para ello, se recorre el arreglo y se imprime el indice y el valor.
     * Todos los arreglos empiezan en el indice 0.
    */
    cout << "Indice:\tValor:" << endl;
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        cout << i << "\t" << arreglo[i] << endl;
    }

    return 0;
}
