#include <iostream>

using namespace std;

int main()
{
    // Declaración de la variable tipo 'string', en C++ se utiliza 'string' en lugar de 'char[]'
    string nombre;

    // Lectura de la cadena de texto
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    // Impresión de la cadena de texto leida
    cout << "Hola " << nombre << "!";
    
    return 0;
}