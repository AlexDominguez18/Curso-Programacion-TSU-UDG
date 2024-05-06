#include <iostream>
#include <ctime>

#include "lista.h"

using namespace std;

int main()
{
    Lista<int>* lista = new Lista<int>();

    srand(time(nullptr));

    for (int i = 0; i < 10000; i++) {
        int numero = rand() % 10000;
        lista->insertar(numero);
    }

    cout << "Longitud de la lista: " << lista->getLongitud() << endl;
    cout << "Lista:\n" << *lista << endl;

    delete lista;

    return 0;
}