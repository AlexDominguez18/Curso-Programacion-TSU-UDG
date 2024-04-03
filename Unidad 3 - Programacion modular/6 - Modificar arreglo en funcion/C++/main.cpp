#include <iostream>

#define TAMANIO_ARR 5

using namespace std;

void modificarArreglo(int arreglo[]);
void imprimirArreglo(int arreglo[]);

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5};

    cout << "Arreglo original: ";
    imprimirArreglo(arreglo);

    modificarArreglo(arreglo);
    cout << "Arreglo modificado: ";
    imprimirArreglo(arreglo);

    return 0;
}

void modificarArreglo(int arreglo[])
{
    for (int i = 0; i < TAMANIO_ARR; i++) {
        arreglo[i] = arreglo[i] * 2;
    }
}

void imprimirArreglo(int arreglo[])
{
    for (int i = 0; i < TAMANIO_ARR; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
