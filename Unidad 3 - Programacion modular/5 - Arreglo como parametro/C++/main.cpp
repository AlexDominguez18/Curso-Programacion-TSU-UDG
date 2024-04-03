#include <iostream>

#define TAMANIO_ARR 5

using namespace std;

int sumar(int arreglo[]);

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5};
    int resultado;
    
    resultado = sumar(arreglo);

    cout << "El resultado de la suma es: " << resultado << endl;

    return 0;
}

int sumar(int arreglo[])
{
    int suma = 0;
    for (int i = 0; i < TAMANIO_ARR; i++) {
        suma += arreglo[i];
    }
    return suma;
}
