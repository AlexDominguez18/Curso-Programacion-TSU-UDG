#include <iostream>

#define TAMANIO_ARREGLO 10

using namespace std;

int main()
{
    int arreglo[TAMANIO_ARREGLO], resultados[TAMANIO_ARREGLO];
    int i, multiplicador;

    // Pedimos los valores del arreglo
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        cout << "Ingrese el valor para la posición " << i << ": ";
        cin >> arreglo[i];
    }

    cout << "Ingrese el multiplicador: ";
    cin >> multiplicador;

    // Calculamos el resultado y lo guardamos en el arreglo resultados
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        resultados[i] = arreglo[i] * multiplicador;
    }

    // Mostramos el resultado
    for (i = 0; i < TAMANIO_ARREGLO; i++) {
        cout << arreglo[i] << " * " << multiplicador << " = " << resultados[i] << endl;
    }

    cin.get(); // Limpiamos el buffer del teclado
    cout << "Presione enter para terminar...";
    cin.get();

    return 0;
}
