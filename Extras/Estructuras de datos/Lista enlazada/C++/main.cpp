#include <iostream>

#include "lista.h"

#define POSICION 5

using namespace std;

int main()
{
    Lista<int> lista;

    for (int i = 0; i < 10; i++)
        lista.agregar(i + 1);

    cout << "Lista:\n" << lista << endl;
    cout << "Longitud: " << lista.obtenerLongitud() << endl;
    cout << "Elemento en la posición " << POSICION <<  ": ";
    cout << lista[POSICION] << endl;
    
    return 0;
}