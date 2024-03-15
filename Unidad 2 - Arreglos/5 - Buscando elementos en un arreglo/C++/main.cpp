#include <iostream>

#define TAMANIO_ARREGLO 10

using namespace std;

int main()
{
    // Definimos un arreglo de enteros
    int arreglo[TAMANIO_ARREGLO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numeroBuscado = 0;

    cout << "Ingrese el numero a buscar: ";
    cin >> numeroBuscado;

    /**
     * Buscamos el numero en el arreglo recorriendolo
     * Las busquedas lineales son ineficientes, pero son utiles para entender el concepto
     * de busqueda en arreglos. Ya que a mayor cantidad de elementos en el arreglo, mayor
     * sera el tiempo de busqueda.
    */
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        // Si encontramos el numero, imprimimos la posicion y terminamos el programa
        if (arreglo[i] == numeroBuscado) {
            cout << "El numero " << numeroBuscado << " se encuentra en la posicion " << i << " del arreglo" << endl;
            return 0;
        }
    }

    // Si llegamos a esta linea, el numero no se encuentra en el arreglo
    cout << "El numero " << numeroBuscado << " no se encuentra en el arreglo" << endl;

    cin.get();
    cout << "Presione enter para continuar...";
    cin.get();

    return 0;
}