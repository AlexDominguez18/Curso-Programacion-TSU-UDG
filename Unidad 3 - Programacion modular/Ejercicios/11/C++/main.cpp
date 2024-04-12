#include <iostream>

#define RECURSIVO 1
#define ITERATIVO 2
#define SALIR 3

using namespace std;

int elegirOpcion();
int leerNumero();
int factorialRecursivo(int n);
int factorialIterativo(int n);

int main()
{
    int n;
    bool continuarPrograma = true;

    do {
        switch (elegirOpcion()) {
        case RECURSIVO:
            n = leerNumero();
            cout << "El factorial de " << n << " es " << factorialRecursivo(n) << endl;
            break;
        case ITERATIVO:
            n = leerNumero();
            cout << "El factorial de " << n << " es " << factorialIterativo(n) << endl;
            break;
        case SALIR:
            continuarPrograma = false;
            break;
        default:
            break;
        }
        cin.ignore();
        cout << "Presione una tecla para continuar...";
        cin.ignore();
    } while (continuarPrograma);
    
    return 0;
}

int leerNumero()
{
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    return numero;
}

int elegirOpcion()
{
    int opcion;
    system("cls || clear");
    cout << "Menu" << endl;
    cout << "1. Factorial recursivo" << endl;
    cout << "2. Factorial iterativo" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

int factorialRecursivo(int n)
{
    if (n == 0) return 1;

    return n * factorialRecursivo(n - 1);
}

int factorialIterativo(int n)
{
    int resultado = n;
    
    while (n > 1) {
        resultado *= --n;
    }

    return resultado;
}