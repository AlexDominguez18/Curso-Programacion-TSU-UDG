#include <iostream>

using namespace std;

int main()
{
    int i;
    int multiplicando;
    int ultimoMultiplicador;

    cout << "Ingrese el multiplicando: ";
    cin >> multiplicando;

    cout << "Ingrese el ultimo multiplicador: ";
    cin >> ultimoMultiplicador;

    cout << "Tabla de multiplicar del " << multiplicando << " usando *for*:\n";
    for (i = 1; i <= ultimoMultiplicador; i++) {
       cout << multiplicando << " * " << i << " = " << multiplicando * i << "\n";
    }

    cin.ignore(); // Limpiamos el buffer del teclado
    cout << "Presione enter para continuar...";
    cin.get();

    cout << "Tabla de multiplicar del " << multiplicando << " usando *while*:\n";
    i = 1;
    while (i <= ultimoMultiplicador) {
       cout << multiplicando << " * " << i << " = " << multiplicando * i << "\n";
        i++;
    }

    cout << "Presione enter para continuar...";
    cin.get();

    cout << "Tabla de multiplicar del " << multiplicando << " usando *do-while*:\n";
    i = 1;
    do {
       cout << multiplicando << " * " << i << " = " << multiplicando * i << "\n";
        i++;
    } while (i <= ultimoMultiplicador);

    cout << "Presione enter para terminar...";
    cin.get();

    return 0;
}
